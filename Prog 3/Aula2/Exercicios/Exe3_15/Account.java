package Exercicios.Exe3_15;

public class Account {
    private String name;
    private double balance;

    public Account(String name, double balance){
        this.name = name;

        if (balance > 0.0)
            this.balance = balance;
    }

    public void deposit (double depositAmount){
        if (depositAmount > 0.0)
            balance = balance + depositAmount;

    }

    public double getBalance(){
        return balance;
    }

    public void SetName(String name){
        this.name = name;

    }

    public String getName(){
        return name;
    }

    public void withdraw(double retira){
        if(retira <= balance){
            balance -= retira;
        }else{
            System.out.println("\nValor de débito excedeu o saldo da conta");
        }
    
    }
}
