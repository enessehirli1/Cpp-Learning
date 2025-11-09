#include <iostream>
#include "IntArray.h" // senin sınıfını buradan include edeceğiz

int main()
{
    // 5 elemanlı bir IntArray oluştur
    IntArray arr(5);

    // elemanları doldur
    for (std::size_t i = 0; i < arr.getLength(); ++i)
        arr[i] = static_cast<int>(i + 1); // 1,2,3,4,5

    std::cout << "Initial array: ";
    for (std::size_t i = 0; i < arr.getLength(); ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";

    // başa eleman ekle
    arr.insertAtBeginning(99);
    std::cout << "After insertAtBeginning(99): ";
    for (std::size_t i = 0; i < arr.getLength(); ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";

    // sona eleman ekle
    arr.insertAtEnd(100);
    std::cout << "After insertAtEnd(100): ";
    for (std::size_t i = 0; i < arr.getLength(); ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";

    // ortasına ekle
    arr.insertBefore(77, 3);
    std::cout << "After insertBefore(77, 3): ";
    for (std::size_t i = 0; i < arr.getLength(); ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";

    // bir elemanı sil
    arr.remove(2);
    std::cout << "After remove(2): ";
    for (std::size_t i = 0; i < arr.getLength(); ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";

    // resize küçült
    arr.resize(4);
    std::cout << "After resize(4): ";
    for (std::size_t i = 0; i < arr.getLength(); ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";

    // resize büyüt
    arr.resize(7);
    std::cout << "After resize(7): ";
    for (std::size_t i = 0; i < arr.getLength(); ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";

    // move constructor testi
    IntArray arr2(std::move(arr));
    std::cout << "After move, arr2: ";
    for (std::size_t i = 0; i < arr2.getLength(); ++i)
        std::cout << arr2[i] << " ";
    std::cout << "\n";

    std::cout << "Original arr length after move: " << arr.getLength() << "\n";

    return 0;
}
