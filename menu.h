


void menu__print_select_floor(int nPnt)
{

	/* clear screen */
	system("cls");

	/* print the screen header */
	print__header();

	printf("\n\nPlease use Arrows on Keyboard to Select a floor:");
	char chItem1[]="First Floor";
	/* function pringt__item has three parameters: display string, if it is choosed,extra space on its left*/
	print__item(chItem1,(nPnt==1)?1:0,0);

	char chItem2[]="Second Floor";
	print__item(chItem2,(nPnt==2)?1:0,0);

	char chItem3[]="Third Floor";
	print__item(chItem3,(nPnt==3)?1:0,0);

	char chItem4[]="Fourth Floor";
	print__item(chItem4,(nPnt==4)?1:0,0);

	char chItem5[]="Fifth Floor";
	print__item(chItem5,(nPnt==5)?1:0,0);

	char chItem6[]="Sixth Floor";
	print__item(chItem6,(nPnt==6)?1:0,0);

	char chItem7[]="Seven Floor";
	print__item(chItem7,(nPnt==7)?1:0,0);

	char chItem8[]="Eighth Floor";
	print__item(chItem8,(nPnt==8)?1:0,0);

	printf("\n\n\n\n\n");
	printf("Press ESC to Exit!");

}

int menu__select_floor()/*data statistics interface*/
{
	int nVal=5600;
	int nArrw=0;
	do
	{
		/* print out the menu */
		menu__print_select_floor(nVal%8+1);


		/* detect user keyboard press*/
		nArrw= input__get_arrow();

		/* when input a arrow */
		if(nArrw==1||nArrw==-1)
			nVal+=nArrw;

		/* when press enter */
		if(nArrw==6)
			break;
		/* when press esc */
		if(nArrw==9)
			return 0;

	}while(1);

	/* return user choice by number*/
	return nVal%8+1;
}


void menu__print_select_number(int nPnt,int floor)
{

	/* clear screen */
	system("cls");

	/* print the screen header */
	print__header();
	printf("\n\nPlease use Arrows on Keyboard to Select a room:");/* function pringt__item has three parameters: display string, if it is choosed,extra space on its left*/

	int floor1=100*floor+1;
	char chItem1[5];
    itoa(floor1,chItem1,10);
	print__item(chItem1,(nPnt==1)?1:0,0);

	int floor2=100*floor+2;
	char chItem2[5];
	itoa(floor2,chItem2,10);
	print__item(chItem2,(nPnt==2)?1:0,0);

	int floor3=100*floor+3;
	char chItem3[5];
	itoa(floor3,chItem3,10);
	print__item(chItem3,(nPnt==3)?1:0,0);

	int floor4=100*floor+4;
	char chItem4[5];
	itoa(floor4,chItem4,10);
	print__item(chItem4,(nPnt==4)?1:0,0);

	int floor5=100*floor+5;
	char chItem5[5];
	itoa(floor5,chItem5,10);
	print__item(chItem5,(nPnt==5)?1:0,0);

	int floor6=100*floor+6;
	char chItem6[5];
	itoa(floor6,chItem6,10);
	print__item(chItem6,(nPnt==6)?1:0,0);

	int floor7=100*floor+7;
	char chItem7[5];
	itoa(floor7,chItem7,10);
	print__item(chItem7,(nPnt==7)?1:0,0);

	int floor8=100*floor+8;
	char chItem8[5];
	itoa(floor8,chItem8,10);
	print__item(chItem8,(nPnt==8)?1:0,0);

	int floor9=100*floor+9;
	char chItem9[5];
	itoa(floor9,chItem9,10);
	print__item(chItem9,(nPnt==9)?1:0,0);

	int floor10=100*floor+10;
	char chItem10[5];
	itoa(floor10,chItem10,10);
	print__item(chItem10,(nPnt==10)?1:0,0);


	printf("\n\n\n");
	printf("Press ESC to Exit!");

}

