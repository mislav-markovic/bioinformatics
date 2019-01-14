#include "CppUnitTest.h"
#include "../Ukonnen/suffix_tree.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ukonnen_tests
{		
	TEST_CLASS(suffix_tree_tests)
	{
	public:



		TEST_METHOD(repepative_2) {
			std::string input{ "ABCDDDDAAABS" };
			input.push_back(suffix_tree::final_char);
			std::string contains_suffix_1{ "ABC" };
			std::string contains_suffix_2{ "ABCD" };
			std::string contains_suffix_3{ "ABCDDDDA" };
			std::string contains_suffix_4{ "DDD" };

			suffix_tree tree{ input };
			tree.build();

			Assert::IsTrue(tree.contains(contains_suffix_1));
			Assert::IsTrue(tree.contains(contains_suffix_2));
			Assert::IsTrue(tree.contains(contains_suffix_3));
			Assert::IsFalse(tree.contains(contains_suffix_4));
		}

		TEST_METHOD(one_char_string)
		{
			std::string input{"A"};
			input.push_back(suffix_tree::final_char);
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
			input.push_back(suffix_tree::final_char);
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
			std::string input{ "ABCABD" };
			input.push_back(suffix_tree::final_char);
			std::string contains_suffix_1{ "ABCABD" };
			std::string contains_suffix_2{ "BCABD" };
			std::string contains_suffix_3{ "CABD" };
			std::string contains_suffix_4{ "ABD" };
			std::string contains_suffix_5{ "BD" };
			std::string contains_suffix_6{ "D" };

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
			Assert::IsTrue(tree.contains(contains_suffix_6));

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
			input.push_back(suffix_tree::final_char);
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

		TEST_METHOD(complex_string_1)
		{
			std::string input{ "abcabxabcd" };
			input.push_back(suffix_tree::final_char);
			std::string contains_suffix_1{ "abcabxabcd" };
			std::string contains_suffix_2{ "bcabxabcd" };
			std::string contains_suffix_3{ "cabxabcd" };
			std::string contains_suffix_4{ "abxabcd" };
			std::string contains_suffix_5{ "bxabcd" };
			std::string contains_suffix_6{ "xabcd" };
			std::string contains_suffix_7{ "abcd" };
			std::string contains_suffix_8{ "bcd" };
			std::string contains_suffix_9{ "cd" };
			std::string contains_suffix_10{ "d" };

			std::string doesnt_contain_suffix_1{ "abcabxabc" };
			std::string doesnt_contain_suffix_2{ "abcabxab" };
			std::string doesnt_contain_suffix_3{ "abcabxa" };
			std::string doesnt_contain_suffix_4{ "abcabx" };
			std::string doesnt_contain_suffix_5{ "ab" };
			std::string doesnt_contain_suffix_6{ "cbd" };

			suffix_tree tree{ input };
			tree.build();

			Assert::IsTrue(tree.contains(contains_suffix_1));
			Assert::IsTrue(tree.contains(contains_suffix_2));
			Assert::IsTrue(tree.contains(contains_suffix_3));
			Assert::IsTrue(tree.contains(contains_suffix_4));
			Assert::IsTrue(tree.contains(contains_suffix_5));
			Assert::IsTrue(tree.contains(contains_suffix_6));
			Assert::IsTrue(tree.contains(contains_suffix_7));
			Assert::IsTrue(tree.contains(contains_suffix_8));
			Assert::IsTrue(tree.contains(contains_suffix_9));
			Assert::IsTrue(tree.contains(contains_suffix_10));

			Assert::IsFalse(tree.contains(doesnt_contain_suffix_1));
			Assert::IsFalse(tree.contains(doesnt_contain_suffix_2));
			Assert::IsFalse(tree.contains(doesnt_contain_suffix_3));
			Assert::IsFalse(tree.contains(doesnt_contain_suffix_4));
			Assert::IsFalse(tree.contains(doesnt_contain_suffix_5));
			Assert::IsFalse(tree.contains(doesnt_contain_suffix_6));
		}

		TEST_METHOD(complex_string_2)
		{
			std::string input{ "cdddcdc" };
			input.push_back(suffix_tree::final_char);
			std::string contains_suffix_1{ "cdddcdc" };
			std::string contains_suffix_2{ "dddcdc" };
			std::string contains_suffix_3{ "ddcdc" };
			std::string contains_suffix_4{ "dcdc" };
			std::string contains_suffix_5{ "dc" };
			std::string contains_suffix_6{ "dc" };
			std::string contains_suffix_7{ "c" };

			std::string doesnt_contain_suffix_1{ "cc" };
			std::string doesnt_contain_suffix_2{ "cd" };
			std::string doesnt_contain_suffix_3{ "ccdc" };
			std::string doesnt_contain_suffix_4{ "cdddcdcc" };
			std::string doesnt_contain_suffix_5{ "cdddcd" };
			std::string doesnt_contain_suffix_6{ "cdddc" };

			suffix_tree tree{ input };
			tree.build();

			Assert::IsTrue(tree.contains(contains_suffix_1));
			Assert::IsTrue(tree.contains(contains_suffix_2));
			Assert::IsTrue(tree.contains(contains_suffix_3));
			Assert::IsTrue(tree.contains(contains_suffix_4));
			Assert::IsTrue(tree.contains(contains_suffix_5));
			Assert::IsTrue(tree.contains(contains_suffix_6));
			Assert::IsTrue(tree.contains(contains_suffix_7));

			Assert::IsFalse(tree.contains(doesnt_contain_suffix_1));
			Assert::IsFalse(tree.contains(doesnt_contain_suffix_2));
			Assert::IsFalse(tree.contains(doesnt_contain_suffix_3));
			Assert::IsFalse(tree.contains(doesnt_contain_suffix_4));
			Assert::IsFalse(tree.contains(doesnt_contain_suffix_5));
			Assert::IsFalse(tree.contains(doesnt_contain_suffix_6));
		}

	};
}