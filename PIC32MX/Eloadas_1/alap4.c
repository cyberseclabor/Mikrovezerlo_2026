// A cél egy villógó elkészítése. 
// A "B" port 0. bitje kimenet, ezt bitmező segítségével 
// állítottuk be. Ekkor csak egy bit állapota került 
// beállításra, tehát nem regiszterírás (TRISB = 0x0000;) volt.
// A "D" port minden alsó bitje kimenet lesz (TRISD = 0x0000;)
// Látni akarjuk a LED villogását, ezért késleltetés kell.
// A késleltetés a keses() függvény segítségével kerül megvalósításra.
// A keses() függvény tetszőleges paraméterrel meghívható (int b).
// A keses() szignatúrája a main() előtt található, az implementációja
// pedig a main() után.

#include <xc.h>

#define     BTN         PORTAbits.RA3
#define     LEDs        LATD
#define     LEDsON()    { LEDs = 0xAAAA; }
#define     LEDsOFF()   { LEDs = 0x5555; }
#define     LED0        LATBbits.LATB0

// fgv prototípusa
void keses(int b);


main()
{
    TRISBbits.TRISB0 = 0;
    TRISD = 0x0000;
    
    while(1)
    {
        LED0 = 1;
        keses(1000);
        LED0 = 0;
        keses(1000);
    }
}

void keses(int b)
{
    int k;
    for(k = 0; k < b; k++);
}
