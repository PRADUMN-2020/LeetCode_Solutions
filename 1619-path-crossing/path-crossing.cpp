class Solution {
public:
    pair<int,int>addPair(pair<int,int>pr1,pair<int,int>pr2)
    {
        return {pr1.first+pr2.first,pr1.second+pr2.second};
    }
    bool isPathCrossing(string path) {
      // Time:O(n), Space:O(n)
      map<pair<int,int>,int>m;
      int n=path.size();
      pair<int,int>route;
      route={0,0};
      m[route]++;
      vector<pair<int,int>>delta={{0,1},{1,0},{0,-1},{-1,0}};
      for(int i=0;i<n;i++)
      {
          if(path[i]=='N')
          {
              route=addPair(route,delta[0]);
          }
          else if(path[i]=='E')
          {
               route=addPair(route,delta[1]);
          }
          else if(path[i]=='S')
          {
               route=addPair(route,delta[2]);
          }
          else
          {
               route=addPair(route,delta[3]);
          }
          m[route]++;
          if(m[route]>=2)
          {
              return true;
          }
      }
        return false;
    }
};