# HaawkFoC Projects and Labs User’s Guide For HXS320F280049C

## 目录

[TOC]



## 1.实验简介

| 解决方案 | 实验名称                                       | 介绍                                                         |
| -------- | ---------------------------------------------- | ------------------------------------------------------------ |
| FoC      | HXS320F280049C_EDC_is01_intro_hal              | HAL, Inverter setup and LED Blinking                         |
| FoC      | HXS320F280049C_EDC_is02_offset_gain_cal        | Offset/Gain calibration with CPU                             |
| FoC      | HXS320F280049C_EDC_is03_hardware_test          | Scalar control for hardware integrity verification with  CPU |
| FoC      | HXS320F280049C_EDC_is04_signal_chain_test      | Closed current loop without position angle for signal  chain verification |
| FoC      | HXS320F280049C_EDC_is05_motor_id               | Motor ID with CPU                                            |
| FoC      | HXS320F280049C_EDC_is06_torque_control         | Torque mode and tuning Id/Iq PI                              |
| FoC      | HXS320F280049C_EDC_is07_speed_control          | Speed mode and tuning speed PI                               |
| FoC      | HXS320F280049C_EDC_is08_overmodulation         | Space Vector Over-Modulation                                 |
| FoC      | HXS320F280049C_EDC_is09_flying_start           | Flying Start                                                 |
| FoC      | HXS320F280049C_EDC_is10_rs_recalc              | Rs Online Recalibration                                      |
| FoC      | HXS320F280049C_EDC_is11_dual_motor             | Dual Motor Control                                           |
| FoC      | HXS320F280049C_EDC_is12_variable_pwm_frequency | Online Variable Switching Frequencies                        |
| FoC      | HXS320F280049C_EDC_is13_fwc_mtpa               | Field-weakening and Maximum Torque Per Ampere  Control for IPM motor |

### 1.1实验题目概述

- HXS320F280049C_EDC_is01_intro_hal - CPU and Inverter Setup

Lab 01 covers how to use the HAL object to setup the F28004xC and inverter hardware.  HaawkFOC API function calls will be used to simplify the microprocessor setup.

- HXS320F280049C_EDC_is02_offset_gain_cal - Offset and Gain Calibration

Lab 02 demonstrates current and voltage offset calculation. Additionally, skipping auto-calibration  to reduce start-up time is demonstrated. Lab 02 also introduces the option to bypass the Rs Fine  Re-estimation.

- HXS320F280049C_EDC_is03_hardware_test – Open Loop Control for Hardware Integrity Verification

Lab 03 implements a scalar volts/frequency control to test the integrity of the hardware, namely 

the PWM and ADC modules for hardware abstraction layer (HAL) setup. While compatible with 

Haawking’ hardware, this lab is intended for custom hardware verification.

- HXS320F280049C_EDC_is04_signal_chain_test – Current Closed Loop Control for Signal Chain Integrity Verification

Lab 04 implements a volts/frequency closed current loop control to test the signal chain integrity, 

mainly the hardware current/voltage sensing circuitry and controller ADC module. While 

compatible with Haawking’ hardware, this lab is intended for custom hardware 

verification.

- HXS320F280049C_EDC_is05_motor_id – Motor Parameters Identification

HaawkFAST does not have to be executed completely out of ROM. Actually, most of the HaawkFAST 

code is provided as open source. The only closed source code is the HaawkFAST observer. This lab 

will show how to run the sensorless field oriented controller as open source in user RAM. The 

only function calls to ROM will be to update and to pull information from the HaawkFAST observer.

- HXS320F280049C_EDC_is06_torque_control – Torque Control Mode and Tuning Id/Iq PI Controller

For the current loop PI controllers, HaawkFAST calculates the starting Kp and Ki gains for both Id 

and Iq controllers. During start-up, HaawkFAST identifies the time constant of the motor to 

determine the Ki and Kp parameters. The Id and Iq controllers’ Kp and Ki gains may need to be 

manually adjusted for an optimal setting. Lab 06 demonstrates manually adjusting the current PI 

controller provided in the HaawkFAST software.

- HXS320F280049C_EDC_is07_speed_control – Speed Control Mode and Tuning Speed PI Controller

HaawkFOC provides a standard PI speed controller. The HaawkFAST library will give a “rule of 

thumb” estimation of Kp and Ki for the speed controller based on the maximum current setting in 

user.h. The estimated PI controller gains are a good starting point, but to obtain better dynamic 

performance, the Kp and Ki terms need to be tuned based on the whole mechanical system that 

the motor is running. This lab will show how to adjust the Kp and Ki terms in the PI speed 

controller.

- HXS320F280049C_EDC_is08_overmodulation – Space Vector Over-Modulation

The SVM that is used by HaawkFAST is capable of saturating to a pre-specified duty cycle. When 

using a duty cycle over 100.0%, the SVM is considered to be in the over-modulation region. When 

in the over-modulation region, low-side inverter leg current shunt measurement windows become 

small or even disappear. This lab will show how to re-create the currents that cannot be 

measured due to high duty cycles during SVM over-modulation.

- HXS320F280049C_EDC_is09_flying_start – Using Flying Start (Motor rotor is already moving)

The lab uses the flying start function to track and control an already rotating motor and resume 

normal operation with a minimal impact on load or speed.

- HXS320F280049C_EDC_is10_rs_recalc – Using Rs Online Recalibration

With the motor under heavy load, Rs Online Recalibration is required to maintain the performance 

of HaawkFAST. This lab will explore using this feature.

- HXS320F280049C_EDC_is11_dual_motor – Dual Motor Sensorless Velocity Control

Sensorless HaawkFOC is implemented to control two inverters independently with one HX2000 

RISC-V DSP. Currently only supports LaunchBoard-F280049C + YuZhou_V1.2.

- HXS320F280049C_EDC_is12_variable_pwm_frequency – Online Variable Switching Frequencies

The lab applies online variable switching frequency feature in HaawkFOC that allows the drive

to change FETs switching frequency to optimize the motor drive efficiency without changing any 

more control parameters. 

- HXS320F280049C_EDC_is13_fwc_mtpa – Field Weakening and Maximum Torque per Ampere Control

This lab implements the Field Weakening (FW) and Maximum Torque Per Ampere (MTPA) 

controlled three-phase Interior Permanent Magnet Synchronous Motor (IPMSM) over a wide 

speed range in an HaawkFOC project. The operation mode will automatically change from 

constant torque region with MTPA control to constant power region with FW control based on the 

speed command and the input DC-link voltage.

### 1.2实验硬件



#### 1.2.1 DSC280049C LaunchBoard板

LaunchBoard DSc280049C是一款基于昊芯HXS320F280049C的开发板。此开发板带有板载的HX-Link 110V-ISO的隔离调试器，只需一根USB线缆即可展开评估，板载调试器可以实现IDE中的对程序进行在线调试，Flash工程支持2个硬件断点，如果是RAM工程，断点的数量则没有限制。

HXS320F280049C是一款基于RISC-V 指令集架构的DSP芯片，主频最高160MHz器件，3.3V 单电源，集成型加电和欠压复位，两个内部零引脚振荡器，多达40个复用通用输入输出(GPIO) 引脚，三个 32 位CPU 定时器，串行端口外设 (SCI/SPI/I2C)，增强型控制外设，增强型脉宽调制器 (ePWM)，高分辨率PWM (HRPWM)，增强型捕捉 (eCAP)，模数转换器(ADC)。

Launchboard提供了ADC、ePWM、SCI、eQEP、FSI等多种外设接口，另外LaunchBoard还带有板载的CAN 收发器，可以用来进行CAN 2.0B的评估和验证。板子引出了2个BoosterPack的兼容排针接口，可以连接多种类型的BoosterPack扩展板和接口兼容的驱动板，如YuZhou_V1.2驱动板。

![实验硬件-DSC280049C_LaunchBoard](C:\Users\Administrator\Downloads\实验硬件-DSC280049C_LaunchBoard.jpg)

控制板和驱动板的链接图，如下所示：

![实验硬件-控制板和驱动板连接图](C:\Users\Administrator\Downloads\实验硬件-控制板和驱动板连接图.jpg)

因为DSC280049C的LaunchBoard支持不同的硬件，在与YuZhou_V1.2驱动板联合工作的时候，在硬件电路方面需要做调整（一些电阻需要去掉和焊接）：

| 需去掉的电阻 | 需焊接的电阻 | 备注        |
| ------------ | ------------ | ----------- |
| R210         | R202         |             |
| R308         | R203         |             |
| R307         | R305         |             |
| R306         | R207         |             |
| R209         | R321         | 外部3.3VREF |
| R303         |              |             |
| R208         |              |             |
| R311         | R222         |             |
| R312         | R217         |             |
| R221         |              |             |
| R216         |              |             |

对于R321电阻来说，如果不焊接，需要通过杜邦线，将3.3V电源和ADC的VREFHI脚进行连接；否则，ADC的采样数据将不准确。

##### 1.2.1.1电机1的连线



三相电流、三相电压及母线电压采样引脚配置和ADC触发源，如下表所示：

| 电压/电流 | ADC引脚 | ADC结果寄存器 |
| --------- | ------- | ------------- |
| Ia        | ADC C0  | ADC Result C0 |
| Ib        | ADC B2  | ADC Result B0 |
| Ic        | ADC B1  | ADC Result B1 |
| Va        | ADC A5  | ADC Result A1 |
| Vb        | ADC B0  | ADC Result B2 |
| Vc        | ADC C2  | ADC Result C1 |
| VBus      | ADC C4  | ADC Result C2 |

ADC中断的触发源，由ADCA的中断1，在SOC1采样完成后触发。

```c
// configure the interrupt sources
  // configure the ample window to 15 system clock cycle wide by assigning 14
  // to the ACQPS of ADCSOCxCTL Register.
  // RA1/A1
  ADC_setInterruptSource(obj->adcHandle[0], ADC_INT_NUMBER1, ADC_SOC_NUMBER1);
```

ePWM控制MOS管的开通和关闭，具体的拓扑如下所示：

| ePWM    | LaunchBoard引脚 | YuZhou_V1.2 | 备注 |
| ------- | --------------- | ----------- | ---- |
| ePWM 6A | IO_10           | A_H         |      |
| ePWM 6B | IO_11           | A_L         |      |
| ePWM 5A | IO_8            | B_H         |      |
| ePWM 5B | IO_9            | B_L         |      |
| ePWM 3A | IO_4            | C_H         |      |
| ePWM 3B | IO_5            | C_L         |      |

##### 1.2.1.2电机2的连线

三相电流、三相电压及母线电压采样引脚配置和ADC触发源，如下表所示：

| 电压/电流 | ADC引脚 | ADC结果寄存器 |
| --------- | ------- | ------------- |
| Ia        | ADC C5  | ADC Result C3 |
| Ib        | ADC C3  | ADC Result C4 |
| Ic        | ADC C1  | ADC Result C5 |
| Va        | ADC A6  | ADC Result A0 |
| Vb        | ADC A2  | ADC Result A2 |
| Vc        | ADC C14 | ADC Result C6 |
| VBus      | ADC A8  | ADC Result A3 |

ADC中断的触发源，由ADCC的中断1，在SOC6采样完成后触发。

```c
// configure the interrupt sources
  // configure the ample window to 15 system clock cycle wide by assigning 14
  // to the ACQPS of ADCSOCxCTL Register.
  // RA1/A1
  ADC_setInterruptSource(obj->adcHandle[2], ADC_INT_NUMBER1, ADC_SOC_NUMBER6);
```

ePWM控制MOS管的开通和关闭，具体的拓扑如下所示：

| ePWM    | LaunchBoard引脚 | YuZhou_V1.2 | 备注 |
| ------- | --------------- | ----------- | ---- |
| ePWM 1A | IO_0            | A_H         |      |
| ePWM 1B | IO_1            | A_L         |      |
| ePWM 4A | IO_6            | B_H         |      |
| ePWM 4B | IO_7            | B_L         |      |
| ePWM 2A | IO_2            | C_H         |      |
| ePWM 2B | IO_3            | C_L         |      |



#### 1.2.2 YuZhou_V1.2驱动板

该模块具有独立的直流总线和相位电压传感以及用于无传感器 BLDC 控制算法的独立低侧电流分流传感：

- 12V 至 48V 电压电源输入
- 支持最大峰值 20A 的 15A 连续电流输出
- 为 BLDC 无传感器控制解决方案提供相位电压和电流反馈
- 超小型完整无刷直流驱动级
- 驱动级受到全面保护，包括短路、过热、击穿和欠压保护

![实验硬件-YuZhou_V1.2驱动板](C:\Users\Administrator\Downloads\实验硬件-YuZhou_V1.2驱动板.jpg)

由于YuZhou_V1.2驱动板的尺寸问题，在进行双电机调试的时候，没办法直接接插到DSC280049C的LaunchBoard板上，需要加高一个驱动板，如下图所示：

![实验十一-双电机控制接线图](C:\Users\Administrator\Downloads\实验十一-双电机控制接线图.png)

#### 1.2.3 YuZhou_V1.3驱动板

该模块具有独立的直流总线和相位电压传感以及用于无传感器 BLDC 控制算法的独立低侧电流分流传感：

- 12V 至 60V 电压电源输入
- 支持最大峰值 66A 的 33A 连续电流输出
- 为 BLDC 无传感器控制解决方案提供相位电压和电流反馈
- 超小型完整无刷直流驱动级
- 驱动级受到全面保护，包括短路、过热、击穿和欠压保护

![实验一YuZhou_V1P3_驱动板](C:\Users\Administrator\Downloads\实验一YuZhou_V1P3_驱动板.png)

双电机接线图，如下所示：

![实验一YuZhou_V1P3_双电机接线图](C:\Users\Administrator\Downloads\实验一YuZhou_V1P3_双电机接线图.png)





#### 1.2.3 电源及电机

##### 1.2.3.1低压直流伺服电机

实验用的电机是一款低压直流伺服电机，产品型号为ZLAC60ASM400。

![ZLAC60ASM400-电机外观和尺寸图](C:\Users\Administrator\Downloads\ZLAC60ASM400-电机外观和尺寸图.png)



![ZLAC60ASM400-电机电气参数表](C:\Users\Administrator\Downloads\ZLAC60ASM400-电机电气参数表.png)



![ZLAC60ASM400-电机接线定义](C:\Users\Administrator\Downloads\ZLAC60ASM400-电机接线定义.png)

##### 1.2.3.2海立新能源压缩机

![海立压缩机外观图](C:\Users\Administrator\Downloads\海立压缩机外观图.png)

![海立压缩机参数](C:\Users\Administrator\Downloads\海立压缩机参数.png)

额定输入电压是24V;
额定电流约6A;
额定转速3000;
弱磁最大转速4500;
弱磁最大电流不明。

HaawkFAST估算出来的参数如下：

![海立压缩机估算参数](C:\Users\Administrator\Downloads\海立压缩机估算参数.png)



##### 1.2.3.3电源

电源则采用**wanptek可调直流稳压电源表**，可以输出120V-3A，满足实验的需求；实验中，一般选择24V就可以。

![APS1203H-直流稳压电源](C:\Users\Administrator\Downloads\APS1203H-直流稳压电源.png)



#### 1.2.4 Freemaster图形化调试界面

DSC280049C LaunchBoard板载USB-SCI的芯片，可以通过将拨码开关SW206的两个开关拨到00的位置，与电脑通信，SCI接口使用的引脚为GPIO28（RX）和GPIO29（TX）。

```
//freemaster
/*初始化串口通信的GPIO口*/
/*GPIO28: SCIRXDA*/
/*GPIO29: SCITXDA*/
InitSciGpio();
/*SCI寄存器配置*/
Scia_Config(115200);
FMSTR_Init();
```

![实验三-三相电流5Hz](C:\Users\Administrator\Downloads\实验三-三相电流5Hz.png)

### 1.3实验资源

为了更好的让学员参与到项目中，我们选择了将所有的硬件和软件进行开源，仓库地址在Github上面，仓库地址为：`https://github.com/JunningWu/HaawkingFoC/tree/main/YuZhou1.0`。

![Github仓库代码结构](C:\Users\Administrator\Downloads\Github仓库代码结构.png)

如上图所示，docs文件夹会放一些实验相关的说明文档，hardware文件夹会放LaunchBoard和驱动板的原理图和PCB文件，software文件夹会存放相关工程的源文件（主要是Haawking IDE的工程代码），如下所示：

![Github仓库software代码结构](C:\Users\Administrator\Downloads\Github仓库software代码结构.png)





### 1.4参与人员

课程负责人：Junning Wu

技术指导：Aihong Kang

首席助教：Hao Zhen

优秀学员：xxx



## 2.实验

### 2.1实验一：HXS320F280049C_EDC_is01_intro_hal

#### 2.1.1摘要

本实验主要介绍如何使用HAL驱动库来配置HXS320F280049C的硬件，来控制电机和逆变器，通过调用HaawkFoC SDK开发套件的API接口函数，来很方便地配置芯片完成目标任务。

#### 2.1.2引言

HAL，也就是Hardware Abstraction Layer的简称，也就是硬件抽象层，在HaawkFoC SDK的开发套件和工程中并未使用“位域库”，而是更易于移植的HAL库。第一个实验主要是介绍如何使用HAL库，配置HXS320F280049C的时钟、GPIOs、看门狗、ePWM、ADC等外设模块。

如下图所示，不同于“位域”库，需要对外设寄存器的bit位进行直接配置，HAL库更便于在不同型号的芯片间进行迁移：

- HAL 模块是唯一可以与硬件交互的模块。在这个上下文中，硬件包括 RISC-V DSP 外设和板级功能。
- 不应在用户接口级别进行外设配置，因为这样不利于代码的可移植性。
- 时间关键的 HAL 函数应内联，以加快执行速度。
- 应避免使用宏，而应使用内联函数代替。



![实验一HAL库架构图](C:\Users\Administrator\Downloads\实验一HAL库架构图.png)

HAL库的定义和API接口函数，可以在hal_obj.h中找到；后续所有的实验都是基于本实验进行扩展的，所以强烈建议学习者以此为基础，再进行后续的开发。

目前HXS320F280049C_EDC提供的_HAL_Obj_，包括全部的外设模块，如下所示：

```
//! \brief      Defines the hardware abstraction layer (HAL) data
//! \details    The HAL object contains all handles to peripherals.  When accessing a
//!             peripheral on a processor, use a HAL function along with the HAL handle
//!             for that processor to access its peripherals.
//!

typedef struct _HAL_Obj_
{
  uint32_t      adcHandle[3];       //!< the ADC handles

  uint32_t      adcResult[3];       //!< the ADC results

  uint32_t      claHandle;          //!< the CLA handle

  uint32_t      pwmHandle[3];       //<! the PWM handles

  uint32_t      timerHandle[3];     //<! the timer handles

  uint32_t      sciHandle[2];       //!< the SCI handle

  uint32_t      spiHandle[2];       //!< the SPI handle

  uint32_t      pgaHandle[3];       //!< the PGA handle

  uint32_t      cmpssHandle[3];     //!< the CMPSS handle

  uint32_t      dacHandle[2];       //!< the DAC handle

  uint32_t      dmaHandle;          //!< the DMA handle
  uint32_t      dmaChHandle[4];     //!< the DMA Channel handle

  float32_t       current_sf;         //!< the current scale factor, amps/cnt

  float32_t       voltage_sf;         //!< the voltage scale factor, volts/cnt

  uint16_t      numCurrentSensors;  //!< the number of current sensors
  uint16_t      numVoltageSensors;  //!< the number of voltage sensors

  uint32_t      pwmDACHandle[4];    //<! the PWMDAC handles

  float32_t       dcbus_voltage_sf;   //!< the voltage scale factor, volts/cnt

  bool          flagEnablePWM;     //<! the pwm enable flag

} HAL_Obj;
```

常见的一些HAL库函数API接口，如下所示：

```
HAL_getTimerStatus()
HAL_getPwmEnableStatus()
HAL_getNumVoltageSensors()
HAL_getNumCurrentSensors()
HAL_getDutyCycles()
HAL_getCurrentScaleFactor()
HAL_enableGlobalInts()
HAL_getVoltageScaleFactor()
HAL_initIntVectorTable()
HAL_readADCDataWithOffsets()
HAL_readTimerCnt()
HAL_setGPIOHigh()
HAL_readGPIOData()
HAL_setGPIOLow()
HAL_setNumCurrentSensors()
HAL_setupADCs()
HAL_setupGPIOs()
HAL_setupPeripheralClks()
HAL_setupPIE()
HAL_setupSCIA()
HAL_setupSPIA()
HAL_setupSPIB()
HAL_setupTimers()
HAL_writePWMData()
HAL_enablePWM()
```

这些 API 是配置设备外设或一组外设的 API。其中一些函数被转换为对外设配置 API 的单个函数调用，尽管如此，它们仍然是必需的，以确保软件架构的可移植性。



#### 2.1.3学习目标

- 学会使用HAL库配置HXS320F280049C
- 学会使用HAL库配置和初始化逆变器和电机控制系统
- 学会使用枚举类型元素，选择合适的外设配置

#### 2.1.4背景

整个工程的配置，都是调用HAL_obj的API接口函数，初始化的流程如下图所示

![image-20240625172140333](C:\Users\Administrator\Downloads\实验一初始化流程图.png)

下图所示是电机控制的系统框图，

![image-20240625173507766](C:\Users\Administrator\Downloads\实验一电机系统结构框图.png)

