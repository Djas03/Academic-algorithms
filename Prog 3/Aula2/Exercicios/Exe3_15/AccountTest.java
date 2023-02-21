package Exercicios.Exe3_15;

import java.util.Scanner;

public class AccountTest {
    public static void main(String[] args) {
        Account account1 = new Account("Jane Green", 50.00);
        Account account2 = new Account("John Blue", -7.53);

        //mostrar saldo de ambos os objetos
        displayAccount(account1);   
        displayAccount(account2);

        Scanner input = new Scanner(System.in);

        System.out.print("Digite um valor a ser depositado para account1: ");
        double depositAmount = input.nextDouble();
        System.out.printf("\nDepositado %,.2f para saldo de account1\n", depositAmount);
        account1.deposit(depositAmount);

        //mostrar saldo de ambos os objetos
        displayAccount(account1);   
        displayAccount(account2);

        System.out.print("Digite um valor a ser depositado para account2: ");
        depositAmount = input.nextDouble();
        System.out.printf("\nDepositado %,.2f para saldo de account2\n", depositAmount);
        account2.deposit(depositAmount);

        displayAccount(account1);   
        displayAccount(account2);

        input.close();
    }

    public static void displayAccount(Account accountToDisplay){
        System.out.printf("%s balance: $%.2f \n", accountToDisplay.getName(),accountToDisplay.getBalance());

    }
}
