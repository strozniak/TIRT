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
#include <sstream>
#include <string>
#include <string.h>
#include <omnetpp.h>
#include "myPacket_m.h"

class PoissonGenerator : public cSimpleModule
{
    private:
        double lambda;
        int rnb;
        int sends;
    protected:
        virtual cMessage *generatePacket();
        virtual void sendMessage();
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
};

Define_Module(PoissonGenerator);

void PoissonGenerator::initialize(){

    lambda = par("lambda").doubleValue();
    rnb = par("rnb").longValue();

    WATCH(sends);

    sendMessage();
}

void PoissonGenerator::handleMessage(cMessage *msg){
    delete msg;
    sendMessage();
}

void PoissonGenerator::sendMessage(){
    cMessage *sel = new cMessage("selfMessage");

    sends = poisson(lambda, rnb);

    std::stringstream ss;

    if(sends == 0){
        cMessage *packet = generatePacket();
        send(packet,"out");

        ss << "Send ";

    }else{
        ss << "Not send ";
    }

    ss << sends;
    std::string s = ss.str();
    bubble(s.c_str());

    scheduleAt(5.0, sel);
}

cMessage *PoissonGenerator::generatePacket(){
    MyPacket *packet = new MyPacket();
    return packet;
}

