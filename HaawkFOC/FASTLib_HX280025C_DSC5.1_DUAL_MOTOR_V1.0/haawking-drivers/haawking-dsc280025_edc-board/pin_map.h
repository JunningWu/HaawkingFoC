//###########################################################################
//
// FILE:   pin_map.h
//
// TITLE:  Definitions of pin mux info for gpio.c.
//
//###########################################################################
// $HAAWKING Release: Hal Driver Support Library V1.0.0 $
// $Release Date: 2023-04-28 06:49:27 $
// $Copyright:
// Copyright (C) 2019-2023 Beijing Haawking Technology Co.,Ltd - http://www.haawking.com/
//###########################################################################


#ifndef __PIN_MAP_H__
#define __PIN_MAP_H__

//*****************************************************************************
// 0x00000003 = MUX register value
// 0x0000000C = GMUX register value
// 0x0000FF00 = Shift amount within mux registers
// 0xFFFF0000 = Offset of MUX register
//*****************************************************************************


#define GPIO_0_GPIO0                    0x000C0000U
#define GPIO_0_EPWM1_A                  0x000C0001U
#define GPIO_0_I2CA_SDA                 0x000C0006U
#define GPIO_0_SPIA_STE                 0x000C0007U
#define GPIO_0_FSIRXA_CLK               0x000C0009U
#define GPIO_0_CLB_OUTPUTXBAR8          0x000C000BU
#define GPIO_0_HIC_BASESEL1             0x000C000FU

#define GPIO_1_GPIO1                    0x000C0200U
#define GPIO_1_EPWM1_B                  0x000C0201U
#define GPIO_1_I2CA_SCL                 0x000C0206U
#define GPIO_1_SPIA_SOMI                0x000C0207U
#define GPIO_1_CLB_OUTPUTXBAR7          0x000C020BU
#define GPIO_1_HIC_A2                   0x000C020DU
#define GPIO_1_FSITXA_TDM_D1            0x000C020EU
#define GPIO_1_HIC_D10                  0x000C020FU

#define GPIO_2_GPIO2                    0x000C0400U
#define GPIO_2_EPWM2_A                  0x000C0401U
#define GPIO_2_OUTPUTXBAR1              0x000C0405U
#define GPIO_2_PMBUSA_SDA               0x000C0406U
#define GPIO_2_SPIA_SIMO                0x000C0407U
#define GPIO_2_SCIA_TX                  0x000C0409U
#define GPIO_2_FSIRXA_D1                0x000C040AU
#define GPIO_2_I2CB_SDA                 0x000C040BU
#define GPIO_2_HIC_A1                   0x000C040DU
#define GPIO_2_CANA_TX                  0x000C040EU
#define GPIO_2_HIC_D9                   0x000C040FU

#define GPIO_3_GPIO3                    0x000C0600U
#define GPIO_3_EPWM2_B                  0x000C0601U
#define GPIO_3_OUTPUTXBAR2              0x000C0602U
#define GPIO_3_PMBUSA_SCL               0x000C0606U
#define GPIO_3_SPIA_CLK                 0x000C0607U
#define GPIO_3_SCIA_RX                  0x000C0609U
#define GPIO_3_FSIRXA_D0                0x000C060AU
#define GPIO_3_I2CB_SCL                 0x000C060BU
#define GPIO_3_HIC_NOE                  0x000C060DU
#define GPIO_3_CANA_RX                  0x000C060EU
#define GPIO_3_HIC_D4                   0x000C060FU

#define GPIO_4_GPIO4                    0x000C0800U
#define GPIO_4_EPWM3_A                  0x000C0801U
#define GPIO_4_OUTPUTXBAR3              0x000C0805U
#define GPIO_4_CANA_TX                  0x000C0806U
#define GPIO_4_SPIB_CLK                 0x000C0807U
#define GPIO_4_EQEP2_STROBE             0x000C0809U
#define GPIO_4_FSIRXA_CLK               0x000C080AU
#define GPIO_4_CLB_OUTPUTXBAR6          0x000C080BU
#define GPIO_4_HIC_BASESEL2             0x000C080DU
#define GPIO_4_HIC_NWE                  0x000C080FU

