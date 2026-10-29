class Solution {
    public int[] nextLargerElement(int[] arr) {
        Deque<Integer> st = new ArrayDeque<>();
        int[] ans = new int[arr.length];
        for (int i = 0; i < arr.length; i++) ans[i] = -1;
        for (int i = arr.length-1; i >= 0; i--) {
            while (!st.isEmpty() && st.getLast() <= arr[i]) st.removeLast();
            if (!st.isEmpty()) ans[i] = st.getLast();
            st.addLast(arr[i]);
        }
        return ans;
    }
}