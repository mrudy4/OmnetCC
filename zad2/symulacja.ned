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

network Symulacja
{
    @display("bgb=514,281");

    submodules:

        komputer: Server {

            //@display("p=124,247");
            @display("p=163,201;i=device/server2");
        }


        casche: Casche {
            parameters:
                procent_danych_w_pamieci = uniform(1, 10);
                @display("p=370,191;i=block/boundedqueue");
                 //display("p=438,66");
        }

        host: Klient {
            parameters:
                wielkosc_danych = lognormal(40,5,0);
                czas_namyslu = exponential(0.5);
                @display("p=163,91;i=device/pc2");
        }

        disk: Disk {
            parameters:
                czas_transmisji = 14us;
                czas_przeszukiwania_i_oczekiwania = 0.028us;
                @display("p=465,168;i=device/disk");
                //@display("p=438,205");
        }

        cpu: Cpu {
            parameters:
                czas_wyszukiwania_danych = 0.527us;
                czas_transmisji_do_klienta = 0.00024us;
                @display("p=360,90;i=device/cpu");
            //@display("p=322,66");
        }

    connections:
        komputer.oddo_klienta <--> host.oddo_komputera;
        //host.oddo_cpu <--> cpu.oddo_klienta;
        //cpu.oddo_casche <--> casche.oddo_procesora;
        //casche.oddo_dysku <--> disk.oddo_casche;
}
