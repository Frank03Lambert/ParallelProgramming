#include <iostream>
#include <omp.h>


// demonstate that output is non-deterministic
int main(int argc, char* argv[])
{
#pragma omp parallel
    {
    std::cout << "Hello World!" << std::endl;
    std::cout   << "I am thead "
                    << omp_get_thread_num()
                    << " of " 
                    << omp_get_num_threads()
                    << std::endl; 
    }        
}        