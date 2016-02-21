//Simulator Events Class Implemtation.
#include "Simulator.h"

Simulator::Simulator()
{
}

Simulator::~Simulator()
{
	Disconnect();
}

bool Simulator::Connect()
{
	DWORD dwResult;
	return FSUIPC_Open(SIM_ANY, &dwResult);
}

void Simulator::Disconnect()
{
	FSUIPC_Close();
}
