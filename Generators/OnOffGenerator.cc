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

#include "OnOffGenerator.h"

Define_Module(OnOffGenerator);

OnOffGenerator::OnOffGenerator()
{
    msgGL = NULL;
    sessionCnt = 0;
}

OnOffGenerator::~OnOffGenerator()
{
    cancelAndDelete(msgGL);
}

void OnOffGenerator::initialize()
{
    int OnOrOff = par("OnOff");

    if(OnOrOff==1){
        msgGL = generateMessage();
        scheduleAt(simTime(), msgGL);
    };
}

void OnOffGenerator::handleMessage(cMessage *msg)
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

    Packet *ttmsg = generateMessage();

    simtime_t delay = par("delayTime");

    send(ttmsg, "gate");

    scheduleAt(simTime()+delay, msgGL);

    sessionCnt++;

}

Packet *OnOffGenerator::generateMessage()
{

    // Produce source and destination addresses.
    int src = getIndex();
    int dest = intuniform(0,int(par("destNumber")));
    if (dest>=src) dest++;

    //klase rowniez losujemy
    int Class = intuniform(0,int(par("classNumber")));

    int SessionId = 1;
    int PacketId = 1;
    int Payload = 1;

    char msgname[30];
    sprintf(msgname, "packet-from-%d-to-%d", src, dest);

    // Create message object and set source and destination field.
    Packet *msg = new Packet(msgname);
    msg->setSrc(src);
    msg->setDst(dest);
    msg->setSessionID(SessionId);
    msg->setPacketID(PacketId);
    msg->setPriority(Class);
    msg->setPayload(Payload);
    return msg;
}
