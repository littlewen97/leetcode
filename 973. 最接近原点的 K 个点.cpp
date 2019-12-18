//973. 最接近原点的 K 个点
//相关标签：堆，排序，分治算法
//我们有一个由平面上的点组成的列表 points。需要从中找出 K 个距离原点 (0, 0) 最近的点。（这里，平面上两点之间的距离是欧几里德距离。）
//你可以按任何顺序返回答案。除了点坐标的顺序之外，答案确保是唯一的。
//示例 1：
//输入：points = [[1, 3], [-2, 2]], K = 1
//输出： [[-2, 2]]
//
//虽然c++提供sort函数，但是这里不用sort函数，而是用快速排序算法。按照x^2+y^2的值进行从小到大的排序，最后取出前k个

vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
	quickSort(points, 0, points.size() - 1);
	return vector<vector<int>>(points.begin(), points.begin() + K);
}

void quickSort(vector<vector<int>>& arr, int left, int right) {
	int pivot = 0;
	if (left < right) {
		pivot = partition(arr, left, right);
		quickSort(arr, left, pivot - 1);
		quickSort(arr, pivot + 1, right);
	}
}
int partition(vector<vector<int>>& arr, int left, int right) {
	vector<int> temp = arr[left];
	int key = distance(arr[left]);
	while (left < right) {
		while (left < right && distance(arr[right]) >= key)
			right--;

		arr[left] = arr[right];

		while (left < right && distance(arr[left]) <= key)
			left++;

		arr[right] = arr[left];
	}
	arr[left] = temp;
	return left;
}

int distance(vector<int> a) {
	return a[0] * a[0] + a[1] * a[1];
}