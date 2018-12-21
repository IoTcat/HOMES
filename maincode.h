

void main__income()
{
	system("cls");
	print__header();
	printf("\nPlease Input a Date in format like 20181220\n\nDate=");

	char *tmp=NULL;

	tmp=input__getchar_plus(tmp);

	system("cls");
	printf("Loading...\n");
	print__income_by_date(atoi(tmp));

	printf("\n\n\n\n\n\nPress any key to go back~");

	system("pause>nul");

}


void main__checkIn()
{
	system("cls");
	print__setup();
	print__header();

	printf("\nPlease Input the date you want to view: \n\nYour Input Date=");

	char *input=NULL;

	input=input__getchar_plus(input);

	print__checkIn_rate(atoi(input));

	printf("\n\n\n\n\n\nPress any key to go back~");

	system("pause>nul");
}



int main__booking()
{
/*
while(1)

{
	char *chTmp=NULL;
	while(1)
	{
	system("cls");
	print__header();

	printf("Please Input a Tel, Name or National Number to search a visitor:\nKey Words= ");



	chTmp=input__getchar_plus(chTmp);
	if(strlen(chTmp)>5) break;

	printf("\n\nYour Key Word is TOO SHORT!!\n");

	Sleep(1500);
	}


	while(1)
	{

	struct visitor *pVstr=NULL;
	pVstr= data__get_visitor_info(chTmp,pVstr);

	if(g_nRtrnRows!=1) 
	{

		printf("\n\nNo user or more than ONE user searched!!\n");

		break;
	}


	}




}
*/
	/****the type choosing screen*****/
	/*****how long choosing screen****/

	if(is_busy) { system("cls");printf("\nThere are data operation conducting, please wait a while..\n");Sleep(1500);return 0;}
	system("cls");
	print__header();

	printf("Please Input the Date:\nDate= ");

	char *chDate=NULL;

	chDate=input__getchar_plus(chDate);

	printf("\nPlease Input Type:\n Type= ");

	char *chType=NULL;

	chType=input__getchar_plus(chType);

	system("cls");

	printf("Availible Rooms and days: \n");

	print__search_room_by_date_and_type(atoi(chDate),atoi(chType));

	char *chRoom=NULL;

	/*未容错*/
	printf("\n\nPlease Input the Room to book:\nroom= ");

	chRoom=input__getchar_plus(chRoom);
	
	/*未容错*/
	char *chDays=NULL;

	printf("\nPlease input the days to book: \ndays= ");

	chDays=input__getchar_plus(chDays);


	system("cls");
	print__header();

	printf("Please input the visitor number\nVisitor Number= ");

	char *chVnum=NULL;

	chVnum=input__getchar_plus(chVnum);

	int nVst[atoi(chVnum)+1];

	nVst[0]=atoi(chVnum);


for(int i=0;i<atoi(chVnum);i++)
{

	int ifCreate=0;
	while(1)
	{

	system("cls");
	print__header();


	printf("Please Input a Key words to search a Visitor or input q to create one: \nKey Words= ");

	char *chWd=NULL;

	chWd=input__getchar_plus(chWd);


	if(strlen(chWd)==1&&chWd[0]=='q')
	{
		ifCreate=1;
		break;
	}

	struct visitor *pVstr=NULL;
	pVstr= data__get_visitor_info(chWd,pVstr);

	/* print all these visitors info on screen */
	for(int i=0;i<g_nRtrnRows;i++)
	printf("\n\n Name:%s Tel:%s VIP:%d NationalID:%s Nation:%s province:%s City:%s\n",  (pVstr+i)->name, (pVstr+i)->tel,(pVstr+i)->vip, (pVstr+i)->nationalId,(pVstr+i)->nation, (pVstr+i)->province, (pVstr+i)->city);


	if(g_nRtrnRows==1)
	{
		Sleep(1500);

		nVst[i+1]=pVstr->id;
		break;
	}

	printf("Find nothing or Find more than one result!!\n");

	Sleep(1500);

	}
	while(ifCreate)
	{

	visitor demo_NewVisitor;

	printf("Please input a name:\n");
	gets(demo_NewVisitor.name);

	printf("Please input a tel:\n");
	gets(demo_NewVisitor.tel);

	printf("Please input if it is vip (not vip->1,vip->2) :\n");
	char tmp_ch[15];
	gets(tmp_ch);
	demo_NewVisitor.vip=atoi(tmp_ch);

	printf("Please input a nationalId:\n");
	gets(demo_NewVisitor.nationalId);

	printf("Please input a nation:\n");
	gets(demo_NewVisitor.nation);

	printf("Please input a province:\n");
	gets(demo_NewVisitor.province);

	printf("Please input a city:\n");
	gets(demo_NewVisitor.city);

	demo_NewVisitor.id=0;

	/* excute the data__insert_visitor_info function and when the function crash, print the error info on screen */
	if(data__insert_visitor_info(&demo_NewVisitor)) printf("Error in Function data__insert_visitor_info: %s\n",strerror(errno));
	else printf("Create successfully!\n");

	struct visitor *pVstr=NULL;
	pVstr= data__get_visitor_info(demo_NewVisitor.tel,pVstr);

	/* print all these visitors info on screen */
	for(int i=0;i<g_nRtrnRows;i++)
	printf(" \n\nName:%s Tel:%s VIP:%d NationalID:%s Nation:%s province:%s City:%s\n",  (pVstr+i)->name, (pVstr+i)->tel,(pVstr+i)->vip, (pVstr+i)->nationalId,(pVstr+i)->nation, (pVstr+i)->province, (pVstr+i)->city);


	Sleep(1500);

	nVst[i+1]=pVstr->id;
	break;

	ifCreate=0;

	}
}


	system("cls");
	print__header();
	

	for(int i=0;i<atoi(chDays);i++)
	{data__insert_userinfo_to_structure(atoi(chDate)+i,atoi(chRoom),nVst);}

	printf("\n\nBooking Successfully!\n");

	Sleep(1500);

	return 0;
}


