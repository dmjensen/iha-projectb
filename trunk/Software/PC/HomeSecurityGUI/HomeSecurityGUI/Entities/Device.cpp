#include "StdAfx.h"
#include "Device.h"

Device::Device(char id)
{
	this->id = id;
}

Device::~Device()
{

}

char Device::getID()
{
	return id;
}

void Device::addEvent(Event e)
{
	events.push_back(e);
}

std::list<Event> Device::getEvents()
{
	return events;
}