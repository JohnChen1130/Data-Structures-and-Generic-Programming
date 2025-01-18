#include <iostream>
#include <vector>

template <typename T>
class Vector {
private:
    std::vector<T> data; // 使用標準庫的 vector 作為內部存儲

public:
    // PushFront 方法：在向量的開頭插入元素
    void PushFront(const T& value) {
        data.insert(data.begin(), value); // 使用 std::vector 的 insert 方法
    }

    // 打印向量內容
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
    Vector<int> a;

    for (int i = 1; i <= 5; i++) {
        a.PushFront(i);            // 將 i 插入向量開頭
        std::cout << a << std::endl; // 印出向量內容
    }

    return 0;
}
