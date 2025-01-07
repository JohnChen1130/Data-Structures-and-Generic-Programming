#include <iostream>
#include <array>
#include <ostream>

// 定義模板類 Array
template <typename T, std::size_t N>
class Array {
private:
    std::array<T, N> data; // 使用標準庫中的 std::array 作為底層容器

public:
    // 初始化列表構造函數
    Array(std::initializer_list<T> init) {
        std::copy(init.begin(), init.end(), data.begin());
    }

    // Swap 方法：交換兩個 Array 對象的內容
    void Swap(Array& other) {
        for (std::size_t i = 0; i < N; ++i) {
            std::swap(data[i], other.data[i]);
        }
    }

    // 實現友元函數以支持輸出操作符 <<
    friend std::ostream& operator<<(std::ostream& os, const Array& arr) {
        os << "[";
        for (std::size_t i = 0; i < N; ++i) {
            os << arr.data[i];
            if (i < N - 1) {
                os << ", ";
            }
        }
        os << "]";
        return os;
    }
};

// 主函數
int main() {
    Array<int, 5> a = {3, 4, 1, 5, 2}; // 初始化 Array a
    Array<int, 5> b = {1, 3, 5, 4, 2}; // 初始化 Array b

    // 輸出 a 和 b 的初始內容
    std::cout << a << std::endl; // 輸出 [3, 4, 1, 5, 2]
    std::cout << b << std::endl; // 輸出 [1, 3, 5, 4, 2]

    // 交換 a 和 b 的內容
    a.Swap(b);

    // 再次輸出 a 和 b 的內容
    std::cout << a << std::endl; // 輸出 [1, 3, 5, 4, 2]
    std::cout << b << std::endl; // 輸出 [3, 4, 1, 5, 2]

    // 再次交換回原始內容
    a.Swap(b);

    // 最後輸出 a 和 b 的內容
    std::cout << a << std::endl; // 輸出 [3, 4, 1, 5, 2]
    std::cout << b << std::endl; // 輸出 [1, 3, 5, 4, 2]

    return 0;
}

