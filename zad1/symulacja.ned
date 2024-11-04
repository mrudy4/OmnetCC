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

        klient1: Klient {
            @display("p=386,208");
        }

        klient2: Klient {

            @display("p=109,31");
        }

        server: Server {

            @display("p=124,247");
        }

        switch: Switch {
            @display("p=250,113");
        }

    connections:
        klient1.bramaSwitch <--> switch.bramaklient1;
        klient2.bramaSwitch <--> switch.bramaklient2;
        server.bramaSwitch <--> switch.bramaServer;


}
