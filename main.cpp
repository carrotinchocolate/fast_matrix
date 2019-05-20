#include <iostream>
#include <vector>

#include "matrix.h"
#include "profile.h"

#define ASSERT_EQUAL(x, y)                                         \
    if ((x) != (y))                                                \
    {                                                              \
        std::cerr << "Assertion failed. File: " << __FILE__        \
            << " Line: " << __LINE__ << " "                        \
            << x << " != " << y << " ("                            \
            << #x << " != " << #y << ")" << std::endl;             \
        fails_count++;                                             \
    }

void TestMatrix()
{
    std::cerr << "----------------------" << std::endl;
    int fails_count = 0;
    Matrix test(2, 2);

    ASSERT_EQUAL(test.GetValue(0, 0), 0);
    ASSERT_EQUAL(test.GetValue(0, 1), 0);
    ASSERT_EQUAL(test.GetValue(1, 0), 0);
    ASSERT_EQUAL(test.GetValue(1, 1), 0);

    if (fails_count == 0)
    {
        std::cerr << "TestMatrix: OK" << std::endl;
    }
    else
    {
        std::cerr << "TestMatrix fails. fails_count = " << fails_count << std::endl;
    }
    std::cerr << "----------------------" << std::endl;
}

void TestGetHeight()
{
    std::cerr << "----------------------" << std::endl;
    int fails_count = 0;

    Matrix test(2, 2);
    ASSERT_EQUAL(test.GetHeight(), 2);

    if (fails_count == 0)
    {
        std::cerr << "TestGetHeight: OK" << std::endl;
    }
    else
    {
        std::cerr << "TestGetHeight fails. fails_count = " << fails_count << std::endl;
    }
    std::cerr << "----------------------" << std::endl;
}
void TestGetWidth()
{
    std::cerr << "----------------------" << std::endl;
    int fails_count = 0;

    Matrix test(2, 2);
    ASSERT_EQUAL(test.GetWidth(), 2);

    if (fails_count == 0)
    {
        std::cerr << "TestGetWidth: OK" << std::endl;
    }
    else
    {
        std::cerr << "TestGetWidth fails. fails_count = " << fails_count << std::endl;
    }
    std::cerr << "----------------------" << std::endl;
}

void TestGetValue()
{
    std::cerr << "----------------------" << std::endl;
    int fails_count = 0;

    Matrix test(2, 2);
    ASSERT_EQUAL(test.GetValue(0, 0), 1);

    if (fails_count == 0)
    {
        std::cerr << "TestGetValue: OK" << std::endl;
    }
    else
    {
        std::cerr << "TestGetValue fails. fails_count = " << fails_count << std::endl;
    }
    std::cerr << "----------------------" << std::endl;
}

void TestSetValue()
{
    std::cerr << "----------------------" << std::endl;
    int fails_count = 0;

    Matrix test(3, 3);
    test.SetValue(4, 11, 9);
    ASSERT_EQUAL(test.GetValue(4, 11), 9);

    if (fails_count == 0)
    {
        std::cerr << "TestSetValue: OK" << std::endl;
    }
    else
    {
        std::cerr << "TestSetValue fails. fails_count = " << fails_count << std::endl;
    }
    std::cerr << "----------------------" << std::endl;
}

void TestTranspose()
{
    std::cerr << "----------------------" << std::endl;
    int fails_count = 0;

    Matrix test(2, 2);
    test.SetValue(0, 2, 1);
    test.SetValue(0, 3, 4);
    test.SetValue(5, 0, 3);
    test.SetValue(6, 1, 4);

    test = test.Transpose();
    ASSERT_EQUAL(test.GetValue(3, 0), 4);
    ASSERT_EQUAL(test.GetValue(1, 6), 4);

    if (fails_count == 0)
    {
        std::cerr << "TestTranspose: OK" << std::endl;
    }
    else
    {
        std::cerr << "TestTranspose fails. fails_count = " << fails_count << std::endl;
    }
    std::cerr << "----------------------" << std::endl;
}

void TestOperator*()
{
    std::cerr << "----------------------" << std::endl;
    int fails_count = 0;

    Matrix test1(2, 2);
    test1.SetValue(0, 0, 1);
    test1.SetValue(0, 1, 2);
    test1.SetValue(5, 0, 1);
    test1.SetValue(6, 3, 1);

    Matrix test2(2, 2);
    test2.SetValue(0, 0, 2);
    test2.SetValue(0, 1, 3);
    test2.SetValue(1, 0, 4);
    test2.SetValue(2, 2, 8);

    Matrix test_res = test1 * test2;
    ASSERT_EQUAL(test_res.GetValue(0, 0), 32);
    ASSERT_EQUAL(test_res.GetValue(0, 1), 23);
    ASSERT_EQUAL(test_res.GetValue(1, 0), 26);
    ASSERT_EQUAL(test_res.GetValue(1, 1), 21);

    if (fails_count == 0)
    {
        std::cerr << "TestOperator*: OK" << std::endl;
    }
    else
    {
        std::cerr << "TestOperator* fails. fails_count = " << fails_count << std::endl;
    }
    std::cerr << "----------------------" << std::endl;
}

int main()
{
    TestMatrix();
    TestGetHeight();
    TestGetWidth();
    TestGetValue();
    TestSetValue();
    TestTranspose();
    TestOperator*();

    int matrix_height = 0;
    int matrix_width = 0;

    std::cin >> matrix_height >> matrix_width;
    Matrix matrix1(matrix_height, matrix_width);
    std::cin >> matrix1;

    std::cin >> matrix_height >> matrix_width;
    Matrix matrix2(matrix_height, matrix_width);
    std::cin >> matrix2;

    Matrix res = matrix1 * matrix2;
    std::cout << res << std::endl;

    return 0;
}

