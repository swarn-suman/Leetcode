class Solution {
public:
    bool rotateString(string s, string goal) {

        int n = s.length();
        int m = goal.length();

        if (n != m) {
            return false;
        }

        string concatenated = s + s;

        int index = concatenated.find(goal);

        if (index != string::npos) {
            return true;
        }
        return false;
    }
};