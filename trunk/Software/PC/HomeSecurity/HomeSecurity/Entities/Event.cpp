#include "..\stdafx.h"
#include "Event.h"

Event::Event(char type, char hour, char minute)
{
	this->type = type;
	this->hour = hour;
	this->minute = minute;
}

Event::~Event()
{

}

char Event::getType()
{
	return type;
}

char Event::getHour()
{
	return hour;
}

char Event::getMinute()
{
	return minute;
}