#define GPIO_5_GPIO5                    0x000C0A00U
#define GPIO_5_EPWM3_B                  0x000C0A01U
#define GPIO_5_OUTPUTXBAR3              0x000C0A03U
#define GPIO_5_CANA_RX                  0x000C0A06U
#define GPIO_5_SPIA_STE                 0x000C0A07U
#define GPIO_5_FSITXA_D1                0x000C0A09U
#define GPIO_5_CLB_OUTPUTXBAR5          0x000C0A0AU
#define GPIO_5_HIC_A7                   0x000C0A0DU
#define GPIO_5_HIC_D4                   0x000C0A0EU
#define GPIO_5_HIC_D15                  0x000C0A0FU

#define GPIO_6_GPIO6                    0x000C0C00U
#define GPIO_6_EPWM4_A                  0x000C0C01U
#define GPIO_6_OUTPUTXBAR4              0x000C0C02U
#define GPIO_6_SYNCOUT                  0x000C0C03U
#define GPIO_6_EQEP1_A                  0x000C0C05U
#define GPIO_6_SPIB_SOMI                0x000C0C07U
#define GPIO_6_FSITXA_D0                0x000C0C09U
#define GPIO_6_FSITXA_D1                0x000C0C0BU
#define GPIO_6_HIC_NBE1                 0x000C0C0DU
#define GPIO_6_CLB_OUTPUTXBAR8          0x000C0C0EU
#define GPIO_6_HIC_D14                  0x000C0C0FU

#define GPIO_7_GPIO7                    0x000C0E00U
#define GPIO_7_EPWM4_B                  0x000C0E01U
#define GPIO_7_OUTPUTXBAR5              0x000C0E03U
#define GPIO_7_EQEP1_B                  0x000C0E05U
#define GPIO_7_SPIB_SIMO                0x000C0E07U
#define GPIO_7_FSITXA_CLK               0x000C0E09U
#define GPIO_7_CLB_OUTPUTXBAR2          0x000C0E0AU
#define GPIO_7_HIC_A6                   0x000C0E0DU
#define GPIO_7_HIC_D14                  0x000C0E0FU

#define GPIO_8_GPIO8                    0x000C1000U
#define GPIO_8_EPWM5_A                  0x000C1001U
#define GPIO_8_ADCSOCAO                 0x000C1003U
#define GPIO_8_EQEP1_STROBE             0x000C1005U
#define GPIO_8_SCIA_TX                  0x000C1006U
#define GPIO_8_SPIA_SIMO                0x000C1007U
#define GPIO_8_I2CA_SCL                 0x000C1009U
#define GPIO_8_FSITXA_D1                0x000C100AU
#define GPIO_8_CLB_OUTPUTXBAR5          0x000C100BU
#define GPIO_8_HIC_A0                   0x000C100DU
#define GPIO_8_FSITXA_TDM_CLK           0x000C100EU
#define GPIO_8_HIC_D8                   0x000C100FU

#define GPIO_9_GPIO9                    0x000C1200U
#define GPIO_9_EPWM5_B                  0x000C1201U
#define GPIO_9_OUTPUTXBAR6              0x000C1203U
#define GPIO_9_EQEP1_INDEX              0x000C1205U
#define GPIO_9_SCIA_RX                  0x000C1206U
#define GPIO_9_SPIA_CLK                 0x000C1207U
#define GPIO_9_FSITXA_D0                0x000C120AU
#define GPIO_9_LINB_RX                  0x000C120BU
#define GPIO_9_HIC_BASESEL0             0x000C120DU
#define GPIO_9_I2CB_SCL                 0x000C120EU
#define GPIO_9_HIC_NRDY                 0x000C120FU

#define GPIO_10_GPIO10                  0x000C1400U
#define GPIO_10_EPWM6_A                 0x000C1401U
#define GPIO_10_ADCSOCBO                0x000C1403U
#define GPIO_10_EQEP1_A                 0x000C1405U
#define GPIO_10_SPIA_SOMI               0x000C1407U
#define GPIO_10_I2CA_SDA                0x000C1409U
#define GPIO_10_FSITXA_CLK              0x000C140AU
#define GPIO_10_LINB_TX                 0x000C140BU
#define GPIO_10_HIC_NWE                 0x000C140DU
#define GPIO_10_FSITXA_TDM_D0           0x000C140EU

