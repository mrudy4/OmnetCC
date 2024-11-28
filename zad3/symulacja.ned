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
            @display("p=422,102;i=device/server2");
        }


        host1: Klient {
            parameters:
                //wielkosc_danych = lognormal(40,5,0);
                //czas_namyslu = exponential(0.5);
                wielkoscZadania = 2.2;
                @display("p=153,47;i=device/pc2");
        }

        host2: Klient {
            parameters:
                //wielkosc_danych = lognormal(40,5,0);
                //czas_namyslu = exponential(0.5);
                wielkoscZadania = 2.2;
                @display("p=61,112;i=device/pc2");
        }

        switch: Switch {
            @display("p=249,127");
        }

    connections:
        host1.bramaSwitch <--> switch.bramaHost1;
        host2.bramaSwitch <--> switch.bramaHost2;
		switch.bramaDoKomputer --> komputer.od_switch;
		switch.bramaOdKomputer <-- komputer.do_switch;
		


}
