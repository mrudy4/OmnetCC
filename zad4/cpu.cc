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

#include "cpu.h"
#include "wlasnyMsg_m.h"

Define_Module(Cpu);


void Cpu::activity()
{

    WlasnyMsg *msg ;
    double jednostkowyCzasObslugi =(double) par("jednostkowyCzasObslugi");
    cQueue kolejka;
    for(;;)
        {

            if(kolejka.isEmpty())
            {
                msg = (WlasnyMsg*)receive();
                //EV << "Queue was empty - Cpu" << endl;
            }
            else
            {
                msg=(WlasnyMsg*)kolejka.pop();
                //EV << "Poped out from queue - Cpu" << endl;
            }

            waitAndEnqueue(0.000527+jednostkowyCzasObslugi*msg->getWielkoscZadania()/512,&kolejka);

            std::string arrivalGate = msg->getArrivalGate()->getBaseName();
//          int index = msg -> getArrivalGate() -> getId();
//          EV << "Index: " << index << endl;
//          EV << "Arrival gate: " << arrivalGate << endl;
//          EV << "Sender: " << msg -> getSenderGate() -> getBaseName() << endl;
            EV << "Msg size: " << msg->getWielkoscZadania()<< endl;

            int a = arrivalGate.compare("od_serwera");

            if(a==0)
            {
                send(msg,"oddo_dysku$o");
                EV << "CPU -> DISK | HOST" << msg->getKind() << endl;
            }
            else
            {
                send(msg,"do_serwera");
                EV << "CPU -> SERVER / SWITCH | HOST" << msg->getKind() << endl;
            }

         }
}

