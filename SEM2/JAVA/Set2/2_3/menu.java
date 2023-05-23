import BookList.*;
import MemberList.*;
import Transaction.*;
import java.util.Scanner;
public class menu {
    public static void main(String args[])
    {
        long ca,cp;
        int ch;
        Scanner Sc = new Scanner(System.in);
        booklist blist=new booklist();
        memberlist mlist=new memberlist();
        transaction tt=new transaction();
        do
        {
            System.out.println("0.Quit");
            System.out.println("1.Add new book in the list");
            System.out.println("2.Add more copies for a book");
            System.out.println("3.Show all book details");
            System.out.println("4.Show a particular book detail");
            System.out.println("5.Add new member");
            System.out.println("6.Show details of all members");
            System.out.println("7.Show details of a member");
            System.out.println("8.Issue a book");
            System.out.println("9.Return a book");
            System.out.println("10.Display All Transaction Details");
            System.out.println("Enter your choice:");
            ch = Sc.nextInt();
            Sc.nextLine();
            switch (ch) {
                case 1:
                    System.out.println("Enter bookid:");//,title, copies purchased, copies available:");
                    String bid=Sc.nextLine();
                    System.out.println("Enter title:");                    
                    String title = Sc.nextLine();
                    System.out.println("Enter copies purchased: ");
                    ca = Sc.nextLong();
                    Sc.nextLine();
                    System.out.println("Enter copies available: ");
                    cp = Sc.nextLong();
                    Sc.nextLine();
                    if(!blist.check(bid))
                    {                        
                        book b = new book(bid, title, cp, ca);
                        blist.add_book(b);
                    }
                    else{
                        System.out.println("Book already present. Copies Incremented...");
                        blist.incrementAvail(bid, ca);
                        blist.incrementPur(bid, cp);
                    }
                    break;
                case 2:
                    System.out.print("Enter book id:");
                    bid=Sc.nextLine();
                    if(!blist.check(bid))
                    {
                        System.out.println("Invalid ID.");
                    }
                    else
                    {
                        System.out.print("Increment Copies available by:");
                        long val=Sc.nextLong();
                        blist.incrementAvail(bid, val);
                    }
                    break;
                case 3:
                    blist.displayAll();
                    break;
                case 4:
                    System.out.println("Print Book id: ");
                    bid=Sc.nextLine();
                    if(!blist.check(bid))
                    {
                        System.out.println("Invalid ID");
                    }
                    else
                    {
                        blist.display(bid);
                    }
                    break;
                case 5:
                    System.out.println("Enter member_id:");
                    String mid=Sc.nextLine();
                    if(!mlist.check(mid)){
                        System.out.println("Enter name:");
                        String name=Sc.nextLine();
                        System.out.println("Enter date of birth:");
                        String date=Sc.nextLine();
                        System.out.println("Enter number of books issued:");
                        int issued=Sc.nextInt();
                        Sc.nextLine();
                        member m=new member(mid,name,date,issued);
                        mlist.addMember(m);
                    }
                    else{
                        System.out.println("Member ID should be unique...");
                    }   
                    break;
                case 6:
                    mlist.displayAll();
                    break;
                case 7:
                    System.out.print("Enter member id:");
                    mid=Sc.nextLine();
                    mlist.display(mid);
                    break;
                case 8:
                    System.out.println("Enter valid book id: ");
                    bid = Sc.nextLine();
                    if(blist.check(bid))
                    {
                        if(blist.isAvialble(bid))
                        {
                            System.out.println("Enter valid member id");
                            mid = Sc.nextLine();
                            if(mlist.check(mid))
                            {
                                if(mlist.issueLimit(mid))
                                {
                                    entry e=new entry(bid,mid);
                                        tt.issue(e);
                                        blist.decrementAvail(bid,1);
                                        mlist.incrementIssue(mid);
                                }
                                else
                                    System.out.println("Issue Limit");
                            }
                            else
                                System.out.println("Invalid member id");
                        }
                    }
                    else
                        System.out.println("Invalid book id");
                    break;
                case 9:
                    System.out.println("Enter valid book_id and member_ID:");
                    bid=Sc.nextLine();
                    mid=Sc.nextLine();
                    if(tt.check(bid,mid)){
                        System.out.println("Book Returned successfully...");
                        blist.incrementAvail(bid, 1);
                        mlist.decrementIssued(mid);
                    }
                    else{
                        System.out.println("Wrong entry details...");
                    }
                    break;
                case 10:
                    tt.displayAll();
                    break;
                default:
                    break;
            }
            
        }while(ch!=0);
        Sc.close();
    }
    
}
