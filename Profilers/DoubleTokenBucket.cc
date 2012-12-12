#include "DoubleTokenBucket.h"

Define_Module(DoubleTokenBucket);

DoubleTokenBucket::DoubleTokenBucket() {
    msgServiced = endServiceMsg = NULL;
}

DoubleTokenBucket::~DoubleTokenBucket() {
    delete msgServiced;
    cancelAndDelete(endServiceMsg);
}

void DoubleTokenBucket::initialize() {
    endServiceMsg = new cMessage("end-service");
    queue.setName("queue");

    qlenSignal = registerSignal("qlen");
    busySignal = registerSignal("busy");
    queueingTimeSignal = registerSignal("queueingTime");
    emit(qlenSignal, queue.length());
    emit(busySignal, 0);

    token = new cMessage("token");

    tokenMax = par("tokenCount");
    tokenCount = tokenMax;
    tokenArrivalInterval = par("tokenArrivalInterval");

    scheduleAt(simTime(), token);
}

int DoubleTokenBucket::getTokenArrivalInterval() {
    return par("buffer");
}

void DoubleTokenBucket::handleMessage(cMessage *msg) {
    if (msg == token) {
        if (tokenCount < tokenMax) {
            tokenCount++;
        }
        scheduleAt(simTime() + tokenArrivalInterval, token);
    } else {
        if (tokenCount > 0) {

            if (msg == endServiceMsg) {
                tokenCount--;
                endService(msgServiced);
                if (queue.empty()) {
                    msgServiced = NULL;
                    emit(busySignal, 0);
                } else {
                    msgServiced = (cMessage *) queue.pop();
                    emit(qlenSignal, queue.length());
                    emit(queueingTimeSignal,
                            simTime() - msgServiced->getTimestamp());
                    simtime_t serviceTime = startService(msgServiced);
                    scheduleAt(simTime() + serviceTime, endServiceMsg);
                }
            } else if (!msgServiced) {
                arrival(msg);
                msgServiced = msg;
                emit(queueingTimeSignal, 0.0);
                simtime_t serviceTime = startService(msgServiced);
                scheduleAt(simTime() + serviceTime, endServiceMsg);
                emit(busySignal, 1);
            } else {
                arrival(msg);
                if (queue.length() < getBuffer()) {
                    queue.insert(msg);
                    msg->setTimestamp();
                    emit(qlenSignal, queue.length());
                    EV << "queue size: " << queue.length();
                } else { // wyrzuc pakiet
                    bubble("packet leaked!");
                }

            }
        } else {
            bubble("No available tokens!");
        }
    }
}

int DoubleTokenBucket::getBuffer() {
    return par("buffer");
}

simtime_t DoubleTokenBucket::startService(cMessage *msg) {
    EV << "Starting service of " << msg->getName() << endl;
    return par("serviceTime");
}

void DoubleTokenBucket::endService(cMessage *msg) {
    EV << "Completed service of " << msg->getName() << endl;
    send(msg, "out");
}
