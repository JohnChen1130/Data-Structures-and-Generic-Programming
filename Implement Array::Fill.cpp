#include <iostream>
#include <array>
#include <ostream>

// 定義模板類 Array
template <typename T, std::size_t N>
class Array {
private:
    std::array<T, N> data; // 使用標準庫中的 std::array 作為底層容器

public:
    // 默認構造函數
    Array() = default;

    // Fill 方法：將所有元素設置為指定的值
    void Fill(const T& value) {
        for (std::size_t i = 0; i < N; ++i) {
            data[i] = value;
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
    Array<int, 5> v;   // 宣告一個大小為 5 的 Array
    v.Fill(5);         // 將所有元素設置為 5
    std::cout << v << std::endl; // 輸出 [5, 5, 5, 5, 5]
    v.Fill(0);         // 將所有元素設置為 0
    std::cout << v << std::endl; // 輸出 [0, 0, 0, 0, 0]
    return 0;
}
