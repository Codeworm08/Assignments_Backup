package A1;
import java.util.Scanner;
public class Q4 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		double radius;
		final double pi = 3.14;
		Scanner Sc = new Scanner(System.in);
		System.out.println("Enter radius: ");
		radius = Sc.nextDouble();
		double area = pi*radius*radius;
		System.out.println("Area of circle = "+area);
		Sc.close();
	}

}
