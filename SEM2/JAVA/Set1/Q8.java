import java.util.Scanner;
class Student{
    private int roll;
    private String name;
    private int score;
    Student()
    {
        roll=0;
        score=0;
        name="";
    }
    Student(int roll)
    {
        this.roll=roll;
        name="";
        score=0;
    }
    Student(String name,int roll)
    {
        this.roll=roll;
        this.name=name;
        score=0;
    }
    Student(String name,int roll,  int score)
    {
        this.roll=roll;
        this.name=name;
        this.score=score;
    }
    Student(Student ob)
    {
        this.roll=ob.roll;
        this.name=ob.name;
        this.score=ob.score;
    }
    public void set(int r, String n, int sc)
    {
        roll = r;
        name = n;
        score = sc;
    }
    public void display()
    {
        System.out.println("Roll: "+roll);
        System.out.println("Name: "+name);
        System.out.println("Score: "+score);
    }
    public void copy(Student ob)
    {
        this.roll=ob.roll;
        this.name=ob.name;
        this.score=ob.score;
    }
}
public class Q8{
    public static void main(String args[]){
        Scanner Sc = new Scanner(System.in);
        System.out.println("Enter name:");
        String name = Sc.nextLine();
        System.out.println("Enter roll:");
        int roll = Sc.nextInt();
        System.out.println("Enter score:");
        int score = Sc.nextInt();
        System.out.println("No value: ");
        Student s = new Student();
        s.display();
        System.out.println("Roll only: ");
        Student r = new Student(roll);
        r.display();
        System.out.println("Roll and name: ");
        Student rn = new Student(name,roll);
        rn.display();
        System.out.println("Roll, name and score: ");
        Student rns = new Student(name,roll,score);
        rns.display();
        System.out.println("Copy Constructor: ");
        Student a = new Student(rns);    
        a.display();
        System.out.println("rns==a: "+(a==rns));
        if(a==rns)
            System.out.println("Shallow Copy");
        else
            System.out.println("Deep Copy since == is false");
        Sc.close();
    }
}