#include <bits/stdc++.h>

using namespace std;
// 实现前缀树 Trie 类：
// 分别用 类描述的方式、静态数组的方式 实现

struct treeNode {
    unordered_map<char, treeNode*> map;
    int pass;
    int end; 
    treeNode(){pass = 0, end = 0;}
};

class Trie {
public:
    // 初始化前缀树对象。
    Trie() {
        head = new treeNode();
    }
    ~Trie() {
        deleteTree(head);
    }
    void deleteTree(treeNode* node) {
        if (!node) return;
        for (auto& pair : node->map) {
            deleteTree(pair.second);
        }
        delete node;
    }
    // 将字符串 word 插入前缀树中。
    void insert(string word) {
        treeNode* cur = head;
        for (char &c : word) {
            auto key = cur->map.find(c);
            if (key != cur->map.end()) {
                cur = key->second;
            } else {
                treeNode* newNode = new treeNode();
                cur->map[c] = newNode;
                cur = newNode;
            }
            cur->pass++;
        }
        cur->end++;
    }
    // 返回前缀树中字符串 word 的实例个数。
    int search(string word) {
        treeNode* cur = head;
        for (char &c : word) {
            auto key = cur->map.find(c);
            if (key == cur->map.end()) {
                return 0;  // 路径中断，单词不存在
            }
            cur = key->second;
        }
        return cur->end;
    }
    // 返回前缀树中以 prefix 为前缀的字符串个数
    int prefixNumber(string prefix) {
        treeNode* cur = head;
        for (char &c : prefix) {
            auto key = cur->map.find(c);
            if (key == cur->map.end()) {
                return 0;  // 前缀不存在
            }
            cur = key->second;
        }
        return cur->pass;
    }
    // 从前缀树中移除字符串 word 。
    void remove(string word) {
        if (search(word) == 0) return;  // 单词不存在
        treeNode* cur = head;
        vector<pair<treeNode*, char>> path;  // 记录路径
        for (char &c : word) {
            path.push_back({cur, c});
            cur = cur->map[c];
            cur->pass--;
        }
        cur->end--;
        if (cur->pass == 0) {
            for (auto it = path.rbegin(); it != path.rend(); ++it) {
                treeNode* parent = it->first;
                char c = it->second;
                treeNode* toDelete = parent->map[c];
                parent->map.erase(c);
                delete toDelete;
                if (parent->pass > 0) break;
            }
        }
    }
private:
    treeNode* head;
};

int main() {
    cout << "开始运行 Trie 测试..." << endl;

    Trie trie;

    // 插入单词
    trie.insert("apple");
    trie.insert("apple");
    trie.insert("app");
    trie.insert("applet");
    trie.insert("application");
    trie.insert("banana");
    trie.insert("band");
    trie.insert("bandit");

    // 测试 search
    cout << "search(\"apple\"): " << trie.search("apple") << endl;          // 2
    cout << "search(\"app\"): " << trie.search("app") << endl;              // 1
    cout << "search(\"banana\"): " << trie.search("banana") << endl;        // 1
    cout << "search(\"bandit\"): " << trie.search("bandit") << endl;        // 1
    cout << "search(\"bandana\"): " << trie.search("bandana") << endl;      // 0

    // 测试 prefixNumber
    cout << "prefixNumber(\"app\"): " << trie.prefixNumber("app") << endl;  // 4 ("app", "apple", "applet", "application")
    cout << "prefixNumber(\"ban\"): " << trie.prefixNumber("ban") << endl;  // 3 ("banana", "band", "bandit")
    cout << "prefixNumber(\"bad\"): " << trie.prefixNumber("bad") << endl;  // 0

    // 测试 remove
    trie.remove("apple");  // 第一次删，apple 还有一次
    cout << "search(\"apple\") after 1 remove: " << trie.search("apple") << endl;  // 1
    trie.remove("apple");  // 第二次删完
    cout << "search(\"apple\") after 2 remove: " << trie.search("apple") << endl;  // 0
    cout << "prefixNumber(\"app\") after removing apple: " << trie.prefixNumber("app") << endl;  // 3

    // 删除不存在的词
    trie.remove("apple");  // 不会报错
    trie.remove("bandana");  // 不存在，也不会报错
}
