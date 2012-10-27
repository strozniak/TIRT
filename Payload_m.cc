//
// Generated file, do not edit! Created by opp_msgc 4.2 from Payload.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "Payload_m.h"

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




Register_Class(Payload);

Payload::Payload(const char *name, int kind) : cPacket(name,kind)
{
    this->DST_var = 0;
    this->SRC_var = 0;
    this->SessionId_var = 0;
    this->PacketId_var = 0;
    this->Class_var = 0;
}

Payload::Payload(const Payload& other) : cPacket(other)
{
    copy(other);
}

Payload::~Payload()
{
}

Payload& Payload::operator=(const Payload& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    copy(other);
    return *this;
}

void Payload::copy(const Payload& other)
{
    this->DST_var = other.DST_var;
    this->SRC_var = other.SRC_var;
    this->SessionId_var = other.SessionId_var;
    this->PacketId_var = other.PacketId_var;
    this->Class_var = other.Class_var;
}

void Payload::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->DST_var);
    doPacking(b,this->SRC_var);
    doPacking(b,this->SessionId_var);
    doPacking(b,this->PacketId_var);
    doPacking(b,this->Class_var);
}

void Payload::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->DST_var);
    doUnpacking(b,this->SRC_var);
    doUnpacking(b,this->SessionId_var);
    doUnpacking(b,this->PacketId_var);
    doUnpacking(b,this->Class_var);
}

int Payload::getDST() const
{
    return DST_var;
}

void Payload::setDST(int DST)
{
    this->DST_var = DST;
}

int Payload::getSRC() const
{
    return SRC_var;
}

void Payload::setSRC(int SRC)
{
    this->SRC_var = SRC;
}

const char * Payload::getSessionId() const
{
    return SessionId_var.c_str();
}

void Payload::setSessionId(const char * SessionId)
{
    this->SessionId_var = SessionId;
}

const char * Payload::getPacketId() const
{
    return PacketId_var.c_str();
}

void Payload::setPacketId(const char * PacketId)
{
    this->PacketId_var = PacketId;
}

int Payload::getClass() const
{
    return Class_var;
}

void Payload::setClass(int Class)
{
    this->Class_var = Class;
}

class PayloadDescriptor : public cClassDescriptor
{
  public:
    PayloadDescriptor();
    virtual ~PayloadDescriptor();

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

Register_ClassDescriptor(PayloadDescriptor);

PayloadDescriptor::PayloadDescriptor() : cClassDescriptor("Payload", "cPacket")
{
}

PayloadDescriptor::~PayloadDescriptor()
{
}

bool PayloadDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<Payload *>(obj)!=NULL;
}

const char *PayloadDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int PayloadDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount(object) : 5;
}

unsigned int PayloadDescriptor::getFieldTypeFlags(void *object, int field) const
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
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *PayloadDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "DST",
        "SRC",
        "SessionId",
        "PacketId",
        "Class",
    };
    return (field>=0 && field<5) ? fieldNames[field] : NULL;
}

int PayloadDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='D' && strcmp(fieldName, "DST")==0) return base+0;
    if (fieldName[0]=='S' && strcmp(fieldName, "SRC")==0) return base+1;
    if (fieldName[0]=='S' && strcmp(fieldName, "SessionId")==0) return base+2;
    if (fieldName[0]=='P' && strcmp(fieldName, "PacketId")==0) return base+3;
    if (fieldName[0]=='C' && strcmp(fieldName, "Class")==0) return base+4;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *PayloadDescriptor::getFieldTypeString(void *object, int field) const
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
        "string",
        "string",
        "int",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : NULL;
}

const char *PayloadDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int PayloadDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    Payload *pp = (Payload *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string PayloadDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    Payload *pp = (Payload *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getDST());
        case 1: return long2string(pp->getSRC());
        case 2: return oppstring2string(pp->getSessionId());
        case 3: return oppstring2string(pp->getPacketId());
        case 4: return long2string(pp->getClass());
        default: return "";
    }
}

bool PayloadDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    Payload *pp = (Payload *)object; (void)pp;
    switch (field) {
        case 0: pp->setDST(string2long(value)); return true;
        case 1: pp->setSRC(string2long(value)); return true;
        case 2: pp->setSessionId((value)); return true;
        case 3: pp->setPacketId((value)); return true;
        case 4: pp->setClass(string2long(value)); return true;
        default: return false;
    }
}

const char *PayloadDescriptor::getFieldStructName(void *object, int field) const
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
    };
    return (field>=0 && field<5) ? fieldStructNames[field] : NULL;
}

void *PayloadDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    Payload *pp = (Payload *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


