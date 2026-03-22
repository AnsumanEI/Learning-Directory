
public class arrays {
    public static void add(int[] arr)// its like call by value in c++
    {
        System.out.println("value inside arr-" + arr[0]);
        arr[0] = 1;
        arr[1] = 2;
        arr[2] = 3;
        arr[3] = 4;
    }

    public static void print(int arr[]) {
        for (int val : arr) {
            System.out.println(val);
        }
    }

    // there is a function for arr length called arr.length
    public static void main(String[] args) {
        int arr[] = new int[10];
        add(arr);
        print(arr);
    }
}