#define GPIO_11_GPIO11                  0x000C1600U
#define GPIO_11_EPWM6_B                 0x000C1601U
#define GPIO_11_OUTPUTXBAR7             0x000C1603U
#define GPIO_11_EQEP1_B                 0x000C1605U
#define GPIO_11_SPIA_STE                0x000C1607U
#define GPIO_11_FSIRXA_D1               0x000C1609U
#define GPIO_11_LINB_RX                 0x000C160AU
#define GPIO_11_EQEP2_A                 0x000C160BU
#define GPIO_11_SPIA_SIMO               0x000C160DU
#define GPIO_11_HIC_D6                  0x000C160EU
#define GPIO_11_HIC_NBE0                0x000C160FU

#define GPIO_12_GPIO12                  0x000C1800U
#define GPIO_12_EPWM7_A                 0x000C1801U
#define GPIO_12_EQEP1_STROBE            0x000C1805U
#define GPIO_12_PMBUSA_CTL              0x000C1807U
#define GPIO_12_FSIRXA_D0               0x000C1809U
#define GPIO_12_LINB_TX                 0x000C180AU
#define GPIO_12_SPIA_CLK                0x000C180BU
#define GPIO_12_CANA_RX                 0x000C180DU
#define GPIO_12_HIC_D13                 0x000C180EU
#define GPIO_12_HIC_INT                 0x000C180FU

#define GPIO_13_GPIO13                  0x000C1A00U
#define GPIO_13_EPWM7_B                 0x000C1A01U
#define GPIO_13_EQEP1_INDEX             0x000C1A05U
#define GPIO_13_PMBUSA_ALERT            0x000C1A07U
#define GPIO_13_FSIRXA_CLK              0x000C1A09U
#define GPIO_13_LINB_RX                 0x000C1A0AU
#define GPIO_13_SPIA_SOMI               0x000C1A0BU
#define GPIO_13_CANA_TX                 0x000C1A0DU
#define GPIO_13_HIC_D11                 0x000C1A0EU
#define GPIO_13_HIC_D5                  0x000C1A0FU

#define GPIO_14_GPIO14                  0x000C1C00U
#define GPIO_14_EPWM8_A                 0x000C1C01U
#define GPIO_14_I2CB_SDA                0x000C1C05U
#define GPIO_14_OUTPUTXBAR3             0x000C1C06U
#define GPIO_14_PMBUSA_SDA              0x000C1C07U
#define GPIO_14_SPIB_CLK                0x000C1C09U
#define GPIO_14_EQEP2_A                 0x000C1C0AU
#define GPIO_14_LINB_TX                 0x000C1C0BU
#define GPIO_14_EPWM3_A                 0x000C1C0DU
#define GPIO_14_CLB_OUTPUTXBAR7         0x000C1C0EU
#define GPIO_14_HIC_D15                 0x000C1C0FU

#define GPIO_15_GPIO15                  0x000C1E00U
#define GPIO_15_EPWM8_B                 0x000C1E01U
#define GPIO_15_I2CB_SCL                0x000C1E05U
#define GPIO_15_OUTPUTXBAR4             0x000C1E06U
#define GPIO_15_PMBUSA_SCL              0x000C1E07U
#define GPIO_15_SPIB_STE                0x000C1E09U
#define GPIO_15_EQEP2_B                 0x000C1E0AU
#define GPIO_15_LINB_RX                 0x000C1E0BU
#define GPIO_15_EPWM3_B                 0x000C1E0DU
#define GPIO_15_CLB_OUTPUTXBAR6         0x000C1E0EU
#define GPIO_15_HIC_D12                 0x000C1E0FU

#define GPIO_16_GPIO16                  0x00100000U
#define GPIO_16_SPIA_SIMO               0x00100001U
#define GPIO_16_OUTPUTXBAR7             0x00100003U
#define GPIO_16_EPWM5_A                 0x00100005U
#define GPIO_16_SCIA_TX                 0x00100006U
#define GPIO_16_EQEP1_STROBE            0x00100009U
#define GPIO_16_PMBUSA_SCL              0x0010000AU
#define GPIO_16_XCLKOUT                 0x0010000BU
#define GPIO_16_EQEP2_B                 0x0010000DU
#define GPIO_16_SPIB_SOMI               0x0010000EU
#define GPIO_16_HIC_D1                  0x0010000FU

