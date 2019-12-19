//1221. 分割平衡字符串
//在一个「平衡字符串」中，'L' 和 'R' 字符的数量是相同的。
//给出一个平衡字符串 s，请你将它分割成尽可能多的平衡字符串。
//返回可以通过分割得到的平衡字符串的最大数量。
//示例 1：
//输入：s = "RLRRLLRLRL"
//输出：4
//解释：s 可以分割为 "RL", "RRLL", "RL", "RL", 每个子字符串中都包含相同数量的 'L' 和 'R'。

//题目规定LLLLRRRR则结果只为1，而不是LR, LLRR, LLLRRR, LLLLRRR 4种
//设定一个计数器，如果遇到R则加1，遇到L则减1，如果发现为0则将结果加1

int balancedStringSplit(string s) {
	int res = 0;
	int temp = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'R')
			temp++;
		if (s[i] == 'L')
			temp--;
		if (temp == 0)
			res++;
	}

	return res;
}