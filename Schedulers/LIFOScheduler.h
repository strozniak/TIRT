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

#ifndef LIFOSCHEDULER_H_
#define LIFOSCHEDULER_H_

using namespace std;
#include "FIFOScheduler.h"

class LIFOScheduler: public FIFOScheduler {
   protected:
       int32_t queueSize;
       list<Packet*> queue;

       virtual void initialize();
       virtual void handleMessage(cMessage* msg);
       virtual bool receivePacket(Packet* packet);
       virtual bool  hasWaitingPacket();
       virtual Packet* getPacketToSend();
       virtual bool canReceive();
};

#endif /* LIFOSCHEDULER_H_ */
