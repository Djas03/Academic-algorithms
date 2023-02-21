package Exercicios.Exe4_37;

import java.util.Scanner;

public class QuestA {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n;

        System.out.print("Digite o número maior que zero, desejado para calcular o fatorial: ");
        n = input.nextInt();

        if (n < 0){
            System.out.println("Numero menor que zero!");
        }
        else if (n == 0){
            System.out.println("0! = 1");
        }else{
            int result = n;
            for(int i = n - 1; i > 1; i--){
                result = result * i;
            }
            System.out.printf("%d! = %d", n,result);
        }

        input.close();
    }
}
