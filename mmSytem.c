#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <conio.h>
struct MM
{
	char name[20];
	int age;
	int num;
	char tel[20];
	char isMar[5];
};
//struct MM mmData[100];
struct System 
{
	struct MM *pMM;
	int maxSize;			//最大元素
	int curSize;			//当前元素个数
};
struct System* createSystem(int maxSize)
{
	struct System* pSystem = (struct System*)malloc(sizeof(struct System));
	assert(pSystem);
	//给结构体变量初始化
	pSystem->maxSize = maxSize;
	pSystem->pMM = (struct MM*)malloc(sizeof(struct MM) * maxSize);
	pSystem->curSize = 0;
	//把当前结构体变量的首地址返回
	return pSystem;
}

//插入数据：直接在原来的数据后面进行
//当然你也可以采用有序的方式进行插入
void  insertData(struct System* pSystem, struct MM data) 
{
	pSystem->pMM[pSystem->curSize++] = data;
	//curSize ： 这个一定要做变化
}
//遍历
void printData(struct System* pSystem)
{
	printf("姓名\t年龄\t编号\t电话\t\t婚姻\n");
	for (int i = 0; i < pSystem->curSize; i++) 
	{
		printf("%s\t%d\t%d\t%s\t%s\n", pSystem->pMM[i].name,
			pSystem->pMM[i].age,
			pSystem->pMM[i].num,
			pSystem->pMM[i].tel,
			pSystem->pMM[i].isMar);
	}
}
//小可爱 18 1001 1874442323 未婚
//小甜心 20 1002 1874442433 已婚
//baby 23 1004 1874443333 未婚
//小美 18 1003 1984343423 已婚
//查询

//删除--->一般按照只有唯一性的东西去做删除
//通过编号去做删除
void deleteByPos(struct System* pSystem, int pos)   //
{
	if (pos == -1) 
	{
		printf("删除失败，没有找到相关信息!\n");
		return;
	}
	for (int i = pos; i < pSystem->curSize; i++) 
	{
		//数组的伪删除
		pSystem->pMM[i] = pSystem->pMM[i + 1];
	}
	pSystem->curSize--;				//这个才是数组删除的本质
	printf("删除成功!\n");
}
int  searchByisMar(struct System* pSystem, const char* isMar) 
{
	for (int i = 0; i < pSystem->curSize; i++) 
	{
		if (strcmp(pSystem->pMM[i].isMar, isMar) == 0) 
		{
			return i;
		}
	}
	return -1;
}
int searchByNum(struct System* pSystem, const int num) 
{
	for (int i = 0; i < pSystem->curSize; i++) 
	{
		if (pSystem->pMM[i].num == num) 
		{
			return i;
		}
	}
	return -1;
}
void deleteData(struct System* pSystem) 
{
	//查找到要删除的编号
	//删除过程
	printf("--------------------------\n");
	printf("1.删除当前编号的人!\n");
	printf("2.删除所有已婚的人!\n");
	printf("--------------------------\n");
	printf("请输入你的选择:");
	int userKey = 0;
	struct MM data;
	scanf_s("%d", &userKey);
	switch (userKey) 
	{
	case 1:
		printf("请输入要删除的编号:");
		scanf_s("%d", &data.num);
		deleteByPos(pSystem, searchByNum(pSystem, data.num));
		break;
	case 2:
		printf("请输入婚姻状况(未婚与已婚):");
		scanf_s("%s", data.isMar,5);
		while (searchByisMar(pSystem, data.isMar) != -1) 
		{
			deleteByPos(pSystem, searchByisMar(pSystem, data.isMar));
		}
		break;
	default:
		printf("输入错误,删除结束!\n");
		break;
	}

}
//修改过程
void modifyDataByNum(struct System* pSystem) 
{
	int num = 0;
	printf("请输入编号:");
	scanf_s("%d", &num);
	int i = searchByNum(pSystem, num);
	if ( i== -1) 
	{
		printf("未找到相关信息，无法修改!\n");
	}
	else 
	{
		printf("请输入姓名，年龄，编号，电话，是否已婚：");
		scanf_s("%s%d%d%s%s", pSystem->pMM[i].name, 20,
			&pSystem->pMM[i].age,
			&pSystem->pMM[i].num,
			pSystem->pMM[i].tel, 20, 
			pSystem->pMM[i].isMar, 5);
		printf("修改成功！\n");
	}


}
void searchData(struct System* pSystem) 
{
	while (1) 
	{
		//1.查找菜单
		printf("-----------------------\n");
		printf("\t1.按婚姻状况查找\n");
		printf("\t2.按年龄查找\n");
		printf("-----------------------\n");
		printf("请输入查询方式:");
		//查找处理
		int userKey = 0;
		scanf_s("%d", &userKey);
		if (userKey == 1)
		{
			char isMar[5] = "";
			printf("请输入未婚或者已婚:");
			scanf_s("%s", isMar,5);
			printf("姓名\t年龄\t编号\t电话\t\t婚姻\n");
			for (int i = 0; i < pSystem->curSize; i++)
			{
				if (strcmp(pSystem->pMM[i].isMar, isMar) == 0) 
				{
					printf("%s\t%d\t%d\t%s\t%s\n", pSystem->pMM[i].name,
						pSystem->pMM[i].age,
						pSystem->pMM[i].num,
						pSystem->pMM[i].tel,
						pSystem->pMM[i].isMar);
				}
			}
		}
		else if (userKey == 2)
		{
			int age = 0;
			printf("请输入年龄:");
			scanf_s("%d", &age);
			printf("姓名\t年龄\t编号\t电话\t\t婚姻\n");
			for (int i = 0; i < pSystem->curSize; i++)
			{
				if (pSystem->pMM[i].age==age)
				{
					printf("%s\t%d\t%d\t%s\t%s\n", pSystem->pMM[i].name,
						pSystem->pMM[i].age,
						pSystem->pMM[i].num,
						pSystem->pMM[i].tel,
						pSystem->pMM[i].isMar);
				}
			}
		}
		else
		{
			printf("input error!\n");
		}
		printf("是否继续查找？(Y/N):");
		while (getchar() != '\n');
		userKey = getchar();
		if (userKey == 'N' || userKey == 'n') 
		{
			break;
		}
	}
}
void makeMenu() 
{
	printf("--------------【MM管理系统】------------\n");
	printf("\t\t0.退出系统\n");
	printf("\t\t1.录入系统\n");
	printf("\t\t2.浏览系统\n");
	printf("\t\t3.删除系统\n");
	printf("\t\t4.修改系统\n");
	printf("\t\t5.查询系统\n");
	printf("\t\t6.排序系统\n");
	printf("---------------------------------------\n");
	printf("请输入(0~5):");
}
//排序功能呢
void sortByNum(struct System* pSystem) 
{
	//冒泡排序，在结构体中需要剥洋葱
	for (int i = 0; i < pSystem->curSize; i++) 
	{
		for (int j = 0; j < pSystem->curSize - i - 1; j++) 
		{
			if (pSystem->pMM[j].num > pSystem->pMM[j + 1].num) 
			{
				struct MM tempMM = pSystem->pMM[j];
				pSystem->pMM[j] = pSystem->pMM[j + 1];
				pSystem->pMM[j + 1] = tempMM;
			}
		}
	}
}

