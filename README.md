# HaawkingFoC

**HaawkingFOC**是一个包括有感FOC和无感FOC算法控制永磁同步电机PMSM、直流无刷电机BLDC等汇总仓库，涉及到电机控制算法、上位机程序、电机控制系统、硬件开发板等，包括
  - HaawkFOC(TM)：无感FOC算法，内置在第三代HX2000系列RISC-V DSP芯片中，如HXS320F280025C、HXS320F280039C、HXS320F280049C
  - HaawkingSmartControl(TM)：针对Haawking各系列芯片推出的电机控制系统，它包含对Haawking系列芯片的电机控制板设计、电机上位机软件及电机控制例程的开发
  - HaawkingDriveMaster(TM)：针对与HaawkingSmartControl控制板推出的配套驱动板，用于驱动永磁同步电机，BLDC电机等
  - LaunchBoard(TM)：集成了昊芯自主研发的H28x内核的RISC-V DSP芯片，集成昊芯调试器，主频高于国际友商同型号产品， 扩展资源丰富，包括SCI(UART)、FSI、eCAN、eQEP 等
  - Haawking Link(TM)：昊芯自主研发的RISC-V DSP芯片的仿真器，支持芯片调试和片内Flash烧写，无需安装驱动
  - Haawking IDE(TM)：基于Eclipse；界面与友商保持一致；不改变用户使用习惯，自研专用编译器、调试器、仿真器（HX-LINK）；多样化FLASH下载工具

## HaawkingSmartControl
### 电机控制例程开发测试
  - 1. PID开环控制
  - 2. ID闭环电流环控制
  - 3. PID闭环速度环控制
  - 4. FOC开环控制（不含编码器采集）
  - 5. FOC开环控制（含编码器采集）
  - 6. FOC闭环电流环控制
  - 7. FOC闭环速度环控制
  - 8. FOC闭环位置环控制

### HaawkingSmartControl上位机软件
本项目为Haawking SmartControl系列上位机软件，该上位机针对电机相关算法的部分参数进行GUI显示设计，用户可以更加方便的对电机进行控制，并更直观的观测到相关数据。

此上位机软件配合Haawking SmartControl系列控制板及Haawking DriveMaster驱动板使用。


### HaawkingDriveMaster控制板
HaawkingDriveMaster是针对与HaawkingSmartControl控制板推出的配套驱动板，用于驱动永磁同步电机，BLDC电机等。


## HaawkFoC
**HaawkFoC**方案的核心是HaawkFAST算法，是昊芯最新研发的电机参数软件估算器，此估算器仅根据HaawkFOC方案所提供的电机电流和电压信号就可以自动识别出电机参数： 
 - 转子磁通 Ψ
 - 转子磁通角度 θ
 - 电机定、转子电阻 Rs、 Rr
 - 电机定子电感 Ld 、Lq
 - 电机转轴的转速和转矩 ω、 T

HaawkFAST算法可在2分钟内实现电机参数的高精度估算，角度估算可在启动的第一个电周期内快速收敛，可以实现四象限稳定运行，可以实现低速下正反转的平滑切换，即使在停止转动下仍然保持角度的完整性，从而实现平滑的启动恢复，较好的低速性能，可实现零转速启动且低于1HZ运行，可以实现电机在线电阻辨识提升角度估算的准确性，HaawkFAST可替代机械编码器，加快控制系统的设计。


