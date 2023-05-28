import java.util.*;
class WrongScoreException extends Exception {
    private int d;
    WrongScoreException(int d)
    {
        this.d=d;
    }
    public String toString()
    {
        return "Score must be positive and less than 100. Score entered is: "+d;
    }
}
class Student
{
    int roll;
    String name;
    int score;
    Student()
    {
        roll=0;
        name="";
    }
    Student(int r, String n)
    {
        roll=r;
        name=n;
    }
    public void setScore(int score) throws WrongScoreException
    {
        if(score<0 || score>100)
            throw new WrongScoreException(score);
        this.score=score;
    }
}

public class Q5 {
    public static void main(String args[])
    {
        Scanner Sc = new Scanner(System.in);
        System.out.println("Enter student name:");
        String name= Sc.nextLine();
        System.out.println("Enter roll:");
        int roll = Sc.nextInt();
        Student s = new Student(roll, name);
        while(true)
        {
            try
            {
                System.out.println("Enter score: ");
                int score = Sc.nextInt();
                s.setScore(score);
                break;
            }
            catch(WrongScoreException e)
            {
                System.out.println("Exception: "+e);
            }
        }
        
    }
}
