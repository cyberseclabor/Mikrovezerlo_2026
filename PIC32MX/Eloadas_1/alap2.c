// Az "A" port 3. bitje bemenet, bitmezővel került beállításra
// A "D" port kimenet, a LATD regiszter írásával konkrét érték
// kerül a "D" kimenetre.
// A cél az, hogy a nyomógomb állapotát mindig le tudjuk kérni,
// vizsgálni, ezért került be a feltételes szerkezet a 
// while(1) végtelen ciklusba.
// Ha az "RA3" bit (PORTA regiszter 3. bitje) logikai 1-ben van,
// akkor a "D" porton a 0x5555 jelenik meg, egyébként pedig 
// a 0xAAAAA.

#include <xc.h>

main()
{
    TRISAbits.TRISA3 = 1;
    
    TRISD = 0x0000;
    LATD = 0x5555;
    
    while(1)
    {
        if(PORTAbits.RA3)
            LATD = 0x5555;
        else
            LATD = 0xAAAA;
    }
}
