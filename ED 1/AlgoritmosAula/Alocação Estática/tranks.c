#include <stdio.h>
#include <stdlib.h>

int main (){
    int a;

    while (1){

        printf("Digite 1 para trancar o curso e 2 para cancelar o trancamento:");
        scanf("%d",&a);
        printf ("\n");

        if (a == 1){
            printf("Curso trancado com sucesso!\n");
            printf("Parabéns sorria novamente e tome uma pequena!\n");
            break;
        }else if (a == 2){
            printf("Seu merda!\n");
            break;
        }else{
            printf("Burro do krl!\n");
        }
    }
        

    return 0;
}