void keyDown(struct System* pSystem) 
{
	int userKey = 0;
	struct MM data;
	scanf_s("%d", &userKey);
	switch (userKey) 
	{
	case 0:
		printf("正常退出!\n");
		system("pause");
		exit(0);			//退出  #include <stdlib.h>
		break;
	case 1:
		printf("-------------【录入功能】-------------\n");
		printf("请输入姓名，年龄，编号，电话，是否已婚：");
		scanf_s("%s%d%d%s%s", data.name,20, &data.age, &data.num, data.tel,20, data.isMar,5);
		insertData(pSystem, data);
		break;
	case 2:
		printf("-------------【浏览功能】-------------\n");
		printData(pSystem);
		break;
	case 3:
		printf("-------------【删除功能】-------------\n");
		deleteData(pSystem);
		break;
	case 4:
		printf("-------------【修改功能】-------------\n");
		modifyDataByNum(pSystem);
		break;
	case 5:
		printf("-------------【查询功能】-------------\n");
		searchData(pSystem);
		break;
	case 6:
		printf("-------------【排序功能】-------------\n");
		sortByNum(pSystem);
		printData(pSystem);
		break;
	default:
		printf("input error!\n");
		break;
	}
}
//判断是否存在字符和数字
int isCrrectPassword(const char* str)
{
	int i = 0;
	int isChar = 0;
	int isNum = 0;
	while (str[i] != '\0') 
	{
		if ((str[i] >= 'A' && str[i] <= 'Z') && (str[i] >= 'a' && str[i] <= 'z'))
		{
			isChar = 1;
		}
		if (str[i] >= '0' && str[i] <= '9')		//数字0-9 和字符0-9 是有区别
		{
			isNum = 1;
		}
		i++;
	}
	if (isChar == 1 && isNum == 1) 
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}
void login() 
{
	printf("欢迎来到魔帅的美女管理系统!\n");
	char userName[20]="";
	char password[7]="";
	printf("\t用户名:");
	gets_s(userName, 20);
	printf("\t密码:");
	int userKey = 0;
	int i = 0;
	while ((userKey = _getch()) != '\r')  //\r 等效\n
	{
		password[i++] = userKey;
		putchar('*');
		if (i > 7) 
		{
			printf("密码过长！\n");
			exit(0);
		}
	}
	printf("\n");
	if (isCrrectPassword(password) != 1) 
	{
		printf("密码不是存在数字和字符!\n");
	}
	printf("\n");
	if (strcmp(userName, "root") == 0 && strcmp(password, "123456") == 0)
	{
		printf("登录成功!\n");

	}
	else
	{
		printf("登录失败！\n");
		exit(0);
	}

}
/*
	//调试程序
		1.打断点 (你觉得可能错误存在的位置)
		2.按F10 进入调试状态
		3.退出调试状态:shif+f5 或者点红心
		4.F10 是逐句调试，代码一行一行再跑

*/



int main() 
{
	login();
	struct System* pSystem = createSystem(100);		//创建一个系统出来
	while (1) 
	{
		makeMenu();
		keyDown(pSystem);
		system("pause");
		system("cls");
	}
	return 0;
}