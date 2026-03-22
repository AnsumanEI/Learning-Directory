import java.util.*;

public class twodarrays {
    static Scanner ip = new Scanner(System.in);// global values have to static

    public static void add(int arr[][]) {
        for (int i = 0; i < arr.length; i++)

        {
            for (int j = 0; j < arr[i].length; j++) {
                System.out.println("enter the value for - arr [" + i + "][" + j + "]");
                arr[i][j] = ip.nextInt();
            }
        }
    }

    public static void print(int arr[][]) {
        for (int i = 0; i < arr.length; i++)

        {
            for (int j = 0; j < arr[i].length; j++) {
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {

        int arr[][] = new int[2][3];// normal
        // or
        int arr1[][] = new int[2][];
        // jagged (rows can have diffrent length)
        arr1[0] = new int[5];
        arr1[0] = new int[6];

        add(arr);
        print(arr);

    }
}
