class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        sort(left.begin(),left.end());
        sort(right.begin(),right.end());
        return max((left.size()>0?left[left.size()-1]:0), n-(right.size()>0?right[0]:n));
    }
};