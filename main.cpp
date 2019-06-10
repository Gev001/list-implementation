#include<iostream>
#include<cassert>
#include"list.cpp"

int main()
{
	list<int>x;
	for (int i = 0; i < 5; ++i)
	{
		x.push_back(i);
	}
	x.print();
	std::cout << std::endl;
	x.pop_front();
	x.print();
	x.pop_back();
	std::cout << std::endl;
	x.print();
	std::cout << "after copy ctor \n";
	list<int>y(x);
	y.print();
	//list<int>m=std::move(x);
	list<int>n;
	n =y;
	std::cout << "\n size= " << n.size() << "\n";
	std::cout << "now call print function for 'n' \n"; n.print();
std::cout<<std::endl;
n.insert(0, 34);
n.print();
std::cout <<std:: endl;
std::cout << "size= " << n.size() << "\n";

}