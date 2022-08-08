void arrangeCodewise(struct product *, struct product, int);
void arrangeNamewise(struct product *, struct product, int);
void display_t_Struct(struct product *, int, int);

void displayProd(){
	system("cls");
	displayTitleHead();
	printf("\t\t\t**| DISPLAY PRODUCT |**\n\n");
	FILE *fp=fopen("inventory.dat", "r");
	struct product pd, *p, *t, temp;
	p=&pd;
	int dSize, opt, sn=0, n=0, i=0, j;
	
	while(fread(p, sizeof(struct product), 1, fp)) 
	{
		n++; //to find the number of products
	}
	fseek(fp, 0, 0); //set file pointer to the beginning again
	
	t= (struct product *)malloc(n * sizeof(struct product)); //dynamically allocating size for temporary structure t
	
	printf("\n\tDisplay Size: ");
	scanf("%d", &dSize);
	
	printf("\n\n");
	printf("\tC - Codewise\n");
	printf("\tN - Namewise");
	displayFooterMenu();
	opt= tolower(getch());
	
	while(fread(p, sizeof(struct product), 1, fp)){
		t[i] = *p; //copy each structure product file in temporary structure t
		i++;
	}
	fseek(fp, 0, 0); //set file pointer in the beginning
	
	switch(opt){
		case 99:  //ASCII value 'c'
			arrangeCodewise(t, temp, n);
			display_t_Struct(t, n, dSize);
			break;
		
		case 110:  //ASCII value 'n'
			arrangeNamewise(t, temp, n);
			display_t_Struct(t, n, dSize);
			break;

		case 27:// ASCII 'ESC'
			free(t);
			fclose(fp);
			return;
			
		case 13:// ASCII 'ENTER'
			free(t);
			fclose(fp);
			displayProd();
			break;
		
		default:
			free(t);
			fclose(fp);
			operateFooter(opt);
			break;
	}
	free(t);
	fclose(fp);
	iMenu();
}

void arrangeCodewise(struct product *t, struct product temp, int n){
	int i, j;
	for (i=0; i<n-1; i++){
		for(j=i+1; j<n; j++){
			//if(strcmp(t[i].code,t[j].code)==1){ //to compare code as string
			if(atoi(t[i].code)>atoi(t[j].code)){  //to compare code as integer (atoi(str) converts string into integer)
				temp= t[i];
				t[i]= t[j];
				t[j]= temp;
			}
		}
	}
}

void arrangeNamewise(struct product *t, struct product temp, int n){
	int i, j;
	for (i=0; i<n-1; i++){
		for(j=i+1; j<n; j++){
			if(strcmp(t[i].name,t[j].name)==1){
				temp= t[i];
				t[i]= t[j];
				t[j]= temp;
			}
		}
	}
}

void display_t_Struct(struct product *t, int n, int dSize){
	int i, sn=0;
	system("cls");
	printf("\n\t--------------------------------------------------------------------------------------------------------");
	printf("\n\t| SN  | Code    | Product Name			  |  Quantity  |  Cost Price  |  Sell Price  |  Stock  |");
	printf("\n\t--------------------------------------------------------------------------------------------------------");
	
	for(i=0; i<n; i++){
		sn++;
		printf("\n\t|%4d | %7s | %-32s|%11d |%13.2f |%13.2f |", sn, t[i].code, t[i].name, t[i].qty, t[i].cp, t[i].sp);
		if(t[i].qty<minQ)
			printf(" REORDER |");
		else
			printf("         |");
		if(sn%dSize==0){
			getch();
		}
	}
	printf("\n\t--------------------------------------------------------------------------------------------------------");
	getch();
}

void displayCodeProd(char *code){
	FILE *fp=fopen("inventory.dat", "r");
	struct product pd, *p;
	p=&pd;
	if(fp==NULL){
		printf("File doesn't exist or Can't open file");
	}
	else{
		system("cls");
		printf("\n\t------------------------------------------------------------------------------------------------");
		printf("\n\t| Code | Product Name				    |  Quantity  |  Cost Price  |  Sell Price  |");
		printf("\n\t------------------------------------------------------------------------------------------------");
		while(fread(p, sizeof(struct product), 1, fp)){
			if(strcmp(code, p->code)==0){
				printf("\n\t| %-5s| %-43s| %-11d| %-13.2f| %-13.2f|", p->code, p->name, p->qty, p->cp, p->sp);	
			}
		}
		printf("\n\t------------------------------------------------------------------------------------------------\n");
	}
	fclose(fp);
}

