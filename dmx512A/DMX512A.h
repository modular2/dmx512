#define DMX_SIZE        512
#define DMX_START_CODE  0
class DMX512A {
public:
      DMX512A(PinName p_tx, PinName p_rx, PinName p_xmit);
      void put(int addr, int data);
      void put(unsigned char *buf, int addr = 0, int len = DMX_SIZE);
      void start();
 protected:
       RawSerial _dmx;
       DigitalOut _xmit; 
      unsigned char data_tx[DMX_SIZE];
      unsigned char data_rx[DMX_SIZE];
      }; 
        