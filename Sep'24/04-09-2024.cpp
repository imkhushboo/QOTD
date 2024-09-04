class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        
        int x1 = 0,y1 = 0;
        char dir = 'N'; 
        int ans = 0;
        set<pair<int, int>> obstacleSet;
        for (auto& obs : obstacles) {
            obstacleSet.insert({obs[0], obs[1]});
        }
        for(auto x: commands)
        {
            
            if(x == -1)
            {
                if(dir == 'N')
                {
                    dir = 'E';
                }
                else if(dir == 'E')
                {
                    dir ='S';
                }
                else if(dir == 'S')
                {
                    dir = 'W';
                }
                else{
                    dir = 'N';
                }
            }
            else if(x == -2)
            {
               if(dir == 'N')
                {
                    dir = 'W';
                }
                else if(dir == 'E')
                {
                    dir ='N';
                }
                else if(dir == 'S')
                {
                    dir = 'E';
                }
                else{
                    dir = 'S';
                } 
            }
            else{
                int flag = 0;
                while(x-- and flag == 0)
                {
                    if(dir == 'N')
                    {
                        y1++;
                    
                    if(obstacleSet.find({x1, y1}) != obstacleSet.end())
                    {
                        y1--;
                        flag = 1;
                    }

                    }
                    else if(dir == 'S')
                    {
                        y1--;
                     
                    if(obstacleSet.find({x1, y1}) != obstacleSet.end())
                    {
                       y1++;
                        flag = 1;
                    }

                    }
                    else if(dir == 'E')
                    {
                        x1++;
                     
                    if(obstacleSet.find({x1, y1}) != obstacleSet.end())
                    {
                        x1--;
                        flag = 1;
                    }
                    }
                    else{
                        x1--;
                    
                    if(obstacleSet.find({x1, y1}) != obstacleSet.end())
                    {
                       x1++;
                        flag = 1;
                    }
                    }   
                }           
            }
            ans = max(ans,x1*x1 + y1* y1);
            
        }
        
        return ans;
        
    }
};