对于本实验以及后续的所有实验，代码的框架如下图所示。包括HXS320F280049C的驱动文件haawking-drivers，HaawkFoC相关的代码src_fast、src_foc、src_utilities等。本实验使用的硬件包括LaunchBoard_DSC280049C_V1.0控制板和YuZhou_V1.2驱动板。

![实验一工程架构和代码](C:\Users\Administrator\Downloads\实验一工程架构和代码.png)

![image-20240625175017353](C:\Users\Administrator\Downloads\实验一HaawkFoC代码.png)

可以直接导入到Haawking IDE中进行查看本实验的源码（注：欢迎使用最新版的Haawking IDE，演示版本为Haawking IDE V2.2.11Pre）。

如果不会使用Haawking IDE查看全局变量和函数定义，可以参考Haawking IDE根目录下的《Haawking-IDE User's Guide.pdf》文档。在本实验中，需要重点关注的全局变量为HAL_Handle和USER_Params。

![实验一全局变量](C:\Users\Administrator\Downloads\实验一全局变量.png)

#### 2.1.5调试步骤

**初始化配置**

本节涵盖了设置微控制器和HaawkFOC软件所需的核心功能。下表中仅列出了电机控制所必需的功能；一些功能虽然存在与工程中，但并未列出，这些功能是为了增强实验的功能，并不是设置驱动器所必需的。关于函数参数和返回值的更详细解释，请参阅《Haawking_HaawkFOC用户指南_V1.0.pdf》的电机控制部分。

![实验一初始化核心函数介绍](C:\Users\Administrator\Downloads\实验一初始化核心函数介绍.png)

**mainISR主中断**

在mainISR()中断服务程序中运行的代码都是关键任务，很重要的一点就是要实时运行。在本实验中，mainISR()会闪烁LED灯、读取ADC结果寄存器值（三相电流、三相电压和母线电压）；同时，PWM寄存器的值也会通过调用HAL_writePWMData()来完成周期性更新。在初始化的时候，会通过向pwm寄存器中写入0来实现50%占空比的波形输出。

![实验一mainISR代码](C:\Users\Administrator\Downloads\实验一mainISR代码.png)

LED的闪烁频率为1Hz，通过counterLED变量的递增来控制，在本实验中，PWM的开关频率是15KHz，用来触发ADC中断，也就是mainISR的执行频率。LED灯由GPIO34控制，即LaunchBoard板上的LED202。

![实验一mainISR代码LED](C:\Users\Administrator\Downloads\实验一mainISR代码LED.png)

将工程（HXS320F280049C_EDC_is01_intro_hal）导入到Haawking IDE中，链接LaunchBoard，下载程序，全速运行，应该可以看到LED202（绿色灯）闪烁，闪烁频率为1Hz。

#### 2.1.6结论

本实验主要是为了展示如何使用HAL库来配置F280049，并且把电机控制的整个框架进行了搭建，用到的源码和函数，也都集成到整个工程中，为后续的实验打好了基础。

### 2.2实验二：HXS320F280049C_EDC_is02_offset_gain_cal

#### 2.2.1摘要

本实验项目“HXS320F280049C_EDC_is02_offset_gain_cal”介绍了电机控制中电流和电压偏移及补偿的概念，这对保证电流和电压反馈信号的采样质量非常重要。本实验还介绍了如何跳过偏移校准以减少启动时间的配置选项。

#### 2.2.2引言

对于典型的用法，在首次启用HaawkFOC后，就会进行偏移校准。在校准期间，将测量并记录电流和电压反馈电路的偏移量。在初始版校准后，应该根据用户头文件中的特定硬件更新这些偏移值，以便在项目编译后向控制器提供它们。在电机运行期间，这些偏移量从ADC测量到的结果寄存器中减去，以向HaawkFOC估计器和矢量控制器提供准确的电压和电流反馈。

#### 2.2.3学习目标

- 针对特定电路板中使用的硬件组件，根据需要实现偏移重新校准，并使用偏移重新校准来验证特定的硬件。
- 将电流和电压偏移量写入HAL对象，以减少电机启动前的校准时间。
- 跳过偏移校准，减少了电机启动前的校准时间。

#### 2.2.4背景

在三相电机FOC（Field-Oriented Control，磁场定向控制）控制中，电流和电压的精确测量和控制是实现高效和稳定运行的关键。

- **提高测量精度**

  - 电流校准

    - **偏置电流**：由于电流传感器在没有电流流过时可能会有一个偏置电流值，校准可以消除这个偏置，使得测量的电流更加准确。

    - **传感器增益误差**：传感器的增益可能会有偏差，校准可以调整增益系数，确保测量的电流值与实际值一致。

  - 电压校准

    - **偏置电压**：电压传感器在没有输入电压时可能会有一个偏置电压值，校准可以消除这个偏置，使得测量的电压更加准确。

    - **传感器增益误差**：传感器的增益可能会有偏差，校准可以调整增益系数，确保测量的电压值与实际值一致。

- 提升控制精度

FOC控制需要对电机定子电流进行精确的矢量控制，这依赖于准确的电流和电压测量。如果测量值不准确，FOC算法中的数学模型将会偏离实际情况，导致控制不精确，影响电机性能。

- 提高系统稳定性

准确的电流和电压测量可以提高系统的反馈精度，使控制器能够快速响应并调整电机运行状态，从而提高系统的稳定性，减少震荡和振动。

- 保护电机和系统

不准确的电流和电压测量可能会导致电机运行在不安全的状态下，如过电流或过电压，这可能会损坏电机或其他系统组件。校准可以确保测量值准确，及时检测并避免这些危险情况。

- 提高效率

准确的电流和电压测量可以优化电机的运行状态，使电机始终运行在高效区间，减少能量损耗，提高整体系统效率。

- 适应环境变化

环境温度、湿度等变化会影响传感器的性能，通过校准可以在不同环境条件下保持测量的准确性，确保系统在各种环境下都能正常工作。

- 满足高性能应用需求

在高性能应用中，如机器人、电动汽车等，电机控制需要非常高的精度和响应速度。准确的电流和电压测量是实现这些高性能需求的基础。

#### 2.2.5调试步骤

在本实验中，当HaawkFAST控制器被启用并开始识别或运行时，控制器状态机执行的第一个任务是偏移量计算。在偏移计算状态期间，估计器（EST）状态保持在空闲状态（EST_State_Idle），电机处于静止状态（甚至可以不用接电机）。偏移量的计算是为了设置电流测量和电压测量的零。为了计算偏移量，在预配置的时间段内对ePWM销应用50%的占空比。用户可以更改计算这些偏移量的时间，并在“HXS320F280049C_EDC_is02_offset_gain_cal.c”源文件中进行配置，如下所示。

`uint32_t gOffsetCalcWaitTime = 50000;`

初始化的时候，完成校准后，应针对特定硬件更新电压和电流偏移值。这些初始偏移参数可以用于在未来的项目中绕过偏移校准。user.h文件中，电流和电压偏移的默认值值如下所示：

```c
//! \brief ADC current offsets for A, B, and C phases
#define   IA_OFFSET_A    (9.97279739f)           // ~=0.5*USER_ADC_FULL_SCALE_CURRENT_A
#define   IB_OFFSET_A    (9.95302963f)           // ~=0.5*USER_ADC_FULL_SCALE_CURRENT_A
#define   IC_OFFSET_A    (9.89870834f)           // ~=0.5*USER_ADC_FULL_SCALE_CURRENT_A


//! \brief ADC voltage offsets for A, B, and C phases
#define   VA_OFFSET_V    (0.495257079f)         // ~=0.5
#define   VB_OFFSET_V    (0.493127942f)         // ~=0.5
#define   VC_OFFSET_V    (0.491690784f)         // ~=0.5
```

请参考《Haawking_HaawkFOC用户指南_V1.0》中的“第5.2节：硬件必要条件”，相关部分概述了需要设置当前偏移量的正确符号，包括正或负。该符号将基于所使用的硬件板的当前反馈极性。电流反馈的正确极性是必要的，以确保微控制器有一个准确的电流测量。对于正反馈信号输入，符号是负的；相反，对于负反馈信号输入，符号是正的。一旦偏移校准完成，结果将存储在motorVars.offsets_I_A和motorVars.offsets_V_V结构体成员中，如下图所示。

![实验二-期望结果三相电流和三相电压校准值](C:\Users\Administrator\Downloads\实验二-期望结果三相电流和三相电压校准值.PNG)

![实验二-期望结果三相电流和三相电压](C:\Users\Administrator\Downloads\实验二-期望结果三相电流和三相电压.PNG)

相较于实验一，本实验需要添加两个源文件，offset.c和filter_fo.c，用于补偿电流和电压以及对信号进行滤波；同时，还需要关注更多的全局变量，如filterHandle[]和filter[]（在工程中可能会把电流和电压分开放置，变量名分别为filterHandle_I、filterHandle_V、filter_I和filter_V等）。

![实验二-校准函数和滤波函数](C:\Users\Administrator\Downloads\实验二-校准函数和滤波函数.PNG)

![实验二全局变量](C:\Users\Administrator\Downloads\实验二全局变量.png)

偏移校准功能允许在电机静止或者未连接电机时根据需要重新计算电压和电流偏移。计算偏移量的方法使用了6个一阶过滤器，它们在HXS320F280049C_EDC_is02_offset_gain_cal工程中main.c程序代码的顶部声明。

```c
//!< the handles for the current offset calculation
FILTER_FO_Handle  filterHandle_I[USER_NUM_CURRENT_SENSORS];
//!< the current offset calculation
FILTER_FO_Obj     filter_I[USER_NUM_CURRENT_SENSORS];

//!< the handles for the voltage offset calculation
FILTER_FO_Handle  filterHandle_V[USER_NUM_VOLTAGE_SENSORS];
//!< the voltage offset calculation
FILTER_FO_Obj     filter_V[USER_NUM_VOLTAGE_SENSORS];
```

接下来，通过USER_OFFSET_POLE_rps使用user.h中指定的截止频率来初始化滤波器。

```c
//! \brief Defines the pole location for the voltage and current offset estimation, rad/s
//!
#define USER_OFFSET_POLE_rps            ((float32_t)(20.0))
```

只有在设置了启用标志motorVars.flagEnableOffsetCalc时，才会计算偏移量；此逻辑在ISR中被检查，如HXS320F280049C_EDC_is02_offset_gain_cal工程中main.c程序代码中的runOffsetsCalculation()所示。当“motorVars.flagEnableOffsetCalc”等于“false”时，偏移补偿的计算代码将被绕过，初始偏移将从“user.h”中读取。

```c
if(motorVars.flagEnableOffsetCalc == true)
	{
		runOffsetsCalculation();

		//
		// Below two lines code only used in this lab for hardware verification
		// these two lines code will be removed for later lab projects
		//
		if(flagEnableOffsetCalibration == true)
		{
			motorVars.flagEnableOffsetCalc = true;
		}
	}
```

runOffsetsCalculation()函数在HXS320F280049C_EDC_is02_offset_gain_cal工程中main.c程序代码中描述。通过将周期（Tabc）值写入0，将PWM占空比设置为50%，并运行滤波器。一旦达到预设的时间点，计算出的偏移量将存储在全局变量motorVars.offsets_I_A.value和motorVars.offsets_V_V.value中。

复制并粘贴该motorVars.offsets_I_A和motorVars.offsets_V_V到相应的#define语句到user.h中，如上所述。如果在后续的运行中，将变量“motorVars.flagEnableOffsetCalc”设置为“0”，则存储在user.h中的电压和电流偏移值将作为运行所需要的数据，可以绕过偏移校准过程，减少电机启动时候的时间开销。

#### 2.2.6结论

本实验项目“HXS320F280049C_EDC_is02_offset_gain_cal”演示了如何实现电压和电流的偏移校准，并使用偏移校准过程来验证硬件板的电流和电压采样电路。此外，本实验还讨论了如何在“user.h”文件中设置逆变器的电流和电压偏移值，以绕过偏移校准，减少电机启动时候的时间开销。

### 2.3实验三：HXS320F280049C_EDC_is03_hardware_test

#### 2.3.1摘要

HaawkFAST使用的SVM能够饱和到预先规定的占空比。当使用超过100.0%的占空比时，SVM被认为处于过调制区域。当在过调制区域时，电流分流测量窗口变得很小，甚至消失。该实验室将展示在SVM过调制期间如何重构由于高占空比而无法测量的电流。

#### 2.3.2引言

实验三“HXS320F280049C_EDC_is03_hardware_test”演示了使用角度发生器模块来模拟基于电机目标频率的通量角，并利用伏特/赫兹轮廓来控制由此产生的三相电机电压。虽然这里没有使用快速估计器来生成输出角，但实验三将通过标量伏特/赫兹控制来测试几个HaawkFOC模块。

#### 2.3.3学习目标

- 如何实现标量电压/频率（VF）电机控制方案。
- 如何使用伏特/赫兹（V/F）控制技术来测试以下HaawkFOC模块
  - 脉冲宽度调制（PWM）模块
  - 模数转换器（ADC）模块
  - 克拉克变换（克拉克）模块
  - 空间矢量发生器（SVGEN）模块

#### 2.3.4背景

为了获得更好的动态性能，需要采用更复杂的控制方案来实现ACI或PM电机的控制。标量控制是指使用非矢量控制驱动方案的一种更简单的电机控制形式。交流电机可以通过电压馈电、电流控制或速度控制方案来达到稳态。在V/Hz（V/F）控制中，交流电机的速度由定子电压和频率的可调幅度来控制。

V/Hz（V/F）控制的应用方式是，在稳定状态期间，磁通量始终保持在期望的值，并且扭矩与供电频率无关。定子电压与频率的比通常是基于这些变量的额定值。典型的V/Hz（V/F）曲线如下图所示。

![实验三-VF模式下定子电压和频率的关系图](C:\Users\Administrator\Downloads\实验三-VF模式下定子电压和频率的关系图.png)

基本上，在V/Hz（V/F）外形中存在以下三速范围：

- 在0-fc Hz时，需要一个电压，因此在定子电阻上的电压降不能被忽略，必须通过增加Vs来补偿。因此，V/Hz分布不是线性的。截止频率（fc）和适当的定子电压可以从具有Rs = 0的稳态等效电路中分析计算出来。
- 在fc-frated，定子电压和频率之间遵循一个恒定的比例关系。
- 在频率大于fratedHz时，由于直流总线输入电压的限制，不能满足恒定的Vs/f比。在这个区域，由此产生的气隙通量会减少，不可避免地导致扭矩的减小。这个区域通常被称为“恒定功率区域”，将出现一个恒定的（“平坦的”）V/Hz曲线，也就是通常所说的“弱磁区间”。

在这个实验中，通过对频率施加一个下限，来修改VF曲线的轮廓，如下图所示。这种方法在一些应用场景下是可以被接受的，如风扇和鼓风机驱动器，在低频下的速度响应不是关键的因素。由于额定电压，也是最大电压，以额定频率施加于电机，因此只需要额定最小和最大频率信息来实现v/f控制曲线。

![实验三-修改的VF模式下定子电压和频率的关系图](C:\Users\Administrator\Downloads\实验三-修改的VF模式下定子电压和频率的关系图.png)

有关参数和返回值的更深入的解释，请参考《Haawking_HaawkFOC用户指南_V1.0》文档中的电机控制部分。下面的代码片段演示了角度发生器模块和电压/频率配置文件模块的设置。

```c
//!< the handles for Angle Generate for open loop control
ANGLE_GEN_Handle angleGenHandle;
//!< the Angle Generate onject for open loop control
ANGLE_GEN_Obj    angleGen;

//!< the handles for Vs per Freq for open loop control
VS_FREQ_Handle VsFreqHandle;
//!< the Vs per Freq object for open loop control
VS_FREQ_Obj    VsFreq;


//
// initialize the angle generate module
//
angleGenHandle = ANGLE_GEN_init(&angleGen, sizeof(angleGen));
ANGLE_GEN_setParams(angleGenHandle, userParams.ctrlPeriod_sec);

//
// initialize the Vs per Freq module
//
VsFreqHandle = VS_FREQ_init(&VsFreq, sizeof(VsFreq));
VS_FREQ_setVsMagPu(VsFreqHandle, userParams.maxVsMag_pu);
VS_FREQ_setMaxFreq(VsFreqHandle, USER_MOTOR_FREQ_MAX_HZ);
VS_FREQ_setProfile(VsFreqHandle,
                   USER_MOTOR_FREQ_LOW_HZ, USER_MOTOR_FREQ_HIGH_HZ,
                   USER_MOTOR_VOLT_MIN_V, USER_MOTOR_VOLT_MAX_V);
```

mainISR()函数是一个执行FOC循环的关键函数。实验室“HXS320F280049C_EDC_is03_hardware_test”的控制方框图如下图所示。mainISR()函数调用Clarke模块，读取ADC，执行ANGLE_GEN_run、VS_FREQ_run和逆Park变换，运行SVGEN，最后写入PWM以进行标量控制（开环控制）。

![实验三-开环控制架构图](C:\Users\Administrator\Downloads\实验三-开环控制架构图.png)



#### 2.3.5调试步骤

调试之前，请确保电机、电源、控制板和驱动板都连接正确，如下图所示：

![实验三-电机电源链接图](C:\Users\Administrator\Downloads\实验三-电机电源链接图.png)

在实验二中获得电流和电压的补偿系数，可以填写到user.h文件中，如下所示：

```c
//! \brief ADC current offsets for A, B, and C phases
#define   IA_OFFSET_A    (16.350033f)           // ~=0.5*USER_ADC_FULL_SCALE_CURRENT_A
#define   IB_OFFSET_A    (16.350033f)           // ~=0.5*USER_ADC_FULL_SCALE_CURRENT_A
#define   IC_OFFSET_A    (16.350033f)           // ~=0.5*USER_ADC_FULL_SCALE_CURRENT_A


//! \brief ADC voltage offsets for A, B, and C phases
#define   VA_OFFSET_V    (0.495257079f)         // ~=0.5
#define   VB_OFFSET_V    (0.493127942f)         // ~=0.5
#define   VC_OFFSET_V    (0.491690784f)         // ~=0.5
```

同样也是在user.h文件中，电机的一些参数也需要配置，包括电机的最大最小频率，电机的最大最小电压。

```c
#define USER_MOTOR_FREQ_MIN_HZ            (5.0)           // Hz
#define USER_MOTOR_FREQ_MAX_HZ            (600.0)         // Hz

#define USER_MOTOR_FREQ_LOW_HZ            (20.0)          // Hz
#define USER_MOTOR_FREQ_HIGH_HZ           (400.0)         // Hz
#define USER_MOTOR_VOLT_MIN_V             (4.0)           // Volt
#define USER_MOTOR_VOLT_MAX_V             (50.0)          // Volt
```

按照上面的连接图，连接好设备以后，就可以下载程序到F280049C上面，程序下载完成以后，会停在main()函数处，这时候用电源给功率板和电机通电，同时使能motorVars.flagEnableSys，全速运行。

此时，通过实时刷新窗口，查看三相电流和三相电压以及母线电压，应如实验二2.2.5节中所示，这里为了方面，贴在下面，如图所示：

![实验二-期望结果三相电流和三相电压](C:\Users\Administrator\Downloads\实验二-期望结果三相电流和三相电压.PNG)

此时，如果使能motorVars.flagRunIdentAndOnLine，则会发现电机已经转起来了。此时，如果连接上Freemaster，就可以观察三相电流的波形，如下图所示（5Hz转速）：

![实验三-三相电流5Hz](C:\Users\Administrator\Downloads\实验三-三相电流5Hz.png)

通过调整motorVars.speedRef_Hz的大小，可以调整电机的转速，注意此时是开环控制，电机的转动效果可能不太理想，会存在震动或者噪声。

![实验三-三相电流10Hz](C:\Users\Administrator\Downloads\实验三-三相电流10Hz.png)

通过Freemaster查看三相电流和电压，波形存在畸变，这是由于串口通信速率较低造成的，如果条件允许，可以通过示波器来观察三相电流和电压。

#### 2.3.6结论

本实验“HXS320F280049C_EDC_is03_hardware_test”演示了如何实现标量伏特/频率（V/F）控制来测试PWM和ADC硬件模块的完整性。此外，也验证了SVGEN、Park和PWM模块的正确性。



### 2.4实验四：HXS320F280049C_EDC_is04_signal_chain_test

#### 2.4.1摘要

本实验实现了一种标量电流/频率电机控制技术来测试信号链的完整性——主要是硬件电流/电压传感和控制器ADC模块。此外，实验“HXS320F280049C_EDC_is04_signal_chain_test”采用了一个电流闭环回路、速度开环回路PI的控制拓扑。

#### 2.4.2引言

本实验“HXS320F280049C_EDC_is04_signal_chain_test”显示了一个没有使用HaawkFAST估计器的例子。本实验使用一个角度发生器模块来根据电机的目标频率产生角度，并使用一个电流闭环回路来控制Id和Iq来运行电机。本实验的目的是通过没有转子位置信息的电流闭环控制来测试HaawkFOC模块。测试到的软件模块包括PI、PWM、ADC、CLARK、PARK、I-PARK和SVGEN。

#### 2.4.3学习目标

- 如何实现无估计角的电机电流闭环控制。
- 如何测试ADC采样和一些HaawkFOC模块

#### 2.4.4背景

FOC（Field-Oriented Control，磁场定向控制）是一种用于交流电机（如永磁同步电机 PMSM 和感应电机）的高级控制策略。FOC 提供了一种方法，通过控制电机的电流矢量，使其在各种运行条件下实现高效运行和精确控制。电流闭环控制是 FOC 中的关键部分。

