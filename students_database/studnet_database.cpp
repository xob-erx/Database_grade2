#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include<sstream>
using namespace std;
//定义学生 
class student
{
public:
	long long stuID;//学号
	string name;//姓名 
	string sex;//性别 
	int age;//年龄 
	string major;//专业 
	int reward_began;//奖励开始 
	int reward_len;//奖励长度 
};
//学生的集合 
class group
{
public:
	string reward;
	vector<student> stds;
	int length;

};
int main()
{
	ifstream infile("students.txt");
	group test();
	if (!infile.is_open())
	{
		cout << "can not open this file" << endl;
		return 0;
	}
	string sline;
	string s1, s2, s3, s4, s5, s6, s7;
	while (getline(infile, sline))
	{
		istringstream sin(sline);
		//sin >> s1 >> s2 >> s3 >> s4 >> s5 >> s6 >> s7;
		student tp;
		sin >> tp.stuID >> tp.name >> tp.sex >> tp.age >> tp.major >>tp.reward_began >>tp.reward_len;
		test.pushback(tp);
		//cout << s1 << " " << s2 << " " << s3 << " " << s4 << " " << s5 << " " << s6 << " " << s7 << "\n";
	}
	
}
