import java.util.Scanner;

public class teste {
    public static void main(String[] args) {
      Scanner input = new Scanner(System.in);
        int tam;
      System.out.print("Digite o tamanho do quadrado: ");
      tam = input.nextInt();

      if (tam <= 20){
        for(int i = 0; i < tam; i++){
            for(int j = 0; j < tam; j++){
                System.out.printf("*");
            }
            System.out.println();
        }

      }

      input.close();
    }
}
