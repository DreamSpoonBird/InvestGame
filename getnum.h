struct INVEST {
	int num;  //���к�
	char name[MAX_NAME_LENTH];  //����
	double ownprice; //���м�
	double ownnum;	//������
	double lastprice; //��һ�μ۸�
	double nowprice;	//��ǰ���׼�
	double yield; // ������,С�������λ������ 
}inv[20];//�����һ������Ϊ INVEST ��һά���� inv,���Ϊ20 
//��ȡ�������ʵ�ֲ�������������ѭ��ʵ�ֶ�β���
void getNum(struct INVEST inv[], int* _n_, int daysnum) {
	srand((unsigned)time(NULL));//��֤ÿ�����ɵ��������һ��
	int x=0;//����
	if (daysnum < 20) {
		x = 780;
	}
	else if (daysnum < 50) {
		x = 623;
	}
	else if (daysnum < 90) {
		x = 515;
	}
	else if(daysnum < 150){
		x = 300;
	}
	else if(daysnum<200){
		x = 645;
	}
	else if (daysnum < 250) {
		x = 150;
	}
	else if(daysnum < 315){
		x = 650;
	}
	else {
		x = 450;
	}
	for (int i = 0; i < *_n_; i++)
	{
		inv[i].lastprice = inv[i].nowprice;
		int myran = rand() % (1000 - 99) + 99;
		if (myran > x) //��(1000-x)/1000�Ŀ�������
		{	
			inv[i].nowprice += rand() % (100 - 9) + 9;//����
		}
		else 
		{
			inv[i].nowprice -= rand() % (100 - 9) + 9;//�µ�
		}
	}
	return;
}

void Init(struct INVEST inv[], int& n) {
	n = 6;
	char temp[6][MAX_NAME_LENTH] = { "�����Ƽ�", "��è����", "��٢ҩҵ", "������", "���Ϸ�֯", "Գ������" };
	for (int i = 0; i < 6; i++) {
		inv[i].num = (i + 1000) * (i + 1) - 52; strcpy_s(inv[i].name, temp[i]);
		inv[i].ownprice = 0; inv[i].lastprice = 1; inv[i].nowprice = 300; inv[i].ownnum = 0; inv[i].yield = 0;
	}
	return;
}