// A villogó egyszerűbben került megvalósításra, 
// egyszer kerül meghívásra a "keses()" függvény, a makró 
// meghívásakor a B.0 bit állapotot vált.

#include <xc.h>

#define     BTN         PORTAbits.RA3
#define     LEDs        LATD
#define     LEDsON()    { LEDs = 0xAAAA; }
#define     LEDsOFF()   { LEDs = 0x5555; }
#define     LED0        LATBbits.LATB0
#define     LED0TG()    { LED0 = ~LED0; }

// fgv prototípusa
void keses(int b);


main()
{
    TRISD = 0x0000;
    
    while(1)
    {
        LED0TG();
        keses(1000);
    }
}

void keses(int b)
{
    int k;
    for(k = 0; k < b; k++);
}
