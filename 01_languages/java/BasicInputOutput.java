import java.util.*;

public class basic {
    public static void main(String[] args) {// main method
        Scanner ip = new Scanner(System.in);// input function
        System.out.println("enter the input int");// display or output function
        String a = ip.nextLine();// input variable taken
        System.out.println(a);// output variable a
        System.out.println("your input was " + a);

        // diffrence in next and next line
        String b = ip.nextLine();
        String c = ip.next();// read 2 times to get 2 spaces
        System.out.println(b);
        System.out.println(c);

        // loops are exactly the same as in c++

        ip.close();
    }
}