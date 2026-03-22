import java.util.Collections;
import java.util.PriorityQueue;

public class priorityqueue {
    @SuppressWarnings("unused")
    public static void main(String[] args) {
        PriorityQueue<Integer> mp = new PriorityQueue<Integer>();
        mp.add(1);
        mp.add(2);
        mp.add(3);
        mp.add(4);
        mp.add(5);
        mp.add(6);
        mp.add(7);
        mp.add(8);
        System.out.println(mp);
        System.out.println(mp.peek());
        mp.remove(1);
        System.out.println(mp.peek());
        // sp we can also use it to sort the array using nlogn
        // to change the order of priority
        PriorityQueue<Integer> mp1 = new PriorityQueue<Integer>(Collections.reverseOrder());

    }
}
