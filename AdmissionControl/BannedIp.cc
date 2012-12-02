#include <omnetpp.h>
#include <Packet_m.h>
#include "BannedIp.h"

Define_Module(BannedIp);

void BannedIp::initialize()
{
        AdmControl::initialize();

        const char* ids = par("restrictedAcces");
        std::vector<int> vIds = cStringTokenizer(ids).asIntVector();

        for(uint32_t i = 0; i < vIds.size(); i++)
            restrictedAcces.insert(vIds[i]);
}

bool BannedIp::packetAccept(Packet* pck)
{
        return restrictedAcces.find(pck->getSrc()) == restrictedAcces.end();
}
