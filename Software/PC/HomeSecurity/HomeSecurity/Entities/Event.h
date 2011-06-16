#pragma once

class Event
{
private:
	char type;
	char hour;
	char minute;

public:
	Event(char type, char hour, char minute);
	~Event();
	
	char getType();
	char getHour();
	char getMinute();

};