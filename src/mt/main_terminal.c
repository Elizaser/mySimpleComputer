#include "myTerm.h"

int main()
{
    mt_clrscr();
    int x, y;

    mt_getscreensize(&y, &x);
    mt_gotoXY(y / 2 , x / 2);

    mt_setfgcolor(GREEN);
    printf(" ");
    mt_setbgcolor(BLACK);
    printf(" HELLO "); 
    mt_setbgcolor(GREEN);
    mt_setfgcolor(WHITE);
    printf(" USER \n");
    // 
    mt_setbgcolor(WHITE);
    mt_setfgcolor(BLACK);
    mt_gotoXY(0, y);
     printf("Continue?[Enter symbol]: "); scanf("%d", &x);
    mt_setbgcolor(DEFAULT);

    return 0;
}