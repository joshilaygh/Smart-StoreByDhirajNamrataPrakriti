void displayCodeMatchProd();
void displayNameMatchProd();
void displayQtyProd();

void searchProd(){
	int opt;
	while(1){
		system("cls");
		displayTitleHead();
		printf("\t\t\t**| SEARCH PRODUCT |**\n\n");
		printf("\tSearch Product as:\n\n");
		printf("\tC - Code\n");
		printf("\tN - Name\n");
		printf("\tQ - Quantity");
		displayFooterMenu();
		
		opt= tolower(getch());
		
		switch(opt){
			case 99:  //ASCII value 'c'
				displayCodeMatchProd();
				break;
		
			case 110:  //ASCII value 'n'
				displayNameMatchProd();
				break;
			
			case 113: //ASCII value 'q'
				displayQtyProd();
				break;
	
			case 27:// ASCII 'ESC'
				iMenu();
				break;
				
			case 13:// ASCII 'ENTER'
				searchProd();
				break;
			
			default:
				operateFooter(opt);
				break;
		}
	}
	
}

void displayCodeMatchProd(){
	int fileFound= 0;
	char *found=false, code[15], storedCode[15];
	struct product *p, pd;
	p=&pd;
	system("cls");
	displayTitleHead();
	printf("\n\tSearch Code: ");
	gets(code);
	strlwr(code);
	FILE *temp=fopen("inventory.dat", "r");
	system("cls");
	printf("\n\t------------------------------------------------------------------------------------------------");
	printf("\n\t| Code | Product Name				    |  Quantity  |  Cost Price  |  Sell Price  |");
	printf("\n\t------------------------------------------------------------------------------------------------");
	while(fread(p, sizeof(struct product), 1, temp)){
		strcpy(storedCode, p->code);
		strlwr(storedCode);
		found= strstr(storedCode, code);
		if (found && strlen(code)!=0){
			fileFound=1;
			printf("\n\t| %-5s| %-43s| %-11d| %-13.2f| %-13.2f|", p->code, p->name, p->qty, p->cp, p->sp);
		}
	}
	printf("\n\t------------------------------------------------------------------------------------------------\n");
	fclose(temp);
	if(fileFound==0){
		fileNotFound();
	}
	else{
		getch();
	}
}

void displayNameMatchProd(){
	int fileFound= 0;
	char *found=false, name[60], storedName[60];
	struct product *p, pd;
	p=&pd;
	system("cls");
	displayTitleHead();
	printf("\n\tSearch Name: ");
	gets(name);
	strlwr(name);
	FILE *temp=fopen("inventory.dat", "r");
	system("cls");
	printf("\n\t------------------------------------------------------------------------------------------------");
	printf("\n\t| Code | Product Name				    |  Quantity  |  Cost Price  |  Sell Price  |");
	printf("\n\t------------------------------------------------------------------------------------------------");
	while(fread(p, sizeof(struct product), 1, temp)){
		strcpy(storedName, p->name);
		strlwr(storedName);
		found= strstr(storedName, name);
		if (found && strlen(name)!=0){
			fileFound=1;
			printf("\n\t| %-5s| %-43s| %-11d| %-13.2f| %-13.2f|", p->code, p->name, p->qty, p->cp, p->sp);
		}
	}
	printf("\n\t------------------------------------------------------------------------------------------------\n");
	fclose(temp);
	if(fileFound==0){
		fileNotFound();
	}
	else{
		getch();
	}
}

void displayQtyProd(){
	int fileFound= 0, minQty, maxQty;
	struct product *p, pd;
	p=&pd;
	
	system("cls");
	displayTitleHead();
	printf("\n\tMin Quantity: ");
	scanf("%d", &minQty);
	printf("\n\tMax Quantity: ");
	scanf("%d", &maxQty);
	FILE *temp=fopen("inventory.dat", "r");
	system("cls");
	printf("\n\t------------------------------------------------------------------------------------------------");
	printf("\n\t| Code | Product Name				    |  Quantity  |  Cost Price  |  Sell Price  |");
	printf("\n\t------------------------------------------------------------------------------------------------");
	while(fread(p, sizeof(struct product), 1, temp)){
		if (p->qty >= minQty && p->qty <= maxQty){
			fileFound=1;
			printf("\n\t| %-5s| %-43s| %-11d| %-13.2f| %-13.2f|", p->code, p->name, p->qty, p->cp, p->sp);
		}
	}
	printf("\n\t------------------------------------------------------------------------------------------------\n");
	fclose(temp);
	if(fileFound==0){
		fileNotFound();
	}
	else{
		getch();
	}
}
