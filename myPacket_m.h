//
// Generated file, do not edit! Created by opp_msgc 4.2 from myPacket.msg.
//

#ifndef _MYPACKET_M_H_
#define _MYPACKET_M_H_

#include <omnetpp.h>

// opp_msgc version check
#define MSGC_VERSION 0x0402
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgc: 'make clean' should help.
#endif



/**
 * Class generated from <tt>myPacket.msg</tt> by opp_msgc.
 * <pre>
 * message MyPacket {
 *     int src;
 *     int dst;
 *     int sessionID;
 *     int packetID;
 *     int priority;
 *     int payload;
 * }
 * </pre>
 */
class MyPacket : public ::cMessage
{
  protected:
    int src_var;
    int dst_var;
    int sessionID_var;
    int packetID_var;
    int priority_var;
    int payload_var;

  private:
    void copy(const MyPacket& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const MyPacket&);

  public:
    MyPacket(const char *name=NULL, int kind=0);
    MyPacket(const MyPacket& other);
    virtual ~MyPacket();
    MyPacket& operator=(const MyPacket& other);
    virtual MyPacket *dup() const {return new MyPacket(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual int getSrc() const;
    virtual void setSrc(int src);
    virtual int getDst() const;
    virtual void setDst(int dst);
    virtual int getSessionID() const;
    virtual void setSessionID(int sessionID);
    virtual int getPacketID() const;
    virtual void setPacketID(int packetID);
    virtual int getPriority() const;
    virtual void setPriority(int priority);
    virtual int getPayload() const;
    virtual void setPayload(int payload);
};

inline void doPacking(cCommBuffer *b, MyPacket& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, MyPacket& obj) {obj.parsimUnpack(b);}


#endif // _MYPACKET_M_H_
