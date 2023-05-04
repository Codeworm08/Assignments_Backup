import java.util.Scanner;
class Metric
{
    public double km_to_mile(double km)
    {
        return km/1.5;
    }
    public double mile_to_km(double mile)
    {
        return 1.5*mile;
    }
}
public class Q10
{
    public static void main(String args[]) {
        int ch;
        double km,mile;
        Metric ob = new Metric();
        Scanner Sc = new Scanner(System.in);
        do
        {
            System.out.println("Enter:\n1->Convert km to mile\n2->Convert mile to km\n0->Quit\n->");
            ch = Sc.nextInt();
            switch (ch) {
                case 1:
                    System.out.println("Enter distance in km:");
                    km=Sc.nextDouble();
                    System.out.println("Distance in miles: "+ob.km_to_mile(km));
                    break;
                case 2:
                    System.out.println("Enter distance in mile:");
                    mile=Sc.nextDouble();
                    System.out.println("Distance in km: "+ob.mile_to_km(mile));
                    break;
                case 0:
                    break;
                default:
                    System.out.println("Invalid Input");
                    break;
            }
        }while(ch!=0);
        Sc.close();
    }
}