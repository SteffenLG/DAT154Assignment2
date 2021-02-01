#include "pch.h"
#include "CppUnitTest.h"
#include "../Traffic/Point.h"
#include "../Traffic/TrafficLight.h"
#include "../Traffic/TrafficLightStates.h"
#include "../Traffic/Palette.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Ass2UnitTests
{
	TEST_CLASS(PointTest)
	{
	public:
		
		TEST_METHOD(TestPointMultiplication)
		{
			Point p(2.0, 1.0);
			p = p * 2.0;
			Assert::AreEqual(p.x, 4.0);
			Assert::AreEqual(p.y, 2.0);
		}
		TEST_METHOD(TestPointAddition)
		{
			Point p(2.0, 1.0);
			p = p + p;
			Assert::AreEqual(p.x, 4.0);
			Assert::AreEqual(p.y, 2.0);
		}
	};
	TEST_CLASS(TrafficLightTest)
	{
	public:
		TEST_METHOD(TestState)
		{
			TrafficLight light(1, 1, 0);
			Assert::AreEqual(((int)light.GetState()), 5);
			light.SetState(State::GREEN);
			int green = (int)State::GREEN;
			Assert::AreEqual(((int)light.GetState()) , green);
		}
		TEST_METHOD(TestObstruct)
		{
			TrafficLight light(1, 1, 0);
			light.SetState(State::GREEN);
			Assert::AreEqual(light.Obstruct(), false);
			light.SetState(State::REDYELLOW);
			Assert::AreEqual(light.Obstruct(), true);
		}
	};
	TEST_CLASS(Name)
	{
	public:
		TEST_METHOD(TestSomethingBlaBlabla)
		{

		}
	};
}
