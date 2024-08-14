# ESP32 - Laser Counter

An ESP32-based open-source laser countermeasure system for research and educational purposes. Simulates various LIDAR gun models and explores infrared signal manipulation techniques.

**Exploring the science of light-based speed detection and countermeasures**
## Overview

ESP32-LaserCounter is an educational project aimed at understanding and experimenting with LIDAR technology and infrared signal manipulation. This system simulates various laser speed gun models and provides a platform for researching countermeasure techniques.

**IMPORTANT:** This project is intended for educational and research purposes only. The use of laser jammers or similar devices may be illegal in your jurisdiction. Always check and comply with local laws and regulations before building or using this device.

## Schematic

![OLD Schematic](https://github.com/captainzero93/ESP32-LaserCounter/blob/master/images/schematic.png)

The schematic shows the basic setup of the ESP32-LaserCounter system. on older chips:

- ESP32 development board (replacing the D1 Mini shown in the image)
- TIP102 NPN transistor for controlling high-power LEDs
- 940nm 12V LED Array for infrared output
- 3.3V voltage regulator for powering the ESP32
- 2.2k Ohm resistor for current limiting

Note: The schematic will be updated in future releases to reflect the move to the ESP32 platform and include additional components like the OLED display and input buttons.

## Features

- ESP32-based architecture for improved performance and connectivity
- 12V circuitry for automobile installation
- 940nm infrared LED array for signal emission
- Wireless connectivity with companion Android app
- Multiple laser gun emulation modes
- MIRT (Mobile Infrared Transmitter) mode simulation
- Over-the-air (OTA) firmware updates

## Hardware Requirements

| Component | Recommended Model |
|-----------|-------------------|
| ESP32 Development Board | LOLIN32 | 
| 2.2k Ohm Resistor | 1/4W 1% |
| 3.3V Voltage Regulator | AMS1117-3.3 |
| NPN Transistor | TIP102 |
| 940nm LED Array | 5W High Power IR LED |
| OLED Display | 0.96" I2C SSD1306 |

## Software Setup

1. Install the Arduino IDE (version 2.0 or later)
2. Add ESP32 board support to Arduino IDE
3. Install required libraries:
   - Adafruit GFX Library
   - Adafruit SSD1306
   - ArduinoJson
4. Clone this repository:
   ```
   git clone https://github.com/captainzero93/ESP32-LaserCounter.git
   ```
5. Open the `ESP32-LaserCounter.ino` file in Arduino IDE
6. Select your ESP32 board and port
7. Compile and upload the sketch

## Usage

1. Power on the device
2. Use the mode selection button to choose the desired operation mode
3. Point the device towards the target
4. Press the trigger button to activate

For detailed usage instructions, please refer to the [User Manual](docs/USER_MANUAL.md).

## Legal Disclaimer

This project is intended for educational and research purposes only. The use of laser jammers or similar devices may be illegal in your jurisdiction. Always check and comply with local laws and regulations. The creators and contributors of this project are not responsible for any misuse or legal consequences arising from the use of this device.

## Release History

- 0.2.0 (2024-08-14)
  - Migrated to ESP32 platform
  - Added OTA update functionality
  - Improved power management
- 0.1.0 (2023-03-15)
  - Added Android app support
  - Implemented multiple laser gun emulation modes
- 0.0.1 (2019-01-08)
  - Initial release, presented at SecKC

## Roadmap

- Update schematic to reflect ESP32 architecture and additional components
- Implement machine learning for adaptive signal generation
- Add support for multiple LED arrays
- Develop iOS companion app
- Improve power efficiency for longer battery life

## Meta

[Joe Faulkner] (captainzero93). (2024). [(https://github.com/captainzero93/ESP32-LaserCounter)](https://github.com/captainzero93/ESP32-LaserCounter)

Distributed under the GNU General Public License v3.0. See [LICENSE](LICENSE) for more information.

## Acknowledgments

- SecKC community for their support and feedback
- [Adafruit](https://www.adafruit.com/) for their excellent libraries and tutorials
- All contributors who have helped improve this project
