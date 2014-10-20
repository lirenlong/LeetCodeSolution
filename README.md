# My Solutions to LeetCode

当前进度：1/153

### [Clone Graph][1]

拷贝一个图，动态创建堆，返回图起点指针。

### [Rotate Image][2]

顺时针方向旋转一个图片90°，图片切分4块，遍历第四象限的每一个点，4象交换。

需要注意奇数行，偶数行是不同的。对于奇数行，中间十字区域，会被斗转星移两次，所以需要特殊处理。

看[soulmachine/戴方勤][soulmachine1]的题解，思路非常清晰：将矩阵对称翻转，再'撇'对角线翻转。

[1]: https://github.com/rogerAce/LeetCodeSolution/blob/master/src/CloneGraph.cpp
[2]: https://github.com/rogerAce/LeetCodeSolution/blob/master/src/RotateImage.cpp
[soulmachine1]: https://github.com/soulmachine/leetcode