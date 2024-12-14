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

#include "statystyki.h"
#include "wlasnyMsg_m.h"

Define_Module(Statystyki);

void Statystyki::initialize()
{
   // TODO - Generated method body
    statystyki.setName("statystyki");
}


void Statystyki::handleMessage(cMessage *msg)
{
    double czasOdpowiedzi;
    //double kara;
    //double t_max = (double) par("t_max");
    //statystyki.setName("statystyki");
    czasOdpowiedzi = msg->getArrivalTime().dbl()-msg->getCreationTime().dbl();
    statystyki.record(czasOdpowiedzi);
    // TODO - Generated method body
}
