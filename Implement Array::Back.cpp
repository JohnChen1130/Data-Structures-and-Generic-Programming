#include <iostream>
#include <array>
#include <initializer_list> // 確保包含這個標頭檔
#include <algorithm>        // 為 std::copy 提供支持
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

    // 實現 Back() 方法
    T& Back() {
        return data[N - 1]; // 返回最後一個元素的引用
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

int main() {
    Array<int, 5> v = {1, 2, 3, 4, 5};
    std::cout << v << std::endl;       // 輸出 [1, 2, 3, 4, 5]
    std::cout << v.Back() << std::endl; // 輸出 5
    v.Back() = 10;
    std::cout << v << std::endl;       // 輸出 [1, 2, 3, 4, 10]
    return 0;
}
