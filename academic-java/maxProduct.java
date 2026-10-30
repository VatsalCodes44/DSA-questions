class Solution {
    public int maxProduct(int[] arr) {
        int pos  = 1;
        int neg = 1;
        int ans = arr[0];
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] < 0) {
                int temp = pos;
                pos = neg;
                neg = temp;
            }

            pos = Math.max(arr[i], pos*arr[i]);
            neg = Math.min(arr[i], neg*arr[i]);
            ans = Math.max(pos, ans);
        }
        return ans;
    }
}