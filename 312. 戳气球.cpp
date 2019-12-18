//312. 戳气球
//动态规划，分治算法
//有 n 个气球，编号为0 到 n-1，每个气球上都标有一个数字，这些数字存在数组 nums 中。
//现在要求你戳破所有的气球。每当你戳破一个气球 i 时，你可以获得 nums[left] * nums[i] * nums[right] 个硬币。 这里的 left 和 right 代表和 i 相邻的两个气球的序号。注意当你戳破了气球 i 后，气球 left 和气球 right 就变成了相邻的气球。
//求所能获得硬币的最大数量。

//其中 dp[i][j] 表示打爆区间 [i,j] 中的所有气球能得到的最多金币
//k在区间 [i, j] 中，假如第k个气球最后被打爆，那么此时区间 [i, j] 被分成了三部分，[i, k-1]，[k]，和 [k+1, j]，
//只要之前更新过了 [i, k-1] 和 [k+1, j] 这两个子区间的 dp 值，可以直接用 dp[i][k-1] 和 dp[k+1][j]，
//最后被打爆的第k个气球的得分应为 nums[i-1] * nums[k] * nums[j+1]，
//状态转移方程如下所示：
//dp[i][j] = max(dp[i][j], nums[i - 1] * nums[k] * nums[j + 1] + dp[i][k - 1] + dp[k + 1][j])                 (i ≤ k ≤ j)
//区间的遍历顺序：先更新完所有的小区间，然后才能去更新大区间

int maxCoins(vector<int>& nums) {
	int n = nums.size();
	nums.insert(nums.begin(), 1);
	nums.push_back(1);
	vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
	for (int len = 1; len <= n; len++) {
		for (int i = 1; i <= n - len + 1; i++) {
			int j = i + len - 1;
			for (int k = i; k <= j; k++) {
				dp[i][j] = max(dp[i][j], nums[i - 1] * nums[k] * nums[j + 1] + dp[i][k - 1] + dp[k + 1][j]);
			}
		}
	}
	return dp[1][n];
}