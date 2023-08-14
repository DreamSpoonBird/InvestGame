struct INVEST {
	int num;  //发行号
	char name[MAX_NAME_LENTH];  //名字
	double ownprice; //持有价
	double ownnum;	//持有量
	double lastprice; //上一次价格
	double nowprice;	//当前交易价
	double yield; // 收益率,小数点后两位！！！ 
}inv[20];//介个是一个类型为 INVEST 的一维数组 inv,最大为20 
//获取随机数，实现波动，可以外套循环实现多次波动
void getNum(struct INVEST inv[], int* _n_, int daysnum) {
	srand((unsigned)time(NULL));//保证每次生成的随机数不一样
	int x=0;//概率
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
		if (myran > x) //有(1000-x)/1000的可能上涨
		{	
			inv[i].nowprice += rand() % (100 - 9) + 9;//上涨
		}
		else 
		{
			inv[i].nowprice -= rand() % (100 - 9) + 9;//下跌
		}
	}
	return;
}

void Init(struct INVEST inv[], int& n) {
	n = 6;
	char temp[6][MAX_NAME_LENTH] = { "喵喵科技", "熊猫集团", "华佗药业", "袋鼠健身", "春蚕纺织", "猿猴娱乐" };
	for (int i = 0; i < 6; i++) {
		inv[i].num = (i + 1000) * (i + 1) - 52; strcpy_s(inv[i].name, temp[i]);
		inv[i].ownprice = 0; inv[i].lastprice = 1; inv[i].nowprice = 300; inv[i].ownnum = 0; inv[i].yield = 0;
	}
	return;
}