import java.util.Arrays;

// https://leetcode.com/problems/maximum-profit-in-job-scheduling/

class Solution {
    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        int n = startTime.length;
        int[][] jobs = new int[n][3];
        for (int i = 0; i < n; i++) {
            jobs[i][0] = startTime[i];
            jobs[i][1] = endTime[i];
            jobs[i][2] = profit[i];
        }

        Arrays.sort(jobs, (a, b) -> a[1] - b[1]);

        int[] dp = new int[n];
        dp[0] = jobs[0][2];

        for (int i = 1; i < n; i++) {
            dp[i] = Math.max(jobs[i][2], dp[i-1]);
            for (int j = i - 1; j >= 0; j--) {
                if (jobs[j][1] <= jobs[i][0]) {
                    dp[i] = Math.max(dp[i], jobs[i][2] + dp[j]);
                    break;
                }
            }
        }

        int ans = Integer.MIN_VALUE;
        for (int val: dp) {
            ans = Math.max(ans, val);
        }
        return ans;
    }
}