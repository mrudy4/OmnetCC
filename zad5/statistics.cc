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

#include "statistics.h"
#include "wlasnyMsg_m.h"

Define_Module(Statistics);

void Statistics::initialize()
{
    statystyki.setName("czasyOpowiedzi");
    // TODO - Generated method body
}

void Statistics::handleMessage(cMessage *msg)
{
//    WlasnyMsg * zadanie = (WlasnyMsg*)msg;
//
//    double czasOdpowiedzi;
//    double kara;
//    double t_max = (double) par("t_max");
//
//    czasOdpowiedzi = zadanie ->getArrivalTime().dbl()-zadanie->getCreationTime();
//
//    if(czasOdpowiedzi > t_max){
//        kara = (czasOdpowiedzi - t_max)*zadanie->getKara();
//
//    }
    double czasOdpowiedzi = msg->getArrivalTime().dbl() - msg->getCreationTime().dbl();
    statystyki.record(czasOdpowiedzi);
}
