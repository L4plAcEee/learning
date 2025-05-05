#include <bits/stdc++.h>

class BitSet {
private:
	std::vector<int> v;
public:
	
	BitSet(int num) {
		v.resize(((num + 31)/32));
	}

	void add(int num) {
		v[num/32] |= 1 << (num%32);
	}

	void remove(int num) {
		v[num/32] &= ~(1 << (num%32));
	}

	void reverse(int num) {
		v[num/32] ^= 1 << (num%32);
	}

	bool contains(int num) {
		return ((v[num/32] >> (num%32)) & 1) == 1;
	}
};
// 对数器测试函数
void testBitset(int n, int testTimes) {
    std::cout << "测试开始" << std::endl;

    // 实现的位图结构
    BitSet bitSet(n);
    // 直接用 unordered_set 作为对照组
    std::unordered_set<int> hashSet;

    std::cout << "调用阶段开始" << std::endl;
    srand(time(0)); // 设置随机种子

    for (int i = 0; i < testTimes; i++) {
        double decide = (double)rand() / RAND_MAX;  // 生成 0~1 之间的随机数
        int number = rand() % n;  // 生成 0 ~ n-1 的随机数

        if (decide < 0.333) {
            bitSet.add(number);
            hashSet.insert(number);
        } else if (decide < 0.666) {
            bitSet.remove(number);
            hashSet.erase(number);
        } else {
            bitSet.reverse(number);
            if (hashSet.count(number)) {
                hashSet.erase(number);
            } else {
                hashSet.insert(number);
            }
        }
    }

    std::cout << "调用阶段结束" << std::endl;
    std::cout << "验证阶段开始" << std::endl;

    for (int i = 0; i < n; i++) {
        if (bitSet.contains(i) != (hashSet.count(i) > 0)) {
            std::cout << "出错了!" << std::endl;
        }
    }

    std::cout << "验证阶段结束" << std::endl;
    std::cout << "测试结束" << std::endl;
}

int main() {
    int n = 1000;
    int testTimes = 10000;
    testBitset(n, testTimes);
    return 0;
}