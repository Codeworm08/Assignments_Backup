import java.util.Scanner;
public class Q6{
    void show(int a){
        System.out.println("Value passed: "+a);
    }
    void show(double a){
        System.out.println("Double Value passed: "+a);
    }
    public static void main(String args[]) {
        Q6 ob = new Q6();
        Scanner Sc = new Scanner(System.in);
        short s;
        double d;
        System.out.println("Short int: ");
        s= Sc.nextShort();
        System.out.println("Double val: ");
        d= Sc.nextDouble();
        ob.show(s);
        ob.show(d);
        Sc.close();
    }
}