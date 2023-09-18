class Solution {
    public int[] kWeakestRows(int[][] mat, int k) {
        PriorityQueue<int[]> pq = new PriorityQueue<>(
            (a, b) -> a[0] != b[0] ? Integer.compare(a[0], b[0]) : Integer.compare(a[1], b[1])
        );
        
        int n = mat.length;
        int m = mat[0].length;
        
        for (int i = 0; i < n; i++) {
            int soldiers = 0;
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) soldiers++;
                else break;
            }
            pq.add(new int[]{soldiers, i});
        }

        int[] weakest = new int[k];
        int index = 0;
        while (k-- > 0) {
            int[] r = pq.poll();
            weakest[index++] = r[1];
        }
        return weakest;
    }
}
