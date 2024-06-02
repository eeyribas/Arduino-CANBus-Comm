#include <mcp_can.h>
#include <SPI.h>

long unsigned int rxId;
unsigned char len = 0;
unsigned char rxBuf[8];

MCP_CAN CAN0(10);

void setup()
{
  Serial.begin(115200);
  CAN0.begin(CAN_500KBPS);
  pinMode(2, INPUT);
  Serial.println("MCP2515 Library Receive Example...");
}

void loop()
{
  if (!digitalRead(2)) {
    CAN0.readMsgBuf(&len, rxBuf);
    rxId = CAN0.getCanId();
    Serial.print("ID: ");
    Serial.print(rxId, HEX);
    Serial.print("  Data: ");

    for (int i = 0; i<len; i++) {
      if(rxBuf[i] < 0x10)
        Serial.print("0");

      Serial.print(rxBuf[i], HEX);
      Serial.print(" ");
    }
    Serial.println();
  }
}