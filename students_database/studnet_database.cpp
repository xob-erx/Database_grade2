#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include<sstream>
using namespace std;
//����ѧ�� 
class student
{
public:
	long long stuID;//ѧ��
	string name;//���� 
	string sex;//�Ա� 
	int age;//���� 
	string major;//רҵ 
	int reward_began;//������ʼ 
	int reward_len;//�������� 
};
//ѧ���ļ��� 
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
