/* function for adjust window color, size and position */
void print__setup()
{
	/* set window title */
	system(PROGRAM_TITLE);	
	/* set window size */
	system(WINDOW_SIZE);
	/* set window color */
	system(WINDOW_COLOR);
}


/* function for print many space */
void print__space(int nSpace)
{
	int i;
	for(i=0;i<nSpace;i++)
		printf(" ");
}


void print__wait(int nTm)
{
	int i;
	for(i=0;i<nTm;i++)
	{
		system("cls");
		printf("Please Wait... -\n");
		Sleep(150);

		system("cls");
		printf("Please Wait... \\\n");
		Sleep(150);

		system("cls");
		printf("Please Wait... |\n");
		Sleep(150);

		system("cls");
		printf("Please Wait... /\n");
		Sleep(150);

	}
	fflush(stdin);
}



void print__get_password(int type, int words)
{
	system("cls");

	if(type)	printf("Your password is WRONG! Please try again~\n\n");

	printf("Please input your Current password: \n\nYour password = ");

	for(int i=0;i<words;i++) printf("*");

	
}


void print__get_newpassword(int type, int words)
{
	system("cls");

	if(type%4==0)	printf("Please set New password: \n\nNew password = ");

	if(type%4==1)	printf("Please input the password again: \n\nThe password = ");

	if(type%4==2)	printf("The passwords you input are not the same!\n\nPlease set the New password again: \n\nNew password = ");

	if(type%4==3)	printf("Please input the password again: \n\nThe password = ");

	for(int i=0;i<words;i++) printf("*");
}


/* display a header */
void print__header()
{
	time_t timep;

    struct tm *curtm;
    time (&timep);
    curtm=gmtime(&timep);
	printf("%d-%d-%d %d:%d:%02d",curtm->tm_year+1900, curtm->tm_mon+1,curtm->tm_mday, curtm->tm_hour,curtm->tm_min, curtm->tm_sec);

	print__space(19);

	if(g_pUsr)
		printf("    %6s",g_pUsr );

	

	printf("\n----------------------------------------------------------------------------------------");
}



/* function for print a standard item */
void print__item(char chItem[20],int nMrk,int nSpc)
{
	printf("\n\n");

	print__space(nSpc+(88-strlen(chItem))/2);

	printf("%11s",chItem );

	if(nMrk==1)
	{
		print__space(3);
		printf("<<--");
	}
}

/* function for printing a menu ,you can design your menu here*/
void print__login(int nPnt)
{

	/* clear screen */
	system("cls");

	/* print the screen header */
	print__header();

	printf("Please use Arrows on Keyboard to Choose:\n");
	char chItem1[]="Staff  ";
	/* function pringt__item has three parameters: display string, if it is choosed,extra space on its left*/
	print__item(chItem1,(nPnt==1)?1:0,0);

	char chItem2[]="Manager";
	print__item(chItem2,(nPnt==2)?1:0,0);

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("Press ESC to Exit!");

}


void print__roomId(room *pRm)
{

	int t=0;
	for(int i=0;i<g_nRtrnRows;)
	{
		t=0;
		printf("%d",(pRm+i)->roomId );

		while(i<g_nRtrnRows&&((pRm+i)->roomId)+1==((pRm+i+1)->roomId))
		{
			t++;
			i++;
		}

		i++;

		if(t==0) printf(", ");
		if(t==1) printf(", %d, ",(pRm+i-1)->roomId );
		if(t>1) printf("-%d, ",(pRm+i-1)->roomId);
	}


}
 
void print__income_by_date(int date)
{
	system("cls");
	print__setup();
	print__header();
	printf("\nIncome for each room type:\n\n                                           **: %.2f",data__income_by_date_and_type(date,2));
	printf("\n\n                                           ***: %.2f",data__income_by_date_and_type(date,3) );
	printf("\n\n                                          ****: %.2f",data__income_by_date_and_type(date,4) );
	printf("\n\n                                          VIP: %.2f",data__income_by_date_and_type(date,5));
	
}



