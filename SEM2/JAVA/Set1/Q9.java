import java.util.Scanner;
class BankAcct{
    private int account_number;
    private double balance;
    private static double rate=0.0;
    BankAcct()
    {
        account_number=0;
        balance=0;
    }
    BankAcct(double balance, int acn)
    {
        account_number = acn;
        this.balance = balance;
    }
    public static void newRate(double r)
    {
        rate=r;
    }
    public static void dispRate()
    {
        System.out.println("Rate is: " + rate);
    }

    public double calInt(int time)
    {
        return balance*rate*time;
    }
    public double getBalance()
    {
        return balance;
    }
}
public class Q9{
    public static void main(String args[])
    {
        
        Scanner Sc = new Scanner(System.in);
        System.out.println("Enter balance for 1st account:");
        double b = Sc.nextDouble();
        System.out.println("Enter account number for 1st account:");
        int a = Sc.nextInt();
        BankAcct ob = new BankAcct(b,a);
        BankAcct.dispRate();
        System.out.println("Balance: "+ob.getBalance());
        System.out.println("Set balance of 2nd object: ");
        double bal = Sc.nextDouble();
        System.out.println("Set account number of 2nd object: ");
        int acn = Sc.nextInt();
        BankAcct o2 = new BankAcct(bal,acn);
        System.out.println("Balance of 2nd account: "+o2.getBalance());
        System.out.println("Rate of 2nd account: ");
        BankAcct.dispRate();
        System.out.println("Set new rate: ");
        double r = Sc.nextDouble();
        BankAcct.newRate(r);
        System.out.println("Rate of 1st account: ");
        BankAcct.dispRate();
        System.out.println("Rate of 2nd account: ");
        BankAcct.dispRate();
        System.out.println("Time for 1st account(in years): ");
        int t = Sc.nextInt();
        System.out.println("Interest for 1st account: "+ob.calInt(t));
        System.out.println("Time for 2nd account(in years): ");
        int t2 = Sc.nextInt();
        System.out.println("Interest for 2nd account: "+o2.calInt(t2));
        Sc.close();
    }
}