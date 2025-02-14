#include "pch.h"
#include "CppUnitTest.h"
#include "../DoubleLinkedList/List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DoubleLinkedListTests
{
	TEST_CLASS(DoubleLinkedListTests)
	{
	public:
		TEST_METHOD(DefaultConstructor)
		{
			List<int> list;
			Assert::AreEqual(0, list.First());
			Assert::AreEqual(0, list.Last());
			Assert::AreEqual(0, list.GetLength());
		}

		TEST_METHOD(InitializerListConstructor)
		{
			List<int> list = { -5, 9, 40000, 0, -25122, 2147483647, -2147483647, -400 };
			
			Iterator<int> iter = list.begin();
			Assert::AreEqual(-5, *iter);
			iter++;
			Assert::AreEqual(9, *iter);
			iter++;
			Assert::AreEqual(40000, *iter);
			iter++;
			Assert::AreEqual(0, *iter);
			iter++;
			Assert::AreEqual(-25122, *iter);
			iter++;
			Assert::AreEqual(2147483647, *iter);
			iter++;
			Assert::AreEqual(-2147483647, *iter);
			iter++;
			Assert::AreEqual(-400, *iter);
			Assert::AreEqual(8, list.GetLength());
		}

		TEST_METHOD(PushFront)
		{
			List<int> list;
			list.PushFront(7);
			Assert::AreEqual(7, list.First());
			Assert::AreEqual(7, list.Last());
			Assert::AreEqual(1, list.GetLength());

			list.PushFront(42);
			Assert::AreEqual(42, list.First());
			Assert::AreEqual(7, list.Last());
			Assert::AreEqual(2, list.GetLength());

			list.PushFront(70);
			Assert::AreEqual(70, list.First());
			Assert::AreEqual(42, *(list.begin()++));
			Assert::AreEqual(7, list.Last());
			Assert::AreEqual(3, list.GetLength());
		}

		TEST_METHOD(PushBack)
		{
			List<int> list;
			list.PushBack(100);
			Assert::AreEqual(100, list.First());
			Assert::AreEqual(100, list.Last());
			Assert::AreEqual(1, list.GetLength());

			list.PushBack(200);
			Assert::AreEqual(100, list.First());
			Assert::AreEqual(200, list.Last());
			Assert::AreEqual(2, list.GetLength());

			list.PushBack(300);
			Assert::AreEqual(100, list.First());
			Assert::AreEqual(200, *(list.begin()++));
			Assert::AreEqual(300, list.Last());
			Assert::AreEqual(3, list.GetLength());
		}

		TEST_METHOD(PopFront)
		{
			List<int> list = { 9999999, 1, 2, 3 };

			Assert::IsNotNull(&list);
			Assert::AreEqual(4, list.GetLength());

			Iterator<int> iter = list.begin();
			Assert::AreEqual(9999999, *iter);
			iter++;
			Assert::AreEqual(1, *iter);
			iter++;
			Assert::AreEqual(2, *iter);
			iter++;
			Assert::AreEqual(3, *iter);

			Assert::AreEqual(9999999, list.PopFront());
			Assert::IsNotNull(&list);
			Assert::AreEqual(3, list.GetLength());

			iter = list.begin();
			Assert::AreEqual(1, *iter);
			iter++;
			Assert::AreEqual(2, *iter);
			iter++;
			Assert::AreEqual(3, *iter);

			Assert::AreEqual(1, list.PopFront());
			Assert::IsNotNull(&list);
			Assert::AreEqual(2, list.GetLength());

			iter = list.begin();
			Assert::AreEqual(2, *iter);
			iter++;
			Assert::AreEqual(3, *iter);

			Assert::AreEqual(2, list.PopFront());
			Assert::IsNotNull(&list);
			Assert::AreEqual(1, list.GetLength());

			iter = list.begin();
			Assert::AreEqual(3, *iter);

			Assert::AreEqual(3, list.PopFront());

			Assert::IsNotNull(&list);
			Assert::AreEqual(0, list.GetLength());

			Assert::AreEqual(0, list.PopFront());
		}

		TEST_METHOD(PopBack)
		{
			List<int> list = { 3, 2, 1, 9999999 };

			Assert::IsNotNull(&list);
			Assert::AreEqual(4, list.GetLength());

			Iterator<int> iter = list.begin();
			Assert::AreEqual(3, *iter);
			iter++;
			Assert::AreEqual(2, *iter);
			iter++;
			Assert::AreEqual(1, *iter);
			iter++;
			Assert::AreEqual(9999999, *iter);

			Assert::AreEqual(9999999, list.PopBack());
			Assert::IsNotNull(&list);
			Assert::AreEqual(3, list.GetLength());

			iter = list.begin();
			Assert::AreEqual(3, *iter);
			iter++;
			Assert::AreEqual(2, *iter);
			iter++;
			Assert::AreEqual(1, *iter);

			Assert::AreEqual(1, list.PopBack());
			Assert::IsNotNull(&list);
			Assert::AreEqual(2, list.GetLength());

			iter = list.begin();
			Assert::AreEqual(3, *iter);
			iter++;
			Assert::AreEqual(2, *iter);

			Assert::AreEqual(2, list.PopBack());
			Assert::IsNotNull(&list);
			Assert::AreEqual(1, list.GetLength());

			iter = list.begin();
			Assert::AreEqual(3, *iter);

			Assert::AreEqual(3, list.PopBack());
			Assert::IsNotNull(&list);
			Assert::AreEqual(0, list.GetLength());

			Assert::AreEqual(0, list.PopBack());
		}

		TEST_METHOD(Insert)
		{
			List<int> emptyList;

			Assert::AreEqual(false, emptyList.Insert(0, 1));
			Assert::AreEqual(false, emptyList.Insert(400, 1));

			List<int> list = { 2, 4 };

			Assert::AreEqual(true, list.Insert(1, 0));
			Assert::AreEqual(1, list.First());
			Assert::AreEqual(2, *(list.begin()++));
			Assert::AreEqual(4, list.Last());
			Assert::AreEqual(3, list.GetLength());

			Assert::AreEqual(true, list.Insert(3, 2));
			Assert::AreEqual(1, list.First());
			Assert::AreEqual(2, *(list.begin()++));
			Assert::AreEqual(3, *(list.end()--));
			Assert::AreEqual(4, list.Last());
			Assert::AreEqual(4, list.GetLength());

			Assert::AreEqual(true, list.Insert(5, 4));
			Assert::AreEqual(1, list.First());
			Assert::AreEqual(2, *(list.begin()++));
			Assert::AreEqual(3, *(list.begin()++++)); // incremented twice iterator
			Assert::AreEqual(4, *(list.end()--));
			Assert::AreEqual(5, list.Last());
			Assert::AreEqual(5, list.GetLength());

			Assert::AreEqual(false, list.Insert(4124, 999));
			Assert::AreEqual(1, list.First());
			Assert::AreEqual(2, *(list.begin()++));
			Assert::AreEqual(3, *(list.begin()++++)); // incremented twice iterator
			Assert::AreEqual(4, *(list.end()--));
			Assert::AreEqual(5, list.Last());
			Assert::AreEqual(5, list.GetLength());
		}

		TEST_METHOD(Remove)
		{
			List<int> emptyList;

			Assert::AreEqual(false, emptyList.Remove(400));
			Assert::AreEqual(false, emptyList.Remove(1));
			Assert::AreEqual(false, emptyList.Remove(0));
			Assert::AreEqual(false, emptyList.Remove(-256210));

			List<int> list = { 1, 2, 3, 4, 5 };

			Assert::AreEqual(false, list.Remove(6));
			Assert::AreEqual(false, list.Remove(0));
			Assert::AreEqual(true, list.Remove(5));

			Assert::AreEqual(1, list.First());
			Assert::AreEqual(2, *(list.begin()++));
			Assert::AreEqual(3, *(list.end()--));
			Assert::AreEqual(4, *(list.end()));
			Assert::AreEqual(4, list.GetLength());

			Assert::AreEqual(false, list.Remove(5));

			Assert::AreEqual(true, list.Remove(2));
			Assert::AreEqual(1, list.First());
			Assert::AreEqual(3, *(list.begin()++));
			Assert::AreEqual(4, *(list.end()));
			Assert::AreEqual(3, list.GetLength());

			Assert::AreEqual(false, list.Remove(2));

			Assert::AreEqual(true, list.Remove(1));
			Assert::AreEqual(3, *(list.begin()));
			Assert::AreEqual(4, *(list.end()));
			Assert::AreEqual(2, list.GetLength());
		}

		TEST_METHOD(RemoveAll)
		{
			List<int> emptyList;
			Assert::IsNotNull(&emptyList);

			Assert::AreEqual(0, emptyList.RemoveAll(100));
			Assert::AreEqual(0, emptyList.RemoveAll(1));
			Assert::AreEqual(0, emptyList.RemoveAll(45));

			List<int> list;
			Assert::IsNotNull(&list);
			list.PushBack(1);
			list.PushBack(0);
			list.PushBack(0);
			list.PushBack(1);
			list.PushBack(3);
			list.PushBack(3);
			list.PushBack(3);
			list.PushBack(1);

			Assert::AreEqual(8, list.GetLength());
			Iterator<int> iter = list.begin();
			Assert::AreEqual(1, *iter);
			iter++;
			Assert::AreEqual(0, *iter);
			iter++;
			Assert::AreEqual(0, *iter);
			iter++;
			Assert::AreEqual(1, *iter);
			iter++;
			Assert::AreEqual(3, *iter);
			iter++;
			Assert::AreEqual(3, *iter);
			iter++;
			Assert::AreEqual(3, *iter);
			iter++;
			Assert::AreEqual(1, *iter);

			Assert::AreEqual(3, list.RemoveAll(1));
			Assert::AreEqual(5, list.GetLength());

			iter = list.begin();
			Assert::AreEqual(0, *iter);
			iter++;
			Assert::AreEqual(0, *iter);
			iter++;
			Assert::AreEqual(3, *iter);
			iter++;
			Assert::AreEqual(3, *iter);
			iter++;
			Assert::AreEqual(3, *iter);

			Assert::AreEqual(2, list.RemoveAll(0));
			Assert::AreEqual(3, list.GetLength());

			iter = list.begin();
			Assert::AreEqual(3, *iter);
			iter++;
			Assert::AreEqual(3, *iter);
			iter++;
			Assert::AreEqual(3, *iter);

			Assert::AreEqual(0, list.RemoveAll(999));
			Assert::AreEqual(3, list.GetLength());

			iter = list.begin();
			Assert::AreEqual(3, *iter);
			iter++;
			Assert::AreEqual(3, *iter);
			iter++;
			Assert::AreEqual(3, *iter);

			Assert::AreEqual(3, list.RemoveAll(3));
			Assert::AreEqual(0, list.GetLength());

			Assert::AreEqual(0, list.First());

			// yknow just to make sure i cant remove any 3s that arent there
			// just gotta double triple quadruple quintuple sextuple so on and so forth check
			Assert::AreEqual(0, list.RemoveAll(3));
			Assert::AreEqual(0, list.RemoveAll(3));
			Assert::AreEqual(0, list.RemoveAll(3));
			Assert::AreEqual(0, list.RemoveAll(3));
			Assert::AreEqual(0, list.RemoveAll(3));
			Assert::AreEqual(0, list.RemoveAll(3));
			Assert::AreEqual(0, list.RemoveAll(3));
			Assert::AreEqual(0, list.RemoveAll(3));
			Assert::AreEqual(0, list.RemoveAll(3));
			Assert::AreEqual(0, list.RemoveAll(3));
			Assert::AreEqual(0, list.RemoveAll(3));
			Assert::AreEqual(0, list.RemoveAll(3));
			Assert::AreEqual(0, list.RemoveAll(3));
			Assert::AreEqual(0, list.RemoveAll(3));
			Assert::AreEqual(0, list.RemoveAll(3));
			Assert::AreEqual(0, list.RemoveAll(3));
			Assert::AreEqual(0, list.RemoveAll(3));
			Assert::AreEqual(0, list.RemoveAll(3));
			Assert::AreEqual(0, list.RemoveAll(3));
			Assert::AreEqual(0, list.RemoveAll(3));

		}

		TEST_METHOD(First)
		{
			List<int> emptyList;
			Assert::AreEqual(0, emptyList.First());

			List<int> list = { 1, 9001, 400, 21 };
			Assert::AreEqual(1, list.First());

			list.PopFront();
			Assert::AreEqual(9001, list.First());

			list.PopFront();
			Assert::AreEqual(400, list.First());

			list.PopFront();
			Assert::AreEqual(21, list.First());

			list.PopFront();
			Assert::AreEqual(0, list.First());

			list.PushFront(4);
			Assert::AreEqual(4, list.First());

			list.PushFront(8);
			Assert::AreEqual(8, list.First());

			list.PushBack(2000);
			Assert::AreEqual(8, list.First());
		}

		TEST_METHOD(Last)
		{
			List<int> emptyList;
			Assert::AreEqual(0, emptyList.Last());

			List<int> list = { 1, 21, 400, 9001 };
			Assert::AreEqual(9001, list.Last());

			list.PopBack();
			Assert::AreEqual(400, list.Last());

			list.PopBack();
			Assert::AreEqual(21, list.Last());

			list.PopBack();
			Assert::AreEqual(1, list.Last());

			list.PopBack();
			Assert::AreEqual(0, list.Last());

			list.PushBack(2);
			Assert::AreEqual(2, list.Last());

			list.PushBack(802);
			Assert::AreEqual(802, list.Last());

			list.PushFront(999999);
			Assert::AreEqual(802, list.Last());
		}

		TEST_METHOD(begin)
		{
			List<int> list = { 1, 9001, 400, 21 };
			Assert::AreEqual(1, *list.begin());

			list.PopFront();
			Assert::AreEqual(9001, *list.begin());

			list.PopFront();
			Assert::AreEqual(400, *list.begin());

			list.PopFront();
			Assert::AreEqual(21, *list.begin());

			list.PushFront(4);
			Assert::AreEqual(4, *list.begin());

			list.PushFront(8);
			Assert::AreEqual(8, *list.begin());

			list.PushBack(2000);
			Assert::AreEqual(8, *list.begin());
		}

		TEST_METHOD(end)
		{
			List<int> list = { 1, 21, 400, 9001 };
			Assert::AreEqual(9001, *list.end());

			list.PopBack();
			Assert::AreEqual(400, *list.end());

			list.PopBack();
			Assert::AreEqual(21, *list.end());

			list.PopBack();
			Assert::AreEqual(1, *list.end());

			list.PushBack(2);
			Assert::AreEqual(2, *list.end());

			list.PushBack(802);
			Assert::AreEqual(802, *list.end());

			list.PushFront(999999);
			Assert::AreEqual(802, *list.end());
		}

		TEST_METHOD(Destroy)
		{
			List<int> emptyList;
			emptyList.Destroy();

			Assert::AreEqual(0, emptyList.First());
			Assert::AreEqual(0, emptyList.Last());
			Assert::AreEqual(0, emptyList.GetLength());

			List<int> list = { 9001, 1337, 21, -24, -25, -6523064, -64, 0, 0, 0 };
			list.Destroy();

			Assert::AreEqual(0, list.First());
			Assert::AreEqual(0, list.Last());
			Assert::AreEqual(0, list.GetLength());

			list.PushBack(999999);
			list.PushBack(9);
			list.PushBack(99);
			list.PushBack(999);

			Assert::AreEqual(4, list.GetLength());
			Iterator<int> iter = list.begin();

			Assert::AreEqual(999999, *iter);
			iter++;
			Assert::AreEqual(9, *iter);
			iter++;
			Assert::AreEqual(99, *iter);
			iter++;
			Assert::AreEqual(999, *iter);

			list.Destroy();

			Assert::AreEqual(0, list.First());
			Assert::AreEqual(0, list.Last());
			Assert::AreEqual(0, list.GetLength());
		}
	};
}
