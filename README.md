# My Solutions to LeetCode

当前进度：29/153

### [Clone Graph][1]

拷贝一个图，动态创建堆，返回图起点指针。

使用[广度优先遍历解题][1_0]，使用queue保存今后todo的节点，使用map数据结构保存已经访问过的节点。

使用[深度优先遍历解题][1_1]，使用map数据结构保存已经访问过的节点，使用递归进行深度遍历。

### [Rotate Image][2]

[我的解题][2_0]为顺时针方向旋转一个图片90°，图片切分4块，遍历第四象限的每一个点，4象交换。

需要注意奇数行，偶数行是不同的。对于奇数行，中间十字区域，会被斗转星移两次，所以需要特殊处理。

看[soulmachine/戴方勤的题解][soulmachine1]，思路非常清晰：将矩阵对称翻转，再'撇'对角线翻转。

[1]: https://oj.leetcode.com/problems/clone-graph/
[1_0]: https://github.com/rogerAce/LeetCodeSolution/blob/master/src/CloneGraph_bf.cpp
[1_1]: https://github.com/rogerAce/LeetCodeSolution/blob/master/src/CloneGraph_df.cpp
[2]: https://oj.leetcode.com/problems/rotate-image/
[2_0]: https://github.com/rogerAce/LeetCodeSolution/blob/master/src/RotateImage.cpp
[soulmachine1]: https://github.com/soulmachine/leetcode