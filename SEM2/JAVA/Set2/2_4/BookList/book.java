package BookList;

public class book {
    public String bookid;
    public String title;
    public long copies_purchased;
    public long copies_available;
    
    public book()
    {
        bookid="";
        title="";
        copies_purchased=0;
        copies_available=0;
    }
    public book(String bookid, String title, long cp, long ca)
    {
        this.bookid = bookid;
        this.title = title;
        copies_available = ca;
        copies_purchased = cp;
    }
    public void display()
    {
        System.out.println("ID: "+bookid+" Title: "+title+" Copies Purchased: "+copies_purchased+" Copies Available: "+copies_available);
    }
}
