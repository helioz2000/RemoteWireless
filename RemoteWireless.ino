#include "CC1101.h"

#define bufsize 61

byte tx_buf[bufsize]={0};
byte rx_buf[bufsize];
byte tx_len,rx_len, i;
bool waitRx = false;
int num = 0;



void setup()
{
  Serial.begin(9600);
  cc1101.Init();

  setup_tx();
}

void loop()
{  
  if (!waitRx) {
    tx();
    cc1101.SetReceive();
    waitRx = true;
  }
  rx();
}

void rx()
{
  bool mismatch = false;
  if(cc1101.CheckReceiveFlag())
  {
    rx_len=cc1101.ReceiveData(rx_buf);

    for (i=0; i < rx_len; i++) {
      if (rx_buf[i] != tx_buf[i])
        mismatch = true;
    }

    // print mismatch
    if (mismatch) {
      Serial.println("");
      Serial.print("RX: ");
      for(i=0;i<rx_len;i++)
      {
        Serial.print(rx_buf[i],DEC);
        Serial.print(' ');
      }
      Serial.println("");
    } else {
      Serial.println("Data RX OK");
    }
    waitRx = false;
    delay(2000);
  }  
}

void tx()
{ 
  tx_buf[0] = 2;
  tx_buf[1] = 9;
  tx_buf[2] = 9;
  tx_buf[3] = 0;
  tx_len = 4;
 
  cc1101.SendData(tx_buf,tx_len);
  Serial.print("Data sent <");
  Serial.print(++num,DEC);
  Serial.print("> - ");
}

void setup_rx()
{
  // RX only
  cc1101.SetReceive();
}

void setup_tx()
{

  /*
  for(i=0;i<size;i++)
  {
     buffer[i]=i;
  }
  */
}
