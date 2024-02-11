public class memoryconcept {
    public static void main(String[] args) {
        String s1 = "hello";// new adress for s1 is crearted to parts one is reference (shell) and another
                            // is
                            // instance
        String s2 = "hello";// as s1 already has hello itll directly point to the s1 address (instance)
        String s4 = new String("hello"); // it will be created in a new address //new shell but the same instance

        // this is called interning

        System.out.println(Integer.toHexString(s1.hashCode()));// to convert use function integer to hex
        System.out.println(Integer.toHexString(s2.hashCode()));// to convert use function integer to hex
        System.out.println(Integer.toHexString(s4.hashCode()));// to convert use function integer to hex

        String s5 = s1 + " e ";
        System.out.println(Integer.toHexString(s5.hashCode()));
        // to add the e now it will copy the entire value to another address then add e
        // which will take a long a time
        // so to solve this string builde class is used

    }
}
