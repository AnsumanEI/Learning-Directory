import java.util.Scanner;

public class scanner {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a word");
        String userInput2 = sc.next();
        System.out.println(userInput2);
        int userNumber1 = sc.nextInt();
        System.out.println(userNumber1);
        double userNumber2 = sc.nextDouble();
        System.out.println(userNumber2);
        sc.close();
    }
}
