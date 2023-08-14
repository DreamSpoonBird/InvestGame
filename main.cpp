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
	int daysnum = 1;//从第一天开始，后期随天数调整难度
	double deposit = 500000;
	double amount_inv = 0;
	//新建游戏
	Init(inv, n);
	do {
		//功能提示
		printf("\n\t\t\t\t\t投资小游戏(第%d天)\n",daysnum);
		getNum(inv, _n_,daysnum);
		OutputInv(inv, _n_);
		printf("\n\t\t\t您当前的现金数：%.2lf, 投资额: %.2lf\n", deposit, amount_inv);
		printf("\n\t\t\t1.交易\t\t\t\t2.测试（随机事件）\n\n\t\t\t3.测试\t\t\t\t4.添加项目\n\n\t\t\t0.退出游戏\t\t\t其他：下一轮\n\n\t\t\t请键入对应数字进行功能选择：");
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
				printf("\n\t\t\t你确定退出游戏吗？（确定请按 ‘1’ , 取消请按其他数字）:");
				scanf_s("%d", &c);
				if (c == 1) {
					printf("\n\t您当前的现金数：%.2lf, 投资额: %.2lf\n", deposit, amount_inv);
					//printf("已为您自动存档（请勿删除或修改同目录下生成的存档文件）\n");
					printf("\n\t\t\t期待您的下一次游玩！\n");
					exit(0);
				}
				else {
					break;
				}
				
			default:
				break;
				
		}
		if(daysnum % 5==0)
			daysnum++;//一周清空一次
		system("cls");
	} while (true);
    return 0;
}