/*
Name: Assesment 4 of EEE 101

File Name: main.c

Copyright: Free

Author: ...

Description: Program for a hotal management system.
 */



#include <stdio.h>  /* Include standard library of stdio.h */
#include <stdlib.h> /* Include standard liberary of stdlib.h */
#include <conio.h>  /* Include liberary of conio.h  */
#include <string.h>	/* Include string.h */ 
#include <ctype.h>  /* Include ctype.h  */
#include <windows.h> /* lib for include windows API such as msgbox */
#include <time.h>	/* lib for getting system time */
#include <errno.h> /* lib dealing with errors */

/* the max length of a name */
#define NAME_MAX_LENGTH 35
/* the max length of a tel */
#define TEL_MAX_LENGTH 20
/* the max length of a national ID */
#define NATIONALID_MAX_LENGTH 20
/* the max length of a nation, province/state or a city */
#define ADDRESS_MAX_LENGTH 35
/* the max visitors number in one room */
#define VISITOR_MAX_NUMBER 3
/* the name of data folder */
#define DATA_FOLDER "data"
/* the name of visitor data file */
#define VISITOR_DATA_FILE "Visitor.txt"
/* the name of visitor del file */
#define VISITOR_DEL_FILE "Del.txt"







/*****************declear global variables ********************/

/* variable of user name ::manager, receptionist*/
char *g_pUsr=NULL;
/* this variable indicate the rows of return struct */ 
int g_nRtrnRows=0;





/************** declear struct here ****************************/

typedef struct visitor
{
	int id;
	char name[NAME_MAX_LENGTH];
	char tel[TEL_MAX_LENGTH];
	unsigned int vip:1;
	char nationalId[NATIONALID_MAX_LENGTH];
	char nation[ADDRESS_MAX_LENGTH];
	char province[ADDRESS_MAX_LENGTH];
	char city[ADDRESS_MAX_LENGTH];

} visitor;



struct room
{
	int roomId;
	int date;
	int visitorId[VISITOR_MAX_NUMBER];
	/* type: 0->not availzble, 1->**level,2->***level,3->****level,4->VIP */
	int type;
	float price;
	/* check: 0->not visit, 1->visited */
	unsigned int check:1;

};




/* declear Fundamental Functions Here */
int input__detect_input_ASCII();
int data__generate_visitor_ID();
void data__check_file_path(char hint);
int data__insert_visitor_info(struct visitor *pVstr);
int *data__seek_key_word(char chKey[40], FILE *fp,int * nSeek);
void data__get_one_visitor_info(int nSeek,FILE *fp,visitor *visitor,int index);
int *data__get_del_usr_info(int *deled_usr);
struct visitor *data__get_visitor_info(char value[35],visitor *pVstr);
int data__del_visitor_info(int id);


























