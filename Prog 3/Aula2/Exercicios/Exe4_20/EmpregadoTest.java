package Exercicios.Exe4_20;

import java.util.Scanner;

public class EmpregadoTest {
    public static void main(String[] args) {
        String nome;
        double hr_trabalho, Salario_hr;

        Scanner input = new Scanner(System.in);
        Scanner inputString = new Scanner(System.in);


        System.out.print("Digite o nome do Primeiro Empregado: ");
        nome = inputString.nextLine();
        System.out.println();
        System.out.print("Digite a quantidade de horas trabalhadas do Primeiro: ");
        hr_trabalho = input.nextDouble();
        System.out.println();
        System.out.print("Digite o Salario-Hora do Primeiro empregado: ");
        Salario_hr = input.nextDouble();
        System.out.println();

        Empregado empregado1 = new Empregado(nome, hr_trabalho, Salario_hr);

        System.out.print("Digite o nome do Segundo Empregado: ");
        nome = inputString.nextLine();
        System.out.println();
        System.out.print("Digite a quantidade de horas trabalhadas do Segundo: ");
        hr_trabalho = input.nextDouble();
        System.out.println();
        System.out.print("Digite o Salario-Hora do Segundo empregado: ");
        Salario_hr = input.nextDouble();
        System.out.println();

        Empregado empregado2 = new Empregado(nome, hr_trabalho, Salario_hr);
        
        System.out.print("Digite o nome do Terceiro Empregado: ");
        nome = inputString.nextLine();
        System.out.println();
        System.out.print("Digite a quantidade de horas trabalhadas do Terceiro: ");
        hr_trabalho = input.nextDouble();
        System.out.println();
        System.out.print("Digite o Salario-Hora do Terceiro empregado: ");
        Salario_hr = input.nextDouble();
        System.out.println();

        Empregado empregado3 = new Empregado(nome, hr_trabalho, Salario_hr);

        empregado1.MostraDados();
        empregado2.MostraDados();
        empregado3.MostraDados();

        input.close();
        inputString.close();
    }


}
