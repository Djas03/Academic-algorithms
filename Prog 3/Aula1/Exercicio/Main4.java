package Exercicio;

public class Main4 {
    public static void main (String[] args){
        System.out.println("Populacao atual 7,9 B");
        System.out.println("Taxa de crescimento demografico 1,2%");

        long populacao = 790000000L;
        double taxa = 0.012;

        for (int i = 1; i <= 5; i++){
            populacao *= (1 + taxa);
            System.out.println("Populacao mundial em "+i+" ano(s) "+(long)populacao);
        }


    }
}
