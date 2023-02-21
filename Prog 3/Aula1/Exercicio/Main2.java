package Exercicio;

public class Main2 {
    public static void main(String[] args){
        System.out.println("  number  square  cube");

        for (int a = 0; a <= 10; a++){
            if(a < 10){
                System.out.printf("      %d      %d     %d\n", (int)a, (int)Math.pow(a, 2) ,(int)Math.pow(a, 3));

            }else if (a == 10){
                System.out.printf("     %d      %d   %d\n", (int)a, (int)Math.pow(a, 2) ,(int)Math.pow(a, 3));

            }
            
        }

    }
    
}
