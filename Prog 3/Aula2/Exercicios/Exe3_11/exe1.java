package Exercicios.Exe3_11;

import java.util.Scanner;

public class exe1 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.println("Digite o nome da conta:");
        String accountname = input.nextLine();
        System.out.println("Digite o saldo da conta:");
        double saldo = input.nextDouble();

        Account myAccount = new Account(accountname, saldo);

        System.out.println();
        System.out.printf("Nome: %s\n", myAccount.getName());
        System.out.printf("Saldo: %,.2f\n\n", myAccount.getBalance());

        System.out.println("Digite o valor a ser retirado: ");
        double retira = input.nextDouble();

        myAccount.withdraw(retira);

        System.out.println();
        System.out.printf("Nome: %s\n", myAccount.getName());
        System.out.printf("Saldo: %,.2f\n\n", myAccount.getBalance());


        input.close();

    }
}
