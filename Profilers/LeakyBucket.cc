#include "LeakyBucket.h"

Define_Module(LeakyBucket);

LeakyBucket::LeakyBucket() {
    msgServiced = endServiceMsg = NULL;
}

LeakyBucket::~LeakyBucket() {
    delete msgServiced;
    cancelAndDelete(endServiceMsg);
}

void LeakyBucket::initialize() {
    endServiceMsg = new cMessage("end-service");
    queue.setName("queue");

    qlenSignal = registerSignal("qlen");
    busySignal = registerSignal("busy");
    queueingTimeSignal = registerSignal("queueingTime");
    emit(qlenSignal, queue.length());
    emit(busySignal, 0);
}

int LeakyBucket::getBuffer() {
    return par("buffer");
}

void LeakyBucket::handleMessage(cMessage *msg) {
    if (msg == endServiceMsg) {
        endService(msgServiced);
        if (queue.empty()) {
            msgServiced = NULL;
            emit(busySignal, 0);
        } else {
            msgServiced = (cMessage *) queue.pop();
            emit(qlenSignal, queue.length());
            emit(queueingTimeSignal, simTime() - msgServiced->getTimestamp());
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
}

simtime_t LeakyBucket::startService(cMessage *msg) {
    EV << "Starting service of " << msg->getName() << endl;
    return par("serviceTime");
}

void LeakyBucket::endService(cMessage *msg) {
    EV << "Completed service of " << msg->getName() << endl;
    send(msg, "out");
}