void displayProdPurchaseList(long int fDate, long int tDate){
	struct product *p, pd;
	p=&pd;
	long int totalDate;
	FILE *purchase= fopen("purchase.dat", "r");
	if(purchase==NULL){
		printf("\nFile doesn't exist or Can't open file.");
	}
	else{
		while (fread(p, sizeof(struct product), 1, purchase)){
			totalDate= (p->d + p->m*30 + p->y*360);
			if(totalDate>=fDate && totalDate<=tDate){
				printf("\n\t| %-5s| %-40s|%9d |%11.2f |%11.2f |   %02d/%02d/%02d  |", p->code, p->name, p->qty, p->cp, p->sp, p->d, p->m, p->y);
			}
		}
	}
	fclose(purchase);
}

void displayProdP_ReturnList(long int fDate, long int tDate){
	struct product *p, pd;
	p=&pd;
	long int totalDate;
	FILE *p_return= fopen("p_return.dat", "r");
	if(p_return==NULL){
		printf("\nFile doesn't exist or Can't open file.");
	}
	else{
		while (fread(p, sizeof(struct product), 1, p_return)){
			totalDate= (p->d + p->m*30 + p->y*360);
			if(totalDate>=fDate && totalDate<=tDate){
				printf("\n\t| %-5s| %-40s|%9d |%11.2f |%11.2f |   %02d/%02d/%02d  |", p->code, p->name, p->qty, p->cp, p->sp, p->d, p->m, p->y);
			}
		}
	}
	fclose(p_return);
}

void displayProdSalesList(long int fDate, long int tDate){
	struct product *p, pd;
	p=&pd;
	long int totalDate;
	FILE *sales= fopen("sales.dat", "r");
	if(sales==NULL){
		printf("\nFile doesn't exist or Can't open file.");
	}
	else{
		while (fread(p, sizeof(struct product), 1, sales)){
			totalDate= (p->d + p->m*30 + p->y*360);
			if(totalDate>=fDate && totalDate<=tDate){
				printf("\n\t| %-5s| %-40s|%9d |%11.2f |%11.2f |   %02d/%02d/%02d  |", p->code, p->name, p->qty, p->cp, p->sp, p->d, p->m, p->y);
			}
		}
	}
	fclose(sales);
}

void displayProdS_ReturnList(long int fDate, long int tDate){
	struct product *p, pd;
	p=&pd;
	long int totalDate;
	FILE *s_return= fopen("s_return.dat", "r");
	if(s_return==NULL){
		printf("\nFile doesn't exist or Can't open file.");
	}
	else{
		while (fread(p, sizeof(struct product), 1, s_return)){
			totalDate= (p->d + p->m*30 + p->y*360);
			if(totalDate>=fDate && totalDate<=tDate){
				printf("\n\t| %-5s| %-40s|%9d |%11.2f |%11.2f |   %02d/%02d/%02d  |", p->code, p->name, p->qty, p->cp, p->sp, p->d, p->m, p->y);
			}
		}
	}
	fclose(s_return);
}

