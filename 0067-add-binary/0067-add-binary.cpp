class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size()-1, j = b.size()-1;
        int carry = 0;
        string ans = "";
        
        while (i >= 0 || j >= 0) {
            int sum = carry;
            if (i >= 0) {
                sum += a[i]-'0';
            }
            if (j >= 0) {
                sum += b[j]-'0';
            }
            ans += ((sum%2)+'0');
            carry = sum > 1 ? 1 : 0;
            i--; j--;
        }

        if (carry) {
            ans += (carry+'0');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
/*
a b c  ->   op
1 1 1       1 1c
    
1 0 1       0 1c
0 1 1       0 1c
1 1 0       0 1c
    
0 0 1       1 0c
1 0 0       1 0c
0 1 0       1 0c
    
0 0 0       0 0c
*/
    