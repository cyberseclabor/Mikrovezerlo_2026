// Ebben a file-ban létrehozásra kerültek definíciók, 
// illetve makrók. 
// A makró és a függvény között lényeges különbségek vannak!!!!
// A programnak a működése megegyezik az "alap2.c"-vel.

#include <xc.h>

#define     BTN         PORTAbits.RA3
#define     LEDs        LATD
#define     LEDsON()    { LEDs = 0xAAAA; }
#define     LEDsOFF()   { LEDs = 0x5555; }

main()
{
    //TRISA = 0xFFFF;
    TRISAbits.TRISA3 = 1;
    
    TRISD = 0x0000;
    LEDs = 0x5555;
    
    while(1)
    {
        if(BTN)
        {
            LEDsON();
        }
        else
        {
            LEDsOFF();
        }
    }
}
