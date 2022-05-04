#pragma once

template <class T>
struct node {
    T data;
    int bf;
    node* l, * r;
};

template <class T>
class AVL {
private:
    node<T>* root;
    bool needs_balance;
    int size;
public:
    AVL() {
        this->root = 0;
        this->needs_balance = false;
        this->size = 0;
    }

    void insert(T data) {
        if (this->root == 0) {
            this->root = make_node(data); 
            return;
        }
        this->_insert(data, this->root);
        this->needs_balance = false;
    }

    void print() {
        _infix(this->root);
        std::cout << '\n';
    }

    void indent() {
        _prefix(this->root, 0);
        std::cout << '\n';
    }
private:
    void _infix(node<T>* root) {
        if (root == 0) return;

        _infix(root->l);
        std::cout << root->data << ' ';
        _infix(root->r);
    }
    void _prefix(node<T>* root, int level) {
        ntabs(level);
        if (root == 0) {
            std::cout << "-\n";
            return;
        }
        std::cout << root->data << '\n';
        _prefix(root->l, level + 1);
        _prefix(root->r, level + 1);
    }
    void ntabs(int n) {
        while (n--)
            std::cout << '\t';
    }
    void _insert(T data, node<T>* &root) {
        if (data > root->data) {
            if (root->r == 0)
                root->r = make_node(data);
            else
                _insert(data, root->r);
            balance(root, data, false);
        }
        else if (data < root->data) {
            if (root->l == 0)
                root->l = make_node(data);
            else
                _insert(data, root->l);
            balance(root, data, true);
        }
        else return;
    }

    node<T>* make_node(T data) {
        node<T>* new_node = new node<T>;
        new_node->data = data;
        new_node->bf = 0;
        new_node->l = new_node->r = 0;
        this->needs_balance = true;

        return new_node;
    }

    void balance(node<T>*& root, T data, bool left) {
        if (!this->needs_balance)
            return;

        if (left) {
            switch (root->bf) {
            case -1:
                root->bf = 0;
                this->needs_balance = false;
                break;
            case 0:
                root->bf = 1;
                break;
            case 1:
                (data < root->l->data) ? this->SRR(root) : this->DRR(root);
                this->needs_balance = false;
            }
        }
        else {
            switch (root->bf) {
            case 1:
                root->bf = 0;
                this->needs_balance = false;
                break;
            case 0:
                root->bf = -1;
                break;
            case -1:
                (data > root->r->data) ? this->SRL(root) : this->DRL(root);
                this->needs_balance = false;
            }
        }
    }

    void SRR(node<T>*& root) {
        node<T>* new_root = root->l;
        root->l = new_root->r;
        new_root->r = root;
        root->bf = new_root->bf = 0;
        root = new_root;
    }

    void SRL(node<T>*& root) {
        node<T>* new_root = root->r;
        root->r = new_root->l;
        new_root->l = root;
        root->bf = new_root->bf = 0;
        root = new_root;
    }

    void DRR(node<T>*& a) {
        node<T>* b, * c;
        b = a->l;
        c = b->r;
        switch (c->bf) {
        case 0:
            a->bf = b->bf = 0;
            break;
        case -1:
            a->bf = 0;
            b->bf = 1;
            break;
        case 1:
            a->bf = -1;
            b->bf = 0;
            break;
        }
        a->l = c->r;
        b->r = c->l;
        c->bf = 0;
        c->l = b;
        c->r = a;
        a = c;
    }

    void DRL(node<T>*& a) {
        node<T>* b, * c;
        b = a->r;
        c = b->l;
        switch (c->bf) {
        case 0:
            a->bf = b->bf = 0;
            break;
        case 1:
            a->bf = -1;
            b->bf = 0;
            break;
        case -1:
            a->bf = 0;
            b->bf = 1;
            break;
        }
        a->r = c->l;
        b->l = c->r;
        c->bf = 0;
        c->l = a;
        c->r = b;
        a = c;
    }
};
