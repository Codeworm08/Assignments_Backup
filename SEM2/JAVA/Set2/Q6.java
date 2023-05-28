public class Q6 {
    public static void main(String[] args) {
        Integer ob;
        int a =10;
        ob = a;
        System.out.println("basic to object: "+ob);
        System.out.println("2*ob ="+(2*ob));
        String s = String.valueOf(a);
        System.out.println("Basic to string:"+s);
        ob = Integer.parseInt(s);
        System.out.println("String to object: "+ob);
        String s1 = String.valueOf(ob);
        System.out.println("String to object: "+s1);
    }
}
