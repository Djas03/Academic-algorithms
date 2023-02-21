package Exercicios.Exe3_16;

import java.util.Scanner;

public class HeartRateTest {
    public static void main(String[] args) {
        String nome, sobrenome;
        int dia, mes, ano;
        Scanner input = new Scanner(System.in);

        System.out.print("Digite seu nome: ");
        nome = input.nextLine();
        System.out.print("\nDigite o sobrenome: ");
        sobrenome = input.nextLine();
        System.out.print("\nDigite o dia do seu nascimento: ");
        dia = input.nextInt();
        System.out.print("\nDigite o mes do seu nascimento(em numero): ");
        mes = input.nextInt();
        System.out.print("\nDigite o ano do seu nascimento: ");
        ano = input.nextInt();
        System.out.println();

        HeartRate P1 = new HeartRate(nome, sobrenome, dia, mes, ano);

        P1.MostraDados();

        input.close();
    }
}
