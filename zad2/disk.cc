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
#define ev EV_INFO
Define_Module(Disk);

void Disk::initialize()
{
    // TODO - Generated method body
}

void Disk::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
}

void Disk::activity(){

    double procent_danych_w_pamieci;
        for (;;)
        {
            zadanie = (cPacket *) receive();

            if (zadanie->getKind()==3){
                wysylanie_do_cache(zadanie);\
            }
        }
}

void Disk::wysylanie_do_cache(cPacket *zadanie){
    char nazwa [15];
    double czas_transmisji_do_cache;
    czas_transmisji_do_cache= (double)par ("czas_transmisji_do_cache")*( zadanie-> getByteLength ()/512);
        if (czas_transmisji_do_cache>0)
            waitAndEnqueue(czas_transmisji_do_cache, &kolejka);

        ev << "Dysk: Wysylanie danych do cache" << endl;
        zadanie->setKind(4);
        send (zadanie, "oddo_casche");
}
