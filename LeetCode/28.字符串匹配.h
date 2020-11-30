class Solution {
public:
    int strStr(string haystack, string needle) {
        // 建立偏移表
        int hSize = haystack.size();
        int nSize = needle.size();
        unordered_map<char, int> shift;
        for(int i = 0;i < nSize;i++) shift[needle[i]] = nSize - i; // 偏移表的作用是存储每一个在模式串中出现的字符，在模式串中出现的最右位置到尾部的距离+1

        // 遍历
        int i = 0;
        while(i <= hSize - nSize){
            if(haystack.substr(i, nSize) == needle) return i;
            else{
                // 查询substr后的字符的偏移值
                if(i + nSize > hSize - 1) return -1;
                else{
                    if(shift.find(haystack[i + nSize]) != shift.end()){
                        i += shift[haystack[i + nSize]];
                    }
                    else{
                        i += nSize;
                    }
                }
            }
        }

        return -1;
    }
};