int main__checkIn_re()
{

	if(is_busy) { system("cls");printf("\nThere are data operation conducting, please wait a while..\n");Sleep(1500);return 0;}
	int nVst=0;

	while(1)
	{

	system("cls");
	print__header();


	printf("Please Input a Key words to search a Visitor: \nKey Words= ");

	char *chWd=NULL;

	chWd=input__getchar_plus(chWd);

	if(strlen(chWd)==0) return 0;

	struct visitor *pVstr=NULL;
	pVstr= data__get_visitor_info(chWd,pVstr);


	/* print all these visitors info on screen */
	for(int i=0;i<g_nRtrnRows;i++)
	printf("\n\nName:%s Tel:%s VIP:%d NationalID:%s Nation:%s province:%s City:%s\n", (pVstr+i)->name, (pVstr+i)->tel,(pVstr+i)->vip, (pVstr+i)->nationalId,(pVstr+i)->nation, (pVstr+i)->province, (pVstr+i)->city);


	if(g_nRtrnRows==1)
	{
		Sleep(1500);

		nVst=pVstr->id;
		break;
	}

	printf("Find nothing or Find more than one result!!\n");

	Sleep(1500);

	}

	/* declear a room pointer to receive the matched rooms info */
	struct room *pRm=NULL;

	int *hh=(int *)malloc(5*sizeof(int));
	*hh=nVst;
	pRm= data__get_room_info(0/*index*/,0/*roomId*/,data__get_current_date(0)/*date*/,hh/*visitorId*/,0/*type*/,0/*price*/,1/*checkIn*/,0/*checkOut*/,pRm);

	/* show error hint if the function not runing successfully */
	if(!pRm)	printf("Error in Function data__get_room_info: %s\n",strerror(errno));

	data__mark_check_in(data__get_current_date(0),pRm->roomId);
	if(g_nRtrnRows==1)
	{printf("\n\nCheck in Successfully!!\n");}
	else
	printf("\n\nThis Visitor has not Book the Room.\n");

	Sleep(1500);


	return 0;
}


int main__change_visitor_info()
{

	int nVst=0;

	while(1)
	{

	system("cls");
	print__header();


	printf("Please Input a Key words to search a Visitor: \nKey Words= ");

	char *chWd=NULL;

	chWd=input__getchar_plus(chWd);

	if(strlen(chWd)==0) return 0;

	struct visitor *pVstr=NULL;
	pVstr= data__get_visitor_info(chWd,pVstr);


	/* print all these visitors info on screen */
	for(int i=0;i<g_nRtrnRows;i++)
	printf("\n\nName:%s Tel:%s VIP:%d NationalID:%s Nation:%s province:%s City:%s\n",  (pVstr+i)->name, (pVstr+i)->tel,(pVstr+i)->vip, (pVstr+i)->nationalId,(pVstr+i)->nation, (pVstr+i)->province, (pVstr+i)->city);


	if(g_nRtrnRows==1)
	{
		nVst=pVstr->id;
		break;
	}

	printf("Find nothing or Find more than one result!!\n");

	Sleep(1500);

	}

	visitor demo_NewVisitor;

	printf("\nPlease input a name:\n");
	gets(demo_NewVisitor.name);

	printf("Please input a tel:\n");
	gets(demo_NewVisitor.tel);

	printf("Please input if it is vip (not vip->1,vip->2) :\n");
	char tmp_ch[15];
	gets(tmp_ch);
	demo_NewVisitor.vip=atoi(tmp_ch);

	printf("Please input a nationalId:\n");
	gets(demo_NewVisitor.nationalId);

	printf("Please input a nation:\n");
	gets(demo_NewVisitor.nation);

	printf("Please input a province:\n");
	gets(demo_NewVisitor.province);

	printf("Please input a city:\n");
	gets(demo_NewVisitor.city);

	demo_NewVisitor.id=0;

	/* excute the data__insert_visitor_info function and when the function crash, print the error info on screen */
	if(data__insert_visitor_info(&demo_NewVisitor)) printf("Error in Function data__insert_visitor_info: %s\n",strerror(errno));
	else {system("cls");printf("\nCreate successfully!\n");/* del the visitor info */
	if(data__del_visitor_info(nVst)) printf("Error in Function data__del_visitor_info: %s\n",strerror(errno));;Sleep(1400);}

	return 0;
}
