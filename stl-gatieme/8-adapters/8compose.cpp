// file: 8compose.cpp
// gcc2.91[o] bcb4[x] vc6[x] 注：compose1() 是GCC独家产品

#include <algorithm>
#include <functional>
#include <ext/functional>
#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

int main(int argc, char const *argv[])
{
	// 将 outite 绑定到 cout，每次对 outite 指派一个元素，就后接一个 " "。
	ostream_iterator<int> outite(cout, " ");

	int ia[] = {2,21,12,7,19,23};
	vector<int> iv(ia, ia+6);

#if 0
	// 欲于每个元素 v 身上执行 (v+2)*3.
	// 注意，for_each() 是 nonmutating algorithm。元素内容不能更改
	// 所以，执行之后 iv 内容不变
	for_each(iv.begin(), iv.end(), compose1(
		bind2nd(multiplies<int>(), 3),
		bind2nd(plus<int>(), 2)
		));
	copy(iv.begin(), iv.end(), outite); // 2 21 12 7 19 23
	cout << endl;

	// 如果像这样，输往另一地点(cout)，是可以的
	transform(iv.begin(), iv.end(), outite, compose1(
		bind2nd(multiplies<int>(), 3),
		bind2nd(plus<int>(), 2)
		));
	cout << endl; // 12 69 42 27 63 75
#endif
	return 0;
}
