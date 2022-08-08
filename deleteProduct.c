void deleteProd(){
	system("cls");
	displayTitleHead();
	printf("\t\t\t**| DELETE PRODUCT |**\n\n");
	FILE *fp=fopen("inventory.dat", "r");
	FILE *temp=fopen("temp.dat", "w");
	FILE *del=fopen("del.dat", "w");
	bool fileFound=false;
	struct product pd, *p;
	p=&pd;
	if(fp==NULL){
		printf("File doesn't exist or Can't open file.");
	}
	else{
		char code[15];
		int i=0;
		fflush(stdin);
		printf("\tEnter Code: ");
		gets(code);
		while(fread(p, sizeof(struct product), 1, fp)){
			if(strcmp(code, p->code)==0){
				fileFound=true;
				fwrite(p, sizeof(struct product), 1, del);
			}
			else{
				fwrite(p, sizeof(struct product), 1, temp);
			}
		}		
		if(!fileFound){
				fileNotFound();
		}
	}
	fclose(fp);
	fclose(temp);
	fclose(del);
	
	if(fileFound){
		int delStat= 1;		
		FILE *del=fopen("del.dat", "r");
		system("cls");
		printf("\n\t------------------------------------------------------------------------------------------------");
		printf("\n\t| Code | Product Name				    |  Quantity  |  Cost Price  |  Sell Price  |");
		printf("\n\t------------------------------------------------------------------------------------------------");
		while(fread(p, sizeof(struct product), 1, del)){
			printf("\n\t| %-5s| %-43s| %-11d| %-13.2f| %-13.2f|", p->code, p->name, p->qty, p->cp, p->sp);
			if(p->qty > 0){
				delStat= 0;
			}
		}
		printf("\n\t------------------------------------------------------------------------------------------------\n");

		if(delStat==1){
			FILE *fp=fopen("inventory.dat", "w");
			FILE *temp=fopen("temp.dat", "r");
			
			while(fread(p, sizeof(struct product), 1, temp)){
				fwrite(p, sizeof(struct product), 1, fp);
			}
			
			fclose(fp);
			fclose(temp);
			printf("\n\n\tFile Deleted Successfully.");
		}
		else{
			printf("\n\n\tCannot Delete... Stock Available.");
		}
		fclose(del);
		sleep(3);		
	}
}
