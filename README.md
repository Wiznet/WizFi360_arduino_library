# Getting Started with WizFi360 Arduino Library & Examples

This document will guide through a series of steps from configuring development environment to running Arduino library and examples using the WIZnet's Wi-Fi product - [**WizFi360**][link-wizfi360].

- [**Development environment configuration**](#development_environment_configuration)
- [**Hardware requirements**](#hardware_requirements)
- [**Examples**](#examples)
- [**Example testing**](#example_testing)
    - [**Using WizFi360-EVB-Shield & Arduino Mega 2560**](#using_wizfi360_evb_shield_arduino_mega_2560)
    - [**Using WizFi360-EVB-Pico**](#using_wizfi360_evb_pico)



<a name="development_environment_configuration"></a>
## Development environment configuration

To test the WizFi360 Arduino library & examples, the development environment must be configured to use Arduino platform.

Please note that in this guide examples were configured and tested using **Arduino IDE** in **Windows** environment.

Before starting, download and install the Arduino IDE from the link below.

- [Arduino IDE][link-arduino_ide]

Additionally, if you are using WizFi360-EVB-Pico rather than WizFi360-EVB-Shield & Arduino Mega 2560, minor settings are required in the Arduino IDE.

It is necessary to add a package to use the evaluation board based on RP2040, and follows below steps to setup.

1. Run the Arduino IDE

2. Open Preferences

3. Add next link to Addtional Boards Manager URLs

```
https://github.com/earlephilhower/arduino-pico/releases/download/global/package_rp2040_index.json
```

![][link-add_boards_manager_urls]

4. Click the OK button to complete the setup



<a name="hardware_requirements"></a>
## Hardware requirements

WizFi360 Arduino Library & Examples supports two boards: **WizFi360-EVB-Shield** & **Arduino Mega 2560** and **WizFi360-EVB-Pico**.

With the WizFi360-EVB-Shield & Arduino Mega 2560, WizFi360-EVB-Shield is a development board for experiment, test and verification of WizFi360. WizFi360-EVB-Shield can also be used as an Arduino shield.

The other board, WizFi360-EVB-Pico, is based on Raspberry Pi RP2040 and adds Wi-Fi connectivity using WizFi360. It is pin compatible with Raspberry Pi Pico board and can be used for IoT Solution development.

For detailed information about each board, refer to the links below.

- [**WizFi360-EVB-Shield**][link-wizfi360-evb-shield] & [**Arduino Mega 2560**][link-arduino_mega_2560]

![][link-wizfi360-evb-shield_arduino_mega_2560_main]

- [**WizFi360-EVB-Pico**][link-wizfi360-evb-pico]

![][link-wizfi360-evb-pico_main]



<a name="examples"></a>
## Examples

Examples are available at `WizFi360_arduino_library/examples/` directory. As of now, following examples are provided.

- [**ConnectWPA**][link-connectwpa]
- [**ScanNetworks**][link-scannetworks]
- [**Thingspeak**][link-thingspeak]
- [**UdpNTPClient**][link-udpntpclient]
- [**UdpSendReceive**][link-udpsendreceive]
- [**WebClient**][link-webclient]
- [**WebClientRepeating**][link-webclientrepeating]
- [**WebClientSSL**][link-webclientssl]
- [**WebServer**][link-webserver]
- [**WebServerAP**][link-webserverap]
- [**WebServerLed**][link-webserverled]



<a name="example_testing"></a>
## Example testing

This section will guide through testing with ConnectWPA example as an example using WizFi360-EVB-Shield & Arduino Mega 2560 or WizFi360-EVB-Pico.



<a name="using_wizfi360_evb_shield_arduino_mega_2560"></a>
### Using WizFi360-EVB-Shield & Arduino Mega 2560



#### Step 1: Prepare software

The following serial terminal program is required for example test, download and install from below link.

- [**Tera Term**][link-tera_term]



#### Step 2: Prepare hardware

1. Combine WizFi360-EVB-Shield with Arduino Mega 2560.

2. Setup DIP switch on WizFi360-EVB-Shield.

- SW1 : Off
- SW2 : Off
- SW3 : On

3. Connect WizFi360-EVB-Shield and Arduino Mega 2560 with jumper cable.

- WizFi360-EVB-Shield : D7 - Arduino Mega 2560 : 18
- WizFi360-EVB-Shield : D6 - Arduino Mega 2560 : 19

![][link-connect_wizfi360-evb-shield_and_arduino_mega_2560_with_jumper_cable]

4. Connect Arduino Mega 2560 to desktop or laptop using USB type B cable.



#### Step 3: Setup Example

To test the example, minor settings shall be done in code.

1. Setup device setting according to device you use.

Serial port configuration is different depending on the board used.

- Arduino Mega 2560 : ARDUINO_MEGA_2560
- WizFi360-EVB-Pico : WIZFI360_EVB_PICO

```cpp
// setup according to the device you use
#define ARDUINO_MEGA_2560
```

2. Setup Wi-Fi configuration.

```cpp
/* Wi-Fi info */
char ssid[] = "wiznet";       // your network SSID (name)
char pass[] = "0123456789";   // your network password
```



#### Step 4: Build and Upload


1. After completing the configuration, click Verify button.

![][link-click_verify_button_1]

2. When the build is completed, click Upload button to upload the firmware to the Arduino Mega 2560.

![][link-click_upload_button_1]



#### Step 5: Run

1. Connect to the serial COM port of Arduino Mega 2560 with Tera Term.

![][link-connect_to_serial_com_port_1]

2. If the example works normally on Arduino Mega 2560, you can see the Wi-Fi connection log and infomation such as SSID, BSSID, etc.

![][link-see_wi-fi_connection_log_and_infomation_such_as_ssid_bssid_etc_on_arduino_mega_2560]



<a name="using_wizfi360_evb_pico"></a>
### Using WizFi360-EVB-Pico



#### Step 1: Prepare software

The following serial terminal program is required for example test, download and install from below link.

- [**Tera Term**][link-tera_term]



#### Step 2: Prepare hardware

1. Connect WizFi360-EVB-Pico to desktop or laptop using 5 pin micro USB cable.



#### Step 3: Setup Example

To test the example, minor settings shall be done in code.

1. Setup device configuration according to device you use.

Serial port configuration is different depending on the board used.

- Arduino Mega 2560 : ARDUINO_MEGA_2560
- WizFi360-EVB-Pico : WIZFI360_EVB_PICO

```cpp
// setup according to the device you use
#define WIZFI360_EVB_PICO
```

2. Setup Wi-Fi configuration.

```cpp
/* Wi-Fi info */
char ssid[] = "wiznet";       // your network SSID (name)
char pass[] = "0123456789";   // your network password
```



#### Step 4: Build and Upload

1. After completing the configuration, click Verify button.

![][link-click_verify_button_2]

2. When the build is completed, click Upload button to upload the firmware to the WizFi360-EVB-Pico.

![][link-click_upload_button_2]



#### Step 5: Run

1. Connect to the serial COM port of WizFi360-EVB-Pico with Tera Term.

![][link-connect_to_serial_com_port_2]

2. If the example works normally on WizFi360-EVB-Pico, you can see the Wi-Fi connection log and infomation such as SSID, BSSID, etc.

![][link-see_wi-fi_connection_log_and_infomation_such_as_ssid_bssid_etc_on_wizfi360-evb-pico]



<!--
Link
-->

[link-wizfi360]: https://docs.wiznet.io/Product/Wi-Fi-Module/WizFi360
[link-arduino_ide]: https://www.arduino.cc/en/software
[link-add_boards_manager_urls]: https://github.com/Wiznet/WizFi360_arduino_library/blob/main/static/images/add_boards_manager_urls.png
[link-wizfi360-evb-shield]: https://docs.wiznet.io/Product/Wi-Fi-Module/WizFi360/wizfi360_evb_shield
[link-arduino_mega_2560]: https://store.arduino.cc/collections/boards/products/arduino-mega-2560-rev3
[link-wizfi360-evb-shield_arduino_mega_2560_main]: https://github.com/Wiznet/WizFi360_arduino_library/blob/main/static/images/wizfi360-evb-shield_arduino_mega_2560_main.png
[link-wizfi360-evb-pico]: https://docs.wiznet.io/Product/Open-Source-Hardware/wizfi360-evb-pico
[link-wizfi360-evb-pico_main]: https://github.com/Wiznet/WizFi360_arduino_library/blob/main/static/images/wizfi360-evb-pico_main.png
[link-connectwpa]: https://github.com/Wiznet/WizFi360_arduino_library/tree/master/examples/ConnectWPA
[link-scannetworks]: https://github.com/Wiznet/WizFi360_arduino_library/tree/master/examples/ScanNetworks
[link-thingspeak]: https://github.com/Wiznet/WizFi360_arduino_library/tree/master/examples/Thingspeak
[link-udpntpclient]: https://github.com/Wiznet/WizFi360_arduino_library/tree/master/examples/UdpNTPClient
[link-udpsendreceive]: https://github.com/Wiznet/WizFi360_arduino_library/tree/master/examples/UdpSendReceive
[link-webclient]: https://github.com/Wiznet/WizFi360_arduino_library/tree/master/examples/WebClient
[link-webclientrepeating]: https://github.com/Wiznet/WizFi360_arduino_library/tree/master/examples/WebClientRepeating
[link-webclientssl]: https://github.com/Wiznet/WizFi360_arduino_library/tree/master/examples/WebClientSSL
[link-webserver]: https://github.com/Wiznet/WizFi360_arduino_library/tree/master/examples/WebServer
[link-webserverap]: https://github.com/Wiznet/WizFi360_arduino_library/tree/master/examples/WebServerAP
[link-webserverled]: https://github.com/Wiznet/WizFi360_arduino_library/tree/master/examples/WebServerLed
[link-tera_term]: https://osdn.net/projects/ttssh2/releases/
[link-connect_wizfi360-evb-shield_and_arduino_mega_2560_with_jumper_cable]: https://github.com/Wiznet/WizFi360_arduino_library/blob/main/static/images/connect_wizfi360-evb-shield_and_arduino_mega_2560_with_jumper_cable.png
[link-click_verify_button_1]: https://github.com/Wiznet/WizFi360_arduino_library/blob/main/static/images/click_verify_button_1.png
[link-click_upload_button_1]: https://github.com/Wiznet/WizFi360_arduino_library/blob/main/static/images/click_upload_button_1.png
[link-connect_to_serial_com_port_1]: https://github.com/Wiznet/WizFi360_arduino_library/blob/main/static/images/connect_to_serial_com_port_1.png
[link-see_wi-fi_connection_log_and_infomation_such_as_ssid_bssid_etc_on_arduino_mega_2560]: https://github.com/Wiznet/WizFi360_arduino_library/blob/main/static/images/see_wi-fi_connection_log_and_infomation_such_as_ssid_bssid_etc_on_arduino_mega_2560.png
[link-click_verify_button_2]: https://github.com/Wiznet/WizFi360_arduino_library/blob/main/static/images/click_verify_button_2.png
[link-click_upload_button_2]: https://github.com/Wiznet/WizFi360_arduino_library/blob/main/static/images/click_upload_button_2.png
[link-connect_to_serial_com_port_2]: https://github.com/Wiznet/WizFi360_arduino_library/blob/main/static/images/connect_to_serial_com_port_2.png
[link-see_wi-fi_connection_log_and_infomation_such_as_ssid_bssid_etc_on_wizfi360-evb-pico]: https://github.com/Wiznet/WizFi360_arduino_library/blob/main/static/images/see_wi-fi_connection_log_and_infomation_such_as_ssid_bssid_etc_on_wizfi360-evb-pico.png
