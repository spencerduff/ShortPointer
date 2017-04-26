# ShortPointer
A class that holds an extra 3 bits of data in a pointer

Pointers in C++ only point towards blocks of bytes at the smallest, except for vectors of bools. This means that the 3 least significant bits in each pointer will always be 0's. We can use those 3 bits to store some extra data, in this case, a short with a value from 0-7. I made a class that holds a pointer to your data as well as the ability to access these 3 bits.
