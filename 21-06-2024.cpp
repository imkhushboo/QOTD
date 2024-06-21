class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes)
    {
        int sum=0;
        for (int i=0;i<customers.size();i++)
        {
            if (grumpy[i]==0)
            {
                sum=sum+customers[i];
            }
        }
        int ws=0;
        int maxsum=0;
        for (int we=0;we<customers.size();we++)
        {
            if (grumpy[we]==1)
            {
                sum=sum+customers[we];
            }
            if (we-ws+1==minutes)
            {
                maxsum=max(maxsum,sum);
                if (grumpy[ws]==1)
                {
                    sum=sum-customers[ws];
                }
                ws++; 
            }
        }
        return maxsum;
        
    }
};
