#include "mbed.h"
#include "DMX512A.h"
DigitalOut myled(PC_6);
DMX512A dmx512(PD_5,PD_6,PD_4);
int main() {
    int addr;
    addr=0;
    //set background color green
    for (int i=0;i<170;i++)
      {
          dmx512.put(addr++,0x00);//red channel
          dmx512.put(addr++,0xff);//green channel
          dmx512.put(addr++,0x00);//blue channel
          }
          dmx512.start();
          addr=0;
    while(1) {
          wait(1.0); // 1 sec
          myled = !myled; // LED Flash
          dmx512.put(addr++,0xff);//red channel
          dmx512.put(addr++,0x00);//green channel
          dmx512.put(addr++,0x00);//blue channel
          dmx512.start();
          if (addr==510) addr=0;
          wait(1.0); // 1 sec
    }
}
