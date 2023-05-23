package MemberList;
import java.util.ArrayList;
public class memberlist {
	ArrayList<member> m = new ArrayList<member>();
	public boolean check(String mid)
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
	public void display(String mid)
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
	}
	public void displayAll()
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
}
