void confirmLOut()
{
	int confirm;
	system("cls");
	displayTitleHead();
	fflush(stdin);
	
	displayLogOutOption();
	confirm = tolower(getch());
	
	if (confirm==13){
		system("cls");
		displayTitleHead();
		printf("\n\n\t\tYou are Logged Out.\n");
		printf("\n\n\t\t*** THANK YOU ***\n\n");
		exit(0);
	}
	else if(confirm==27){
		system("cls");
		displayTitleHead();
		printf("\n\n\t\t\tGetting Back to program...\n\n");
		sleep(1);
		system("cls");
	}
	else{
		invalidInput();
		confirmLOut();
	}
}

int operateFileOption(int opt){
	switch(opt)
	{
		case 27:  //ASCII value 'ESC'
			return 0;
			
		case 19: //ASCII value 'CTRL+S'
			return 1;
			
		default:
			return 2;
	}
}
int operateProdOption(int opt){
	switch(opt)
	{
		case 27:  //ASCII value 'ESC'
			return 0;
			
		default:
			return 1;
	}
}

int operateLogOutOption(int opt){
	switch(opt)
	{		
		case 13: //ASCII value 'ENTER'
			return 1;
		
		case 27:  //ASCII value 'ESC'
			return 0;
			
		default:
			invalidInput();
			return -1;
	}
}

void operateFooter(int opt){
	switch(opt){		
		case 105: //ASCII value 'i'
			iMenu();
			break;
		
		case 112: //ASCII value 'p'
			pMenu();
			break;
		
		case 115: //ASCII value 's'
			sMenu();
			break;
		
		case 114: //ASCII value 'r'
			invReportMenu();
			break;
		
		case 120: //ASCII value 'x'
			confirmLOut();
			break;
		
		default:
			invalidInput();
			break;
	}
}

int doCodeExist(char *code, struct product *p){
	FILE *fp=fopen("inventory.dat", "r");
	if(fp==NULL){
		printf("File doesn't exist or Can't open file");
	}
	else{
		while(fread(p, sizeof(struct product), 1, fp)){
			if(strcmp(code, p->code)==0){
				fclose(fp);
				return 1;
			}
		}
		fclose(fp);
		return 0;
	}
}

int isSPValid(struct product *p){
	if (p->cp <= p->sp){
		return 1;
	}
	else{
		return 0;
	}
}

int isProdAdded(struct product *t, char *code, int n){
	int i;
	for(i=0; i<n; i++){
		if(!strcmp(t[i].code, code)){
			return 1;
		}
	}
	return 0;
}

void findMonthDays(int *mDays, int d, int m, int y){
	int leapYear;
	if (y%400==0){
		leapYear= 1;
	}
	else if (y%100==0){
		leapYear= 0;
	}
	else if (y%4==0){
		leapYear= 1;
	}
	else{
		leapYear= 0;
	}
	
	if(m==2 && !leapYear){
		*mDays= 28;
	}
	else if (m==2 && leapYear){
		*mDays= 29;
	}
	else if ( m==4 || m==6 || m==9 || m==11){
		*mDays= 30;
	}
	else{
		*mDays= 31;
	}
}
