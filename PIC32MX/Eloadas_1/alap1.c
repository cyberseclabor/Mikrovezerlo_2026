// Az "A" port 3. bitje logikai bemenet,
// a "D" port alsó 16 bitje kimenet lesz.
// A I/O portok irányának beállítása után a 
// "D" portra 0x5555 (0B0101010101010101) kerül
// kiírásra
// A while(1) végtelen ciklus miatt a vezérlés (PC)
// nem lép ki a main() függvényből.

// Az xc.h a bitmező és az SFR-ek miatt kell.

#include <xc.h>

main()
{
    //TRISA = 0xFFFF;
    TRISAbits.TRISA3 = 1;
    
    TRISD = 0x0000;
    LATD = 0x5555;
    
    while(1);
}
