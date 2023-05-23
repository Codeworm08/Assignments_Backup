package BookList;
import java.util.ArrayList;

public class booklist {
    ArrayList<book> b = new ArrayList<book>();
    
    public boolean check(String bid)
    {
        for(int i=0;i<b.size();i++)
        {
            book ob = b.get(i);
            if(ob.bookid.equals(bid))
                return true;
        }
        return false;
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

    public void display(String bid)
    {
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
    public void displayAll()
    {
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
}
