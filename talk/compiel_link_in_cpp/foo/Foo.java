public class Foo{
    private String name;
    private int age;
    public Foo(String name, int age){
        this.name = name;
        this.age = age;
    }
    public void printAge(){
        System.out.println(age);
    }
    public void printName(){
        System.out.println(name);
    }
    public static int main(String[] Args){
        return 0;
    }
}