#include <iostream>

class A {
public:
	A(int a) {
		this->a = a;
	}
private:
	int a;
};

template <typename T>
class ShortPointer {
public:
	ShortPointer(T pv, short s) {
		val = reinterpret_cast<uintptr_t>(pv);
		val |= (s & 0x7);
	}

	short getShort() {
		return short(val & 0x7);
	}

	T getPointer() {
		if (sizeof(void*) == 4)
			return reinterpret_cast<T>(val & 0xffffff8);
		else
			return reinterpret_cast<T>(val & 0xfffffffffffffff8);
	}

private:
	uintptr_t val;
};

int main() {
	int *a = new int(42);
	short val = 5;

	ShortPointer<int*> sp(a, val);

	std::cout << "sizeof(void*) = " << sizeof(void*) << "\n";
	std::cout << "sizeof(uintptr_t) = " << sizeof(uintptr_t) << "\n";

	std::cout << "pointer address before: " << a << "\n";
	std::cout << "pointer address in sp: " << sp.getPointer() << "\n";

	std::cout << "pointer's value before: " << *a << "\n";
	std::cout << "pointer's value in sp: " << *sp.getPointer() << "\n";

	std::cout << "val before: " << val << "\n";
	std::cout << "val in sp: " << sp.getShort();

	std::cout << "\n\nPrinting A\n";

	A* a1 = new A(7);

	ShortPointer<A*> sp2(a1, 3);

	std::cout << sp2.getPointer(); 
	std::cout << "\n" << sp2.getShort();

	return 0;
}