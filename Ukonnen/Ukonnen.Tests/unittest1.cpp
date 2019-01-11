#include "CppUnitTest.h"
#include "../Ukonnen/suffix_tree.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ukonnen_tests
{		
	TEST_CLASS(suffix_tree_tests)
	{
	public:
		
		TEST_METHOD(one_char_string)
		{
			std::string input{"A"};
			std::string contains_suffix_1{"A"};
			std::string doesnt_contain_suffix_1{"B"};
			std::string doesnt_contain_suffix_2{ "AB" };
			std::string doesnt_contain_suffix_3{ "BA" };
		  
		  suffix_tree tree{ input };
			tree.build();

			Assert::IsTrue(tree.contains(contains_suffix_1));
			Assert::IsFalse(tree.contains(doesnt_contain_suffix_1));
			Assert::IsFalse(tree.contains(doesnt_contain_suffix_2));
			Assert::IsFalse(tree.contains(doesnt_contain_suffix_3));
		}

		TEST_METHOD(simple_no_repetition_string)
		{
			std::string input{ "ABC" };
			std::string contains_suffix_1{ "ABC" };
			std::string contains_suffix_2{ "BC" };
			std::string contains_suffix_3{ "C" };
			std::string doesnt_contain_suffix_1{"A"};
			std::string doesnt_contain_suffix_2{ "AB" };
			std::string doesnt_contain_suffix_3{ "AC" };
			std::string doesnt_contain_suffix_4{ "CBA" };
			std::string doesnt_contain_suffix_5{ "BAC" };

			suffix_tree tree{ input };
			tree.build();

			Assert::IsTrue(tree.contains(contains_suffix_1));
			Assert::IsTrue(tree.contains(contains_suffix_2));
			Assert::IsTrue(tree.contains(contains_suffix_3));

			Assert::IsFalse(tree.contains(doesnt_contain_suffix_1));
			Assert::IsFalse(tree.contains(doesnt_contain_suffix_2));
			Assert::IsFalse(tree.contains(doesnt_contain_suffix_3));
			Assert::IsFalse(tree.contains(doesnt_contain_suffix_4));
			Assert::IsFalse(tree.contains(doesnt_contain_suffix_5));
		}

		TEST_METHOD(repetition_string_last_char_unique)
		{
			std::string input{ "ABCAD" };
			std::string contains_suffix_1{ "ABCAD" };
			std::string contains_suffix_2{ "BCAD" };
			std::string contains_suffix_3{ "CAD" };
			std::string contains_suffix_4{ "AD" };
			std::string contains_suffix_5{ "D" };

			std::string doesnt_contain_suffix_1{ "ABC" };
			std::string doesnt_contain_suffix_2{ "BC" };
			std::string doesnt_contain_suffix_3{ "C" };
			std::string doesnt_contain_suffix_4{ "AB" };
			std::string doesnt_contain_suffix_5{ "ABA" };
			std::string doesnt_contain_suffix_6{ "AC" };
			std::string doesnt_contain_suffix_7{ "AD" };
			std::string doesnt_contain_suffix_8{ "BCD" };
			std::string doesnt_contain_suffix_9{ "DCA" };

			suffix_tree tree{ input };
			tree.build();

			Assert::IsTrue(tree.contains(contains_suffix_1));
			Assert::IsTrue(tree.contains(contains_suffix_2));
			Assert::IsTrue(tree.contains(contains_suffix_3));
			Assert::IsTrue(tree.contains(contains_suffix_4));
			Assert::IsTrue(tree.contains(contains_suffix_5));

			Assert::IsFalse(tree.contains(doesnt_contain_suffix_1));
			Assert::IsFalse(tree.contains(doesnt_contain_suffix_2));
			Assert::IsFalse(tree.contains(doesnt_contain_suffix_3));
			Assert::IsFalse(tree.contains(doesnt_contain_suffix_4));
			Assert::IsFalse(tree.contains(doesnt_contain_suffix_5));
			Assert::IsFalse(tree.contains(doesnt_contain_suffix_6));
			Assert::IsFalse(tree.contains(doesnt_contain_suffix_7));
			Assert::IsFalse(tree.contains(doesnt_contain_suffix_8));
			Assert::IsFalse(tree.contains(doesnt_contain_suffix_9));
		}

		TEST_METHOD(repetition_string_last_char_non_unique)
		{
			std::string input{ "ABCA" };
			std::string contains_suffix_1{ "ABCA" };
			std::string contains_suffix_2{ "BCA" };
			std::string contains_suffix_3{ "CA" };
			std::string contains_suffix_4{ "A" };

			std::string doesnt_contain_suffix_1{"ABC"};
			std::string doesnt_contain_suffix_2{ "BC" };
			std::string doesnt_contain_suffix_3{ "C" };
			std::string doesnt_contain_suffix_4{ "AB" };
			std::string doesnt_contain_suffix_5{ "ABA" };
			std::string doesnt_contain_suffix_6{ "AC" };

			suffix_tree tree{ input };
			tree.build();

			Assert::IsTrue(tree.contains(contains_suffix_1));
			Assert::IsTrue(tree.contains(contains_suffix_2));
			Assert::IsTrue(tree.contains(contains_suffix_3));
			Assert::IsTrue(tree.contains(contains_suffix_4));

			Assert::IsFalse(tree.contains(doesnt_contain_suffix_1));
			Assert::IsFalse(tree.contains(doesnt_contain_suffix_2));
			Assert::IsFalse(tree.contains(doesnt_contain_suffix_3));
			Assert::IsFalse(tree.contains(doesnt_contain_suffix_4));
			Assert::IsFalse(tree.contains(doesnt_contain_suffix_5));
			Assert::IsFalse(tree.contains(doesnt_contain_suffix_6));
		}

	};
}