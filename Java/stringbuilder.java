public class stringbuilder {
    public static void main(String[] args) {
        StringBuilder sb = new StringBuilder("hello");
        sb.setCharAt(0, 'd'); // this cannot be done in string as instance cannot be changed
        System.out.println(sb);

        sb.insert(3, 'c');
        System.out.println(sb);
        sb.deleteCharAt(3);
        sb.delete(2, 3);
        System.out.println(sb);
        System.out.println(sb.length());
        // we can check the time diffrence by

    }
}
