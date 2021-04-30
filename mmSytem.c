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
	int maxSize;			//���Ԫ��
	int curSize;			//��ǰԪ�ظ���
};
struct System* createSystem(int maxSize)
{
	struct System* pSystem = (struct System*)malloc(sizeof(struct System));
	assert(pSystem);
	//���ṹ�������ʼ��
	pSystem->maxSize = maxSize;
	pSystem->pMM = (struct MM*)malloc(sizeof(struct MM) * maxSize);
	pSystem->curSize = 0;
	//�ѵ�ǰ�ṹ��������׵�ַ����
	return pSystem;
}

//�������ݣ�ֱ����ԭ�������ݺ������
//��Ȼ��Ҳ���Բ�������ķ�ʽ���в���
void  insertData(struct System* pSystem, struct MM data) 
{
	pSystem->pMM[pSystem->curSize++] = data;
	//curSize �� ���һ��Ҫ���仯
}
//����
void printData(struct System* pSystem)
{
	printf("����\t����\t���\t�绰\t\t����\n");
	for (int i = 0; i < pSystem->curSize; i++) 
	{
		printf("%s\t%d\t%d\t%s\t%s\n", pSystem->pMM[i].name,
			pSystem->pMM[i].age,
			pSystem->pMM[i].num,
			pSystem->pMM[i].tel,
			pSystem->pMM[i].isMar);
	}
}
//С�ɰ� 18 1001 1874442323 δ��
//С���� 20 1002 1874442433 �ѻ�
//baby 23 1004 1874443333 δ��
//С�� 18 1003 1984343423 �ѻ�
//��ѯ

