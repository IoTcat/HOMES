/*
Name: Assesment 4 of EEE 101

File Name: main.c

Copyright: Free

Author: Group 9

Description: Program for a hotal management system.
 */



#include <stdio.h>  /* Include standard library of stdio.h */
#include <stdlib.h> /* Include standard liberary of stdlib.h */
#include <conio.h>  /* Include liberary of conio.h  */
#include <string.h>	/* Include string.h */ 
#include <ctype.h>  /* Include ctype.h  */
#include <windows.h> /* lib for include windows API such as msgbox */
#include <time.h>	/* lib for getting system time */
#include <errno.h> /* lib dealing with error */
#include <math.h> /* lib for math */
#include <unistd.h> /* include this lib for multithread processing */
#include <pthread.h> /* include this lib for multithread processing */


/* program title */
#define PROGRAM_TITLE "TITLE EEE101 Assessment 4 BY Group 9"
/* window color */
#define WINDOW_COLOR "color 0F"
/* window size */
#define WINDOW_SIZE "mode con cols=88 lines=30"
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
/* the name of room data file */
#define ROOM_DATA_FILE "Room.txt"
/* the name of visitor del file */
#define VISITOR_DEL_FILE "Del.txt"
/* the name of room del file */
#define ROOM_DEL_FILE "Dell.txt"
/* the name of signature file */
#define SIGNATURE_FILE "Signature.txt"
/* the name of index file */
#define VISITOR_INDEX_FILE "visitorIndex.txt"
/* the name of index file */
#define ROOM_INDEX_FILE "roomIndex.txt"
/* the name of index file */
#define VISITOR_EXCEL_FILE "visitorInfo.csv"
/* the name of index file */
#define ROOM_EXCEL_FILE "roomInfo.csv"
/* the name of passwd file */
#define STAFF_PASSWD_FILE "staffPasswd.txt"
/* the name of passwd file */
#define MANAGER_PASSWD_FILE "managerPasswd.txt"
/* the password of data file */
#define PASSWORD 'l'
/* the digital signature key */
#define DIGITAL_SIGNATURE_KEY 'k'
/* the max size of password */
#define USRPASSWORD_MAX_SIZE 99






/*****************declear global variables ********************/

/* variable of user name ::manager, receptionist*/
char *g_pUsr=NULL;
/* this variable indicate the rows of return struct */ 
int g_nRtrnRows=0;





/************** declear struct here ****************************/


typedef struct usr
{
	char name[10]; /* staff> staff,manager-> manager */
	char passwd[USRPASSWORD_MAX_SIZE];
} usr;



typedef struct visitor
{
	int id;/* unique key for identify visitor */
	char name[NAME_MAX_LENGTH];
	char tel[TEL_MAX_LENGTH];
	unsigned int vip:2;/* 1->not vip, 2->vip */
	char nationalId[NATIONALID_MAX_LENGTH];
	char nation[ADDRESS_MAX_LENGTH];
	char province[ADDRESS_MAX_LENGTH];
	char city[ADDRESS_MAX_LENGTH];

} visitor;



typedef struct room
{
	int index;
	int roomId;
	int date;
	int visitorId[VISITOR_MAX_NUMBER+1];
	/* type: 1->not availzble, 2->**level,3->***level,4->****level,5->VIP */
	int type;
	double price;
	/* checkIn: 1->not visit, 2->visited */
	unsigned int checkIn:2;
	/* checkOut: 1->not out, 2->checkout */
	unsigned int checkOut:2;

} room;

/************** above are the struct declearation ****************************/



/************* include personal lib****************************/
#include "data.h"
#include "input.h"
#include "print.h"
#include "login.h"




/**************** here are Fundamental Functions ,please don not change these ***********************/



/**************** the above are Fundamental Functions ,please don not change these ***********************/




/*************here are the declearation of some demo functions***********************/

int demo__test_fundamental_functions();
int demo__menu();
void demo__print__menu(int nPnt);
void demo__data__insert_visitor_info();
void demo__data__del_visitor_info();
void demo__data__get_visitor_info();
void demo__data__insert_room_info();
void demo__data__del_room_info();
void demo__data__get_room_info();
void demo__create_visitor();
void demo__create_room();
void demo__display_all_visitors();
void demo__display_all_rooms();
int final_main();

/***************above are the declearation of some demo functions*********************/





/*****************please put your function declearation here!!***********************/

void data__room_setup(int quick)
{
	for(int i=0;i<7;i++)
	{
		data__room_setup_by_date(data__get_current_date(0)+i,20181219);
	
		if(!quick)
			data__check_del_by_date(data__get_current_date(0)+i);
	}

}


