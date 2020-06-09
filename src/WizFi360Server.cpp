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

#include "WizFi360Server.h"

#include "utility/WizFi360Drv.h"
#include "utility/debug.h"



WiFiServer::WiFiServer(uint16_t port)
{
	_port = port;
}

void WiFiServer::begin()
{
	LOGDEBUG(F("Starting server"));

	/* The WizFi360 Module only allows socket 1 to be used for the server */
#if 0
	_sock = WizFi360Class::getFreeSocket();
	if (_sock == SOCK_NOT_AVAIL)
	  {
	    LOGERROR(F("No socket available for server"));
	    return;
	  }
#else
	_sock = 1; // If this is already in use, the startServer attempt will fail
#endif
	WizFi360Class::allocateSocket(_sock);

	_started = WizFi360Drv::startServer(_port, _sock);

	if (_started)
	{
		LOGINFO1(F("Server started on port"), _port);
	}
	else
	{
		LOGERROR(F("Server failed to start"));
	}
}

WiFiClient WiFiServer::available(byte* status)
{
	// TODO the original method seems to handle automatic server restart

	int bytes = WizFi360Drv::availData(0);
	if (bytes>0)
	{
		LOGINFO1(F("New client"), WizFi360Drv::_connId);
		WizFi360Class::allocateSocket(WizFi360Drv::_connId);
		WiFiClient client(WizFi360Drv::_connId);
		return client;
	}

    return WiFiClient(255);
}

uint8_t WiFiServer::status()
{
    return WizFi360Drv::getServerState(0);
}

size_t WiFiServer::write(uint8_t b)
{
    return write(&b, 1);
}

size_t WiFiServer::write(const uint8_t *buffer, size_t size)
{
	size_t n = 0;

    for (int sock = 0; sock < MAX_SOCK_NUM; sock++)
    {
        if (WizFi360Class::_state[sock] != 0)
        {
        	WiFiClient client(sock);
            n += client.write(buffer, size);
        }
    }
    return n;
}
