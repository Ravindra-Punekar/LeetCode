class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1) return 0;
        if(k%2==0) return 1 - kthGrammar(n-1,k/2);
        else return kthGrammar(n-1,(k+1)/2);
    }
};

/*
n1- 0
n2- 01
n3- 0110
n4- 01101001
n5- 0110100110010110
n6- 01101001100101101001011001101001

*so kth ele independent of n

*2nd half is NOT of first half
    eg. n4- 01101001 
    0110
    1001

*kth index is not operator of k/2th 
recusively go to 
*/