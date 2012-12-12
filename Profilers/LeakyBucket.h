#include <omnetpp.h>

class LeakyBucket: public cSimpleModule
{
protected:
    cMessage *msgServiceTime;
    cMessage *msgServiced;
    cQueue queue;
    simtime_t serviceTime;
public:
    LeakyBucket();
    virtual ~LeakyBucket();

protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);

    int getBuffer();
};

