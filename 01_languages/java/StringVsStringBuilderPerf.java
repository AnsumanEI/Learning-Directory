public class timediffrence {
    static long start;
    static long end;
    static long start1;
    static long end1;

    @SuppressWarnings("unused")
    public static void main(String[] args) {
        // for string
        start = System.currentTimeMillis();
        String s10 = " ";
        int n = 50000;
        for (int i = 0; i < n; i++) {
            s10 += i;
        }
        end = System.currentTimeMillis();
        long stringstarttime = start;
        long stringendtime = end;

        long duration = stringendtime - stringstarttime;
        System.out.println(duration);

        start1 = System.currentTimeMillis();
        StringBuilder s101 = new StringBuilder();

        for (int i = 0; i < n; i++) {
            s101.append(i);
        }
        end1 = System.currentTimeMillis();
        long stringstarttime1 = start1;
        long stringendtime1 = end1;

        long duration1 = stringendtime1 - stringstarttime1;
        System.out.println(duration1);
    }

}
