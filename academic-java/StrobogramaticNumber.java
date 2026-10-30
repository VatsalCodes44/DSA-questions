import java.util.*;
public class StrobogramaticNumber {
    static boolean s(int n) {
        if (n < 0) return false;
        HashMap<Integer, Integer> mpp = new HashMap<>();
        mpp.put(0,0);
        mpp.put(1,1);
        mpp.put(6,9);
        mpp.put(8,8);
        mpp.put(9,6);
        int temp = n;
        int ans = 0;
        while (temp > 0) {
            int digit = temp%10;
            temp /= 10;
            if (digit == 2 || digit == 3 || digit == 4 || digit == 5 || digit ==7) return false;
            ans = ans*10+mpp.get(digit);
        }

        if (ans == n) return true;

        return false;
    }
    public static void main(String[] args) {
        

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.println(s(n));
        sc.close();
    }
}
