
FAST-TAG Integrated RFID Toll System

📌 Project Overview

The FAST-TAG Integrated RFID Toll System is an embedded system designed to automate toll collection using RFID technology.

The system detects a vehicle using a GP2D12 distance sensor, reads the FASTag/RFID card through an RFID reader, verifies the card details stored in EEPROM, deducts the required toll amount, and automatically controls the toll gate using a DC motor.

🎯 Aim

The aim of the FAST-TAG Integrated RFID Toll System is to design and implement an automated toll collection system using RFID technology.

✨ Features

- Automatic vehicle detection using a GP2D12 distance sensor
- RFID/FASTag card identification
- RFID card data reception through UART
- Card and vehicle details stored in EEPROM
- Automatic balance deduction
- LCD-based status display
- Automatic toll gate opening and closing
- Manual recharge facility using keypad
- Manual toll payment facility
- Interrupt-based switch operation
- Embedded C implementation

🛠️ Hardware Requirements

- LPC2148 ARM7 Microcontroller
- RFID Reader
- RFID Cards
- 20×4 LCD
- 4×4 Matrix Keypad
- Switches
- AT24C256 EEPROM
- DC Motor
- GP2D12 Distance Sensor
- USB-to-UART Converter

💻 Software Requirements

- Embedded C
- Keil C Compiler
- Flash Magic

🔌 Communication Protocols

UART

UART is used for communication between the RFID reader and the LPC2148 microcontroller.

The RFID reader transmits the card number using a 9600 baud rate.

I2C

I2C is used for communication between the LPC2148 and the AT24C256 EEPROM, where card-related information and balance are stored.

🔄 System Working

1. The project name is displayed on the LCD.

2. The GP2D12 distance sensor detects a vehicle when it comes within approximately 10–15 cm.

3. The LCD displays:
   
   Welcome to Toll Plaza
   Waiting for card ....

4. The RFID card is placed near the RFID reader.

5. The RFID reader sends the card number through serial communication at 9600 baud.

6. The LPC2148 receives the card number using UART0 interrupt.

7. The controller checks the received card number against the predefined card information stored in EEPROM.

8. The LCD displays the FASTag ID, vehicle number, and available balance.

9. The required toll amount is deducted from the available balance.

10. The DC motor rotates clockwise to represent gate opening.

11. When the vehicle moves approximately 15 cm away from the sensor, the DC motor rotates anticlockwise to represent gate closing.

12. Two interrupt switches provide additional operations:
    
    - Switch 1: Manual recharge using the keypad.
    - Switch 2: Manual toll amount deduction using the keypad when there is an issue with the RFID/FASTag card.

📡 RFID Data Format

The RFID reader sends 10 bytes of data when an RFID card is placed near the reader.

For example, if the card number is:

"12345678"

The RFID reader output is:

0x02 0x31 0x32 0x33 0x34 0x35 0x36 0x37 0x38 0x03

Where:

- "0x02" → Start byte
- "0x31"–"0x38" → ASCII representation of the card number
- "0x03" → Stop byte

🧩 Modules

The project can be divided into the following modules:

- LCD Module
- Keypad Module
- UART Module
- RFID Module
- I2C Module
- EEPROM Module
- GP2D12 Sensor Module
- DC Motor/Gate Control Module
- Interrupt Module

🧪 Development Approach

The peripherals should be tested individually before integrating the complete system:

1. Test LCD with character, string, and integer display.
2. Test keypad and display the pressed key on LCD.
3. Test UART transmission and reception.
4. Test UART interrupt operation.
5. Connect the RFID reader and verify its output.
6. Read the RFID card number using UART0 interrupt.
7. Display the received card number on the LCD.
8. Test EEPROM/I2C communication.
9. Integrate the distance sensor.
10. Integrate DC motor gate control.
11. Integrate all modules into the complete toll system.


🔘 Interrupt Operations

Switch 1 — Recharge

When Switch 1 interrupt occurs:

- Recharge operation is selected.
- Amount is entered manually using the keypad.
- The balance can be updated in EEPROM.

Switch 2 — Manual Payment

When Switch 2 interrupt occurs:

- Manual payment operation is selected.
- The toll amount is entered through the keypad.
- The amount is deducted manually when there is an issue with the RFID/FASTag card.



🔧 Development Tools

IDE/Compiler: Keil C Compiler
Programming Language: Embedded C
Microcontroller: LPC2148
Programming Tool: Flash Magic

⚠️ Limitations

- The prototype is designed around the LPC2148, so its processing and memory resources are limited compared with modern microcontrollers.
- The RFID reader requires the card to be placed within its effective reading range.
- The GP2D12 sensor is used for vehicle detection within a limited distance range.
- Card and vehicle information is based on predefined data stored in EEPROM.


🚀 Future Scope

The project can be further enhanced to make it suitable for a more advanced and scalable toll-management system.
1. IoT Integration
The system can be connected to the Internet to send toll transactions and vehicle information to a cloud server for centralized monitoring.
2. Mobile Application
A mobile application can be developed to allow users to:
- Check FASTag balance
- View toll transactions
- Recharge the account
- Receive transaction notifications
3. Online Recharge
The manual keypad-based recharge can be replaced or supplemented with online recharge through a secure payment system.


⭐ Conclusion

The FAST-TAG Integrated RFID Toll System demonstrates how embedded systems can be used to automate toll collection. By integrating RFID, UART, I2C, EEPROM, LCD, keypad, distance sensing, interrupts, and motor control with the LPC2148, the system provides an automated approach to vehicle identification, toll deduction, and gate control.

  
👩‍💻 Author
Rakshitha