![实验四-FOC算法电流闭环控制框图](C:\Users\Administrator\Downloads\实验四-FOC算法电流闭环控制框图.png)

FOC 电流闭环控制的基本步骤：

1. **电流测量**：
   - 通过电流传感器测量电机的定子电流。
   - 测量的电流通常是三相电流。
2. **坐标变换**：
   - 将三相电流（I_a、I_b、I_c）转换为两相静止坐标系（α-β 坐标系）的电流（I_α、I_β）。这通常使用 Clarke 变换。
   - 接着，再将 α-β 坐标系的电流转换到旋转坐标系（d-q 坐标系），这使用 Park 变换。
3. **电流调节器**：
   - 在 d-q 坐标系中，对 d 轴电流（I_d）和 q 轴电流（I_q）分别进行 PI 调节。目标是将实际电流调节到参考值。
   - PI 调节器输出电压指令（V_d 和 V_q）。
4. **逆坐标变换**：
   - 将 V_d 和 V_q 转换回 α-β 坐标系电压（V_α 和 V_β），这使用逆 Park 变换。
   - 接着，再将 α-β 坐标系电压转换回三相电压（V_a、V_b、V_c），这使用逆 Clarke 变换。
5. **PWM 调制**：
   - 通过 PWM（脉宽调制）将参考电压 V_a、V_b 和 V_c 应用到电机的三相绕组上。
6. **电机运行**：
   - 电机根据施加的三相电压运行，产生相应的磁场和转矩。

![实验四-FOC电流闭环数据流程图](C:\Users\Administrator\Downloads\实验四-FOC电流闭环数据流程图.jpg)



#### 2.4.5调试步骤

将电机、电源、控制板和驱动板，设置合适的电源限流值（如1.5A）；下载烧录代码，停留在main()函数处，给驱动板通电，设置motorVars.flagEnableSys=1，查看adcData.I_A和adcData.V_V的数值是否符合预期，确认硬件接线和ADC采样是ok的。

```
adcData.I_A ： 16.xx A
adcData.V_V ： 12.xx V
```

确认无误后，设置motorVars.flagRunIdentAndOnLine=1，电机应该可以转动，默认的转速为20Hz。

![实验四-电机转动后电流波形图](C:\Users\Administrator\Downloads\实验四-电机转动后电流波形图.jpg)

可以通过调整motorVars.speedRef_krpm、motorVars.IdSet_A和motorVars.IqSet_A的值，让电机转动的更平稳。

通过Freemaster，可以查看ADC采样得到的三相电流，如下图所示：

![实验四-电机转动后电流波形图Freemaster](C:\Users\Administrator\Downloads\实验四-电机转动后电流波形图Freemaster.jpg)

同时，也可以查看Clark变换和Park变换前后的数据，如Id和Iq等，如下图所示：

![实验四-电机转动后clark变换和IdIq-Freemaster](C:\Users\Administrator\Downloads\实验四-电机转动后clark变换和IdIq-Freemaster.jpg)

停止电机，首先需要设置motorVars.flagRunIdentAndOnLine=0，然后把电源的输出关闭，再点击Haawking IDE的停止调试按钮。

因为工程代码中，设置的默认频率是20Hz，Iq的初始值是0.05，给定使能信号以后，会发现电机没有转动；这是因为给的力小了；调试思路，可以把转速降到5Hz，同时调大Iq的给定值，如1.5。



#### 2.4.6结论

本实验“HXS320F280049C_EDC_is04_signal_chain_test”演示了如何实现当前的闭环标量控制来测试信号链硬件的完整性。预期的结果是验证了信号链硬件抽象层（HAL）的设置，特别是用于电流传感的ADC模块。此外，还验证了PI、PWM、ADC、CLARK、PARK、I-PARK和SVGEN模块。



### 2.5实验五：HXS320F280049C_EDC_is05_motor_id

#### 2.5.1摘要

电机参数识别是HaawkFOC的一项核心功能，借助于估算器，可以自动识别电机所需的参数。InstaSPIN的电机识别特性使用户能够在电机参数未知的情况下，使其电机达到最高性能。

#### 2.5.2引言

HaawkFOC中的电机参数辨识功能基于中科昊芯开发的HaawkFAST（Flux, Angle, Speed and Torque）估算器，它是一种高效的感应电机和无刷直流电机（BLDC）控制算法。

![实验五-FOC算法FAST估算器框图](C:\Users\Administrator\Downloads\实验五-FOC算法FAST估算器框图.png)

除了FAST估计器在芯片内部的ROM中之外，所有其他的FOC模块都可以从RAM/FLASH中执行，并且都是开源的。本实验“HXS320F280049C_EDC_is05_motor_id”将演示电机参数识别流程以及如何启动电机。

#### 2.5.3学习目标

- 借助FOC开放源代码，并调用API函数来设置无传感器的FOC系统。
- 为电机和逆变器设置user.h文件。
- 启动自动电机参数估计。
- 更新user.h为您的电机使用识别的参数。
- 如何初始化和设置HaawkFAST观察器。
- 如何运行HaawkFAST观察器。

#### 2.5.4背景

HaawkFOC使用的HaawkFAST估算器能够在没有物理传感器的情况下，通过电流和电压反馈来估算电机的磁链、转子角度、速度和转矩。为了使估算器准确地工作，需要了解电机的一些关键参数，如定子电阻、定子电感和反电动势常数等。电机参数辨识的原理就是通过施加特定的测试信号并分析电机的响应来计算这些参数。

**参数识别过程**：

1. **启动辨识模式**：在MCU初始化阶段，进入电机参数辨识模式。此时，控制器将停止正常的电机运行，进入专门的参数辨识过程。
2. **初始电流注入**：控制器通过PWM（脉宽调制）信号注入一个小的直流电流到电机中，并测量响应电压。这一步用于计算定子电阻（Rs）。
3. **绕组电感辨识**：接下来，通过施加不同频率的交流信号并测量电机的响应来计算定子电感（L）。这一过程利用电感在不同频率下的阻抗特性进行计算。
4. **反电动势常数辨识**：为了辨识反电动势常数（Ke），控制器会驱动电机以一个已知的速度，并测量生成的反电动势（电机在运动时产生的电压）。通过已知的速度和测量的电压，可以计算出Ke。
5. **结果存储和使用**：所有参数辨识完成后，控制器会将这些参数存储到内存或非易失性存储器中，并在之后的闭环控制中使用这些参数来优化电机的性能。

**优势**：

- **自动化**：不需要手动测量和输入电机参数，节省时间和减少错误。
- **高精度**：通过自动化的测试和计算，可以获得更精确的电机参数，提升控制精度。
- **适应性强**：适用于各种类型的电机，即使参数未知，也能快速辨识并实现高性能控制。

#### 2.5.5调试步骤

在“user.h”文件的中间，有一个部分包含了电机参数的定义，涉及到下面的一些参数：

```c
#define USER_MOTOR_TYPE                   MOTOR_TYPE_PM
#define USER_MOTOR_NUM_POLE_PAIRS         (4)
#define USER_MOTOR_Rr_Ohm                 (0)
#define USER_MOTOR_Rs_Ohm                 (0.381334811)
#define USER_MOTOR_Ls_d_H                 (0.000169791776)
#define USER_MOTOR_Ls_q_H                 (0.000169791776)
#define USER_MOTOR_RATED_FLUX_VpHz        (0.0398557819)
#define USER_MOTOR_MAGNETIZING_CURRENT_A  (0)
#define USER_MOTOR_RES_EST_CURRENT_A      (2.0)
#define USER_MOTOR_IND_EST_CURRENT_A      (-1.5)
#define USER_MOTOR_MAX_CURRENT_A          (6.0)
#define USER_MOTOR_FLUX_EXC_FREQ_Hz       (40.0)
```

有一些参数，是可以事先获得的，如极对数等。

- `USER_MOTOR_TYPE = MOTOR_TYPE_PM` 或 `MOTOR_TYPE_INDUCTION`：必须知道电机类型，并在此参数中输入。
- `USER_MOTOR_NUM_POLE_PAIRS`：电机的极对数。
- `USER_MOTOR_MAX_CURRENT`：电机铭牌上的最大电流。
- `USER_MOTOR_RES_EST_CURRENT`：在辨识过程中，电机需要在开环状态下初始启动。此值设置初始启动时使用的峰值电流。如果电机有较高的齿槽转矩或某种负载，增加此电流值直到电机开始旋转。电机辨识后，不再使用此值。
- `USER_MOTOR_IND_EST_CURRENT`：对于ACIM电机，必须为零。对于PMSM电机，此值可以设置为 `USER_MOTOR_RES_EST_CURRENT` 的负值。例如，如果 `USER_MOTOR_RES_EST_CURRENT` 是1.0，那么 `USER_MOTOR_IND_EST_CURRENT` 可以是 -1.0。
- `USER_MOTOR_NUM_POLE_PAIRS`：电机的极对数。
- `USER_MOTOR_RATED_FLUX`：对于PMSM电机，必须为零。对于ACIM电机，额定磁链应设定为根据铭牌值计算的值，计算方法如下： USER_MOTOR_RATED_FLUX = SQRT(2) / SQRT(3) * Rated_VAC / Rated_F。所以，对于额定电压为220VAC、额定频率为60Hz的电机，额定磁链应为： USER_MOTOR_RATED_FLUX = SQRT(2) / SQRT(3) * 220.0 / 60.0 = 2.9938
- `USER_MOTOR_FLUX_EST_FREQ_Hz`：对于PMSM电机，初始值可以设为20.0 Hz；对于ACIM电机，初始值可以设为5.0 Hz。

稍后在实验中，当电机参数被识别出来后，相应的NULL值将会被更新为识别出的参数值。需要注意的是，如果电机被定义为永磁电机，则不需要“Magnetizing Current磁化电流”和“Rr”这些参数，因此它们将始终保持为NULL。此外，请注意，逆变器已经定义。在“user.h”文件的上半部分，有电流和电压、时钟和定时器、以及极数的定义。这些定义用于设置库的电流、电压缩放和滤波参数。

这里有一些参数是需要计算出来的，而且在从国际原厂的F280049C工程迁移到昊芯的F280049C的时候，因为国际原厂F280049C版本的估算器的架构为原始版本，有部分函数的API接口需要做调整。

如下面的参数需要做修改，包括直流母线电压、滤波器参数以及满量程电压值等：

```
//! \brief Defines the nominal DC bus voltage, V
//!
#define USER_NOMINAL_DC_BUS_VOLTAGE_V         (24.0f)

//! \brief Defines the maximum voltage at the AD converter
#define USER_ADC_FULL_SCALE_VOLTAGE_V         (56.0f)

//! \brief Defines the analog voltage filter pole location, Hz
#define USER_VOLTAGE_FILTER_POLE_Hz           (680.4839141f)     // 47nF

//! \brief Defines the maximum current at the AD converter
#define USER_ADC_FULL_SCALE_CURRENT_A         (33.0f)     // gain=10
```

涉及到的文件包括user.h、user.c、est.h、est_Flux_states.h、est_Ls_states.h、est_Rr_states.h、est_Rs_states.h、est_states.h、est_Traj_states.h、userParams.h、motor.h，必须用昊芯所提供的文件，且在各头文件中所定义的变量及枚举不要更改，否则会导致估算器的参数在进行配置时出现差错。这里列举一些关键的文件和注意点，如下表所示：

| 文件名 | 注意事项                                                     |
| ------ | ------------------------------------------------------------ |
| main.c | 驱动板上电流采样的运放为正反馈还是负反馈<br/>adcData.I_A.value[0] = motorVars.offsets_I_A.value[0] - adcData.I_A.value[0];<br/>adcData.I_A.value[1] = motorVars.offsets_I_A.value[1] - adcData.I_A.value[1];<br/>adcData.I_A.value[2] = motorVars.offsets_I_A.value[2] - adcData.I_A.value[2]; |
| main.c | EST_initEst()需要替换成<br />estHandle = (EST_Handle)est_motor_1; |
| user.h | USER_NOMINAL_DC_BUS_VOLTAGE_V：母线电压<br/>USER_ADC_FULL_SCALE_VOLTAGE_V：相电压采样范围<br/>USER_ADC_FULL_SCALE_CURRENT_A：相电流采样范围<br/>USER_SYSTEM_FREQ_Hz：系统主频 |
| user.c | USER_setParams();函数需要与HX保持一致<br/>EST_setupTraj(); 用EST_setupTrajState();替换<br/>EST_configureCtrl(); 用 EST_configureTrajState();替换<br/>EST_configureTrajState();函数入参与EST_configureCtrl();函数不同，如下：<br/>Void EST_configureCtrl(EST_Handle handle,CTRL_Handle ctrlHandle);<br/>void EST_configureTrajState(EST_Handle handle, USER_Params *pUserParams,                                   PI_Handle piHandle_spd,<br/>                                   PI_Handle piHandle_Id, PI_Handle piHandle_Iq); |

在参数辨识阶段，需要首先在实时刷新窗口中使能motorVars.flagEnableSys，全速运行，查看ADC采样的三相电流和三相电压是否符合预期（adcData结构体，预期结果参考之前章节）。

如果三相电流和三相电压采样都符合预期，则使能motorVars.flagRunIdentAndOnLine，就开始进入参数辨识的过程了，整个参数辨识的状态转换如下图所示（这里只做简单概述，具体可参考《Haawking_HaawkFOC用户指南_V1.0》6.2.1 估算器(EST) 状态机章节）：

![实验五-参数辨识流程图](C:\Users\Administrator\Downloads\实验五-参数辨识流程图.png)

①EST_STATE_ROVERL

估算器的 R/L 状态在电机识别过程期间执行，用于测量电机的电气常量。此状态结束时，可使用产生的 R/L 比来计算 ID 和 IQ 电流控制器增益。

![实验五-EST_STATE_ROVERL](C:\Users\Administrator\Downloads\实验五-EST_STATE_ROVERL.png)

②EST_STATE_RS

首次识别电机定子电阻时或在完全识别电机后重新校准定子电阻时，估算器处于 Rs 状态。

![实验五-EST_STATE_RS](C:\Users\Administrator\Downloads\实验五-EST_STATE_RS.png)

③EST_STATE_RAMPUP

在估算器斜升状态下，电机可上升至已配置的频率以执行其它识别任务，例如磁通和电感识别。在此状态期间，不会估算任何参数，仅仅使电机上升至特定频率。

![实验五-EST_STATE_RAMPUP](C:\Users\Administrator\Downloads\实验五-EST_STATE_RAMPUP.png)

④EST_STATE_CONSTSPEED + EST_STATE_RATEDFLUX

在此状态期间，将识别电机定子到转子的磁链。

![实验五-EST_STATE_CONSTSPEED+EST_STATE_RATEDFLUX](C:\Users\Administrator\Downloads\实验五-EST_STATE_CONSTSPEED+EST_STATE_RATEDFLUX.png)

![实验五-EST_STATE_CONSTSPEED+EST_STATE_RATEDFLUX-2](C:\Users\Administrator\Downloads\实验五-EST_STATE_CONSTSPEED+EST_STATE_RATEDFLUX-2.png)

⑤EST_STATE_LS

估算器的这一状态期间将识别定子电感。

![实验五-EST_STATE_LS](C:\Users\Administrator\Downloads\实验五-EST_STATE_LS.png)

辨识完成后，会自动将motorVars.flagRunIdentAndOnLine清零，同时置位motorVars.flagMotorIdentified，辨识结果如下所示：

![实验五-辨识完成1](C:\Users\Administrator\Downloads\实验五-辨识完成1.png)

![实验五-辨识完成2](C:\Users\Administrator\Downloads\实验五-辨识完成2.png)

48V-400W的电机参数如下：

![实验五-辨识完成3](C:\Users\Administrator\Downloads\实验五-辨识完成3.png)



#### 2.5.6转M2电机

![实验五-电机2接线图](C:\Users\Administrator\Downloads\实验五-电机2接线图.png)

需要修改的地方，涉及到ADC和PWM的初始化，主要是电压和电流采样部分的代码，其他上层的代码都可以用M1电机的。

ADC部分的代码，主要是根据1.2.1.2小节，配置ADC的采样通道和触发源：

```
// configure the interrupt sources
// configure the ample window to 15 system clock cycle wide by assigning 14
// to the ACQPS of ADCSOCxCTL Register.
// RA1/A1
ADC_setInterruptSource(obj->adcHandle[0], ADC_INT_NUMBER1, ADC_SOC_NUMBER0);

// configure the SOCs for M2 on YuZhou_V1.2
// IA-FB - C5->H3.16
ADC_setupSOC(obj->adcHandle[2], ADC_SOC_NUMBER3, ADC_TRIGGER_EPWM1_SOCA,
             ADC_CH_ADCIN5, 14);

// IB-FB - C3->H3.14
ADC_setupSOC(obj->adcHandle[2], ADC_SOC_NUMBER4, ADC_TRIGGER_EPWM1_SOCA,
             ADC_CH_ADCIN3, 14);

// IC-FB - C1->H3.12
ADC_setupSOC(obj->adcHandle[2], ADC_SOC_NUMBER5, ADC_TRIGGER_EPWM1_SOCA,
             ADC_CH_ADCIN1, 14);

// ADC-Vhb1 - A6->H3.6
ADC_setupSOC(obj->adcHandle[0], ADC_SOC_NUMBER0, ADC_TRIGGER_EPWM1_SOCA,
             ADC_CH_ADCIN6, 14);

// ADC-Vhb2 - A2->H3.8
ADC_setupSOC(obj->adcHandle[0], ADC_SOC_NUMBER2, ADC_TRIGGER_EPWM1_SOCA,
             ADC_CH_ADCIN2, 14);

// ADC-Vhb3 - C14->H3.10
ADC_setupSOC(obj->adcHandle[2], ADC_SOC_NUMBER6, ADC_TRIGGER_EPWM1_SOCA,
             ADC_CH_ADCIN14, 14);

// VDCBUS - A8->H3.3
ADC_setupSOC(obj->adcHandle[0], ADC_SOC_NUMBER3, ADC_TRIGGER_EPWM1_SOCA,
                 ADC_CH_ADCIN8, 14);
```

ADC采样的代码，也需要做响应的修改，在函数HAL_readADCDataWithOffsets()中：

```
// convert phase A current        ->RC5/C3
value = (float32_t)ADC_readResult(obj->adcResult[2], ADC_SOC_NUMBER3);
pADCData->I_A.value[0] = value * current_sf;

// convert phase B current        ->RC3/C4
value = (float32_t)ADC_readResult(obj->adcResult[2], ADC_SOC_NUMBER4);
pADCData->I_A.value[1] = value * current_sf;

// convert phase C current        ->RC1/C5
value = (float32_t)ADC_readResult(obj->adcResult[2], ADC_SOC_NUMBER5);
pADCData->I_A.value[2] = value * current_sf;

// convert phase A voltage        ->RA6/A0
value = (float32_t)ADC_readResult(obj->adcResult[0], ADC_SOC_NUMBER0);
pADCData->V_V.value[0] = value * voltage_sf;

// convert phase B voltage        ->RA2/A2
value = (float32_t)ADC_readResult(obj->adcResult[0], ADC_SOC_NUMBER2);
pADCData->V_V.value[1] = value * voltage_sf;

// convert phase C voltage        ->RC14/C6
value = (float32_t)ADC_readResult(obj->adcResult[2], ADC_SOC_NUMBER6);
pADCData->V_V.value[2] = value * voltage_sf;

// convert dcBus voltage          ->RA8/A3
value = (float32_t)ADC_readResult(obj->adcResult[0], ADC_SOC_NUMBER3);
pADCData->dcBus_V = value * voltage_sf;
```

PWM部分的代码，只需要根据1.2.1.2小节中修改ePWM模块的基地址即可：

```
// initialize PWM handles for Motor 2
obj->pwmHandle[0] = EPWM1_BASE;
obj->pwmHandle[1] = EPWM4_BASE;
obj->pwmHandle[2] = EPWM2_BASE;
```

