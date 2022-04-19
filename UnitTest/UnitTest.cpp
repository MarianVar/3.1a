#include "pch.h"
#include "CppUnitTest.h"
#include "../3.1a/3.1a.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int N = 1;
			Student* s = new Student[N];
			string lastname = "Varhomij";
			s->prizv = "Varhomij";
			s->cours = 2;
			s->spec = "it";
			s->physic = 5;
			s->informatic = 5;
			s->math = 5;
			Excellent(s, N);
			Assert::IsTrue(Excellent(s, N) >= 0.0);
		}
	};
}
