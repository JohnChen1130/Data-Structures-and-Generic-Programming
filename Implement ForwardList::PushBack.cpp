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

    // 新增 PushBack 方法
    void PushBack(const T& value) {
        if (IsEmpty()) {
            head_ = new ListNode<T>(value); // 如果是空鏈表，直接新增節點為頭節點
            return;
        }
        auto curr = head_;
        while (curr->next) { // 遍歷直到最後一個節點
            curr = curr->next;
        }
        curr->next = new ListNode<T>(value); // 在最後節點後新增節點
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
    ForwardList<int> a;
    for (int i = 0; i <= 5; ++i) {
        a.PushBack(i * 10);
        std::cout << a << std::endl;
    }
}
