

int main__income()
{
	
	int opt=menu__two_option_today_else();
	char *tmp=(char*)malloc(15*sizeof(char));

	if(opt==1) sprintf(tmp,"%d",data__get_current_date(0));
	if(opt==0) return 0;
	if(opt==2)
	{

	system("cls");
	print__header();
	printf("\nPlease Input a Date in format like 20181220\n\nDate=");

	tmp=input__getchar_plus(tmp);
	}

	system("cls");
	printf("Loading...\n");
	print__income_by_date(atoi(tmp));

	printf("\n\n\n\n\n\nPress any key to go back~");

	system("pause>nul");

	return 0;
}


int main__checkIn()
{
	
	int opt=menu__two_option_today_else();
	char *input=(char*)malloc(15*sizeof(char));

	if(opt==1) sprintf(input,"%d",data__get_current_date(0));
	if(opt==0) return 0;
	if(opt==2)
	{

	system("cls");
	print__setup();
	print__header();

	printf("\nPlease Input the date you want to view: \n\nYour Input Date=");

	input=input__getchar_plus(input);

	}

	print__checkIn_rate(atoi(input));

	printf("\n\n\n\n\n\nPress any key to go back~");

	system("pause>nul");

	return 0;
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

	int opt=menu__two_option_today_else();
	char *chDate=(char*)malloc(15*sizeof(char));

	if(opt==1) sprintf(chDate,"%d",data__get_current_date(0));
	if(opt==0) return 0;
	if(opt==2)
	{
	system("cls");
	print__header();

	printf("Please Input the Date:\nDate= ");

	
	 int i0=0,i1=0,i2=0,i3=0,i4=0,i5=0,i6=0,i7=0;
    while(1)
    {
        chDate=input__getchar_plus(chDate);

        i0=data__get_current_date(0);
        i1=data__get_current_date(1);
        i2=data__get_current_date(2);
        i3=data__get_current_date(3);
        i4=data__get_current_date(4);
        i5=data__get_current_date(5);
        i6=data__get_current_date(6);
        i7=data__get_current_date(7);
	    if(strlen(chDate)==8)
       {
           if(atoi(chDate)==i0 || atoi(chDate)==i1 || atoi(chDate)==i2 || atoi(chDate)==i3 || atoi(chDate)==i4)
           {
               break;
           }
           else if( (atoi(chDate)==i5) || (atoi(chDate)==i6) || (atoi(chDate)==i7) )
            break;
            else
            {
                printf("Please make sure the Date is valid\n");
                printf("Press \"q\" to quit");
                Sleep(1500);
                system("cls");
                print__header();
                printf("Please Input the Date:\nDate= ");
                continue;
            }
       }
       else if(strlen(chDate)==1 && chDate[0]=='q')
        return -1;
       else
       {
           printf("Please make sure the Date is valid\n");
           printf("Press \"q\" to quit");
           Sleep(1500);
           system("cls");
           print__header();
           printf("Please Input the Date:\nDate= ");
       }
    }
	}
      int inType=menu__select_room_type();
      if (inType==0) return -2;
      inType=inType+1;

	//printf("\nPlease Input Type:\n Type= ");

	//char *chType=NULL;

	//chType=input__getchar_plus(chType);

	system("cls");

	printf("Availible Rooms and days: \n");

	print__search_room_by_date_and_type(atoi(chDate),inType);

	char *chRoom=NULL;

	/*未容错*/
	printf("\n\nPlease Input the Room to book:\nroom= ");

	 while(1)
      {
          chRoom=input__getchar_plus(chRoom);
          if(strlen(chRoom)==3)
          {
              int m=0;
              m=data__filter_input(chRoom);
              if(m==3)
              {
                  int n=0,baiwei=0,gewei=0;
                  n=atoi(chRoom);
                  baiwei=n/100;
                  gewei=n%100;
                  if(baiwei>=1 && baiwei<=8 && gewei>=1 && gewei<=10)
                    break;
                  else
                  {
                      printf("Please Enter a Correct Room No\n");
                      printf("Press \"q\" to quit\n");
                      Sleep(1500);
                      printf("\n\nPlease Input the Room to book:\nroom= ");

                  }
              }
              else
              {
                  printf("Please Enter a Correct Room No\n");
                  printf("Press \"q\" to quit\n");
                  Sleep(1500);
                  printf("\n\nPlease Input the Room to book:\nroom= ");
              }
          }
          else if(strlen(chRoom)==1 && chRoom[0]=='q') return -3;
          else
          {
              printf("Please Enter a Correct Room No\n");
              printf("Press \"q\" to quit\n");
              Sleep(1500);
              printf("\n\nPlease Input the Room to book:\nroom= ");
          }
      }
	
	/*未容错*/
	char *chDays=NULL;

	printf("\nPlease input the days to book: \ndays= ");

	while(1)
    {
        chDays=input__getchar_plus(chDays);
        if(strlen(chDays)==1 && chDays[0]>=49 && chDays[0]<=56)
            break;
        else if(strlen(chDays)==1 && chDays[0]=='q')
            return -3;
        else
        {
            printf("Please Enter a Correct Day Interval\n");
            printf("Press \"q\" to quit... \n");
            Sleep(1500);
            printf("\nPlease input the days to book: \ndays= ");
        }
    }


	system("cls");
	print__header();

	printf("Please input the visitor number\nVisitor Number= ");

	char *chVnum=NULL;

	while(1)
    {
        chVnum=input__getchar_plus(chVnum);
        if(strlen(chVnum)==1 && chVnum[0]<=51 && chVnum[0]>=49)
            break;
        else if(strlen(chVnum)==1 && chVnum[0]=='q')
            return -4;
        else
        {
            printf("Please Enter a Correct Visitor Number\n");
            printf("Press \"q\" to quit... \n");
            Sleep(1500);
            printf("Please input the visitor number\nVisitor Number= ");
        }

    }

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
	printf("\n\n Name:%s Tel:%s VIP:%d Nation:%s province:%s City:%s\n",  (pVstr+i)->name, (pVstr+i)->tel,(pVstr+i)->vip, (pVstr+i)->nation, (pVstr+i)->province, (pVstr+i)->city);


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
	char *pttel=NULL;
	while(1)
       {
          gets(demo_NewVisitor.tel);
          pttel=demo_NewVisitor.tel;
            if(strlen(pttel)<=20 && strlen(pttel)>=3)
            {
                int i=0,m=0;

                m=strlen(pttel);
                for(i=0;i<m;i++)
                {
                    if(isdigit(pttel[i]))
                        continue;
                    else break;
                }
                if(i==m) break;
                else
                {
                    printf("The Form of Tel Number is not correct\n");
                    printf("Press \"q\" to quit\n");
                    Sleep(1500);
                    printf("Please input a tel:\n");

                }
            }
            else if(strlen(pttel)==1 && pttel[0]=='q')
            {
                return -12;
            }
            else
            {
                    printf("The Form of Tel Number is not correct\n");
                    printf("Press \"q\" to quit\n");
                    Sleep(1500);
                    printf("Please input a tel:\n");

            }
       }


	printf("Please input if it is vip (not vip->1,vip->2) :\n");
	char tmp_ch[15];
	while(1)
    {
       gets(tmp_ch);
       if(strlen(tmp_ch)==1 && (tmp_ch[0]==49 || tmp_ch[0]==50))
        break;
       else if(strlen(tmp_ch)==1 && tmp_ch[0]=='q') return -13;
        else
       {
                    printf("The Form of Input is not Correct\n");
                    printf("Press \"q\" to quit\n");
                    Sleep(1500);
                    printf("Please Input a number :\n");

        }

    }
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
	printf(" \n\nName:%s Tel:%s VIP:%d Nation:%s province:%s City:%s\n",  (pVstr+i)->name, (pVstr+i)->tel,(pVstr+i)->vip, (pVstr+i)->nation, (pVstr+i)->province, (pVstr+i)->city);


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
	printf("\n\nName:%s Tel:%s VIP:%d Nation:%s province:%s City:%s\n", (pVstr+i)->name, (pVstr+i)->tel,(pVstr+i)->vip, (pVstr+i)->nation, (pVstr+i)->province, (pVstr+i)->city);


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

	
	if(g_nRtrnRows==1)
	{data__mark_check_in(data__get_current_date(0),pRm->roomId);printf("\n\nCheck in Successfully!!\n");}
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
	printf("\n\nName:%s Tel:%s VIP:%d Nation:%s province:%s City:%s\n",  (pVstr+i)->name, (pVstr+i)->tel,(pVstr+i)->vip,(pVstr+i)->nation, (pVstr+i)->province, (pVstr+i)->city);


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
