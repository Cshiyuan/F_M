// MFS.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"Item.h"
#include"MDataBase.h"
#include"Item_MS.h"

using namespace std;
int main()
{
	Item t("sdsd");
	t.Addnext("sdsd1");
	t.Addnext("sasa2");
	Item_MS m;
	m.Item_MSadd(t);
	m.Item_MSadd(t);
	m.Item_MSadd(t);
	m.Item_Msdel(1);
	return 0;
}
