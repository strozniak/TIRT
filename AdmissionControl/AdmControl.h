#ifndef ADMCONTROL_H_
#define ADMCONTROL_H_

#include <omnetpp.h>
#include <Packet_m.h>

class AdmControl : public cSimpleModule {


    protected:
      virtual void initialize();
      virtual void handleMessage(cMessage *msg);
      virtual void finish();
      virtual bool packetAccep(Packet* packet);

};

#endif
