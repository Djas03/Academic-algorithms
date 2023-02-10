import java.util.Scanner;

public class HelloWorld{
    public static void main (String[] args){
        Scanner input = new Scanner(System.in);

        int number1,number2, soma;

        System.out.println("Digite o primeiro numero: ");
        number1 = input.nextInt();
        
        System.out.println("Digite o segundo numero: ");
        number2 = input.nextInt();

        soma = number1 + number2;

        System.out.printf("A soma dos valores é %d ", soma);
        
        input.close();
    }
}

