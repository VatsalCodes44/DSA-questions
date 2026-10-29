class Solution {
    int f (int r, int c, int m, int n) {
        if (r == m-1 && c == n-1) return 1;
        if (r >= m || c >= n) return 0;
        return f(r+1, c, m, n) + f(r, c+1, m, n);
    }
    public int numberOfPaths(int m, int n) {
        // code here
        return f(0,0, m, n);
    }
}