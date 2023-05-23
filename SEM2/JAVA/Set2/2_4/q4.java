import BookList.book;
import MemberList.member;
import Transaction.entry;
import java.util.*;

interface booklist{
    ArrayList<book> b=new ArrayList<book>();
    public boolean checkBook(String bid);
    public void displayAllBook();
    public void add_book(book ob);
    public void displayBook(String bid);
    public void incrementPur(String bid,long val);
    public void incrementAvail(String bid,long val);
    public boolean isAvialble(String bid);
    public void decrementPur(String bid, long val);
    public void decrementAvail(String bid, long val);
}

interface memberlist{
    ArrayList<member> m=new ArrayList<member>();
    boolean checkMember(String mid);
    public void addMember(member mi);
    public boolean issueLimit(String mid);
    public void incrementIssue(String mid);
    public void decrementIssued(String mid);
    public void displayMember(String mid);
    public void displayAllMembers();
}
interface transaction{
    ArrayList<entry> t=new ArrayList<entry>();
    public boolean checkTransaction(String bid,String mid);
    public void issue(entry e);
    public void displayAllTransactions();
}
class Lib implements booklist, memberlist, transaction{
    //BookList
    public boolean checkBook(String bid) {
        for(int i=0;i<b.size();i++)
        {
            book ob = b.get(i);
            if(ob.bookid.equals(bid))
                return true;
        }
        return false;
    }
    public boolean isAvialble(String bid){
        for(int i=0;i<b.size();i++){
            book obj=b.get(i);
            if(obj.bookid.equals(bid)){
                if(obj.copies_available==0)
                    return false;
            }
        }
        return true;
    }    
    public void displayBook(String bid) {
        for(int i=0;i<b.size();i++)
        {
            book ob = b.get(i);
            if(ob.bookid.equals(bid))
            {
                ob.display();
                return;
            }
        }
        System.out.println("Book not in List.");        
    }
    public void displayAllBook() {
        if(b.size()==0)
        {
            System.out.println("No books in List.");
            return;
        }
        for(int i=0;i<b.size();i++)
        {
            book ob = b.get(i);
            System.out.println("Book "+(i+1)+": ");
            ob.display();
        }        
    }
     public void add_book(book ob)
    {
        b.add(ob);
        System.out.println("Book successfully added in list.");
    }
    public void incrementPur(String bid,long val)
    {
        for(int i=0;i<b.size();i++)
        {
            book ob = b.get(i);
            if(ob.bookid.equals(bid))
            {
                ob.copies_purchased+=val;
                return;
            } 
        }
    }
    public void decrementPur(String bid, long val)
    {
        for(int i=0;i<b.size();i++)
        {
            book ob = b.get(i);
            if(ob.bookid.equals(bid))
            {
                if(ob.copies_purchased>=val)
                    ob.copies_purchased-=val;
                else
                    System.out.println("Not enough copies left. Decrement failed.");
                return;
            } 
        }
    }
    public void incrementAvail(String bid, long val)
    {
        for(int i=0;i<b.size();i++)
        {
            book ob = b.get(i);
            if(ob.bookid.equals(bid))
            {
                ob.copies_available+=val;
                return;
            } 
        }
    }
    public void decrementAvail(String bid, long val)
    {
        for(int i=0;i<b.size();i++)
        {
            book ob = b.get(i);
            if(ob.bookid.equals(bid))
            {
                if(ob.copies_available>=val)
                    ob.copies_available-=val;
                else
                    System.out.println("Not enough copies left. Decrement failed.");
                return;
            } 
        }
    }
    //MemberList
    public boolean checkMember(String mid)
	{
		for(int i=0;i<m.size();i++)
		{
			member ob = m.get(i);
			if(ob.memid.equals(mid))
				return true;
		}
		return false;
	}
	public void addMember(member mi)
	{
		m.add(mi);
		System.out.println("New member added");
	}
	public boolean issueLimit(String mid)
	{
		for(int i=0;i<m.size();i++)
		{
			member ob = m.get(i);
			if(ob.memid.equals(mid))
			{
				if(ob.issued==member.max_books)
					return false;
				return true;
			}
		}
		return false;
	}

	public void incrementIssue(String mid)
	{
		for(int i=0;i<m.size();i++)
		{
			member ob = m.get(i);
			if(ob.memid.equals(mid))
			{
				ob.issued++;
				break;
			}
		}
	}
	public void decrementIssued(String mid)
	{
		for(int i=0;i<m.size();i++)
		{
			member ob = m.get(i);
			if(ob.memid.equals(mid))
			{
				ob.issued--;
				break;
			}
		}
	}
	public void displayMember(String mid)
	{
		for(int i=0;i<m.size();i++)
		{
			member ob = m.get(i);
			if(ob.memid.equals(mid))
			{
				System.out.println("Member details: ");
				ob.display();
				break;
			}
		}
        System.out.println("Member not found.");
	}
	public void displayAllMembers()
	{
		if(m.size()==0)
		{
			System.out.println("No members in list.");
			return;
		}
		for(int i=0;i<m.size();i++)
		{
			member om = m.get(i);
			System.out.println("Member "+(i+1)+" :");
			om.display();
		}
	}
    //TransactionList
    public boolean checkTransaction(String bid, String mid) {
        for(int i=0;i<t.size();i++)
		{
			entry e = t.get(i);
			if(e.memid.equals(mid) && e.bookid.equals(bid))
			{
				e.memid="xxxx";
				return true;
			}
		}
        return false;
    }
    
