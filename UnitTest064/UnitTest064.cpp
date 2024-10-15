#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_06.4.cpp"  

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest064)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            const int SIZE = 20;
            int arr[SIZE]{};
            int MIN = -20;
            int MAX = 20;
            int C = 2;

            create(arr, SIZE, MIN, MAX);  
            int result = count(arr, SIZE, C);  
            Assert::AreEqual(8, result);  
        }

        TEST_METHOD(TestMethod2)
        {
            const int SIZE = 20;
            int arr[SIZE]{};
            int MIN = -20;
            int MAX = 20;

            create(arr, SIZE, MIN, MAX);  
            int maxIndex = findMaxIndex(arr, SIZE);  
            double result = mult(arr, SIZE, maxIndex);  
            Assert::AreEqual(0.0, result, 0.00001);  
        }
    };
}
