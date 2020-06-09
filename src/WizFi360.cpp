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


int16_t 	WizFi360Class::_state[MAX_SOCK_NUM] = { NA_STATE, NA_STATE, NA_STATE, NA_STATE };
uint16_t 	WizFi360Class::_server_port[MAX_SOCK_NUM] = { 0, 0, 0, 0 };


uint8_t WizFi360Class::wizfi360Mode = 0;


WizFi360Class::WizFi360Class()
{

}

void WizFi360Class::init(Stream* wizfi360Serial)
{
    LOGINFO(F("Initializing WizFi360 module"));
	WizFi360Drv::wifiDriverInit(wizfi360Serial);
}



char* WizFi360Class::firmwareVersion()
{
	return WizFi360Drv::getFwVersion();
}


int WizFi360Class::begin(const char* ssid, const char* passphrase)
{
    wizfi360Mode = 1;
	if (WizFi360Drv::wifiConnect(ssid, passphrase))
		return WL_CONNECTED;

	return WL_CONNECT_FAILED;
}


int WizFi360Class::beginAP(const char* ssid, uint8_t channel, const char* pwd, uint8_t enc, bool apOnly)
{
	if(apOnly)
        wizfi360Mode = 2;
    else
        wizfi360Mode = 3;
    
    if (WizFi360Drv::wifiStartAP(ssid, pwd, channel, enc, wizfi360Mode))
		return WL_CONNECTED;

	return WL_CONNECT_FAILED;
}

int WizFi360Class::beginAP(const char* ssid)
{
	return beginAP(ssid, 10, "", 0);
}

int WizFi360Class::beginAP(const char* ssid, uint8_t channel)
{
	return beginAP(ssid, channel, "", 0);
}


void WizFi360Class::config(IPAddress ip)
{
	WizFi360Drv::config(ip);
}

void WizFi360Class::configAP(IPAddress ip)
{
	WizFi360Drv::configAP(ip);
}



int WizFi360Class::disconnect()
{
    return WizFi360Drv::disconnect();
}

uint8_t* WizFi360Class::macAddress(uint8_t* mac)
{
	// TODO we don't need _mac variable
	uint8_t* _mac = WizFi360Drv::getMacAddress();
	memcpy(mac, _mac, WL_MAC_ADDR_LENGTH);
    return mac;
}

IPAddress WizFi360Class::localIP()
{
	IPAddress ret;
	if(wizfi360Mode==1)
		WizFi360Drv::getIpAddress(ret);
	else
		WizFi360Drv::getIpAddressAP(ret);
	return ret;
}

IPAddress WizFi360Class::subnetMask()
{
	IPAddress mask;
	if(wizfi360Mode==1)
    WizFi360Drv::getNetmask(mask);
	return mask;
}

IPAddress WizFi360Class::gatewayIP()
{
	IPAddress gw;
	if(wizfi360Mode==1)
		WizFi360Drv::getGateway(gw);
	return gw;
}


char* WizFi360Class::SSID()
{
    return WizFi360Drv::getCurrentSSID();
}

uint8_t* WizFi360Class::BSSID(uint8_t* bssid)
{
	// TODO we don't need _bssid
	uint8_t* _bssid = WizFi360Drv::getCurrentBSSID();
	memcpy(bssid, _bssid, WL_MAC_ADDR_LENGTH);
    return bssid;
}

int32_t WizFi360Class::RSSI()
{
    return WizFi360Drv::getCurrentRSSI();
}


int8_t WizFi360Class::scanNetworks()
{
	return WizFi360Drv::getScanNetworks();
}

char* WizFi360Class::SSID(uint8_t networkItem)
{
	return WizFi360Drv::getSSIDNetoworks(networkItem);
}

int32_t WizFi360Class::RSSI(uint8_t networkItem)
{
	return WizFi360Drv::getRSSINetoworks(networkItem);
}

uint8_t WizFi360Class::encryptionType(uint8_t networkItem)
{
    return WizFi360Drv::getEncTypeNetowrks(networkItem);
}


uint8_t WizFi360Class::status()
{
	return WizFi360Drv::getConnectionStatus();
}



////////////////////////////////////////////////////////////////////////////
// Non standard methods
////////////////////////////////////////////////////////////////////////////

void WizFi360Class::reset(void)
{
	WizFi360Drv::reset();
}


/*
void WizFi360Class::hardReset(void)
{
connected = false;
strcpy(ip, "");
digitalWrite(WIZFI360_RST, LOW);
delay(WIZFI360_HARD_RESET_DURATION);
digitalWrite(WIZFI360_RST, HIGH);
delay(WIZFI360_HARD_RESET_DURATION);
}
*/


bool WizFi360Class::ping(const char *host)
{
	return WizFi360Drv::ping(host);
}

uint8_t WizFi360Class::getFreeSocket()
{
  // WizFi360 Module assigns socket numbers in ascending order, so we will assign them in descending order
    for (int i = MAX_SOCK_NUM - 1; i >= 0; i--)
	{
      if (_state[i] == NA_STATE)
      {
          return i;
      }
    }
    return SOCK_NOT_AVAIL;
}

void WizFi360Class::allocateSocket(uint8_t sock)
{
  _state[sock] = sock;
}

void WizFi360Class::releaseSocket(uint8_t sock)
{
  _state[sock] = NA_STATE;
}


WizFi360Class WiFi;
