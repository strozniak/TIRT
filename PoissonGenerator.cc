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

#include <string.h>
#include <omnetpp.h>
#include "myPacket_m.h"

class PoissonGenerator : public cSimpleModule
{
    private:
        double lambda;
        int rnb;
    protected:
        virtual cPacket *generatePacket();
        virtual void sendMessage();
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
};

Define_Module(PoissonGenerator);

void PoissonGenerator::initialize(){

    lambda = par("lambda").doubleValue();
    rnb = par("rnb").longValue();

    sendMessage();
}

void PoissonGenerator::handleMessage(cMessage *msg){
    sendMessage();
}

void PoissonGenerator::sendMessage(){
    cPacket *packet = generatePacket();

    int delay = poisson(lambda, rnb);

    cMessage *self = new cMessage("selfMessage");

    send(packet,"out");
    scheduleAt(delay, self);
}

cPacket *PoissonGenerator::generatePacket(){
    MyPacket *packet = new MyPacket();
    return packet;
}

