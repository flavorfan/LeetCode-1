
https://www.jianshu.com/p/da70ee7da21c


# 调试遇到以下问题
VS中只能存在一个main()函数
在main()函数中执行算法跟网页上缩进不同(强迫症)
树、链表等数据结构构造比较麻烦
测试结果
github

# 目录结构
```
├── CMakeLists.txt  # 顶层CMake配置文件
├── README.md       # 项目说明
├── build           # 构建文件夹
├── doc             # 解释说明，用以整理思路
├── include         # 相关头文件
│   ├── CMakeLists.txt  # CMake配置文件
│   ├── bstree.cc
│   ├── bstree.h        # 二叉树头文件
│   ├── headers.h       # 包含头文件
│   ├── listnode.cc
│   └── listnode.h      # 链表头文件
├── leetcode        # 编译脚本
└── src             # 解答目录
    ├── 0.template.cc       # 解答模板，每次复制改名即可
    ├── CMakeLists.txt      # 解答CMake配置文件
    ├── climbStai
```

## leetcode 脚本

环境基本配置完成了，在src目录下答题，然后调试即可。每次都编译全部解答会很慢，指定target又需要敲很长命令，将这些命令写成脚本即可。

./leetcode maxProfit

## 测试

```c
#include "headers.h"

class Solution
{
  public:
    int climbStairs(int n)
    {
        int ways[] = {1, 1};
        for (int i = 1; i < n; i++)
        {
            int temp = ways[1];
            ways[1] += ways[0];
            ways[0] = temp;
        }
        return ways[1];
    }
};

TEST(climbStairs, climbStairs)
{
    Solution s;
    EXPECT_EQ(s.climbStairs(2), 2);
    EXPECT_EQ(s.climbStairs(3), 3);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
```

# run test 

$ ./leetcode 1.two-sum

```sh
...
+ ./1.two-sum
[==========] Running 1 test from 1 test suite.
[----------] Global test environment set-up.
[----------] 1 test from isValid
[ RUN      ] isValid.isValid_1
[       OK ] isValid.isValid_1 (0 ms)
[----------] 1 test from isValid (0 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test suite ran. (0 ms total)
[  PASSED  ] 1 test.
```