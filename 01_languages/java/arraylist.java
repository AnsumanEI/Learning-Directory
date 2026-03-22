import java.util.ArrayList;

public class arraylist {
    public static void main(String[] args) {
        ArrayList<Integer> abc = new ArrayList<>();
        System.out.println(abc + "-> " + abc.size());

        abc.add(20);
        abc.add(10);
        abc.add(40);
        System.out.println(abc + "-> " + abc.size());

        abc.add(2, 100);
        System.out.println(abc + "-> " + abc.size());

        int val = abc.get(0);
        System.out.println(val);

        abc.set(0, 1);
        System.out.println(abc + "-> " + abc.size());

        abc.remove(1);
        System.out.println(abc + "-> " + abc.size());
    }
}