void print__checkIn_rate(int date)
{
	system("cls");
	print__setup();
	print__header();

	printf("\nCheck In Rate:\n\n                                           **: %.2f%%",data__checkIn_rate_by_date_and_type(date,2));
	printf("\n\n                                           ***: %.2f%%",data__checkIn_rate_by_date_and_type(date,3) );
	printf("\n\n                                          ****: %.2f%%",data__checkIn_rate_by_date_and_type(date,4) );
	printf("\n\n                                          VIP: %.2f%%",data__checkIn_rate_by_date_and_type(date,5));
}





/* exit */
int print__exit()
{
	
	int i;
	i=MessageBox(NULL,"Are You Sure to Exit? ","AS4 Message",MB_YESNO);
	if(i!=IDYES) return 0; 

	system("cls");

	printf("\n\n\n\n");

	int nSpc=30;
	/* print a 再见 with a heart */
	print__space(nSpc);
    printf("        **           **        \n");
    Sleep(70);	
    print__space(nSpc);
    printf("    *       *     *       *    \n");
    Sleep(70);	
    print__space(nSpc);
    printf("  *            *             *  \n");
    Sleep(70);	
    print__space(nSpc);
    printf(" *    _______      ____        * \n");
    Sleep(70);
    print__space(nSpc);
    printf(" *     __|__      |    |       * \n");
    Sleep(70);	
    print__space(nSpc);
    printf(" *    |__|__|     |  | |       * \n");
    Sleep(70);	
    print__space(nSpc);
    printf(" *   _|__|__|_    |  | |      * \n");
    Sleep(70);	
    print__space(nSpc);
    printf("  *   |     |       /|       *  \n");
    Sleep(70);	
    print__space(nSpc);
    printf("   *  |     |      /  \\__|  *   \n");
    Sleep(70);	
    print__space(nSpc);
    printf("    *                     *    \n");
    Sleep(70);	
    print__space(nSpc);
    printf("      *                 *      \n");
    Sleep(70);	
    print__space(nSpc);
    printf("        *             *        \n");
    Sleep(70);	
    print__space(nSpc);
    printf("          *         *          \n");
    Sleep(70);	
    print__space(nSpc);
    printf("             *   *             \n");
    Sleep(70);	
    print__space(nSpc);
    printf("               *               \n");

    Sleep(300);
    exit(0);
}





void print__room_type(void)
{
    system("cls");
    print__setup();
    print__header();
    printf("\nHere is the room and their types:\n");
    printf("\n");
    room *pts=NULL;
    int Date=data__get_current_date(0);

    pts=data__get_room_info(0,0,Date,NULL,2,0,0,0,pts);
    if(g_nRtrnRows==0)
        printf("Type **(%.1f): ",pts->price);
    else
    {
        printf("Type **(%.1f): ",pts->price);
        print__roomId(pts);
    }


    pts=data__get_room_info(0,0,Date,NULL,3,0,0,0,pts);
    printf("\n\n");
    if(g_nRtrnRows==0)
        printf("Type ***(%.1f): ",pts->price);
    else
    {
        printf("Type ***(%.1f): ",pts->price);
        print__roomId(pts);
    }

    pts=data__get_room_info(0,0,Date,NULL,4,0,0,0,pts);
    printf("\n\n");
    if(g_nRtrnRows==0)
        printf("Type ****(%.1f): ",pts->price);
    else
    {
        printf("Type ****(%.1f): ",pts->price);
        print__roomId(pts);
    }

    pts=data__get_room_info(0,0,Date,NULL,5,0,0,0,pts);
    printf("\n\n");
    if(g_nRtrnRows==0)
        printf("Type VIP(%.1f): ",pts->price);
    else
    {
        printf("Type VIP(%.1f): ",pts->price);
        print__roomId(pts);
    }

    pts=data__get_room_info(0,0,Date,NULL,1,0,0,0,pts);
    printf("\n\n");
    if(g_nRtrnRows==0)
        printf("Type Unavailable: None");
    else
    {
        printf("Type Unavailable: ");
        print__roomId(pts);
    }
}


	void print__search_room_by_date_and_type(int date,int type)
	{
		room *pRm=NULL;

		pRm=data__get_room_availavble_by_date(date,type,pRm);

		int tmp_g=g_nRtrnRows;

		for(int i=0;i<tmp_g;i++)
		{
			printf("Room Number: %d         Days: %d\n",(pRm+i)->roomId,data__get_day_available_from_A_date_for_room(date,(pRm+i)->roomId) ); 
		}
	}
