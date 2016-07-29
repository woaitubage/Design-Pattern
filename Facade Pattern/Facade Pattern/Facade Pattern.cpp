

/*
Intent
Provide a unified interface to a set of interfaces in a subsystem. 
Facade defines a higher-level interface that makes the subsystem easier to use.
*/

#include <iostream>

using namespace std;
//SubSystem 1
class SubSystemone
{
public:
	void MethodOne()
	{
		cout<<"SubSystem 1"<<endl;
	}
};

//Subsystem 2
class SubSystemTwo
{
public:
	void MethodTwo()
	{
		cout<<"SubSystem 2"<<endl;
	}
};


//SubSystemThree
class SubSystemThree
{
public:
	void MethodThree()
	{
		cout<<"SubSystem 3"<<endl;
	}
};

//Facade
class Facade
{
public:
	Facade()
	{
		pOne = new SubSystemone();
		pTwo = new SubSystemTwo();
		pThree = new SubSystemThree();
	}

	void MethodA()
	{
		cout<<"Facade::MethodA"<<endl;
		pOne->MethodOne();
		pTwo->MethodTwo();
	}

	void MethodB()
	{
		cout<<"Facade::MethodB"<<endl;
		pTwo->MethodTwo();
		pThree->MethodThree();
	}

private:
	SubSystemone *pOne;
	SubSystemTwo *pTwo;
	SubSystemThree *pThree;

};


int main()
{
	Facade *pFacade = new Facade();

	pFacade->MethodA();
	pFacade->MethodB();

	system("pause");
	return 0;
}