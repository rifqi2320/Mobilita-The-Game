#include "charmachine.h"
#include "wordmachine.h"
#include <stdio.h>

boolean endWord;
Word currentWord;

int main() {
    startWord();
    int geser = currentWord.length;
    while (!endWord) {
        char wordGeser[] = "";
        for (int i=0; i < currentWord.length; i++) {
            int valword = currentWord.contents[i];
            int val = (int)((valword+geser-65)%26+65);
            char huruf = val;
            printf("%c", huruf);
        }
        advWord();
        if (!endWord) {
            printf(" ");
        }
    }
    printf(".\n");
    return 0;
}