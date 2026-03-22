
import java.util.Arrays;

public class arrays {
    public static void main(String[] args) {
        int[] userArray = { 22, 11, 2, 34, 48 };
        String[] useStrings = { "hi", "bye", "seeyou" };
        Arrays.sort(userArray);
        // Arrays.fill(userArray, 0);
        for (int val : userArray) {
            System.out.println(val);
            System.out.println(useStrings[0]);
        }

    }
}
