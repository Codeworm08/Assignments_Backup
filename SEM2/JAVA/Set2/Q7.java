import java.util.*;

public class Q7 {
    static int aCount(String s)
    {
        int n = s.length();
        char ch;
        int count = 0;
        for(int i=0;i<n;i++)
        {
            ch=s.charAt(i);
            if(ch=='a')
                count++;
        }
        return count;
    }
    static int andCount(String s)
    {
        int count = 0;
        int i = 0;
        while(true)
        {
            i=s.indexOf(" and ", i);
            if(i==-1)
            {
                break;
            }
            else
            {
                count++;
                i+=5;
            }
        }
        return count;
    }

    public static void main(String[] args) {
        Scanner Sc = new Scanner(System.in);
        System.out.println("Enter a string: ");
        String s = Sc.nextLine();
        int ch;
        do
        {
            System.out.println("0.Quit");
            System.out.println("1.Count no of a's");
            System.out.println("2.Count no of and's");
            System.out.println("3.Check if starts with 'The'");
            System.out.println("4.Put String into array of characters");
            System.out.println("5.Display tokens in the string");
            ch = Sc.nextInt();
            switch(ch)
            {
                case 0:
                    break;
                case 1:
                    
            }
        }while(ch!=0);
    }
}
