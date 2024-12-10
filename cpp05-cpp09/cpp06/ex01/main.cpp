#include "Serializer.hpp"

int main() {
    Data originalData = {1337, "Leet"};

    uintptr_t raw = Serializer::serialize(&originalData);

    Data* deserializedData = Serializer::deserialize(raw);

    if (deserializedData == &originalData) {
        std::cout << BC "Serialization and deserialization are successful!" R << std::endl;
        std::cout << "Original Data Number: " << BM << originalData.nbr << R << ", Name: " << BM << originalData.name << R << std::endl;
        std::cout << "Deserialized Data Number: " << BM << deserializedData->nbr << R << ", Name: " << BM << deserializedData->name << R << std::endl;
    } else {
        std::cerr << "Serialization and deserialization failed!" << std::endl;
    }

    return 0;
}