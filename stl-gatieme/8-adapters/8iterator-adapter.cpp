// file: 8iterator-adapter.cpp

#include <iterator>
#include <deque>
#include <algorithm>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	// 将 outite 绑定到 cout，每次对 outite 指派一个元素，就后接一个 " "。
	ostream_iterator<int> outite(cout, " ");

	int ia[] = {0,1,2,3,4,5};
	deque<int> id(ia, ia+6);

	// 将所有元素拷贝到 outite （那么也就是拷贝到 cout）
	copy(id.begin(), id.end(), outite); // 输出 0 1 2 3 4 5
	cout << endl;

	// 将 ia[] 的部分元素拷贝到 id 内，使用 front_insert_iterator。
	// 注意，front_insert_iterator 会将 assign 操作改为 push_front 操作
	// vector 不支持 push_front()，这就是本例不以 vector 为示范对象的原因
	copy(ia+1, ia+2, front_inserter(id));
	copy(id.begin(), id.end(), outite); // 1 0 1 2 3 4 5
	cout << endl;

	// 将 ia[] 的部分元素拷贝到 id 内，使用 back_insert_iterator。
	copy(ia+3, ia+4, back_inserter(id));
	copy(id.begin(), id.end(), outite); // 1 0 1 2 3 4 5 3
	cout << endl;

	// 搜寻元素 5 所在位置
	deque<int>::iterator ite = find(id.begin(), id.end(), 5);

	// 将 ia[] 的部分元素拷贝到 id 内，使用 insert_iterator。
	copy(ia+0, ia+3, inserter(id, ite));
	copy(id.begin(), id.end(), outite); // 1 0 1 2 3 4 0 1 2 5 3
	cout << endl;

	// 将所有元素逆向拷贝到 outite
	// rbegin() 和 rend() 与 reverse_iterator 有关，见稍后源代码说明
	copy(id.rbegin(), id.rend(), outite); // 3 5 2 1 0 4 3 2 1 0 1
	cout << endl;

	if(0) {
		// 以下，将 intie 绑定到 cin。将元素拷贝到 intie，直到 eos 出现
		istream_iterator<int> inite(cin), eos;
		copy(inite, eos, inserter(id, id.begin()));
		// 由于很难在键盘上直接输入 end-of-stream(end-of-file)符号
		// （而且不同的系统的 eof 符号也不尽相同），因此，为了让上一行顺利执行，
		// 请单独取出此一段落为一个独立程序，并准备一个文件，例如 int.dat，内置
		// 32 26 99（自由格式），并在 console 之下利用 piping 方式执行该程序，如下：
		// c:\>type int.data | thisprog
		// 意思是将 type int.dat 的结果作为 thisprog 的输入
		copy(id.rbegin(), id.rend(), outite);
		cout << endl;
	}

	return 0;
}
