class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size()-1;
        int count = 0;

        while(n >= 0){
            if(s[n] != ' '){
                count++;
            }

            else if(s[n] == ' ' && count > 0){
                break;
            }
            n--;
        }
        return count;
    }
};