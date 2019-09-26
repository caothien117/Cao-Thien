#include <iostream>
#include <memory>
#include <vector>
using namespace std;


class Person
{
public:
	string name;
	shared_ptr<Person> mother;
	shared_ptr<Person> father;
	vector<weak_ptr<Person>> kids; // sử dụng weak_ptr để khử con trỏ lặp
	Person(const string& n, shared_ptr<Person> m = nullptr, shared_ptr<Person> f = nullptr)
	: name(n), mother(m), father(f) 
	{
	}
	/*
	~Person()
	{
		cout << "delete " << endl;
	}
	*/	
};
 
shared_ptr<Person> initFamily(const string& name)
{
	shared_ptr<Person> mom(new Person(name + "'s mon"));
	shared_ptr<Person> dad(new Person(name + "'s dad"));
	shared_ptr<Person> kid(new Person(name, mom, dad));
	mom->kids.push_back(kid);
	dad->kids.push_back(kid);
	
	return kid;
}
 
int main()
{
	shared_ptr<Person> p = initFamily("Nico");
	cout<<p;

}