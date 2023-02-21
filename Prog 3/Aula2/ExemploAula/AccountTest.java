package ExemploAula;
import java.util.Scanner;

public class AccountTest {
    public static void main (String[] args){
        //cria um objeto Scanner
        Scanner input = new Scanner(System.in);
        
        //cria um objeto do tipo Account
        Account myAccount = new Account();

        System.out.printf("Initial name is: %s\n\n", myAccount.getName());

        System.out.println("Please enter the name: ");
        String theName = input.nextLine();//le uma linha de texto
        myAccount.SetName(theName);//insere theName em myAccount
        System.out.println();//gera linha de saida em branco


        System.out.printf("Name in object myAccount is: %s\n\n", myAccount.getName());

        input.close();
    }
}
