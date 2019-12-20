//763. 划分字母区间
//字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一个字母只会出现在其中的一个片段。返回一个表示每个字符串片段的长度的列表。
//示例 1:
//输入: S = "ababcbacadefegdehijhklij"
//输出 : [9, 7, 8]
//解释 :
//	划分结果为 "ababcbaca", "defegde", "hijhklij"。
//	每个字母最多出现在一个片段中。
//	像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。


//使用一个map来存储每个字母最后出现的位置，再次遍历找当前最大end，当遍历到end处时，得出目前字符串的长度


vector<int> partitionLabels(string S) {
	vector<int> res;
	unordered_map<char, int> mymap;
	for (int i = 0; i < S.size(); i++)
		mymap[S[i]] = i;

	int start = 0;
	int end = 0;
	for (int i = 0; i < S.size(); i++) {
		end = max(end, mymap[S[i]]);
		if (i == end) {
			res.push_back(end - start + 1);
			start = i + 1;
		}

	}
	return res;
}