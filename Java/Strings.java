import java.util.Scanner;

public class Strings {
    public static void main(String[] args) {
        String s = "ansuman";
        Scanner ip = new Scanner(System.in);
        String s1 = ip.nextLine();

        System.out.println(s + " " + s1);

        ip.close();

        char ch = s.charAt(3);

        System.out.println(ch);
        System.out.println(s1.length());

    }
}
