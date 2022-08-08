void purchaseReturnProd(){
	int i=0, j, n=0, opt;
	char code[15];
	
	struct product pd, *p, t[50];
	p=&pd;
	
	while(1){
		displayPurRetHead();
		if(n>0){
			displayProdP_ReturnHead();
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
				prodP_ReturnUpdate(t, p, n);
				prodDeductUpdate(t, p, n);
				displayPurRetHead();
				printf("\tProduct Returned Successfully...");
				sleep(2);
				break;
			}
			else if(operateFileOption(opt)==0){
				displayPurRetHead();
				printf("\n\tPurchase Return Cancelled.");
				sleep(2);
				pMenu();
			}
			else{
				goto addProduct;
			}
		}
		
		addProduct:
		displayPurRetHead();
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
				purchaseReturnProd:
				system("cls");
				displayProdDetailHead();
				displayStruct(p);
				displayBottomLine();
				printf("\n\tFile Exist... Return Existing Product?\n");	
				displayProdOption();
			
				opt=tolower(getch());
				if(operateProdOption(opt)==0){
					continue;
				}
				else{
					t[i]= *p;
					printf("\n\n\tReturn Quantity: ");
					scanf("%d", &t[i].qty);
					if((p->qty - t[i].qty) < 0){
						displayPurRetHead();
						printf("\tReturn Quantity More than Available Quantity... !");
						sleep(2);
						goto purchaseReturnProd;
					}
					n++;
					continue;
				}
			}
			else{
				printf("\n\tProduct Not Available!\n");
				sleep(2);
				continue;
			}
		}
	}
}
