// Ennek a file-nak a működése megegyezik az "alap5.c" működésével,
// de egyszerűbben, struktúráltan került megvalósításra.
// A "panel.h" file-ban a panelhez köthető makrók, definíciók 
// találhatók, a "sajatfgv.h"-ban pedig a sajátfüggvény szignatúrája.
// A "fgv.c"-ben a sajátfüggvény (keses()) található, de ezt 
// a "C" file-t nem olvassuk be a file elején.

#include <xc.h>
#include "panel.h"
#include "sajatfgv.h"

main()
{
    TRISD = 0x0000;
    
    while(1)
    {
        LED0TG();
        keses(1000);
    }
}
