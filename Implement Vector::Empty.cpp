#include <iostream>
#include <vector>

template <typename T>
class Vector {
private:
    std::vector<T> data; 
public:
    
    bool Empty() const {
        return data.empty(); 
    }

    
    void Resize(size_t newSize) {
        data.resize(newSize); 
    }
};


template <typename T>
void Check(const Vector<T>& v) {
    if (v.Empty()) {
        std::cout << "Empty" << std::endl;
    }
}

int main() {
    Vector<int> v;
    Check(v);          
    v.Resize(3);       
    Check(v);         
    v.Resize(0);       
    Check(v);          

    return 0;
}
