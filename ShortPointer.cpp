#include <iostream>
using namespace std;

class ShortPointer{
public:
    ShortPointer(void* pv, short s){
        val = reinterpret_cast<uintptr_t>(pv);
        val |= (s & 0x0000007);
    }
    
    short getShort(){
        return short(val & 0x0000007);
    }
    
    void* getPointer(){
        return reinterpret_cast<void*>(val & 0xffffff8);
    }
    
private:
    uintptr_t val;
};

int main() {
    int *a = new int(42);
    short val = 5;
    
    ShortPointer sp(a, val);
    
    std::cout << "pointer address before: " << a << "\n";
    std::cout << "pointer address in sp: " << sp.getPointer() << "\n";
    
    std::cout << "pointer's value before: " << *a << "\n";
    std::cout << "pointer's value in sp: " << *((int*)sp.getPointer()) << "\n";
    
    std::cout << "val before: " << val << "\n";
    std::cout << "val in sp: " << sp.getShort();
    
	return 0;
}
