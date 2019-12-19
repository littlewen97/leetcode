//1282. 用户分组
//有 n 位用户参加活动，他们的 ID 从 0 到 n - 1，每位用户都 恰好 属于某一用户组。给你一个长度为 n 的数组 groupSizes，其中包含每位用户所处的用户组的大小，请你返回用户分组情况（存在的用户组以及每个组中用户的 ID）。
//你可以任何顺序返回解决方案，ID 的顺序也不受限制。此外，题目给出的数据保证至少存在一种解决方案。
//示例 1：
//输入：groupSizes = [3, 3, 3, 3, 3, 1, 3]
//输出： [[5], [0, 1, 2], [3, 4, 6]]
//解释：
//其他可能的解决方案有 [[2, 1, 6], [5], [0, 4, 3]] 和 [[5], [0, 6, 2], [4, 3, 1]] 。


//对于两个用户 x 和 y，如果 groupSize[x] != groupSize[y]，它们用户组的大小不同，那么它们一定不在同一个用户组中
//用一个哈希映射（HashMap）来存储所有的用户。哈希映射中键值对为 (用户组大小, 满足对应用户组大小的所有用户)，这样以来，我们就把所有用户组大小相同的用户都暂时放在了同一个组中
//每次从（对应用户组大小的所有用户） 中取出（用户组大小）个用户，把它们放在一个组中

vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
	unordered_map<int, vector<int>> group;
	vector<vector<int>> res;

	for (int i = 0; i < groupSizes.size(); i++)
		group[groupSizes[i]].push_back(i);

	for (auto& it : group) {
		for (auto curr = it.second.begin(); curr != it.second.end(); curr += it.first)
			res.push_back(vector<int>(curr, curr + it.first));
	}
	return res;
}