/*
 * Node_e.h
 *
 *      Author: Wilku
 */

#ifndef NODE_E_H_
#define NODE_E_H_

#include <omnetpp.h>
#include <Payload_m.h>

class Node_e : public cSimpleModule
{
  private:
    // state
    simtime_t lastArrival;

    // statistics
    cDoubleHistogram iaTimeHistogram;
    cOutVector arrivalsVector;

  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual void finish();
};

#endif /* NODE_E_H_ */
