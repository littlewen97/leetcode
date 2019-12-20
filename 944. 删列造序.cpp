//944. 删列造序
//给定由 N 个小写字母字符串组成的数组 A，其中每个字符串长度相等。
//删除 操作的定义是：选出一组要删掉的列，删去 A 中对应列中的所有字符，形式上，第 n 列为 [A[0][n], A[1][n], ..., A[A.length - 1][n]]）。
//输入：["cba", "daf", "ghi"]
//输出：1
//解释：
//当选择 D = { 1 }，删除后 A 的列为：["c", "d", "g"] 和["a", "f", "i"]，均为非降序排列。
//若选择 D = {}，那么 A 的列["b", "a", "h"] 就不是非降序排列了。


//用一个flag来标记这一列是否出现了降序排列
int minDeletionSize(vector<string>& A) {
	int res = 0;
	int height = A.size();

	if (height == 0 || height == 1) return 0;
	bool flag = true;
	int width = A[0].size();
	for (int i = 0; i < width; i++) {
		for (int j = 1; j < height; j++) {
			if (A[j][i] < A[j - 1][i]) {
				flag = false;
				break;
			}
		}
		if (flag == false) {
			res++;
			flag = true;
		}
	}
	return res;
}
