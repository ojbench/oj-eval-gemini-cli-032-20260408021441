#ifndef PYLIST_H
#define PYLIST_H

#include <iostream>
#include <vector>
#include <memory>

class pylist {
private:
    struct Node {
        bool is_int;
        int val;
        std::vector<pylist> list;
        Node() : is_int(false), val(0) {}
        Node(int v) : is_int(true), val(v) {}
    };
    std::shared_ptr<Node> ptr;

public:
    pylist() : ptr(std::make_shared<Node>()) {}
    pylist(int v) : ptr(std::make_shared<Node>(v)) {}
    
    void append(const pylist &x) {
        ptr->list.push_back(x);
    }

    pylist pop() {
        pylist back = ptr->list.back();
        ptr->list.pop_back();
        return back;
    }

    pylist &operator[](size_t i) {
        return ptr->list[i];
    }

    operator int() const {
        return ptr->val;
    }

    friend std::ostream &operator<<(std::ostream &os, const pylist &ls) {
        if (ls.ptr->is_int) {
            os << ls.ptr->val;
        } else {
            os << "[";
            for (size_t i = 0; i < ls.ptr->list.size(); ++i) {
                if (i > 0) os << ", ";
                os << ls.ptr->list[i];
            }
            os << "]";
        }
        return os;
    }
};

#endif //PYLIST_H
