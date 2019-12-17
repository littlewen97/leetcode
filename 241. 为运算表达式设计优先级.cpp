//241. 为运算表达式设计优先级
//相关标签：分治算法
//给定一个含有数字和运算符的字符串，为表达式添加括号，改变其运算优先级以求出不同的结果。你需要给出所有可能的组合的结果。有效的运算符号包含 +, - 以及 * 。
//示例 1:
//输入: "2-1-1"
//输出 : [0, 2]
//解释 :
//	((2 - 1) - 1) = 0
//	(2 - (1 - 1)) = 2
//
//可以变成 () ? () 这种形式，两个括号内分别是各自的表达式，最终会分别计算得到两个整型数组，中间的问号表示运算符，可以是加，减，或乘
//左右两个括号代表的黑盒子就交给递归去计算

vector<int> diffWaysToCompute(string input) {
	vector<int> res;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
			vector<int> left = diffWaysToCompute(input.substr(0, i));
			vector<int> right = diffWaysToCompute(input.substr(i + 1));
			for (int j = 0; j < left.size(); j++) {
				for (int k = 0; k < right.size(); k++) {
					if (input[i] == '+') res.push_back(left[j] + right[k]);
					else if (input[i] == '-') res.push_back(left[j] - right[k]);
					else res.push_back(left[j] * right[k]);
				}
			}

		}
	}
	if (res.empty()) res.push_back(stoi(input));
	return res;
}