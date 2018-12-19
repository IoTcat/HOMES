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

int data__change_room_info(int,int,int,int,struct room *);
/*int data__initialize_pointer(int **);
int data__allocate_room_to_pointer_array(int **);*/
int data__allocate_room_to_array(int *);
int data__initialize_room_array(int *);
int data__correspond_input_to_array(int);
int data__allocate_type_to_room(int*);
int data__allocate_price_to_room(int*);
int data__initialize_room_structure(room*,int*,int*,int*);

int data__revise_room_price_based_on_type(int,int,double);
int data__mark_check_in(int,int);
int data__mark_check_out(int,int);
int data__insert_userinfo_to_structure(int,int,int*);
int data__filter_input(char*);

int menu__data_statistics();
int menu__data_setting();
int menu__receptionist();
int menu__manager_password();
int menu__main();

/*****************Above are your function declearation ^_^ ***********************/



/* main function begin */
int main(int argc, char const *argv[])
{
	demo__test_fundamental_functions(); /* Don't Remove This For Test Purpose!! */

	//final_main();

	/*************Your Code Here****************/
    /* initialize the window */
    //print__setup();
    //menu__main();

	/*interface*/
	//char choosec[2];
	//room demo_NewRoom={0/*this is the visitor id, please leave 0 here */,666/*roomId*/,20181111/*date*/,{2/*visitor number*/,1234567899,1243567899}/*visitorId*/,2/*room type*/,66.66/*price*/,2/*checkIn*/,1/*checkOut*/};
	//int ce3=0;/*Used for quit the program*/
	/*int *RP[80];
	int *DP[80];
	data__initialize_pointer(RP);
	data__initialize_pointer(DP);*/

	//room r2={0,205,20180921,{0},2,289,1,1};

	//data__insert_room_info(&r2);
    //data__revise_room_price_based_on_type(int Date,int Type,double Price)
    //data__mark_check_in(int Date,int RoomNo)
    //data__mark_check_out(int Date,int RoomNo)
    //data__insert_userinfo_to_structure(int Date,int RoomNo,int* Visitordetail)
    //data__filter_input(char*parameter1)


    //menu__data_statistics();
    //menu__data_setting();
    //menu__receptionist();
    //menu__manager_password();
    //menu__main();
    while(1)
    {
        system("cls");
        printf("Please enter a number\n\n");
        char in[10];
        gets(in);
        int baby=atoi(in);
        int yes=data__get_current_date(baby);
       printf("Today is %d",yes);
       system("pause");
    }







	/*************Your Code Above****************/

	system("echo This is the END of your Main function!!!!&&pause>nul"); /* Remain you of the end of your main function */

	return 0;
}

/*********** My own function (staring line) ********/
int data__revise_room_price_based_on_type(int Date,int Type,double Price)
{
    int vid[4];
    vid[0]=0;
    struct room *pts=NULL;
    pts=data__get_room_info(0,0,Date,vid,Type,0,0,0,pts);

    system("pause");
    for(int i=0;i<g_nRtrnRows;i++)
    {
        (pts+i)->price=Price;
        data__del_room_info((pts+i)->index,(pts+i)->roomId);
        data__insert_room_info(pts+i);
    }
    return 0;


}

int data__mark_check_in(int Date,int RoomNo)
{
    int vid[4];
    vid[0]=0;
    struct room *pts=NULL;
    pts=data__get_room_info(0,RoomNo,Date,vid,0,0,0,0,pts);
    pts->checkIn=2;
    data__del_room_info(pts->index,pts->roomId);
    data__insert_room_info(pts);
    return 0;

}

int data__mark_check_out(int Date,int RoomNo)
{
    int vid[4];
    vid[0]=0;
    struct room *pts=NULL;
    pts=data__get_room_info(0,RoomNo,Date,vid,0,0,0,0,pts);
    pts->checkOut=2;
    data__del_room_info(pts->index,pts->roomId);
    data__insert_room_info(pts);
    return 0;

}

