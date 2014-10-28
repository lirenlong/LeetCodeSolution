# My Solutions to LeetCode

当前进度：31/153

### [Clone Graph][1]

拷贝一个图，动态创建堆，返回图起点指针。

使用[广度优先遍历解题][1_0]，使用queue保存今后todo的节点，使用map数据结构保存已经访问过的节点。

使用[深度优先遍历解题][1_1]，使用map数据结构保存已经访问过的节点，使用递归进行深度遍历。

### [Rotate Image][2]

[我的解题][2_0]为顺时针方向旋转一个图片90°，图片切分4块，遍历第四象限的每一个点，4象交换。

需要注意奇数行，偶数行是不同的。对于奇数行，中间十字区域，会被斗转星移两次，所以需要特殊处理。

看[soulmachine/戴方勤的题解][soulmachine1]，思路非常清晰：将矩阵对称翻转，再'撇'对角线翻转。

### [Find Minimum in Rotated Sorted Array][3]

寻找偶一个有序数组中，最小的那个，有序有特殊性，是将一个有序的数组，从某个位置一刀两半，再LR交换重新拼接成的所谓rotated sorted数组。

[题解][3_0]那么只需要找到那个断层即可。

### [Find Minimum in Rotated Sorted Array II][4]

在Find Minimum in Rotated Sorted Array基础上，允许元素是重复的。

I的逻辑基本符合，除了一种情况，就是把重复元素中的某一个作为pixel point的时候，这个时候，num[left]和num[right]相同，所以把这个逻辑填上即可。时间复杂度为O(logn + n) = O(n)。

### [Maximum Product Subarray][5]

动态规划，由于是求最大连续乘积，那么最优子结构是对于当前状态有3个选择：如果当前值是负，与之前最小值乘；如果当前值是正，与之前最大值乘；如果是0，从新开始。

则动态转移方程为：

    dp_max[i]=max(dp_max[i-1]*A[i], dp_min[i-1]*A[i], A[i])
    dp_min[i]=min(dp_min[i-1]*A[i], dp_max[i-1]*A[i], A[i])

### [Reverse Words in a String][6]

使用stl中的strok来以空格切分字串，注意输入是""和" "的情况。[题解][6_0]

### [Add Two Numbers][7]

题目简单，注意进位问题，和两个数字链表长度不一致的情况[即可][7_0]。

### [Add Binary][8]

同[Add Two Numbers][7]题目，学会使用stl解决问题。这里可以用到reverse进行字符串反转，用*string*.insert来向字符串的头部进行添加。[题解][8_0]

### [Balanced Binary Tree][9]

充分利用未来完成的函数，实现合理的递归，看看高富帅的代码比我的简洁多少。

    bool isBalanced (TreeNode* root) {
		return balancedHeight (root) >= 0;
	}
	int balancedHeightGFS (TreeNode* root) {
		if (root == nullptr) return 0; // 终止条件
		int left = balancedHeight (root->left);
		int right = balancedHeight (root->right);
		if (left < 0 || right < 0 || abs(left - right) > 1) return -1; // 剪枝
		return max(left, right) + 1; // 三方合并
	}

[1]: https://oj.leetcode.com/problems/clone-graph/
[1_0]: https://github.com/rogerAce/LeetCodeSolution/blob/master/src/CloneGraph_bf.cpp
[1_1]: https://github.com/rogerAce/LeetCodeSolution/blob/master/src/CloneGraph_df.cpp
[2]: https://oj.leetcode.com/problems/rotate-image/
[2_0]: https://github.com/rogerAce/LeetCodeSolution/blob/master/src/RotateImage.cpp
[soulmachine1]: https://github.com/soulmachine/leetcode
[3]: https://oj.leetcode.com/problems/find-minimum-in-rotated-sorted-array/
[3_0]: https://github.com/rogerAce/LeetCodeSolution/blob/master/src/FindMinimuminRotatedSortedArray.cpp
[4]: https://oj.leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
[5]: https://oj.leetcode.com/problems/maximum-product-subarray/
[6]: https://oj.leetcode.com/problems/reverse-words-in-a-string/
[6_0]: https://github.com/rogerAce/LeetCodeSolution/blob/master/src/Reverse_Words_in_String.cpp
[7]: https://oj.leetcode.com/problems/add-two-numbers/
[7_0]: https://github.com/rogerAce/LeetCodeSolution/blob/master/src/Add_Two_Numbers.cpp
[8]: https://oj.leetcode.com/problems/add-binary/
[8-0]: https://github.com/rogerAce/LeetCodeSolution/blob/master/src/Add_Binary.cpp
[9]: https://oj.leetcode.com/problems/balanced-binary-tree/
[9-0]: https://github.com/rogerAce/LeetCodeSolution/blob/master/src/Balanced_Binary_Tree.cpp
[10]: https://oj.leetcode.com/problems/binary-tree-level-order-traversal/
[11]: https://oj.leetcode.com/problems/binary-tree-level-order-traversal-ii/