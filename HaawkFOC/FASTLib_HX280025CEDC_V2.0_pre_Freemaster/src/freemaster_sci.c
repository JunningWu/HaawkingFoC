
#include <freemaster_sci.h>
#include "freemaster.h"
__interrupt void sciaTxIsr(void);
__interrupt void sciaRxIsr(void);

/******************************************************************
 *函数名：sciaTxIsr(void)
 *参   数： 无
 *返回值：无
 *作   用： SCIA中断发送处理
 ******************************************************************/
__interrupt void sciaTxIsr(void)
{
	FMSTR_Isr();
	/*清除中断标志位*/
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;
}

/******************************************************************
 *函数名：sciaRxIsr(void)
 *参   数： 无
 *返回值：无
 *作   用： SCIA中断接收处理
 ******************************************************************/
__interrupt void sciaRxIsr(void)
{
	FMSTR_Isr();
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;
}

/******************************************************************
 *函数名：Scia_Send(uint8 data)
 *参   数： data，准备发送的字节
 *返回值：无
 *作   用： SCIA 发送一个字节
 ******************************************************************/
void Scia_Send(uint8 data)
{
	while(SciaRegs.SCICTL2.bit.TXRDY == 0)
	{
	}

	SciaRegs.SCITXBUF.all = data;

	while(SciaRegs.SCICTL2.bit.TXRDY == 0)
	{
	}
}


/******************************************************************
 *函数名：Scia_Config(uint32 baud)
 *参   数： baud，串口波特率
 *返回值：无
 *作   用： SCIA 初始化配置
 ******************************************************************/
/******************************************************************
 *函数名：Scia_Config(uint32 baud)
 *参   数： baud，串口波特率
 *返回值：无
 *作   用： SCIA 初始化配置
 ******************************************************************/
void Scia_Config(uint32 baud)
{
	//uint32 div = 0;
	uint32 divsel = 0;
	uint32 lospcp = 0;
	uint32 lspclk = 0;
	uint16 brr = 0;

	//获取系统时钟的倍频、分频和低速外部时钟的值
	//div = SysCtrlRegs.PLLCR.bit.DIVF;
	divsel = ClkCfgRegs.SYSCLKDIVSEL.bit.PLLSYSCLKDIV;
	lospcp = ClkCfgRegs.LOSPCP.bit.LSPCLKDIV;

	if(lospcp != 0)
	{
		lospcp = lospcp * 2;
	}
	else
	{
		lospcp = 1;
	}

	/*分频值设置
	 divsel为 0时，系统时钟4分频
	 divsel为 1时，系统时钟4分频
	 divsel为 2时，系统时钟2分频
	 divsel为 3时，系统时钟1分频*/
	switch(divsel)
	{
	case 0:
	case 1:
		lspclk = 160000000 / lospcp;
		break;
	case 2:
		lspclk = 160000000 / lospcp;
		break;
	case 3:
		lspclk = 160000000 / lospcp;
		break;
	}

	brr = lspclk / (baud * 8) - 1;

	/*SCI 停止位设置    0：一个停止位   1：两个停止位*/
	SciaRegs.SCICCR.bit.STOPBITS = 0;

	/*SCI 奇偶校验位    0：奇偶校验   1：偶偶校验*/
	SciaRegs.SCICCR.bit.PARITY = 0;

	/*SCI 奇偶校验使能   0：关闭   1：启用*/
	SciaRegs.SCICCR.bit.PARITYENA = 0;

	/*SCI 字符长度   0：1个字长  1：2个字长 ... 7：8个字长*/
	SciaRegs.SCICCR.bit.SCICHAR = 7;

	/*使能SCI的发送机和接收机*/
	SciaRegs.SCICTL1.bit.TXENA = 1;
	SciaRegs.SCICTL1.bit.RXENA = 1;

	/*SCI 16位波特率选择寄存器 高8位*/
	SciaRegs.SCIHBAUD.bit.BAUD = (uint8)((brr >> 8) & 0xff);
	/*SCI 16位波特率选择寄存器 低8位*/
	SciaRegs.SCILBAUD.bit.BAUD = (uint8)(brr & 0xff);

	/*SCI 发送中断使能*/
//	SciaRegs.SCICTL2.bit.TXINTENA = 1;
	/*SCI 接收中断使能*/
	SciaRegs.SCICTL2.bit.RXBKINTENA = 1;

	/*SCI 指定发送和接收中断处理函数，该寄存器受EALLOW保护*/
	EALLOW;
	PieVectTable.SCIA_RX_INT = &sciaRxIsr;
	PieVectTable.SCIA_TX_INT = &sciaTxIsr;
	EDIS;

	/*PIE Group 9, SCIRXINTA*/
	PieCtrlRegs.PIEIER9.bit.INTx1 = 1;
	/*PIE Group 9, SCITXINTA*/
	PieCtrlRegs.PIEIER9.bit.INTx2 = 1;
	IER |= M_INT9;

	/*SCI 软件复位，重新启动SCI*/
	SciaRegs.SCICTL1.bit.SWRESET = 1;

}


void InitSciGpio(){
    GPIO_SetupPinMux(28, GPIO_MUX_CPU1, 1);
    GPIO_SetupPinOptions(28, GPIO_INPUT, GPIO_PUSHPULL);
    GPIO_SetupPinMux(29, GPIO_MUX_CPU1, 1);
    GPIO_SetupPinOptions(29, GPIO_OUTPUT, GPIO_ASYNC);
}
