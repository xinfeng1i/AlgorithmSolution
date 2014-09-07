import java.io.*;
import java.util.*;
import java.math.*;
import java.math.BigInteger;


public class Problem56
{
    public static void main(String arg[])
    {
        // BigInteger maxSum = new BigInteger("0");
        int maxSum = 0;
        BigInteger curSum = new BigInteger("0");
        BigInteger one = new BigInteger("1");
        BigInteger hundred = new BigInteger("100");
        for (BigInteger a = new BigInteger("1"); !a.equals(hundred); a = a.add(one))
        {
            for (int b = 1; b < 100; ++b)
            {
                curSum = a.pow(b);
                int tmp = digitSum(curSum); 
                if (tmp > maxSum)
                {
                    maxSum = tmp;
                }
                // System.out.println("curSum " + curSum);
            }
        }

        System.out.println("max digit sum : " + maxSum);
    }
    
    public static int digitSum(BigInteger n)
    {
        int ans = 0;
        String s = n.toString();
        for (int i = 0; i < s.length(); ++i)
        {
            ans += s.charAt(i) - '0';
        }
        return ans;
    }
}
