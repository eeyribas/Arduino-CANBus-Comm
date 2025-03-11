#include <mcp_can.h>
#include <SPI.h>

MCP_CAN mcp_can(10);                                    
unsigned char tmp[8] = {0, 1, 2, 3, 4, 5, 6, 7};

void setup()
{
  Serial.begin(115200);
  if (mcp_can.begin(CAN_500KBPS) == CAN_OK)
    Serial.print("Can init ok!!\r\n");
  else 
    Serial.print("Can init fail!!\r\n");
}

void loop()
{
  mcp_can.sendMsgBuf(0x00, 0, 8, tmp);  
  delay(100);
}