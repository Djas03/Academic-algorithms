package Exercicios.Exe4_20;


public class Empregado {
    
    private String Nome;
    private double numHorasTrab;
    private double Salario_hr;

    public Empregado (String nome, double numHorasTrab, double Salario_hr){
        this.Nome = nome;
        this.numHorasTrab = numHorasTrab;
        this.Salario_hr = Salario_hr;
    }

    public void setNome(String nome){this.Nome = nome;}
    public void setNumHorasTrab(double numHorasTrab){this.numHorasTrab = numHorasTrab;}
    public void setSalario_hr(double Salario_hr){this.Salario_hr = Salario_hr;}

    public String getNome(){return this.Nome;}
    public double getNumHorasTrab(){return this.numHorasTrab;}
    public double getSalario_hr(){return this.Salario_hr;}

    public double getSalarioBruto(){
        if (getNumHorasTrab() <= 40){
            return getNumHorasTrab() * getSalario_hr();
        }else{
            double hr_extra = (getNumHorasTrab() - 40) * (getSalario_hr()/2);
            double first40 = (getNumHorasTrab() - (getNumHorasTrab() - 40)) *  getSalario_hr();
            return first40 + hr_extra;
        }
    }

    public void MostraDados(){
        System.out.printf("Nome do Empregado: %s%n", getNome());
        System.out.printf("Salario Bruto: $%,.2f%n%n", getSalarioBruto());
    }
}
