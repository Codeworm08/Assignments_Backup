import java.util.Scanner;
class Student{
    private int roll;
    private String name;
    private int score;
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
        roll=ob.roll;
        name=ob.name;
        score=ob.score;
    }
}
public class Q7{
    public static void main(String args[]){
        Scanner Sc = new Scanner(System.in);
        Student s = new Student();
        System.out.println("Enter name:");
        String name = Sc.nextLine();
        System.out.println("Enter roll:");
        int roll = Sc.nextInt();
        
        System.out.println("Enter score:");
        int score = Sc.nextInt();
        s.set(roll,name,score);
        s.display();
        Student a = new Student();
        a.copy(s);
        System.out.println("Details of copied object:");
        a.display();
        Sc.close();
    }
}