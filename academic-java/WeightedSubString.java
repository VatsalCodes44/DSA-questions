public class WeightedSubString {
    long[] values = new long[26];
    WeightedSubString () {
        values[0] = 1;

        for (int i = 1; i < 26; i++) {
            values[i] = (i+1)*values[i-1]+values[i-1];
        }
    } 

    int findFloor(long k) {
        int i = 0;
        int j = 25;
        int ans = 0;
        while (i <= j) {
            int mid = i+(j-i)/2;
            if (values[mid] <= k) {
                ans = mid;
                i = mid+1;
            }
            else j = mid-1;
        }
        return ans;
    }

    String smallestStr (long weight) {
        String ans = "";

        while (weight > 0) {
            int floor = findFloor(weight);
            ans = (char)('A' + floor) + ans;
            weight -= values[floor];
        }
        return ans;
    }

    public static void main(String[] args) {
        WeightedSubString x = new WeightedSubString();
        System.out.println(x.smallestStr(207328820));
    }
}
