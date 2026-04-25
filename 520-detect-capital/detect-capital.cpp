class Solution {
public:
    bool detectCapitalUse(string word) {
        int uppercaseCount = 0;
        
        for(char c : word) {
            if(isupper(c)) {
                uppercaseCount++;
            }
        }
        
        
        if(uppercaseCount == word.size()){
            return true;
        } 
        
        
        if(uppercaseCount == 0){
            return true;
        }
        
       
        if(uppercaseCount == 1 && isupper(word[0])){
            return true;
        }
        
        return false;
    }
};