#include <iostream>
#include <stack>
#include <stdexcept>
using namespace std;


template<typename T>
class MyQueue
{
public:
	MyQueue() {}
	~MyQueue() {}

	void push(const T& node);
	T pop();

private:
	stack<T> stack1;
	stack<T> stack2;
};

template<typename T> 
void MyQueue<T>::push(const T& node)
{
	stack1.push(node);
}

template<typename T>
T MyQueue<T>::pop()
{
	if (stack2.size() <= 0)
	{
		while (stack1.size()>0)
		{			
			stack2.push(stack1.top());
			stack1.pop();							
		}
	}
	if (stack2.size() <= 0)
		throw new exception("¶ÓÁÐÎª¿Õ£¡");

	T head = stack2.top();
	stack2.pop();

	return head;
}

int main()
{
	MyQueue<int>  myQueue;

	for (int i = 0; i < 10;i++)
		myQueue.push(i);

	for (int i = 0; i < 10;i++)
		cout << myQueue.pop() << "\t";

	system("pause");
}