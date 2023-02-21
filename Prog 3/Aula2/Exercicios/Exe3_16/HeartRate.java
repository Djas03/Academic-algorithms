package Exercicios.Exe3_16;

import java.time.LocalDate;
import java.time.Period;

public class HeartRate {
    private String nome, sobrenome;
    private int data_dia, data_mes, data_ano;

    public HeartRate(String nome, String sobrenome, int dia, int mes, int ano){
        this.nome = nome;
        this.sobrenome = sobrenome;
        this.data_dia = dia;
        this.data_mes = mes;
        this.data_ano = ano;
    }

    //modificadores 
    public void SetName(String nome){this.nome = nome;}
    public void SetSobrenome(String sobrenome){this.sobrenome = sobrenome;}
    public void SetDia(int dia){this.data_dia = dia;}
    public void SetMes(int mes){this.data_mes = mes;}
    public void SetAno(int ano){this.data_ano = ano;}

    //seletores
    public String getName(){return this.nome;}
    public String getSobrenome(){return this.sobrenome;}
    public int getDia(){return this.data_dia;}
    public int getMes(){return this.data_mes;}
    public int getAno(){return this.data_ano;}

    //Metodos
    public int getIdade(){
        LocalDate dataNasc = LocalDate.of(getAno(), getMes(), getDia());
        LocalDate dataHoje = LocalDate.now();
        Period Idade = Period.between(dataNasc, dataHoje);
        return Idade.getYears();
    }

    public int getFreqMax(){
        return 220 - getIdade();
    }

    public double getFreqCardAlvo(){
        return getFreqMax() * 0.85;
    }

    public void MostraDados(){
        System.out.printf("Nome: %s\n", getName());
        System.out.printf("Sobrenome: %s\n", getSobrenome());
        System.out.printf("Data de nascimento: %d/%d/%d\n", getDia(),getMes(), getAno());
        System.out.printf("Idade: %d\n", getIdade());
        System.out.printf("Frequencia Cardiaca Maxima: %d\n", getFreqMax());
        System.out.printf("Frequencia Cardia Alvo (85%%): %,.2f", getFreqCardAlvo());
    }


}