辨识后的参数如下所示，尽管是同一个电机(001#)，可以发现辨识出来的参数也是有些不一样的：

![实验五-电机2识别完成后参数列表](C:\Users\Administrator\Downloads\实验五-电机2识别完成后参数列表.png)

另外一台电机的参数（003#），如下所示：

![实验五-电机2识别完成后参数列表good](C:\Users\Administrator\Downloads\实验五-电机2识别完成后参数列表good.png)



#### 2.5.7结论

本实验“HXS320F280049C_EDC_is05_motor_id”已经演示了使用HaawkFAST估计器和HaawkFOC库的基础知识。同时演示了如何识别一个新的电机，并将值输入user.h中。获取到的电机参数将在后续的实验中使用，以减少电机的启动时间。

### 2.6实验六：HXS320F280049C_EDC_is06_torque_control

#### 2.6.1摘要

本实验探讨了一种基于HaawkSPIN的FOC控制系统，通过调节控制器的比例增益（Kp）和积分增益（Ki）来满足系统需求的方法。首先，我们计算出合适的Kp和Ki增益，然后将学习如何用这些值编写HaawkSPIN的应用程序。

#### 2.6.2引言

本实验介绍了在使用HaawkSPIN控制电机时，如何调整PI增益的数值，来进行力矩控制。

#### 2.6.3学习目标

- 如何计算当前控制器的PI增益
- HaawkFOC控制系统中配置Kp和Ki

#### 2.6.4背景

PI控制器（比例-积分控制器）是控制系统中常用的一种控制器，用于提高系统的稳态精度和动态性能。PI控制器结合了比例控制（P控制）和积分控制（I控制）的优点，能够有效消除稳态误差并改善系统的响应速度。

比例控制（P控制）：比例控制器输出与输入误差（即期望值与实际值之间的差异）成正比；优点是响应快速，缺点是存在稳态误差。

积分控制（I控制）：积分控制器输出与误差的积分成正比，旨在消除稳态误差；优点是消除稳态误差，缺点是响应较慢，可能引入超调。

PI控制器：PI控制器将比例控制和积分控制结合起来，使得系统既有快速响应能力又能消除稳态误差。

![实验六-PI控制器框图](C:\Users\Administrator\Downloads\实验六-PI控制器框图.png)

调节PI控制器的参数主要涉及两个方面：

- **比例增益 Kp**：调节系统的响应速度。增大Kp 会加快系统响应，但过大可能引起振荡。
- **积分增益 Ki**：消除稳态误差。增大Ki 会加快误差消除，但过大可能引起超调和振荡。



#### 2.6.5调试步骤

首先需要在user.h中，配置合适的电机参数，参数可以通过实验五的参数辨识获得，如下所示：

```
//36V 200W

#define USER_MOTOR_TYPE                   MOTOR_TYPE_PM
#define USER_MOTOR_NUM_POLE_PAIRS         (5)
#define USER_MOTOR_Rr_Ohm                 (0)
#define USER_MOTOR_Rs_Ohm                 (0.244506612)
#define USER_MOTOR_Ls_d_H                 (0.000343821011)
#define USER_MOTOR_Ls_q_H                 (0.000343821011)
#define USER_MOTOR_RATED_FLUX_VpHz        (0.05490241434)
#define USER_MOTOR_MAGNETIZING_CURRENT_A  (0)
#define USER_MOTOR_RES_EST_CURRENT_A      (1.5f)
#define USER_MOTOR_IND_EST_CURRENT_A      (-1.0f)
#define USER_MOTOR_MAX_CURRENT_A          (6.5f)
#define USER_MOTOR_FLUX_EXC_FREQ_Hz       (20.0f)
```

Rs和Ls用来计算KP和KI参数，截取部分setupControllers()函数的代码如下：

```
//
//! \brief  Sets up the controllers
//
static inline void setupControllers(void)
{
    float32_t Ls_d_H = userParams.motor_Ls_d_H;
    float32_t Ls_q_H = userParams.motor_Ls_q_H;
    float32_t Rs_d_Ohm = userParams.motor_Rs_Ohm;
    float32_t Rs_q_Ohm = userParams.motor_Rs_Ohm;
    float32_t RdoverLd_rps = Rs_d_Ohm / Ls_d_H;
    float32_t RqoverLq_rps = Rs_q_Ohm / Ls_q_H;
    float32_t BWc_rps = userParams.BWc_rps;
    float32_t currentCtrlPeriod_sec =
                (float32_t)userParams.numCtrlTicksPerCurrentTick /
                userParams.ctrlFreq_Hz;
    float32_t outMax_V = userParams.Vd_sf * userParams.maxVsMag_V;

    float32_t Kp_Id = Ls_d_H * BWc_rps;
    float32_t Ki_Id = RdoverLd_rps * currentCtrlPeriod_sec;

    float32_t Kp_Iq = Ls_q_H * BWc_rps;
    float32_t Ki_Iq = RqoverLq_rps * currentCtrlPeriod_sec;
```

如下面的FOC控制框图所示，设置Id的参考值，通过HaawkFAST估算器获得反馈的Id，送入PI控制器中，经过iPark变换，驱动电机运行。

![实验六-FOC控制框图](C:\Users\Administrator\Downloads\实验六-FOC控制框图.png)

此时，通过设置motorVars.speedRef_Hz已经不起作用，只能通过IdqSet_A.value[1]来修改Id的参考值，来调整输出的力矩和电机的转速。

如果Id的参考值，小于某一个值，电机是无法运行的，例如本实验中，只有当Id参考值大于0.27，电机才可以勉强转起来，此时的电机转速为11Hz左右。

![实验六-修改配置转速无法启动](C:\Users\Administrator\Downloads\实验六-修改配置转速无法启动.png)

![实验六-修改配置转速勉强启动](C:\Users\Administrator\Downloads\实验六-修改配置转速勉强启动.png)

当Id的参考值超过某一个数值的时候，电机的转速也不会上去了，这是因为程序中设置了输出上限，在本实验中，Id的参考值超过0.6以后，电机转速就达到了最高，203Hz左右。

![实验六-修改配置转速203Hz-之二](C:\Users\Administrator\Downloads\实验六-修改配置转速203Hz-之二.png)

![实验六-修改配置转速203Hz](C:\Users\Administrator\Downloads\实验六-修改配置转速203Hz.png)

![实验六-默认的配置转速203Hz](C:\Users\Administrator\Downloads\实验六-默认的配置转速203Hz.png)

当Id参考值在0.27和0.6之间，可以通过调整Id的参考值，调整电机的转速，如下所示：

![实验六-修改配置转速23Hz](C:\Users\Administrator\Downloads\实验六-修改配置转速23Hz.png)

![实验六-修改配置转速58Hz](C:\Users\Administrator\Downloads\实验六-修改配置转速58Hz.png)

![实验六-修改配置转速105Hz](C:\Users\Administrator\Downloads\实验六-修改配置转速105Hz.png)

也可以通过Freemaster查看力矩和转速，如下图所示：

![实验六-Freemaster查看Nm和Speed](C:\Users\Administrator\Downloads\实验六-Freemaster查看Nm和Speed.png)

![实验六-Freemaster查看Nm和Speed-之二](C:\Users\Administrator\Downloads\实验六-Freemaster查看Nm和Speed-之二.png)

#### 2.6.6结论

在本实验项目“HXS320F280049C_EDC_is06_torque_control”中，探讨了一种基于HaawkSPIN的FOC控制系统，通过调节控制器的比例增益（Kp）和积分增益（Ki）来满足系统需求的方法。首先，我们计算出合适的Kp和Ki增益，然后将学习如何用这些值编写HaawkSPIN的应用程序；同时，通过调整Id的参考值，动态调整电机的转速，实现力矩控制的效果。

### 2.7实验七：HXS320F280049C_EDC_is07_speed_control

#### 2.7.1摘要

HaawkSPIN的FOC方案提供了一个标准的PI速度控制器。HaawkSPIN库将根据“user.h”中的最大电流和电机惯性设置，给出速度控制器的Kp和Ki的“经验法则”下的理论值。理论上的PI控制器增益是一个很好的起点，但为了获得更好的动态性能，Kp和Ki项需要基于电机运行的整个机械系统进行调整。本实验将展示如何调整PI速度控制器中的Kp和Ki项，来达到更好的电机运行效果。

#### 2.7.2引言

调整速度控制器比调整电流控制器要困难得多。速度控制器处于机械领域的范畴，其时间常数要慢得多，相位延迟可以更紧，对系统的稳定性有更大的影响。精确调整速度控制系统所需的最重要的参数是惯量。本实验介绍了两种不同的调整速度环的方法。第一种技术就是根据经验和误差来动态调整，如果机械系统的参数未知，就可以使用本方法。第二种技术假设惯量和机械参数已知，然后可以直接设计当前的控制和速度控制增益。

#### 2.7.3学习目标

- 使用试错技术快速调整速度控制器
- 根据惯性和机械参数的先验知识来调整速度控制器
- 将获得的Kp和Ki输入到HaawkSPIN中

#### 2.7.4背景

##### 2.7.4.1基于经验和误差的调整方法

很多时候，当你试图调整一个电机的参数时，惯量是不能立刻获得的。HaawkSPIN提供了使用一种非常简单但有效的技术，在不知道任何机械参数的情况下快速调整PI参数来让速度控制回路达到预期目标。在接下来的讨论中，HaawkSPIN使用“并行”PI控制器来进行速度控制回路，如下图所示。

![实验七-并行PI控制器](C:\Users\Administrator\Downloads\实验七-并行PI控制器.png)

一般来说，增加Ki增益会加剧系统震荡。系统的阻尼则由Kp增益控制。例如，如果Kp增益设置得很低，Ki增益将起主要作用，电机控制系统将像弹簧一样工作，震动剧烈。当对系统施加阶跃负载时，它会振荡。增加阻尼（也就是Kp增益）则将减少振荡。

##### 2.7.4.2基于参数的调整方法

速度信号通常需要经过过滤后才能被用来控制系统。在本实验中，假设我们使用的是一种单极低通滤波器，`Vel_filter(s)=1/(τs+1)`，其中，`τs`为速度低通滤波器的时间常数（下图中的绿色块）。

![实验七-速度环叠加电流环和速率滤波器](C:\Users\Administrator\Downloads\实验七-速度环叠加电流环和速率滤波器.png)

然后，电流闭环控制的传递函数为：

`Gcurrent(s)=1/((L/Kp)*s+1)≈1`

我们可以根据所使用的电机参数，来计算出电机系统稳定运行的Kp和Ki参数值，然后用其来控制电机运行系统。

比如，针对本实验用到的电机，可以获得如下的参数：

```
定子电阻Rs = 0.16110213

定子电感Ls = 0.0002862567

反电动势Back-EMF = （Line，7±10%V/krpm）

转动惯量Inertia = 0.58±10%kg.m³*10-4

转子极数 Poles = 10
```

这样就可以计算出所需要的Kp和Ki，具体的计算函数为setupControllers()，代码如下所示：

```
//
//! \brief  Sets up the controllers
//
static inline void setupControllers(void)
{
    float32_t Ls_d_H = userParams.motor_Ls_d_H;
    float32_t Ls_q_H = userParams.motor_Ls_q_H;
    float32_t Rs_d_Ohm = userParams.motor_Rs_Ohm;
    float32_t Rs_q_Ohm = userParams.motor_Rs_Ohm;
    float32_t RdoverLd_rps = Rs_d_Ohm / Ls_d_H;
    float32_t RqoverLq_rps = Rs_q_Ohm / Ls_q_H;
    float32_t BWc_rps = userParams.BWc_rps;
    float32_t currentCtrlPeriod_sec =
                (float32_t)userParams.numCtrlTicksPerCurrentTick /
                userParams.ctrlFreq_Hz;
    float32_t outMax_V = userParams.Vd_sf * userParams.maxVsMag_V;

    float32_t Kp_Id = Ls_d_H * BWc_rps;
    float32_t Ki_Id = RdoverLd_rps * currentCtrlPeriod_sec;

    float32_t Kp_Iq = Ls_q_H * BWc_rps;
    float32_t Ki_Iq = RqoverLq_rps * currentCtrlPeriod_sec;

    //
    // set the Id controller
    //
    PI_setGains(piHandle_Id, Kp_Id, Ki_Id);
    PI_setUi(piHandle_Id, 0.0);
    PI_setRefValue(piHandle_Id, 0.0);
    PI_setFbackValue(piHandle_Id, 0.0);
    PI_setFfwdValue(piHandle_Id, 0.0);
    PI_setMinMax(piHandle_Id, -outMax_V, outMax_V);

    //
    // set the Iq controller
    //
    PI_setGains(piHandle_Iq, Kp_Iq, Ki_Iq);
    PI_setUi(piHandle_Iq, 0.0);
    PI_setRefValue(piHandle_Iq, 0.0);
    PI_setFbackValue(piHandle_Iq, 0.0);
    PI_setFfwdValue(piHandle_Iq, 0.0);
    PI_setMinMax(piHandle_Iq, 0.0, 0.0);

#if(!defined(USER_MOTOR1_INERTIA_Kgm2))
    //
    // set the speed controller
    //
    PI_setGains(piHandle_spd, motorVars.Kp_spd, motorVars.Ki_spd);
#else
    if(userParams.Kctrl_Wb_p_kgm2 <= 1.0e-4f)
    {
        float32_t Kp_spd1 = 10.0f *
                userParams.maxCurrent_A / userParams.maxFrequency_Hz;
        float32_t Ki_spd1 = 5000.0f *
                userParams.maxCurrent_A * userParams.ctrlPeriod_sec / userParams.maxFrequency_Hz;

        PI_setGains(piHandle_spd, Kp_spd1, Ki_spd1);
    }
    else
    {
        float32_t speedCtrlPeriod_sec =
            (float32_t)userParams.numCtrlTicksPerSpeedTick /
            userParams.ctrlFreq_Hz;

        float32_t BWdelta = userParams.BWdelta;
        float32_t Kctrl_Wb_p_kgm2 = (float32_t)3.0 *
                                  userParams.motor_numPolePairs *
                                  userParams.motor_ratedFlux_Wb /
                                  (float32_t) (2.0 * USER_MOTOR1_INERTIA_Kgm2);

        float32_t Kp_spd =
                MATH_TWO_PI * BWc_rps / (BWdelta * Kctrl_Wb_p_kgm2);

        float32_t Ki_spd =
                BWc_rps * speedCtrlPeriod_sec / (BWdelta * BWdelta);

        //
        // set the speed controller
        //
        PI_setGains(piHandle_spd, Kp_spd, Ki_spd);
    }
#endif

    //
    // set the speed controller
    //
    PI_setUi(piHandle_spd, 0.0);
    PI_setRefValue(piHandle_spd, 0.0);
    PI_setFbackValue(piHandle_spd, 0.0);
    PI_setFfwdValue(piHandle_spd, 0.0);
    PI_setMinMax(piHandle_spd,
                 (-userParams.maxCurrent_A),
                 userParams.maxCurrent_A);

    //
    // set the Id, Iq and speed controller parameters to motorVars
    //
    getControllers();

    return;
} // end of setupControllers() function
```



#### 2.7.5调试步骤

跟2.6.5小节中一样，首先需要在user.h中，配置合适的电机参数，setupControllers()函数会初始化速度控制器的Kp和Ki值。

与2.6.5小节不同的是，设置速度Spd_ref的参考值，通过HaawkFAST估算器获得反馈的速度w，送入速度环的PI控制器中，经过电流环的PI控制器，驱动电机运行。

![实验七-速度环FOC控制框图](C:\Users\Administrator\Downloads\实验七-速度环FOC控制框图.png)

调试的步骤跟前几个实验一样的，首先在实时刷新窗口中使能motorVars.flagEnableSys，全速运行；然后，查看ADC采样的三相电流和三相电压是否符合预期（adcData结构体，预期结果参考之前章节）。如果三相电流和三相电压采样都符合预期，则使能motorVars.flagRunIdentAndOnLine，电机以默认的速度运行。

如下图所示，采用的默认的Kp和Ki值，电机在20Hz的时候运行效果图，反馈的电机转速，波动较大。

![实验七-速度环FOC控制默认KpKi值](C:\Users\Administrator\Downloads\实验七-速度环FOC控制默认KpKi值.png)

如果将电机的速度提升到100Hz，则可以通过Freemaster查看反馈的电机转速如下变化：

![实验七-速度环FOC控制默认KpKi值加速之一](C:\Users\Administrator\Downloads\实验七-速度环FOC控制默认KpKi值加速之一.png)

可以再将速度提升到150Hz和200Hz，观察到电机转速的误差随着速度的提升在变小。

![实验七-速度环FOC控制150Hz](C:\Users\Administrator\Downloads\实验七-速度环FOC控制150Hz.png)

![实验七-速度环FOC控制200Hz](C:\Users\Administrator\Downloads\实验七-速度环FOC控制200Hz.png)

但是，在200Hz的时候，可以看到转速误差的曲线，呈现出正弦波的形状。

#### 2.7.6结论

调优速度控制器比调优电流控制器有更多的未知数。因此，在本实验中，调整速度控制器的第一种方法是采用经验和试错的方法。结果表明，并行速度PI闭环控制与质量、弹簧、阻尼器系统有关。如果对电机控制系统的机械系统参数了解较多，则可以采用最优计算方法。计算出的方法将根据用户所选择的带宽和阻尼来识别速度和当前控制器的增益。



### 2.8实验八：HXS320F280049C_EDC_is08_overmodulation

#### 2.8.1摘要

HaawkSPIN使用的SVM能够饱和到预先规定的占空比。当使用超过100.0%的占空比时，SVM被认为处于过调制区域。当在过调制区域时，电流分流测量窗口变得很小，甚至消失。该实验将展示如何重新创建在SVM过调制期间由于高占空比而无法测量的电流，通过电流重构的方式，达到更高的转速。

#### 2.8.2引言

在一个典型的三相逆变器中，测量电机电流的首选方法之一是使用低侧分流电阻，如下图所示。这提供了一个经济的解决方案，因为电流测量的参考与微控制器的GND相同。然而，它引入了一个限制，因为低侧分流电阻器只在低侧PWM接通时携带电流。

![实验八-三相电机采样电阻示意图](C:\Users\Administrator\Downloads\实验八-三相电机采样电阻示意图.png)

此外，当用三相逆变器驱动电机时，希望施加到电机绕组的电压是全量程的，而不仅仅是正弦调制波形。这一要求将空间向量调制的性能推到了极限，并导致长时间的低侧PWM开启时间基本消失。下图显示了一个场景，PWM1L中的脉冲太窄，无法在A相上进行有效电流转换。

![实验八-过调制场景下PWM波形示意图](C:\Users\Administrator\Downloads\实验八-过调制场景下PWM波形示意图.png)

本实验中使用的方法利用了电流重建技术和设置触发功能，即使逆变器产生这样的窄脉冲，也可以测量电流。如果我们至少可以测量两个相电流，就可以用公式`ia+ib+ic=0`来重构未知相的电流。因此，如果保证可以采样到两相的电流，我们就可以通过电流重构的方法，获得所有三相的电流。

本实验采用的电流重构方法是一种相位电压重构的方法，同时设置了一个触发条件。这样，即使在过调制过程中相位电压发生了变化，但由于相位补偿方法，这些相位之间的线对线电压仍保持不变。能够在执行过调制时重建电流，允许场定向控制系统甚至在重过调制或梯形控制期间依然稳定工作。

#### 2.8.3学习目标

本实验室的目的是向用户展示在电流采样窗口不够宽时，通过重构电流的方法让电机继续工作的方法。

#### 2.8.4背景

FOC（磁场定向控制）中的过调制（Overmodulation）是指在PWM（脉宽调制）中，通过扩大调制指数来增加输出电压幅值的过程。过调制的目的是在电机运行的某些情况下提供更高的电压，从而提高电机的转矩输出和速度性能。然而，过调制也会带来一些谐波失真和其他不利影响，因此需要谨慎使用。

在标准的SVPWM（空间矢量脉宽调制）中，调制指数 mmm 的范围是0到1，这对应于最大电压矢量（即直流母线电压的1/√3倍）。当需要更高的输出电压时，可以通过提高调制指数使其超过1，进入过调制区域。

过调制的优点：

- 提高输出电压：通过过调制，可以在某些工作情况下提供更高的输出电压，从而提高电机的转矩和速度性能。
- 增强动态性能：在需要快速响应和高动态性能的应用中，过调制可以提供更强的驱动能力。

过调制的缺点：

- 谐波失真：过调制会引入更多的谐波失真，增加电机的损耗和发热。
- 控制复杂性：过调制需要更复杂的控制算法，以确保在高电压输出时仍能保持系统的稳定性。
- 电机绝缘和可靠性问题：提高输出电压会增加对电机绝缘和系统可靠性的要求，可能导致绝缘老化和其他可靠性问题。

#### 2.8.5调试步骤

在实验“HXS320F280049C_EDC_is08_overmodulation”中，探索了一种实现过调制的新方法。该算法有四个方面：

- **输出电压生成**。这是空间矢量调制（SVM）生成输出波形的能力，从零开始，通过仅增加在 α/β 坐标中的输入幅值，生成正弦波形，然后生成梯形波形。
- 电流重构。由于这是基于诸如FOC（磁场定向控制）之类的电流控制算法，Id 和 Iq 电流控制器的工作需要始终有电流反馈。根据可用的电流测量值，当低侧PWM占空比低于最小宽度时，该算法会重构三相电流。
- **输出电压补偿**。输出相位被重新定位，以保证至少在两个相位上保持最小占空比。为了实现这个最小占空比，该算法分析了与用户定义的最大输出电压限制相比，能够被测量的电流相位的数量。当两个相位的电压超过限制电压，意味着它们不能被准确采样时，将基于具有第二小电流采样窗口的电压相位找到一个偏移量。偏移量定义为“中间”电压（采样窗口第二小的相位）的幅值与用户定义的限制电压之间的差值。一旦确定了偏移电压，所有相位电压都会减少这个偏移电压，同时保持线电压。基于当前和下一个PWM周期的占空比，该算法还可以定义哪些电流将在下一个PWM周期被忽略。
- **设置转换开始（SOC）触发器**。在生成PWM输出时，为了获得干净的电流测量结果，需要避免一些开关事件。该算法分析了PWM占空比和先前计算的忽略分流值，以正确设置下一次ADC转换开始信号的触发器。

##### 2.8.5.1输出电压生成

空间矢量调制（SVM）的实现允许在Alpha-Beta坐标系中输入幅度高达 (2/3) 标幺值（pu）。为了确保SVM能够生成高达 (2/3) 标幺值的输出，调用 `USER_setParams()` 函数设置最大调制指数：

注意：为了实现纯正弦电流波形，建议将最大调制指数限制为 (1.0/√3)。

在 "user.h" 文件中定义了最大 Vs 幅值限制。

`#define USER_MAX_VS_MAG_PU            (0.576) //// Set to 0.5774 for a pure sinewave with a peak at 100% duty cycle which need a current reconstruction`

要将最大 Vs 幅值设置为直流母线电压按标幺值（per unit limit）进行缩放后的值，并根据这个值设置 Iq 和 Id 的限制

```
//
// Maximum voltage output
//
userParams.maxVsMag_V = userParams.maxVsMag_pu * adcData.dcBus_V;
PI_setMinMax(piHandle_Id,
             (-userParams.maxVsMag_V), userParams.maxVsMag_V);
```

##### 2.8.5.2电流重构

过调制的第二个方面是允许在需要时重构电流。在ISR中采样电流时，通过以下函数调用读取和缩放电流：

```
    //
    // Over Modulation Supporting
    // run the current reconstruction algorithm
    //
    SVGENCURRENT_RunRegenCurrent(svgencurrentHandle,
                                 &adcData.I_A, &adcDataPrev);

    if(motorVars.flagEnableOffsetCalc == false)
    {
		//
		// remove offsets
		// 电流反馈
		//
		adcData.I_A.value[0] = motorVars.offsets_I_A.value[0] - adcData.I_A.value[0];
		adcData.I_A.value[1] = motorVars.offsets_I_A.value[1] - adcData.I_A.value[1];
		adcData.I_A.value[2] = motorVars.offsets_I_A.value[2] - adcData.I_A.value[2];
		adcData.V_V.value[0] -= motorVars.offsets_V_V.value[0] * adcData.dcBus_V;
		adcData.V_V.value[1] -= motorVars.offsets_V_V.value[1] * adcData.dcBus_V;
		adcData.V_V.value[2] -= motorVars.offsets_V_V.value[2] * adcData.dcBus_V;

        //
        // Verify close speed loop sensorless by FAST Estimator
        // Dual current close loop
        //
        float32_t outMax_V;
        MATH_Vec2 phasor;

		//
    	// with controller object
        // run Clarke transform on current
        //
        CLARKE_run(clarkeHandle_I, &(adcData.I_A), &(estInputData.Iab_A));
```

根据上述代码，所有电流数值都存储在 adcData.I_A 结构体中。根据相应电流测量时低侧PWM脉冲的宽度，某些数值可能无效。由于我们使用了过调制，我们利用了一个名为 SVGENCURRENT 的SVM扩展模块。该模块根据名为 "SVGENCURRENT_IgnoreShunt_e" 的枚举状态，以简单的方式重构相位电流。以下逻辑作为 SVGENCURRENT 模块的一部分实现在 "svgen_current.h" 中，用于重构电流。

添加两个变量来保存过调制时的前一次电流采样和PWM输出占空比。

```
// the previous data of ADC result and PWM output
MATH_Vec3 adcDataPrev_A = {0.0, 0.0, 0.0};
MATH_Vec3 pwmDataPrev = {0.0, 0.0, 0.0};
```

在这个实验中，增加了电流重构的第二阶段，以处理当三个电流读数中有两个无效时的边界条件情况。这种方法利用了一个滑动平均值，其原理很简单：如果某个电流无效，使用软件逼近法结合滤波器和其过去的值。在 "svgen_current.h" 文件中的代码展示了如何实现这一点。

```
//! \brief     Reconstructs the missed measured currents due to a small sampling window
//! \param[in] handle         The svgen current handle
//! \param[in] pADCData                   Pointer to the shunt currents
static inline void
SVGENCURRENT_RunRegenCurrent(SVGENCURRENT_Handle handle,
                             MATH_Vec3 *pADCData, MATH_Vec3 *pADCDataPrev)
{
  SVGENCURRENT_Obj *obj = (SVGENCURRENT_Obj *)handle;

  float32_t Ia = pADCData->value[0];
  float32_t Ib = pADCData->value[1];
  float32_t Ic = pADCData->value[2];

  // select valid shunts and ignore one when needed
  if(obj->ignoreShunt == SVGENCURRENT_IGNORE_A)
  {
      // repair a based on b and c
      Ia = -Ib - Ic;       //Ia = -Ib - Ic;
  }
  else if(obj->ignoreShunt == SVGENCURRENT_IGNORE_B)
  {
      // repair b based on a and c
      Ib = -Ia - Ic;       //Ib = -Ia - Ic;
  }
  else if(obj->ignoreShunt == SVGENCURRENT_IGNORE_C)
  {
      // repair c based on a and b
      Ic = -Ia - Ib;       //Ic = -Ia - Ib;
  }
  else if(obj->ignoreShunt == SVGENCURRENT_IGNORE_AB)
  {
      Ia = -Ic * 0.5f;
      Ib = Ia;
  }
  else if(obj->ignoreShunt == SVGENCURRENT_IGNORE_AC)
  {
      Ia = -Ib * 0.5f;
      Ic = Ia;
  }
  else if(obj->ignoreShunt == SVGENCURRENT_IGNORE_BC)
  {
      Ib = -Ia * 0.5f;
      Ic = Ib;
  }

  pADCData->value[0] = Ia;
  pADCData->value[1] = Ib;
  pADCData->value[2] = Ic;

  pADCDataPrev->value[0] += (pADCData->value[0] - pADCDataPrev->value[0]) * 0.5f;
  pADCDataPrev->value[1] += (pADCData->value[1] - pADCDataPrev->value[1]) * 0.5f;
  pADCDataPrev->value[2] += (pADCData->value[2] - pADCDataPrev->value[2]) * 0.5f;

  if(obj->compMode > SVGENCURRENT_TWO_PHASE_MEASURABLE)
  {
      pADCData->value[0] = pADCDataPrev->value[0];
      pADCData->value[1] = pADCDataPrev->value[1];
      pADCData->value[2] = pADCDataPrev->value[2];
  }

  return;
} // end of SVGENCURRENT_RunRegenCurrent() function
```

在电流重构的这个阶段之后，测量和估计的电流尽可能接近，以便在极端过调制条件下操作无传感器的FOC系统。

##### 2.8.5.3输出电压补偿

第三个方面涉及补偿输出相位电压，以确保至少两个相位的最小占空比。这是通过运行 SVGENCURRENT 函数来实现的，该函数更新PWM输出值：SVGENCURRENT_compPWMData()。在这个函数中，有三个主要的输出PWM补偿函数。

**定义补偿模式**
所有相位电压都与VLIM进行比较，以检查相位电流是否可测。限制电压VLIM被定义为保证分流电流测量的最小占空比所需的最大相位输出电压。如果所有相位电压都小于VLIM，补偿模式被定义为“三相可测”（ALL_PHASE_MEASURABLE）；如果两相电压小于VLIM，补偿模式被定义为“二相可测”（TWO_PHASE_MEASURABLE）；同样，如果只有一相电压小于VLIM，补偿模式被定义为“一相可测”（ONE_PHASE_MEASURABLE）。在“一相可测”模式下，通过找到一个中间电压VMIDDLE来进行电压补偿。

**相位电压补偿**
在“一相可测”模式下，所有电压重构应考虑偏移电压，以保证两相可测。偏移电压的计算和减法在 "svgen_current.h" 文件中展示了如何实现。

**忽略分流**
第三个模块涉及到知道在下一个中断中哪些电流将被忽略。这个功能通过比较平均输出电压和限制电压VLIMIT来实现。IgnoreShunt值被设置为两类主要值。"svgen_current.h" 文件中第501行到第517行的代码展示了如何实现这一点。

- USE_ALL：如果所有相位电压都小于限制电压，则采样所有电流，因为所有脉冲的宽度都大于最小可接受宽度。

- IGNORE_A、IGNORE_B 或 IGNORE_C：在相应相位的测量窗口小于可接受的测量窗口时使用。这也假设被忽略的相位与其他两个相位之间的差异大于可接受的时间。

![实验八-过调制场景下补偿模式示意图](C:\Users\Administrator\Downloads\实验八-过调制场景下补偿模式示意图.png)

##### 2.8.5.4设置转换开始（SOC）触发器

过调制的最后一个方面是将转换开始触发器设置在正确的位置，以确保在下一个PWM周期内进行最佳电流测量。这是通过HAL层实现的，调用函数 HAL_setTrigger()。该函数根据以下情况设置下一次转换的触发器：

- **下一个采样脉冲值**：当使用所有分流时，setTrigger函数需要知道哪个脉冲是最窄的，以便将触发器放置在脉冲的中心。
- **忽略分流**：根据忽略的分流，触发器会变化以适应最佳分流。
- **中间电压分流**：当忽略1个或2个分流时，setTrigger函数需要知道三个脉冲中哪个脉冲的采样窗口是第二小的，因为这个“中等长度”脉冲是最小的占空比。PWM触发器被放置在这个脉冲的中心。

当所有的分流都有效时，触发器被设置在三个脉冲中最窄的那个脉冲的正中间，如下图所示：

![实验八-过调制场景下触发源调整](C:\Users\Administrator\Downloads\实验八-过调制场景下触发源调整.png)

当输出电压补偿后有两个分流有效时，触发器被设置在三个脉冲中间长度的那个脉冲的正中间。

首先，将“user.h”中的最大相位电压幅值设置为高于 0.5 且低于 0.667 的 Vbus。默认情况下，该值设置为 (1.0/√3)，即0.576，如下所示。

```
//#define USER_MAX_VS_MAG_PU            (0.66)
//#define USER_MAX_VS_MAG_PU              (0.65)
#define USER_MAX_VS_MAG_PU            (0.576)
//#define USER_MAX_VS_MAG_PU            (0.565)
//#define USER_MAX_VS_MAG_PU            (0.5)
```

接着，通过将这两个标志设置为true来运行电机：`motorVars.flagEnableSys = 1` 和 `motorVars.flagRunIdentAndOnLine = 1`。

跟上一个实验一样，增加速度参考 `motorVars.speedRef_Hz`，直到忽略分流值显示电机在旋转时分流被忽略。

![实验八-过调制场景下速度控制](C:\Users\Administrator\Downloads\实验八-过调制场景下速度控制.png)

如上图所示，默认的参考速度是20Hz，当将参考速度设置到200Hz的时候，可以发现速度只能上升到190Hz，并且稳定下来；通过设置userParams.maxVsMag_pu的值为0.66，则进入过调制区间，电机转速经过PI控制器以后，可以稳定在200HZ。

在进行速度控制的过程中，可以观察到不同速度下，电机转速的误差，

![实验八-20Hz转速误差](C:\Users\Administrator\Downloads\实验八-20Hz转速误差.png)

![实验八-150Hz转速误差](C:\Users\Administrator\Downloads\实验八-150Hz转速误差.png)

![实验八-过调制场景下200Hz转速误差](C:\Users\Administrator\Downloads\实验八-过调制场景下200Hz转速误差.png)

同时，过调制，也只能把电机的转速提高一定的速度范围，而不是无限制的增加。

![实验八-过调制场景下220Hz上不去](C:\Users\Administrator\Downloads\实验八-过调制场景下220Hz上不去.png)

#### 2.8.6结论

在这个实验中，讨论了过调制的几个方面，允许利用整个输入电压范围。基于分流电阻的电流采样问题也通过软件技术解决，包括重构电流和在正确位置设置触发点。



### 2.9实验九：HXS320F280049C_EDC_is09_flying_start

#### 2.9.1摘要

飞行起动功能用于控制已经旋转的电机，并在对负载或速度影响最小的情况下恢复正常运行。本实验“HXS320F280049C_EDC_is09_flying_start”展示了如何在HaawkSPIN FOC中使用飞行起动功能。

#### 2.9.2引言

本实验“HXS320F280049C_EDC_is09_flying_start”提供了在HaawkSPIN FOC中应用飞行起动功能的指南。飞行起动是一种功能，允许驱动器确定旋转电机的速度和方向，并以该速度和方向开始输出电压和频率。如果没有飞行起动，驱动器将从零电压和零速度开始其输出，并尝试将速度逐渐加速到命令的速度。如果负载的惯性或旋转方向要求电机产生大量扭矩，可能会导致过流并触发驱动器的过流保护。这些问题可以通过飞行起动功能来消除。

#### 2.9.3学习目标

本实验的目标是学习如何使用HaawkSPIN FOC的飞行起动功能来控制已经旋转的电机。

#### 2.9.4背景

飞行起动是在非零速度下启动控制的能力，在某些应用中非常重要，如牵引、洗衣机、风扇、电动自行车和电动滑板车。

当电机在正常模式下启动时，控制器最初将频率设置为0 Hz，并逐渐增加到期望的频率。如果在电机已经以非零频率旋转的情况下以此模式启动驱动器，则会产生大电流。如果电流限制器反应不够快，可能会导致过流保护。即使电流限制器足够快以防止过流保护，也可能需要不可接受的时间来进行同步并使电机达到期望的频率。此外，应用中会增加更大的机械应力。

在飞行起动模式下，驱动器对启动命令的响应是与电机的速度（频率和相位）及电压同步。然后电机加速到指定的频率。这个过程可以防止过流保护，并显著缩短电机达到指定频率的时间。由于驱动器与电机在其旋转速度上同步并逐渐加速到适当的速度，因此几乎没有或没有机械应力存在。

飞行起动功能实现了一个算法，用于搜索转子速度。该算法通过搜索与施加到电机的励磁电流相对应的电机电压来实现。

当电机旋转时，可以通过反电动势（BEMF）电压估计速度和位置信息。由于HaawkSPIN驱动器中测量了定子电压，因此可以通过切换逆变器轻松获取速度和位置。对电机施加零扭矩电流，并测量生成的电流和定子电压，然后HaawkSPIN FOC模块利用这些信号来估算转子位置和速度。

下面的代码在“HXS320F280049C_EDC_is09_flying_start.c”文件中展示了飞行起动模块如何初始化和配置默认值。

```
//
// Set up some global variables for flying start
//
motorVars.flagEnableRsRecalc = false;
motorVars.flagEnableRsOnLine = false;

motorVars.flagStateMotorRunning = false;
motorVars.flagEnableFlyingStart = true;
motorVars.flagStateFlyingStart = false;
motorVars.flyingStartTimeCnt = 0;
motorVars.flyingStartTimeDelay = FLYINGSTART_DELAY_TIME;
motorVars.flyingStartMode = FLYINGSTART_MODE_STANDBY;
```

飞行起动控制程序的流程图如下图所示，飞行起动模块输出一个标志来启用或禁用速度闭环控制。在飞行起动运行时，设置零参考扭矩电流，并禁用速度PI控制器输出。

![实验九-飞行启动控制流程图](C:\Users\Administrator\Downloads\实验九-飞行启动控制流程图.png)

飞行起动频率和角度搜索算法函数是这个实验室的新功能，必须在主ISR中调用。

```
// run the flying start function
runFlyingStart(estHandle);
```

飞行起动变量和标志在下面的新函数中更新，该函数可以在主后台循环中的ISR外部调用。

```
// run motor control function
runMotorCtrl(estHandle);
```

如下图所示，模块例程禁用速度闭环控制，将参考Iq设为零，并启用HaawkSPIN FOC模块。在测量相电流和电压后，例程运行HaawkSPIN FOC，可以估算实际电机速度。程序在完成飞行起动后重新启用速度闭环控制，并设置速度参考值。

![实验九-飞行启动程序流图](C:\Users\Administrator\Downloads\实验九-飞行启动程序流图.png)



#### 2.9.5调试步骤

跟前述实验一样，首先要设置好实验套件，确保正确连接电机和电源。

其次，在“user.h”头文件中，确保已知道并正确设置电机参数。实验“HXS320F280049C_EDC_is09_flying_start”仅适用于永磁同步电机。

要使用飞行起动功能运行电机：

- 将变量“motorVars.flagEnableSys”设置为1。
- 将变量“motorVars.flagEnableFlyingStart”设置为1，启用飞行起动功能。
- 将变量“motorVars.flagEnableRunAndIdentify”设置为1，打开PWM输出到电机。
- 可通过调整“motorVars.accelerationMax_Hzps”中的值来修改加速度。
- 使用“motorVars.speedRef_Hz”设置参考速度，以便在目标速度下运行电机。

------

受限于负载设备，目前实验环境还无法测试飞行启动功能。





#### 2.9.6结论

本实验“HXS320F280049C_EDC_is09_flying_start”在HaawkSPIN FOC示例中增加了飞行起动功能。飞行起动功能允许电机在非零速度下启动，而不会在驱动器中触发过流保护。



### 2.10实验十：HXS320F280049C_EDC_is10_rs_recalc

#### 2.10.1摘要

电机线圈的定子电阻（也称为 Rs）可能会根据线圈（也称为电机绕组）的工作温度发生显著变化。由于多个因素，这一温度可能会升高。以下列举了一些可能影响定子线圈温度的情况：

- 线圈中通过的电流过大。
- 电机的外壳不允许自冷却。
- 严苛的工作环境导致温度升高。
- 电机附近的其他加热元件。

由于温度的升高，电机绕组的电阻也会增加。根据用于绕组的材料，这种电阻与温度之间的关系定义明确。

#### 2.10.2引言

定子电阻在线辨识（Online Stator Resistance Identification）是指在电机运行过程中，实时估算并调整定子电阻参数的过程。这对于保持电机控制的准确性和效率非常重要，尤其是在定子电阻会随着温度变化显著波动的情况下。

电阻在线辨识对于电机控制系统的运行效率具有至关重要的意义：

- **温度补偿**：电机运行过程中，定子电阻会由于温度变化而变化。在线辨识可以实时监测这些变化，进行及时补偿。
- **提高控制精度**：准确的定子电阻值有助于提高电机控制系统（如FOC）的精度，从而提高电机性能。
- **保护电机**：通过实时监测定子电阻，可以检测到异常的温升，提前采取保护措施，防止电机过热损坏。



#### 2.10.3学习目标

- 运行 Rs 在线重校准功能。

- 在电机运行时查看 Rs 值的更新情况。

#### 2.10.4背景

以下函数是本实验中用到的新函数，如下表所示。这些函数都打包在一个名为 `runRsOnLine()` 的新函数中，该函数在主后台循环中调用。该函数包含以下估算器函数：

![实验十-在线电阻辨识核心函数列表](C:\Users\Administrator\Downloads\实验十-在线电阻辨识核心函数列表.png)

在线电阻辨识的FoC架构图如下所示，红色部分为启用 Rs 在线的函数调用。同样以红色显示的是来自HaawkFAST 的 Id 参考，它在 Rs 在线启用时允许 Rs 在线功能工作。

![实验十-在线电阻辨识FoC架构图](C:\Users\Administrator\Downloads\实验十-在线电阻辨识FoC架构图.png)

实验“HXS320F280049C_EDC_is10_rs_recalc”的状态机流程图如下图所示，允许 Rs 在线重校准在后台循环中工作。

![实验十-在线电阻辨识控制流程图](C:\Users\Administrator\Downloads\实验十-在线电阻辨识控制流程图.png)

在线辨识的基本步骤

1. **电流注入**：在定子绕组中注入已知的电流。
2. **电压测量**：测量注入电流后的电压变化。
3. **计算电阻**：根据欧姆定律（V = I * R），计算出定子电阻。
4. **动态调整**：将计算得到的定子电阻值反馈到电机控制算法中，实时调整控制参数。



#### 2.10.5调试步骤

构建项目“HXS320F280049C_EDC_is10_rs_recalc”，连接到目标板并加载 .elf文件。

1. 点击运行按钮。
4. 在监视窗口启用连续刷新。
5. 将“motorVars.flagEnableSys”和“motorVars.flagEnableRunAndIdentify”标志都设置为“1”以运行电机。
6. 将“motorVars.flagEnableRsOnLine”标志设置为“1”以启用 Rs 在线功能。

一旦电机开始运行，可以看到下图所示的电阻辨识结果。这意味着 Rs 在线功能正在运行，算法正在修改 Id 参考值。

![实验十-在线电阻辨识0.5](C:\Users\Administrator\Downloads\实验十-在线电阻辨识0.5.png)

通过调整motorVars.RsOnLineCurrent_A的值，可以观测到不同的电阻辨识过程。

![实验十-在线电阻辨识1.5](C:\Users\Administrator\Downloads\实验十-在线电阻辨识1.5.png)

#### 2.10.6结论



### 2.11实验十一：HXS320F280049C_EDC_is11_dual_motor

#### 2.11.1摘要

该实验涵盖了如何使用HaawkSPIN FOC基于一个RISC-V DSP控制两台电机，确切的说就是F280049C芯片。

#### 2.11.2引言

双电机控制具有多种优势，尤其在需要同步或独立控制两台电机的应用中；同时，集成双电机控制系统可以减少控制器数量，降低设备的重量和体积，特别适用于空间和重量受限的应用，如无人机和便携式设备。双电机控制不仅可以提升系统性能和效率，还能降低成本和复杂性，为各种工业和消费应用提供灵活、可靠的解决方案。

双电机控制的难点主要包括以下几个方面：

1. **资源分配**：
   - 单个MCU需要管理和分配足够的资源（如定时器、PWM通道、ADC通道等）来同时控制两台电机。
   - MCU的计算能力和存储容量需要足够强大，以处理两台电机的控制算法和反馈数据。

2. **同步控制**：
   - 若要求两台电机同步运行，必须确保它们的速度和位置控制紧密协调。这需要复杂的算法和精确的反馈控制。
   - 处理两台电机的同步误差，确保在各种负载和条件下两台电机都能同步运行。

3. **独立控制**：
   - 在独立控制两台电机时，需要确保一个电机的控制不会干扰另一个电机的运行。这涉及到隔离控制信号和避免电气干扰。
   - 管理两个独立的控制回路，确保每个电机的控制参数和状态反馈都准确无误。

4. **实时性和响应速度**：
   - 双电机控制对实时性要求更高，MCU必须快速响应每台电机的控制需求，确保系统稳定运行。
   - 实时处理两个电机的速度、电流、位置等反馈信号，及时调整控制输出。

5. **调试和维护**：
   - 双电机系统更复杂，调试时需要同时监控和分析两台电机的运行状态，找出并解决潜在问题。
   - 维护过程中，需要考虑两台电机的同步性和独立性，确保系统的可靠性和稳定性。

通过合理的算法设计和充分利用MCU的资源，可以克服这些难点，实现双电机的高效控制。

#### 2.11.3学习目标

- 如何使用HaawkSPIN FOC基于单个RISC-V DSP控制两台电机。
- 如何同步或独立运行两台电机。

#### 2.11.4背景

实验“HXS320F280049C_EDC_is11_dual_motor”通过在单个HX2000 RISC-V DSP上利用两个HawwkSPIN FOC实例实现了双电机控制。用于控制单个电机的相同控制技术现在用于控制两个电机。“HXS320F280049C_EDC_is11_dual_motor”实验继续使用单个中断子程序mainISR()来运行两个电机的时间关键的HaawkSPIN FOC代码。

在“HXS320F280049C_EDC_is11_dual_motor.c”中，为每个电机初始化参数，设置两个电机的通用硬件，创建一个新的硬件抽象层对象，并设置每个电机的驱动参数，并定义所有控制对象。

相位控制被实施以改进两个电机反馈信号的电流采样。在相应的PWM模块之间建立了90º的相位关系，motor_1被设置为主模块，motor_2为从模块。PWM模块的配置在‘hal_dm.c’中的HAL_setupPWMs()中完成。

双电机控制的PWM输出波形示例如下图所示，

![实验十一-双电机控制PWM输出波形](C:\Users\Administrator\Downloads\实验十一-双电机控制PWM输出波形.png)

电机电流波形如下图所示。

![实验十一-双电机控制电流波形](C:\Users\Administrator\Downloads\实验十一-双电机控制电流波形.png)

`mainISR()` 是时间关键的。在将代码集成到此 ISR 中时，必须验证这两个 ISR 是否能够实时运行。

`CPU_Time` 模块允许测量 ISR 使用的 CPU 时间。根据这些信息，用户可能需要释放一些空间以添加其他功能，或者可能希望增加 ISR 的频率以实现更紧密的电流控制。

`CPU_TIME_run()` 函数计算 ISR 的最大、最小和平均 CPU 使用时间。如果用户想要重置这些值并重新开始计算，可以将 `cpuTime.flag_resetStatus` 标志设置为 1。最大和最小 CPU 使用时间可以通过监视窗口进行监控，如下图所示。确保 `cpuTime.timer_delta_max` 的值小于 [`cpuTime.pwm_period` – 100] 以避免 ISR 时间溢出。



双电机控制，会增加一些C文件和h文件，以及一些全局变量，如下所示。

![实验十一-双电机控制所需新增的c文件](C:\Users\Administrator\Downloads\实验十一-双电机控制所需新增的c文件.png)

![实验十一-双电机控制所需新增的h文件](C:\Users\Administrator\Downloads\实验十一-双电机控制所需新增的h文件.png)

![实验十一-双电机控制所需新增的全局变量](C:\Users\Administrator\Downloads\实验十一-双电机控制所需新增的全局变量.png)



#### 2.11.5调试步骤

跟前述实验一样，首先要设置好实验套件，确保正确连接电机和电源。

其次，在“user.h”头文件中，确保已知道并正确设置电机参数。

将变量 `systemVars.flagEnableSystem` 设置为 `1`，可以启动项目。在本实验中，`motorVars[0].flagEnableSys` 和 `motorVars[1].flagEnableSys` 变量将自动设置为 `1`，以完成电流和电压偏移校准。

可以使用相同的标志和速度参考来同步运行两个电机：
- 将变量 `systemVars.flagEnableSynControl` 设置为 `1`，启用同步控制。
- 将变量 `systemVars.flagEnableRun` 设置为 `1`，启动电流和速度闭环控制器。
- 通过调整 `systemVars.accelerationMaxSet_Hzps` 中的值来修改加速度。
- 设置参考速度到 `systemVars.speedSet_krpm` 以使电机以目标速度运行。

也可以使用不同的标志和速度参考来独立运行两个电机：
- 运行第一个电机（motor_1）：
  - 将变量 `systemVars.flagEnableSynControl` 设置为 `0`，禁用同步控制。
  - 将变量 `motorVars[0].flagEnableRunAndIdentify` 设置为 `1`，启用 PWM 输出到 motor_1。
  - 通过调整 `motorVars[0].accelerationMax_Hzps` 中的值来修改加速度。
  - 设置参考速度到 `motorVars[0].speedRef_Hz` 以使 motor_1 以目标速度运行。

- 运行第二个电机（motor_2）：
  - 将变量 `systemVars.flagEnableSynControl` 设置为 `0`，禁用同步控制。
  - 将变量 `motorVars[1].flagEnableRunAndIdentify` 设置为 `1`，启用 PWM 输出到 motor_2。
  - 通过调整 `motorVars[1].accelerationMax_Hzps` 中的值来修改加速度。
  - 设置参考速度到 `motorVars[1].speedRef_Hz` 以使 motor_2 以目标速度运行。

![实验十一-双电机控制接线图](C:\Users\Administrator\Downloads\实验十一-双电机控制接线图.png)

可以通过修改motorVars[1].speedRef_Hz的符号，实现电机的正反转。



实验结束后，停止电机：

- 如果使用同步控制，将变量 `systemVars.flagEnableRun` 设置为 `0`；如果不使用同步控制，将 `motorVars[0].flagEnableRunAndIdentify` 或 `motorVars[1].flagEnableRunAndIdentify` 设置为 `0`，以禁用 PWM 输出到电机。
- 停止调试器。
- 关闭驱动套件的电源。



#### 2.11.6结论

实验 “HXS320F280049C_EDC_is11_dual_motor” 展示了如何在双电机系统中使用HaawkSPIN FOC，演示了如何使用单个HX2000  RISC-V DSP芯片快速部署无传感器控制两台电机的设置。



### 2.12实验十二：HXS320F280049C_EDC_is12_variable_pwm_frequency

#### 2.12.1摘要

在电机驱动应用中，逆变器的热损耗和效率必须在设计中加以考虑。在线可变开关频率可以减少功率模块损耗，从而提高电机的运行效率。本实验展示了如何在HaawkSPIN FOC项目中使用在线可变开关频率功能。

#### 2.12.2引言

实验“HXS320F280049C_EDC_is12_variable_pwm_frequency”提供了HaawkSPIN FOC在线可变开关频率功能的示例。在线可变开关频率是一种功能，它允许驱动器更改FET的开关频率，以在不更改任何附加控制参数的情况下优化电机驱动效率。更改开关频率可以帮助在低速运行期间减少热量产生和损耗，减少电流波动，并通过使用更高的开关频率在高速区域减少可听噪音。

#### 2.12.3学习目标

本实验的目的是学习如何在实验项目中实现在线可变开关频率。

#### 2.12.4背景

功率模块的总损耗包括绝缘栅双极型晶体管（IGBT）损耗和自由轮回二极管（FWD）损耗。IGBT的损耗包括稳态导通损耗和开关损耗，如下面公式Ploss(IGBT )所示，而FWD的损耗包括稳态导通损耗和反向恢复损耗，如下面公式Ploss(FWD)所示。

![实验十二-功率损耗公式1](C:\Users\Administrator\Downloads\实验十二-功率损耗公式1.png)

IGBT和自由轮回二极管的导通损耗可以通过在导通期间流经集电极/阳极的电流乘以饱和电压的积分来计算。相比之下，开关损耗是由于在过渡和开关事件期间发生的能量损失所引起的。导通损耗主要取决于占空比、负载电流和结温；而开关损耗取决于负载电流、直流母线电压、结温和开关频率，如公式Psw(IGBT)和公式Prec(FWD)所示。

![实验十二-功率损耗公式2](C:\Users\Administrator\Downloads\实验十二-功率损耗公式2.png)

IGBT开关损耗和FWD反向恢复损耗随开关频率增加而增加，同时总损耗也随电流增加而增加。如果开关频率较高，则损耗会更高，导致更多的热量产生，这需要更大的功率模块和冷却系统。为了解决这个问题，使用在线可变开关频率方案来减少由于开关损耗引起的功率模块效率低下。

在FOC（Field-Oriented Control）控制系统中，不同的载波频率对电机的运行性能和系统特性有显著影响。以下是同样转速下，不同载波频率的主要差异：

1.电流波动

- **高载波频率**：较高的载波频率会导致电流波动减小。这是因为开关频率越高，电流控制的反应越快，电流波形越接近理想的正弦波形。

- **低载波频率**：较低的载波频率会导致电流波动增大，电流波形较为粗糙，电流中的谐波分量增加。

2.热损耗和效率

- **高载波频率**：开关频率越高，逆变器中的开关损耗越大，这会导致功率模块的热损耗增加，系统效率降低。
- **低载波频率**：开关频率越低，开关损耗减少，功率模块的热损耗减小，系统效率提高。

3.可听噪音

- **高载波频率**：高开关频率通常超出了人耳的听觉范围（超过20 kHz），因此在高速区域内可以减少可听噪音。
- **低载波频率**：低开关频率会导致逆变器产生的噪音落在可听范围内，可能会在电机运行时听到明显的嗡嗡声或其他噪音。

4.电磁干扰（EMI）

- **高载波频率**：高频开关会产生更多的高频电磁干扰（EMI），这需要更好的屏蔽和滤波措施来减少对其他电子设备的影响。
- **低载波频率**：低频开关产生的EMI较少，对系统的电磁兼容性（EMC）影响较小。

5.控制响应

- **高载波频率**：高频率的载波使得PWM信号能够更快地响应电机的变化，提高了系统的动态响应速度。
- **低载波频率**：低频率的载波响应较慢，可能会在快速变化的负载或转速条件下降低控制系统的响应速度。

在FOC控制系统中，选择合适的载波频率需要在电流波动、热损耗、噪音、电磁干扰和控制响应之间找到一个平衡点。高载波频率有利于电流波形质量和减少可听噪音，但会增加热损耗和电磁干扰；低载波频率则有助于提高系统效率和减少EMI，但可能会增加电流波动和可听噪音。

#### 2.12.5调试步骤

首先，要将宏定义`_VSF_EN_`打开，然后才会使能estISR的中断服务程序，如下所示。

```
//! \brief      Initializes the interrupt vector table
//! \details    Points the ISR to the function mainISR.
//! \param[in]  handle  The hardware abstraction layer (HAL) handle
static inline void HAL_initIntVectorTable(HAL_Handle handle)
{

    Interrupt_register(INT_ADCA1, &mainISR);

#ifdef _VSF_EN_
    Interrupt_register(INT_TIMER0, &estISR);
#endif  // _VSF_EN_

    return;
} // end of HAL_initIntVectorTable() function
```

同时，还涉及到两个控制器，电流环和速度环，分别由函数computeCurrentControllers()和computeSpeedControllers()来完成。

在mainISR中，更新pwm的周期和计数寄存器，代码如下：

```
//
// update pwm period and counter of vsf functions
//
VSF_setPeriod(vsfHandle);
VSF_getPeriod(vsfHandle, &(pwmData.period));
```

跟前述实验一样，首先要设置好实验套件，确保正确连接电机和电源。

其次，在“user.h”头文件中，确保已知道并正确设置电机参数。

运行电机
- 将变量“motorVars.flagEnableSys”设置为1，启动项目。
- 将变量“motorVars.flagEnableRunAndIdentify”设置为1，开启电机的PWM。
- 可以通过调整“motorVars.accelerationMax_Hzps”的值来修改加速度。
- 设置“motorVars.speedRef_Hz”以运行电机到目标速度。

调整载波频率，使用在线可变开关频率功能运行电机

- 将 `pwmFreqSet_Hz` 设置为目标开关频率，单位为 Hz。
- 在 `vsf.h` 中的 `NUM_VSF_DELTA` 和 `NUM_VSF_WAIT_TIME` 用于设置改变开关频率的斜坡速度。

![实验十二-变频测试之默认15KHz](C:\Users\Administrator\Downloads\实验十二-变频测试之默认15KHz.png)

![实验十二-变频测试之20KHz](C:\Users\Administrator\Downloads\实验十二-变频测试之20KHz.png)

![实验十二-变频测试之5KHz](C:\Users\Administrator\Downloads\实验十二-变频测试之5KHz.png)





#### 2.12.6结论

本实验为HaawkSPIN FOC的功能集增加了在线可变开关频率功能。此功能允许在运行时更改开关频率，以通过减少功率损耗来提高逆变器的效率。

### 2.13实验十三：HXS320F280049C_EDC_is13_fwc_mtpa

#### 2.13.1摘要

本实验展示了如何在HaawkSPIN FOC项目中实现磁场弱化（FW）和每安培最大转矩（MTPA）技术，以控制三相内嵌式永磁同步电机（IPM）在广泛的速度范围内运行。在这个例子中，操作模式将根据速度命令和输入直流链电压自动从恒定转矩区域的MTPA控制切换到恒定功率区域的FW控制。

#### 2.13.2引言

永磁同步电机（PMSM）由于其高功率密度、高效率和宽速度范围，被广泛应用于家用电器、工业驱动和汽车应用中。PMSM主要包括两种类型：表面贴装PMSM（SPM）和内嵌PMSM（IPM）。SPM电机由于其转矩与q轴电流之间的线性关系，更容易控制。然而，IPMSM由于其大的凸极比，既有电磁转矩又有磁阻转矩。包括电磁转矩和磁阻转矩在内的总转矩与转子角度呈非线性关系。因此，MTPA技术可以用于IPM电机，以在恒定转矩区域优化转矩生成。磁场弱化控制的目的是优化Id，以达到PMSM驱动的最高功率和效率。磁场弱化可以使电机在基础速度以上运行，扩展永磁电机的操作极限，以达到高于额定速度的速度，并允许在整个速度和电压范围内实现最佳控制。

本实验“HXS320F280049C_EDC_is13_fwc_mtpa”是基于实验十“HXS320F280049C_EDC_is10_rs_recalc”开发的项目，添加了磁场弱化（FW）和每安培最大转矩（MTPA）控制模块。这两个模块可以同时使用，也可以根据电机控制需求单独使用。

TI的例程中，曾经使用过两款IPM电机，

```
// IPM motors
// If user provides separate Ls-d, Ls-q
// else treat as SPM with user or identified average Ls
#define Belt_Drive_Washer_IPM 201
#define Anaheim_Salient 202
```



#### 2.13.3学习目标

- 了解FW和MTPA模块在实验“HXS320F280049C_EDC_is13_fwc_mtpa”中的添加位置。
- 调整FW模块以执行磁场弱化控制，扩展速度范围。
- 调整MTPA模块以执行每安培最大转矩控制，产生更大的电磁转矩。

#### 2.13.4背景

IPMSM数学模型的电压方程可以用d-q坐标系表示，如下所示：

![实验十三-IPMSM电机的d-q轴电压计算公式](C:\Users\Administrator\Downloads\实验十三-IPMSM电机的d-q轴电压计算公式.png)

IPM同步电机的动态等效电路如上图所示。IPMSM产生的总转矩T可以用下面的方程表示，即所产生的转矩由两个不同的项组成。第一个项对应于转矩电流id与永磁体之间的相互反应转矩φm，第二个项对应于由于d轴和q轴电感差异而产生的磁阻转矩。

![实验十三-IPMSM电机的扭矩计算公式](C:\Users\Administrator\Downloads\实验十三-IPMSM电机的扭矩计算公式.png)

在大多数应用中，IPMSM驱动器存在速度和转矩限制，主要由于逆变器或电机额定电流和可用直流母线电压的限制。这些限制可以用下面的数学方程表示：

![实验十三-IPMSM电机的电流和电压限幅值计算公式](C:\Users\Administrator\Downloads\实验十三-IPMSM电机的电流和电压限幅值计算公式.png)

其中 Vmax 和 Imax 是逆变器或电机的最大允许电压和电流。在由两级三相电压源逆变器 (VSI) 供电的机器中，最大可实现的相电压受直流母线电压和 PWM 策略的限制。如果采用空间矢量调制 (SVPWM)，最大电压限制如下面方程所示：

![实验十三-IPMSM电机的电压和母线电压关系](C:\Users\Administrator\Downloads\实验十三-IPMSM电机的电压和母线电压关系.png)

通常在高速运行时，定子电阻 ( Rs \) 可以忽略，并且在稳态下电流的导数为零，因此可以得到如下的方程。

![实验十三-IPMSM电机的电压限幅与转速w的关系](C:\Users\Administrator\Downloads\实验十三-IPMSM电机的电压限幅与转速w的关系.png)

电流限制在定子电流的 d-q 平面上产生一个半径为 Imax的圆，而电压限制则产生一个随着速度增加而半径减小的椭圆。结果是 d-q 平面的电流矢量必须同时遵守电流和电压限制。根据这些限制，可以区分出 IPMSM 的三个运行区域，如下图所示。

![实验十三-IPMSM电机的三个运行区域](C:\Users\Administrator\Downloads\实验十三-IPMSM电机的三个运行区域.png)

I. 恒定转矩区域：在该运行区域可以实现 MTPA，以确保最大转矩生成。
II. 恒定功率区域：必须采用磁场弱化控制，当达到电流限制时转矩能力减小。
III. 恒定电压区域：在该运行区域，深度磁场弱化控制保持恒定定子电压以最大化转矩生成。

在恒定转矩区域，根据Te力矩方程，IPMSM 的总转矩包括来自磁链的电磁转矩和由 L_d 和 L_q 之间的显著差异引起的磁阻转矩。电磁转矩与 q 轴电流成正比，而磁阻转矩与 d 轴电流、q 轴电流及 L_d 和 L_q 之间的差异的乘积成正比。

传统的 SPM 电机矢量控制系统仅利用电磁转矩，在非磁场弱化模式下将指令 i_d 设为零。但对于 IPMSM，为了利用电机的磁阻转矩，也应控制 d 轴电流。MTPA 控制的目的是计算参考电流 i_d 和 i_q，以最大化产生的电磁转矩和磁阻转矩之间的比例。以下方程展示了 i_d、i_q 和定子电流矢量和 I_s 之间的关系：

![实验十三-IPMSM电机的定子电流的计算公式](C:\Users\Administrator\Downloads\实验十三-IPMSM电机的定子电流的计算公式.png)

则，前面力矩Te的计算公式，可以将Is带入后，得到如下公式：

![实验十三-IPMSM电机带入Is后力矩Te的计算公式](C:\Users\Administrator\Downloads\实验十三-IPMSM电机带入Is后力矩Te的计算公式.png)

上面的方程表明，电机转矩取决于定子电流矢量的角度。因此，当电机转矩微分等于零时，可以计算出最大效率点。当微分 \(\frac{dT}{d\theta}\) 等于零时，可以找到 MTPA 点，如下面的方程所示：

![实验十三-IPMSM电机MTPA的计算公式](C:\Users\Administrator\Downloads\实验十三-IPMSM电机MTPA的计算公式.png)

接下来，MTPA 控制的电流角度可以推导如下：

![实验十三-IPMSM电机MTPA时电流角度的计算公式](C:\Users\Administrator\Downloads\实验十三-IPMSM电机MTPA时电流角度的计算公式.png)

因此，使用 MTPA 控制的电流角度，可以用下面方程表示有效的 d 轴和 q 轴参考电流。

![实验十三-IPMSM电机MTPA时Id和Iq的计算公式](C:\Users\Administrator\Downloads\实验十三-IPMSM电机MTPA时Id和Iq的计算公式.png)

然而，如方程βmtpa所示，MTPA 控制的角度与 d 轴和 q 轴电感有关。这意味着电感的变化会阻碍找到最佳 MTPA 点的能力。为了提高电机驱动的效率，d 轴和 q 轴电感应该在线估计，但参数 \(L_d\) 和 \(L_q\) 在线测量不易，并且受到饱和效应的影响。一个健壮的查找表 (LUT) 可以确保在电气参数变化下的可控性。通常，为了简化数学模型，可以忽略 d 轴和 q 轴电感之间的耦合效应。因此，\(L_d\) 只随 \(i_d\) 变化，\(L_q\) 只随 \(i_q\) 变化。因此，d 轴和 q 轴电感可以分别建模为它们各自 d-q 电流的函数，如下所示。

![实验十三-IPMSM电机MTPA时Ld和Lq的计算公式](C:\Users\Administrator\Downloads\实验十三-IPMSM电机MTPA时Ld和Lq的计算公式.png)

通过简化βmtpa方程可以减少 ISR 计算的负担。使用基于电机参数的常数 \( kmtpa \)，则βmtpa方程可以改写为如下的计算公式，其中kmtpa在后台循环中使用更新的 \( L_d \) 和 \( L_q \) 进行计算。

![实验十三-IPMSM电机MTPA时电流角度简化的计算公式](C:\Users\Administrator\Downloads\实验十三-IPMSM电机MTPA时电流角度简化的计算公式.png)

为了进一步简化βmtpa的计算，引入一个临时变量Gmtpa，如下所示。这两个方程的计算在 ISR 中进行，以获得实际的电流角度。

![实验十三-IPMSM电机MTPA时电流角度进一步简化的计算公式](C:\Users\Administrator\Downloads\实验十三-IPMSM电机MTPA时电流角度进一步简化的计算公式.png)

在所有情况下，通过作用于直轴电流 \( I_d \)，可以削弱磁通以扩展可实现的速度范围。因此，当进入这种恒功率操作区域时，会选择场弱化控制，而不是用于恒转矩区域的 MTPA 控制。

由于逆变器的最大电压有限，PMSM 电机无法在反电动势高于逆变器最大输出电压的速度区域中运行，反电动势几乎与永磁体的磁场和电机速度成正比。对 PM 电机来说，直接控制磁通不是一个选项。然而，可以通过在直轴电流中加入负值id，利用电枢反应的去磁效应来削弱气隙磁通。考虑到电压和电流限制，电枢电流 \( I_a \) 和端电压 \( V \) 受到方程Ia和方程Va的限制。逆变器输入电压（DC 链路电压）的变化限制了电机的最大输出。此外，最大基波电机电压也取决于使用的 PWM 方法。IPMSM 具有两个因素：一个是永磁体的值，另一个是由电感和磁通电流决定的。

![实验十三-IPMSM电机MTPA和FWC控制流程图](C:\Users\Administrator\Downloads\实验十三-IPMSM电机MTPA和FWC控制流程图.png)

上图显示了用于实现场弱化的典型控制结构； \( I_{d,ref} \) 是场弱化（FW）PI 控制器的输出，并生成参考电流 \( I_d \) 和 \( I_q \)。在电压幅值达到其极限之前，场弱化 PI 控制器的输入始终为正，因此其输出始终饱和在 0。

下图展示了HaawkSPIN FOC 的实现。该框图提供了HaawkSPIN FOC 系统功能和变量的概览。主要模块包括：
- 用于速度的轨迹控制模块
- 用于电流和电压的 Clarke 正变换模块
- Park 正变换和反变换模块
- 角度和速度估计器模块（FAST）
- 用于速度和电流的比例-积分控制器模块
- 场弱化（FW）和每安培最大扭矩（MTPA）模块
- 空间矢量调制模块

![实验十三-HaawFOC中MTPA和FWC控制框图](C:\Users\Administrator\Downloads\实验十三-HaawFOC中MTPA和FWC控制框图.png)

HaawkSPIN FOC 电机驱动系统中有两个控制模块，如上图所示：一个是 MTPA 控制，另一个是场弱化控制。这两个模块分别基于输入参数生成电流角度β。切换控制模块用于决定应用哪个角度，然后计算参考电流 \( i_d \) 和 \( i_q \)，如图 77 所示。电流角度的选择如下：
- \( \theta = \theta_{MTPA} \) 如果 \( V_{d} > V_{d,\text{limit}} \)
- \( \theta = \theta_{FW} \) 如果 \( V_{d} \leq V_{d,\text{limit}} \)

![实验十三-HaawFOC中MTPA和FWC控制示意图](C:\Users\Administrator\Downloads\实验十三-HaawFOC中MTPA和FWC控制示意图.png)

下图是一个程序控制的流程图，展示了在主循环和中断中运行HaawkSPIN FOC 与场弱化（FW）和最大转矩每安培（MTPA）的步骤。

![实验十三-HaawFOC中MTPA和FWC程序流图](C:\Users\Administrator\Downloads\实验十三-HaawFOC中MTPA和FWC程序流图.png)

在后台循环中更新 FW 和 MTPA 模块的控制参数

在 "HXS320F280049C_EDC_is13_fwc_mtpa.c" 文件的代码中，在后台循环中调用 FWC 和 MTPA 函数，基于更新后的电机参数计算 MTPA 的控制常数。用于根据电枢电流 I 计算 \(\theta\) 和 \(\delta\) 的表格在 mtpa.h 中定义，更新过程在后台循环中完成。

```
//
// Update FW control parameters
//
FWC_setKp(fwcHandle, motorVars.Kp_fwc);
FWC_setKi(fwcHandle, motorVars.Ki_fwc);
FWC_setAngleMax(fwcHandle, motorVars.angleMax_fwc_rad);

if(motorVars.flagUpdateMTPAParams == true)
{
    //
    // update motor parameters according to current
    //
    motorVars.LsOnline_d_H =
            MTPA_updateLs_d_withLUT(mtpaHandle, motorVars.Is_A);

    motorVars.LsOnline_q_H =
            MTPA_updateLs_q_withLUT(mtpaHandle, motorVars.Is_A);

    motorVars.fluxOnline_Wb = motorVars.flux_Wb;

    //
    // update the motor constant for MTPA based on
    // the update Ls_d and Ls_q which are the function of Is
    //
    MTPA_computeParameters(mtpaHandle,
                           motorVars.LsOnline_d_H,
                           motorVars.LsOnline_q_H,
                           motorVars.fluxOnline_Wb);
}

//
// get the mtpa constant
//
motorVars.mtpaKconst = MTPA_getKconst(mtpaHandle);
```

在 ISR 中更新 FW 和 MTPA 模块

在 "HXS320F280049C_EDC_is13_fwc_mtpa.c" 文件的代码中调用 FW 和 MTPA 函数，以计算电流角度，然后计算 d 轴和 q 轴的参考电流。

```
//
// run the FWC
//
FWC_computeCurrentAngle(fwcHandle,
                        motorVars.Vs_V, motorVars.VsRef_V);

//
// run the MTPA
//
MTPA_computeCurrentAngle(mtpaHandle,
                         motorVars.IsRef_A);

//
// get the current angle
//
motorVars.angleCurrent_rad =
                    MATH_max(FWC_getCurrentAngle_rad(fwcHandle),
                             MTPA_getCurrentAngle_rad(mtpaHandle));

currentPhasor.value[0] = cosf(motorVars.angleCurrent_rad);
currentPhasor.value[1] = sinf(motorVars.angleCurrent_rad);
```



#### 2.13.5调试步骤

跟前述实验一样，首先要设置好实验套件，确保正确连接电机和电源。

其次，在“user.h”头文件中，确保已知道并正确设置电机参数。

运行电机

- 将变量“motorVars.flagEnableSys”设置为1，启动项目。
- 将变量“motorVars.flagEnableRunAndIdentify”设置为1，开启电机的PWM。
- 可以通过调整“motorVars.accelerationMax_Hzps”的值来修改加速度。
- 设置“motorVars.speedRef_Hz”以运行电机到目标速度。

使用FW和MTPA功能运行电机：

- 要启用FW，将“motorVars.flagEnableFWC”设置为“1”。
  - 通过设置motorVars.Kp_fwc、motorVars.Ki_fwc和motorVars.angleMax_fwc_rad来调整FW的控制参数。
- 要启用MTPA，将“motorVars.flagEnableMTPA”设置为“1”。

电机的默认速度是20Hz，可以通过调整电机的转速，查看Idq_ref_A.value[0]的符号，如果该值变成负数，则说明已经进入弱磁区间；同时，也可以通过fwcHandle结构体查看弱磁的Kp和Ki值，以及反馈值。

![实验十三-弱磁开关未使能，Id接近于0,100Hz](C:\Users\Administrator\Downloads\实验十三-弱磁开关未使能，Id接近于0,100Hz.png)

针对电机ZLAC60ASM400，当转速超过180Hz的时候，就开始进入弱磁区间；但是可以看出，跟过调制相比较，转速的提升并不明显，即使打开弱磁，也上不到200Hz。

未打开弱磁功能，测试结果如下：

![实验十三-弱磁开关未使能，Id接近于0,190Hz，速度无法跟踪](C:\Users\Administrator\Downloads\实验十三-弱磁开关未使能，Id接近于0,190Hz，速度无法跟踪.png)

![实验十三-弱磁开关未使能，Id接近于0,190Hz，速度无法跟踪-之二](C:\Users\Administrator\Downloads\实验十三-弱磁开关未使能，Id接近于0,190Hz，速度无法跟踪-之二.png)

打开弱磁功能，测试结果如下：

![实验十三-弱磁开关使能，Id接近于0,190Hz，速度可以跟踪-之一](C:\Users\Administrator\Downloads\实验十三-弱磁开关使能，Id接近于0,190Hz，速度可以跟踪-之一.png)

![实验十三-弱磁开关使能，Id接近于0,190Hz，速度可以跟踪-之二](C:\Users\Administrator\Downloads\实验十三-弱磁开关使能，Id接近于0,190Hz，速度可以跟踪-之二.png)

实验结束后，停止电机的方法：

- 将变量“motorVars.flagEnableRunAndIdentify”设置为“0”，以关闭电机的PWM。
- 停止调试器。
- 关闭驱动套件的电源。



#### 2.13.6结论

本实验在HaawkSPIN FOC中添加了磁场弱化（FW）和最大扭矩每安培（MTPA）控制功能。这些功能允许在恒定扭矩区域内通过MTPA提高扭矩输出，并通过FW在基础速度之上扩展速度范围，从而在MTPA和FW之间实现非常平滑的过渡。



## 3.电机控制基础知识汇总

### 3.1电机分类及常见电机介绍

***注**：本章节内容大多参考**移步IT之巅**相关文章。*

电机的分类方式有多重，但常见的主要按以下6大类划分

1、**按工作电源种类**：可分为直流电机和交流电机。其中交流电机还可分为单相电机（220V）和三相电机（380V）。

2、**按结构和工作原理**：可分为直流电动机、异步电动机、同步电动机。

3、**按起动与运行方式**：电容起动式单相异步电动机、电容运转式单相异步电动机、电容起动运转式单相异步电动机和分相式单相异步电动机。

4、**按用途**：驱动用电动机和控制用电动机。

5、**按转子的结构**：笼型感应电动机（旧标准称为鼠笼型异步电动机）和绕线转子感应电动机（旧标准称为绕线型异步电动机）。

6、**按运转速度**：高速电动机、低速电动机、恒速电动机、调速电动机。

![电机分类总图](C:\Users\Administrator\Downloads\电机分类总图.png)

![电机分类总图之二](C:\Users\Administrator\Downloads\电机分类总图之二.png)

#### 3.1.1直流电机

直流电动机是依靠直流电驱动的电动机，最常见的是以磁场产生的力使电动机转动。几乎所有电流电动机都有类似的机构，用机电或电子的方式，周期性地改变电动机中电流的方向。

直流电动机是最早使用的电动机，可以用当时的直流电照明电源系统来供电。直流电动机的速度调整范围很大，调整方式为改变电源电压或是调整磁场强度。小型的直流电动机会用在工具、玩具及家电上。交流整流子电动机可以用直流电供电运转，是轻型的有刷电动机，用在电池供电的动力工具或是家电中。较大功率的直流电动机可以当作电动载具、电梯及吊车的动力来源，也可以用在轧钢厂的设备中。由于电力电子学的演进，交流电动机在许多应用上已可以取代直流电动机。

##### 3.1.1.1直流有刷电机

直流有刷电动机利用内部的换向器（整流子）、定子磁铁（永久磁铁或是电磁铁）及旋转的电磁铁，利用直流电源来产生力矩。

直流有刷电动机的好处是初期成本低，高可靠度，控制电动机速度的方式简单。缺点是高强度使用下的高维护成本以及低生命周期。维护包括定期更换整流子上导电的碳刷以及弹簧，也需要清洁或更换整流子。这些设备是将外部电源传送到电动机内部必要的零组件。

碳刷一般是用碳或是石墨所制，有时会加入铜粉以增加导电性。在使用时，软的碳刷材料会磨损，以符合整流子的半径，而且会继续磨损。碳刷架有弹簧，在碳刷变短时仍维持其压力。若碳刷承载的电流超过一安培或二安培，会有飞线放在电刷中，并且和电动机端子连接。非常小功率的电动机会用金属电刷架上的滑动接触来传导电刷上的电流，或是用接触弹簧压在电刷末端。若是非常小功率，短寿命的电动机（例如玩具中的电动机），会用与换向器接触的折叠金属带来当作电刷。



##### 3.1.1.2直流无刷电机

典型的直流无刷电动机会在转子上放永久磁铁，配置定子上的电磁铁使转子旋转。电动机控制器会将直流电转换为交流电。这种电动机在机械设计上比较简单，不用考虑将外部电源传递到转子的机构。电动机控制器可以用霍尔效应感测器或是类似元件感测转子角度，来调整电流时序及相位，以达到力矩最大化、能量转换、速度控制，甚至部分的刹车机能。也有些电动机控制器没有位置感测器（sensorless），利用电流量测以及电动机的相关参数来推算转子的转速。无刷电动机的优点包括寿命长，几乎不需要保养，以及其高效率。其缺点是初期成本高、电动机速度控制器复杂等。有些无刷电动机会称为“同步电动机”，不过此“同步”的意思是转子的转速和定子上交流电对应的机械转速相同（若是感应电动机，转子转速和定子上交流电对应的机械转速之间会存在滑差），不是转子转速和交流电源对应的机械转速同步。



##### 3.1.1.3无整流子的电动机

有些直流电动机不需要整流子。

- 单极电动机：单极电动机有一个沿着旋转轴的磁场，以及一个在同一点，但和磁场不平行的电流。“单极”是指其中没有极性的变化。单极电动机的线圈只允许一圈，因此其电压很低，这也限制此电动机在实务上的应用。
- 滚珠轴承电动机：滚珠轴承电动机是一种特殊的电动机，其中包括二个滚珠轴承，轴承内圈接在共同的的导电衬套上，轴承外圈接在大电流的低压电源上。另一种架构是外圈在金属管内，内圈在一个不导电的轴上。滚珠轴承电动机的好处是轴会以类似飞轮的形式旋转，滚珠轴承电动机需要外力辅助才能开始旋转，旋转方向会依照一开始时的旋转方向而定。

##### 3.1.1.4和交流电动机的比较

直流电动机（DC Motor）的好处为在控速方面比较简单，只须控制电压大小即可控制转速，但此类电动机不宜在高温、易燃等环境下操作，许多直动电动机中需要以碳刷作为电流变换器（Commutator）的部件（直流有刷电动机），所以需要定期清理炭刷磨擦所产生的污物。无碳刷之直流电动机称为直流无刷电动机，相对于有刷，无刷电动机因为少了碳刷与轴的摩擦因此较省电也比较安静。制作难度较高、价格也较高。

交流电动机（AC Motor）则可以在高温、易燃等环境下操作，而且不用定期清理碳刷的污物，但在控速上比较困难，因为控制交流电动机转速需要控制交流电的频率（或使用感应电动机，用增加内部阻力的方式，在相同交流电的频率下降低电动机转速），控制其电压只会影响电动机的扭力。一般工业用直流电动机之电压有 AC 110V (125V) 和AC 220V两种。

#### 3.1.2交流电机

交流电动机是利用交流电来激励并产生磁场的电动机，交流电动机可以控制电流和磁场的方向，是不用设计电刷的，而结构上主要分为同步电动机和异步电动机两大类，前者一般会有永久磁铁，后者则使用感应方式使线圈产生磁场，也可根据所加的交流电也分为单相和三相电机。

##### 3.1.2.1同步电动机

同步电动机是一种交流电动机，转子旋转速度与所提供交流电的角频率相同。原理是在转子励磁绕组中通以直流电流后电机内产生转子磁场，从而使电动机转子旋转。

同步电动机的转子主要为电磁铁或永久磁铁，使用永久磁铁的称为永磁同步电动机，若有电路提供转子电源的，即属于双馈型电动机。同步电动机的定子所产生的旋转磁场吸引转子磁场的异极，使转子随着定子磁场旋转，在稳定状态下，将以相同的速度旋转。

同步电动机的特点是转速固定，不受电源电压的影响。只要电动机的负载低于其最大转矩，转速也不会受负载的影响。因此小型的同步机可以应用在电子时钟、工业用定时器，或是要求精确等速的系统如磁带录音机、伺服机构。由于这种特性，同步电动机只能通过使用变频器调整电动机的电源频率来进行调速。

无载的同步机即是同步调相机（Synchronous Condenser），其电流相位超前于电压，为一个电容性负载。因此，若一供电系统的负载为落后功率因数，可以使用无载的同步电动机来改进其功率因数，但此方法的运作成本十分高。现在，电力公司可使用静止无功补偿器（Static VAR Compensator）来提供无功功率。

按照不同的励磁方式，同步电动机可以分为如下三类：

- 电励磁式：电励磁同步电机不能自动启动，所以在转子上还装有鼠笼式绕组而作为电动机启动之用，结构与异步电动机相似。电动机旋转之后，其速度慢慢增高到稍低于旋转磁场的转速，此时转子磁场线圈经由直流电来激励，使转子上面形成一定的磁极，这些磁极就企图跟踪定子上的旋转磁极，这样就增加电动机转子的速率直至与旋转磁场同步旋转为止。

- 永磁无刷：永磁同步电动机（permanent-magnet synchronous motor，缩写：PMSM）是指一种转子用永久磁铁代替绕线的同步电动机。
- 磁阻式：磁阻电动机（Reluctance motor）可以再细分为同步磁阻电动机（Synchronous reluctance motors，缩写：SynRM）和切换式磁阻电动机（Switched Reluctance Motor，缩写：SRM）。

同步电动机的转速，可以由下面的公式计算而来：

![同步电动机转速计算公式](C:\Users\Administrator\Downloads\同步电动机转速计算公式.png)

同步电动机有电动和发电两种状态，其稳定性极限如下所示：

![同步电机的电动和发电稳定极限](C:\Users\Administrator\Downloads\同步电机的电动和发电稳定极限.png)

##### 3.1.2.2表贴式PMSM

当三相PMSM转子磁路的结构不同时，电机的运行性能、控制方法、制造工艺和适用场合也会不同。目前，根据永磁体转子上的位置不同，三相PMSM的转子结构可以分为表贴式和内置式两种结构。

![永磁同步电机IPM-SPM](C:\Users\Administrator\Downloads\永磁同步电机IPM-SPM.png)

表面式永磁电动机简称 SPM，结构较简单，由于永久磁铁固定在转子表面，因此电动机的转子和定子中间有较宽的气隙，而磁铁的磁导率和空气相当，因此转子的凸极效应（saliency）很小，可以省略。较大的气隙也使得转子的电枢效应减弱，因此其电感Ld很小，也影响电动机的定子时间常数。

- 控制策略。

  - IPM：更多使用最大转矩电流比（MTP）+弱磁控制。


  - SPM：更多使用 id=0 的矢量控制。


- 应用领域。
  - SPM 电机主要应用于工业控制，而 IPM 电机主要用于电动汽车，这似乎表明 IPM 电机的功率密度比 SPM 电机更强，而 SPM 电机的控制性能比 IPM 电机更强。


- DQ 轴的电感

  - SPM 电机的 D 轴和 Q 轴电感相等。


  - IPM 电机的 D 轴和 Q 轴电感不同，且 Lq 大于 LD。



##### 3.1.2.3内嵌式PMSM

内藏式永磁电动机简称 IPM，其在转子内侧装有永久磁铁，由于磁铁受到转子的保护，在高速运转时电机不会出现磁铁脱落的问题，但转子需设有空洞用于置入磁铁。此外，由于转子的材质为矽钢，磁导率远高于磁铁，因此磁铁部分可视为一个额外的气隙，转子和定子间的气隙会产生周期性的变化（即凸极效应），因此产生的转矩中有磁阻转矩成分，其效率较高。

内藏式永磁电动机的设计需符合以下需求：

- 高功率/质量比及转矩/惯量比。
- 平顺的电磁转矩，尽量减少齿槽转矩（cogging torque）的产生。
- 高气隙磁通密度。
- 高性能及功率系数的小型化设计。





##### 3.1.2.4异步电动机

异步电动机（英语：asynchronous motor）也称为感应电动机（induction motor），简称 IM 或 ACIM，是一种由定子线圈利用电磁感应的方式使转子产生电流，让电动机产生力矩的交流电动机。异步电机可按转子绕组形式，分为绕线式和鼠笼式。绕线型的均为三相电动机，而鼠笼式的有三相电动机，也有单相电动机。鼠笼式感应电动机的转子可以不用连接电动机外部的电路。

三相异步电动机是工业用的电动机械，其功率范围从几瓦到上万千瓦，具有广泛的应用范围。三相异步电动机由三相电路为其提供动力，因为不需启动电路，而且可靠、价格不高，主要应用于挖掘、流体输送等需要提供动力的领域，例如机床、中小型轧钢设备、风机、水泵、轻工机械、冶金和矿山机械等。在化工，物流，工程制造等领域都广泛应用。其中主要是以鼠笼式异步电动机为主。单相异步电动机主要用在负载较小的场合，例如电风扇、洗衣机、电冰箱、空调器等家用电器。

异步电动机的传统应用是用在定速的场合，不过越来越多的三相异步电动机应用是配合变频器（VFD）或是变速驱动器使用。变频器可以配合频率调整输出电压。若是应用在离心型风扇、泵浦或是压缩机上，配合感应电动机有节能的效果。

异步电动机若接在频率为f的电网上运行时，转速n与电网频率f之间不存在同步电动机那样的恒定的比例关系。同步速和转子转速之间有转差，转差率通常介于3%到10%。如果转子转速高于同步速，则变成发电机。

![异步电动机的同步速计算公式](C:\Users\Administrator\Downloads\异步电动机的同步速计算公式.png)

异步电动机的转子绕组中没有使用外加电源供电，而是通过定子产生的旋转磁场（其转速为同步转速n1）与转子绕组的相对运动，转子绕组切割磁感线产生感应电动势，从而使转子绕组中产生感应电流，感应电流的方式类似变压器中二次绕组感应电流的方式。

转子绕组的感应电流会在转子产生磁场来反抗定子磁场造成的变化。根据**楞次定律**，转子上产生的磁场会和转子上的电流变化相反。此时转子所受电磁力的方向与定子旋转磁场方向相同，转子和开始往定子旋转磁场的方向旋转。当转子的电磁转矩与转子的机械负载转矩平衡的时候转子转速达到稳定。同步速和真实转速的转速差相对同步速的比例称为转差率（slip），若为转矩曲线为标准设计 B的感应电动机，其转差率介于0.5%和5.0%之间。异步电动机的特点就是其转子电流和转矩是由感应产生，不像同步电动机或直流电动机由独立转子激磁电路产生，也不像永磁电动机是用永久磁铁产生转子磁场。

为了产生转子电流，转子的实际转速会比定子旋转磁场的转速（ns）慢一些，否则旋转磁场和转子导体没有相对运动，转子上不会感应到电流。若转子速度低于同步速度，且持续下降，转子上的磁场旋转速度会增加，感应的电流会变大，也会产生较大的力矩。在有负载时，转子速度会下降，会产生够大的力矩推动负载旋转。因此感应电动机也称为是异步电动机。

![异步电动机的转差率计算公式](C:\Users\Administrator\Downloads\异步电动机的转差率计算公式.png)

因为鼠笼式转子的电阻很小，很小的转差率就可以产生转子的大电流，因而产生够大的转矩。在满载时，小功率电动机或是特殊用途的转差率约为5%，若是大功率电动机，转差率会小于1%。若功率不同的电动机直接以机械方式连接相同负载，其转差率的差异可能会造成负载分配的问题。

#### 3.1.3步进电动机

步进电动机（英语：Stepper motor、Step motor）是直流无刷电动机的一种，为具有如齿轮状突起（小齿）相锲合的定子和转子，可借由切换流向定子线圈中的电流，以一定角度逐步转动的电动机。

步进电动机的特征是采用开回路控制（Open-loop control）处理，不需要运行量传感器（sensor）或编码器，且切换电流触发器的是脉冲信号，不需要位置检出和速度检出的回授装置，所以步进电机可正确地依比例随脉冲信号而转动，因此达成精确的位置和速度控制，且稳定性佳。

步进电动机只需要通过脉波信号的操作，即可简单实现高精度的定位，并使工作物在目标位置高精度地停止。步进电动机是以基本步级角的角度为单位来进行定位。以5相步进电动机为例，其基本步级角为0.72，因此可以将电动机转1圈分为500等分（=360度 / 0.72），以此方式来细分每次行进量做为定位基准。

间歇动作是步进器输出的最佳方式。当应用需要电动机不间断运行时，步进电机会降低效率和扭矩。从成本的角度来看，步进电机通常比伺服电机便宜得多。

在步进电动机的选用上必须注意以下几点：

- 步进角：亦即步进电动机之分辨率（此指1脉波的移动量），步进电动机的步进角就是依电动机旋转一圈（360°）而分割成多少来决定。
- 转动速度：亦即脉波输入速度（pulse/s）。
- 转矩：选择步进电动机时，需以有负荷时之最大转矩（kg-m）的1.5倍~2倍来决定。
- 负荷惯性惯量：依据使用场合计算负荷惯性惯量，再依步进电动机规格表，选择容许负载惯性惯量需大于计算值之1.3倍以上。
- 驱动器：连结控制器或直接接受外部讯号，进而控制步进电动机动作。驱动器将直接影响步进电动机的性能表现。
- 搭配减速机：使用减速机型步进电动机可达到减速、提高转矩、提高分辨率、降低施加于电动机轴之负荷惯性惯量、改善起动与停止时的阻尼特性，进而降低运行之振动。

#### 3.1.4伺服电动机

伺服电机(电动机)（Servomotor）是对用于使用伺服机构的电动机总称。伺服（Servo）一词来自拉丁文"Servus"，本为奴隶（SI所谓伺服系统，就是依照指示命令动作所构成的控制装置，应用于电机的伺服控制，将感测器装在电机与控制对象机器上，侦测结果会返回伺服放大器与指令值做比较。由此可知，因为伺服电机是以回馈讯号控制，与借由输入脉冲讯号控制的步进电机有所区别。

伺服电机通常具有精密的位置检测元件如光电编码器或解角器（resolver）做为位置或速度的回授元件，伺服电机的装置由下列三者构成：

- 发出动作指令的"指示装置"（控制器，Controller）

- 依照指示装置的指示讯号与回馈讯号下等指令使电机动作的"控制装置"（伺服放大器），
- 以及将由伺服放大器而来的电力供给驱动控制对象和侦测其状态的"驱动、感测装置"。

伺服系统是控制结果与目标值的误差量能缩小。将来自控制对象的讯号返回到伺服放大器而反映在控制上，称为反馈（Feedback）。借由编码器（Encoder）感测电机旋转并回馈的方式，简单方便而广泛使用。相对地，可在控制对象机器外加装置如线性编码器等感测器，其结果在与指示讯号比较，因此多用于需要高精密度控制的用途中。

伺服电机的动作特性是进行**位置定位控制**和**动作速度控制**，其主要特点是转速可以精确控制，速度控制范围广，可以安定平顺等速运转之外，还可以根据需求随时变更速度。在极低速度也可以稳定转动。能迅速做出正转与逆转，也能迅速加减速。在由静态改为动态运作或由动态改为静态运作所需费时极短，而且即便有外力附加仍可以保持位置。并在额定容量范围内瞬间产生大转矩，输出功率大且效率也高。

伺服电机分为交流（AC）和直流（DC）两种，直流伺服电机机体较细长，因此转子惯性较小，而且具有线性反应佳与简单易于控制特性，因为直流伺服电机因为操作容易，也就是旋转方向由电流决定，并且旋转速度由改变施加的电压来控制，控制简单所以广泛使用因此现在直流伺服电机是使用最多的电机。

而交流（AC）伺服电机多使用在感应电机与交流无刷电机。为了让感应电机变化旋转速度，必须改变电源频率，因为这个目的而使用变频器（Inverter）。由此可知，因为伺服电机是以回馈讯号控制，可以与借由输入脉冲电流控制的步进电机有所区别。



### 3.2常见的电机控制算法

如下图所示，是一些常见的电机控制算法，可以大致分为Basic、Advanced和Senior三类。

![电机控制算法种类](C:\Users\Administrator\Downloads\电机控制算法种类.png)

#### 3.2.1基础算法

##### 3.2.1.1控制方式之FOC算法

磁场定向控制 (FOC) 也称为矢量控制，它是一种用于控制永磁同步电机 (PMSM) 和交流感应电机 (ACIM) 的方法。FOC 在整个转矩和转速范围内提供良好的控制能力。FOC 实现需要将定子电流从静止参考系变换为转子磁通参考系（也称为 d-q 参考系）。

转速控制和转矩控制是 FOC 最常用的控制模式。位置控制模式不太常见。大多数牵引应用使用转矩控制模式，其中电机控制系统遵循参考转矩值。在转速控制模式下，电机控制器遵循参考转速值，并为形成内部子系统的转矩控制生成转矩参考值。在位置控制模式下，转速控制器构成内部子系统。

FOC 算法的实现需要电流和转子位置的实时反馈。使用传感器测量电流和位置。您也可以使用无传感器方法，该方法使用估计的反馈值，而不是基于实际传感器的测量值。

FOC算法的控制架构，一般包括以下组件：

- 由两个比例积分控制器组成的电流控制器
- 外环使用可选的速度控制器和电流参考发生器
- 用于在静止坐标系和同步旋转坐标系之间转换的Clarke 变换、Park 变换和 Park 逆变换
- 空间矢量调制器算法，用于将 vα 和 vβ 命令转换为应用于定子绕组的脉宽调制信号
- 保护和辅助功能，包括启动和关闭逻辑
- 当需要无传感器控制时，可选观测器来估计转子角位置

永磁同步电机的FOC控制框图：

![pmsm_foc](C:\Users\Administrator\Downloads\pmsm_foc.png)

交流感应电机 (ACIM)的FOC控制框图：

![acim_foc](C:\Users\Administrator\Downloads\acim_foc.png)





##### 3.2.1.2控制方式之方波

方波控制，也称为梯形波控制、120°控制、六步换向控制。

方波控制运用霍尔传感器或者无感估算算法取得电机转子的位置，然后依据转子的位置在360°的电气周期内，进行6次换向（每60°换向一次）。每个换向方位电机输出特定方向的力，因而可以说方波控制的位置精度是电气60°。因为在这种方法控制下，电机的相电流波形接近方波，所以称为方波控制。

方波控制方法的长处是控制算法简单、硬件成本较低，运用功能普通的控制器便能取得较高的电机转速；缺陷是转矩脉动大、存在必定的电流噪声、功率达不到最大值。方波操控适用于对电机滚动功能要求不高的场合。

![方波控制的电流波形图](C:\Users\Administrator\Downloads\方波控制的电流波形图.png)



##### 3.2.1.3正弦波控制

正弦波控制方式使用的是SPWM波，输出的是3相正弦波电压，相应的电流也是正弦波电流。这种方式没有方波控制换向的概念，或者认为一个电气周期内进行了无限多次的换向。显然，正弦波控制相比方波控制，其转矩波动较小，电流谐波少，控制起来感觉比较“细腻”，但是对控制器的性能要求稍高于方波控制，而且电机效率不能发挥到最大值。

SPWM-Sinusoidal  Pulse  Witdh Modulation正弦脉宽调制 ，与PWM区别就是一个Sinusoidal ，这里不是想当然的加在控制对象上一个正弦信号波，而是仍然使用变种PWM控制来达到等同于正弦信号直接加载到控制对象上，而且设计生成一个控制对象的正弦波是很难的。

![SPWM正弦波控制](C:\Users\Administrator\Downloads\SPWM正弦波控制.png)

正弦波控制器的实现方式包括模拟控制和数字控制两种。模拟控制器一般使用操作放大器等模拟电路来实现电机控制，具有快速响应、实时性好等优点，但是精度受到器件的限制，控制精度较低。数字控制器则通过数字信号处理器（DSP）等处理器来实现电机的控制，具有高精度、可编程性强等优点，但是需要高性能的处理器和复杂的控制算法，成本较高。

正弦波控制器应用广泛，特别是在直流和交流变频器中，以供给交流电机使用。通过控制交流电压和频率，正弦波控制器可以实现电机的转速和转矩的精确调节，被广泛应用于工业自动化、机器人控制、电动车辆等领域。

##### 3.2.1.4电流采样

**注**：本章节主要参考《**三相逆变器电流采样方案总结**》：`https://github.com/g199209/BlogMarkdown/blob/master/%E4%B8%89%E7%9B%B8%E9%80%86%E5%8F%98%E5%99%A8%E7%94%B5%E6%B5%81%E9%87%87%E6%A0%B7%E6%96%B9%E6%A1%88%E6%80%BB%E7%BB%93.md`

当使用三相逆变器进行电机控制时，经常需要获取相电流以进行闭环控制，这就涉及到一个电流采样问题。尽管现在有许多电流检测方法，但低成本、大批量应用中常见的只有三种，其它都是昂贵的实验室系统、新兴技术或很少使用的方法。常用技术包括：采样电阻、霍尔元件与电流互感器。这些技术又可进一步细分，详见下图：

![电流采样方式分类](C:\Users\Administrator\Downloads\电流采样方式分类.png)

按照采样电阻放置位置不同，电阻采样方案可分为两大类——高端采样(High-Side Sensing)与低端采样(Low-Side Sensing)，其区别见下图：

![高端电流采样和低端电流采样](C:\Users\Administrator\Downloads\高端电流采样和低端电流采样.png)

**高端采样**

对于三相逆变器电路，采样电阻直接置于相电流桥臂上即可，如下图所示，根据基尔霍夫电流定律，只需要测量两相的电流即可，另一相电流可通过计算得到。

![高端电流采样示意图](C:\Users\Administrator\Downloads\高端电流采样示意图.png)

高端采样的优势在于：

1. 采样得到的电流值在任何时刻都等于相电流值，对于采样时刻无需特别考虑；
2. 因为使用类似差分输入的形式，可以很好的避免地平面噪声的干扰，检测精度会更高。

高端采样最大的缺陷在于其对后级处理电路的要求很高，后级运放要能承受很高的且急剧变化的共模电压，这样的运放选择起来并不是很容易。 不过目前不少半导体厂商均有专门针对高端电流检测的运放芯片，比如TI有专门的Current Sense Amplifiers系列运放，最大共模电压为80V；ADI的AD8479能承受600V的共模电压；IR的IR2277更是能承受高达1200V的共模电压，其共模抑制比CMRR也达到了100dB。

**低端采样**

一般来说，高端采样是一种较为昂贵的解决方案，考虑到成本问题，更为普遍使用的是低端采样方案。常用的低端采样方案根据使用电阻数量的不同可分为三种——三电阻采样、双电阻采样与单电阻采样，其电路结构见下面的组图：

![低端采样之三电阻采样示意图](C:\Users\Administrator\Downloads\低端采样之三电阻采样示意图.png)

![低端采样之两电阻采样示意图](C:\Users\Administrator\Downloads\低端采样之两电阻采样示意图.png)

![低端采样之单电阻采样示意图](C:\Users\Administrator\Downloads\低端采样之单电阻采样示意图.png)

其中，最为常用的是双电阻采样方案，在某些成本敏感的应用中，也会选用单电阻采样方案。

低端采样的优势在于：

1. 对运放没有特殊要求，选用常规通用运放即可；
2. 成本低廉，特别是单电阻采样方案，具有较大的价格优势。

其缺点在于：

1. 由于开关管的存在，流经采样电阻的电流并不随时等于相电流，对采样时刻有严格的要求；
2. 地平面噪声会影响采样的准确性。

采样时刻问题是使用低端采样时需要重点考虑的问题

从原理图中可以看到，当下桥臂的开关管断开的时候，采样电阻上显然是不会有电流流过的；只有当下桥臂开关管导通的时候，由于负载是感性负载，此时才会有续流电流从下桥臂流过，这个续流电流就等于相电流。 以SVPWM调试波形为例，

![下桥臂电流和相电流的关系示意图](C:\Users\Administrator\Downloads\下桥臂电流和相电流的关系示意图.png)

从上图中可以看到，相电流是基本连续的，然而下桥臂电流并不连续，当且仅当下桥臂导通时流过下桥臂采样电阻的电流才等于相电流。

所以对于双电阻及三电阻采样方案而言，只需要在SVPWM的零矢量（000）中央处进行采样即可获得正确的相电流。采样时刻示意图见下面这两幅图：

![下桥臂电流采样PWM波形图](C:\Users\Administrator\Downloads\下桥臂电流采样PWM波形图.png)

![下桥臂电流采样ADC示意图](C:\Users\Administrator\Downloads\下桥臂电流采样ADC示意图.png)

上面介绍的是双电阻采样，可以通过其中两相的电流，拟合出第三相电流；不过，双电阻采样的情况下，尽管可以通过电流平衡条件推算出第三相的电流，不过此方案有一个问题，在某些情况下（如SVPWM几个扇区的交界处），采样窗口时间会变得很短。而三电阻采样则不存在此问题，任何时刻都可丢弃采样窗口时间较短采样电阻的结果，用其他两相的电流值来推出此相的电流，其原理说明见下图：

![下桥臂三电阻采样原理示意图](C:\Users\Administrator\Downloads\下桥臂三电阻采样原理示意图.png)

单电阻采样方案中，是通过在一个PWM周期内进行两次AD采样实现相电流检测的，其采样时刻见下图所示：

![下桥臂单电阻采样原理示意图之一](C:\Users\Administrator\Downloads\下桥臂单电阻采样原理示意图之一.png)

![下桥臂单电阻采样原理示意图之二](C:\Users\Administrator\Downloads\下桥臂单电阻采样原理示意图之二.png)



![下桥臂单电阻采样原理示意图之三](C:\Users\Administrator\Downloads\下桥臂单电阻采样原理示意图之三.jpg)

上图中的T1与T2阶段就是采样时刻。而采样得到的电流值与相电流的对应关系见下表：

![下桥臂单电阻采样原理示意图之四](C:\Users\Administrator\Downloads\下桥臂单电阻采样原理示意图之四.png)

与双电阻采样方案一样，单电阻采样方案也存在一些不允许单分流三相重构的特殊情形。在SVPWM中，有些时候会输出两路占空比相等的PWM信号，如下图所示，此时T2=0，不能重构得到三相电流信息。除此之外，死区时间等因素也会影响采样窗口。

![下桥臂单电阻采样无法重构电流的情形](C:\Users\Administrator\Downloads\下桥臂单电阻采样无法重构电流的情形.png)

解决此问题有几种不同的方案，其中最常用的一种方法是：在相邻边界的时候插入固定时间的有效矢量，而在低调制区域的时候，采用轮流插入有效矢量的方法。插入有效矢量会给电流波形带来失真，这种情况下需要通过软件来进行补偿。



#### 3.2.2升级算法

##### 3.2.2.1弱磁控制算法（Field Weakening Control）

弱磁算法的原理，可以参考《2.13实验十三：HXS320F280049C_EDC_is13_fwc_mtpa》小节，这里对在具体调试过程中遇到点，做一些记录和介绍。

在调试海立压缩机的时候，遇到了弱磁深度不够的问题，beta角只能到100°。

```
beta角
未开弱磁&未开MTPA：  1.5707964    90°
开MTPA：           1.631377     93.47°
开弱磁：            1.7453293    100°
开弱磁&开MTPA：     1.7453293     100°
```

究其原因，是有多方面的，对于IPMSM 电机的弱磁控制，beta 角是电流矢量与 d 轴之间的夹角，它影响了电机的电流分配和弱磁效果。在实际应用中，beta 角通常不能超过 100°，这是由于以下几个原因：

1. 电流幅值限制
电机的电流幅值是有限的，这由逆变器和电机本身的额定电流决定。当 beta 角过大时，需要较大的电流来维持弱磁效果，但超出电流限制会导致系统过载。

2. 电压限制
在弱磁控制中，电机的端电压会随着转速的增加而增加。当 beta 角过大时，电机需要更高的电压来保持弱磁效果，但逆变器的输出电压是有限的，这限制了 beta 角的最大值。

3. 稳定性问题
超过一定范围的 beta 角会导致控制系统的不稳定。较大的 beta 角会导致电流矢量在 d-q 平面内的摆动幅度过大，从而引起电机的动态响应变差，影响系统稳定性。

4. 电磁特性
电机的电磁特性决定了 beta 角的有效范围。IPMSM 的磁路设计和电感参数会影响弱磁效果。当 beta 角过大时，电机的磁通和转矩特性会受到影响，导致弱磁控制效果下降。

5. 功率因数
在弱磁控制下，beta 角的增大会影响电机的功率因数。较大的 beta 角会导致功率因数下降，进而影响系统的效率和性能。

6. 机械应力
较大的 beta 角会导致电机在高转速下产生较大的机械应力，增加电机部件的磨损和疲劳，影响电机的寿命和可靠性。

具体的改进方向，有以下几个：

- 提高母线电压：提高逆变器的直流母线电压（DC bus voltage），可以增加电机的端电压，从而允许更大的弱磁角度。
- 最优电流矢量控制：采用先进的控制算法，如模型预测控制（Model Predictive Control, MPC）或最优电流矢量控制（Optimal Current Vector Control），根据电机的瞬时状态动态调整电流矢量，从而实现更深的弱磁控制。
- 改进电机设计：通过优化电机的设计参数，如转子和定子的磁路设计，减少漏磁和磁阻损耗，从而提高弱磁能力。
- 温度补偿控制：在控制算法中引入温度补偿，动态调整控制参数以适应温度变化，提高弱磁控制的稳定性和深度。



##### 3.2.2.2最佳电流转矩比MTPA

MTPA算法的原理，可以参考《2.13实验十三：HXS320F280049C_EDC_is13_fwc_mtpa》小节，这里对在具体调试过程中遇到点，做一些记录和介绍。



##### 3.2.2.3过调制（Over Modulation）



##### 3.2.2.4转矩补偿



##### 3.2.2.5恒转速、恒功率控制



##### 3.2.2.6恒转矩控制



##### 3.2.2.7超高速运行（>2KHz）



#### 3.2.3高阶算法





### 3.3常见的传感器









## 4.常见问题分析

### 4.1母线电压采样不准

母线电压采样不准，可以从不同的方面来排查。

首先确定ADC模块的参考源是否配置正确，其次排查ADC模块的每个通道是否可以正常采样；如果这些都没问题，那么就需要从比例关系的宏定义排查。

对于DSC280049C来说，12位的ADC模块，结果寄存器的表示范围是0-4095，母线电压经过分压电阻以后，对应到0-3.3v的输入范围，如果比例关系不对，也会导致换算后的母线电压不正确。



### 4.2电机启动时电流瞬间上升到峰值



### 4.3电机运行震荡明显



### 4.4主中断服务程序未正常执行

如果在调试过程中，发现DSC280049C_Launchboard上面的LED指示灯没有按周期（周期1s）闪烁，说明主中断服务程序（mainISR()函数）未正常执行，有几个地方可以排查。

- 程序是否进入Trap：如果程序中存在错误，则会跑飞，进入到Trap中，此时将无法正常执行中断服务程序。
- 查看PWM的周期和SOC信号是否配置正确
- 查看ADC的触发源是否配置正确，如果配置错误，PWM的中断将不会触发ADC采样
- 查看是否存在TZ故障；为了便于调试，实验中可将TZ相关的代码屏蔽掉，不触发TZ故障



