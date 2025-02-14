#include <iostream>
#include "List.h"
#include "Iterator.h"

int main()
{
    List<int> list;
    list.PushBack(10000000);
    list.PushBack(21420690);
    list.PushFront(10);
    list.PopBack();
    return 0;
}
