//Simulator Events Class Implemtation.
#include "Simulator.h"

Simulator::Simulator()
{
}

Simulator::~Simulator()
{
    Disconnect();
    isConnected = false;
}

int Simulator::Connect()
{
	//Ensure any previous connections are closed first then connect to simulator.
	DWORD result;
    FSUIPC_Close();
    if (FSUIPC_Open(SIM_ANY, &result) == TRUE)
        isConnected = true;
    else
        isConnected = false;
    return static_cast<int>(result);
}

void Simulator::Disconnect()
{
    FSUIPC_Close();
    isConnected = false;
}

int Simulator::Reset()
{
    return Connect();
}

int Simulator::Read(unsigned int offset, unsigned int size, void* destination)
{
    //Add read call to queue.
    DWORD result;
    FSUIPC_Read(static_cast<DWORD>(offset), static_cast<DWORD>(size), destination, &result);
    return static_cast<int>(result);
}

int Simulator::Write(unsigned int offset, unsigned int size, void* source)
{
    //Add write call to queue.
    DWORD result;
    FSUIPC_Write(static_cast<DWORD>(offset), static_cast<DWORD>(size), source, &result);
    return static_cast<int>(result);
}

int Simulator::Process()
{
    //Process queued calls.
    DWORD result;
    FSUIPC_Process(&result);
    return static_cast<int>(result);
}

bool Simulator::ConnectionStatus()
{
    return isConnected;
}