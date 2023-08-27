/**
 * @param {number[][]} mat
 * @return {number}
 */
var diagonalSum = function(mat) {
    var ans = 0;
    var n = mat.length;
    for(let i=0, j=n-1; i<n; i++, j--){
        ans += (i==j)? mat[i][i] : mat[i][j] + mat[i][i];
    }
    return ans;
};