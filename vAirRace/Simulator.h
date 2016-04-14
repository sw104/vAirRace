//Simulator Events Class Declaration.
#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <windows.h>

#include "FSUIPC_User.h"

class Simulator
{
public:
    Simulator();
    ~Simulator();   //Destructor - disconnects from simulator.   
    int Connect();  //Connect to simulator.
	int Reset();    //Reset simulator connection - alias for "Connect" as this ensures disconnection from the simulator first.
    void Disconnect();  //Disconnect from simulator.
    int Read(unsigned int offset, unsigned int size, void* destination);  //Adds a read call of offset to destination to queue.
    int Write(unsigned int offset, unsigned int size, void* source);  //Adds write call from source to offset to queue.
    int Process();    //Process queued read and writes.
};

#endif