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
	void show()
	{
		cout << stuID << " " << name << " " << sex << " " << age << " " << major << " ";

	}
};
//学生的集合 
class group
{
public:
	string reward;
	vector<student> stds;
	int length=0;
	int get_studentsdata(string file)//读取学生信息
	{
		ifstream infile(file);
		if (!infile.is_open())
		{
			cout << "can not open this file" << endl;
			return 0;
		}
		cout << "open 'students.txt' correct"<<"\n";
		string sline;
		while (getline(infile, sline))//一行一行读取到sline中
		{
			istringstream sin(sline);//将sline按” “切割
			student tp;
			sin >> tp.stuID >> tp.name >> tp.sex >> tp.age >> tp.major >> tp.reward_began >> tp.reward_len;
			stds.push_back(tp);
			length++;
		}
	}
	int get_reward(string file)//读取奖励信息
	{
		ifstream infile(file);
		if (!infile.is_open())
		{
			cout << "can not open this file" << endl;
			return 0;
		}
		cout << "open 'reward.txt' correct"<<"\n";
		infile >> reward;
	}
	int find(long long ID)//查找ID
	{
		for (int i = 0; i < length; i++)
		{
			if (ID == stds[i].stuID)
			{
				cout << "found it ,in line " << i + 1 << "\n";
				showstu(i);
				return 1;
			}
		}
		cout << "sorry the ID: " << ID << " is not found"<<"\n";
		return 0;
	}
	void showstu(int n)
	{
		stds[n].show();
		for (int i = stds[n].reward_began;i < stds[n].reward_began + stds[n].reward_len ;i++)//输出奖励
		{
			cout << reward[i];
		}
		cout << "\n";
	}
};
int main()
{
	group test;
	test.get_reward("reward.txt");
	test.get_studentsdata("students.txt");
	long long ID;
	cin >> ID;
	test.find(ID);
	//cout << test.reward;
}