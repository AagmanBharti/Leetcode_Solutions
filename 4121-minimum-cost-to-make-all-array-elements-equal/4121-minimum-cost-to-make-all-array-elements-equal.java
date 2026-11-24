class Solution {
    public long minCost(int[] nums) {
        long ans = Long.MAX_VALUE;
        int n = nums.length;

        for(int i = 1;i < n - 1;i++){
            long prefix = 0;
            int j = i;

            while(j - 1 >= 0 && nums[j] == nums[j-1]) j--;

            if(j == 0) prefix = 0;
            else prefix = (long)nums[j] * j;

            while(i + 1 < n && nums[i] == nums[i+1]) i++;

            long suffix = (n - i - 1) * (long)nums[i];
            ans = Math.min(ans, prefix + suffix);
        }
        return ans;
    }
}