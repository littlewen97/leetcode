//338. 比特位计数
//给定一个非负整数 num。对于 0 ≤ i ≤ num 范围中的每个数字 i ，计算其二进制数中的 1 的数目并将它们作为数组返回。
//示例 1:
//输入: 2
//输出 : [0, 1, 1]

//
//方法一
vector<int> countBits(int num) {
	vector<int> r;
	for (int i = 0; i <= num; i++) {
		int res = 0;
		int x = i;
		int y = i;
		do {
			y = x % 2;
			if (y == 1)
				res++;
			x = x / 2;
		} while (x != 0);
		r.push_back(res);
	}
	return r;
}
//方法二：通过dp实现O(n)复杂度， 对于一个二进制数来说，如果它的最低位为1(%2 为 1）,则它与 n/2 的 1 个数相差1。 如果它的最低位为 0，则它与 n/2 的 1 个数相同 这样就可以用前面的推出后面的
//dp[i]=dp[i/2]    when i%2==0
//dp[i]=dp[i/2]+1  when i%2==1
vector<int> countBits(int num) {
	vector<int> res(num + 1, 0);
	for (int i = 1; i <= num; i++) {
		if (i % 2 == 0)
			res[i] = res[i / 2];
		else
			res[i] = res[i / 2] + 1;
	}
	return res;
}