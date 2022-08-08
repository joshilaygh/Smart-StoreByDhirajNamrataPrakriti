int editStruct(struct product *);

void editProdDetail(){
	displayEditProdHead();
	FILE *fp=fopen("inventory.dat", "r");
	FILE *temp=fopen("temp.dat", "w");
	bool fileFound=false;
	struct product pd, *p;
	p=&pd;
	if(fp==NULL){
		printf("File doesn't exist or Can't open file.");
	}
	else{
		char code[15];
		fflush(stdin);
		printf("\n\tEnter Code: ");
		gets(code);
		while(fread(p, sizeof(struct product), 1, fp)){
			if(strcmp(code, p->code)==0){
				fileFound=true;
				
				if(!editStruct(p)){
					fclose(fp);
					fclose(temp);
					return;
				}					
			}
			fwrite(p, sizeof(struct product), 1, temp);
		}
		if(!fileFound){
				fileNotFound();
		}
	}
	fclose(fp);
	fclose(temp);
	
	if(fileFound){
		FILE *fp=fopen("inventory.dat", "w");
		FILE *temp=fopen("temp.dat", "r");
		while(fread(p, sizeof(struct product), 1, temp)){
			fwrite(p, sizeof(struct product), 1, fp);
		}
		fclose(fp);
		fclose(temp);
		displayEditProdHead();
		printf("\n\tProduct Updated.");
		sleep(1);
	}
}

int editStruct(struct product *p){
	int opt;
	displayEditProdHead();
	displayProdDetailHead();
 	displayStruct(p);
 	displayBottomLine();

	printf("\n\tN - Edit Name");
	//printf("\n\tQ - Edit Qty");
	printf("\n\tC - Edit CP");
	printf("\n\tS - Edit SP");
	printf("\n\n");
	displayFileEditOption();

	opt= tolower(getch());
	
	switch(opt)
	{
		case 110: //ASCII value 'n'
			printf("\n\tProduct Name: ");
			scanf("%[^\n]", p->name);
			break;
			
		case 113: //ASCII value 'q'
			printf("\n\tQuantity: ");
			scanf("%d", &p->qty);
			break;
			
		case 99: //ASCII value 'c'
			printf("\n\tCost Price: ");
			scanf("%f", &p->cp);
			break;
			
		case 115: //ASCII value 's'
			do{
		    	printf("\n\tSell Price: ");
			    scanf("%f", &p->sp);
			    if(!(isSPValid(p))){
					printf("\n\tInvalid Sell Price!\n");
				}
			}while(!(isSPValid(p)));
			break;
			
		case 13: //ASCII value 'ENTER'
			break;
		case 19: //ASCII value 'CTRL+S'
			return 1;
		case 27:  //ASCII value 'ESC'
			return 0;
		default:
			invalidInput();
			break;
 	}
	editStruct(p);	
}