/*****************Above are your function declearation ^_^ ***********************/



/* main function begin */
int main(int argc, char *argv[])
{
	

	//data__update_signature(argc, &*argv);
	/* start monitor event, for the purpose of kill bgm and delete tmp file after user exit */
	//data__start_monitor(argv[0]);


	//data__check_del_by_date(20181219);
	demo__test_fundamental_functions(); /* Don't Remove This For Test Purpose!! */

	//final_main();

	/*************Your Code Here****************/
	//data__room_setup_by_nothing(20181226);
	//for(int i=0;i<7;i++)
	//data__room_setup_by_date(20181220+i,20181219);
	//data__revise_room_price_based_on_type(20181219,1,55);
	//data__mark_check_in(20181220,805);
	//data__check_del_by_date(20181218);
	//data__mark_check_out(20181219,805);
	//int Visitordetail[]={1,1234567899};
	//data__insert_userinfo_to_structure(20181219,805,Visitordetail);
	//room *pRm=NULL;

	//pRm=data__get_room_info(0/*index*/,0/*roomId*/,20181219/*date*/,NULL/*visitorId*/,0/*type*/,0/*price*/,0/*checkIn*/,0/*checkOut*/,pRm);

	//print__roomId(pRm);

	//data__export_room_to_excel();
	//data__export_visitor_to_excel();

	//print__checkIn_rate(20181220);
	//print__select_date_checkIn();
	//printf("%f\n",data__income_by_date_and_type(20181219, 1) );
	//print__income_by_date(20181219);
	//print__select_date_income();

	//data__room_setup(0);
	//login__change_my_passwd();
	//login__create_staff_passwd();
	//login__clean_staff_passwd();
	//login__setup();
	
	/*************Your Code Above****************/

	system("echo This is the END of your Main function!!!!&&pause>nul"); /* Remain you of the end of your main function */

	return 0;
}





int final_main()
{

	usr usr;

	int nUsr=login__choose_usr();

	if(nUsr==1) sprintf(usr.name,"staff");
	else sprintf(usr.name,"manager");

	login__check_passwd(usr);


	return 0;
}








/*********** demo test function, you can find the demo of most fundamental function here ********/

/* demo guide function*/
int demo__test_fundamental_functions()
{
	printf("Please Press 't' to goto test screen, or press any other key to goto your main fuction!\n");

	if(input__detect_input_ASCII()=='t')
	{
		system("cls");/*clean the screen */
		printf("1. press 'p' to goto input and print fundamental function demo.\n\n");
		printf("2. press 'd' to goto data fundamental function demo.\n\n");
		printf("3. press 'g' to create visitor and room data to support your own code!\n\n");

		/* get user pressed key */
		char tmp_getPress=input__detect_input_ASCII();

		if(tmp_getPress=='p')
		{
			system("cls");/* clean the screen */

			/* initialize the window */
			print__setup();

			/* quit untill press an esc*/
			while(demo__menu()!=6);

			/* quit the demo function */
			return 0;
		}

		if(tmp_getPress=='d')
		{
			system("cls");/* clean the screen */

			printf("Please select:\n\n");
			printf("1. data__insert_visitor_info() demo\n\n");
			printf("2. data__del_visitor_info() demo\n\n");
			printf("3. data__get_visitor_info() demo\n\n\n");
			printf("4. data__insert_room_info() demo\n\n");
			printf("5. data__del_room_info() demo\n\n");
			printf("6. data__get_room_info() demo\n\n");

			tmp_getPress=input__detect_input_ASCII();

			system("cls");/* clean the screen */

			if(tmp_getPress=='1') demo__data__insert_visitor_info();
			if(tmp_getPress=='2') demo__data__del_visitor_info();
			if(tmp_getPress=='3') demo__data__get_visitor_info();
			if(tmp_getPress=='4') demo__data__insert_room_info();
			if(tmp_getPress=='5') demo__data__del_room_info();
			if(tmp_getPress=='6') demo__data__get_room_info();

			system("echo Press any key to goto main()&pause>nul");

		}

		if(tmp_getPress=='g')
		{
			system("cls");

			printf("Please select:\n\n");
			printf("1. Create a visitor data\n\n");
			printf("2. Create a room data\n\n");
			printf("3. Display all visitors\n\n");
			printf("4. Display all rooms\n\n");

			tmp_getPress=input__detect_input_ASCII();

			system("cls");

			if(tmp_getPress=='1')	demo__create_visitor();
			if(tmp_getPress=='2')	demo__create_room();
			if(tmp_getPress=='3')	demo__display_all_visitors();
			if(tmp_getPress=='4')	demo__display_all_rooms();

			system("echo Press any key to goto main()&pause>nul");
		}

		/* clean the screen */
		system("cls");
	}

	return 0;
}



