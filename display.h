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
