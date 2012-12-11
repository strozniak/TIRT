#include <omnetpp.h>

class LeakyBucket: public cSimpleModule
{
protected:
    cMessage *msgServiced;
    cMessage *endServiceMsg;
    cQueue queue;
    simsignal_t qlenSignal;
    simsignal_t busySignal;
    simsignal_t queueingTimeSignal;

public:
    LeakyBucket();
    virtual ~LeakyBucket();

protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);

    // hook functions to (re)define behaviour
    virtual void arrival(cMessage *msg) {}
    simtime_t startService(cMessage *msg);
    int getBuffer();
    void endService(cMessage *msg);
};

