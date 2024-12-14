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

network Symulator
{
    parameters:
        @display("bgb=462,328");
    submodules:
        klient1: Klient {
            parameters:
                address = 0;
                @display("p=175,63");
                czasMiedzyZadaniami = 3;
                wielkoscZadania = 100;
        }

        klient2: Klient {
            parameters:
                address = 1;
                @display("p=175,185");
                czasMiedzyZadaniami = 7;
                wielkoscZadania = 100;
        }


        serwer: Serwer {
            @display("p=401,137");
        }

        przelacznik: KartaSieciowa {
            parameters:
                @display("p=312,137");
            gates:
                odKlienta[2];
                doKlienta[2];

        }
        blokStatystyk: Statystyki {
            parameters:

                @display("p=37,137");
            gates:
                odKlienta[2];
        }

    connections:

        klient1.doSerwera --> przelacznik.odKlienta[0];
        //klient1.odSerwera <-- router.doKlienta[0];
        klient1.odSerwera <-- {  datarate = 100Mbps; } <-- przelacznik.doKlienta[0];

        klient2.doSerwera --> przelacznik.odKlienta[1];
        //klient2.odSerwera <-- router.doKlienta[1];
        klient2.odSerwera <-- {  datarate = 100Mbps; } <-- przelacznik.doKlienta[1];

        przelacznik.doSerwera --> {  datarate = 100Mbps; } --> serwer.odKlienta;
        //router.doSerwera --> serwer.odKlienta;
        przelacznik.odSerwera <-- serwer.doKlienta;

        klient1.doStatystyki --> blokStatystyk.odKlienta[0];
        klient2.doStatystyki --> blokStatystyk.odKlienta[1];


}
