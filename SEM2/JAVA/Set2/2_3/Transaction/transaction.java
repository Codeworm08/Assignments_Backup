package Transaction;
import java.util.ArrayList;
public class transaction {
	ArrayList<entry> t = new ArrayList<entry>();
	public boolean check(String mid, String bid)
	{
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
		System.out.println("Transaction");
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
	public void displayAll(){
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
