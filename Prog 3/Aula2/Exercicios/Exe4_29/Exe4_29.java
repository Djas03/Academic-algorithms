package Exercicios.Exe4_29;
import java.util.Scanner;

public class Exe4_29 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
          int tam;
        System.out.print("Digite o tamanho do quadrado entre 1 e 20: ");
        tam = input.nextInt();
  
        if (tam <= 20 && tam > 0){
          for(int i = 0; i < tam; i++){
              for(int j = 0; j < tam; j++){
                  System.out.printf("* ");
              }
              System.out.println();
          }
  
        }else{
            System.out.println("Número fora do alcance.");
        }
  
        input.close();
      }
}
