#define     BTN     PORTAbits.RA15
#define     LEDs    LATD
#define     LEDsA()   { LEDs = 0xAAAA; }
#define     LEDs5()   { LEDs = 0x5555; }
#define     LED0    LATDbits.LATD0
#define     LED0TG()  { LED0 = ~LED0; }
