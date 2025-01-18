#include <iostream>
#include <vector>
#include <initializer_list>

template <typename T>
class Vector {
private:
    std::vector<T> data; // 使用標準庫的 vector 作為底層存儲

public:
    // 支援初始化列表構造函數
    Vector(std::initializer_list<T> init) : data(init) {}

    // Swap 方法：交換兩個向量的內容
    void Swap(Vector& other) {
        data.swap(other.data); // 使用 std::vector 的 swap 方法
    }

    // 輸出向量內容
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

int main() 
{
    Vector<int> a = {1, 2, 3, 4, 5};
    Vector<int> b = {4, 3, 2, 1};

    std::cout << a << std::endl; // 印出 [1, 2, 3, 4, 5]
    std::cout << b << std::endl; // 印出 [4, 3, 2, 1]

    a.Swap(b); // 交換 a 和 b 的內容
    std::cout << a << std::endl; // 印出 [4, 3, 2, 1]
    std::cout << b << std::endl; // 印出 [1, 2, 3, 4, 5]

    a.Swap(b); // 再交換回來
    std::cout << a << std::endl; // 印出 [1, 2, 3, 4, 5]
    std::cout << b << std::endl; // 印出 [4, 3, 2, 1]

    return 0;
}
