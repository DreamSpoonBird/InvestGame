void OutputInv(struct INVEST inv[], int* _n_) {
	int i;
	printf("\n\t| 发行号\t名字\t\t持有价格\t持有量\t上一次价格\t当前交易价\t收益率 |\n");
	printf("\t| -------------------------------------------------------------------------------------------- |\n");
	for (i = 0; i < *_n_; i++) {
		if (inv[i].ownnum != 0) {
			inv[i].yield = (inv[i].nowprice - inv[i].ownprice)/ inv[i].ownprice;
		}
		printf("\t| %d\t\t%s\t%.2lf\t\t%.2lf\t%.2lf\t\t%.2lf\t\t%.2lf   |\n", inv[i].num, inv[i].name, inv[i].ownprice, inv[i].ownnum, inv[i].lastprice, inv[i].nowprice, inv[i].yield);
		printf("\t| -------------------------------------------------------------------------------------------- |\n");
	}
}
void AppendInv(struct INVEST inv[], int* _n_)// 在投资表末尾添加一个记录
{
	//录入名字
	printf("\n输入新项目名字（其他数据将自动生成）：");
	char tname[MAX_NAME_LENTH] = {};
	scanf_s("%s", tname);
	inv[*_n_].num = (*_n_ + 1000) * (*_n_ + 1) - 52; strcpy_s(inv[*_n_].name,tname);inv[*_n_].ownprice = 0;
	inv[*_n_].lastprice = 1; inv[*_n_].nowprice = 300; inv[*_n_].ownnum = 0; inv[*_n_].yield = 0;
	*_n_ += 1;
	return;
}
