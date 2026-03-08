#include <xc.h>

#define     ADON()      { AD1CON1bits.ON = 1; }

void ADConfig();
int ADResult();

main()
{
    TRISD = 0x0000;
    LATD = 0x0000;
    
    ADConfig();
    
    ADON();
    while(1)
    {
        LATD = ADResult();      
    }     
}

void ADConfig()
{
    AD1CON1 = 0x00E0;   // 0000
    AD1CON2 = 0x0000;
    AD1CON3 = 0x1F3F;
    AD1CHSbits.CH0SA = 0; // AN0
    AD1CSSL = 0x0000;
    AD1PCFG = 0xFFFE;
}

int ADResult()
{
    AD1CON1bits.SAMP = 1;
    while(!AD1CON1bits.DONE);
    return ADC1BUF0;
}
