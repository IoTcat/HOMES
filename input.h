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
