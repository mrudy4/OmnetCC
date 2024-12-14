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

#include "klient.h"
#include "wlasnyMsg_m.h"

Define_Module(Klient);

void Klient::initialize()
{
    // TODO - Generated method body
    cMessage *wlasnaWiadomosc = new cMessage();
    scheduleAt(simTime(),wlasnaWiadomosc);
    EV << "Initialization of Host" << endl;
}

void Klient::handleMessage(cMessage *msg)
{
    WlasnyMsg *zadanie ;
        if(msg->isSelfMessage())
        {
            zadanie=new WlasnyMsg();
            int wielkoscZadania =(int) par("wielkoscZadania").doubleValue();

            zadanie->setWielkoscZadania(wielkoscZadania);
            zadanie->setByteLength(wielkoscZadania);

            send(zadanie,"bramaSwitch$o");
            EV << "Sent from Host to Switch" << endl;
            EV << "HOST -> SWITCH" << endl;
            EV << "Msg size: " << wielkoscZadania << endl;

            double czasMiedzyZadaniami = (double) par("czasMiedzyZadaniami");
            if(czasMiedzyZadaniami<0)
            {
                czasMiedzyZadaniami = 0;
            }

            scheduleAt(simTime() + czasMiedzyZadaniami,msg);
        }
        else
        {
            send(msg, "stats");
            //delete msg;
        }
}