void displayProdStockList(long int fDate, long int tDate){
	struct product *p, pd;
	p=&pd;
	long int totalDate;
	//int foundCode[200];
	int i=0, j, n=0, codeExists;
	float pCP[200], pSP[200];
	char pName[200][60], pCode[200][15];
	FILE *purchase= fopen("purchase.dat", "r");
	FILE *p_return= fopen("p_return.dat", "r");
	FILE *sales= fopen("sales.dat", "r");
	FILE *s_return= fopen("s_return.dat", "r");
	
	
	if(purchase==NULL||p_return==NULL||sales==NULL||s_return==NULL){
		printf("\nFile doesn't exist or Can't open file.");
	}
	else{
		while (fread(p, sizeof(struct product), 1, purchase)){
			codeExists=0;
			for (j=0; j<n; j++){
				if(strcmp(pCode[j], p->code)==0){
					codeExists=1;
					break;	
				}
			}
			totalDate= (p->d + p->m*30 + p->y*360);
			if(codeExists){
				continue;
			}
			else if(totalDate>=fDate && totalDate<=tDate){
				strcpy(pCode[i],p->code);
				strcpy(pName[i],p->name);
				pCP[i]= p->cp;
				pSP[i]= p->sp;
				i++;
				n++;
				continue;
			}
			else{
				continue;
			}
		}
		
		while (fread(p, sizeof(struct product), 1, p_return)){
			codeExists=0;
			for (j=0; j<n; j++){
				if(strcmp(pCode[j], p->code)==0){
					codeExists=1;
					break;	
				}
			}
			totalDate= (p->d + p->m*30 + p->y*360);
			if(codeExists){
				continue;
			}
			else if(totalDate>=fDate && totalDate<=tDate){
				strcpy(pCode[i],p->code);
				strcpy(pName[i],p->name);
				pCP[i]= p->cp;
				pSP[i]= p->sp;
				i++;
				n++;
				continue;
			}
			else{
				continue;
			}
		}
		
		while (fread(p, sizeof(struct product), 1, sales)){
			codeExists=0;
			for (j=0; j<n; j++){
				if(strcmp(pCode[j], p->code)==0){
					codeExists=1;
					break;	
				}
			}
			totalDate= (p->d + p->m*30 + p->y*360);
			if(codeExists){
				continue;
			}
			else if(totalDate>=fDate && totalDate<=tDate){
				strcpy(pCode[i],p->code);
				strcpy(pName[i],p->name);
				pCP[i]= p->cp;
				pSP[i]= p->sp;
				i++;
				n++;
				continue;
			}
			else{
				continue;
			}
		}
		
		while (fread(p, sizeof(struct product), 1, s_return)){
			codeExists=0;
			for (j=0; j<n; j++){
				if(strcmp(pCode[j], p->code)==0){
					codeExists=1;
					break;	
				}
			}
			totalDate= (p->d + p->m*30 + p->y*360);
			if(codeExists){
				continue;
			}
			else if(totalDate>=fDate && totalDate<=tDate){
				strcpy(pCode[i],p->code);
				strcpy(pName[i],p->name);
				pCP[i]= p->cp;
				pSP[i]= p->sp;
				i++;
				n++;
				continue;
			}
			else{
				continue;
			}
		}
		/*for(j=0; j<n; j++){
			printf("\nFound: %d\t%s\t%.2f\t%.2f", foundCode[j], pName[j], pCP[j], pSP[j]);
		}*/
		
		for (i=0; i<n; i++){
			int opStk=0, clStk=0, curP=0, curP_R=0, curS=0, curS_R=0;
			fseek(purchase, 0, 0); //set file pointer to the beginning again
			while (fread(p, sizeof(struct product), 1, purchase)){
				if(strcmp(pCode[i], p->code)==0){
					totalDate= (p->d + p->m*30 + p->y*360);
					if(totalDate>=fDate && totalDate<=tDate){
						curP+=p->qty;
					}
					else if (totalDate<fDate){
						opStk+=p->qty;
					}
				}
			}
			
			fseek(p_return, 0, 0);
			while (fread(p, sizeof(struct product), 1, p_return)){
				if(strcmp(pCode[i], p->code)==0){
					totalDate= (p->d + p->m*30 + p->y*360);
					if(totalDate>=fDate && totalDate<=tDate){
						curP_R+=p->qty;
					}
					else if (totalDate<fDate){
						opStk-=p->qty;
					}
				}
			}
			
			fseek(sales, 0, 0);
			while (fread(p, sizeof(struct product), 1, sales)){
				if(strcmp(pCode[i], p->code)==0){
					totalDate= (p->d + p->m*30 + p->y*360);
					if(totalDate>=fDate && totalDate<=tDate){
						curS+=p->qty;
					}
					else if (totalDate<fDate){
						opStk-=p->qty;
					}
				}
			}
			
			fseek(s_return, 0, 0);
			while (fread(p, sizeof(struct product), 1, s_return)){
				if(strcmp(pCode[i], p->code)==0){
					totalDate= (p->d + p->m*30 + p->y*360);
					if(totalDate>=fDate && totalDate<=tDate){
						curS_R+=p->qty;
					}
					else if (totalDate<fDate){
						opStk+=p->qty;
					}
				}
			}
			clStk= (opStk+curP-curP_R-curS+curS_R);
			//sprintf(pCode, "%f", foundCode[i]);
			printf("\n\t| %-5s| %-24s|%9.2f |%9.2f |%7d |%7d |%7d |%7d |%7d |%7d |", pCode[i], pName[i], pCP[i], pSP[i], opStk, curP, curP_R, curS, curS_R, clStk);
		}
	}
	fclose(purchase);
	fclose(p_return);
	fclose(sales);
	fclose(s_return);
}