int menu__select_number(int floor1)/*data statistics interface*/
{
	int nVal=5600;
	int nArrw=0;
	do
	{
		/* print out the menu */
		menu__print_select_number(nVal%10+1,floor1);


		/* detect user keyboard press*/
		nArrw= input__get_arrow();

		/* when input a arrow */
		if(nArrw==1||nArrw==-1)
			nVal+=nArrw;

		/* when press enter */
		if(nArrw==6)
			break;
		/* when press esc */
		if(nArrw==9)
			return 0;

	}while(1);

	/* return user choice by number*/
	return nVal%10+1;
}



void menu__print_select_room_type(int nPnt)
{

	/* clear screen */
	system("cls");

	/* print the screen header */
	print__header();

	printf("\n\nPlease use Arrows on Keyboard to Select:");
	char chItem1[]="   Type **   ";
	/* function pringt__item has three parameters: display string, if it is choosed,extra space on its left*/
	print__item(chItem1,(nPnt==1)?1:0,0);

	char chItem2[]="  Type ***  ";
	print__item(chItem2,(nPnt==2)?1:0,0);

	char chItem3[]="   Type ****  ";
	print__item(chItem3,(nPnt==3)?1:0,0);

	char chItem4[]="  VIP    ";
	print__item(chItem4,(nPnt==4)?1:0,0);


	printf("\n\n\n\n\n");
	printf("Press ESC to Exit!");

}


int menu__select_room_type()/*data statistics interface*/
{
	int nVal=5600;
	int nArrw=0;
	do
	{
		/* print out the menu */
		menu__print_select_room_type(nVal%4+1);


		/* detect user keyboard press*/
		nArrw= input__get_arrow();

		/* when input a arrow */
		if(nArrw==1||nArrw==-1)
			nVal+=nArrw;

		/* when press enter */
		if(nArrw==6)
			break;
		/* when press esc */
		if(nArrw==9)
			return 0;

	}while(1);

	/* return user choice by number*/
	return nVal%4+1;
}



void menu__print_update_visitor_info(int nPnt)
{

	/* clear screen */
	system("cls");

	/* print the screen header */
	print__header();

	printf("\n\nPlease use Arrows on Keyboard to Select an option:");
	char chItem1[]="                Name";
	/* function pringt__item has three parameters: display string, if it is choosed,extra space on its left*/
	print__item(chItem1,(nPnt==1)?1:0,0);

	char chItem2[]="                 Tel No.";
	print__item(chItem2,(nPnt==2)?1:0,0);

	char chItem3[]="VIP";
	print__item(chItem3,(nPnt==3)?1:0,0);

	char chItem4[]="                   Nation ID ";
	print__item(chItem4,(nPnt==4)?1:0,0);

	char chItem5[]="                Nation";
	print__item(chItem5,(nPnt==5)?1:0,0);

	char chItem6[]="                 Province ";
	print__item(chItem6,(nPnt==6)?1:0,0);

	char chItem7[]="                City";
	print__item(chItem7,(nPnt==7)?1:0,0);

	printf("\n\n\n\n\n");
	printf("Press ESC to Exit!");

}

int menu__update_visitor_info()/*data statistics interface*/
{
	int nVal=5600;
	int nArrw=0;
	do
	{
		/* print out the menu */
		menu__print_update_visitor_info(nVal%7+1);


		/* detect user keyboard press*/
		nArrw= input__get_arrow();

		/* when input a arrow */
		if(nArrw==1||nArrw==-1)
			nVal+=nArrw;

		/* when press enter */
		if(nArrw==6)
			break;
		/* when press esc */
		if(nArrw==9)
			return 0;

	}while(1);

	/* return user choice by number*/
	return nVal%7+1;
}


void menu__print_search_visitor_three_type_selection(int nPnt)
{

	/* clear screen */
	system("cls");

	/* print the screen header */
	print__header();

	printf("\n\nPlease use Arrows on Keyboard to Select an option:");
	char chItem1[]="                Name";
	/* function pringt__item has three parameters: display string, if it is choosed,extra space on its left*/
	print__item(chItem1,(nPnt==1)?1:0,0);

	char chItem2[]="                 Tel No.";
	print__item(chItem2,(nPnt==2)?1:0,0);

	char chItem3[]="                   Nation ID ";
	print__item(chItem3,(nPnt==3)?1:0,0);
	printf("\n\n\n\n\n");
	printf("Press ESC to Exit!");

}

