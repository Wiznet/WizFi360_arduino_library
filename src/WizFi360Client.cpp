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

#include <inttypes.h>

#include "WizFi360.h"
#include "WizFi360Client.h"
#include "WizFi360Server.h"

#include "utility/WizFi360Drv.h"
#include "utility/debug.h"


WiFiClient::WiFiClient() : _sock(255)
{
}

WiFiClient::WiFiClient(uint8_t sock) : _sock(sock)
{
}


////////////////////////////////////////////////////////////////////////////////
// Overrided Print methods
////////////////////////////////////////////////////////////////////////////////

// the standard print method will call write for each character in the buffer
// this is very slow on WizFi360
size_t WiFiClient::print(const __FlashStringHelper *ifsh)
{
    return printFSH(ifsh, false);
}

// if we do override this, the standard println will call the print
// method twice
size_t WiFiClient::println(const __FlashStringHelper *ifsh)
{
    return printFSH(ifsh, true);
}


////////////////////////////////////////////////////////////////////////////////
// Implementation of Client virtual methods
////////////////////////////////////////////////////////////////////////////////

int WiFiClient::connectSSL(const char* host, uint16_t port)
{
	return connect(host, port, SSL_MODE);
}

int WiFiClient::connectSSL(IPAddress ip, uint16_t port)
{
	char s[16];
	sprintf_P(s, PSTR("%d.%d.%d.%d"), ip[0], ip[1], ip[2], ip[3]);
	return connect(s, port, SSL_MODE);
}

int WiFiClient::connect(const char* host, uint16_t port)
{
    return connect(host, port, TCP_MODE);
}

int WiFiClient::connect(IPAddress ip, uint16_t port)
{
	char s[16];
	sprintf_P(s, PSTR("%d.%d.%d.%d"), ip[0], ip[1], ip[2], ip[3]);

	return connect(s, port, TCP_MODE);
}

/* Private method */
int WiFiClient::connect(const char* host, uint16_t port, uint8_t protMode)
{
	LOGINFO1(F("Connecting to"), host);

	_sock = WizFi360Class::getFreeSocket();

    if (_sock != NO_SOCKET_AVAIL)
    {
    	if (!WizFi360Drv::startClient(host, port, _sock, protMode))
			return 0;

    	WizFi360Class::allocateSocket(_sock);
    }
	else
	{
    	LOGERROR(F("No socket available"));
    	return 0;
    }
    return 1;
}



size_t WiFiClient::write(uint8_t b)
{
	  return write(&b, 1);
}

size_t WiFiClient::write(const uint8_t *buf, size_t size)
{
	if (_sock >= MAX_SOCK_NUM or size==0)
	{
		setWriteError();
		return 0;
	}

	bool r = WizFi360Drv::sendData(_sock, buf, size);
	if (!r)
	{
		setWriteError();
		LOGERROR1(F("Failed to write to socket"), _sock);
		delay(4000);
		stop();
		return 0;
	}

	return size;
}



int WiFiClient::available()
{
	if (_sock != 255)
	{
		int bytes = WizFi360Drv::availData(_sock);
		if (bytes>0)
		{
			return bytes;
		}
	}

	return 0;
}

int WiFiClient::read()
{
	uint8_t b;
	if (!available())
		return -1;

	bool connClose = false;
	WizFi360Drv::getData(_sock, &b, false, &connClose);

	if (connClose)
	{
		WizFi360Class::releaseSocket(_sock);
		_sock = 255;
	}

	return b;
}

int WiFiClient::read(uint8_t* buf, size_t size)
{
	if (!available())
		return -1;
	return WizFi360Drv::getDataBuf(_sock, buf, size);
}

int WiFiClient::peek()
{
	uint8_t b;
	if (!available())
		return -1;

	bool connClose = false;
	WizFi360Drv::getData(_sock, &b, true, &connClose);

	if (connClose)
	{
		WizFi360Class::releaseSocket(_sock);
		_sock = 255;
	}

	return b;
}


void WiFiClient::flush()
{
	while (available())
		read();
}



void WiFiClient::stop()
{
	if (_sock == 255)
		return;

	LOGINFO1(F("Disconnecting "), _sock);

	WizFi360Drv::stopClient(_sock);

	WizFi360Class::releaseSocket(_sock);
	_sock = 255;
}


uint8_t WiFiClient::connected()
{
	return (status() == ESTABLISHED);
}


WiFiClient::operator bool()
{
  return _sock != 255;
}


////////////////////////////////////////////////////////////////////////////////
// Additional WiFi standard methods
////////////////////////////////////////////////////////////////////////////////


uint8_t WiFiClient::status()
{
	if (_sock == 255)
	{
		return CLOSED;
	}

	if (WizFi360Drv::availData(_sock))
	{
		return ESTABLISHED;
	}

	if (WizFi360Drv::getClientState(_sock))
	{
		return ESTABLISHED;
	}

	WizFi360Class::releaseSocket(_sock);
	_sock = 255;

	return CLOSED;
}

IPAddress WiFiClient::remoteIP()
{
	IPAddress ret;
	WizFi360Drv::getRemoteIpAddress(ret);
	return ret;
}

////////////////////////////////////////////////////////////////////////////////
// Private Methods
////////////////////////////////////////////////////////////////////////////////

size_t WiFiClient::printFSH(const __FlashStringHelper *ifsh, bool appendCrLf)
{
	size_t size = strlen_P((char*)ifsh);
	
	if (_sock >= MAX_SOCK_NUM or size==0)
	{
		setWriteError();
		return 0;
	}

	bool r = WizFi360Drv::sendData(_sock, ifsh, size, appendCrLf);
	if (!r)
	{
		setWriteError();
		LOGERROR1(F("Failed to write to socket"), _sock);
		delay(4000);
		stop();
		return 0;
	}

	return size;
}
