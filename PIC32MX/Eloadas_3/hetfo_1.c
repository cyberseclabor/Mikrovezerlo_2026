#include <xc.h>

// SYSCLK = 1MHz, PBCLK = 250KHz
//#pragma config FNOSC = FRCDIV, FSOSCEN = OFF, POSCMOD = OFF
//#pragma config FRCDIV = 8

#pragma config FNOSC = FRCPLL, FSOSCEN = OFF, POSCMOD = OFF
#pragma config FPLLMUL = MUL_20, FPLLIDIV = DIV_10, FPLLODIV = DIV_16
// PBCLK
#pragma config FPBDIV = DIV_4

#define T1ON()  { T1CONbits.ON = 1; }

void keses(unsigned int a)
{
    int k;
    for(k = 0; k < a; k++);
}

// a függvénynek két paramétere van
// 1. meddig számoljon a for ciklus (a)
// 2. unsigned char (byte) típus a T1 osztó értéke
void T1Config(int hatar, unsigned char oszto)
{
    PR1 = hatar;
    T1CON = 0x0000;
    T1CONbits.TCKPS = oszto;
}

main()
{
//    unsigned char b;
//    typedef unsigned char byte;
//    byte k;

    TRISD = 0x0000;
    LATD = 0x0000;
    
    // T1 konfig
    T1Config(0x1234, 2);
    T1ON();
    
    while(1)
    {
        // késés
        // timer1???
        // saját fgv
        // keses(10000);
    
        if(IFS0bits.T1IF)
        {
            IFS0bits.T1IF = 0;
            LATD++;
        }
        
        // egyéb kódrészlet
        
    }
}