#define GPIO_17_GPIO17                  0x00100200U
#define GPIO_17_SPIA_SOMI               0x00100201U
#define GPIO_17_OUTPUTXBAR8             0x00100203U
#define GPIO_17_EPWM5_B                 0x00100205U
#define GPIO_17_SCIA_RX                 0x00100206U
#define GPIO_17_EQEP1_INDEX             0x00100209U
#define GPIO_17_PMBUSA_SDA              0x0010020AU
#define GPIO_17_CANA_TX                 0x0010020BU
#define GPIO_17_HIC_D2                  0x0010020FU

#define GPIO_18_GPIO18_X2               0x00100400U
#define GPIO_18_SPIA_CLK                0x00100401U
#define GPIO_18_CANA_RX                 0x00100403U
#define GPIO_18_EPWM6_A                 0x00100405U
#define GPIO_18_I2CA_SCL                0x00100406U
#define GPIO_18_EQEP2_A                 0x00100409U
#define GPIO_18_PMBUSA_CTL              0x0010040AU
#define GPIO_18_XCLKOUT                 0x0010040BU
#define GPIO_18_LINB_TX                 0x0010040DU
#define GPIO_18_FSITXA_TDM_CLK          0x0010040EU
#define GPIO_18_HIC_INT                 0x0010040FU

#define GPIO_19_GPIO19_X1               0x00100600U
#define GPIO_19_SPIA_STE                0x00100601U
#define GPIO_19_CANA_TX                 0x00100603U
#define GPIO_19_EPWM6_B                 0x00100605U
#define GPIO_19_I2CA_SDA                0x00100606U
#define GPIO_19_EQEP2_B                 0x00100609U
#define GPIO_19_PMBUSA_ALERT            0x0010060AU
#define GPIO_19_CLB_OUTPUTXBAR1         0x0010060BU
#define GPIO_19_LINB_RX                 0x0010060DU
#define GPIO_19_FSITXA_TDM_D0           0x0010060EU
#define GPIO_19_HIC_NBE0                0x0010060FU

#define GPIO_22_GPIO22                  0x00100C00U
#define GPIO_22_EQEP1_STROBE            0x00100C01U
#define GPIO_22_SPIB_CLK                0x00100C06U
#define GPIO_22_LINA_TX                 0x00100C09U
#define GPIO_22_CLB_OUTPUTXBAR1         0x00100C0AU
#define GPIO_22_LINB_TX                 0x00100C0BU
#define GPIO_22_HIC_A5                  0x00100C0DU
#define GPIO_22_EPWM4_A                 0x00100C0EU
#define GPIO_22_HIC_D13                 0x00100C0FU

#define GPIO_23_GPIO23                  0x00100E00U
#define GPIO_23_EQEP1_INDEX             0x00100E01U
#define GPIO_23_SPIB_STE                0x00100E06U
#define GPIO_23_LINA_RX                 0x00100E09U
#define GPIO_23_LINB_RX                 0x00100E0BU
#define GPIO_23_HIC_A3                  0x00100E0DU
#define GPIO_23_EPWM4_B                 0x00100E0EU
#define GPIO_23_HIC_D11                 0x00100E0FU

#define GPIO_24_GPIO24                  0x00101000U
#define GPIO_24_OUTPUTXBAR1             0x00101001U
#define GPIO_24_EQEP2_A                 0x00101002U
#define GPIO_24_SPIB_SIMO               0x00101006U
#define GPIO_24_LINB_TX                 0x00101009U
#define GPIO_24_PMBUSA_SCL              0x0010100AU
#define GPIO_24_SCIA_TX                 0x0010100BU
#define GPIO_24_ERRORSTS                0x0010100DU
#define GPIO_24_HIC_D3                  0x0010100FU

#define GPIO_25_GPIO25                  0x00101200U
#define GPIO_25_OUTPUTXBAR2             0x00101201U
#define GPIO_25_EQEP2_B                 0x00101202U
#define GPIO_25_EQEP1_A                 0x00101205U
#define GPIO_25_SPIB_SOMI               0x00101206U
#define GPIO_25_FSITXA_D1               0x00101209U
#define GPIO_25_PMBUSA_SDA              0x0010120AU
#define GPIO_25_SCIA_RX                 0x0010120BU
#define GPIO_25_HIC_BASESEL0            0x0010120EU