/* demo function for display menu, you can design your menu logic here*/
int demo__menu()
{
	int nVal=54;
	int nArrw=0;
	do
	{
		/* print out the menu */
		demo__print__menu(nVal%6+1);

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
			return 6;

	}while(1);

	/* return user choice by number*/
	return nVal%6+1;
}


/* demo function for printing a menu ,you can design your menu here*/
void demo__print__menu(int nPnt)
{

	/* clear screen */
	system("cls");

	/* print the screen header */
	print__header();

	printf("Please use Arrows on Keyboard to Choose:\n");
	char chItem1[]="Choose 1";
	/* function pringt__item has three parameters: display string, if it is choosed,extra space on its left*/ 
	print__item(chItem1,(nPnt==1)?1:0,0);

	char chItem2[]="Choose 2";
	print__item(chItem2,(nPnt==2)?1:0,0);

	char chItem3[]="Choose 3";
	print__item(chItem3,(nPnt==3)?1:0,0);

	char chItem4[]="Choose 4";
	print__item(chItem4,(nPnt==4)?1:0,0);

	char chItem5[]="Choose 5";
	print__item(chItem5,(nPnt==5)?1:0,0);

	char chItem6[]="Exit   ";
	print__item(chItem6,(nPnt==6)?1:0,0);

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("Press ESC to Exit!");

}


/* demo for data_insert visitor_info() */
void demo__data__insert_visitor_info()
{

	printf("Demo 1:\nThis demo will create a visitor file of yimian. \nto begin with this function, you need a visitor struct which include the visitor info you want to insert. \nYou can see this code in demo__data_insert_visitor_info() function\n\n");

	/* Create a new visitor struct variable with some user info */
	visitor demo_NewVisitor={0/*this is the visitor id, please leave 0 here */,"yimian Liu"/*name*/,"18118155257"/*tel*/,1/*vip*/,"370902199909041813"/*nationalId*/,"china"/*nation*/,"shandong"/*province*/,"taian"/*city*/};

	/* excute the data__insert_visitor_info function and when the function crash, print the error info on screen */
	if(data__insert_visitor_info(&demo_NewVisitor)) printf("Error in Function data__insert_visitor_info: %s\n",strerror(errno));
	else printf("Create successfully!\n");

}



/* demo for data__del_visitor_info */
void demo__data__del_visitor_info()
{
	printf("Demo 2:\nTo delete a visitor info, you need to provide the visitor's ID.\n\n");
	printf("you can see detailed info in demo__data__del_visitor_info()\n\n");
		
	printf("Please input the ID:\n");

	/* get ID input */
	char tmp_visitorId[11];
	while(!scanf("%s",tmp_visitorId)) fflush(stdin);

	/* del the visitor info */
	if(data__del_visitor_info(atoi(tmp_visitorId))) printf("Error in Function data__del_visitor_info: %s\n",strerror(errno));; 

}


/* demo for data__get_visitor_info() */
void demo__data__get_visitor_info()
{
	printf("Demo 3:\nGet Visitors info, index key word is 'china' in this case. \n");
	printf("to search a visitor info, data__get_visitor_info() need a key word and a visitor pointer.\n");
	printf("the key word must be more than three word and the visito info found will be store in the visitor point you provided\n");
	printf("for more info please see demo__data__get_visitor_info() function!\n\n");

	/* provide a key word to search visitors*/
	char tmp_Nation[35]="china";

	/* declear a visitor pointer to receive the matched visitors info */
	struct visitor *pVstr=NULL;
	pVstr= data__get_visitor_info(tmp_Nation,pVstr);

	/* show error hint if the function not runing successfully */
	if(errno)	printf("Error in Function data__get_visitor_info: %s\n",strerror(errno));

	/* deal with situation that nothing found */
	if(!g_nRtrnRows) printf("No visitor found!!\n");

	/* print all these visitors info on screen */
	for(int i=0;i<g_nRtrnRows;i++)
	printf("ID:%d Name:%s Tel:%s VIP:%d NationalID:%s Nation:%s province:%s City:%s\n", (pVstr+i)->id, (pVstr+i)->name, (pVstr+i)->tel,(pVstr+i)->vip, (pVstr+i)->nationalId,(pVstr+i)->nation, (pVstr+i)->province, (pVstr+i)->city);

}


