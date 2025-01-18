#include <iostream>
#include <vector>
#include <initializer_list>

template <typename T>
class Vector {
private:
    std::vector<T> data; // 使用標準庫的 vector 作為底層存儲

public:
    // 構造函数，支持初始化列表
    Vector(std::initializer_list<T> init) : data(init) {}

    // 返回第一個元素（可修改版本）
    T& Front() {
        return data.front();
    }

    // 返回第一個元素（只讀版本）
    const T& Front() const {
        return data.front();
    }

    // 返回最後一個元素（可修改版本）
    T& Back() {
        return data.back();
    }

    // 返回最後一個元素（只讀版本）
    const T& Back() const {
        return data.back();
    }

    // 印出向量内容
    friend std::ostream& operator<<(std::ostream& os, const Vector& v) {
        os << "[";
        for (size_t i = 0; i < v.data.size(); ++i) {
            os << v.data[i];
            if (i != v.data.size() - 1) {
                os << ", ";
            }
        }
        os << "]";
        return os;
    }
};

int main() {
    Vector<int> a = {1, 2, 3, 4, 5};
    std::cout << a.Front() << std::endl; // 印出 1
    std::cout << a.Back() << std::endl;  // 印出 5
    a.Front() = 0;                       // 修改第一個元素為 0
    a.Back() = 10;                       // 修改最後一個元素為 10
    std::cout << a << std::endl;         // 印出 [0, 2, 3, 4, 10]
    
    const Vector<int> b = a;             // 定義為 Vector
    std::cout << b.Front() << std::endl; // 印出 0
    std::cout << b.Back() << std::endl;  // 印出 10

    return 0;
}

