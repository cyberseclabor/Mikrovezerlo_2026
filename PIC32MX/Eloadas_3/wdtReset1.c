#include <xc.h>

#pragma config  FWDTEN = ON, WDTPS = PS2048

#define     WDTClr()    { WDTCONbits.WDTCLR = 1; WDTCONbits.WDTCLR = 0; }

void keses(int a)
{
    int k;
    for(k = 0; k < a; k++);
}

main()
{
    TRISD = 0x0000;
    LATD = 0x0000;
    
    if(RCONbits.BOR)
    {
        LATDbits.LATD0 = 1;
        RCONbits.BOR = 0;
    }
    
    if(RCONbits.POR)
    {
        LATDbits.LATD1 = 1;
        RCONbits.POR = 0;
    }
    
    if(RCONbits.EXTR)
    {
        LATDbits.LATD2 = 1;
        RCONbits.EXTR = 0;
    }
    
    if(RCONbits.WDTO)
    {
        LATDbits.LATD3 = 1;
        RCONbits.WDTO = 0;
    }
    
    while(1)
    {
        keses(500000);
        WDTClr();
    }
}