/* demo function for data__insert_room_info() */
void demo__data__insert_room_info()
{
	printf("Demo 4:\nThis demo will create a room file of room 666 in 20181111.\n");
	printf("data__insert_room_info() need the address of a room struct before insert one info.\n");
	printf("for more info please see demo__data__insert_room_info()\n\n");

	/* Create a new visitor struct variable with some user info */
	room demo_NewRoom={0/*this is the visitor id, please leave 0 here */,666/*roomId*/,20181111/*date*/,{2/*visitor number*/,1234567899,1243567899}/*visitorId*/,2/*room type*/,66.66/*price*/,2/*checkIn*/,1/*checkOut*/};

	/* excute the data__insert_visitor_info function and when the function crash, print the error info on screen */
	if(data__insert_room_info(&demo_NewRoom)) printf("Error in Function data__insert_room_info: %s\n",strerror(errno));
	else printf("Create successfully!\n");

}



/* demo for data__del_room_info() */
void demo__data__del_room_info()
{
	printf("Demo 5:\nTo delete a room info, you need to provide the index and the roomId.\n\n");
	printf("See more in function demo__data__del_room_info()\n\n" );

		printf("Please input the Index:\n");

		/* get index input */
		char tmp_roomIndex[11];
		while(!scanf("%s",tmp_roomIndex)) fflush(stdin);

		printf("Please input the RoomId:\n");

		/* get room input */
		char tmp_roomId[11];
		while(!scanf("%s",tmp_roomId)) fflush(stdin);

		/* del the visitor info */
		if(data__del_room_info(atoi(tmp_roomIndex),atoi(tmp_roomId))) printf("Error in Function data__del_room_info: %s\n",strerror(errno));
}



void demo__data__get_room_info()
{
	printf("Demo 6:\nGet room info, you need to set one or more condition, and the function will return all the room info which satisfy your condition.\n");
	printf("to learn more please see demo__data__get_room_info()\n\n");
	printf("in this case, we had set some condition for rooms searching.\n");
	printf("You can find more detail in function demo__data__get_room_info()\n\n");

	/* declear a room pointer to receive the matched rooms info */
	struct room *pRm=NULL;

	int hh[]={2/* number of visitors*/,1234567899/* visitorId*/,1243567899/* visitorId*/};
	pRm= data__get_room_info(0/*index*/,666/*roomId*/,0/*date*/,hh/*visitorId*/,2/*type*/,0/*price*/,0/*checkIn*/,1/*checkOut*/,pRm);

	/* show error hint if the function not runing successfully */
	if(!pRm)	printf("Error in Function data__get_room_info: %s\n",strerror(errno));

	/* deal with situation that nothing found */
	if(!g_nRtrnRows) printf("No room found!!\n");

	/* print all these rooms info on screen */
	for(int i=0;i<g_nRtrnRows;i++)
	printf("Index:%d Room:%d date:%d VisitorNum:%d Type:%d Price:%f CheckIn:%d CheckOut:%d\n", (pRm+i)->index, (pRm+i)->roomId, (pRm+i)->date,(pRm+i)->visitorId[0], (pRm+i)->type,(pRm+i)->price, (pRm+i)->checkIn, (pRm+i)->checkOut);

}


/* function for create a visitor*/
void demo__create_visitor()
{
	visitor demo_NewVisitor;

	printf("Please input a name:\n");
	while(!scanf("%s",demo_NewVisitor.name)) fflush(stdin);

	printf("Please input a tel:\n");
	while(!scanf("%s",demo_NewVisitor.tel)) fflush(stdin);

	printf("Please input if it is vip (not vip->1,vip->2) :\n");
	char tmp_ch[15];
	while(!scanf("%s",tmp_ch)) fflush(stdin);
	demo_NewVisitor.vip=atoi(tmp_ch);

	printf("Please input a nationalId:\n");
	while(!scanf("%s",demo_NewVisitor.nationalId)) fflush(stdin);

	printf("Please input a nation:\n");
	while(!scanf("%s",demo_NewVisitor.nation)) fflush(stdin);

	printf("Please input a province:\n");
	while(!scanf("%s",demo_NewVisitor.province)) fflush(stdin);

	printf("Please input a city:\n");
	while(!scanf("%s",demo_NewVisitor.city)) fflush(stdin);

	demo_NewVisitor.id=0;

	/* excute the data__insert_visitor_info function and when the function crash, print the error info on screen */
	if(data__insert_visitor_info(&demo_NewVisitor)) printf("Error in Function data__insert_visitor_info: %s\n",strerror(errno));
	else printf("Create successfully!\n");
}


