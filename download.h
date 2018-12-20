
void download__data(char chName[20])
{
	/* declear a file var */
    FILE *fp;
    char chDos[30];

 	sprintf(chDos,"del /Q data\\%s>nul",chName);

 	int nRnd=rand()%4;
 	char chSign[3];
 	if(nRnd==0)	strcpy( chSign,"\\");
  	if(nRnd==1)	strcpy(  chSign,"/");
   	if(nRnd==2)	strcpy( chSign,"-");
    if(nRnd==3)	strcpy( chSign,"|");
 	system("cls");
 	printf("Updating Local Data from Internet...  %s\n",chSign);
    system(chDos);
    /* point the data file by user name */
    fp = fopen ("data_online.vbs", "w+");

	fprintf( fp,"Dim Url, Target \nUrl = \"http://yimian.xyz/file/ee101/as4/data/%s\" \nTarget =  \"%s/%s\" \nDownload Url,Target \nSub Download(url,target) \n  Const adTypeBinary = 1 \n  Dim http,ado  \n  Const adSaveCreateOverWrite = 2 \n  Set http = CreateObject(\"Msxml2.ServerXMLHTTP\") \n  http.open \"GET\",url,False \n  http.send \n  Set ado = createobject(\"Adodb.Stream\") \n  ado.Type = adTypeBinary \n  ado.Open \n  ado.Write http.responseBody \n  ado.SaveToFile target \n  ado.Close \nEnd Sub ",chName,DATA_FOLDER,chName);


    /* close file */
    fclose(fp);


        /* point the data file by user name */
    fp = fopen ("start_data_online.vbs", "w+");

	fprintf( fp,"dim  strvbs\nstrvbs = \"data_online.vbs\" \nset oshell = createobject(\"wscript.shell\")\noshell.run strvbs,false,false");


    /* close file */
    fclose(fp);

	system("wscript start_data_online.vbs");

	system("del /Q start_data_online.vbs>nul");

}


void * p_1(void *a)
{
	system("ftp -n -s:\"ftp1.txt\"");
    return NULL;
}

void * p_2(void *a)
{
	system("ftp -n -s:\"ftp2.txt\"");
    return NULL;
}

void * p_3(void *a)
{
	system("ftp -n -s:\"ftp3.txt\"");
    return NULL;
}


void download__upload()
{
	FILE *fp;

    /* point the data file by user name */
    fp = fopen ("ftp1.txt", "w+");

	fprintf( fp,"open yimian.xyz\nuser as4 as4\nput %s\\%s\nbye",DATA_FOLDER,ROOM_DATA_FILE);

    /* close file */
    fclose(fp);

    /* point the data file by user name */
    fp = fopen ("ftp2.txt", "w+");

	fprintf( fp,"open yimian.xyz\nuser as4 as4\nput %s\\%s\nbye",DATA_FOLDER,VISITOR_DATA_FILE);

    /* close file */
    fclose(fp);


    /* point the data file by user name */
    fp = fopen ("ftp3.txt", "w+");

	fprintf( fp,"open yimian.xyz\nuser as4 as4\nput %s\\%s\nbye",DATA_FOLDER,VISITOR_DEL_FILE);

    /* close file */
    fclose(fp);


    pthread_t t1,t2,t3;

    pthread_create(&t1, NULL, p_1, NULL);
    pthread_create(&t2, NULL, p_2, NULL);
    pthread_create(&t3, NULL, p_3, NULL);

}