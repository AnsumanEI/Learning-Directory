import java.util.*;

public class stack {
    public static void main(String[] args) {
        Stack<Integer> st = new Stack<>();
        st.push(1);
        st.push(11);
        st.push(111);
        st.push(1111);
        st.push(11111);
        System.out.println(st);

        int val = st.get(3);
        System.out.println(val);

        System.out.println(st.peek());// displays the top element in the stack

        System.out.println(st.pop());// pp removes the top value in the stack
        System.out.println(st);
    }
}