int menu__search_visitor_three_type_selection()/*data statistics interface*/
{
	int nVal=5700;
	int nArrw=0;
	do
	{
		/* print out the menu */
		menu__print_search_visitor_three_type_selection(nVal%3+1);


		/* detect user keyboard press*/
		nArrw= input__get_arrow();

		/* when input a arrow */
		if(nArrw==1||nArrw==-1)
			nVal+=nArrw;

		/* when press enter */
		if(nArrw==6)
			break;
		/* when press esc */
		if(nArrw==9)
			return 0;

	}while(1);

	/* return user choice by number*/
	return nVal%3+1;
}





void menu__print_main(int nPnt)
{

	/* clear screen */
	system("cls");

	/* print the screen header */
	print__header();

	printf("\n\nPlease use Arrows on Keyboard to Select\n");
	char chItem1[]="Data Setting";
	/* function pringt__item has three parameters: display string, if it is choosed,extra space on its left*/
	print__item(chItem1,(nPnt==1)?1:0,0);

	char chItem2[]="View Statistics";
	print__item(chItem2,(nPnt==2)?1:0,0);

	char chItem3[]="Account Setting";
	print__item(chItem3,(nPnt==3)?1:0,0);

	char chItem4[]="Switch User";
	print__item(chItem4,(nPnt==4)?1:0,0);

	char chItem5[]="  Exit    ";
	print__item(chItem5,(nPnt==5)?1:0,0);

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("Press ESC to Exit!");

}

int menu__main()/*data statistics interface*/
{
	int nVal=5500;
	int nArrw=0;
	do
	{
		/* print out the menu */
		menu__print_main(nVal%5+1);


		/* detect user keyboard press*/
		nArrw= input__get_arrow();

		/* when input a arrow */
		if(nArrw==1||nArrw==-1)
			nVal+=nArrw;

		/* when press enter */
		if(nArrw==6)
			break;
		/* when press esc */
		if(nArrw==9)
			return 0;

	}while(1);

	/* return user choice by number*/
	return nVal%5+1;
}


void menu__print_manager_password(int nPnt)
{

	/* clear screen */
	system("cls");

	/* print the screen header */
	print__header();

	printf("\n\nPlease use Arrows on Keyboard to Select:\n");
	char chItem1[]="Change My Password";
	/* function pringt__item has three parameters: display string, if it is choosed,extra space on its left*/
	print__item(chItem1,(nPnt==1)?1:0,0);

	char chItem2[]="Create Staff Password";
	print__item(chItem2,(nPnt==2)?1:0,0);

	char chItem3[]="Clean All Staff Passwords";
	print__item(chItem3,(nPnt==3)?1:0,0);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("Press ESC to Exit!");

}

int menu__manager_password()
{
	int nVal=5700;
	int nArrw=0;
	do
	{
		/* print out the menu */
		menu__print_manager_password(nVal%3+1);

		/* detect user keyboard press*/
		nArrw= input__get_arrow();

		/* when input a arrow */
		if(nArrw==1||nArrw==-1)
			nVal+=nArrw;

		/* when press enter */
		if(nArrw==6)
			break;
		/* when press esc */
		if(nArrw==9)
			return 0;

	}while(1);

	/* return user choice by number*/
	return nVal%3+1;
}

void menu__print_data_statistics(int nPnt)
{

	/* clear screen */
	system("cls");

	/* print the screen header */
	print__header();

	printf("\n\nPlease use Arrows on Keyboard to Select:\n");
	char chItem1[]="View Income";
	/* function pringt__item has three parameters: display string, if it is choosed,extra space on its left*/
	print__item(chItem1,(nPnt==1)?1:0,0);

	char chItem2[]="Occupancy Rate";
	print__item(chItem2,(nPnt==2)?1:0,0);

	char chItem3[]="Export Room Data to Excel";
	print__item(chItem3,(nPnt==3)?1:0,0);

	char chItem4[]="Export Visitor Data to Excel";
	print__item(chItem4,(nPnt==4)?1:0,0);

	char chItem5[]="Backup Data to Server";
	print__item(chItem5,(nPnt==5)?1:0,0);

	char chItem6[]="Recover Data From Server";
	print__item(chItem6,(nPnt==6)?1:0,0);

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("Press ESC to Exit!");

}


