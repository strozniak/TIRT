/*
 * Node_s.h
 *
 *      Author: Wilku
 */

#ifndef NODE_S_H_
#define NODE_S_H_

#include <omnetpp.h>
#include <Payload_m.h>

class Node_s : public cSimpleModule
{

  private:
    Payload *msgGL;
    int sessionCnt;

  public:
    Node_s();
    virtual ~Node_s();

  protected:
    virtual Payload *generateMessage();
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

#endif /* NODE_S_H_ */
