import java.util.ArrayDeque;

public class queue {
    public static void main(String[] args) {
        ArrayDeque<Integer> qt = new ArrayDeque<>();
        qt.addLast(1);
        qt.addLast(2);
        qt.addLast(3);
        qt.addLast(4);
        qt.addLast(5);

        System.out.println(qt);
        System.out.println(qt.getFirst());
        System.out.println(qt.getLast());
        qt.removeLast();
        System.out.println(qt);
        // by default refrencing is done in java so as to reduce the pressue on the
        // processor

    }
}
