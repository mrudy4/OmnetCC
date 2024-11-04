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
#include <iostream>
#define ev EV_INFO
using namespace std;

Define_Module(Klient); //po co ta definicja, skoro mamy plik naglowkowy??

void Klient::initialize()
{
    // TODO - Generated method body
}

void Klient::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
}

void Klient::activity(){
    kolejka.setName("kolejka"); //tworzy kopie i nazywa ja "kolejka"
    char nazwa[20]; // tworzymy zmienna do przesylania danych
    int wielkosc_danych;
    double czas_namyslu;

    for(;;){    //w nieskonczonej petli bedziemy dawac funkcje wysylania/odbierania itp.
        strcpy(nazwa, "oddo_klienta");
        cPacket *zadanie = new cPacket(nazwa);
        wielkosc_danych=par ("wielkosc_danych");
        zadanie->setByteLength(wielkosc_danych);
        zadanie->setKind(1);
        ev << "Klient: Wielkosc wygenerowanego zadania: "<< wielkosc_danych << endl;
        ev << "Klient: Rodzaj komuniaktu od klienta: " << zadanie -> getKind() << endl;

        send(zadanie, "oddo_klienta");
        czas_namyslu=par ("czas_namyslu");
        waitAndEnqueue((double) czas_namyslu, &kolejka);
        kolejka.clear ();

    }
}

