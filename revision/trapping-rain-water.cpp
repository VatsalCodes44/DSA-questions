#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int nextGreatestElement = -1;
        vector<int> nge(height.size(), -1);

        // nge left
        for (int i = 0; i < height.size(); i++) {
            if (nextGreatestElement > height[i]) nge[i] = nextGreatestElement;
            nextGreatestElement = max(nextGreatestElement, height[i]);
        }

        nextGreatestElement = -1;

        // nge right
        for (int i = height.size()-1; i >= 0; i--) {
            if (nextGreatestElement > height[i]) nge[i] = min(nge[i], nextGreatestElement);
            else nge[i] = -1;
            nextGreatestElement = max(nextGreatestElement, height[i]);
        }
        nge[nge.size()-1] = -1;
        nge[0] = -1;

        int sum = 0;
        for (int i = 0; i < nge.size(); i++) {
            if (nge[i] != -1) sum += nge[i] - height[i];
        }

        return sum;
    }
};

int main () {
    vector<int> arr = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution s;
    cout << s.trap(arr);
}