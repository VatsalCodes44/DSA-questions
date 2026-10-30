import java.util.*;
class Solution {
  public ArrayList<Integer> primeTillN(int n) {
    // your code goes here
    int[] arr = new int[n + 1];
    ;
    ArrayList<Integer> ans = new ArrayList<>();
    for (int i = 0; i <= n; i++) {
      arr[i] = 1;
    }

    for (int i = 2; i <= Math.sqrt(n); i++) {
      for (int j = i * i; j <= n; j += i) {
        if (arr[j] == 1) arr[j] = 0;
      }
    }

    for (int i = 2; i <= n; i++) {
      if (arr[i] == 1) ans.add(i);
    }

    return ans;
  }
}

