/*--------------------------------------------------------------------
This file is part of the Arduino WizFi360 library.

The Arduino WizFi360 library is free software: you can redistribute it
and/or modify it under the terms of the GNU General Public License as
published by the Free Software Foundation, either version 3 of the
License, or (at your option) any later version.

The Arduino WizFi360 library is distributed in the hope that it will be
useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with The Arduino WizFi360 library.  If not, see
<http://www.gnu.org/licenses/>.
--------------------------------------------------------------------*/

#include "WizFi360.h"
#include "WizFi360Udp.h"

#include "utility/WizFi360Drv.h"
#include "utility/debug.h"

/* Constructor */
WiFiUDP::WiFiUDP() : _sock(NO_SOCKET_AVAIL) {}




/* Start WiFiUDP socket, listening at local port PORT */

uint8_t WiFiUDP::begin(uint16_t port)
{
    uint8_t sock = WizFi360Class::getFreeSocket();
    if (sock != NO_SOCKET_AVAIL)
    {
        WizFi360Drv::startClient("0", port, sock, UDP_MODE);
		
        WizFi360Class::allocateSocket(sock);  // allocating the socket for the listener
        WizFi360Class::_server_port[sock] = port;
        _sock = sock;
        _port = port;
        return 1;
    }
    return 0;

}


/* return number of bytes available in the current packet,
   will return zero if parsePacket hasn't been called yet */
int WiFiUDP::available()
{
	 if (_sock != NO_SOCKET_AVAIL)
	 {
		int bytes = WizFi360Drv::availData(_sock);
		if (bytes>0)
		{
			return bytes;
		}
	}

	return 0;
}

/* Release any resources being used by this WiFiUDP instance */
void WiFiUDP::stop()
{
	  if (_sock == NO_SOCKET_AVAIL)
	    return;

      // Discard data that might be in the incoming buffer
      flush();
      
      // Stop the listener and return the socket to the pool
	  WizFi360Drv::stopClient(_sock);
      WizFi360Class::_state[_sock] = NA_STATE;
      WizFi360Class::_server_port[_sock] = 0;

	  _sock = NO_SOCKET_AVAIL;
}

int WiFiUDP::beginPacket(const char *host, uint16_t port)
{
  if (_sock == NO_SOCKET_AVAIL)
	  _sock = WizFi360Class::getFreeSocket();
  if (_sock != NO_SOCKET_AVAIL)
  {
	  //WizFi360Drv::startClient(host, port, _sock, UDP_MODE);
	  _remotePort = port;
	  strcpy(_remoteHost, host);
	  WizFi360Class::allocateSocket(_sock);
	  return 1;
  }
  return 0;
}


int WiFiUDP::beginPacket(IPAddress ip, uint16_t port)
{
	char s[18];
	sprintf_P(s, PSTR("%d.%d.%d.%d"), ip[0], ip[1], ip[2], ip[3]);

	return beginPacket(s, port);
}


int WiFiUDP::endPacket()
{
	return 1; //ServerDrv::sendUdpData(_sock);
}

size_t WiFiUDP::write(uint8_t byte)
{
  return write(&byte, 1);
}

size_t WiFiUDP::write(const uint8_t *buffer, size_t size)
{
	bool r = WizFi360Drv::sendDataUdp(_sock, _remoteHost, _remotePort, buffer, size);
	if (!r)
	{
		return 0;
	}

	return size;
}

int WiFiUDP::parsePacket()
{
	return available();
}

int WiFiUDP::read()
{
	uint8_t b;
	if (!available())
		return -1;

	bool connClose = false;
	
    // Read the data and handle the timeout condition
	if (! WizFi360Drv::getData(_sock, &b, false, &connClose))
      return -1;  // Timeout occured

	return b;
}

int WiFiUDP::read(uint8_t* buf, size_t size)
{
	if (!available())
		return -1;
	return WizFi360Drv::getDataBuf(_sock, buf, size);
}

int WiFiUDP::peek()
{
  uint8_t b;
  if (!available())
    return -1;

  return b;
}

void WiFiUDP::flush()
{
	  // Discard all input data
	  int count = available();
	  while (count-- > 0)
	    read();
}


IPAddress  WiFiUDP::remoteIP()
{
	IPAddress ret;
	WizFi360Drv::getRemoteIpAddress(ret);
	return ret;
}

uint16_t  WiFiUDP::remotePort()
{
	return WizFi360Drv::getRemotePort();
}



////////////////////////////////////////////////////////////////////////////////
// Private Methods
////////////////////////////////////////////////////////////////////////////////


