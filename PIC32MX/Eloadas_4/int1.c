// Két belső periféria adhat megszakítást, a Timer1 és a Timer2
// Egy INT függvény van (Single mód), ebben feltételes szerkezeteket 
// alaklmazunk az interrupt flag-ek állapotának figyelésére.

#include <xc.h>
#include "sys/attribs.h"

#define     T1ON()      { T1CONbits.ON = 1; }
#define     T2ON()      { T2CONbits.ON = 1; }
#define     LEDT1       LATDbits.LATD0
#define     LEDT2       LATDbits.LATD1
#define     LEDT1TG()     { LEDT1 = ~LEDT1; }
#define     LEDT2TG()     { LEDT2 = ~LEDT2; }

void __ISR(0, ipl1) szerdaINT()
{
    if(IFS0bits.T1IF)
    {
        IFS0bits.T1IF = 0;
        LEDT1TG();
    }
    
    if(IFS0bits.T2IF)
    {
        IFS0bits.T2IF = 0;
        LEDT2TG();
    }
}

void T1Config(unsigned int pr1, unsigned char oszto);

main()
{
    // konfig
    TRISD = 0x0000;
    LATD = 0x0000;
    
    // Timer1 konfig
    // időzítő mód
    T1Config(0x1234, 0x02);
    
    // Timer2 konfig, irdőzítő, 1:32
    T2CON = 0x0050;
    
    // T1 INT konfig
    IFS0bits.T1IF = 0;
    IEC0bits.T1IE = 1;
    IPC1bits.T1IP = 1;
    
    // T2 INT konfig
    IFS0bits.T2IF = 0;
    IEC0bits.T2IE = 1;
    IPC2bits.T2IP = 1;
    
    // INT konfig
    INTCONbits.MVEC = 0;
    
    // INT engedélyezése
    asm volatile("ei");
    
    // T1, T2 engedélyezése
    T1ON();
    T2ON();
    
    while(1)
    {
       // itt van a vezérlés 
    }
}

void T1Config(unsigned int pr1, unsigned char oszto)
{
    T1CONbits.TGATE = 0;
    T1CONbits.TCS = 0;
    T1CONbits.TCKPS = oszto;
    TMR1 = 0x0000;
    PR1 = pr1;
}