    public void issue(entry e) 
    {
        System.out.println("Transaction Completed");
		for(int i=0;i<t.size();i++)
		{
			entry ob = t.get(i);
			if(e.bookid.equals(ob.bookid))
			{
				if(e.memid.equals("xxxx"))
				{
					ob.memid=e.memid;
					return;
				}
			}
		}
		t.add(e);            
    }
    
    public void displayAllTransactions() 
    {
        if(t.size()==0){
            System.out.println("No transactions to Display...");
            return;
        }
        System.out.println("All transaction details are:");
        for(int i=0;i<t.size();i++){
            entry obj=t.get(i);
            System.out.println("Transaction "+(i+1)+"=>");
            obj.display();
        }    
    }
}
public class q4 {
    public static void main(String[] args) {
        Lib l = new Lib();
        Scanner sc = new Scanner(System.in);
        
        int ch;
        long ca,cp;
        do{
            System.out.println("0.Quit");
            System.out.println("1.Add new book in the list");
            System.out.println("2.Search for a book");
            System.out.println("3.Show all book details");
            System.out.println("4.Add new member");
            System.out.println("5.Search for a member");
            System.out.println("6.Show details of all members");
            System.out.println("7.Issue a book");
            System.out.println("8.Return a book");
            System.out.println("9.Display All Transaction Details");
            System.out.println("Enter your choice:");
            ch=sc.nextInt();
            sc.nextLine();
            switch(ch){
                case 0:
                    break;
                case 1:
                    System.out.println("Enter bookid:");//,title, copies purchased, copies available:");
                    String bid=sc.nextLine();
                    System.out.println("Enter title:");                    
                    String title = sc.nextLine();
                    System.out.println("Enter copies purchased: ");
                    ca = sc.nextLong();
                    sc.nextLine();
                    System.out.println("Enter copies available: ");
                    cp = sc.nextLong();
                    sc.nextLine();
                    if(!l.checkBook(bid))
                    {                        
                        book b = new book(bid, title, cp, ca);
                        l.add_book(b);
                    }   
                    else{
                        System.out.println("Book already present. Copies Incremented...");
                        l.incrementAvail(bid, ca);
                        l.incrementPur(bid, cp);
                    }            
                    break;
                case 2:
                    System.out.print("Enter book id:");
                    bid=sc.nextLine();
                    l.displayBook(bid);
                    break;
                case 3:
                    l.displayAllBook();
                    break;
                case 4:
                System.out.println("Enter member_id:");
                String mid=sc.nextLine();
                if(!l.checkMember(mid)){
                    System.out.println("Enter name:");
                    String name=sc.nextLine();
                    System.out.println("Enter date of birth:");
                    String date=sc.nextLine();
                    System.out.println("Enter number of books issued:");
                    int issued=sc.nextInt();
                    sc.nextLine();
                    member m=new member(mid,name,date,issued);
                    l.addMember(m);
                }
                else{
                    System.out.println("Member ID should be unique...");
                }   
                break;
                case 5:
                    System.out.print("Enter member id:");
                    mid=sc.nextLine();
                    l.displayMember(mid);
                    break;
                case 6:
                    l.displayAllMembers();
                    break;
                case 7:
                    System.out.println("Enter valid book id: ");
                    bid = sc.nextLine();
                    if(l.checkBook(bid))
                    {
                        if(l.isAvialble(bid))
                        {
                            System.out.println("Enter valid member id");
                            mid = sc.nextLine();
                            if(l.checkMember(mid))
                            {
                                if(l.issueLimit(mid))
                                {
                                    entry e=new entry(bid,mid);
                                    l.issue(e);
                                    l.decrementAvail(bid,1);
                                    l.incrementIssue(mid);
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
                case 8:
                    System.out.println("Enter valid book_id and member_ID:");
                    bid=sc.nextLine();
                    mid=sc.nextLine();
                    if(l.checkTransaction(bid,mid)){
                        System.out.println("Book Returned successfully...");
                        l.incrementAvail(bid, 1);
                        l.decrementIssued(mid);
                    }else{
                        System.out.println("Wrong entry details...");
                    }
                    break;
                case 9:
                    l.displayAllTransactions();
                    break;
                default:
                    System.out.println("Invalid Input");
                    break;
            }
        }while(ch!=0);
        sc.close();
    }
    
}
