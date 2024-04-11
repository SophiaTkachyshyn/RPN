#include "pch.h"
#include "CppUnitTest.h"
#include "../RPN/main.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestInfixToPostfix1)
		{
			string expression = "2+2*4/2+3";
			string expected_postfix = "224*2/+3+";
			string actual_postfix = infixToPostfix(expression);
			Assert::AreEqual(expected_postfix, actual_postfix);
		}

		TEST_METHOD(TestInfixToPostfix2)
		{
			string expression = "(2+3)*4-5";
			string expected_postfix = "23+4*5-";
			string actual_postfix = infixToPostfix(expression);
			Assert::AreEqual(expected_postfix, actual_postfix);
		}

		TEST_METHOD(TestEvaluatePostfix)
		{
			string postfix_expression = "224*2/+3+";
			int expected_result = 9;
			int actual_result = evaluatePostfix(postfix_expression);
			Assert::AreEqual(expected_result, actual_result);
		}

		TEST_METHOD(TestEvaluatePostfix2)
		{
			string postfix_expression = "23+4*5-";
			int expected_result = 15;
			int actual_result = evaluatePostfix(postfix_expression);
			Assert::AreEqual(expected_result, actual_result);
		}
	};
}
