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
                    System.out.println("Number of a's: "+aCount(s));
                    break;
                case 2:
                    System.out.println("No of and's: "+andCount(s));
                    break;
                case 3:
                    System.out.println(s.startsWith("The")? "Yes" : "No");
                    break;
                case 4:
                    char[] a = new char[s.length()];
                    for(int i=0;i<s.length();i++)
                        a[i]=s.charAt(i);
                    System.out.println("Elements in the array: ");
                    for(int i=0;i<s.length();i++)
                        System.out.print(a[i]+" ");
                    System.out.println();
                    break;
                case 5:
                    String[] tokens = s.split("[.\\s@]");
                    System.out.println("The tokens are: ");
                    for(String x : tokens)
                    {
                        System.out.println(x);
                    }
                    break;
                default:
                    System.out.println("Wrong choice.");
                    break;
            }
        }while(ch!=0);
    }
}
