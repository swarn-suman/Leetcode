class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size()==0){
            return true;
        }

        vector<char> arr;

        for(int i=0; i<s.size(); i++){
            if(isalnum(s[i])){
                arr.push_back(tolower((unsigned char)s[i]));
            }
        }

        int i=0;
        int j=arr.size()-1;

        while(i<j){
            if(arr[i] != arr[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};