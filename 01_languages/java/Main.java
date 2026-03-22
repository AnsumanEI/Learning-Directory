
// import java.awt.Color;

public class Main {
    public static void main(String[] args) {
        String userInput = "entertainment";
        String upperCased = userInput.toUpperCase();

        System.out.println(upperCased);
        System.out.println(userInput);
        char firstChar = userInput.charAt(0);
        System.out.println(firstChar);
        System.out.println("Contains :" + userInput.contains("Enter".toLowerCase()));
        System.out.println("Contains :" + userInput.contains("Enter"));

    }

}
