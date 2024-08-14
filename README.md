# Not-Cotcha / Notcha-Cotcha

## Open Source ESP32-Based Laser Countermeasure / suite 

## Overview

Not-Cotcha (also known as Notcha-Cotcha) is an open-source project aimed at developing a laser countermeasure system based on the ESP32 platform. This project is for educational and research purposes only.

**IMPORTANT:** The use of laser jammers may be illegal in your jurisdiction. Always check and comply with local laws and regulations before building or using this device.

## Features

- ESP32-based architecture for improved performance and connectivity
- 12V circuitry for automobile installation
- 940nm brute force mode for effective countermeasures
- Wireless connectivity with companion Android app
- Laser gun emulation mode for testing and research
- MIRT (Mobile Infrared Transmitter) mode (use with extreme caution)
- Over-the-air (OTA) firmware updates

## Hardware Requirements

| Component | Recommended Model | Purchase Link |
|-----------|-------------------|----------------|
| ESP32 Development Board | LOLIN32 | [Amazon](https://www.amazon.com/dp/B08246MCL5) |
| 2.2k Ohm Resistor | 1/4W 1% | [Amazon](https://www.amazon.com/dp/B07HDFHPP3) |
| 3.3V Voltage Regulator | AMS1117-3.3 | [Amazon](https://www.amazon.com/dp/B07CP4P5XJ) |
| NPN Transistor | TIP102 | [Amazon](https://www.amazon.com/dp/B07PDCW2Z3) |
| 940nm LED Array | 5W High Power IR LED | [Amazon](https://www.amazon.com/dp/B07KW3VHVF) |
| OLED Display | 0.96" I2C SSD1306 | [Amazon](https://www.amazon.com/dp/B08RWMPZ69) |

## Schematic

![Schematic](https://github.com/hevnsnt/NOTCHACOTCHA/blob/master/images/schematic.png)

## Software Setup

1. Install the Arduino IDE (version 2.0 or later)
2. Add ESP32 board support to Arduino IDE
3. Install required libraries:
   - Adafruit GFX Library
   - Adafruit SSD1306
   - ArduinoJson
4. Clone this repository:
   ```
   git clone https://github.com/hevnsnt/NOTCHACOTCHA.git
   ```
5. Open the `notcha.ino` file in Arduino IDE
6. Select your ESP32 board and port
7. Compile and upload the sketch

## Usage

1. Power on the device
2. Use the mode selection button to choose the desired operation mode
3. Point the device towards the target
4. Press the trigger button to activate

For detailed usage instructions, please refer to the [User Manual](docs/USER_MANUAL.md).

## Android App

The companion Android app provides a user-friendly interface for controlling and monitoring the Not-Cotcha device. You can find the app source code and installation instructions in the [Android App Repository](https://github.com/hevnsnt/NOTCHACOTCHA-Android).

## Legal Disclaimer

This project is intended for educational and research purposes only. The use of laser jammers or similar devices may be illegal in your jurisdiction. Always check and comply with local laws and regulations. The creators and contributors of this project are not responsible for any misuse or legal consequences arising from the use of this device.

## Contributing

We welcome contributions to improve Not-Cotcha! Here's how you can help:

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

Please read [CONTRIBUTING.md](CONTRIBUTING.md) for details on our code of conduct and the process for submitting pull requests.

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

- Implement machine learning for adaptive countermeasures
- Add support for multiple LED arrays
- Develop iOS companion app
- Improve power efficiency for longer battery life

## Meta

Created by: Bill Swearingen – [@hevnsnt](https://twitter.com/hevnsnt) – bill@seckc.org

Distributed under the GNU General Public License v3.0. See [LICENSE](LICENSE) for more information.

For more projects, please visit [https://github.com/hevnsnt/](https://github.com/hevnsnt/)

## Acknowledgments

- SecKC community for their support and feedback
- [Adafruit](https://www.adafruit.com/) for their excellent libraries and tutorials
- All contributors who have helped improve this project
