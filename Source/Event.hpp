#pragma once

enum class EventType
{
};

class Event final
{
public:
	Event(const EventType type);

public:
	const EventType type;
};