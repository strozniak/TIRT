#include <omnetpp.h>

class DoubleTokenBucket: public cSimpleModule {
protected:
    cMessage *msgServiced;
    cMessage *endServiceMsg;
    cQueue queue;
    simsignal_t qlenSignal;
    simsignal_t busySignal;
    simsignal_t queueingTimeSignal;

    cMessage *token;

    int tokenCount;
    int tokenMax;
    simtime_t tokenArrivalInterval;

public:
    DoubleTokenBucket();
    virtual ~DoubleTokenBucket();

protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);

    // hook functions to (re)define behaviour
    virtual void arrival(cMessage *msg) {
    }
    simtime_t startService(cMessage *msg);
    void endService(cMessage *msg);
    int getTokenArrivalInterval();
    int getBuffer();
};

