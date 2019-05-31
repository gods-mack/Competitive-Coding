// POINTER TO POINTER

#include<iostream>

int g_n = 42;

void example_ptr_to_ptr()
{
    int n = 23;
    int* pn = &n;

    std::cout << "example_ptr_to_ptr()" << std::endl;

    std::cout << "Before :" << *pn << std::endl; // display 23

    func_ptr_to_ptr(&pn);

    std::cout << "After :" << *pn << std::endl; // display 42
}

void func_ptr_to_ptr(int** pp)
{
    *pp = &g_n;
}

int main(){
    
    example_ptr_to_ptr();
    
}
