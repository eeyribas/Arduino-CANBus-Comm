#include <mcp_can.h>
#include <SPI.h>

MCP_CAN CAN0(10);                                    
unsigned char tmp[8] = {0, 1, 2, 3, 4, 5, 6, 7};

void setup()
{
  Serial.begin(115200);
  if (CAN0.begin(CAN_500KBPS) == CAN_OK)
    Serial.print("Can init ok!!\r\n");
  else 
    Serial.print("Can init fail!!\r\n");
}

void loop()
{
  CAN0.sendMsgBuf(0x00, 0, 8, tmp);  
  delay(100);
}