#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#define MAX_NAME_LENTH 40

#include "getnum.h"
#include "display.h"
#include "deal.h"


int main() {
	int c;
	int n = 0;
	int* _n_ = &n;
	int daysnum = 1;//�ӵ�һ�쿪ʼ�����������������Ѷ�
	double deposit = 500000;
	double amount_inv = 0;
	//�½���Ϸ
	Init(inv, n);
	do {
		//������ʾ
		printf("\n\t\t\t\t\tͶ��С��Ϸ(��%d��)\n",daysnum);
		getNum(inv, _n_,daysnum);
		OutputInv(inv, _n_);
		printf("\n\t\t\t����ǰ���ֽ�����%.2lf, Ͷ�ʶ�: %.2lf\n", deposit, amount_inv);
		printf("\n\t\t\t1.����\t\t\t\t2.���ԣ�����¼���\n\n\t\t\t3.����\t\t\t\t4.�����Ŀ\n\n\t\t\t0.�˳���Ϸ\t\t\t��������һ��\n\n\t\t\t������Ӧ���ֽ��й���ѡ��");
		scanf_s("%d", &c);
		printf("\n");
		
		switch (c)
		{
			case 1:
				Deal(inv,_n_,deposit,amount_inv);
				break;
			case 2:

				break;
			case 3:

				break;
			case 4:

				break;
			case 0:
				printf("\n\t\t\t��ȷ���˳���Ϸ�𣿣�ȷ���밴 ��1�� , ȡ���밴�������֣�:");
				scanf_s("%d", &c);
				if (c == 1) {
					printf("\n\t����ǰ���ֽ�����%.2lf, Ͷ�ʶ�: %.2lf\n", deposit, amount_inv);
					//printf("��Ϊ���Զ��浵������ɾ�����޸�ͬĿ¼�����ɵĴ浵�ļ���\n");
					printf("\n\t\t\t�ڴ�������һ�����棡\n");
					exit(0);
				}
				else {
					break;
				}
				
			default:
				break;
				
		}
		if(daysnum % 5==0)
			daysnum++;//һ�����һ��
		system("cls");
	} while (true);
    return 0;
}