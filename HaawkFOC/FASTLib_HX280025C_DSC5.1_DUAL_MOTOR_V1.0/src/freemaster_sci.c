
#include <freemaster_sci.h>
#include "freemaster.h"
__interrupt void sciaTxIsr(void);
__interrupt void sciaRxIsr(void);

/******************************************************************
 *��������sciaTxIsr(void)
 *��   ���� ��
 *����ֵ����
 *��   �ã� SCIA�жϷ��ʹ���
 ******************************************************************/
__interrupt void sciaTxIsr(void)
{
	FMSTR_Isr();
	/*����жϱ�־λ*/
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;
}

/******************************************************************
 *��������sciaRxIsr(void)
 *��   ���� ��
 *����ֵ����
 *��   �ã� SCIA�жϽ��մ���
 ******************************************************************/
__interrupt void sciaRxIsr(void)
{
	FMSTR_Isr();
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;
}

/******************************************************************
 *��������Scia_Send(uint8 data)
 *��   ���� data��׼�����͵��ֽ�
 *����ֵ����
 *��   �ã� SCIA ����һ���ֽ�
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
 *��������Scia_Config(uint32 baud)
 *��   ���� baud�����ڲ�����
 *����ֵ����
 *��   �ã� SCIA ��ʼ������
 ******************************************************************/
/******************************************************************
 *��������Scia_Config(uint32 baud)
 *��   ���� baud�����ڲ�����
 *����ֵ����
 *��   �ã� SCIA ��ʼ������
 ******************************************************************/
void Scia_Config(uint32 baud)
{
	//uint32 div = 0;
	uint32 divsel = 0;
	uint32 lospcp = 0;
	uint32 lspclk = 0;
	uint16 brr = 0;

	//��ȡϵͳʱ�ӵı�Ƶ����Ƶ�͵����ⲿʱ�ӵ�ֵ
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

	/*��Ƶֵ����
	 divselΪ 0ʱ��ϵͳʱ��4��Ƶ
	 divselΪ 1ʱ��ϵͳʱ��4��Ƶ
	 divselΪ 2ʱ��ϵͳʱ��2��Ƶ
	 divselΪ 3ʱ��ϵͳʱ��1��Ƶ*/
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

	/*SCI ֹͣλ����    0��һ��ֹͣλ   1������ֹͣλ*/
	SciaRegs.SCICCR.bit.STOPBITS = 0;

	/*SCI ��żУ��λ    0����żУ��   1��żżУ��*/
	SciaRegs.SCICCR.bit.PARITY = 0;

	/*SCI ��żУ��ʹ��   0���ر�   1������*/
	SciaRegs.SCICCR.bit.PARITYENA = 0;

	/*SCI �ַ�����   0��1���ֳ�  1��2���ֳ� ... 7��8���ֳ�*/
	SciaRegs.SCICCR.bit.SCICHAR = 7;

	/*ʹ��SCI�ķ��ͻ��ͽ��ջ�*/
	SciaRegs.SCICTL1.bit.TXENA = 1;
	SciaRegs.SCICTL1.bit.RXENA = 1;

	/*SCI 16λ������ѡ��Ĵ��� ��8λ*/
	SciaRegs.SCIHBAUD.bit.BAUD = (uint8)((brr >> 8) & 0xff);
	/*SCI 16λ������ѡ��Ĵ��� ��8λ*/
	SciaRegs.SCILBAUD.bit.BAUD = (uint8)(brr & 0xff);

	/*SCI �����ж�ʹ��*/
//	SciaRegs.SCICTL2.bit.TXINTENA = 1;
	/*SCI �����ж�ʹ��*/
	SciaRegs.SCICTL2.bit.RXBKINTENA = 1;

	/*SCI ָ�����ͺͽ����жϴ��������üĴ�����EALLOW����*/
	EALLOW;
	PieVectTable.SCIA_RX_INT = &sciaRxIsr;
	PieVectTable.SCIA_TX_INT = &sciaTxIsr;
	EDIS;

	/*PIE Group 9, SCIRXINTA*/
	PieCtrlRegs.PIEIER9.bit.INTx1 = 1;
	/*PIE Group 9, SCITXINTA*/
	PieCtrlRegs.PIEIER9.bit.INTx2 = 1;
	IER |= M_INT9;

	/*SCI �����λ����������SCI*/
	SciaRegs.SCICTL1.bit.SWRESET = 1;

}


void InitSciGpio(){
    GPIO_SetupPinMux(28, GPIO_MUX_CPU1, 1);
    GPIO_SetupPinOptions(28, GPIO_INPUT, GPIO_PUSHPULL);
    GPIO_SetupPinMux(29, GPIO_MUX_CPU1, 1);
    GPIO_SetupPinOptions(29, GPIO_OUTPUT, GPIO_ASYNC);
}