int menu__data_statistics()/*data statistics interface*/
{
	int nVal=5400;
	int nArrw=0;
	do
	{
		/* print out the menu */
		menu__print_data_statistics(nVal%6+1);

		/* detect user keyboard press*/
		nArrw= input__get_arrow();

		/* when input a arrow */
		if(nArrw==1||nArrw==-1)
			nVal+=nArrw;

		/* when press enter */
		if(nArrw==6)
			break;
		/* when press esc */
		if(nArrw==9)
			return 0;

	}while(1);

	/* return user choice by number*/
	return nVal%6+1;
}


void menu__print_data_setting(int nPnt)
{

	/* clear screen */
	system("cls");

	/* print the screen header */
	print__header();

	printf("\n\nPlease use Arrows on Keyboard to Select:\n");
	char chItem1[]="Update Room Price";
	/* function pringt__item has three parameters: display string, if it is choosed,extra space on its left*/
	print__item(chItem1,(nPnt==1)?1:0,0);

	char chItem2[]="Change Room Type";
	print__item(chItem2,(nPnt==2)?1:0,0);

	char chItem3[]="Update Guests Info";
	print__item(chItem3,(nPnt==3)?1:0,0);

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("Press ESC to Exit!");

}


int menu__data_setting()/*room setting interface*/
{
	int nVal=5100;
	int nArrw=0;
	do
	{
		/* print out the menu */
		menu__print_data_setting(nVal%3+1);

		/* detect user keyboard press*/
		nArrw= input__get_arrow();

		/* when input a arrow */
		if(nArrw==1||nArrw==-1)
			nVal+=nArrw;

		/* when press enter */
		if(nArrw==6)
			break;
		/* when press esc */
		if(nArrw==9)
			return 0;

	}while(1);

	/* return user choice by number*/
	return nVal%3+1;
}



void menu__print_receptionist(int nPnt)
{

	/* clear screen */
	system("cls");

	/* print the screen header */
	print__header();

	printf("\n\nPlease use Arrows on Keyboard to Select:\n");
	char chItem1[]="   Book Room";
	/* function pringt__item has three parameters: display string, if it is choosed,extra space on its left*/
	print__item(chItem1,(nPnt==1)?1:0,0);

	char chItem2[]="   Check In";
	print__item(chItem2,(nPnt==2)?1:0,0);

	char chItem3[]="   Check Out";
	print__item(chItem3,(nPnt==3)?1:0,0);

	char chItem4[]="   Switch User";
	print__item(chItem4,(nPnt==4)?1:0,0);

	char chItem5[]="     Update Visitor Info";
	print__item(chItem5,(nPnt==5)?1:0,0);

	char chItem6[]="               Exit          ";
	print__item(chItem6,(nPnt==6)?1:0,0);
	printf("\n\n\n\n\n\n\n\n\n");
	printf("Press ESC to Exit!");

}


int menu__receptionist()
{
	int nVal=5400;
	int nArrw=0;
	do
	{
		/* print out the menu */
		menu__print_receptionist(nVal%6+1);

		/* detect user keyboard press*/
		nArrw= input__get_arrow();

		/* when input a arrow */
		if(nArrw==1||nArrw==-1)
			nVal+=nArrw;

		/* when press enter */
		if(nArrw==6)
			break;
		/* when press esc */
		if(nArrw==9)
			return 0;

	}while(1);

	/* return user choice by number*/
	return nVal%6+1;
}