#define GPIO_26_GPIO26                  0x00101400U
#define GPIO_26_OUTPUTXBAR3             0x00101401U
#define GPIO_26_EQEP2_INDEX             0x00101402U
#define GPIO_26_SPIB_CLK                0x00101406U
#define GPIO_26_FSITXA_D0               0x00101409U
#define GPIO_26_PMBUSA_CTL              0x0010140AU
#define GPIO_26_I2CA_SDA                0x0010140BU
#define GPIO_26_HIC_D0                  0x0010140EU
#define GPIO_26_HIC_A1                  0x0010140FU

#define GPIO_27_GPIO27                  0x00101600U
#define GPIO_27_OUTPUTXBAR4             0x00101601U
#define GPIO_27_EQEP2_STROBE            0x00101602U
#define GPIO_27_SPIB_STE                0x00101606U
#define GPIO_27_FSITXA_CLK              0x00101609U
#define GPIO_27_PMBUSA_ALERT            0x0010160AU
#define GPIO_27_I2CA_SCL                0x0010160BU
#define GPIO_27_HIC_D1                  0x0010160EU
#define GPIO_27_HIC_A4                  0x0010160FU

#define GPIO_28_GPIO28                  0x00101800U
#define GPIO_28_SCIA_RX                 0x00101801U
#define GPIO_28_EPWM7_A                 0x00101803U
#define GPIO_28_OUTPUTXBAR5             0x00101805U
#define GPIO_28_EQEP1_A                 0x00101806U
#define GPIO_28_EQEP2_STROBE            0x00101809U
#define GPIO_28_LINA_TX                 0x0010180AU
#define GPIO_28_SPIB_CLK                0x0010180BU
#define GPIO_28_ERRORSTS                0x0010180DU
#define GPIO_28_I2CB_SDA                0x0010180EU
#define GPIO_28_HIC_NOE                 0x0010180FU

#define GPIO_29_GPIO29                  0x00101A00U
#define GPIO_29_SCIA_TX                 0x00101A01U
#define GPIO_29_EPWM7_B                 0x00101A03U
#define GPIO_29_OUTPUTXBAR6             0x00101A05U
#define GPIO_29_EQEP1_B                 0x00101A06U
#define GPIO_29_EQEP2_INDEX             0x00101A09U
#define GPIO_29_LINA_RX                 0x00101A0AU
#define GPIO_29_SPIB_STE                0x00101A0BU
#define GPIO_29_ERRORSTS                0x00101A0DU
#define GPIO_29_I2CB_SCL                0x00101A0EU
#define GPIO_29_HIC_NCS                 0x00101A0FU

#define GPIO_30_GPIO30                  0x00101C00U
#define GPIO_30_CANA_RX                 0x00101C01U
#define GPIO_30_SPIB_SIMO               0x00101C03U
#define GPIO_30_OUTPUTXBAR7             0x00101C05U
#define GPIO_30_EQEP1_STROBE            0x00101C06U
#define GPIO_30_FSIRXA_CLK              0x00101C09U
#define GPIO_30_EPWM1_A                 0x00101C0BU
#define GPIO_30_HIC_D8                  0x00101C0EU

#define GPIO_31_GPIO31                  0x00101E00U
#define GPIO_31_CANA_TX                 0x00101E01U
#define GPIO_31_SPIB_SOMI               0x00101E03U
#define GPIO_31_OUTPUTXBAR8             0x00101E05U
#define GPIO_31_EQEP1_INDEX             0x00101E06U
#define GPIO_31_FSIRXA_D1               0x00101E09U
#define GPIO_31_EPWM1_B                 0x00101E0BU
#define GPIO_31_HIC_D10                 0x00101E0EU

#define GPIO_32_GPIO32                  0x008C0000U
#define GPIO_32_I2CA_SDA                0x008C0001U
#define GPIO_32_SPIB_CLK                0x008C0003U
#define GPIO_32_LINA_TX                 0x008C0006U
#define GPIO_32_FSIRXA_D0               0x008C0009U
#define GPIO_32_CANA_TX                 0x008C000AU
#define GPIO_32_ADCSOCBO                0x008C000DU
#define GPIO_32_HIC_INT                 0x008C000FU

