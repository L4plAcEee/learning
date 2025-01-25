#include <iostream>
using namespace std;

enum ops {
    push,
    query,
    __size,
    pop,
    unknow
};

ops get_op() {
    string str;
    cin>>str;
    if(str == "push") return push;
    if(str == "query") return query;
    if(str == "size") return __size;
    if(str == "pop") return pop;
    return unknow;
}

struct Stack {
    struct node {
        int val;
        node *next;
    };
    int size = 0;
    node *dummy_head;
    Stack() {
        dummy_head = new node;
        dummy_head->next = nullptr;
    }
    // ~Stack() { 可能会导致wa 没加上去
    //     while (dummy_head->next) { // 清理所有节点
    //         pop();
    //     }
    //     delete dummy_head; // 删除 dummy_head
    // }
    void push(int val) {
        node *new_node = new node;
        new_node->val = val;
        new_node->next = dummy_head->next;
        dummy_head->next = new_node; 
        size++;
    }
    void pop() {
        if(dummy_head->next == nullptr) {
            cout<<"Empty"<<endl;
            return;
        } 
        node *temp = dummy_head->next;
        dummy_head->next = dummy_head->next->next;
        delete temp; 
        size--;
    }
    void query() {
        if(size == 0) {
            cout<<"Anguei!"<<endl;
            return;
        }
        cout<<dummy_head->next->val<<endl;
    }
    void __size() {
        cout<<size<<endl;
    }
};

int main() {
    int n;
    cin>>n;
    Stack stk;
    while(n--) {
        ops op = get_op();
        int op_num;
        switch(op) {
            case push: 
                cin>>op_num;
                stk.push(op_num);
                break;
            case pop: 
                stk.pop();
                break;
            case __size: 
                stk.__size();
                break;
            case query: 
                stk.query();
                break;
        }
    }
}