#include <iostream>
using namespace std;

template <typename T>
struct ListNode {
    T value;
    ListNode* next;
    ListNode(T value) : value(value), next(nullptr) {}
};

template <typename T>
class ForwardList {
    template <typename T1>
    friend ostream& operator<<(ostream&, const ForwardList<T1>&);

   public:
    ForwardList() : head_(nullptr) {}
    ~ForwardList() {
        while (!IsEmpty()) {
            PopFront();
        }
    }
    ForwardList(const ForwardList<T>& other) {
        ListNode<T> temp(T{});
        auto insertAt = &temp;
        for (auto copyFrom = other.head_; copyFrom; copyFrom = copyFrom->next) {
            insertAt->next = new ListNode<T>(copyFrom->value);
            insertAt = insertAt->next;
        }
        head_ = temp.next;
    }
    ForwardList(const initializer_list<T>& values) {
        ListNode<T> temp(T{});
        auto insertAt = &temp;
        for (const auto& v : values) {
            insertAt->next = new ListNode<T>(v);
            insertAt = insertAt->next;
        }
        head_ = temp.next;
    }
    ForwardList<T>& operator=(ForwardList<T>& other) {
        if (&other == this) return *this;
        auto newList = other;
        swap(head_, newList.head_);
        return *this;
    }
    bool IsEmpty() const { return head_ == nullptr; }
    void PopFront() {
        auto temp = head_;
        head_ = head_->next;
        delete temp;
    }
    void PushFront(const T& value) {
        auto temp = head_;
        head_ = new ListNode<T>(value);
        head_->next = temp;
    }

    // 新增 Back 方法
    T& Back() {
        auto curr = head_;
        while (curr->next) { // 遍歷直到最後一個節點
            curr = curr->next;
        }
        return curr->value; // 返回最後節點的值（非 const 引用）
    }

    const T& Back() const {
        auto curr = head_;
        while (curr->next) { // 遍歷直到最後一個節點
            curr = curr->next;
        }
        return curr->value; // 返回最後節點的值（const 引用）
    }

   private:
    ListNode<T>* head_;
};

template <typename T>
ostream& operator<<(ostream& os, const ForwardList<T>& l) {
    os << '[';
    for (auto curr = l.head_; curr; curr = curr->next) {
        os << curr->value;
        if (curr->next) {
            cout << ", ";
        }
    }
    return os << ']';
}

// 在不修改 main 的情況下合理達到預期的結果
int main() {
    ForwardList<int> a = {10, 20, 30, 40, 50};
    const ForwardList<int> b = {10, 20, 30};
    ForwardList<int> c = {10};

    std::cout << a.Back() << std::endl; // 預期輸出 50
    a.Back() = 60;
    std::cout << a.Back() << std::endl; // 預期輸出 60
    std::cout << b.Back() << std::endl; // 預期輸出 30
    std::cout << c.Back() << std::endl; // 預期輸出 10
}
