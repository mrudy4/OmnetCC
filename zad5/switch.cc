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

#include "switch.h"
#include "wlasnyMsg_m.h"

Define_Module(Switch);

void Switch::initialize()
{
    // TODO - Generated method body

}

void Switch::handleMessage(cMessage *msg)
{

  std::string arrivalGate = msg->getArrivalGate()->getBaseName();
//  int index = msg -> getArrivalGate() -> getId();
//  EV << "Index: " << index << endl;
//  EV << "Arrival gate: " << arrivalGate << endl;
//  EV << "Sender: " << msg -> getSenderGate() -> getBaseName() << endl;



  if(arrivalGate == "bramaHost1")
  {
      msg->setKind(1);
      send(msg, "bramaDoKomputer");
      EV << "SWITCH -> SERVER / CPU | HOST" << msg->getKind() << endl;

  }
  else if(arrivalGate == "bramaHost2")
  {
      msg->setKind(2);
      send(msg,"bramaDoKomputer");
      EV << "SWITCH -> SERVER / CPU | HOST" << msg->getKind() << endl;
  }
  else
  {

      int kind = msg->getKind();
      if(kind == 1){
          send(msg,"bramaHost1$o");
          EV << "SWITCH -> HOST1 | HOST" << msg->getKind() << endl;
      } else if (kind == 2)
      {
          send(msg,"bramaHost2$o");
          EV << "SWITCH -> HOST2 | HOST" << msg->getKind() << endl;
      }else
      {
          EV << "Kind: " << msg->getKind() << endl;
          EV << "Something fucked up" << endl;
      }

  }

}

