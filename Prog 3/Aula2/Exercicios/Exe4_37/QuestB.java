package Exercicios.Exe4_37;

import java.util.Scanner;

public class QuestB {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int N;
        System.out.print("Digite a quantidade de termos para e : ");
        N = input.nextInt();

        double resultado = 1;
        for (int i = 1; i <= N; i++){
            resultado +=  1/fatorial(i);
        }

        System.out.printf("Valor de e = %,.2f", resultado);

        input.close();
    }

    public static int fatorial(int num){
        int n = num;
        int result = n;
        if (n < 0){
            System.out.println("Numero menor que zero!");
        }
        else if (n == 0){
            result = 1;
        }else{
            for(int i = n - 1; i > 1; i--){
                result = result * i;
            }
        }
        return result;
    }
}
