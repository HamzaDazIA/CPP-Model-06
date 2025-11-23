#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main() {
    
    Data originalData;
    originalData.i = 42;

    std::cout << "Original Data Value: " << originalData.i << std::endl;
    std::cout << "Original Data Addr:  " << &originalData << std::endl;

    uintptr_t raw = Serializer::serialize(&originalData);
    
    std::cout << "Serialized (Raw):    " << raw << std::endl;

    Data* deserializedPtr = Serializer::deserialize(raw);

    std::cout << "Deserialized Addr:   " << deserializedPtr << std::endl;
    std::cout << "Deserialized Value:  " << deserializedPtr->i << std::endl;

    std::cout << "--------------------------------" << std::endl;
    if (deserializedPtr == &originalData) {
        std::cout << "SUCCESS: Pointers compare equal!" << std::endl;
    } else {
        std::cout << "FAILURE: Pointers are different." << std::endl;
    }
    if (deserializedPtr->i == originalData.i) {
        std::cout << "SUCCESS: Data value preserved." << std::endl;
    } else {
        std::cout << "FAILURE: Data corrupted." << std::endl;
    }

    return 0;
}