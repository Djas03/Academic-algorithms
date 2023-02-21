package Exercicio;

import java.util.Scanner;

public class Main3 {
    public static void main (String[] args){
        Scanner input = new Scanner(System.in);

        double pesoEmQuilos, alturaEmMetros;
        
        System.out.println("Digite o seu peso em Quilos: ");
        pesoEmQuilos = input.nextDouble();

        System.out.println("Digite sua altura em Metros: ");
        alturaEmMetros = input.nextDouble();

        double IMC;

        IMC = pesoEmQuilos / Math.pow(alturaEmMetros, 2);
        
        System.out.printf("IMC = %f\n", (double)IMC);

        System.out.printf("BMI VALUES\nUnderweight: less than 18.5\nNormal: between 18.5 and 24.9\nOverweight: between 25 and 29.9\nObese: 30 or greater\n");
        
        input.close();
    }
}
