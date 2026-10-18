#include "CppUnitTest.h"
#include "pch.h"
#include "../Project/Matrix.h"
#include "../Project/RandomGenerator.h"
#include "../Project/ConstGenerator.h"
#include "../Project/InputGenerator.h"
#include "../Project/Task1Exercise.h"
#include "../Project/Task2Exercise.h"
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
    TEST_CLASS(MatrixConstructors)
    {
    public:
        TEST_METHOD(DefaultIsEmpty)
        {
            Matrix m;
            Assert::AreEqual((size_t)0, m.getRows());
            Assert::AreEqual((size_t)0, m.getColumns());
        }

        TEST_METHOD(SizedMatrixIsZeroFilled)
        {
            Matrix m(3, 4);
            Assert::AreEqual((size_t)3, m.getRows());
            Assert::AreEqual((size_t)4, m.getColumns());
            Assert::AreEqual(0, m[0][0]);
        }
    };

    TEST_CLASS(MatrixCopy)
    {
    public:
        TEST_METHOD(CopyIsDeep)
        {
            Matrix a(2, 2);
            a[0][0] = 1; a[0][1] = 2; a[1][0] = 3; a[1][1] = 4;

            Matrix b = a;
            b[0][0] = 999;

            Assert::AreEqual(1, a[0][0]);
            Assert::AreEqual(999, b[0][0]);
        }

        TEST_METHOD(CopyAssignmentIsDeep)
        {
            Matrix a(2, 2);
            a[0][0] = 1; a[0][1] = 2; a[1][0] = 3; a[1][1] = 4;

            Matrix b;
            b = a;
            b[1][1] = 777;

            Assert::AreEqual(4, a[1][1]);
            Assert::AreEqual(777, b[1][1]);
        }
    };

    TEST_CLASS(MatrixMove)
    {
    public:
        TEST_METHOD(MoveLeavesSourceEmpty)
        {
            Matrix a(2, 2);
            a[0][0] = 42;

            Matrix b = std::move(a);
            Assert::AreEqual(42, b[0][0]);
            Assert::AreEqual((size_t)0, a.getRows());
            Assert::AreEqual((size_t)0, a.getColumns());
        }
    };

    TEST_CLASS(MatrixEquality)
    {
    public:
        TEST_METHOD(EqualMatrices)
        {
            Matrix a(2, 2);
            Matrix b(2, 2);
            Assert::IsTrue(a == b);
            Assert::IsFalse(a != b);
        }

        TEST_METHOD(DifferentValues)
        {
            Matrix a(2, 2);
            Matrix b(2, 2);
            b[0][0] = 1;
            Assert::IsFalse(a == b);
            Assert::IsTrue(a != b);
        }
    };

    TEST_CLASS(Task1Tests)
    {
    public:
        TEST_METHOD(ReplaceOddElements)
        {
            Matrix m(2, 3);
            m[0][0] = 1; m[0][1] = 2; m[0][2] = 3;
            m[1][0] = -4; m[1][1] = 5; m[1][2] = 0;

            RandomGenerator dummyGen(0, 0);
            Task1Exercise task(m, dummyGen);
            Matrix result = task.solve();

            // 1 -> 0, 3 -> 0, 5 -> 0. Четные (-4, 2, 0) остаются.
            Assert::AreEqual(0, result[0][0]);
            Assert::AreEqual(2, result[0][1]);
            Assert::AreEqual(0, result[0][2]);
            Assert::AreEqual(-4, result[1][0]);
            Assert::AreEqual(0, result[1][1]);
            Assert::AreEqual(0, result[1][2]);
        }
    };

    TEST_CLASS(Task2Tests)
    {
    public:
        TEST_METHOD(InsertFirstColumnAfterZeroColumn)
        {
            Matrix m(2, 3);
            m[0][0] = 1; m[0][1] = 0; m[0][2] = 3;
            m[1][0] = 4; m[1][1] = 5; m[1][2] = 6;

            RandomGenerator dummyGen(0, 0);
            Task2Exercise task(m, dummyGen);
            Matrix result = task.solve();

            Assert::AreEqual((size_t)4, result.getColumns());
            // Второй столбец (индекс 1) содержал 0. После него вставился первый столбец (1, 4).
            Assert::AreEqual(1, result[0][2]);
            Assert::AreEqual(4, result[1][2]);
        }
    };
}