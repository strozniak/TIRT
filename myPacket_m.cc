//
// Generated file, do not edit! Created by opp_msgc 4.2 from myPacket.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "myPacket_m.h"

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




Register_Class(MyPacket);

MyPacket::MyPacket(const char *name, int kind) : cMessage(name,kind)
{
    this->src_var = 0;
    this->dst_var = 0;
    this->sessionID_var = 0;
    this->packetID_var = 0;
    this->priority_var = 0;
    this->payload_var = 0;
}

MyPacket::MyPacket(const MyPacket& other) : cMessage(other)
{
    copy(other);
}

MyPacket::~MyPacket()
{
}

MyPacket& MyPacket::operator=(const MyPacket& other)
{
    if (this==&other) return *this;
    cMessage::operator=(other);
    copy(other);
    return *this;
}

void MyPacket::copy(const MyPacket& other)
{
    this->src_var = other.src_var;
    this->dst_var = other.dst_var;
    this->sessionID_var = other.sessionID_var;
    this->packetID_var = other.packetID_var;
    this->priority_var = other.priority_var;
    this->payload_var = other.payload_var;
}

void MyPacket::parsimPack(cCommBuffer *b)
{
    cMessage::parsimPack(b);
    doPacking(b,this->src_var);
    doPacking(b,this->dst_var);
    doPacking(b,this->sessionID_var);
    doPacking(b,this->packetID_var);
    doPacking(b,this->priority_var);
    doPacking(b,this->payload_var);
}

void MyPacket::parsimUnpack(cCommBuffer *b)
{
    cMessage::parsimUnpack(b);
    doUnpacking(b,this->src_var);
    doUnpacking(b,this->dst_var);
    doUnpacking(b,this->sessionID_var);
    doUnpacking(b,this->packetID_var);
    doUnpacking(b,this->priority_var);
    doUnpacking(b,this->payload_var);
}

int MyPacket::getSrc() const
{
    return src_var;
}

void MyPacket::setSrc(int src)
{
    this->src_var = src;
}

int MyPacket::getDst() const
{
    return dst_var;
}

void MyPacket::setDst(int dst)
{
    this->dst_var = dst;
}

int MyPacket::getSessionID() const
{
    return sessionID_var;
}

void MyPacket::setSessionID(int sessionID)
{
    this->sessionID_var = sessionID;
}

int MyPacket::getPacketID() const
{
    return packetID_var;
}

void MyPacket::setPacketID(int packetID)
{
    this->packetID_var = packetID;
}

int MyPacket::getPriority() const
{
    return priority_var;
}

void MyPacket::setPriority(int priority)
{
    this->priority_var = priority;
}

int MyPacket::getPayload() const
{
    return payload_var;
}

void MyPacket::setPayload(int payload)
{
    this->payload_var = payload;
}

class MyPacketDescriptor : public cClassDescriptor
{
  public:
    MyPacketDescriptor();
    virtual ~MyPacketDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(MyPacketDescriptor);

MyPacketDescriptor::MyPacketDescriptor() : cClassDescriptor("MyPacket", "cMessage")
{
}

MyPacketDescriptor::~MyPacketDescriptor()
{
}

bool MyPacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<MyPacket *>(obj)!=NULL;
}

const char *MyPacketDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int MyPacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount(object) : 6;
}

unsigned int MyPacketDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<6) ? fieldTypeFlags[field] : 0;
}

const char *MyPacketDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "src",
        "dst",
        "sessionID",
        "packetID",
        "priority",
        "payload",
    };
    return (field>=0 && field<6) ? fieldNames[field] : NULL;
}

int MyPacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "src")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "dst")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "sessionID")==0) return base+2;
    if (fieldName[0]=='p' && strcmp(fieldName, "packetID")==0) return base+3;
    if (fieldName[0]=='p' && strcmp(fieldName, "priority")==0) return base+4;
    if (fieldName[0]=='p' && strcmp(fieldName, "payload")==0) return base+5;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *MyPacketDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<6) ? fieldTypeStrings[field] : NULL;
}

const char *MyPacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int MyPacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    MyPacket *pp = (MyPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string MyPacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    MyPacket *pp = (MyPacket *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getSrc());
        case 1: return long2string(pp->getDst());
        case 2: return long2string(pp->getSessionID());
        case 3: return long2string(pp->getPacketID());
        case 4: return long2string(pp->getPriority());
        case 5: return long2string(pp->getPayload());
        default: return "";
    }
}

bool MyPacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    MyPacket *pp = (MyPacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setSrc(string2long(value)); return true;
        case 1: pp->setDst(string2long(value)); return true;
        case 2: pp->setSessionID(string2long(value)); return true;
        case 3: pp->setPacketID(string2long(value)); return true;
        case 4: pp->setPriority(string2long(value)); return true;
        case 5: pp->setPayload(string2long(value)); return true;
        default: return false;
    }
}

const char *MyPacketDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<6) ? fieldStructNames[field] : NULL;
}

void *MyPacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    MyPacket *pp = (MyPacket *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


