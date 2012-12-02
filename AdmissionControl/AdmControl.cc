#include "AdmControl.h"

void AdmControl::initialize()
{
    wentIn = 0;
    wentOut = 0 ;
    lastArrival = SIMTIME_ZERO;

    WATCH(wentIn);
    WATCH(wentOut);

    iaTimeHistogram.setName("Time packets went through");
    arrivalsVector.setName("Arrivals AC");
    arrivalsVector.setInterpolationMode(cOutVector::NONE);

}

void AdmControl::handleMessage(cMessage* msg)
{

    wentIn++;
    lastArrival = std::max(lastArrival, simTime());

    Packet* pck = check_and_cast<Packet*>(msg);


    EV << "Received " << pck->getName() << endl;

    //sprawdzenie akceptacji pakietu
    if(packetAccept(pck)){

        //zebranie danych
        simtime_t d = simTime() - lastArrival;
        iaTimeHistogram.collect(d);
        arrivalsVector.record(1);

        //pobranie bramy wyjsciowej i wyslanie przez nia pakietu
        cGate* out = gate("out");
        send(pck, out);

        //zwiekszenie ilosci pakietow jakie wyszly
        wentOut++;

    }
    else {
        EV << "Blocked " << pck->getName() << endl;
        delete pck;
    }

}

void AdmControl::finish()
{

}
