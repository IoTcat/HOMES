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

