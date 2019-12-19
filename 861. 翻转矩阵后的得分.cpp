//861. 翻转矩阵后的得分
//有一个二维矩阵 A 其中每个元素的值为 0 或 1 。
//移动是指选择任一行或列，并转换该行或列中的每一个值：将所有 0 都更改为 1，将所有 1 都更改为 0。
//在做出任意次数的移动后，将该矩阵的每一行都按照二进制数来解释，矩阵的得分就是这些数字的总和。
//返回尽可能高的分数。
//示例：
//输入： [[0, 0, 1, 1], [1, 0, 1, 0], [1, 1, 0, 0]]
//输出：39
//解释：
//转换为 [[1, 1, 1, 1], [1, 0, 0, 1], [1, 1, 1, 1]]
//0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39

//贪心算法：首先保证每一行尽可能的大，即如果每一行第一位为0，则翻转，必然能保证翻转后的结果（第一位为1）比原结果大
//再看每一列，如果每列的0个数大于一半，则翻转列，翻转后使得1的个数多余0

int matrixScore(vector<vector<int>>& A) {
	for (int i = 0; i < A.size(); i++) {
		if (A[i][0] != 1) {
			for (int j = 0; j < A[i].size(); j++)
				A[i][j] = 1 - A[i][j];
		}
	}

	for (int j = 0; j < A[0].size(); j++) {
		int zero_count = 0;
		for (int i = 0; i < A.size(); i++) {
			if (A[i][j] == 0)
				zero_count++;
		}
		if (zero_count > A.size() / 2) {
			for (int i = 0; i < A.size(); i++) {
				A[i][j] = 1 - A[i][j];
			}
		}
	}

	int res = 0;
	for (int i = 0; i < A.size(); i++) {
		int rowSum = 0;
		for (int j = 0; j < A[i].size(); j++) {
			rowSum += A[i][j] * pow(2, A[i].size() - j - 1);
		}
		res += rowSum;
	}
	return res;
}