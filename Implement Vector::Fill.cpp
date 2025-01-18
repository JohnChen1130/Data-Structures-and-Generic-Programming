#include <iostream>
#include <vector>

template <typename T>
class Vector {
private:
    std::vector<T> data; // 使用標準庫的 vector 作為內部存儲

public:
    // 調整向量大小
    void Resize(size_t newSize) {
        data.resize(newSize); // 使用標準 vector 的 resize 方法
    }

    // 填充向量
    void Fill(const T& value) {
        std::fill(data.begin(), data.end(), value); // 填充整個 vector
    }

    // 印出向量內容
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
    Vector<int> v;

    v.Resize(2);           // 調整大小為 2
    v.Fill(1);             // 所有元素為 1
    std::cout << v << std::endl; // 印出 [1, 1]

    v.Resize(5);           // 調整大小為 5，多出的部分填充為 0
    std::cout << v << std::endl; // 印出 [1, 1, 0, 0, 0]

    v.Fill(5);             // 所有元素為 5
    std::cout << v << std::endl; // 印出 [5, 5, 5, 5, 5]

    return 0;
}
