#pragma once
#include "stdafx.h"
#include "XML\XMLFile.h"
#include "Entities\Device.h"
#include "Entities\Event.h"
#include "Serial\Serial.h"


#ifdef _UNICODE
#define std_out std::wcout
#else
#define std_out std::cout
#endif

#define conf_file "D:\\plan.xml"

using namespace std;

bool loadConf(LPTSTR path);
bool parseConf(CXMLFile* xml_file, list<Device*>& devices);
bool programConf(list<Device*>& devices, int port, int baudRate);


int _tmain(int argc, _TCHAR* argv[])
{
	int choice = -1;

	while (choice != 0)
	{
		system("CLS");

		std_out << _T("Home Security System v0.1\n")
				<< _T("Enter choice:\n")
				<< _T("1. Load configuration\n")
				<< _T("2. Save configuration\n")
				<< _T("\n0. Exit\n")
				<< endl;

		cin >> choice;

		switch(choice)
		{
			case 0: std_out << _T("Exiting...\n");
					break;
			case 1: std_out << _T("Loading Configuration...\n");
					if(!loadConf(_T(conf_file)))
						std_out << _T("Error loading Configuration...\n");
					break;
			default: std_out << _T("Invalid command\n");
		}

		Sleep(1000);
	}

	system("CLS");
	return 0;
}

//Loads configuration XML file from "path" and checks if it is well formed. If it is this configuration is sent to the STK500.
bool loadConf(LPTSTR path)
{
	CXMLFile xml_file;// = new CXMLFile();
	if( !xml_file.LoadFromFile(path) )
		return false; //Error reading XML, maybe badly formed?

	//Check if the XML configuration file is formed as expected and if so get a list of devices.
	list<Device*> devices;
	if( !parseConf(&xml_file, devices) )
		return false; //Error parsing the XML Configuration file, not formed as expected?

	if( !programConf(devices, 3, 115200) )
		return false; //Error programming STK500

	//Destroy file in memory
	xml_file.~CXMLFile();

	return true;
}

//Checks if the xml file is formed as expected
bool parseConf(CXMLFile* xml_file, list<Device*>& devices)
{
	stack<CXMLElement*> elem_stack;

	//XML_root
	elem_stack.push(xml_file->GetRoot());
	//Configuration root
	elem_stack.push(elem_stack.top()->GetLastChild());
	//Check if it actually is the configuration root
	if(lstrcmp(elem_stack.top()->GetElementName(), _T("configuration")) != 0)
		return false;

	//Loop through devices in the configuration
	elem_stack.push(elem_stack.top()->GetFirstChild());
	while(elem_stack.top() != NULL)
	{
		//Check if it actually is a device:
		if(lstrcmp(elem_stack.top()->GetElementName(), _T("device")) != 0)
			return false;

		//First child should be an id
		elem_stack.push(elem_stack.top()->GetFirstChild());
		if(lstrcmp(elem_stack.top()->GetElementName(), _T("id")) != 0)
			return false;
		//Create new Device object using the id from XML file
		devices.push_back(new Device((char)_ttoi(elem_stack.top()->GetValue())));
		elem_stack.pop(); //Pop id

		//Following children should be events
		char type, hour, minute;
		elem_stack.push(elem_stack.top()->GetNextChild());
		while(elem_stack.top() != NULL)
		{
			if(lstrcmp(elem_stack.top()->GetElementName(), _T("event")) != 0)
				return false;

			//First child should be a type
			elem_stack.push(elem_stack.top()->GetFirstChild()); //Push type
			if(elem_stack.top() == NULL || lstrcmp(elem_stack.top()->GetElementName(), _T("type")) != 0)
				return false;
			type = _ttoi(elem_stack.top()->GetValue()); //Save type
			elem_stack.pop(); //Pop Type
			
			//Second child should be an hour
			elem_stack.push(elem_stack.top()->GetNextChild()); //Push hour
			if(elem_stack.top() == NULL || lstrcmp(elem_stack.top()->GetElementName(), _T("hour")) != 0)
				return false;
			hour = _ttoi(elem_stack.top()->GetFirstChild()->GetElementName()); //Save hour
			elem_stack.pop(); //Pop Hour

			//Third child should be a minute
			elem_stack.push(elem_stack.top()->GetNextChild()); //Push Minute
			if(elem_stack.top() == NULL || lstrcmp(elem_stack.top()->GetElementName(), _T("minute")) != 0)
				return false;
			minute = _ttoi(elem_stack.top()->GetFirstChild()->GetElementName()); //Save minute
			elem_stack.pop(); //Pop Minute

			//We expect no more children
			elem_stack.push(elem_stack.top()->GetNextChild());
			if(elem_stack.top() != NULL)
				return false;
			elem_stack.pop();

			devices.back()->addEvent(Event(type, hour, minute));

			elem_stack.pop(); //Pop current Event
			elem_stack.push(elem_stack.top()->GetNextChild()); //Proceed to next event
		}
		elem_stack.pop(); //Pop NULL (Event)


		elem_stack.pop(); //Pop current device
		elem_stack.push(elem_stack.top()->GetNextChild()); //Proceed to next device
	}
	elem_stack.pop(); //Pop NULL (Device)

	return true;
}

bool programConf(list<Device*>& devices, int port, int baudRate)
{
	char data[3];

	CSerial* s = new CSerial();

	if(!s->Open(port, baudRate))
	{
		std_out << _T("Could not open COM") << port << endl;
		return false;
	}

#define C_Reset 0xB0
#define C_CONF 0xB1	

	while(!devices.empty())
	{
		list<Event> events = devices.front()->getEvents();

		data[0] = C_CONF;
		data[1] = devices.front()->getID();
		data[2] = events.size();
		s->SendData(data, 3);

		while(!events.empty())
		{
			data[0] = events.front().getType();
			data[1] = events.front().getHour();
			data[2] = events.front().getMinute();
			s->SendData(data, 3);

			events.pop_front();
		}

		devices.pop_front();
	}

	s->Close();

	return true;
}