#include "mbed.h"
#include "DMX512A.h"
DMX512A::DMX512A (PinName p_tx, PinName p_rx, PinName p_xmit)
 : _dmx(p_tx, p_rx),
 _xmit(p_xmit)
  {   
    _xmit=1;
    _dmx.baud(250000);
    _dmx.format(8, Serial::None, 2);
    }
void DMX512A::put (int addr, int data) {
    if (addr < 0 || addr >= DMX_SIZE) return;
    data_tx[addr] = data;
} 
void DMX512A::put (unsigned char *buf, int addr, int len) {
    if (addr < 0 || addr >= DMX_SIZE) return;
    if (len > DMX_SIZE - addr) len = DMX_SIZE - addr;
    memcpy(&data_tx[addr], buf, len);
} 
void DMX512A::start () {
    //send break
    _dmx.send_break();
    wait_us(88); 
    // send start code
     _dmx.putc(DMX_START_CODE);
    // send 512 channel
    for (int i=0;i<512;i++)
      _dmx.putc(data_tx[i]);
      
    } 