#pragma once
#include"Member.h"
#include<map>
//#define MAX 20  // �궨�壬���޸�
class MDataBase
{
public:
	MDataBase();
	virtual ~MDataBase();
	void addmember(int key, char* _name, char* _sex, Bdata _Bdate, int _age, double _height, double _weight);  // ��ӳ�Ա
	void memberlist();  // ������г�Ա��Ϣ
	void delmember(int key);  //����keyɾ����Ա

	void change_name(int key, char* _name);  // �޸�����
	void change_sex(int key, char* _sex);    // �޸��Ա�
	void change_Bdata(int key, Bdata _Bdata);  // �޸�����
	void change_height(int key, double _height);  // �޸����
	void change_weight(int key, double _weight);   // �޸�����
	void change_age(int key, int _age);   // �޸�����

private:
	map<int, Member> members;  // ����map����  int��Ϊ��ֵ��Member��Ϊ����

};

