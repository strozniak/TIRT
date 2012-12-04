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

class MMPPGenerator : public cSimpleModule
{
    private:
        double lambda;
        int rnb;
        double delay;
    protected:
        virtual cMessage *generatePacket();
        virtual void sendMessage();
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
};

Define_Module(MMPPGenerator);

void MMPPGenerator::initialize(){
    lambda = par("lambda").doubleValue();
    rnb = par("rnb").longValue();

    WATCH(delay);

    sendMessage();
}

void MMPPGenerator::handleMessage(cMessage *msg){
    delete msg;
    sendMessage();
}

void MMPPGenerator::sendMessage(){

    std::stringstream ss;

    simtime_t delay = poisson(lambda,rnb);
    lambda = delay.dbl();
    ss << "Self "<< delay;

    std::string s = ss.str();
    cMessage *sel = new cMessage(s.c_str());
    cMessage *packet = generatePacket();
    sendDelayed(packet, delay, "out");
    scheduleAt(simTime()+delay, sel);


}

cMessage *MMPPGenerator::generatePacket(){
    MyPacket *packet = new MyPacket();
    return packet;
}

