/* The following code example is taken from the book
 * "The C++ Standard Library - A Tutorial and Reference"
 * by Nicolai M. Josuttis, Addison-Wesley, 1999
 *
 * (C) Copyright Nicolai M. Josuttis 1999.
 * Permission to copy, use, modify, sell and distribute this software
 * is granted provided this copyright notice appears in all copies.
 * This software is provided "as is" without express or implied
 * warranty, and with no claim as to its suitability for any purpose.
 */
#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;

void printLists (const list<int>& l1, const list<int>& l2)
{
    cout << "list1: ";
    copy (l1.begin(), l1.end(), ostream_iterator<int>(cout," "));
    cout << endl << "list2: ";
    copy (l2.begin(), l2.end(), ostream_iterator<int>(cout," "));
    cout << endl << endl;
}

void origin_example()
{
    // create two empty lists
    list<int> list1, list2;

    // fill both lists with elements
    for (int i=0; i<6; ++i) {
        list1.push_back(i);
        list2.push_front(i);
    }
    printLists(list1, list2);

    // insert all elements of list1 before the first element with value 3 of list2
    // - find() returns an iterator to the first element with value 3
    list2.splice(find(list2.begin(),list2.end(),  // destination position
                      3),
                 list1);                          // source list
    printLists(list1, list2);

    // move first element to the end
    list2.splice(list2.end(),        // destination position
                 list2,              // source list
                 list2.begin());     // source position
    printLists(list1, list2);

    // sort second list, assign to list1 and remove duplicates
    list2.sort();
    list1 = list2;
    list2.unique();
    printLists(list1, list2);

    // merge both sorted lists into the first list
    list1.merge(list2);
    printLists(list1, list2);
}


void our_example_head_splice()
{
    // create two empty lists
    list<int> list1, list2;

    // fill both lists with elements
    for (int i=0; i<6; ++i) {
        list1.push_back(i);
        list2.push_front(i);
    }
    printLists(list1, list2);

    // list1 to head of list2
    list2.splice(list2.begin(),
                 list1);                          // source list
    printLists(list1, list2);
}

void our_example_inner_splice()
{
    // create two empty lists
    list<int> list1, list2;

    // fill both lists with elements
    for (int i=0; i<6; ++i) {
        list1.push_back(i);
        list2.push_front(i);
    }
    printLists(list1, list2);

    // splice `position` in [`first`, `last`), 2 in [0, 4)
    list<int>::iterator position = list1.begin();
    list<int>::iterator first = list1.begin();
    list<int>::iterator last = list1.begin();
    position++;position++;
    last++;last++;last++;last++;
    list1.splice(position,
                 list1,
                 first,
                 last);                          // source list
    printLists(list1, list2);
}

void our_example_outer_splice()
{
    // create two empty lists
    list<int> list1, list2;

    // fill both lists with elements
    for (int i=0; i<6; ++i) {
        list1.push_back(i);
        list2.push_front(i);
    }
    printLists(list1, list2);

    // splice `position` out [`first`, `last`), 4 in [0, 2)
    list<int>::iterator position = list1.begin();
    list<int>::iterator first = list1.begin();
    list<int>::iterator last = list1.begin();
    position++;position++;position++;position++;
    last++;last++;
    list1.splice(position,
                 list1,
                 first,
                 last);                          // source list
    printLists(list1, list2);
}

int main()
{
    if (true) {
        our_example_outer_splice();
    } else {
        our_example_inner_splice();
        our_example_head_splice();
        origin_example();
    }
}