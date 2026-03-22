import java.util.Scanner;

public class functions {
    static int a;
    static int b;
    static int C = 30;

    public static void swap() {
        int temp = a;
        a = b;
        b = temp;
    }

    public static void main(String[] args) {
        Scanner ip = new Scanner(System.in);
        System.out.println("a");
        a = ip.nextInt();
        System.out.println("b");
        b = ip.nextInt();
        System.out.println(a + " " + b);
        ip.close();

    }

}
