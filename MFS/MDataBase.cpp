#include "stdafx.h"
#include "MDataBase.h"
#include<fstream>  // ���ļ����ж�д
//#include <cstring>
MDataBase::MDataBase()
{
	Member m;
	fstream file;  // ��ȡ�ļ�
	file.open("members.dat", ios::in | ios::binary);  // ���ļ� ���������ļ��е����ݶ���
	int key;
	while (1)
	{
		file.read((char*)&key, sizeof(int)*2);  // ��Ȼƾֱ�������˸�������Ȼ�Ϳ����ˡ�������ԭ��ʱ��׷����
		file.read((char*)&m, sizeof(m));
		if (!file) break;
		members.insert(map<int, Member>::value_type(key, m));
	}
	file.close();
}
MDataBase::~MDataBase()
{
	fstream file;
	file.open("members.dat", ios::out | ios::binary);
	map<int, Member>::iterator  it;
	int key;
	for (it = members.begin(); it != members.end(); ++it)
  {
		key = it->first;
		file.write((char*)&key, sizeof(int)*2);
		file.write((char*)&members[it->first], sizeof(members[it->first]));  
  }
	file.close();
}
void MDataBase::addmember(int key, char* _name, char* _sex, Bdata _Bdate, int _age, double _height, double _weight)  // ��ӳ�Ա
{  
	members.insert(map<int, Member> ::value_type(key, Member(_name, _sex, _Bdate, _age, _height, _weight)));
}
void MDataBase::delmember(int key)  // ɾ����Ա
{
	map<int, Member>::iterator it;
	it = members.find(key);       // ���ָ��key�ĵ�����
	if (it == members.end())
	{
        cout << "û���ҵ�" << endl;
		return ;
	}
	else
	{
        members.erase(it);  
		return;
	}
}
void MDataBase::memberlist()  // ����map���������member��
{
	map<int, Member>::iterator it = members.begin();
	for (; it != members.end(); ++it)
	{
		cout << it->first << "  " << endl;
		cout << it->second << endl;  // �˴������˲��������
	}

}
void MDataBase::change_name(int key, char*_name)  // ����keyֵ�޸ĳ�Ա����
{
	map<int, Member>::iterator it;
	it = members.find(key);
	it->second.changename(_name);
}
void MDataBase::change_sex(int key, char* _sex)  // ����keyֵ�޸ĳ�Ա�Ա�
{
	map<int, Member>::iterator it;
	it = members.find(key);
	it->second.changename(_sex);
}
void MDataBase::change_Bdata(int key, Bdata _Bate)  // ����keyֵ�޸ĳ�Ա������
{
	map<int, Member>::iterator it;
	it = members.find(key);
	it->second.changeBdate(_Bate);
}
void MDataBase::change_weight(int key, double weight)  // ����keyֵ�޸ĳ�Ա������
{
	map<int, Member>::iterator it;
	it = members.find(key);
	it->second.changeweight(weight);
}
void MDataBase::change_height(int key, double height)  // ����keyֵ�޸ĳ�Ա�����
{
	map<int, Member>::iterator it;
	it = members.find(key);
	it->second.changeheight(height);
}  
void MDataBase::change_age(int key, int age)  // ����keyֵ�޸ĳ�Ա������
{
	map<int, Member>::iterator it;
	it = members.find(key);
	it->second.changeage(age);
}