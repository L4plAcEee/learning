#pragma once

struct Set {
    enum Color {
        BLACK,
        RED
    };

    struct Node {
        Node *parent;
        Node *left;
        Node *right;
        Color color;
        int value;
    };
    struct Iterator {
        Node* current;

        Iterator() : current(nullptr){}
        Iterator(Node* node) : current(node){}

        int operator* () {
            return current->value;
        }

        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }

        Iterator& operator++() {
            if (current != nullptr) {
                current = findNext(current);  // 迭代到下一个节点
            }
            return *this;
        }

        Iterator operator++(int) {
            Iterator temp = *this; // 保存当前迭代器的拷贝
            current = findNext(current); // 更新当前节点到下一个节点
            return temp; // 返回拷贝，即自增前的状态
        }

        Node* findNext(Node* node) {
            if(node == nullptr) return nullptr;  // 如果节点为空，直接返回

            if(node->right != nullptr) {
                return minValueNode(node->right);
            }

            Node* parent = node->parent;
            while(parent != nullptr && node == parent->right) {
                node = parent;
                parent = parent->parent;
            }
            return parent;
        }
    };

    Node *root = nullptr;
    Iterator it;

    Set() : it(root) {}

    Iterator end() {
        return Iterator(nullptr);
    }

    Iterator begin() {
        if (root == nullptr) {
            return end();  // 如果根节点为空，直接返回结束迭代器
        }
        return Iterator(minValueNode(root));
    }

    void left_rotate(Node *x) {
        Node *y = x->right;
        x->right = y->left; 

        if(y->left != nullptr) { 
            y->left->parent = x; 
        }

        y->parent = x->parent; 
        if(x->parent == nullptr) {
            root = y; 
        }else if (x == x->parent->left) {
            x->parent->left = y;
        }else {
            x->parent->right = y;
        }

        y->left = x; 
        x->parent = y;
    }

    void right_rotate(Node *y) {
        Node *x = y->left;
        y->left = x->right;
        if (x->right != nullptr) {
            x->right->parent = y;
        }

        x->parent = y->parent;

        if (y->parent == nullptr) {
            root = x;
        }else if (y == y->parent->left) {
            y->parent->left = x;
        }else {
            y->parent->right = x;
        }

        x->right = y;
        y->parent = x;
    }

    void fix_violation(Node *node) {
        Node *parent = nullptr;
        Node *grandparent = nullptr;

        while((node != root) && (node->color == RED) && (node->parent->color == RED)) {
            parent = node->parent;
            grandparent = parent->parent;
            // 两种情况 -- 父节点是祖父节点的 左子节点 or 右子节点
            if(parent == grandparent->left) {
                Node* uncle = grandparent->right; 
                if (uncle != nullptr && uncle->color == RED) {  // 情况 1：叔叔节点是红色
                    grandparent->color = RED;
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    node = grandparent;
                }else { // 情况 2：叔叔节点是黑色
                    if(node == parent->right) { // 情况 2.1：当前节点是右子节点，左旋父节点
                        left_rotate(parent);
                        node = parent;
                        parent = node->parent;
                    }
                    // 情况 2.2：当前节点是左子节点，右旋祖父节点
                    right_rotate(grandparent);
                    parent->color = BLACK;
                    grandparent->color = RED;
                    node = parent; // 更新当前节点为父节点
                }
            }else {
                // 处理为右子树的情况
                Node* uncle = grandparent->left;

                // 情况 1：叔叔节点是红色
                if(uncle != nullptr && uncle->color == RED) {
                    grandparent->color = RED;
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    node = grandparent;
                }else {
                    // 情况 2：叔叔节点是黑色
                    if(node == parent->left) {
                        // 情况 2.1：当前节点是左子节点，右旋父节点
                        right_rotate(parent);
                        node = parent;
                        parent = node->parent;
                    }
                    // 情况 2.2：当前节点是右子节点，左旋祖父节点
                    left_rotate(grandparent);
                    parent->color = BLACK;
                    grandparent->color = RED; 
                    node = parent; // 更新当前节点为父节点
                }
            }
        }
        root->color = BLACK; // 确保根节点始终是黑色
    }

    void printTree(Node *node) {
        if (node == nullptr) return;
        printTree(node->left);
        printf("Node: %d, Parent: %d\n", node->value, node->parent ? node->parent->value : -1);
        printTree(node->right);
    }

    Node* find(int value) {
        Node *current = root;
        while(current != nullptr) {
            if(value < current->value) {
                current = current->left;
                continue;
            }
            if(value > current->value) {
                current = current->right;
                continue;
            }
            break;// if cur->val == val; 
        }
        return current;
    }

    Node* BST_remove(Node* node, int value) {    // 基于二叉搜索树的删除逻辑
        if(node == nullptr) return node;

        if(value < node->value) {
            node->left = BST_remove(node->left, value);
        }else if (value > node->value) {
            node->right = BST_remove(node->right, value);
        }else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // 如果有两个子节点，找到中序后继
            Node* temp = minValueNode(node->right);
            node->value = temp->value;
            node->right = BST_remove(node->right, temp->value);
        }
        return node;
    }

    static Node* minValueNode(Node* node) {
        if (node == nullptr || node == (Node*)0xfeeefeee) {
            std::cerr << "Error: Invalid node pointer passed to minValueNode" << std::endl;
            return nullptr;  // 返回空指针，防止进一步操作
        }

        Node* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    void fix_remove_violation(Node* node) {
        if (node == nullptr) return;

        while (node != root && (node == nullptr || node->color == BLACK)) {
            if (node == node->parent->left) {
                Node* sibling = node->parent->right;
                if (sibling == nullptr) {
                    // 如果兄弟节点为空，我们无法继续修复，直接退出循环
                    break;
                }

                if (sibling->color == RED) {
                    sibling->color = BLACK;
                    node->parent->color = RED;
                    left_rotate(node->parent);
                    sibling = node->parent->right;
                }

                bool leftBlack = (sibling->left == nullptr || sibling->left->color == BLACK);
                bool rightBlack = (sibling->right == nullptr || sibling->right->color == BLACK);
                
                if (leftBlack && rightBlack) {
                    sibling->color = RED;
                    node = node->parent;
                } else {
                    if (rightBlack) {
                        if (sibling->left != nullptr) {
                            sibling->left->color = BLACK;
                        }
                        sibling->color = RED;
                        right_rotate(sibling);
                        sibling = node->parent->right;
                    }
                    sibling->color = node->parent->color;
                    node->parent->color = BLACK;
                    if (sibling->right != nullptr) {
                        sibling->right->color = BLACK;
                    }
                    left_rotate(node->parent);
                    node = root;
                }
            } else {
                Node* sibling = node->parent->left;
                if (sibling == nullptr) {
                    // 如果兄弟节点为空，我们无法继续修复，直接退出循环
                    break;
                }

                if (sibling->color == RED) {
                    sibling->color = BLACK;
                    node->parent->color = RED;
                    right_rotate(node->parent);
                    sibling = node->parent->left;
                }

                bool rightBlack = (sibling->right == nullptr || sibling->right->color == BLACK);
                bool leftBlack = (sibling->left == nullptr || sibling->left->color == BLACK);

                if (leftBlack && rightBlack) {
                    sibling->color = RED;
                    node = node->parent;
                } else {
                    if (leftBlack) {
                        if (sibling->right != nullptr) {
                            sibling->right->color = BLACK;
                        }
                        sibling->color = RED;
                        left_rotate(sibling);
                        sibling = node->parent->left;
                    }
                    sibling->color = node->parent->color;
                    node->parent->color = BLACK;
                    if (sibling->left != nullptr) {
                        sibling->left->color = BLACK;
                    }
                    right_rotate(node->parent);
                    node = root;
                }
            }
        }
        if (node != nullptr) {
            node->color = BLACK;
        }
    }

    bool remove(int value) {
        Node* to_delete = find(value);
        if (to_delete == nullptr) return false;

        Color original_color = to_delete->color;
        Node* replacement;
        Node* parent = to_delete->parent;

        if (to_delete->left == nullptr) {
            replacement = to_delete->right;
            transplant(to_delete, to_delete->right);
        } else if (to_delete->right == nullptr) {
            replacement = to_delete->left;
            transplant(to_delete, to_delete->left);
        } else {
            Node* successor = minValueNode(to_delete->right);
            original_color = successor->color;
            replacement = successor->right;
            
            if (successor->parent == to_delete) {
                if (replacement) replacement->parent = successor;
            } else {
                transplant(successor, successor->right);
                successor->right = to_delete->right;
                successor->right->parent = successor;
            }
            
            transplant(to_delete, successor);
            successor->left = to_delete->left;
            successor->left->parent = successor;
            successor->color = to_delete->color;
        }

        delete to_delete;

        if (original_color == BLACK) {
            fix_remove_violation(replacement);
        }

        return true;
    }

    void transplant(Node* u, Node* v) {
        if (u->parent == nullptr) {
            root = v;
        } else if (u == u->parent->left) {
            u->parent->left = v;
        } else {
            u->parent->right = v;
        }
        if (v != nullptr) {
            v->parent = u->parent;
        }
    }

    bool insert(int value) {
        Node *new_node = new Node;
        new_node->value = value;
        new_node->left = nullptr;
        new_node->right = nullptr;
        new_node->color = RED;

        Node **pp_next = &root;
        Node *parent = nullptr;
        while(*pp_next != nullptr) {
            parent = *pp_next;
            if(value < parent->value) {
                pp_next = &parent->left;
                continue;
            }
            if(value > parent->value) {
                pp_next = &parent->right;
                continue;
            }
            delete new_node;
            return false;// if cur->val == val; 
        }

        new_node->parent = parent;
        *pp_next = new_node;
        fix_violation(new_node);
        // printTree(root);
        // printf("-----\n");
        return true;
    }
};