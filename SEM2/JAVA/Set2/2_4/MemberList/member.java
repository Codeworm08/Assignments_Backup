package MemberList;

public class member {
	public String memid;
	public String name;
	public String dob;
	public int issued;
	public static int max_books=5;
	public member()
	{
		memid="";
		name="";
		dob="";
		issued=0;
	}
	public member(String mid, String name, String dob, int issued)
	{
		this.memid=mid;
		this.name=name;
		this.dob=dob;
		this.issued=issued;
	}
	public member(member m)
	{
		this.memid=m.memid;
		this.name=m.name;
		this.dob=m.dob;
		this.issued=m.issued;
	}
	public void display()
	{
		System.out.println("Member: "+memid+" Name: "+name+" Date of Birth: "+dob+" No. of copies issued: "+issued);
	}
}
