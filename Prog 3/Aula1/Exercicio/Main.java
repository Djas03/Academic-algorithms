package Exercicio;
//exercicio 2.28

import java.lang.Math;
import java.util.Scanner;

public class Main {

    public static void main(String[] args){
        Scanner input = new Scanner(System.in);

        int num;

        System.out.println("Digite um numero :");
        num = input.nextInt();

        System.out.printf("Diametro: %f\n", (double)2*num);
        System.out.printf("Circunferencia: %f\n", (double)2*Math.PI* num);
        System.out.printf("Área: %f \n", (double)Math.PI*Math.pow(num, 2));

        input.close();
    }

    
    
}
