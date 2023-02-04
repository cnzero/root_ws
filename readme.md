
<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [语音交互方案](#语音交互方案)
- [ToDo](#todo)
- [Attention](#attention)
- [Q&A zhigui Chen](#qa-zhigui-chen)

<!-- /code_chunk_output -->

# 直接测试
启动 `roslaunch xf_mic_asr_offline_line limo.launch`，这一步应该直接就terminal里显示进行“你好小艺”的提醒，即等待被唤醒。

- Q：运行成功，但是一直都无法进行唤醒？
- A: 麦克风的USB连接，尽量往前面的USB-hub连接，后面一级的USB-hub可能无法支撑供电与通讯。

# 语音交互方案

1. 唤醒。
   当收听到唤醒词“你好小艺”时，对外发布：a-唤醒标志位，b-唤醒方位角。

2. 控制，对外发布如下字符串，代表的意义如下：
   - 字符串“L1”. “打开左灯”，“打开左边的灯”
   - 字符串“L0”. “关闭左灯”，“关闭左边的灯”
   - 字符串“R1”. “打开右灯”，“打开右边的灯”
   - 字符串“R0”. “关闭右灯”，“关闭右边的灯”

# ToDo

- [ ] 目前通过Windows中的串口工具修改了唤醒词"ni2 hao3 xiao3 yi4"，原来的唤醒词为“你好小薇”；但是经测试，这两个唤醒词均能够正常唤醒语音助手。
- [ ] 理清楚目前pulisher-subscriber问题

# Attention

- `src/voice_control.cpp` L233, L244的参数配置，是否需要修改，暂时还没有修改

# FAQ
- Q1:在不同的设备上如何使用`aplay ` 播放音频
A1: 首先使用`aplay xxx.wav`，如果无法播放出来，说明声卡没有选对。`aplay -D sysdefault:CARD=Device_1 xxx.wav` 这里选定了指定的设备。
如何找设备呢？使用`aplay -h` 看这个`aplay`的相关命令，尤其是`aplay -l` 或 `aplay -L` 

- Q2:


# Q&A zhigui Chen

- 哪里找到音频文件，能否直接发送音频文件的路径地址？
- 有关service回调函数的3个问题，`src/voice_control.cpp` L253 