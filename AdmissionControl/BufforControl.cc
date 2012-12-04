#include <omnetpp.h>
#include <Packet_m.h>
#include "BufforControl.h"

Define_Module(BufforControl);

void BufforControl::initialize()
{
        AdmControl::initialize();

        bufforSize = par("bufforSize");

}

bool BufforControl::packetAccept(Packet* pck)
{
        if(processing > bufforSize)
            return false;
        else
            return true;
}
