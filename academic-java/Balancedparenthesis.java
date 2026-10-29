import java.util.*;
class Solution {
    public boolean isValid(String s) {
        Deque<Character> dq = new ArrayDeque<>();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(' || s.charAt(i) == '{' || s.charAt(i) == '[') dq.addLast(s.charAt(i));
            else {
                if (dq.size() > 0 && ((s.charAt(i) == ')' && dq.getLast() == '(') || (s.charAt(i) == '}' && dq.getLast() == '{') || (s.charAt(i) == ']' && dq.getLast() == '['))) dq.removeLast();
                else return false;
            }
        }
        return dq.size() == 0 ;
    }
}