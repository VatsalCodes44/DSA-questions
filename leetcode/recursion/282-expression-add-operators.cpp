#include <bits/stdc++.h>

using namespace std;

void f(string& num, int k, int i, int lastOperand, string& ans, int total, vector<string>& ansArr) {
    if (i == num.size()) {
        if (k == total) {
            ansArr.push_back(ans);
        }
        return;
    }

    int curr = 0;
    string currStr = "";
    int totalCopy = total;
    int oldSize = ans.size();

    for (int j = i; j < num.size(); j++){

        curr = curr * 10 + (num[j] - '0');
        currStr.push_back(num[j]);

        
        if (ans.size() == 0) {
            if (curr != 0) {
                ans += currStr;
            }
            total += curr;
            f(num, k, j+1, curr, ans, total, ansArr);
            ans.resize(oldSize);
            total = totalCopy;
        }
        else {
            // +
            ans.push_back('+');
            ans += currStr;
            total += curr;
            f(num, k, j+1, curr, ans, total, ansArr);
            ans.resize(oldSize);
            total = totalCopy;
            
            // -
            ans.push_back('-');
            ans.push_back(num[i]);
            total -= num[i] - '0';
            f(num, k, j+1, curr, ans, total, ansArr);
            ans.resize(oldSize);
            total = totalCopy;
            
            // *
            ans.push_back('*');
            ans.push_back(num[i]);
            int curr = num[i] - '0';
            total = total - lastOperand + lastOperand * curr;
            f(num, k, j+1, curr, ans, total, ansArr);
            ans.resize(oldSize);
            total = totalCopy;
            
            // /
            if (num[i] - '0') {
                ans.push_back('/');
                ans.push_back(num[i]);
                int curr = num[i] - '0';
                total = total - lastOperand + lastOperand / curr;
                f(num, k, j+1, curr, ans, total, ansArr);
                ans.resize(oldSize);
                total = totalCopy;
            }
        }
    }
}

vector<string> addOperators(string num, int target) {
    string ans;
    vector<string> ansArr;
    f(num, target, 0, 0, ans, 0, ansArr);
    return ansArr;
}

int main () {
    string num = "105";
    int target = 5;
    vector <string> arr = addOperators(num, target);
    for (auto i: arr) {
        cout << i << endl;
    } 
}