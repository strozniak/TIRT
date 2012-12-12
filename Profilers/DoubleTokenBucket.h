#include <omnetpp.h>

class DoubleTokenBucket: public cSimpleModule {
protected:
    cQueue queue;

    cMessage *token;
    cMessage *serviceTimeMsg;
    cMessage *msgServiced;

    int tokenCount;
    int tokenMax;
    simtime_t tokenArrivalInterval;
    simtime_t serviceTime;

public:
    DoubleTokenBucket();
    virtual ~DoubleTokenBucket();

protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);

    int getBuffer();
};