#define GPIO_33_GPIO33                  0x008C0200U
#define GPIO_33_I2CA_SCL                0x008C0201U
#define GPIO_33_SPIB_STE                0x008C0203U
#define GPIO_33_OUTPUTXBAR4             0x008C0205U
#define GPIO_33_LINA_RX                 0x008C0206U
#define GPIO_33_FSIRXA_CLK              0x008C0209U
#define GPIO_33_CANA_RX                 0x008C020AU
#define GPIO_33_EQEP2_B                 0x008C020BU
#define GPIO_33_ADCSOCAO                0x008C020DU
#define GPIO_33_HIC_D0                  0x008C020FU

#define GPIO_34_GPIO34                  0x008C0400U
#define GPIO_34_OUTPUTXBAR1             0x008C0401U
#define GPIO_34_PMBUSA_SDA              0x008C0406U
#define GPIO_34_HIC_NBE1                0x008C040DU
#define GPIO_34_I2CB_SDA                0x008C040EU
#define GPIO_34_HIC_D9                  0x008C040FU

#define GPIO_35_GPIO35                  0x008C0600U
#define GPIO_35_SCIA_RX                 0x008C0601U
#define GPIO_35_I2CA_SDA                0x008C0603U
#define GPIO_35_CANA_RX                 0x008C0605U
#define GPIO_35_PMBUSA_SCL              0x008C0606U
#define GPIO_35_LINA_RX                 0x008C0607U
#define GPIO_35_EQEP1_A                 0x008C0609U
#define GPIO_35_PMBUSA_CTL              0x008C060AU
#define GPIO_35_HIC_NWE                 0x008C060EU
#define GPIO_35_TDI                     0x008C060FU

#define GPIO_37_GPIO37                  0x008C0A00U
#define GPIO_37_OUTPUTXBAR2             0x008C0A01U
#define GPIO_37_I2CA_SCL                0x008C0A03U
#define GPIO_37_SCIA_TX                 0x008C0A05U
#define GPIO_37_CANA_TX                 0x008C0A06U
#define GPIO_37_LINA_TX                 0x008C0A07U
#define GPIO_37_EQEP1_B                 0x008C0A09U
#define GPIO_37_PMBUSA_ALERT            0x008C0A0AU
#define GPIO_37_HIC_NRDY                0x008C0A0EU
#define GPIO_37_TDO                     0x008C0A0FU

#define GPIO_39_GPIO39                  0x008C0E00U
#define GPIO_39_FSIRXA_CLK              0x008C0E07U
#define GPIO_39_EQEP2_INDEX             0x008C0E09U
#define GPIO_39_CLB_OUTPUTXBAR2         0x008C0E0BU
#define GPIO_39_SYNCOUT                 0x008C0E0DU
#define GPIO_39_EQEP1_INDEX             0x008C0E0EU
#define GPIO_39_HIC_D7                  0x008C0E0FU

#define GPIO_40_GPIO40                  0x008C1000U
#define GPIO_40_SPIB_SIMO               0x008C1001U
#define GPIO_40_EPWM2_B                 0x008C1005U
#define GPIO_40_PMBUSA_SDA              0x008C1006U
#define GPIO_40_FSIRXA_D0               0x008C1007U
#define GPIO_40_EQEP1_A                 0x008C100AU
#define GPIO_40_LINB_TX                 0x008C100BU
#define GPIO_40_HIC_NBE1                0x008C100EU
#define GPIO_40_HIC_D5                  0x008C100FU

#define GPIO_41_GPIO41                  0x008C1200U
#define GPIO_41_EPWM2_A                 0x008C1205U
#define GPIO_41_PMBUSA_SCL              0x008C1206U
#define GPIO_41_FSIRXA_D1               0x008C1207U
#define GPIO_41_EQEP1_B                 0x008C120AU
#define GPIO_41_LINB_RX                 0x008C120BU
#define GPIO_41_HIC_A4                  0x008C120DU
#define GPIO_41_SPIB_SOMI               0x008C120EU
#define GPIO_41_HIC_D12                 0x008C120FU

