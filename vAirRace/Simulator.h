//Simulator Events Class Declaration.
#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <windows.h>

#include "FSUIPC_User.h"

class Simulator
{
public:
	Simulator();
	~Simulator();

	bool Connect();
	void Disconnect();
};

#endif