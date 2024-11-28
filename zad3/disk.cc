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

#include "disk.h"
#include "wlasnyMsg_m.h"


Define_Module(Disk);

void Disk::activity()
{
    WlasnyMsg *msg;
    cQueue kolejka;
    for(;;)
    {
        if(kolejka.isEmpty())
        {
            msg = (WlasnyMsg*)receive();
        }
        else
        {
            msg=(WlasnyMsg*)kolejka.pop();
        }

        std::string arrivalGate = msg->getArrivalGate()->getBaseName();
//      int index = msg -> getArrivalGate() -> getId();
//      EV << "Index: " << index << endl;
//      EV << "Arrival gate: " << arrivalGate << endl;
//      EV << "Sender: " << msg -> getSenderGate() -> getBaseName() << endl;


        int a = arrivalGate.compare("oddo_cpu");
        if (a==0)
        {
            send (msg, "oddo_cpu$o");
            EV << "DISK -> CPU | HOST" << msg->getKind() << endl;
        }
        else
        {
            EV << "Kind: " << msg->getKind() << endl;
            EV << "Dziwna akcja" << endl;
        }

    }
}

