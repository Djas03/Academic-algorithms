#include <stdio.h>

char first_char(char *); //declaração

int main(){
    char *s = "You shall not pass!";
    char c = first_char(s);
    printf("O primeiro caractere de %s eh %c", s,c);
    return 0;


}