void demo__create_room()
{

	room demo_NewRoom={0/*this is the visitor id, please leave 0 here */,666/*roomId*/,20181111/*date*/,{2/*visitor number*/,1234567899,1243567899}/*visitorId*/,2/*room type*/,66.66/*price*/,2/*checkIn*/,1/*checkOut*/};

	char tmp_ch[25];

	printf("Please input a roomId (e.g. 205):\n");
	while(!scanf("%s",tmp_ch)) fflush(stdin);
	demo_NewRoom.roomId=atoi(tmp_ch);

	printf("Please input a date (e.g. 20181111):\n");
	while(!scanf("%s",tmp_ch)) fflush(stdin);
	demo_NewRoom.date=atoi(tmp_ch);

	printf("Please input the number of visitors:\n");
	int tmp_vNum=0;
	while(!scanf("%s",tmp_ch)) fflush(stdin);
	tmp_vNum=atoi(tmp_ch);

	if(tmp_vNum)
	{
		for(int i=0;i<tmp_vNum;i++)
		{
			printf("Please input visitors Id\n");
			while(!scanf("%s",tmp_ch)) fflush(stdin);
			demo_NewRoom.visitorId[i+1]=atoi(tmp_ch);
		}
	}

	demo_NewRoom.visitorId[0]=tmp_vNum;

	printf("Please input a room type (e.g. 1,2,3,4,5):\n");
	while(!scanf("%s",tmp_ch)) fflush(stdin);
	demo_NewRoom.type=atoi(tmp_ch);

	printf("Please input a price (e.g. 205.5):\n");
	while(!scanf("%s",tmp_ch)) fflush(stdin);
	demo_NewRoom.price=atof(tmp_ch);

	printf("Please input if it is checkIn (not In->1, In->2):\n");
	while(!scanf("%s",tmp_ch)) fflush(stdin);
	demo_NewRoom.checkIn=atoi(tmp_ch);

	printf("Please input if it is checkOut (not Out->1, Out->2):\n");
	while(!scanf("%s",tmp_ch)) fflush(stdin);
	demo_NewRoom.checkOut=atoi(tmp_ch);


	/* excute the data__insert_visitor_info function and when the function crash, print the error info on screen */
	if(data__insert_room_info(&demo_NewRoom)) printf("Error in Function data__insert_room_info: %s\n",strerror(errno));
	else printf("Create successfully!\n");
}



void demo__display_all_visitors()
{
	char tmp_chTmp[35];
	tmp_chTmp[0]='\0';
	/* declear a visitor pointer to receive the matched visitors info */
	struct visitor *pVstr=NULL;
	pVstr= data__get_visitor_info(tmp_chTmp,pVstr);

	/* show error hint if the function not runing successfully */
	if(!pVstr)	printf("Error in Function data__get_visitor_info: %s\n",strerror(errno));

	/* print all these visitors info on screen */
	for(int i=0;i<g_nRtrnRows;i++)
	printf("ID:%d Name:%s Tel:%s VIP:%d NationalID:%s Nation:%s province:%s City:%s\n", (pVstr+i)->id, (pVstr+i)->name, (pVstr+i)->tel,(pVstr+i)->vip, (pVstr+i)->nationalId,(pVstr+i)->nation, (pVstr+i)->province, (pVstr+i)->city);
}



void demo__display_all_rooms()
{
	/* declear a room pointer to receive the matched rooms info */
	struct room *pRm=NULL;

	pRm= data__get_room_info(0/*index*/,0/*roomId*/,0/*date*/,NULL/*visitorId*/,0/*type*/,0/*price*/,0/*checkIn*/,0/*checkOut*/,pRm);

	/* show error hint if the function not runing successfully */
	if(!pRm)	printf("Error in Function data__get_room_info: %s\n",strerror(errno));

	/* print all these rooms info on screen */
	for(int i=0;i<g_nRtrnRows;i++)
	printf("Index:%d Room:%d date:%d VisitorNum:%d Type:%d Price:%f CheckIn:%d CheckOut:%d\n", (pRm+i)->index, (pRm+i)->roomId, (pRm+i)->date,(pRm+i)->visitorId[0], (pRm+i)->type,(pRm+i)->price, (pRm+i)->checkIn, (pRm+i)->checkOut);

}

/***************above are the demo function********************/











/**********!!!!!!!!Fundamental Functions Here::Please do not change these unless you are forced to do!!!!!!!!!***********/









/***********!!!!!!!!!!above are fundamental functions!!!!!!!!!************/