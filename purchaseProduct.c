void purchaseProd(){
	int i=0, j, n=0, opt;
	char code[15];
	
	struct product pd, *p, t[50];
	p=&pd;
	
	while(1){
		displayPurProdHead();
		
		if(n>0){
			displayProdPurchaseHead();
			for(i=0; i<n; i++){
				getDate(p);
				t[i].d= p->d;
				t[i].m= p->m;
				t[i].y= p->y;
				printf("\n\t| %-5s| %-40s|%9d |%11.2f |%11.2f |   %02d/%02d/%02d  |", t[i].code, t[i].name, t[i].qty, t[i].cp, t[i].sp, t[i].d, t[i].m, t[i].y);
			}
			displayLongBottomLine();
			displayFileOption();
			opt=tolower(getch());
			
			if(operateFileOption(opt)==1){
				prodPurchaseUpdate(t, p, n);
				prodAddUpdate(t, p, n);
				displayPurProdHead();
				printf("\tProduct Purchsed Successfully...");
				sleep(2);
				break;
			}
			else if(operateFileOption(opt)==0){
				displayPurProdHead();
				printf("\n\tPurchase Cancelled.");
				sleep(2);
				pMenu();
			}
			else{
				goto addProduct;
			}
		}
		
		addProduct:
		displayPurProdHead();
		fflush(stdin);
		printf("\n\tEnter Code: ");
		gets(code);
		if(!strlen(code)){
			goto addProduct;
		}
		else if(isProdAdded(t, code, n)){
			printf("\tProduct already Added!");
			sleep(1);
			goto addProduct;
		}

		else{
			
			if(doCodeExist(code, p)){
				purchaseOldProd:
				system("cls");
				displayProdDetailHead();
				displayStruct(p);
				displayBottomLine();
				printf("\n\tFile Exist... Purchase Existing Product?\n");	
				displayProdOption();
			
				opt=tolower(getch());
				if(operateProdOption(opt)==1){
					t[i]= *p;
					printf("\n\n\tPurchase Quantity: ");
					scanf("%d", &t[i].qty);
					n++;
					continue;
				}
				else{
					continue;
				}
			}
			else{
				purchaseNewProd:
				printf("\n\tCreate new Product?\n");
				displayProdOption();
				opt=tolower(getch());
				
				if(operateProdOption(opt)==0){
					continue;
				}
				else{
					strcpy(t[i].code, code);
					printf("\n\n\tName: ");
					gets(t[i].name);
					printf("\tQuantity: ");
					scanf("%d", &t[i].qty);
					printf("\tCost Price: ");
					scanf("%f", &t[i].cp);
					do{
				    	printf("\tSell Price: ");
					    scanf("%f", &t[i].sp);
					    if(t[i].sp < t[i].cp){
					    	printf("\n\tInvalid Sell Price!\n");
						}
					}while(t[i].sp < t[i].cp);
					n++;
					continue;
				}
			}
		}
	}
}
