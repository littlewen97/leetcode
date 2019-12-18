//快速排序

void quickSort(int[] arr, int left, int right) {
	int pivot = 0;
	if (left < right) {
		pivot = partition(arr, left, right);
		quickSort(arr, left, pivot - 1);
		quickSort(arr, pivot + 1, right);
	}
}


int partition(int[] arr, int left, int right) {
	int key = arr[left];
	while (left < right) {
		while (left < right && arr[right] >= key) 
			right--;

		arr[left] = arr[right];

		while (left < right && arr[left] <= key)
			left++;

		arr[right] = arr[left];
	}
	arr[left] = key;
	return left;
}