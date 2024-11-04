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

#include "casche.h"

#define ev EV_INFO

Define_Module(Casche);

void Casche::initialize()
{
    // TODO - Generated method body
}

void Casche::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
}

void Casche::activity(){
    int procent_danych_w_pamieci;
    for (;;)
    {
        zadanie = (cPacket *) receive();
         //jeśli wiadomość przyszła od procesora
        if (zadanie->getKind()==2){
             procent_danych_w_pamieci= rand () %10 +1;
             if (procent_danych_w_pamieci <= 8)
                 obsluz_zad_na_cache(zadanie);
             else
                 wyslij_do_dysku(zadanie);
        }
         //jęsli wiadomość przyszła od dysku
        if (zadanie->getKind()==4)
        obsluz_zad_na_cache(zadanie);
    }

}

void Casche::obsluz_zad_na_cache(cPacket *zadanie){
    char nazwa [15];
    double czas_wyszukiwania_danych = (double)par("czas_wyszukiwania_danych");
       waitAndEnqueue(czas_wyszukiwania_danych, &kolejka);
       ev << "Cache: Wyslanie zadania do procesora" << endl;
       zadanie->setKind(5);
       ev << "Cache: Rodzaj komuniaktu wsylanego do procesora: "<< zadanie->getKind () << endl;
       send (zadanie, "oddo_procesora");
}

void Casche::wyslij_do_dysku(cPacket *zadanie){
    char nazwa [15];
    double czas_transmisji_do_dysku;
    czas_transmisji_do_dysku= (double)par ("czas_transmisji_do_dysku")*( zadanie-> getByteLength ()/512);
    if (czas_transmisji_do_dysku>0)
        waitAndEnqueue(czas_transmisji_do_dysku, &kolejka);

    ev << "Cache: Wysylanie zadania do dysku" << endl;
    zadanie->setKind(3);
    send (zadanie, "oddo_dysku");
}


