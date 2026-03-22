public class substring {
    public static void main(String[] agrs) {
        String s = "ansuman";
        System.out.println(s.substring(2, s.length()));// if we forget writng the end point then it will print till the
                                                       // end
        String s2 = "append";
        String s3 = s + " " + s2;
        // left to right evaluated
        // so if the first part evaluated as a string then the 2nd part is also
        // evaluated as a string
        String s4 = s3 + " " + 10 + 20;
        System.out.println(s4);// ansuman 1020 is printed instead of ansuman 30
        System.out.print(10 + 20 + " hell0 ");// so 30hello is printed
        // splitting
        String s5 = "hello my name is ansuman , hello i am ansuman panigrahi";
        String[] parts = s5.split(" ");

        for (int i = 0; i < parts.length; i++) {
            System.out.println(parts[i]);
        }
    }
}
