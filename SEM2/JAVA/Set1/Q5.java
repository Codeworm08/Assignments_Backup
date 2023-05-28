package A1;

import java.util.Scanner;

public class Q5 {

	public static void main(String[] args) {
		
		Scanner Sc = new Scanner (System.in);
		System.out.println("Enter string: ");
		String s1 = Sc.nextLine();
		String s2 = s1;
		System.out.println(s1==s2);
		System.out.println(s1 + ".equals(" + s2 + ")" + s1.equals(s2));
		System.out.println("Enter 2 strings: ");
		String s3 = Sc.nextLine();
		String s4 = Sc.nextLine();
		System.out.println(s3==s4);
		System.out.println(s3 + ".equals(" + s4 + ")" +s3.equals(s4));
		Sc.close();
	}

}
