class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end()); //去重
        if(wordSet.count(endWord) == 0) return 0;//list中没有要查找单词

        unordered_set<string> upTodown({beginWord});
        unordered_set<string> downToup({endWord});
        int word_size = beginWord.size();
        int list_size = wordList.size();
        vector<int> flag(list_size, 0);//标记是否已经找到过 避免形成环
        int res = 2;
        while(!upTodown.empty()){
            unordered_set<string> next;//下一层元素
            for(auto& word : upTodown){
                for(int i=0; i<list_size; ++i){//在list中找差一个字母的单词
                    int count = 0;
                    for(int j=0; j<word_size; ++j){
                        if(word[j] != wordList[i][j]) count++;
                        if(count > 1) break;
                    }
                    if(count == 1){//只差一个字母
                        if(downToup.count(wordList[i]) != 0) return res;//该单词在从下至上 有了 返回结果
                        if(flag[i] == 0) next.insert(wordList[i]);//没用过的再添加
                        flag[i] = 1;
                    }
                } 
            }
            res++;
            upTodown = next;
            if(upTodown.size() > downToup.size()) swap(upTodown, downToup);//双bfs 每次从元素少的开始找
        }
        return 0;
    }
};