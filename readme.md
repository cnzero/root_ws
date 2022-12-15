
<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [语音交互方案](#语音交互方案)
- [ToDo](#todo)
- [Attention](#attention)
- [Q&A zhigui Chen](#qa-zhigui-chen)

<!-- /code_chunk_output -->

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

# Q&A zhigui Chen

- 哪里找到音频文件，能否直接发送音频文件的路径地址？
- 有关service回调函数的3个问题，`src/voice_control.cpp` L253 