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

	char chItem2[]="     Update Visitor Info";
	print__item(chItem2,(nPnt==2)?1:0,0);

	char chItem3[]="   Check In";
	print__item(chItem3,(nPnt==3)?1:0,0);

	char chItem4[]="   Check Out";
	print__item(chItem4,(nPnt==4)?1:0,0);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("Press ESC to Exit!");

}


int menu__receptionist()
{
	int nVal=5600;
	int nArrw=0;
	do
	{
		/* print out the menu */
		menu__print_receptionist(nVal%4+1);

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
           if(legalornot==3 || legalornot==4 )
           {
               int linputpricel=atoi(p);
               system("cls");
               printf("Loading...");
               m=m+1;
               double ll=linputpricel;
               data__revise_room_price_based_on_type(m,ll);
               printf("\n\nThe price has been updated successfully");
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