void test__test_fundamental_functions()
{
	printf("Please Press 't' to test fundamental_functions, or press any other key to goto your main fuction!\n");

	if(input__detect_input_ASCII()=='t')
	{
		/* clean the screen */
		system("cls");


		printf("Demo 1:\nThis demo will a visitor file of yimian.\n");
		/*********demo of Create a New User*********/

		/* Create a new visitor struct variable with some user info */
		visitor demo_NewVisitor={data__generate_visitor_ID(),"yimian Liu","18118155257",1,"370902199909041813","china","shandong","taian"};

		/* excute the data__insert_visitor_info function and when the function crash, print the error info on screen */
		if(data__insert_visitor_info(&demo_NewVisitor)) printf("Error in Function data__insert_visitor_info: %s\n",strerror(errno));
		else printf("Create successfully!\n");

		/************end of the demo****************/
		system("pause");



		printf("\n\nDemo 2:\nGet Visitors info, index key word is 'china' in this case.\n\n");
		/***********demo of Find one or more Visitors info********/

		/* provide a key word to search visitors*/
		char tmp_Nation[35]="china";

		/* declear a visitor pointer to receive the matched visitors info */
		struct visitor *pVstr=NULL;
		pVstr= data__get_visitor_info(tmp_Nation,pVstr);

		/* show error hint if the function not runing successfully */
		if(!pVstr)	printf("Error in Function data__get_visitor_info: %s\n",strerror(errno));

		/* print all these visitors info on screen */
		for(int i=0;i<g_nRtrnRows;i++)
		printf("ID:%d Name:%s Tel:%s VIP:%d NationalID:%s Nation:%s province:%s City:%s\n", (pVstr+i)->id, (pVstr+i)->name, (pVstr+i)->tel,(pVstr+i)->vip, (pVstr+i)->nationalId,(pVstr+i)->nation, (pVstr+i)->province, (pVstr+i)->city);

		/******************end of the demo**************************/
		system("pause");



		printf("\n\nDemo 3:\nTo delete a visitor info, you need to provide a visitor ID.\n\n");
		/***********demo of Find one or more Visitors info********/
		printf("Please input the ID:\n");

		/* get ID input */
		char tmp_visitorId[11];
		while(!scanf("%s",tmp_visitorId)) fflush(stdin);

		/* del the visitor info */
		if(data__del_visitor_info(atoi(tmp_visitorId))) printf("Error in Function data__del_visitor_info: %s\n",strerror(errno));; 

		/******************end of the demo**************************/
		system("pause");

	}
}




int main(int argc, char const *argv[])
{
	test__test_fundamental_functions(); /* Don't Remove This For Test Purpose!! */

	/*************Your Code Here****************/

	//printf("Hellow World!\n");






	/*************Your Code Here****************/

	system("echo This is the END of your Main function!!!!&&pause>nul"); /* Remain you the end of your main function */

	return 0;
}

































/*******************Fundamental Functions Here::Please do not change these unless you are forced to do******************/


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



/* function for generate a new visitor ID */
int data__generate_visitor_ID()
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
   	if(hint=='v')
    sprintf(chCmd,"IF NOT EXIST \"%s\" MD \"%s\"",DATA_FOLDER,DATA_FOLDER);
	if(hint=='r')
  	sprintf(chCmd,"IF NOT EXIST \"%s\" MD \"%s\"",DATA_FOLDER,DATA_FOLDER);
  	if(hint=='d')
    sprintf(chCmd,"IF NOT EXIST \"%s\" MD \"%s\"",DATA_FOLDER,DATA_FOLDER);
	if(hint=='i')
	sprintf(chCmd,"IF NOT EXIST \"%s\" MD \"%s\"",DATA_FOLDER,DATA_FOLDER);


   



    

	/* if data floder not exist, then make one */
	system(chCmd);



    /* if data file not exist, then make one */
	if(hint=='v')
    sprintf(chCmd,"@echo off&IF NOT EXIST \"%s\\%s\" echo VisitorData:>%s\\%s",DATA_FOLDER,VISITOR_DATA_FILE,DATA_FOLDER,VISITOR_DATA_FILE);

	if(hint=='d')
	sprintf(chCmd,"@echo off&IF NOT EXIST \"%s\\%s\" echo VisitorData:>%s\\%s",DATA_FOLDER,VISITOR_DATA_FILE,DATA_FOLDER,VISITOR_DATA_FILE);

	system(chCmd);	


}



/* function for insert a visitor data */
int data__insert_visitor_info(struct visitor *pVstr)
{

	char chPath[60];

   	data__check_file_path('v');

	/* declear a file var */
    FILE *fp;

    /* get file name */
    sprintf(chPath,"%s/%s",DATA_FOLDER,VISITOR_DATA_FILE);
    /* point the data file by at */
    fp = fopen (chPath, "at+");

    /* insert new visitor */
    fprintf( fp,"$$$%d$|%s$|%s$|%d$|%s$|%s$|%s$|%s$|as4|||",pVstr->id,pVstr->name,pVstr->tel,pVstr->vip,pVstr->nationalId,pVstr->nation,pVstr->province,pVstr->city);

    /* close file */
    fclose(fp);

    /* return error num */
	return errno;
}



