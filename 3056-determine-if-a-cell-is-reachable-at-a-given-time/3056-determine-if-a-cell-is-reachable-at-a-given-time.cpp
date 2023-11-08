class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
    
      int mx = max(abs(sx - fx), abs(sy - fy));
      return (sx==fx && sy==fy)? (t==1?false:true) : mx<=t;
   }
};