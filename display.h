void OutputInv(struct INVEST inv[], int* _n_) {
	int i;
	printf("\n\t| ���к�\t����\t\t���м۸�\t������\t��һ�μ۸�\t��ǰ���׼�\t������ |\n");
	printf("\t| -------------------------------------------------------------------------------------------- |\n");
	for (i = 0; i < *_n_; i++) {
		if (inv[i].ownnum != 0) {
			inv[i].yield = (inv[i].nowprice - inv[i].ownprice)/ inv[i].ownprice;
		}
		printf("\t| %d\t\t%s\t%.2lf\t\t%.2lf\t%.2lf\t\t%.2lf\t\t%.2lf   |\n", inv[i].num, inv[i].name, inv[i].ownprice, inv[i].ownnum, inv[i].lastprice, inv[i].nowprice, inv[i].yield);
		printf("\t| -------------------------------------------------------------------------------------------- |\n");
	}
}
void AppendInv(struct INVEST inv[], int* _n_)// ��Ͷ�ʱ�ĩβ���һ����¼
{
	//¼������
	printf("\n��������Ŀ���֣��������ݽ��Զ����ɣ���");
	char tname[MAX_NAME_LENTH] = {};
	scanf_s("%s", tname);
	inv[*_n_].num = (*_n_ + 1000) * (*_n_ + 1) - 52; strcpy_s(inv[*_n_].name,tname);inv[*_n_].ownprice = 0;
	inv[*_n_].lastprice = 1; inv[*_n_].nowprice = 300; inv[*_n_].ownnum = 0; inv[*_n_].yield = 0;
	*_n_ += 1;
	return;
}
