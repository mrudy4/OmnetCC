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
        @display("bgb=334,237");
    submodules:
        klient: Klient {
            @display("p=56,43");
        }
        serwer: Serwer {
            @display("p=265,182");
        }
        
        kartaSieciowa: KartaSieciowa{}
        
    connections:

        klient.doSerwera --> kartaSieciowa.odKlienta ;  
        kartaSieciowa.doSerwera -->{  datarate = 100Mbps; } --> serwer.odKlienta;
        
        kartaSieciowa.odSerwera <--  serwer.doKlienta;
        klient.odSerwera <-- {  datarate = 100Mbps; } <-- kartaSieciowa.doKlienta;




}
