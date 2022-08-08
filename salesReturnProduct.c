void salesReturnProd(){
	int i=0, j, n=0, opt;
	char code[15];
	
	struct product pd, *p, t[50];
	p=&pd;
	
	while(1){
		displaySalesRetHead();
		if(n>0){
			displayProdS_ReturnHead();
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
				prodS_ReturnUpdate(t, p, n);
				prodAddUpdate(t, p, n);
				displaySalesRetHead();
				printf("\tSales Returned...");
				sleep(2);
				break;
			}
			else if(operateFileOption(opt)==0){
				displaySalesRetHead();
				printf("\n\tSell Product Cancelled.");
				sleep(2);
				pMenu();
			}
			else{
				goto addProduct;
			}
		}
		
		addProduct:
		displaySalesRetHead();
		fflush(stdin);
		printf("\n\tEnter Code: ");
		gets(code);
		if(!strlen(code)){
			goto addProduct;
		}
		else if(isProdAdded(t, code, n)){
			goto addProduct;
		}
		else{
			
			if(doCodeExist(code, p)){
				salesRetProd:
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
					printf("\n\n\tSales Return Quantity: ");
					scanf("%d", &t[i].qty);
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
