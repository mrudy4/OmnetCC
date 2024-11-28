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

#include "kartaSieciowa.h"
#include "wlasnyMsg_m.h"
Define_Module(KartaSieciowa);

void KartaSieciowa::wyslijZadanie(char *brama, cQueue kolejka, WlasnyMsg *zadanie){

    cChannel *channel = gate(brama)->getTransmissionChannel();
    simtime_t txFinishTime = channel->getTransmissionFinishTime();

    if (txFinishTime <= simTime())
    {
    send(zadanie,brama);
    }
    else
    {
    waitAndEnqueue(txFinishTime-simTime(),&kolejka);
    send(zadanie,brama);
    }

}

void KartaSieciowa::activity()
{

    WlasnyMsg *zadanie ;
   // double jednostkowyCzasObslugi =(double) par("jednostkowyCzasObslugi");
    cQueue kolejka;
    for(;;)
        {
            if(kolejka.isEmpty())
            {
                zadanie = (WlasnyMsg*)receive();
            }
            else
            {
                zadanie=(WlasnyMsg*)kolejka.pop();
            }



                std::string brama= zadanie->getArrivalGate()->getBaseName();

                        int a = brama.compare("odKlienta");

                            if(a==0)  // brama.compare("odKlienta")== true
                            {
                               wyslijZadanie("doSerwera",kolejka,zadanie);
                                //send(zadanie,"doSerwera");
                            }
                            else
                            {

                                wyslijZadanie("doKlienta",kolejka,zadanie);
//                                cChannel *channel = gate("doKlienta")->getTransmissionChannel();
//                                simtime_t txFinishTime = channel->getTransmissionFinishTime();
//
//                                if (txFinishTime <= simTime())
//                                {
//                                send(zadanie,"doKlienta");
//                                }
//                                else
//                                {
//                                waitAndEnqueue(txFinishTime-simTime(),&kolejka);
//                                send(zadanie,"doKlienta");
//                                }
                            }




         }
}
