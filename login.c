void userLogin(bool *lStat)
{		
	int i, j=0;
	FILE *fp = fopen("login.txt", "r");
	char userName[20], passWord[20], uName[20], login, ch;
	fscanf(fp, "%[^\n] %[^\n]", userName, passWord);

	do{
		login = 'n';
		system("cls");
		displayTitleHead();
		
		for (i=0; i<3; i++){
			fflush(stdin);
			printf("\tEnter Username: ");
			scanf("%[^\n]", uName);
			fflush(stdin);
			if (strcmp(userName, uName)!=0){
				system("cls");
				displayTitleHead();
				printf("\n\t\t\tIncorrect Username!!!\n\n");
				continue;
			}
				
			printf("\n\tEnter Password: ");
			int j=0;
			char pWord[strlen(passWord)];
			
			while((ch=getch())!=13) //Continue until user press ENTER i.e. inter value 13
			{
			 	pWord[j] = ch;
				printf("*");
				j++;
			}
			pWord[j]='\0';

			if (strcmp(passWord, pWord)!=0){
				system("cls");
				displayTitleHead();		
				printf("\n\t\t\tIncorrect Password!!!\n\n");
				continue;
			}
			else
				*lStat=true;
				printf("\n\n\t\t\t!!!-- Log in Successful --!!!");
				sleep(1);
				system("cls");
				break;				
		}
		if (i==3){
			printf("Try it again after timer expires.\t");
			for (i=5; i>0; i--){
				printf("%2d", i);
				sleep(1);
				printf("\b\b");
			}
			do{
				system("cls");
				displayTitleHead();
				printf("\n\tDo you want to log in again?(Y/N): ");
				login = tolower(getch());
				if (!(login=='y'||login=='n')){
					printf("\n\n\tPlease Enter correct Choice!!!");
					sleep(1);
				}
			}while(!(login=='y'||login=='n'));
		}
	}while (login=='y');
}
