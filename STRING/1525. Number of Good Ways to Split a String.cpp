class Solution {
public:
    /*int numSplits(string s) {
        int l=s.length();
        int i=0;
        int gl=0;
        while(i<l)
        {
            unordered_set<char>ls(s.begin(),s.begin()+i+1);
             unordered_set<char>rs(s.begin()+i+1,s.end());
             if(ls.size()==rs.size())
             {
                gl++;

             }
             
        }
        return gl;
        
    }*/
    int numSplits(string s) {
        int n=s.length();
        int gs=0;
        set<char>ps;
        set<char>ss;
        vector<int>pv(n,0),sv(n,0);
        for(int i=0;i<n;i++)
        {
            //pv rep prefix vector the state definition states that the element of this vector says that if
            //u include me in the string from beg u will get the no of different characters at my index
            ps.insert(s[i]);
            pv[i]=ps.size();
        }

          for(int i=n-1;i>=0;i--)
        {
            //pv rep sufix vector the state definition states that the element of this vector says that if
            //u include me in the string from lasst pos u will get the no of different characters at my index
            ss.insert(s[i]);
            sv[i]=ss.size();
        }


        for(int i=0;i<n-1;i++)
        {
            if(pv[i]==sv[i+1])//agar main ith index wale element pe split krr rhi hu to i will check whether the no of elements are == to no of element after this index islia
            {
                gs++;
            }
        }
        return gs;
    }
};
