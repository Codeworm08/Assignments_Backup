import java.util.Scanner;
class Instructor
{
    private String name;
    private long phone;
    public void view()
    {
        System.out.println("Name: "+ name);
        System.out.println("Phone: "+phone);
    }
    public void set(String name, long phone)
    {
        this.name=name;
        this.phone=phone;
    }
}
class Textbook
{
    private String title;
    private String author;
    private String publisher;
    
    public void display()
    {
        System.out.println("Title: "+title);
        System.out.println("Author: "+ author);
        System.out.println("Publisher: "+ publisher);
    }
    public void set(String title, String author, String publisher)
    {
        this.title=title;
        this.author=author;
        this.publisher=publisher;
    }
}
class Course 
{
     private String cname;
     private Instructor in = new Instructor();
     private Textbook t = new Textbook();
     public void display()
     {
        System.out.println("Course name: " + cname);
        System.out.println("Instructor: ");
        in.view();
        System.out.println("Textbook: ");
        t.display();
     }
     public void set(String cname)
     {
        this.cname=cname;
        Scanner S = new Scanner(System.in);
        System.out.println("Set details of course instructor:");
        System.out.println("Enter new name: ");
        String name = S.nextLine();
        System.out.println("Enter new phone no: ");
        long phone = S.nextLong();
        in.set(name,phone);

        System.out.println("Set details of course textbook:");
        
        System.out.println("Enter new title: ");
        S.nextLine();
        String title = S.nextLine();
        System.out.println("Enter new author name: ");
        String author = S.nextLine();
        System.out.println("Enter new publisher name: ");
        String publisher = S.nextLine();
        t.set(title,author,publisher);
        
        S.close(); 
     }
}
class Q11
{
    public static void main(String args[])
    {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter course name:");
        String c = s.nextLine();
        Course cour = new Course();
        System.out.println("Set course details:");
        cour.set(c);
        s.close();
        System.out.println("Course details: ");
        cour.display();
    }
}