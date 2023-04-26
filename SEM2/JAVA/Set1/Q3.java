package A1;
import java.util.Scanner;
public class Q3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner Sc = new Scanner(System.in);
		int height;
		float feet,inch;
		System.out.println("Enter height in cm: ");
		height = Sc.nextInt();
		feet = height / 30.5f;
		inch = height / 2.54f;
		System.out.println("Height in feet: "+ feet);
		System.out.println("Height in inches: "+ inch);
	}

}
