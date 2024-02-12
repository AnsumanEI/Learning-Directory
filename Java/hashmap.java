import java.util.HashMap;
import java.util.Set;

public class hashmap {
    public static void main(String[] args) {
        HashMap<Integer, String> map = new HashMap<>();
        map.put(1, "one");
        map.put(2, "two");
        map.put(3, "three");
        map.put(4, "four");
        System.out.println(map);
        map.put(1, "hundred");// itll replace the previous value
        System.out.println(map);
        System.out.println(map.get(1));// prints the value of the key 1
        System.out.println(map.containsValue("three"));

        // get all the keys
        Set<Integer> keys = map.keySet();
        System.out.println(keys);

    }
}