/* function for locate a peice of info in a file by key words */
int *data__seek_key_word(char chKey[40], FILE *fp,int * nSeek)
{
	int i,j=0;
	char chTmp[strlen(chKey)];

	/* if the length of key words is less than 3, the function will not work */
	if(strlen(chKey)<4)	return NULL;

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
			if(fgetc(fp)==chKey[j++]) ;
			else break;
		}

		/* if found the key word, record its location */
		if(j==strlen(chKey))
		{
			nSeek[++i]=ftell(fp)-strlen(chKey)+1;
			/*active this only for debug purpose*//*printf("%d\n",nSeek[i] );*/
		}
	}

	/* record the times that the key words appeared in the File */
	nSeek[0]=i;

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

	}while(!(fgetc(fp)=='$'&&fgetc(fp)=='$'&&fgetc(fp)=='$'));

	/* adjust the pionter for the following reading*/
	fseek(fp,2,SEEK_CUR); 
	/* read visitor info */
	nItem=0;
	do
	{
		/* only active this for debug purpose */
		/*printf("%c", fgetc(fp));*/
		chTmp[0]='\0';
		i=0;
		/* read visitor info item one by one */
		do
		{
			fseek(fp,-2,SEEK_CUR); /* readjust the pointer*/

			chTmp[i++]=fgetc(fp);

			/* mark when find a '$|' which indicate the end of one item */ 
			nLineCnt_sub=0;
			if(fgetc(fp)=='$')	nLineCnt_sub++;
			if(fgetc(fp)=='|')	nLineCnt_sub++;

			fseek(fp,-2,SEEK_CUR); /* readjust the pointer */

			/* mark when find a '|||' which indicate the end this user info */ 
			nLineCnt=0;
			if(fgetc(fp)=='|')	nLineCnt++;
			if(fgetc(fp)=='|')	nLineCnt++;
			if(fgetc(fp)=='|')	nLineCnt++;
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



/* function for collect info about deleted visitor id */
int *data__get_del_usr_info(int *deled_usr)
{
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
    *deled_usr=nFlen/10;

    /* find each deleted visitor ID */
    for(j++;j<nFlen/10;j++)
    {
    	/* get one ID */
    	for(i=0;i<10;i++)
   	 	{
    		strTmp[i]=fgetc(fp);
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



/* function for get visitors info */
struct visitor *data__get_visitor_info(char value[35],visitor *pVstr)
{
	char chPath[60];

	data__check_file_path('d');

	/* declear a file var */
    FILE *fp;

    /* get file name */
    sprintf(chPath,"%s/%s",DATA_FOLDER,VISITOR_DATA_FILE);
    /* point the data file by at */
    fp = fopen (chPath, "r");

	int *a=NULL;

	/* find visitor info position in File by key words */
	a=data__seek_key_word(value, fp,a);

	/* if no visitor found */
	if(!a){errno=2;return NULL;}

	/* free the memmory of former pVstr */
	free(pVstr);

	/* set a visitor struct array */
	struct visitor visitors[a[0]+4];

	/* point pVstr at visitors */
	pVstr=visitors;

	/* allocate memory for pVstr */
	pVstr=(visitor*)malloc(a[0]*sizeof(visitor));

	/* find all visitor ID which is abandon */
	int *del=data__get_del_usr_info(del);

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

	/* inform return rows of the pVstr*/
	g_nRtrnRows=ii;

   	return pVstr;
}



/* function for delete a visitor info */
int data__del_visitor_info(int id)
{
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

    	/* insert new visitor */
    	fprintf( fp,"%d",id);

    	/* close file */
    	fclose(fp);

    	return 0;
	}
	/* remark error */
	errno=2;
	return 2;
}