class Solution {
    public boolean isZeroArray(int[] nums, int[][] queries) {
        int n = nums.length;
        int[] diff = new int[n + 1];

        // Apply queries using difference array
        for (int i = 0; i < queries.length; i++) {
            int l = queries[i][0];
            int r = queries[i][1];

            diff[l] -= 1;
            if (r + 1 < n) diff[r + 1] += 1;
        }

        // Build prefix sum and check
        int cumSum = 0;
        for (int i = 0; i < n; i++) {
            cumSum += diff[i];
            nums[i] += cumSum;

            if (nums[i] > 0) return false;
        }

        return true;
    }
}