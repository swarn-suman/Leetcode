class Solution {
public:
    int balancedStringSplit(string s) {
        int temp = 0;
        int count = 0;

        for(int i=0; i<s.size(); i++){
            if(s[i] == 'R'){
                temp++;
            }
            else{
                temp--;
            }

            if(temp == 0){
                count++;
            }
        }
        return count;
    }
};