#include "timer.h"
#include "led.h"
#include "keyboard.h"
#include "timer_interrupts.h"
#include "servo.h"
#include "string.h"
#include "command_decoder.h"

#include <LPC210X.H>

#define UART_RXD_PIN0_1		(1<<2)

#define mDIVISOR_LATCH_ACCES_BIT                   (1<<7)
#define m8BIT_UART_WORD_LENGTH                     0x00000003

#define mRX_DATA_AVALIABLE_INTERRUPT_ENABLE        (1<<0)
#define mTHRE_INTERRUPT_ENABLE                     (1<<1)

#define mINTERRUPT_PENDING_IDETIFICATION_BITFIELD  0x0000000F
#define mTHRE_INTERRUPT_PENDING                    (1<<1)
#define mRX_DATA_AVALIABLE_INTERRUPT_PENDING       (1<<2)

#define VIC_UART0_CHANNEL_NR  6

#define mIRQ_SLOT_ENABLE                           (1<<5)



char cReceivedString[RECIEVER_SIZE];

__irq void UART0_Interrupt (void) {
   
   unsigned int uiCopyOfU0IIR=U0IIR;

   if      ((uiCopyOfU0IIR & mINTERRUPT_PENDING_IDETIFICATION_BITFIELD) == mRX_DATA_AVALIABLE_INTERRUPT_PENDING)
   {
      Reciever_PutCharacterToBuffer(U0RBR);
   } 
   
   if ((uiCopyOfU0IIR & mINTERRUPT_PENDING_IDETIFICATION_BITFIELD) == mTHRE_INTERRUPT_PENDING) 
   {

   }

   VICVectAddr = 0;
}

void UART_InitWithInt(unsigned int uiBaudRate){

   PINSEL0 = PINSEL0 | UART_RXD_PIN0_1;                                     // ustawic pina na odbiornik uart0
   U0LCR  |= (m8BIT_UART_WORD_LENGTH | mDIVISOR_LATCH_ACCES_BIT); // dlugosc slowa, DLAB = 1
   U0DLL   = (((15000000)/16)/uiBaudRate);                      // predkosc transmisji
   U0LCR  &= (~mDIVISOR_LATCH_ACCES_BIT);                       // DLAB = 0
   U0IER  |= mRX_DATA_AVALIABLE_INTERRUPT_ENABLE;               // ??? co tu robinmy

   VICVectAddr1  = (unsigned long) UART0_Interrupt;             // set interrupt service routine address
   VICVectCntl1  = mIRQ_SLOT_ENABLE | VIC_UART0_CHANNEL_NR;     // use it for UART 0 Interrupt
   VICIntEnable |= (0x1 << VIC_UART0_CHANNEL_NR);               // Enable UART 0 Interrupt Channel
}	   

int main (){
	unsigned int uiPos;
	UART_InitWithInt(9600);
	ServoInit(50);
	Reciever_Empty();
	
	while(1){
		if(eReciever_GetStatus() == READY)
		{
			Reciever_GetStringCopy(cReceivedString);
			switch(eDecodeCommand(cReceivedString, &uiPos))
			{
			case cCALLIB:
				ServoCallib();
				break;
			
			case cGOTO:
				ServoGoTo(uiPos);
				break;
			
			case cERROR:
				break;
			}
			Reciever_Empty();
		}
		else if(eReciever_GetStatus() == OVERFLOW)
		{
			Reciever_Empty();
		}
}
}
