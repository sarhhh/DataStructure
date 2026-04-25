#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // 更直观的写法：i 从 0 到倒数第二个
        for (int i = 0; i < nums.size(); i++)
        {
            // j 从 i 的下一个开始，到最后一个
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return {i, j}; // C++11 及以上可以直接用 {} 初始化
                }
            }
        }
        // 如果没找到，返回一个空的或者两个 -1，避免越界
        return {-1, -1};
    }
};

// 【必须有】main 函数，程序入口
int main()
{
    // 测试用例
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    Solution sol;
    vector<int> result = sol.twoSum(nums, target);

    // 打印结果
    cout << "结果: [" << result[0] << ", " << result[1] << "]" << endl;

    // 暂停窗口，防止闪退
    system("pause");
    return 0;
}