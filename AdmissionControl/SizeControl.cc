#include <omnetpp.h>
#include <Packet_m.h>
#include "SizeControl.h"

Define_Module(SizeControl)

void SizeControl::initialize()
{
        AdmControl::initialize();

        minSize = par("minSize");
        maxSize = par("maxSize");

}

bool SizeControl::packetAccept(Packet* pck)
{
    uint64_t pckSize = pck->getByteLength();

    if(pckSize >= minSize && pckSize <= maxSize)
        return true;
    else
        return false;
}