int data__change_price_by_type_final(void)
{
    char* p=NULL;
    int legalornot=-100;
    int brnum=0;

    while(1)
    {
        int m=menu__select_room_type();
        if(m==0) return 0;
        system("cls");
        printf("Please input a price\n\n");
        p=input__getchar_plus(p);

        while(1)
        {

           legalornot=data__filter_input(p);
           if(legalornot==3 || legalornot==4||legalornot==2 )
           {
               int linputpricel=atoi(p);
               system("cls");
               printf("Loading...");
               m=m+1;
               double ll=linputpricel;
               data__revise_room_price_based_on_type(m,ll);
               printf("\n\nThe price has been updated successfully");
    			pthread_create(&t8, NULL, p_room_updating, NULL);
               Sleep(2000);
               brnum=10;
               break;
           }
           else if(strlen(p)==1 && p[0]=='q') break;
           else
           {
               printf("Please enter a correct price\n\n\n Press \"q\" to quit\n\n");
               p=input__getchar_plus(p);
               if(strlen(p)==1 && p[0]=='q')
               break;
           }


        }
        if(brnum==10)
            break;

     }


return 0;

}



int data__change_room_type_final(void)
{
    int m=-100,n=0,x=0,brnum=0;
    while(1)
    {
    do
    {
    while(1)
    {

       m=menu__select_floor();
       if(m==0) break;
       while(1)
       {
           n=0;
           x=0;
          n=menu__select_number(m);
          if(n==0) break;
          x=menu__select_room_type();
          if(x==0) continue;
          else break;
       }
       if(x!=0) break;

    }
    if(m==0) break;

    if(x!=0)
    {
      int roomNo=100*m+n;

      system("cls");
      printf("Loading...");
      data__change_room_type(roomNo,x+1);
      printf("\n\nThe room has been successfully updated!\n\n");
    pthread_create(&t8, NULL, p_room_updating, NULL);
      brnum=-10;
      Sleep(2000);
      break;
    }

    }while(1);
    if(!m) return 0;

    if(m==0 || brnum==-10) return 1;
    }



    return -1;

}



int menu__change_check_out()
{
    
	char *chTmp=NULL;

	while(1)
	{
	system("cls");
	

	print__header();

	printf("Please Input the Room Number: \nRoom Number=");



	chTmp=input__getchar_plus(chTmp);

	if(data__filter_input(chTmp)==3&&atoi(chTmp)%100<11&&atoi(chTmp)%100>0&&atoi(chTmp)/100>0&&atoi(chTmp)/100<9) break;

	printf("\n\n\n\nIllegal Input!!!\n");

	Sleep(1500);

	}


	system("cls");
	print__header();

    int totalmoney=0;
    room *pts=NULL;
    pts=data__get_room_info(0,atoi(chTmp),0,NULL,0,0,2,1,pts);
    for(int i=0;i<g_nRtrnRows;i++)
    {
        totalmoney=totalmoney+(pts+i)->price;

    }
    if(g_nRtrnRows==0) {printf("\n\nThis Room not need to CheckOut!!");Sleep(1500);return 0;}

    printf("\n\nThe total is: %d\n\nPlease press enter or space to confirm, or press Any Other Key to quit..",totalmoney);

    char cTmp=input__detect_input_ASCII();

    if((cTmp==32||cTmp==13))
     for(int i=0;i<g_nRtrnRows;i++)
    {
        system("cls");
		print__header();

		printf("Loading...\n");
        data__mark_check_out((pts+i)->date,atoi(chTmp));

    }


    return 0;
}


void menu__print_two_option_today_else(int nPnt)
{

	/* clear screen */
	system("cls");

	/* print the screen header */
	print__header();

	printf("\n\nPlease use Arrows on Keyboard to Select:\n");
	char chItem1[]="   Today";
	/* function pringt__item has three parameters: display string, if it is choosed,extra space on its left*/
	print__item(chItem1,(nPnt==1)?1:0,0);

	char chItem2[]="         Other";
	print__item(chItem2,(nPnt==2)?1:0,0);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("Press ESC to Exit!");

}


int menu__two_option_today_else()
{
	int nVal=5600;
	int nArrw=0;
	do
	{
		/* print out the menu */
		menu__print_two_option_today_else(nVal%2+1);

		/* detect user keyboard press*/
		nArrw= input__get_arrow();

		/* when input a arrow */
		if(nArrw==1||nArrw==-1)
			nVal+=nArrw;

		/* when press enter */
		if(nArrw==6)
			break;
		/* when press esc */
		if(nArrw==9)
			return 0;

	}while(1);

	/* return user choice by number*/
	return nVal%2+1;
}



