package ExemploAula;
public class Account {
 
    private String name;

    //Contrutores
    public Account(){}
    public Account (String name){
        this.name = name;
    }
    //

    public void SetName(String name) {
        this.name = name;        
    }

    public String getName(){
        return name;
    }
}
