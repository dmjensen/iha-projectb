#pragma once
#include <list>
#include "Event.h"

class Device
{
private:
	char id;
	std::list<Event> events;

public:
	Device(char id);
	~Device();
	char getID();
	void addEvent(Event);
	std::list<Event> getEvents();

};