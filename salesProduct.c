void salesProd(){
	int i=0, j, n=0, opt;
	char code[15];
	
	struct product pd, *p, t[50];
	p=&pd;
	
	while(1){
		displaySalesProdHead();
		if(n>0){
			displayProdSalesHead();
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
				prodSalesUpdate(t, p, n);
				prodDeductUpdate(t, p, n);
				displaySalesProdHead();
				printf("\tProduct Sold...");
				sleep(2);
				break;
			}
			else if(operateFileOption(opt)==0){
				displaySalesProdHead();
				printf("\n\tSell Product Cancelled.");
				sleep(2);
				pMenu();
			}
			else{
				goto addProduct;
			}
		}
		
		addProduct:
		displaySalesProdHead();
		fflush(stdin);
		printf("\n\tEnter Code: ");
		gets(code);
		if(!strlen(code)){
			goto addProduct;
		}
		else if(isProdAdded(t, code, n)){
			displaySalesProdHead();
			printf("\tProduct already Added.");
			sleep(1);
			goto addProduct;
		}
		else{
			
			if(doCodeExist(code, p)){
				sellProd:
				system("cls");
				displayProdDetailHead();
				displayStruct(p);
				displayBottomLine();
				printf("\n\tFile Exist... Continue ?\n");	
				displayProdOption();
			
				opt=tolower(getch());
				if(operateProdOption(opt)==0){
					continue;
				}
				else{
					t[i]= *p;
					printf("\n\n\tSell Quantity: ");
					scanf("%d", &t[i].qty);
					if((p->qty - t[i].qty) < 0){
						displaySalesProdHead();
						printf("\tSelling Quantity More than Available Quantity... !");
						sleep(2);
						goto sellProd;
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
