#define     BTN         PORTAbits.RA3
#define     LEDs        LATD
#define     LEDsON()    { LEDs = 0xAAAA; }
#define     LEDsOFF()   { LEDs = 0x5555; }
#define     LED0        LATBbits.LATB0
#define     LED0TG()    { LED0 = ~LED0; }