int data__insert_userinfo_to_structure(int Date,int RoomNo,int* Visitordetail)
{
    struct room *pts=NULL;
    int vid[4];
    vid[0]=0;
    pts=data__get_room_info(0,RoomNo,Date,vid,0,0,0,0,pts);
    for(int i=0;i<4;i++)
    {
    pts->visitorId[i]=Visitordetail[i];
    }
    data__del_room_info(pts->index,pts->roomId);
    data__insert_room_info(pts);

    return 0;
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



void menu__print_main(int nPnt)
{

	/* clear screen */
	system("cls");

	/* print the screen header */
	print__header();

	printf("\n\nPlease use Arrows on Keyboard to Select:\n");
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

int data__change_room_type(int roomNo,int Type)
{
    room *pts=NULL;
    int i;
    for(i=0;i<8;i++)
    {
        int currentdate=data__get_current_date(i);
        pts=data__get_room_info(0,roomNo,currentdate,NULL,0,0,0,0,pts);
        pts->type=Type;
    }
    if(i==8)
        return 1;
    else
        return 0;


}

//--------------------------------------------------------------------------------------------------------------//
int data__change_room_info(int room,int date,int roomNo,int roomdate,struct room *container)
{
    if(!data__get_room_info(0,room,date,"NULL",0,0,0,0,&container))
    {
       container->roomId=roomNo;
       container->date=date;
       container->price=100;/*Needs a price list 100 is just an example to let the program run*/
       container->index=0;
       container->visitorId[0]=0;
       container->type=2;/*Needs a parameter which records the type for every room*/
       container->checkIn=1;/*Needs nothing*/
       container->checkOut=1;/*Needs nothing*/
       data__insert_room_info(&container);
    }

}



int data__allocate_type_to_room(int*initialtype)
{
    int i;
    for(i=0;i<20;i++)
    {
        initialtype[i]=1;
    }
    for(i=20;i<40;i++)
    {
        initialtype[i]=2;
    }
    for(i=40;i<60;i++)
    {
        initialtype[i]=3;
    }
    for(i=60;i<80;i++)
    {
        initialtype[i]=10;
    }
    if(i==80)
        return 1;
    else
        return 2;
}

int data__allocate_price_to_room(int* initialprice)
{
    int i;
    for(i=0;i<20;i++)
    {
        initialprice[i]=200;
    }
    for(i=20;i<40;i++)
    {
        initialprice[i]=300;
    }
    for(i=40;i<60;i++)
    {
        initialprice[i]=400;
    }
    for(i=60;i<80;i++)
    {
        initialprice[i]=1000;
    }
    if(i==80)
        return 1;
    else
        return 2;
}

int data__initialize_room_array(int *ptr)
{
    int i;
    for(i=0;i<80;i++)
    {
        ptr[i]=0;
    }
    if(i==80)
    {
        return 1;
    }
    else
    {
        return 10;
    }
}

/*int data__initialize_room_structure(room* ptr,int*roomNo,int*price,int*type)
{
    int i=0;
    for(i=0;i<80;i++)
    {
        roomNo[i]->roomId=roomNo[i];

    }
}*/

int data__allocate_roomNo_to_array(int *ptr)
{
    int i;
    int unit;
    unit=1;
    for(i=0;i<10;i++)
    {
        ptr[i]=100+unit;
        unit++;
    }

    unit=1;
    for(i=10;i<20;i++)
    {
        ptr[i]=200+unit;
        unit++;
    }

    unit=1;
    for(i=20;i<30;i++)
    {
        ptr[i]=300+unit;
        unit++;
    }

    unit=1;
    for(i=30;i<40;i++)
    {
        ptr[i]=400+unit;
        unit++;
    }

    unit=1;
    for(i=40;i<50;i++)
    {
        ptr[i]=500+unit;
        unit++;
    }

    unit=1;
    for(i=50;i<60;i++)
    {
        ptr[i]=600+unit;
        unit++;
    }

    unit=1;
    for(i=60;i<70;i++)
    {
        ptr[i]=700+unit;
        unit++;
    }

    unit=1;
    for(i=70;i<80;i++)
    {
        ptr[i]=800+unit;
        unit++;
    }

    i=0;
    while(1)
    {

        if(ptr[i]!=0)
        {
            i++;
            if(i==80)
            break;

        }
        else
            break;
    }
    if(i==80)
        return 1;
    else
        return 10;

}

int data__correspond_input_to_array(int input)
{
    int gewei;
    int shiwei;
    shiwei=input/100-1;
    gewei=input%100-1;
    return (shiwei*10+gewei);
}
/*int data__initialize_pointer(int **ptr)
{
    int i;
    for(i=0;i<80;i++)
    {
        ptr[0]=NULL;
    }
    if(i==80)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

int data__allocate_room_to_pointer_array(int **ptr)
{
    int i;
    for(i=0;i<10;i++)
    {

    }
}*/
/*********** My own function (End line) ********/



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
