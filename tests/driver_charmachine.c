#include "charmachine.h"
#include <stdio.h>

int main() {
    start();
    while (currentChar == ' ' || currentChar == LINEMARK) {
        adv();
    }

    if (currentChar == TEXTMARK) {
        printf("DONE MARK AT FIRST CHAR\n");
    } else {
        int i=0;
        while (currentChar != LINEMARK && currentChar!= ' ') {
            printf("%c", currentChar);
            adv();
            i++;
        }
    }
}