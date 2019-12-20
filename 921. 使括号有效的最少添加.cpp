//921. 使括号有效的最少添加
//给定一个由 '(' 和 ')' 括号组成的字符串 S，我们需要添加最少的括号（ '(' 或是 ')'，可以在任何位置），以使得到的括号字符串有效。
//从形式上讲，只有满足下面几点之一，括号字符串才是有效的：
//它是一个空字符串，或者
//它可以被写成 AB （A 与 B 连接）, 其中 A 和 B 都是有效字符串，或者
//它可以被写作 (A)，其中 A 是有效字符串。
//给定一个括号字符串，返回为使结果字符串有效而必须添加的最少括号数。
//示例 1：
//输入："())"
//输出：1

//题目规定LLLLRRRR则结果只为1，而不是LR, LLRR, LLLRRR, LLLLRRR 4种
//设定一个计数器，如果遇到R则加1，遇到L则减1，如果发现为0则将结果加1

//方法一：
int minAddToMakeValid(string S) {
	int n = S.size();
	int temp = 0;
	int res = 0;
	for (int i = 0; i < n; i++) {
		if (S[i] == '(') {
			temp++;
		}
		if (S[i] == ')') {
			if (temp != 0)temp--;
			else res++;
		}

	}
	return temp + res;
}

//方法二：贪心---用一个栈，把配对的括号都拿掉，剩下的就是结果了
int minAddToMakeValid(string S) {
	stack<char> ss;
	for (int i = 0; i < S.size(); i++) {
		if (ss.empty())
			ss.push(S[i]);
		else if (S[i] == ')' && ss.top() == '(')
			ss.pop();
		else
			ss.push(S[i]);
	}
	return ss.size();
}