#define GPIO_42_GPIO42                  0x008C1400U
#define GPIO_42_LINA_RX                 0x008C1402U
#define GPIO_42_OUTPUTXBAR5             0x008C1403U
#define GPIO_42_PMBUSA_CTL              0x008C1405U
#define GPIO_42_I2CA_SDA                0x008C1406U
#define GPIO_42_EQEP1_STROBE            0x008C140AU
#define GPIO_42_CLB_OUTPUTXBAR3         0x008C140BU
#define GPIO_42_HIC_D2                  0x008C140EU
#define GPIO_42_HIC_A6                  0x008C140FU

#define GPIO_43_GPIO43                  0x008C1600U
#define GPIO_43_OUTPUTXBAR6             0x008C1603U
#define GPIO_43_PMBUSA_ALERT            0x008C1605U
#define GPIO_43_I2CA_SCL                0x008C1606U
#define GPIO_43_EQEP1_INDEX             0x008C160AU
#define GPIO_43_CLB_OUTPUTXBAR4         0x008C160BU
#define GPIO_43_HIC_D3                  0x008C160EU
#define GPIO_43_HIC_A7                  0x008C160FU

#define GPIO_44_GPIO44                  0x008C1800U
#define GPIO_44_OUTPUTXBAR7             0x008C1803U
#define GPIO_44_EQEP1_A                 0x008C1805U
#define GPIO_44_FSITXA_CLK              0x008C1807U
#define GPIO_44_CLB_OUTPUTXBAR3         0x008C180AU
#define GPIO_44_HIC_D7                  0x008C180DU
#define GPIO_44_HIC_D5                  0x008C180FU

#define GPIO_45_GPIO45                  0x008C1A00U
#define GPIO_45_OUTPUTXBAR8             0x008C1A03U
#define GPIO_45_FSITXA_D0               0x008C1A07U
#define GPIO_45_CLB_OUTPUTXBAR4         0x008C1A0AU
#define GPIO_45_HIC_D6                  0x008C1A0FU

#define GPIO_46_GPIO46                  0x008C1C00U
#define GPIO_46_LINA_TX                 0x008C1C03U
#define GPIO_46_FSITXA_D1               0x008C1C07U
#define GPIO_46_HIC_NWE                 0x008C1C0FU

#define GPIO_61_GPIO61                  0x00901A00U

#define GPIO_62_GPIO62                  0x00901C00U

#define GPIO_63_GPIO63                  0x00901E00U

#define GPIO_224_GPIO224                0x038C0000U
#define GPIO_224_HIC_A3                 0x038C000FU

#define GPIO_225_GPIO225                0x038C0200U
#define GPIO_225_HIC_NWE                0x038C020FU

#define GPIO_226_GPIO226                0x038C0400U
#define GPIO_226_HIC_A1                 0x038C040FU

#define GPIO_227_GPIO227                0x038C0600U
#define GPIO_227_HIC_NBE0               0x038C060FU

#define GPIO_228_GPIO228                0x038C0800U
#define GPIO_228_HIC_A0                 0x038C080FU

#define GPIO_230_GPIO230                0x038C0C00U
#define GPIO_230_HIC_BASESEL2           0x038C0C0FU

#define GPIO_231_GPIO231                0x038C0E00U
#define GPIO_231_HIC_BASESEL1           0x038C0E0FU

#define GPIO_232_GPIO232                0x038C1000U
#define GPIO_232_HIC_BASESEL0           0x038C100FU

#define GPIO_233_GPIO233                0x038C1200U
#define GPIO_233_HIC_A4                 0x038C120FU

#define GPIO_237_GPIO237                0x038C1A00U
#define GPIO_237_HIC_A6                 0x038C1A0FU

#define GPIO_238_GPIO238                0x038C1C00U
#define GPIO_238_HIC_NCS                0x038C1C0FU

#define GPIO_239_GPIO239                0x038C1E00U
#define GPIO_239_HIC_A5                 0x038C1E0FU

#define GPIO_241_GPIO241                0x03900200U
#define GPIO_241_HIC_NBE1               0x0390020FU

#define GPIO_242_GPIO242                0x03900400U
#define GPIO_242_HIC_A2                 0x0390040FU

#define GPIO_244_GPIO244                0x03900800U
#define GPIO_244_HIC_A7                 0x0390080FU

#define GPIO_245_GPIO245                0x03900A00U
#define GPIO_245_HIC_NOE                0x03900A0FU

#endif // PIN_MAP_H
