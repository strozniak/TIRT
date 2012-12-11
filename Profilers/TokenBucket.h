#include <omnetpp.h>

class TokenBucket: public cSimpleModule
{
protected:
    cMessage *msgServiced;
    cMessage *endServiceMsg;
    cMessage *token;
    simsignal_t queueingTimeSignal;

    int tokenCount;
    int tokenMax;
    simtime_t tokenArrivalInterval;

public:
    TokenBucket();
    virtual ~TokenBucket();

protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);

    // hook functions to (re)define behaviour
    virtual void arrival(cMessage *msg) {}
    simtime_t startService(cMessage *msg);
    int getTokenArrivalInterval();
};

