// egyik levelezős feladat

// Az egyik feladat az volt, hogy az A.15 bemenetern lévő 0-1-0 állapotváltásokat
// számoljuk. A while(1) ciklusok nem jók, mert az állapotváltások végéig 
// várakozik a mikrovezérlő.
// Ezért az egyik Timer belső periféria kerül felhasználásra úgy, hogy számláló 
// módban dolgozik ez a belső periféria.
// A Timer1 nem használható, mert a T1CK bemenet nincs kivezetve a Fusion V7-es
// fejlesztőpanelre. Ezért (és csak ezért) kerül alkalmazásra a Timer3.

#include <xc.h>


main()
{
    TRISAbits.TRISA15 = 1;
    TRISCbits.TRISC2 = 1;   // T3CK
    TRISD = 0x0000;
    LATD = 0x0000;
    
    // T3 konfig, számláló
    T3CON = 0x0002;
    PR3 = 0xFFFF;
    T3CONbits.ON = 1;
    
    while(1)
    {
        //while(PORTAbits.RA15);
        //while(!PORTAbits.RA15);
        //LATD++;
        
        // egyéb kódrészlet
        
        if(IFS0bits.T3IF)
        {
            LATD++;
            IFS0bits.T3IF = 0;
        }
    }
}
