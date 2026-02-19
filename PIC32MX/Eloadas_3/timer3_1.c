#include <xc.h>
// Timer3 T3CK/RC2

#define     T3CK      PORTCbits.RC2
#define     T3On()    { T3CONbits.ON = 1; }

main()
{
    TRISCbits.TRISC2 = 1;
    TRISD = 0x0000;
    
    // Timer3 számláló, 1:1
    T3CON = 0x0002;
    PR3 = 0xFFFF;
    T3On();
    
    while(1)
    {
        // egyéb kódrészlet
        
        LATD = TMR3;
        
        // egyéb kódrészlet
    }
}
