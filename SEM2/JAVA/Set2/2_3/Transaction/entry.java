package Transaction;

public class entry {
	String memid,bookid;
	public entry()
	{
		memid="";
		bookid="";
	}
	public entry(String memid, String bookid)
	{
		this.memid=memid;
		this.bookid=bookid;
	}
	public entry(entry e)
	{
		this.memid=e.memid;
		this.bookid=e.bookid;
	}
	public void display()
	{
		System.out.println("Book id: "+bookid+" Member id: "+memid);
	}
}
