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
#define ev EV_INFO
Define_Module(Cpu);

void Cpu::initialize()
{
    // TODO - Generated method body
}

void Cpu::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
}

void Cpu::activity(){
    kolejka.setName("kolejka");
    for (;;){
        if (kolejka.empty())
            zadanie = (cPacket *) receive();
        else
            zadanie = (cPacket *)kolejka.pop();

        if (zadanie->getKind()==1) //od klienta
            obsluz_zad_na_procesorze(zadanie);

        if (zadanie->getKind()==5) //od pamięci podręcznej
            wysyla_do_klient(zadanie);
     }
}


void Cpu::obsluz_zad_na_procesorze(cPacket *zadanie){
    char nazwa [15];
    double czas_wyszukiwania_danych = (double)par("czas_wyszukiwania_danych");
    waitAndEnqueue(czas_wyszukiwania_danych, &kolejka);
    ev << "procesor: Wyslanie zadania do cache" << endl;
    zadanie->setKind(2);
    ev << "procesor: Rodzaj komuniaktu wsylanego do cache: "<< zadanie->getKind () << endl;
    send (zadanie, "oddo_casche");

}

void Cpu::wysyla_do_klient(cPacket *zadanie){

    char nazwa [15];
    double czas_transmisji_do_klienta;
    czas_transmisji_do_klienta= (double)par ("czas_transmisji_do_klienta")*( zadanie-> getByteLength ()/512);
     if (czas_transmisji_do_klienta>0)
         waitAndEnqueue(czas_transmisji_do_klienta, &kolejka);

     ev << "procesor: Wysylanie odpowiedzi do klienta" << endl;
     zadanie->setKind(6);
     send (zadanie, "oddo_klienta");

}
