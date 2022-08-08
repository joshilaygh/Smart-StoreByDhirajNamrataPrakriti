void prodPurchaseUpdate(struct product *t, struct product *p, int n){
	int i;
	FILE *temp= fopen("temp.dat", "w");
	FILE *pur= fopen("purchase.dat", "r");
	
	while(fread(p, sizeof(struct product), 1,pur)){
		fwrite(p, sizeof(struct product), 1, temp);
	}

	for (i=0; i<n; i++){
		*p= t[i];
		fwrite(p, sizeof(struct product), 1, temp);
		//printf("\n\t| %-5s| %-40s| %-9d| %-11.2f| %-11.2f|   %02d/%02d/%02d  |", p->code, p->name, p->qty, p->cp, p->sp, p->d, p->m, p->y);
	}		
	fclose(temp);
	fclose(pur);
	
	FILE *temp1= fopen("temp.dat", "r");
	FILE *pur1= fopen("purchase.dat", "w");
	while(fread(p, sizeof(struct product), 1,temp1)){
		fwrite(p, sizeof(struct product), 1, pur1);
	}
	fclose(temp1);
	fclose(pur1);
}

void prodP_ReturnUpdate(struct product *t, struct product *p, int n){
	int i;
	FILE *temp= fopen("temp.dat", "w");
	FILE *pur= fopen("p_return.dat", "r");
	
	while(fread(p, sizeof(struct product), 1,pur)){
		fwrite(p, sizeof(struct product), 1, temp);
	}

	for (i=0; i<n; i++){
		*p= t[i];
		fwrite(p, sizeof(struct product), 1, temp);
		//printf("\n\t| %-5s| %-40s| %-9d| %-11.2f| %-11.2f|   %02d/%02d/%02d  |", p->code, p->name, p->qty, p->cp, p->sp, p->d, p->m, p->y);
	}		
	fclose(temp);
	fclose(pur);
	
	FILE *temp1= fopen("temp.dat", "r");
	FILE *pur1= fopen("p_return.dat", "w");
	while(fread(p, sizeof(struct product), 1,temp1)){
		fwrite(p, sizeof(struct product), 1, pur1);
	}
	fclose(temp1);
	fclose(pur1);
}

void prodSalesUpdate(struct product *t, struct product *p, int n){
	int i;
	FILE *temp= fopen("temp.dat", "w");
	FILE *s= fopen("sales.dat", "r");
	
	while(fread(p, sizeof(struct product), 1,s)){
		fwrite(p, sizeof(struct product), 1, temp);
	}

	for (i=0; i<n; i++){
		*p= t[i];
		fwrite(p, sizeof(struct product), 1, temp);
		//printf("\n\t| %-5s| %-40s| %-9d| %-11.2f| %-11.2f|   %02d/%02d/%02d  |", p->code, p->name, p->qty, p->cp, p->sp, p->d, p->m, p->y);
	}		
	fclose(temp);
	fclose(s);
	
	FILE *temp1= fopen("temp.dat", "r");
	FILE *s1= fopen("sales.dat", "w");
	while(fread(p, sizeof(struct product), 1,temp1)){
		fwrite(p, sizeof(struct product), 1, s1);
	}
	fclose(temp1);
	fclose(s1);
	
}
void prodS_ReturnUpdate(struct product *t, struct product *p, int n){
	int i;
	FILE *temp= fopen("temp.dat", "w");
	FILE *s= fopen("s_return.dat", "r");
	
	while(fread(p, sizeof(struct product), 1,s)){
		fwrite(p, sizeof(struct product), 1, temp);
	}

	for (i=0; i<n; i++){
		*p= t[i];
		fwrite(p, sizeof(struct product), 1, temp);
		//printf("\n\t| %-5s| %-40s| %-9d| %-11.2f| %-11.2f|   %02d/%02d/%02d  |", p->code, p->name, p->qty, p->cp, p->sp, p->d, p->m, p->y);
	}		
	fclose(temp);
	fclose(s);
	
	FILE *temp1= fopen("temp.dat", "r");
	FILE *s1= fopen("s_return.dat", "w");
	while(fread(p, sizeof(struct product), 1,temp1)){
		fwrite(p, sizeof(struct product), 1, s1);
	}
	fclose(temp1);
	fclose(s1);
}

void prodAddUpdate(struct product *t, struct product *p, int n){
	int i, prodFound;
	
	for (i=0; i<n; i++){
		prodFound=0;
		FILE *fp= fopen("inventory.dat", "r");
		FILE *temp= fopen("temp.dat", "w");
		while(fread(p, sizeof(struct product), 1, fp)){
			if(!strcmp(t[i].code, p->code)){
				p->qty+=t[i].qty;
				prodFound=1;
			}
			fwrite(p, sizeof(struct product), 1, temp);
		}
		//fseek(fp, 0, 0); //set file pointer in the beginning
		if(!prodFound){
			*p=t[i];
			fwrite(p, sizeof(struct product), 1, temp);
		}
		fclose(fp);
		fclose(temp);
		
		FILE *temp1= fopen("temp.dat", "r");
		FILE *fp1= fopen("inventory.dat", "w");
		while(fread(p, sizeof(struct product), 1, temp1)){
			fwrite(p, sizeof(struct product), 1, fp1);
		}
		fclose(temp1);
		fclose(fp1);
	}
}

void prodDeductUpdate(struct product *t, struct product *p, int n){
	int i, fileFound;
	
	for (i=0; i<n; i++){
		fileFound=0;
		FILE *fp= fopen("inventory.dat", "r");
		FILE *temp= fopen("temp.dat", "w");
		while(fread(p, sizeof(struct product), 1, fp)){
			if(!strcmp(t[i].code, p->code)){
				p->qty-=t[i].qty;
				fileFound=1;
			}
			fwrite(p, sizeof(struct product), 1, temp);
		}
		//fseek(fp, 0, 0); //set file pointer in the beginning
		if(!fileFound){
			*p=t[i];
			printf("\n\tPurchase Return Error... !");
		}
		fclose(fp);
		fclose(temp);
		
		FILE *temp1= fopen("temp.dat", "r");
		FILE *fp1= fopen("inventory.dat", "w");
		while(fread(p, sizeof(struct product), 1, temp1)){
			fwrite(p, sizeof(struct product), 1, fp1);
		}
		fclose(temp1);
		fclose(fp1);
	}
}
