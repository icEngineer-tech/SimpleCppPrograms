#pragma once
#define MAX_ROOM 30
#define MIN_ROOM 1
#define MAX_FLOOR 5
#define MIN_FLOOR 1

void info(std::string);
void End(void);

struct Floor
{
	unsigned sRoom, dRoom, kRoom, suiteRoom;
};
