#include <iostream>

using namespace std;


/*
 *正常析构函数修饰符都是public，此时才能保证编译器自动析构对象
 *例外：
 *    若类A被其他对象继承时，此时类A的析构函数的修饰符可设置为protected，但此时类A不能有自己的对象存在
 *    若使用静态变量的方式将类变成单例模式，此时该类的析构函数的修饰符还可以设置为private，虽然不知道为什么，
 *    	此时只能理解为存储空间不同，导致编译器对类对象的析构函数的解释不同
 */

class A{
protected:
	A(){}
	~A(){cout<<"father"<<endl;}
};

class B : public A {
public:
	B(){}
	~B(){cout<<"child"<<endl;}	
};

int main(){
	//A a;
	B b;
	return 0;
}
