#include <xc.h>

// SYSCLK 8MHz, 1MHz
#pragma config FNOSC = FRC, FSOSCEN = OFF, POSCMOD = OFF
#pragma config FPBDIV = DIV_8
#pragma config FWDTEN = OFF

void keses(unsigned int a);

main()
{
    TRISD = 0x0000;
    LATD = 0x0000;
    
    while(1)
    {
        LATDbits.LATD0 = ~LATDbits.LATD0;
        keses(10000);
    }
}

void keses(unsigned int a)
{
    int k;
    for(k = 0; k < a; k++);
}
