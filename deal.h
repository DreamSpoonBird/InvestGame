void Deal(struct INVEST inv[], int* _n_, double &deposit, double &amount_inv) {
	int tnum=0,flag=0,index=0,model=0;
	double town=0, result=0;

	do {
		printf("\t -------------------------------------------------------------------------------------------- \n");
		printf("\n\t\t\t\t\t项目交易系统\n");
		printf("\n\t\t\t注意：可以在同一交易日多次交易，此时交易价固定，退出交易系统后刷新交易价\n");
		printf("\n\t\t\t\t1.购买\t\t2.卖出\t\t0.退出\n\n");
		printf("\t\t\t您选择(注意此处不要输错)："); scanf_s("%d", &model);
		if (model == 0)break;//输入0退出购买
		do {
			printf("\n\t\t\t请输入你要交易的项目对应的发行号：");
			scanf_s("%d", &tnum);
			for (int i = 0; i < *_n_; i++)
				if (inv[i].num == tnum)//在现有项目中匹配
				{
					printf("\n\t\t\t\t名字\t\t持有价格\t持有量\t上一次价格\t当前交易价\t收益率\n");
					printf("\n\t\t匹配到项目:");
					flag = 1; index = i;//记录下标
					printf("\t%s\t%.2lf\t\t%.2lf\t%.2lf\t\t%.2lf\t\t%.2lf\n", inv[i].name, inv[i].ownprice, inv[i].ownnum, inv[i].lastprice, inv[i].nowprice, inv[i].yield);
					break;
				}
			if (flag == 0)
				printf("\n\t\t\t非法项目号，请重新输入(#^.^#)\n");
		} while (flag == 0);
		do {
			printf("\n\t\t请输入交易量(1~999闭区间,不想交易请输入0)：");
			scanf_s("%lf", &town);
			result = town * inv[index].nowprice;
			if (model == 1 && (result <= deposit) && town >= 1 && town <= 999) {//购买
				deposit -= result;	//现金减少
				amount_inv += result;//投资额增加

				//修改该项数据
				//持有价赋值，如果是0就直接赋值;如果不是就（持有量*持有价+购买量和当前价）/2。
				if (inv[index].ownnum == 0) {
					inv[index].ownprice = inv[index].nowprice;
				}
				else {
					inv[index].ownprice = inv[index].ownnum * inv[index].ownprice + town * inv[index].nowprice;
				}
				//持有量赋值，直接相加
				inv[index].ownnum += town;//持有量赋值
			}
			else if (model == 2 && (town <= inv[index].ownnum) && town >= 1 && town <= 999) {//卖出
				amount_inv -= result;//投资额增加
				deposit += result;//现金减少
			}
			else if (town == 0) {
				printf("\n取消交易！\n");
			}
			else {
				printf("\n\t\t\t你的输入超过能够买卖的金额或交易量范围！请重新输入！\n");
				flag = 0;
			}
		} while (flag == 0);
		printf("\n\t\t\t交易成功！祝您财源广进！\n");
	} while (model != 0);
	
	return;
}


