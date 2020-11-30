/*
 * @Author: your name
 * @Date: 2020-09-11 23:41:58
 * @LastEditTime: 2020-09-12 11:34:59
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \undefinedc:\Users\yuzhe\Desktop\笔试\0912-QiAnXin.cpp
 */
/* 1. 在万圣节的时候，迪普和梅宝去向叔公讨要糖果，已知叔公有 candies.length 包糖果，每包中有一些糖果（candies[i]），叔公给了梅宝一个硬币。
如果梅宝抛的硬币结果是正面(coin[i] = 0)，则梅宝能够得到这包糖果; 是反面（coin[i]=1）则迪普得到这包糖果。
梅宝有个魔法能连续 n 次抛得硬币结果为正面，但是只能使用一次。
请问梅宝最多能得到多少颗糖果
 */


#include <iostream>
#include <vector>
#include <set>
#include <utility>
using namespace std;

int maxCandies(vector<int>& candies, vector<int>& coin, int n) {
    int len = candies.size();
    int sum = 0, l = 0, r = n-1;
    for (int i = l; i <= r; ++i) {
        if (!coin[i]) continue;
        sum += candies[i];
    }
    int maxSum = sum, maxL = l, maxR = r;
    l++; r++;
    for (; r < len; ++r,++l) {
        if (coin[l-1]) sum -= candies[l-1];
        if (coin[r]) sum += (candies[r]);
        if (sum > maxSum) {
            maxSum = sum;
            maxL = l;
            maxR = r;
        }
    }
    // cout << maxL << maxR << " " << maxSum << " ";
    for (int i = 0; i < len; ++i) {
        if (coin[i]) continue;
        // cout << i << " ";
        maxSum += candies[i];
    }
    return maxSum;
}



/* 2. 求最大干净矩形的面积：一个正方形区域(0,0,10,10)，里面有两个矩形(x1,y1,x2,y2)、(x3,y3,x4,y4)被涂污（注：两矩形有可能存在重叠区域）。
现在，还能裁剪出的干净矩形，面职最大能有多大。
0,0,1,1,9,9,10,10     81
4,1,6,9,1,4,9,6       16 */
// https://leetcode-cn.com/problems/maximal-rectangle/
// https://www.nowcoder.com/discuss/507738?source_id=profile_create&channel=666

int getMaxArea(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    int maxArea = 0;
    set<pair<int, int>> points;
    for (int x = 0; x <= 10; ++x) {
        for (int y = 0; y <= 10; ++y) {
            if (x>x1 && y>y1 && x<x2 && y<y2) continue;
            if (x>x3 && y>y3 && x<x4 && y<y4) continue;
            points.insert({x, y});
            
        }
    }

    return maxArea;
}

int main() {
    vector<int> candies = {3,5,7,6,4,2,8,8,15,3};
    vector<int> coin = {1,0,1,0,1,1,1,0,1,0};
    int n = 3;
    cout << maxCandies(candies, coin, n) << endl << endl;


    cout << getMaxArea(0,0,1,1,9,9,10,10) << " " << getMaxArea(4,1,6,9,1,4,9,6) << endl;
}