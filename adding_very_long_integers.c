/*********************************************************
** In this example, we will deal eith pointer arithmetic  *
** and string. The example program given in this section  *
** takes as input two long integers seperated by "+" and  *
** displays their sum. Each of these numbers can be up to *
** 80 digit long; Thus, The maximum total to be obtained  *
** is 81 digits. When displaying the total, unnecessary   *
** zeros on the left are skipped. Here is the Program     *
*********************************************************/

/// Metehan Gencer
/// Date: 2023 - 09 - 29

#include <stdio.h>
#include <string.h>

#define MAKSR 80                // Maximum number of digits for operands
#define DTAN "%80[0123456789]"  // Conversion definition for scanf()

int main()
{
    char x[MAKSR + 1], y[MAKSR + 1];    // Operands

    if (scanf(DTAN "+" DTAN, x, y) == 2) {
        char   t[MAKSR + 2];                    // The sum of the operands
        int    top;                             // Temporary single digit sum
        int    elde = 0;                        // carry bit
        int    xb = strlen(x);                  // The size of the first operand.
        char  *xg = x + xb;                     // Pointer to the first operand.
        int    yb = strlen(y);                  // The size of the second operand
        char  *yg = y + yb;                     // Pointer to the second operand
        int    tb = (xb > yb ? xb : yb) + 1;    // Length of the sum
        char  *tg = t + tb;                     // Length of the pointer
        char  *tig = tg - 1;                    // Pointer into t to hold the leftmost nonzero digit.
        *tg = '\0';                             // Termiante the total string of characters

        while (tg > t){
            top = (xg > x ? *--xg - '0' : 0) +
                  (yg > y ? *--yg - '0' : 0) + elde;
            if((elde = top > 9))
                top -= 10;
            *--tg = (char)(top + '0');
            if(top)
                tig = tg;                   // Non-zero number
            }
            printf("Toplam = %s\n", tig);
    }
    else{
        printf("Girdi hatasi");
        return 1;
    }
    return 0;
} // main





