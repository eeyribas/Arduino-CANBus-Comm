# Arduino-CANBus-Comm
Contains Arduino CAN-Bus communication applications. For CAN-Bus communication, the MCP2515 and MCP2551 integrated circuits are used alongside Arduino. These applications are: Receiver and Sender.

1. Sender: The Sender application sends 8-byte data to the Receiver application at specific intervals.

2. Receiver: The Receiver application receives the 8-byte data from the Sender application and prints it to the serial monitor.

Programming Language: C/C++ Programming Language

IDE: Arduino IDE Version - 2.2.0

Arduino Used: Arduino Uno

CAN-Bus Arduino Library: The CAN_BUS_Shield.zip library is used for CAN-Bus communication. Include this library in your Arduino IDE.

Arduino Connection Diagram: The connection between the Arduino and the MCP2515 and MCP2551 integrated circuits is shown in the (CAN-Bus Comm Breadbord.jpg) image.