//ɾ��--->һ�㰴��ֻ��Ψһ�ԵĶ���ȥ��ɾ��
//ͨ�����ȥ��ɾ��
void deleteByPos(struct System* pSystem, int pos)   //
{
	if (pos == -1) 
	{
		printf("ɾ��ʧ�ܣ�û���ҵ������Ϣ!\n");
		return;
	}
	for (int i = pos; i < pSystem->curSize; i++) 
	{
		//�����αɾ��
		pSystem->pMM[i] = pSystem->pMM[i + 1];
	}
	pSystem->curSize--;				//�����������ɾ���ı���
	printf("ɾ���ɹ�!\n");
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
	//���ҵ�Ҫɾ���ı��
	//ɾ������
	printf("--------------------------\n");
	printf("1.ɾ����ǰ��ŵ���!\n");
	printf("2.ɾ�������ѻ����!\n");
	printf("--------------------------\n");
	printf("���������ѡ��:");
	int userKey = 0;
	struct MM data;
	scanf_s("%d", &userKey);
	switch (userKey) 
	{
	case 1:
		printf("������Ҫɾ���ı��:");
		scanf_s("%d", &data.num);
		deleteByPos(pSystem, searchByNum(pSystem, data.num));
		break;
	case 2:
		printf("���������״��(δ�����ѻ�):");
		scanf_s("%s", data.isMar,5);
		while (searchByisMar(pSystem, data.isMar) != -1) 
		{
			deleteByPos(pSystem, searchByisMar(pSystem, data.isMar));
		}
		break;
	default:
		printf("�������,ɾ������!\n");
		break;
	}

}
//�޸Ĺ���
void modifyDataByNum(struct System* pSystem) 
{
	int num = 0;
	printf("��������:");
	scanf_s("%d", &num);
	int i = searchByNum(pSystem, num);
	if ( i== -1) 
	{
		printf("δ�ҵ������Ϣ���޷��޸�!\n");
	}
	else 
	{
		printf("���������������䣬��ţ��绰���Ƿ��ѻ飺");
		scanf_s("%s%d%d%s%s", pSystem->pMM[i].name, 20,
			&pSystem->pMM[i].age,
			&pSystem->pMM[i].num,
			pSystem->pMM[i].tel, 20, 
			pSystem->pMM[i].isMar, 5);
		printf("�޸ĳɹ���\n");
	}


}
void searchData(struct System* pSystem) 
{
	while (1) 
	{
		//1.���Ҳ˵�
		printf("-----------------------\n");
		printf("\t1.������״������\n");
		printf("\t2.���������\n");
		printf("-----------------------\n");
		printf("�������ѯ��ʽ:");
		//���Ҵ���
		int userKey = 0;
		scanf_s("%d", &userKey);
		if (userKey == 1)
		{
			char isMar[5] = "";
			printf("������δ������ѻ�:");
			scanf_s("%s", isMar,5);
			printf("����\t����\t���\t�绰\t\t����\n");
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
			printf("����������:");
			scanf_s("%d", &age);
			printf("����\t����\t���\t�绰\t\t����\n");
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
		printf("�Ƿ�������ң�(Y/N):");
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
	printf("--------------��MM����ϵͳ��------------\n");
	printf("\t\t0.�˳�ϵͳ\n");
	printf("\t\t1.¼��ϵͳ\n");
	printf("\t\t2.���ϵͳ\n");
	printf("\t\t3.ɾ��ϵͳ\n");
	printf("\t\t4.�޸�ϵͳ\n");
	printf("\t\t5.��ѯϵͳ\n");
	printf("\t\t6.����ϵͳ\n");
	printf("---------------------------------------\n");
	printf("������(0~5):");
}
//��������
void sortByNum(struct System* pSystem) 
{
	//ð�������ڽṹ������Ҫ�����
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
		printf("�����˳�!\n");
		system("pause");
		exit(0);			//�˳�  #include <stdlib.h>
		break;
	case 1:
		printf("-------------��¼�빦�ܡ�-------------\n");
		printf("���������������䣬��ţ��绰���Ƿ��ѻ飺");
		scanf_s("%s%d%d%s%s", data.name,20, &data.age, &data.num, data.tel,20, data.isMar,5);
		insertData(pSystem, data);
		break;
	case 2:
		printf("-------------��������ܡ�-------------\n");
		printData(pSystem);
		break;
	case 3:
		printf("-------------��ɾ�����ܡ�-------------\n");
		deleteData(pSystem);
		break;
	case 4:
		printf("-------------���޸Ĺ��ܡ�-------------\n");
		modifyDataByNum(pSystem);
		break;
	case 5:
		printf("-------------����ѯ���ܡ�-------------\n");
		searchData(pSystem);
		break;
	case 6:
		printf("-------------�������ܡ�-------------\n");
		sortByNum(pSystem);
		printData(pSystem);
		break;
	default:
		printf("input error!\n");
		break;
	}
}
//�ж��Ƿ�����ַ�������
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
		if (str[i] >= '0' && str[i] <= '9')		//����0-9 ���ַ�0-9 ��������
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
	printf("��ӭ����ħ˧����Ů����ϵͳ!\n");
	char userName[20]="";
	char password[7]="";
	printf("\t�û���:");
	gets_s(userName, 20);
	printf("\t����:");
	int userKey = 0;
	int i = 0;
	while ((userKey = _getch()) != '\r')  //\r ��Ч\n
	{
		password[i++] = userKey;
		putchar('*');
		if (i > 7) 
		{
			printf("���������\n");
			exit(0);
		}
	}
	printf("\n");
	if (isCrrectPassword(password) != 1) 
	{
		printf("���벻�Ǵ������ֺ��ַ�!\n");
	}
	printf("\n");
	if (strcmp(userName, "root") == 0 && strcmp(password, "123456") == 0)
	{
		printf("��¼�ɹ�!\n");

	}
	else
	{
		printf("��¼ʧ�ܣ�\n");
		exit(0);
	}

}
/*
	//���Գ���
		1.��ϵ� (����ÿ��ܴ�����ڵ�λ��)
		2.��F10 �������״̬
		3.�˳�����״̬:shif+f5 ���ߵ����
		4.F10 �������ԣ�����һ��һ������

*/



int main() 
{
	login();
	struct System* pSystem = createSystem(100);		//����һ��ϵͳ����
	while (1) 
	{
		makeMenu();
		keyDown(pSystem);
		system("pause");
		system("cls");
	}
	return 0;
}