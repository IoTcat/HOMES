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
#include "menu.h"
#include "download.h"
#include "maincode.h"
#include "demo.h"




/**************** here are Fundamental Functions ,please don not change these ***********************/



/**************** the above are Fundamental Functions ,please don not change these ***********************/




/*************here are the declearation of some demo functions***********************/


int final_main();

/***************above are the declearation of some demo functions*********************/





/*****************please put your function declearation here!!***********************/




/*****************Above are your function declearation ^_^ ***********************/



/* main function begin */
int main(int argc, char *argv[])
{
	
	/* if the program is aroused by the monitor, update signature and exit */
	data__update_signature(argc, &*argv);
	/* check signature to see if the data has been illegally changed */
	data__check_file_signature();
	/* start monitor event, for the purpose of kill bgm and delete tmp file after user exit */
	data__start_monitor(argv[0]);

	//demo__test_fundamental_functions(); /* Don't Remove This For Test Purpose!! */

	final_main();

	/*************Your Code Here****************/
	//data__room_setup_by_nothing(20181226);
	//data__check_del_by_date(20181219);
	//for(int i=0;i<7;i++)
	//data__room_setup_by_date(20181220+i,20181219);
	//data__revise_room_price_based_on_type(20181219,1,55);
	//data__mark_check_in(20181220,805);
	//data__check_del_by_date(20181218);
	//data__mark_check_out(20181219,805);
	//int Visitordetail[]={1,1234567899};
	//data__insert_userinfo_to_structure(20181219,805,Visitordetail);
	//

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
	
	//download__data(ROOM_DATA_FILE);
	//download__data(VISITOR_DATA_FILE);
	//download__upload();
	//
	//main__room_setup();
	//
	

	//int Visitordetail[4]={1,1234567899};

	//data__insert_userinfo_to_structure(808,20181227,Visitordetail);
	//main__booking();
	
	/*************Your Code Above****************/

	system("echo This is the END of your Main function!!!!&&pause>nul"); /* Remain you of the end of your main function */

	return 0;
}





int final_main()
{

	usr usr;
	char chUsr[]="Welcome!";
	int step=0;
	g_pUsr=chUsr;
	login__setup();
	data__room_setup();

	/********Body********/
	while(1)
	{
		/***********login*****************/
		while(step==0)
		{
			int nUsr=login__choose_usr();

			if(nUsr==1) sprintf(usr.name,"staff");
			else sprintf(usr.name,"manager");

			sprintf(chUsr,"%s",usr.name);

			g_pUsr=chUsr;

			if(login__check_passwd(usr)) 
			{
				if(nUsr!=1)
					step++;
				else
					step=5;
			}
		}

		/**************Manager main menu**********/
		while(step==1)
		{
			int nPnt=menu__main();

			if(nPnt==1) step=2;
			if(nPnt==2) step=3;
			if(nPnt==3) step=4;
			if(nPnt==4) step=0;
			if(nPnt==0||nPnt==5) print__exit();
		}

		/**********Data Setting************/
		while(step==2)
		{
			int nPnt=menu__data_setting();

			if(nPnt==1) {while(1){print__room_type(); printf("\n\n\n\n"); system("echo Please Press esc to quit of press Any Key to Continue...");if(input__detect_input_ASCII()==27) break;if(data__change_price_by_type_final()==0) break;}}
			if(nPnt==2) {while(1){print__room_type(); printf("\n\n\n\n"); system("echo Please Press esc to quit of press Any Key to Continue...");if(input__detect_input_ASCII()==27) break;if(data__change_room_type_final()==0) break;}}
			if(nPnt==3) main__change_visitor_info();
			if(nPnt==0) step=1;
		}

		/**********View Statistics************/
		while(step==3)
		{
			int nPnt=menu__data_statistics();

			if(nPnt==1) main__income();
			if(nPnt==2) main__checkIn();
			if(nPnt==3) {system("cls");printf("Loading...\n"); data__export_room_to_excel();}
			if(nPnt==4) {system("cls");printf("Loading...\n"); data__export_visitor_to_excel();}
			if(nPnt==5) {system("cls");printf("If Windows no feedback for long time, Please close the window with control ^C\n\nUploading...\n");Sleep(2500); download__upload();Sleep(4000);}
			if(nPnt==6)	{system("cls");printf("Downloading...\n"); download__data(VISITOR_DATA_FILE);download__data(VISITOR_DEL_FILE);download__data(ROOM_DATA_FILE);}
			if(nPnt==0)  step=1;
			
			
		}

		/**********Account Setting************/
		while(step==4)
		{
			int nPnt=menu__manager_password();

			if(nPnt==1) login__change_my_passwd();
			if(nPnt==2) login__create_staff_passwd();
			if(nPnt==3) login__clean_staff_passwd();
			if(nPnt==0) step=1;

		}

		/**********Staff Page************/
		while(step==5)
		{
			int nPnt=menu__receptionist();

			if(nPnt==1)  main__booking();
			if(nPnt==2) main__change_visitor_info();
			if(nPnt==3) main__checkIn_re();
			if(nPnt==4) menu__change_check_out();
			if(nPnt==0) print__exit();
			
		}

	}
	return 0;
}

