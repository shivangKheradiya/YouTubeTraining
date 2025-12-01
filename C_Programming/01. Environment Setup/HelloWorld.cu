#include <iostream>
__global__ void hello() {
    printf("Hello, world from GPU!\n");
}

int main() {
    // Launch kernel with 1 block of 1 thread
    hello<<<1,1>>>();
    cudaDeviceSynchronize();
    
    std::cout << "Hello World!" << std::endl;
    return 0;
}