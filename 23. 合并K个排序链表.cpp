//23. 合并K个排序链表
//合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
//示例:
//输入:
//[
//	1->4->5,
//	1->3->4,
//	2->6
//]
//输出 : 1->1->2->3->4->4->5->6

//合并6个链表，那么按照分治法，首先分别合并0和3，1和4，2和5。这样下一次只需合并3个链表，再合并1和3，最后和2合并就可以了。
//代码中的k是通过 (n+1)/2 计算的，这里为啥要加1呢，这是为了当n为奇数的时候，k能始终从后半段开始，比如当 n=5 时，那么此时 k=3，则0和3合并，1和4合并，最中间的2空出来。
//当n是偶数的时候，加1也不会有影响，比如当 n=4 时，此时 k=2，那么0和2合并，1和3合并

ListNode* mergeKLists(vector<ListNode*>& lists) {
	int len = lists.size();
	while (len > 1) {
		int k = (len + 1) / 2;
		for (int i = 0; i < len / 2; i++) {
			lists[i] = mergeTwo(lists[i], lists[i + k]);
		}
		len = k;
	}
	return lists[0];
}

ListNode* mergeTwo(ListNode* l1, ListNode* l2) {
	ListNode* dummy = new ListNode(-1), * cur = dummy;
	while (l1 && l2) {
		if (l1->val < l2->val) {
			cur->next = l1;
			l1 = l1->next;
		}
		else {
			cur->next = l2;
			l2 = l2->next;
		}
		cur = cur->next;
	}
	if (l1) cur->next = l1;
	if (l2) cur->next = l2;
	return dummy->next;
}