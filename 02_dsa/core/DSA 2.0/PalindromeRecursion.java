import java.io.*;
class arr
{
    static String rev;
    static String pallin (int n,String s)
    {
        if(n==0)
        {
            rev ="";
        }
        else
        
        {
            n--;
            rev = s.charAt(n)+pallin(n,s);
        }
        return rev;
    }
    public static void main(String args[])throws IOException
    {
        InputStreamReader isr=new InputStreamReader(System.in);
        BufferedReader br=new BufferedReader(isr);
        System.out.println("Enter");
        String s=br.readLine();
        String r=pallin(s.length(),s);
        r=r.trim();
        if(r==s)
        {System.out.println("Pallindrome");}
        else
        {System.out.println("not Pallindrome");}
        
    }
}
        