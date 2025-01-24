#include <iostream>
#include <utility> // 為了使用 std::swap

// 不能更動已有的函式
template<typename T>
class Vector {
public:
    Vector() = default;
    Vector(const std::initializer_list<T>& l) {
        size_t i = 0;
        for (const T & v : l) {
            Resize(i+1);
            elems_[i] = v;
            i++;
        }
        size_ = i;
    }
    explicit Vector(size_t n) {    // 備註: 加上 explicit 避免發生隱性轉型
        elems_ = new T[n]{}; // 備註: {} 預設會歸零
        size_ = n;
    }
    ~Vector() {
        delete[] elems_;
    }
    Vector(const Vector<T> & rhs) {
        elems_ = new T[rhs.size_];
        size_ = rhs.size_;
        for (size_t i = 0; i < size_; i++) {
            elems_[i] = rhs.elems_[i];
        }
    }
    Vector<T> & operator=(const Vector<T> & rhs) {
        if (this == &rhs) return *this;   // 當自己賦值給自己時不處理直接回傳
        delete[] elems_;
        elems_ = new T[rhs.size_];
        size_ = rhs.size_;
        for (size_t i = 0; i < size_; i++) {
            elems_[i] = rhs.elems_[i];
        }
        return *this;
    }
    T & operator[](size_t n) {
        return elems_[n];
    }          
    void Resize(size_t n) {
        T * newElems = new T[n]{}; // 預設都歸零
        for (size_t i = 0; i < n && i < size_; i++) {
            newElems[i] = elems_[i];
        }
        delete[] elems_;
        elems_ = newElems;
        size_ = n;
    }  
    const T & operator[](size_t n) const {
        return elems_[n];
    }  
    size_t Size() const {
        return size_;
    }  

    // 新增 Swap 方法
    void Swap(Vector<T>& other) {
        std::swap(this->elems_, other.elems_); // 交換內部指標
        std::swap(this->size_, other.size_);   // 交換大小
    }

private:
    size_t size_ = 0;
    T * elems_ = nullptr;
};

template<typename T>
std::ostream & operator<<(std::ostream & os, const Vector<T> & v) {
    if (v.Size() == 0) return os << "[]";
    os << '[' << v[0];
    for (size_t i = 1; i < v.Size(); i++) {
        os << ", " << v[i];
    }
    return os << ']';
}

int main() {
    Vector<int> a = {1, 2, 3, 4, 5};
    Vector<int> b = {4, 3, 2, 1};
    std::cout << a << std::endl; // 印出 [1, 2, 3, 4, 5]
    std::cout << b << std::endl; // 印出 [4, 3, 2, 1]
    a.Swap(b);
    std::cout << a << std::endl; // 印出 [4, 3, 2, 1]
    std::cout << b << std::endl; // 印出 [1, 2, 3, 4, 5]
    a.Swap(b);
    std::cout << a << std::endl; // 印出 [1, 2, 3, 4, 5]
    std::cout << b << std::endl; // 印出 [4, 3, 2, 1]
}
