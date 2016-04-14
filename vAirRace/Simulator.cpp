//Simulator Events Class Implemtation.
#include "Simulator.h"

Simulator::Simulator()
{
}

Simulator::~Simulator()
{
    Disconnect();
}

int Simulator::Connect()
{
	//Ensure any previous connections are closed first then connect to simulator.
	DWORD result;
    FSUIPC_Close();
	FSUIPC_Open(SIM_ANY, &result);
	return (int)result;
}

void Simulator::Disconnect()
{
    FSUIPC_Close();
}

int Simulator::Reset()
{
    return Connect();
}

int Simulator::Read(unsigned int offset, unsigned int size, void* destination)
{
    //Add read call to queue.
    DWORD result;
    FSUIPC_Read((DWORD)offset, (DWORD)size, destination, &result);
    return (int)result;
}

int Simulator::Write(unsigned int offset, unsigned int size, void* source)
{
    //Add write call to queue.
    DWORD result;
    FSUIPC_Write((DWORD)offset, (DWORD)size, source, &result);
    return (int)result;
}

int Simulator::Process()
{
    //Process queued calls.
    DWORD result;
    FSUIPC_Process(&result);
    return (int)result;
}