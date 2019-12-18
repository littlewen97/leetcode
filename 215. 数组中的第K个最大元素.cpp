//215. 数组中的第K个最大元素
//堆，分治算法
//在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
//示例 1:
//输入: [3, 2, 1, 5, 6, 4] 和 k = 2
//输出 : 5

//快速排序
//核心思想是每次都要先找一个中枢点 Pivot，然后遍历其他所有的数字，像这道题从大往小排的话，
//就把大于中枢点的数字放到左半边，把小于中枢点的放在右半边，这样中枢点是整个数组中第几大的数字就确定了，虽然左右两部分各自不一定是完全有序的，但是并不影响

int findKthLargest(vector<int>& nums, int k) {
	int pivot = 0;
	int left = 0, right = nums.size() - 1;
	while (true) {
		pivot = partition(nums, left, right);
		if (pivot == k - 1) return nums[pivot];
		else if (pivot > k - 1) right = pivot - 1;
		else left = pivot + 1;
	}

}

int partition(vector<int>& arr, int left, int right) {
	int key = arr[left];
	while (left < right) {
		while (left < right && arr[right] <= key) {
			right--;
		}
		arr[left] = arr[right];
		while (left < right && arr[left] >= key) {
			left++;
		}
		arr[right] = arr[left];
	}
	arr[left] = key;
	return left;
}