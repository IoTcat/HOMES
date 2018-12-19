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

	printf("Please input your password: \n\nYour password = ");

	for(int i=0;i<words;i++) printf("*");

	
}


void print__get_newpassword(int type, int words)
{
	system("cls");

	if(type%4==0)	printf("Please set your password: \n\nYour password = ");

	if(type%4==1)	printf("Please input your password again: \n\nYour password = ");

	if(type%4==2)	printf("The passwords you input are not the same!\n\nPlease set your password again: \n\nYour password = ");

	if(type%4==3)	printf("Please input your password again: \n\nYour password = ");

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
		printf("User: %6s",g_pUsr );

	printf("this is the header");

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