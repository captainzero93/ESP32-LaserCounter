# ESP32 - Laser Counter

An ESP32-based open-source laser countermeasure system for research and educational purposes. Simulates various LIDAR gun models and explores infrared signal manipulation techniques.

## Overview

ESP32-LaserCounter is an educational project aimed at understanding and experimenting with LIDAR technology and infrared signal manipulation. This system simulates various laser speed gun models and provides a platform for researching countermeasure techniques.

**IMPORTANT:** This project is intended for educational and research purposes only. The use of "laser jammers" or similar devices may be illegal in your jurisdiction. Always check and comply with local laws and regulations before building or using this device.

## Schematic

![Schematic](schematic.png)

Note: I recommend the ESP32 platform and to include additional components like the OLED display and input buttons;

- ESP32 development board (replacing the D1 Mini shown in the image)
- TIP102 NPN transistor for controlling high-power LEDs
- 940nm 12V LED Array for infrared output
- 3.3V voltage regulator for powering the ESP32
- 2.2k Ohm resistor for current limiting

## Features

- ESP32-based architecture for improved performance and connectivity
- 12V circuitry for automobile installation
- 940nm infrared LED array for signal emission
- Multiple laser gun emulation modes
- MIRT (Mobile Infrared Transmitter) mode simulation

## Hardware Requirements and Build Guide

### Components List

| Component | Recommended Model | Notes |
|-----------|-------------------|-------|
| ESP32 Development Board | ESP32-WROOM-32 or ESP32-WROVER-B | These modules offer good performance and built-in Wi-Fi/Bluetooth |
| 2.2k Ohm Resistor | 2.2k Ohm, 1/4W, 1% tolerance | Metal film resistors are recommended for better precision |
| 3.3V Voltage Regulator | XC6206P332MR | Low dropout regulator, better efficiency than AMS1117 |
| NPN Transistor | 2N2222A or BC547 | Modern, widely available alternatives to TIP102 |
| 940nm LED Array | Osram SFH 4550 or similar | 5W, 940nm, high-power IR LED |
| OLED Display | 0.96" I2C SSD1306 128x64 | Monochrome display, widely compatible with ESP32 |

**Note:** The exact models may vary based on availability and specific project requirements. Always check the datasheets and ensure compatibility with your design. I highly reccomend implementing a control button.

### Basic Assembly Instructions

1. Start with the ESP32 development board as the central component.
2. Connect the 3.3V Voltage Regulator (XC6206P332MR) to power the ESP32.
3. Use the 2.2k Ohm resistor for pull-up/pull-down purposes or current limiting, depending on your specific circuit design.
4. Connect the NPN Transistor (2N2222A or BC547) to control the high-power IR LED array.
5. Connect the 940nm LED Array (Osram SFH 4550 or similar) to the transistor.
6. Connect the OLED Display (0.96" I2C SSD1306) to the ESP32's I2C pins.

**Important:** This is a basic guide.

### Software Setup

1. **Install the Arduino IDE (version 2.0 or later)**:
   - Download the Arduino IDE from the official website.
   - Follow the installation instructions for your operating system.

2. **Add ESP32 board support to Arduino IDE**:
   - Open the Arduino IDE.
   - Go to **File > Preferences**.
   - In the **Additional Board Manager URLs** field, add the following URL: `https://dl.espressif.com/dl/package_esp32_index.json`.
   - Click **OK**.
   - Go to **Tools > Board > Board Manager**.
   - Search for "ESP32" and install the **ESP32 by Espressif Systems** package.

3. **Install required libraries**:
   - Go to **Sketch > Include Library > Manage Libraries**.
   - Search for and install the following libraries:
     - **Adafruit GFX Library**
     - **Adafruit SSD1306**
     - **ArduinoJson**

4. **Clone this repository**:
   - Open a terminal or command prompt.
   - Run the following command to clone the repository:
     ```bash
     git clone https://github.com/captainzero93/ESP32-LaserCounter.git
     ```

5. **Open the project file in Arduino IDE**:
   - Navigate to the cloned repository folder.
   - Open either `notcha.ino` or `MIRT-COTCHA.ino` file in the Arduino IDE.

6. **Select your ESP32 board and port**:
   - Go to **Tools > Board** and select your ESP32 board model.
   - Go to **Tools > Port** and select the port to which your ESP32 is connected.

7. **Compile and upload the sketch**:
   - Click the **Verify** button to compile the sketch.
   - Click the **Upload** button to upload the sketch to your ESP32 board.

## Usage

1. Power on the device
2. Use the mode selection button to choose the desired operation mode
3. Point the device towards the target
4. Press the trigger button to activate

## Legal Disclaimer

This project is intended solely for educational and research purposes. The creation, possession, or use of laser jammers, countermeasures, or similar devices may be illegal in many jurisdictions. By accessing, using, or contributing to this project, you acknowledge and agree to the following:

1. Legal Compliance: It is your sole responsibility to research, understand, and comply with all applicable local, state, and federal laws and regulations regarding the use of laser detection and countermeasure devices in your jurisdiction.

2. Intended Use: This project is designed for controlled, educational environments only. Any use of this device or its derivatives on public roads or in real-world traffic situations is strictly prohibited.

3. No Warranty: This project is provided "as is" without any warranties of any kind, either express or implied. The creators and contributors make no representations or warranties regarding the accuracy, functionality, or performance of this device.

4. Assumption of Risk: By using this project, you assume all risks associated with its use, including but not limited to legal, financial, and safety risks. You agree that the creators, contributors, and any affiliated parties shall not be held liable for any damages or legal issues arising from the use or misuse of this project.

5. Indemnification: You agree to indemnify, defend, and hold harmless the project creators, contributors, and any affiliated parties from and against any claims, liabilities, damages, losses, and expenses, including legal fees, arising out of or in any way connected with your access to or use of this project.

6. Ethical Use: You agree to use this project and its information ethically and responsibly, respecting the rights and safety of others at all times.

7. No Encouragement of Illegal Activities: Nothing in this project should be construed as encouragement to violate any laws or regulations. The project exists purely to further the understanding of LIDAR and related technologies.

8. Modification and Distribution: If you modify or distribute any part of this project, you are required to include this disclaimer and ensure that any recipients are also aware of these terms.

By using, contributing to, or distributing this project, you acknowledge that you have read, understood, and agreed to this disclaimer. If you do not agree to these terms, you must not use, access, or contribute to this project in any way.

## Roadmap

- Implement machine learning for adaptive signal generation
- Add support for multiple LED arrays
- Develop iOS/Android companion app
- Improve power efficiency

## License

This project is available under a dual licence:

1. **Non-Commercial Use**: For non-commercial purposes, this project is licenced under the Creative Commons Attribution-NonCommercial 4.0 International License (CC BY-NC 4.0). This allows for sharing and adaptation of the code for non-commercial purposes, with appropriate attribution.

2. **Commercial Use**: Any commercial use, including but not limited to selling the code, using it in commercial products or services, or any revenue-generating activities, requires a separate commercial licence. You must contact the project owner to discuss terms before deployment.

Please see the [LICENCE](LICENCE) file for full details on both licences.

By using this project, you agree to abide by the terms of the appropriate licence based on your intended use.

## Acknowledgments

- SecKC community for hosting the first presentation of this project
- Espressif Systems for developing the ESP32 and providing excellent documentation and tools
- Adafruit for their libraries, especially the Adafruit GFX Library and Adafruit SSD1306, which are crucial for this project
- All contributors who have helped improve this project through code contributions, bug reports, and feature suggestions (including those on Discord)
