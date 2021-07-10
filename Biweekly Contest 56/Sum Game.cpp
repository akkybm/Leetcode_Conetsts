class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        // question amrk in alice and bob's area
        int al = 0;
        int bo = 0;
        
        // sum of numbers in alice area and bob's area respectively
        int count1 = 0;
        int count2 = 0;
        
        for(int i=0;i<n;i++)
        {
            if(i<n/2)
            {
                if(num[i] == '?')
                {
                    al++;
                }
                else
                {
                    count1 += num[i]-'0';
                }
            }
            else
            {
                if(num[i] == '?')
                {
                    bo++;
                }
                else
                {
                    count2 += num[i]-'0';
                }
            }
        }
        int res = (count1+(al/2)*9) - (count2+(bo/2)*9);
        return res!=0;
        
    }
};
