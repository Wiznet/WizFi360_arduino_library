# WizFi360 Arduino Library

## 목차

- [소개](#Introduction)
- [Step 1: 필수 구성 요소](#Prerequisites)
- [Step 2: Device 준비](#Prepare_Device)
- [Step 3: 동작 예제](#Example)
- [Step 4: 동작 예제 결과](#Result)



<a name="Introduction"></a>
## 소개
WizFi360 Arduino Library는 Arduino에 WizFi360을 결합하여 쉽게 사용 할 수 있도록 Library 및 Example을 제공합니다.

제공하는 Example은 다음과 같습니다.

- [ConnectWPA][link-connect_wpa]
- [ScanNetworks][link-scan_networks]
- [Thingspeak][link-thing_speak]
- [UdpNTPClient][link-udp_ntp_client]
- [UdpSendReceive][link-udp_send_receive]
- [WebClient][link-web_client]
- [WebClientRepeating][link-web_client_repeating]
- [WebClientSSL][link-web_client_ssl]
- [WebServer][link-web_server]
- [WebServerAP][link-web_server_ap]
- [WebServerLed][link-web_server_led]



<a name="Prerequisites"></a>
## Step 1: 필수 구성 요소

본 문서를 따라하기 전에 다음 항목이 준비되어야 합니다.

**Hadrware**
 - Desktop or Laptop Computer
 - [WizFi360-EVB-Shield][link-wizfi360-evb-shield]
 - [Arduino Mega 2560][link-arduino_mega_2560]
 - USB Type-B Cable

 ![][link-required_item]

**Software**
 - [Arduino IDE][link-arduino_ide_download]
 - Serial Terminal (TeraTerm, Hercules, etc . . .)



<a name="Prepare_Device"></a>
## Step 2: Device 준비

**1. Hardware 준비**

WizFi360-EVB-Shield는 Arduino Mega 2560과 결합을 하여 사용합니다. 따라서 WizFi360-EVB-Shield의 DIP Switch 설정 및 Jumper Cable 연결이 다음과 같이 필요합니다.

> * SW1 : Off
> * SW2 : Off
> * SW3 : On
> * WizFi360-EVB-Shield : D7 - Arduino Mega 2560 : 18
> * WizFi360-EVB-Shield : D6 - Arduino Mega 2560 : 19

![][link-set_wizfi360_evb_shield_dip_switch_and_connect_arduino_mega_2560]

**2. Device 연결**

Hardware 설정 후, USB Type-B Cable을 이용하여 Arduino Mega 2560을 Desktop 혹은 Laptop Computer와 연결을 합니다.

장치 관리자에서 Arduino Mega 2560과 연결된 COM Port를 확인 할 수 있습니다.

![][link-device_management]

> Arduino IDE를 정상적으로 설치를 하였다면 위와 같이 장치 관리자에서 COM Port를 확인 할 수 있습니다.
>
> 장치 관리자에서 COM Port를 확인 할 수 없는 경우, 다음 Link의 설명에 따라 설정 바랍니다.
>
> * [Manually install Drivers on Windows][link-manually_install_drivers_on_windows]



<a name="Example"></a>
## Step 3: 동작 예제

※ 본 문서는 ConnectWPA Example로 진행합니다.

**1. WizFi360 Arduino Library Download 및 Example 실행**

WizFi360 Arduino Library Download를 한 후, 실행하고자 하는 Example의 .ino 확장자를 선택하여 Project 실행합니다.

> * [WizFi360 Arduino Library][link-wizFi360 arduino library_download]

**2. Parameter 값 수정**

※ 본 문서는 Debugging을 위한 Serial, WizFi360과 통신을 위한 Serial의 Baudrate를 기존 설정 115,200으로 진행을 합니다.

AP(무선 공유기)에 연결하기 위하여, 다음의 Parameter를 수정합니다.

```cpp
/* Wi-Fi info */
char ssid[] = "xxxxxxxxxx";   // your network SSID (name)
char pass[] = "xxxxxxxxxx";   // your network password
```

![][link-modify_wifi_information_through_arduino_ide]

**3. Project Build 및 Upload**

사용하는 Board, COM Port 선택 후, Build 및 Upload를 수행합니다.

![][link-select_board_to_use_through_arduino_ide]

![][link-select_com_port_to_use_through_arduino_ide]

![][link-build_and_upload_through_arduino_ide]



<a name="Result"></a>
## Step 4: 동작 예제 결과

※ 본 문서는 Serial Terminal로 [TeraTerm][link-teraterm_download]을 사용합니다.

Terminal Program으로 WizFi360가 AP(무선 공유기)에 접속하고, SSID, BSSID 등의 정보가 출력되는 것을 확인 할 수 있습니다.

![][link-result_example_connect_wpa_through_teraterm]



[link-connect_wpa]: https://github.com/GiungKim/wizfi360_arduino_nepes/blob/master/examples/ConnectWPA/ConnectWPA.ino
[link-scan_networks]: https://github.com/GiungKim/wizfi360_arduino_nepes/blob/master/examples/ScanNetworks/ScanNetworks.ino
[link-thing_speak]: https://github.com/GiungKim/wizfi360_arduino_nepes/blob/master/examples/Thingspeak/Thingspeak.ino
[link-udp_ntp_client]: https://github.com/GiungKim/wizfi360_arduino_nepes/blob/master/examples/UdpNTPClient/UdpNTPClient.ino
[link-udp_send_receive]: https://github.com/GiungKim/wizfi360_arduino_nepes/blob/master/examples/UdpSendReceive/UdpSendReceive.ino
[link-web_client]: https://github.com/GiungKim/wizfi360_arduino_nepes/blob/master/examples/WebClient/WebClient.ino
[link-web_client_repeating]: https://github.com/GiungKim/wizfi360_arduino_nepes/blob/master/examples/WebClientRepeating/WebClientRepeating.ino
[link-web_client_ssl]: https://github.com/GiungKim/wizfi360_arduino_nepes/blob/master/examples/WebClientSSL/WebClientSSL.ino
[link-web_server]: https://github.com/GiungKim/wizfi360_arduino_nepes/blob/master/examples/WebServer/WebServer.ino
[link-web_server_ap]: https://github.com/GiungKim/wizfi360_arduino_nepes/blob/master/examples/WebServerAP/WebServerAP.ino
[link-web_server_led]: https://github.com/GiungKim/wizfi360_arduino_nepes/blob/master/examples/WebServerLed/WebServerLed.ino
[link-wizfi360-evb-shield]: https://wizwiki.net/wiki/doku.php/products:wizfi360:board:wizfi360-evb:start
[link-arduino_mega_2560]: https://store.arduino.cc/usa/mega-2560-r3
[link-required_item]: https://github.com/GiungKim/images/blob/master/wizfi360_arduino_nepes/required_item.png
[link-arduino_ide_download]: https://www.arduino.cc/en/main/software
[link-set_wizfi360_evb_shield_dip_switch_and_connect_arduino_mega_2560]: https://github.com/GiungKim/images/blob/master/wizfi360_arduino_nepes/set_wizfi360_evb_shield_dip_switch_and_connect_arduino_mega_2560.png
[link-device_management]: https://github.com/GiungKim/images/blob/master/wizfi360_arduino_nepes/device_menagement.png
[link-manually_install_drivers_on_windows]: https://www.arduino.cc/en/Guide/DriverInstallation
[link-wizFi360 arduino library_download]: https://codeload.github.com/GiungKim/wizfi360_arduino_nepes/zip/master
[link-modify_wifi_information_through_arduino_ide]: https://github.com/GiungKim/images/blob/master/wizfi360_arduino_nepes/modify_wifi_information_through_arduino_ide.png
[link-select_board_to_use_through_arduino_ide]: https://github.com/GiungKim/images/blob/master/wizfi360_arduino_nepes/select_board_to_use_through_arduino_ide.png
[link-select_com_port_to_use_through_arduino_ide]: https://github.com/GiungKim/images/blob/master/wizfi360_arduino_nepes/select_com_port_to_use_through_arduino_ide.png
[link-build_and_upload_through_arduino_ide]: https://github.com/GiungKim/images/blob/master/wizfi360_arduino_nepes/build_and_upload_through_arduino_ide.png
[link-teraterm_download]: https://osdn.net/projects/ttssh2/releases/
[link-result_example_connect_wpa_through_teraterm]: https://github.com/GiungKim/images/blob/master/wizfi360_arduino_nepes/result_example_connect_wpa_through_teraterm.png