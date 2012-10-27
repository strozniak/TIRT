//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//

#include "Node_s.h"

Define_Module(Node_s);

Node_s::Node_s()
{
    msgGL = NULL;
    sessionCnt = 0;
}

Node_s::~Node_s()
{
    cancelAndDelete(msgGL);
}

void Node_s::initialize()
{
    int OnOrOff = par("OnOff");

    if(OnOrOff==1){
        msgGL = generateMessage();
        scheduleAt(simTime(), msgGL);
    };
}

void Node_s::handleMessage(cMessage *msg)
{

    //Zmieniamy wartosc po przekroczeniu okreslonego progu
    int OnOrOff = par("OnOff");
    int lowerB = par("lowerBound");
    int upperB = par("upperBound");
    int chgVal = par("changeValue");
    int result = intuniform(lowerB,upperB);

    if ((result >= chgVal) && OnOrOff == 0){
        OnOrOff = 1;
    }
    else if((result <= chgVal) && OnOrOff == 1){
        OnOrOff = 0;
        EV << "Blokada wysylki! Res: "<< result << endl;
    };

    while (OnOrOff == 0){
        //Chcemy chwile poczekac przed nastepna proba wysylki
//        Sleep(1000);
        result = intuniform(lowerB,upperB);
        EV << "Proba odblokowania wysylki! Res: "<< result << endl;
        if ((result >= chgVal) && OnOrOff == 0){
            OnOrOff = 1;
        };
    };

    ASSERT(msg==msgGL);

    Payload *ttmsg = generateMessage();

    simtime_t delay = par("delayTime");

    send(ttmsg, "gate");

    scheduleAt(simTime()+delay, msgGL);

    sessionCnt++;

}

Payload *Node_s::generateMessage()
{

    // Produce source and destination addresses.
    int src = getIndex();
    int n = size();
    int dest = intuniform(0,int(par("destNumber")));
    if (dest>=src) dest++;

    //klase rowniez losujemy
    int Class = intuniform(0,int(par("classNumber")));

    //Jakis tam dowolny ciag znakow
    //char * SessionId = "|"<<sessionCnt<<"|"<<src<<"|"<<dest<<"|"<<sessionCnt<<"|";
    //char * PacketId = "|"<<sessionCnt<<"|"<<src<<"|"<<dest<<"|"<<Class<<"|";

    char * SessionId = "Test";
    char * PacketId = "Test";

    char msgname[30];
    sprintf(msgname, "packet-from-%d-to-%d", src, dest);

    // Create message object and set source and destination field.
    Payload *msg = new Payload(msgname);
    msg->setSRC(src);
    msg->setDST(dest);
    msg->setSessionId(SessionId);
    msg->setPacketId(PacketId);
    msg->setClass(Class);
    return msg;
}
