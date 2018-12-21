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


char *input__process_space(char *chTmp)
{
	for(int i=0;i<strlen(chTmp);i++)
	{
		if(chTmp[i]==32) chTmp[i]='_';
	}

	return chTmp;
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

    p=input__process_space(p);

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


int data__filter_input(char*parameter1)
{
    if(strlen(parameter1)>40 || parameter1[0]=='\0')
    {
        return -40;
    }
    else if(strlen(parameter1)==1)/*Visitor number*/
    {
        if(parameter1[0]==48 || parameter1[0]==49 || parameter1[0]==50)
            return 1;
        else
            return -1;
    }
    else if(strlen(parameter1)==3)/*Price or room number*/
    {
        int i;
        for(i=0;i<3;i++)/*Whether all characters are digits*/
        {
         if(isdigit(parameter1[i]))
            continue;
         else
            break;
        }
        if(i==3 && parameter1[0]!=48)/*If the first element is not 0*/
        {
           return 3;
        }
        else
        {
            return -3;
        }

    }
    else if(strlen(parameter1)==4)/*price*/
    {
        int i;
        for(i=0;i<4;i++)/*Whether all characters are digits*/
        {
         if(isdigit(parameter1[i]))
            continue;
         else
            break;
        }
      if(i==4 && atoi(parameter1)>=1000 && atoi(parameter1)<=9999)
        return 4;
      else
        return -4;
    }
    else if(strlen(parameter1)==7)
    {
        if(parameter1[3]==44 || parameter1[3]==45)/*Test * and - first */
        {
            int i,t;
            for(i=0;i<3;i++)
            {
                if(isdigit(parameter1[i]))
                    continue;
                else
                    break;
            }
            for(t=4;t<7;t++)
            {
                if(isdigit(parameter1[t]))
                    continue;
                else
                    break;
            }
            if(i==3 && t==7)
            {
                if(parameter1[0]<=56 && parameter1[0]>=49 && parameter1[4]<=56 && parameter1[4]>=49)
                {
                    if((parameter1[1]==48 || parameter1[1]==49)&& (parameter1[5]==48 || parameter1[5]==49) )
                    {
                        if(parameter1[1]==48 && parameter1[5]==48)
                        {
                            if((parameter1[2]<=57 && parameter1[2]>=49) && (parameter1[6]<=57 && parameter1[6]>=49))
                                return 7;
                        }
                        else if(parameter1[1]==48 && parameter1[5]==49)
                        {
                           if((parameter1[2]<=57 && parameter1[2]>=49) && parameter1[6]==48)
                            return 7;
                        }
                        else if(parameter1[1]==49 && parameter1[5]==48)
                        {
                            if((parameter1[6]<=57 && parameter1[6]>=49) && parameter1[2]==48)
                            return 7;
                        }
                        else if(parameter1[1]==49 && parameter1[5]==49)
                        {
                            if(parameter1[2]==48 && parameter1[6]==48)
                                return 7;
                        }
                    }
                }
            }
            return -7;
        }
        else
            return -7;
    }
    else if(strlen(parameter1)==8)/*Date*/
    {
        int i;
        for(i=0;i<8;i++)/*Whether all characters are digits*/
        {
         if(isdigit(parameter1[i]))
            continue;
         else
            break;
        }
      if(i==8 && atoi(parameter1)>=20181218 && atoi(parameter1)<=99999999)
        return 8;
      else
        return -8;

    }
    else if(strlen(parameter1)==11)/*telephone number*/
    {
        int i;
        for(i=0;i<11;i++)/*Whether all characters are digits*/
        {
         if(isdigit(parameter1[i]) || parameter1[i]==35 || parameter1[i]==42 || parameter1[i]==43)
            continue;
         else
            break;
        }
      if(i==11 && parameter1[0]!=48)
        return 11;
      else
        return -11;
    }
    else
    {
        int i;
        for(i=0;i<strlen(parameter1);i++)
        {
            if((parameter1[i]<=122 && parameter1[i]>=65) || parameter1[i]==32)
                continue;
            else
                break;
        }
       if(i==strlen(parameter1))
       {
           return 20;
       }
       else
       return -20;
    }
    /*    char test[50];
    int rv;
    while(1)
    {
     system("cls");
     printf("Please enter a input\n\n");
     gets(test);
     rv=data__filter_input(test);
     printf("The return value of your input is %d.\n\n\n\n if it is larger than 0, then it is legal\n\n",rv);
     printf("If it is less than 0, then it is illegal");
     system("pause");
    }*/
}
