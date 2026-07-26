// Methods pop, top and getMin operations will always be called on non-empty stacks.#include <bits/stdc++.h>
#include <bits/stdc++.h>

using namespace std;

// using linked list
// class MinStack {
//     struct ListNode {
//         int val;
//         int mini;
//         ListNode* next;

//         ListNode(int x, int mini) {
//             val = x;
//             this->mini = mini;
//             next = nullptr;
//         }
//         ListNode(int x, int mini, ListNode* next) {
//             this->val = x;
//             this->mini = mini;
//             this->next = next;
//         }
//     };
//     ListNode* head;
//     int currSize;

// public:
//     MinStack() {
//         head = nullptr;
//         currSize = 0;
//     }

//     ~MinStack() {
//         while (head) {
//             ListNode* temp = head;
//             head = head->next;
//             delete temp;
//         }
//     }
    
//     void push(int value) {
//         if (!head) {
//             head = new ListNode(value, value);
//             currSize = 1;
//             return;
//         }

//         ListNode* temp = new ListNode(value, head->mini < value ? head->mini : value, head);
//         head = temp;
//         currSize++;
//     }
    
//     void pop() {
//         if (!head->next) {
//             delete head;
//             currSize = 0;
//             head = nullptr;
//             return;
//         }
//         ListNode* temp = head;
//         head = head->next;
//         delete temp;
//         currSize--;
//     }
    
//     int top() {
//         return head->val;
//     }
    
//     int getMin() {
//         return head->mini;
//     }
// };


// // using vector and pair<int, int> data structure
// class MinStack {
//     vector <pair<int, int>> arr;
//     int currSize;

// public:
//     MinStack() {
//         currSize = 0;
//     }
    
//     void push(int value) {
//         if (arr.size() == 0) {
//             arr.push_back({value, value});
//             currSize = 1;
//             return;
//         }

//         arr.push_back({value, (arr.back().second) < value ? arr.back().second : value});
//         currSize++;
//     }
    
//     void pop() {
//         arr.pop_back();
//         currSize--;
//     }
    
//     int top() {
//         return arr.back().first;
//     }
    
//     int getMin() {
//         return arr.back().second;
//     }
// };


// most optimal approach
class MinStack {
    
    vector<int> arr;
    int mini;

public:
    MinStack(): mini(0) {}
    
    void push(int value) {
        if (arr.size() == 0) {
            mini = value;
            return;
        }

        if (value < mini) {
            arr.push_back((2*value) - mini);
            mini = value;
            return;
        }

        arr.push_back(value);
    }
    
    void pop() {
        if (arr.back() < mini) {
            int prevMini = (2*mini) - arr.back();
            arr.pop_back();
            mini = prevMini;
            return;
        }
        arr.pop_back();
    }
    
    int top() {
        return arr.back() < mini ? mini : arr.back();
    }
    
    int getMin() {
        return mini;
    }
};



int main () {
    vector <int> arr;
}