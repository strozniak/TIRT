#ifndef ADMCONTROL_H_
#define ADMCONTROL_H_

#include <omnetpp.h>
#include <Packet_m.h>

class AdmControl : public cSimpleModule {

    private:
        // state
        simtime_t lastArrival;

        // statistics
        cDoubleHistogram iaTimeHistogram;
        cOutVector arrivalsVector;

        //counts
        int wentIn;
        int wentOut;

    protected:

        virtual void initialize();
        virtual void handleMessage(cMessage* msg);
        virtual void finish();
        //virtual bool packetAccept(Packet* packet);

};

#endif /* ADMCONTROL_H_ */
