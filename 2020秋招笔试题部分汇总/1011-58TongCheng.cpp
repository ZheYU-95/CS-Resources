/*
 * @Author: 于哲
 * @Date: 2020-10-11 13:57:22
 * @LastEditTime: 2020-10-11 15:15:41
 * @LastEditors: Please set LastEditors
 * @Description: 2020-1011 58同城
 * @FilePath: \undefinedc:\Users\yuzhe\Desktop\笔试\1011-58TongCheng.cpp
 */

/* 1. */
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> removeDuplicate(int* array, int arrayLen) {
    unordered_map<int, int> mymap;
    for (int i = 0; i < arrayLen; ++i) {
        if (mymap.count(array[i])) mymap[array[i]] = i;
        else mymap.insert({array[i], i});
    }
    int len = mymap.size();
    vector<int> res;
    vector<int> tmp(arrayLen, 0);
    for (auto& x : mymap) {
        tmp[x.second] = x.first;
    }
    for (int num : tmp) {
        if (!num) continue;
        res.push_back(num);
    }
    return res;
}

int main() {
    int array[] = {1,1,1,2,1};
    vector<int> res = removeDuplicate(array, 5);
    for (int num : res) cout << num << " ";
    return 0;
}