#include "pch.h"
#include "CppUnitTest.h"
#include "../DAT154_Assigment2/Point.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Ass2UnitTests
{
	TEST_CLASS(Ass2UnitTests)
	{
	public:
		
		TEST_METHOD(TestPointMultiplication)
		{
			Point p(2.0, 1.0);
			p = p * 2.0;
			Assert::AreEqual(p.x, 4.0);
			Assert::AreEqual(p.y, 2.0);
		}
	};
}
