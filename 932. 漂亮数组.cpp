//932. 漂亮数组
//相关标签：分治算法
//对于某些固定的 N，如果数组 A 是整数 1, 2, ..., N 组成的排列，使得：
//对于每个 i < j，都不存在 k 满足 i < k < j 使得 A[k] * 2 = A[i] + A[j]。那么数组 A 是漂亮数组。给定 N，返回任意漂亮数组 A（保证存在一个）。
//示例 1：
//输入：4
//输出：[2, 1, 4, 3]
//
//参考：https://blog.csdn.net/lwgkzl/article/details/83502656
//因为2*A[k]是偶数，如果要求2*A[K]!=A[I]+A[J]那么可以构造位置在A[k]左边的全部放奇数，位置在A[k]右边的全部放偶数。这样就保证了对于K位置而言，这个性质是满足的。
//1,3,5,6,2,4.这组序列中，虽然对于6位置而言，左边全是奇数，右边全是偶数，但是全是奇数的那一边明显不满足要求。怎么解决呢？
//左边是奇数，右边是偶数的形式也得从N比较小的时候开始。这里有一个递归的思想。因为长度为N的序列中，奇数个数为（N+1）/2，偶数个数为N/2，所以Beautiful Array（N）的排列，可以由Beautiful Array(N/2)和Beautiful Array((N+1)/2)组成，为什么这么说呢？
//假设N  = 7，那么Beautiful Array(N/2) = 1,3,2（满足题目性质）  Beautiful Array((N+1)/2) = 1 3  2  4.（满足题目性质）
//那么 2* Beautiful Array((N + 1) / 2) - 1（奇数在前）连接  2 * Beautiful Array(N / 2) = 1  5  3  7 | 2  6  4.（逐个元素进行操作）


vector<int> beautifulArray(int N) {
	vector<int> res;
	if (N == 1) {
		res.push_back(1);
		return res;
	}
	else {
		vector<int> a = beautifulArray((N + 1) / 2);
		for (int i = 0; i < a.size(); i++) res.push_back(a[i] * 2 - 1);
		vector<int> b = beautifulArray(N / 2);
		for (int i = 0; i < b.size(); i++) res.push_back(b[i] * 2);
	}
	return res;
}