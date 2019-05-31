// Syntax of Reference to Pointer

/* Now let us look at how you call the function with ref-to-ptr parameter.
Many C++ developers mistook this type as pointer to reference. 
C++ types are inferred by reading from right to left!.

*/

#include<iostream>
using namespace std;

int g_n = 42;

void example_ref_to_ptr()
{
    int n = 23;
    int* pn = &n;

    std::cout << "example_ref_to_ptr()" << std::endl;

    std::cout << "Before :" << *pn << std::endl; // display 23

    func_ref_to_ptr(pn);

    std::cout << "After :" << *pn << std::endl; // display 42
}

void func_ref_to_ptr(int*& pp)  // C++ types are inferred by reading from right to left!.
{
    pp = &g_n;
}


int main(){
    
      example_ref_to_ptr();
}
