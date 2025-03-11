#include <mcp_can.h>
#include <SPI.h>

long unsigned int rx_id;
unsigned char length = 0;
unsigned char rx_buf[8];

MCP_CAN mcp_can(10);

void setup()
{
  Serial.begin(115200);
  mcp_can.begin(CAN_500KBPS);
  pinMode(2, INPUT);
  Serial.println("MCP2515 Library Receive Example...");
}

void loop()
{
  if (!digitalRead(2)) {
    mcp_can.readMsgBuf(&length, rx_buf);
    rx_id = mcp_can.getCanId();
    Serial.print("ID: ");
    Serial.print(rx_id, HEX);
    Serial.print("  Data: ");

    for (int i = 0; i < length; i++) {
      if (rx_buf[i] < 0x10)
        Serial.print("0");

      Serial.print(rx_buf[i], HEX);
      Serial.print(" ");
    }
    Serial.println();
  }
}