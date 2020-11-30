/*
 * @Author: YuZhe
 * @Date: 2020-09-18 13:49:52
 * @LastEditTime: 2020-09-18 15:23:20
 * @LastEditors: Please set LastEditors
 * @Description: 平安科技笔试
 * @FilePath: \undefinedc:\Users\yuzhe\Desktop\笔试\0918-PingAn.cpp
 */

/* 1.合并两个升序链表 */
#include <iostream>
#include <vector>
#include <algorithm>



struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int v) : val(v),next(nullptr) {}
};


ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode *preHead = new ListNode(-1);
    ListNode *head = preHead;
    while (l1 && l2) {
        if (l1->val <= l2->val) {
            head->next = l1;
            l1 = l1->next;
        }
        else {
            head->next = l2;
            l2 = l2->next;
        }
        head = head->next;
    }
    if (l1) head->next = l1;
    if (l2) head->next = l2;
    return preHead->next;
}


/* 2.给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
注意： 答案中不可以包含重复的四元组，注意输出元组中的元素顺序均为升序，见样例所示。
[1,0,-1,0,-2,2],0
[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
 */
using namespace std;

void backTrack(vector<int> &nums, int prev, vector<int> &path, int target, vector<vector<int>> &res) {
    int n = path.size();
    int sum = 
    if ((n == 4 && sum != target) || n > 4) return;
    if (n == 4 && sum == target) {
        res.push_back(path);
        return;
    }
    for (int i = prev+1; i < nums.size(); ++i) {
        path.push_back(nums[i]);
        backTrack(nums, i, path, target, res);
        path.pop_back();
    }
    return;
}

vector<vector<int> > fourSum(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> path;
    for (int i = 0; i < nums.size(); ++i) {
        path.push_back(nums[i]);
        backTrack(nums, i, path, target, res);
        path.pop_back();
    }
    return res;
}


int main() {
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;
    vector<vector<int>> res = fourSum(nums, target);
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < 4; ++j) cout << res[i][j] << " ";
        cout << endl;
    }
    return 0;
}