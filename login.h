/* demo function for display menu, you can design your menu logic here*/
int login__choose_usr()
{
	int nVal=54;
	int nArrw=0;
	print__setup();
	do
	{
		/* print out the menu */
		print__login(nVal%2+1);

		/* detect user keyboard press*/
		nArrw= input__get_arrow();

		/* when input a arrow */
		if(nArrw==1||nArrw==-1)
			nVal+=nArrw;

		/* when press enter */
		if(nArrw==6)
        {
            return(nVal%2+1);
            break;
        }

		/* when press esc */
		if(nArrw==9)
			print__exit();

	}while(1);

	/* return user choice by number*/
	return nVal%2+1;
}







/* function for create password*/
int login__create_passwd(usr usr)
{

	int words=0,times=0;
	char tmp_word=0;
	char tmp_psswd[40];

	while(1)
	{
		usr.passwd[0]='\0';
		while(1)
		{
			print__get_newpassword(times,words);

			tmp_word=input__detect_input_ASCII();
			/* esc*/
			if(tmp_word==27) return 0;
			/* enter*/
			if(tmp_word==13) break;
			/*backspace*/
			if(tmp_word==8) 
			{
				if(words>0)
				{
					words--;
					usr.passwd[words]='\0';
				}
			}
			/* words*/
			if(tmp_word>32&&tmp_word<127) 
			{
				usr.passwd[words]=tmp_word;
				words++;
				usr.passwd[words]='\0';
			}

		}
		times++;
		words=0;
		tmp_psswd[0]='\0';
		/*get the passwd input again if it's legal*/
		while(!(usr.passwd[0]=='\0'||strlen(usr.passwd)<3||strlen(usr.passwd)>30))
		{
			print__get_newpassword(times,words);

			tmp_word=input__detect_input_ASCII();
			/* esc*/
			if(tmp_word==27) return 0;
			/* enter*/
			if(tmp_word==13) break;
			/*backspace*/
			if(tmp_word==8) 
			{
				if(words>0)
				{
					words--;
					tmp_psswd[words]='\0';
				}
			}

			if(tmp_word>32&&tmp_word<127) 
			{
				tmp_psswd[words]=tmp_word;
				words++;
				tmp_psswd[words]='\0';
			}

		}

		if(usr.passwd[0]=='\0')
		{
		
			system("cls");
			printf("Your password contains NOTHING!!!\n");
			Sleep(2500);

			times=-1;
		}

		else if(strlen(usr.passwd)<3||strlen(usr.passwd)>30)
		{
		
			system("cls");
			printf("Your password length should between 3 and 30!!!\n");
			Sleep(2500);

			times=-1;
		}

		else if(usr.passwd[0]!='\0'&&!strcmp(usr.passwd,tmp_psswd)) break;

		times++;
		words=0;
	}

	char *key=NULL;
	char tmp[50];
	char staff[]="staff";

	sprintf(tmp,"%s",data__encode_password(usr,key));

	data__insert_psswd_online(tmp, (strcmp(usr.name,staff)?2:1));

	return 1;
}

/*function for check password*/
int login__check_passwd(usr usr)
{
	int words=0,times=0;
	char tmp_word=0;

	while(1)
	{
		/* get password input*/
		while(1)
		{
			print__get_password(times,words);

			tmp_word=input__detect_input_ASCII();
			/* when press esc*/
			if(tmp_word==27) return 0;
			/* when press enter*/
			if(tmp_word==13) break;
			/* when press backpace<-*/
			if(tmp_word==8) 
			{
				if(words>0)
				{
					words--;
					usr.passwd[words]='\0';
				}
			}
			/* filter*/
			if(tmp_word>32&&tmp_word<127) 
			{
				usr.passwd[words]=tmp_word;
				words++;
				usr.passwd[words]='\0';
			}
		}


		char *key=NULL;
		int *ifPasswd=NULL;
		FILE *fp=NULL;

  		 char chPath[50];

  		  /* get file name */
   		 if(usr.name[0]=='s')
   		 sprintf(chPath,"%s/%s",DATA_FOLDER,STAFF_PASSWD_FILE);
  		 else
   		 sprintf(chPath,"%s/%s",DATA_FOLDER,MANAGER_PASSWD_FILE);

		fp=fopen(chPath,"r");
		char tmp[50];
		sprintf(tmp,"%s",data__encode_password(usr,key));
		/* check is passwd exist*/
		ifPasswd =data__seek_key_word_former(tmp, fp,ifPasswd);

		fclose(fp);
		/* if exist*/
		if(ifPasswd[0]) return 1;
		/* input time ++*/
		times++;
		/* reset*/
		tmp_word=0;
		words=0;
		/* if wrong for more than 5 times*/
		if(times>5)
		{
			system("cls&&color 4F");

			printf("\nPassword is wrong for more than 5 times!!  Program will quit in 2 Seconds!\n");
			Sleep(3000);

			exit(-1);
		}
	}

}




int login__change_my_passwd()
{
	usr usr={"manager","123"};
	
	if(!login__check_passwd(usr)) return 0;
	login__create_passwd(usr);
	return 0;
}

int login__create_staff_passwd()
{
	usr usr={"manager","123"};
	
	if(!login__check_passwd(usr)) return 0;

	sprintf(usr.name,"staff");
	login__create_passwd(usr);
	return 0;
}


int login__clean_staff_passwd()
{
	char chPath[60];

	sprintf(chPath,"del /Q %s\\%s>nul",DATA_FOLDER,STAFF_PASSWD_FILE);

	int i;usr usr={"manager","123"};
	i=MessageBox(NULL,"This Action Should Only be executed in case of an emergency. Are Your Sure to CLEAN ALL the staff password? ","AS4 Message",MB_YESNO);
	if(i==IDYES&&login__check_passwd(usr)) 
		{system(chPath);		

		char chPath2[90];

		sprintf(chPath2,"if exist %s\\%s (echo >nul)else (echo g48xQ5l05mvy6u30vzd20UK7g48xQ5l05mvy6>%s\\%s)>nul",DATA_FOLDER,STAFF_PASSWD_FILE,DATA_FOLDER,STAFF_PASSWD_FILE);

		system(chPath2);}
	return 0;
}

void login__setup()
{
	char chPath[60];


	sprintf(chPath,"%s/%s",DATA_FOLDER,MANAGER_PASSWD_FILE);


	if(fopen(chPath,"r")==NULL)
	{
		MessageBox( 0, "Successful initialized! Please open again to run the program!", "AS4 Message", 0 );
		
		sprintf(chPath,"if exist %s\\%s (echo >nul)else (echo g48xQ5l05mvy6u30vzd20UK7g48xQ5l05mvy6>%s\\%s)>nul",DATA_FOLDER,MANAGER_PASSWD_FILE,DATA_FOLDER,MANAGER_PASSWD_FILE);

		system(chPath);
		sprintf(chPath,"if exist %s\\%s (echo >nul)else (echo g48xQ5l05mvy6u30vzd20UK7g48xQ5l05mvy6>%s\\%s)>nul",DATA_FOLDER,STAFF_PASSWD_FILE,DATA_FOLDER,STAFF_PASSWD_FILE);

		system(chPath);

		exit(0);

	}



}
