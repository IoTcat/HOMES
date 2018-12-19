/* function for detect the keyborad to wait for a keyboard event and return it with ASCII */
int input__detect_input_ASCII()
{
	int nKey;

	/* clear former cache */
	fflush(stdin);

	/* get key value */
    nKey = _getch();

    return nKey;
}

/* function to get a char type string as needed */
char *input__getchar_plus(char *p)
{

    char *pTmp;

    /* apply for a large dynamic memory for the first time storage */
    if((pTmp=(char *)malloc(100*sizeof(char)))==NULL)
    {
        printf("Application memory failure...\n");
        exit(0); /* if fail, exit the input__as1_getchar_plus function with the return value of 0 */
    }

    /* get words from keyboard to pTemp */
    gets(pTmp);

    /* apply for a dynamic memory as needed */
    if((p=(char *)malloc(strlen(pTmp)+1))==NULL)
    {
        printf("Application memory failure...\n");
        exit(0); /* if fail, exit the input__as1_getchar_plus function with the return value of 0 */
    }

    /* copy str from pTmp to p */
    strcpy(p,pTmp);

    /* free the Tmp memory */
    free(pTmp);

    return p;
}


/* function for get keyboard arrow event */
int input__get_arrow()
{
	int nVal=0;

	while(1)
	{
		nVal=input__detect_input_ASCII();

		if(nVal==224)
		{
			/* get arraw value */
			int nKey=input__detect_input_ASCII();

			if(nKey==75)
				return -1;
			if(nKey==77)
				return 1;
			if(nKey==72)
				return -1;
			if(nKey==80)
				return 1;
			else
				return 0;
		}

		if(nVal==13)
			return 6;
		if(nVal==27)
			return 9;
	}
}
