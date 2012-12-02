#ifndef SIZECONTROL_H_
#define SIZECONTROL_H_

#include <omnetpp.h>
#include <Packet_m.h>
#include "AdmControl.h"

class SizeControl : public AdmControl {

    protected:
        uint64_t minSize;
        uint64_t maxSize;

        virtual void initialize();
        virtual bool packetAccept(Packet* packet);

};

#endif
