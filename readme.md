# DMX512 灯光控制项目
DMX512协议最先是由USITT（美国剧院技术协会）发展成为从控制台用标准数字接口控制调光器的方式。这个接口基于RS485 硬件接口，传输速率为250Kbps。在舞台灯光，景观灯控制领域得到广泛应用。 
#DMX512 帧结构
DMX512帧以break 信号开始。大于22bit，或者88 us。一个起始码，跟随其后的是512 个字节的通道，可以控制512 个通道，或者170个RGB 灯具。 
#起始码 
一般来讲，简单的设备开始码位0x00，代表后面的数据是灯光数据。DMX512 也可以传输RDM（远程设备管理协议） 这时起始码为0xCC。 

 Code| Meaning |Notes|
 ----|--------|------|
0000 0000 | Lighting Data|Default format
0101 0101|Network Test|All slots carry the same value
0001 0111|Text Packet|Simple text message
1100 1100|Remote DeviceManagement|RDMControl/Response message
1100 1111|System Information Packet|Identifies a DMX Universe
1111 1111|Dimmer Curve Select

# DMX512 物理接口
DMX512 使用RS485 接口，物理插头是5 针卡农头。   
Male | Female |
-----|--------|
Pin 1 (screen)| Pin 1 (screen)|
Pin 2 (Data -)| Pin 2 (Data -)|
Pin 3 (Data +)| Pin 3 (Data +)|
# DMX512A 协议的使用
DMX512 LED RGB 射灯，景观灯。每个灯具需要设置一个起始地址。  
DMX512 协议的舞台灯光，除了RGB 三个通道以外，可能包括灯光转向的控制通道 。
# 适合的Modular2 IO 扩展板
M2-RS485X4 四RS-485 模块
# 实例
参见 [DMX512 项目](https://github.com/modular2/dmx512)

