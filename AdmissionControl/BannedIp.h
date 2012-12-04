#ifndef BANNEDIP_H_
#define BANNEDIP_H_

#include <omnetpp.h>
#include <Packet_m.h>
#include "AdmControl.h"
#include <set>

class BannedIp : public AdmControl {

    std::set<int> restrictedAcces;

    virtual void initialize();
    virtual bool packetAccept(Packet* packet);

};

#endif
