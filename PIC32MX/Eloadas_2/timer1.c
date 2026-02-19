#include <xc.h>
#include "panel.h"
#include "timers.h"

main()
{
    // I/O konfig
    TRISD = 0x0000;
    
    // Timer1 konfig
    // T1CONbits.TGATE = 0;
    T1CON = 0x0020;
    TMR1 = 0x0000;
    PR1 = 0x1234;
    //T1CONbits.ON = 1;
    T1ON();
    
    while(1)
    {
        // egyéb kódrészlet
        
        if(IFS0bits.T1IF)
        {
            LED0TG();
            //IFS0bits.T1IF = 0;
            T1IFCLR();
        }
        
        // egyéb kódrészlet
    }
}
