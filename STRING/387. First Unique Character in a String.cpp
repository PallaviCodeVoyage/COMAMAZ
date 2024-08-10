class Solution {
public:
    int firstUniqChar(string s) {
        int ans=-1;
        unordered_map<char,int>mp;
        for(char c:s)
        {
            mp[c]++;

        }
        for(int i=0;i<s.length();i++)
        {
            if(mp[s[i]]==1)
            {
                return i;
            }
        }
         return ans;
    }
   
};
