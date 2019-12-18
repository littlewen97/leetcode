//53. 最大子序和
//相关标签：数组，动态规划，分治算法
//给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
//示例:
//输入: [-2, 1, -3, 4, -1, 2, 1, -5, 4] ,
//输出 : 6
//解释 : 连续子数组 [4, -1, 2, 1] 的和最大，为 6。

//方法一
int maxSubArray(vector<int>& nums) {
	int res = INT_MIN, curSum = 0;
	for (int num : nums) {
		curSum = max(num, num + curSum);
		res = max(curSum, res);
	}
	return res;
}

//方法二：分治法
//类似于二分搜索法，需要把数组一分为二，分别找出左边和右边的最大子数组之和，然后还要从中间开始向左右分别扫描，求出的最大值分别和左右两边得出的最大值相比较取最大的那一个
//边界为：left >= right
int maxSubArray(vector<int>& nums) {
	return helper(nums, 0, nums.size() - 1);
}

int helper(vector<int>& nums, int left, int right) {
	if (left >= right) return nums[left];
	int mid = left + (right - left) / 2;
	int lmax = helper(nums, left, mid - 1);
	int rmax = helper(nums, mid + 1, right);
	int t = nums[mid];
	int mmax = nums[mid];
	for (int i = mid - 1; i >= left; i--) {
		t += nums[i];
		mmax = max(t, mmax);
	}
	t = mmax;
	for (int i = mid + 1; i <= right; i++) {
		t += nums[i];
		mmax = max(t, mmax);
	}
	return max(lmax, max(rmax, mmax));
}