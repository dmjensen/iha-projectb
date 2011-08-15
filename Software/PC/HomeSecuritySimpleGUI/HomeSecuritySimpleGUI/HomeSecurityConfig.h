#pragma once
#include <list>
#include "XML\XMLFile.h"
#include "Entities\Device.h"
#include "Entities\Event.h"
#include "Serial\Serial.h"

#define COM_PORT_NO 3
#define BAUD_RATE 115200

using namespace std;


class HomeSecurityConfig
{
private:
	CSerial* s;
	list<Device*> device_list;

public:
	HomeSecurityConfig();
	~HomeSecurityConfig();
	bool loadConf(LPTSTR path);
	bool parseConf(CXMLFile* xml_file, list<Device*>& devices);
	bool programConf(list<Device*>& devices, int port, int baudRate);
	void sendByteSerial(unsigned char byte);
	list<Device*> getDeviceList();

};

