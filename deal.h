void Deal(struct INVEST inv[], int* _n_, double &deposit, double &amount_inv) {
	int tnum=0,flag=0,index=0,model=0;
	double town=0, result=0;

	do {
		printf("\t -------------------------------------------------------------------------------------------- \n");
		printf("\n\t\t\t\t\t��Ŀ����ϵͳ\n");
		printf("\n\t\t\tע�⣺������ͬһ�����ն�ν��ף���ʱ���׼۹̶����˳�����ϵͳ��ˢ�½��׼�\n");
		printf("\n\t\t\t\t1.����\t\t2.����\t\t0.�˳�\n\n");
		printf("\t\t\t��ѡ��(ע��˴���Ҫ���)��"); scanf_s("%d", &model);
		if (model == 0)break;//����0�˳�����
		do {
			printf("\n\t\t\t��������Ҫ���׵���Ŀ��Ӧ�ķ��кţ�");
			scanf_s("%d", &tnum);
			for (int i = 0; i < *_n_; i++)
				if (inv[i].num == tnum)//��������Ŀ��ƥ��
				{
					printf("\n\t\t\t\t����\t\t���м۸�\t������\t��һ�μ۸�\t��ǰ���׼�\t������\n");
					printf("\n\t\tƥ�䵽��Ŀ:");
					flag = 1; index = i;//��¼�±�
					printf("\t%s\t%.2lf\t\t%.2lf\t%.2lf\t\t%.2lf\t\t%.2lf\n", inv[i].name, inv[i].ownprice, inv[i].ownnum, inv[i].lastprice, inv[i].nowprice, inv[i].yield);
					break;
				}
			if (flag == 0)
				printf("\n\t\t\t�Ƿ���Ŀ�ţ�����������(#^.^#)\n");
		} while (flag == 0);
		do {
			printf("\n\t\t�����뽻����(1~999������,���뽻��������0)��");
			scanf_s("%lf", &town);
			result = town * inv[index].nowprice;
			if (model == 1 && (result <= deposit) && town >= 1 && town <= 999) {//����
				deposit -= result;	//�ֽ����
				amount_inv += result;//Ͷ�ʶ�����

				//�޸ĸ�������
				//���м۸�ֵ�������0��ֱ�Ӹ�ֵ;������Ǿͣ�������*���м�+�������͵�ǰ�ۣ�/2��
				if (inv[index].ownnum == 0) {
					inv[index].ownprice = inv[index].nowprice;
				}
				else {
					inv[index].ownprice = inv[index].ownnum * inv[index].ownprice + town * inv[index].nowprice;
				}
				//��������ֵ��ֱ�����
				inv[index].ownnum += town;//��������ֵ
			}
			else if (model == 2 && (town <= inv[index].ownnum) && town >= 1 && town <= 999) {//����
				amount_inv -= result;//Ͷ�ʶ�����
				deposit += result;//�ֽ����
			}
			else if (town == 0) {
				printf("\nȡ�����ף�\n");
			}
			else {
				printf("\n\t\t\t������볬���ܹ������Ľ���������Χ�����������룡\n");
				flag = 0;
			}
		} while (flag == 0);
		printf("\n\t\t\t���׳ɹ���ף����Դ�����\n");
	} while (model != 0);
	
	return;
}


