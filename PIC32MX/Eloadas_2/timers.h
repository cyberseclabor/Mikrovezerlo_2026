#define     T1ON()  { T1CONbits.ON = 1;}
#define     T1OFF()  { T1CONbits.ON = 0;}
#define     T1IFCLR() { IFS0bits.T1IF = 0; }
