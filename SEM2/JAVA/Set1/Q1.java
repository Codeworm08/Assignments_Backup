package A1;
import java.util.Scanner;
public class Q1 {
	public static void main(String args[])
	{
		Scanner Sc = new Scanner(System.in);
		int a,b,sum;
		System.out.println("Enter 1st number: ");
		a=Sc.nextInt();
		System.out.println("Enter 2nd number: ");
		b=Sc.nextInt();
		sum=a+b;
		System.out.println("Sum: "+sum);
	}
}
