#include <iostream>
#include <thread>
#include <mutex>
#include <future>
using namespace std;

int fun(shared_future<int> f)
{
	int res = 1;
	int n = f.get();
	for (int i = n; i > 0; i--)
		res *= i;
	cout << "Result is " << res << endl;
	return res;
}

int main()
{
	/// just test
	int x;
	promise<int> p;
	future<int> fu1 = p.get_future();
	shared_future<int>  sf = fu1.share();
	future<int> fu = async(launch::async,fun, sf);
	future<int> fu2 = async(launch::async, fun, sf);
	future<int> fu3 = async(launch::async, fun, sf);
	future<int> fu4 = async(launch::async, fun, sf);
	p.set_value(4);
	
	return 0;
}