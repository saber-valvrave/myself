#include <iostream>
#include <sstream>

using namespace std;

/*
 *转换多个对象时，输入多个要转换的对象时，注意每个对象以空格分隔，不然会合并到一起转换为一个值
 *此时转换将不是所期望的结果 🔐
 */

int main(){

	string a = "10";
	string b = "20";
	string c = "30";

	int i = 0;
	int j = 0;
	int k = 0;

	stringstream conv;
	conv << a <<" " << b << " " << c;

	conv >> i >> j >> k;


	cout <<i<<endl;
	cout <<j<<endl;
	cout <<k<<endl;

	return 0;
}

