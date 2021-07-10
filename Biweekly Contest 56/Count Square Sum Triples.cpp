class Solution {
public:
    int countTriples(int n) {
        int z;
        int zs;
        int count=0;
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                z = i*i + j*j;
                zs = pow(z,0.5);
                
                if(zs*zs == z && zs<=n)
                {
                    count++;
                }
            }
        }
        return count;
        
    }
};
