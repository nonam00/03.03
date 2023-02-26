#include <iostream>
#include <vector>

class Person
{

public:

	Person() : Person("", 0) {}
	Person(std::string _name, int _age) :name{ _name }, age{ _age } {}

	virtual void sayHi()
	{
		std::cout << name << " " << age << std::endl;
	}

protected:

	std::string name;
	int age;
};

class Employer : public Person
{
public:

	Employer() : Person("", 0) {}
	Employer(std::string _name, int _age) : Person(_name, _age) {}

	void sayHi() override
	{
		std::cout << "Employer" << std::endl;
	}
};

class Supplier : public Person
{
public:

	Supplier() : Person("", 0) {}
	Supplier(std::string _name, int _age) : Person(_name, _age) {}

	void sayHi() override
	{
		std::cout << "Supplier" << std::endl;
	}
};

class Client : public Person
{
public:

	Client() : Person("", 0) {}
	Client(std::string _name, int _age) : Person(_name, _age) {}

	void sayHi() override
	{
		std::cout << "Client" << std::endl;
	}
};


int main()
{

	Employer employer("name", 3);
	employer.sayHi();

	Client client("name", 1);
	client.sayHi();

	Supplier supplier("name", 2);
	supplier.sayHi();

	std::cout << std::endl;

	std::vector<Person> vec{ employer, client, supplier };
	
	for (auto item : vec)
	{
		item.sayHi();
	}
	return 0;
}