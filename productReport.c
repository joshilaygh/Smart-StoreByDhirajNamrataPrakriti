void prodPurchaseReport(){
	int fd, fm, fy, td, tm, ty, x, mDays;
	long int totalFromDate, totalToDate, totalDate, totalNowDate;
	struct product *p, pd;
	p=&pd;
	
	printf("\tPurchase Report Display:\n\n");
	
	getFromDate:
	printf("\tFrom Date\t(dd mm yyyy): ");
	x= scanf("%2d%2d%4d", &fd, &fm, &fy);
	
	findMonthDays(&mDays, fd, fm, fy);
	if(!x || fd>mDays || fm>12){
		fflush(stdin);
		printf("\tInvalid From Date!\n");
		goto getFromDate;
	}
	
	getToDate:
	printf("\tTo Date\t\t(dd mm yyyy): ");
	x= scanf("%2d%2d%4d", &td, &tm, &ty);
	
	findMonthDays(&mDays, td, tm, ty);
	if(!x || td>mDays || tm>12){
		fflush(stdin);
		printf("\tInvalid To Date!\n");
		goto getToDate;
	}
	totalFromDate= (fd + fm*30 + fy*360);
	totalToDate= (td + tm*30 + ty*360);
	getDate(p);
	totalNowDate= (p->d + p->m*30 + p->y*360);
	if(totalToDate<totalFromDate || totalToDate>totalNowDate){
		printf("\tInvalid To Date!\n");
		goto getToDate;
	}
	displayInvReportHead();
	printf("\tProduct Purchase:\n\n");
	printf("\tFrom Date: %02d/%02d/%02d\t\t\tTo Date: %02d/%02d/%02d\n", fd, fm, fy, td, tm, ty);
	displayProdPurchaseHead();
	displayProdPurchaseList(totalFromDate, totalToDate);
	displayLongBottomLine();
	getch();
}

void prodP_ReturnReport(){
	int fd, fm, fy, td, tm, ty, x, mDays;
	long int totalFromDate, totalToDate, totalDate, totalNowDate;
	struct product *p, pd;
	p=&pd;
	
	printf("\tPurchase Return Report Display:\n\n");
	
	getFromDate:
	printf("\tFrom Date\t(dd mm yyyy): ");
	x= scanf("%2d%2d%4d", &fd, &fm, &fy);
	
	findMonthDays(&mDays, fd, fm, fy);
	if(!x || fd>mDays || fm>12){
		fflush(stdin);
		printf("\tInvalid From Date!\n");
		goto getFromDate;
	}
	
	getToDate:
	printf("\tTo Date\t\t(dd mm yyyy): ");
	x= scanf("%2d%2d%4d", &td, &tm, &ty);
	
	findMonthDays(&mDays, td, tm, ty);
	if(!x || td>mDays || tm>12){
		fflush(stdin);
		printf("\tInvalid To Date!\n");
		goto getToDate;
	}
	totalFromDate= (fd + fm*30 + fy*360);
	totalToDate= (td + tm*30 + ty*360);
	getDate(p);
	totalNowDate= (p->d + p->m*30 + p->y*360);
	if(totalToDate<totalFromDate || totalToDate>totalNowDate){
		printf("\tInvalid To Date!\n");
		goto getToDate;
	}
	displayInvReportHead();
	printf("\tProduct Purchase Return:\n\n");
	printf("\tFrom Date: %02d/%02d/%02d\t\t\tTo Date: %02d/%02d/%02d\n", fd, fm, fy, td, tm, ty);
	displayProdP_ReturnHead();
	displayProdP_ReturnList(totalFromDate, totalToDate);
	displayLongBottomLine();
	getch();
}

void prodSalesReport(){
	int fd, fm, fy, td, tm, ty, x, mDays;
	long int totalFromDate, totalToDate, totalDate, totalNowDate;
	struct product *p, pd;
	p=&pd;
	
	printf("\tSales Report Display:\n\n");
	
	getFromDate:
	printf("\tFrom Date\t(dd mm yyyy): ");
	x= scanf("%2d%2d%4d", &fd, &fm, &fy);
	
	findMonthDays(&mDays, fd, fm, fy);
	if(!x || fd>mDays || fm>12){
		fflush(stdin);
		printf("\tInvalid From Date!\n");
		goto getFromDate;
	}
	
	getToDate:
	printf("\tTo Date\t\t(dd mm yyyy): ");
	x= scanf("%2d%2d%4d", &td, &tm, &ty);
	
	findMonthDays(&mDays, td, tm, ty);
	if(!x || td>mDays || tm>12){
		fflush(stdin);
		printf("\tInvalid To Date!\n");
		goto getToDate;
	}
	totalFromDate= (fd + fm*30 + fy*360);
	totalToDate= (td + tm*30 + ty*360);
	getDate(p);
	totalNowDate= (p->d + p->m*30 + p->y*360);
	if(totalToDate<totalFromDate || totalToDate>totalNowDate){
		printf("\tInvalid To Date!\n");
		goto getToDate;
	}
	displayInvReportHead();
	printf("\tProduct Sales:\n\n");
	printf("\tFrom Date: %02d/%02d/%02d\t\t\tTo Date: %02d/%02d/%02d\n", fd, fm, fy, td, tm, ty);
	displayProdSalesHead();
	displayProdSalesList(totalFromDate, totalToDate);
	displayLongBottomLine();
	getch();
}

void prodS_ReturnReport(){
	int fd, fm, fy, td, tm, ty, x, mDays;
	long int totalFromDate, totalToDate, totalDate, totalNowDate;
	struct product *p, pd;
	p=&pd;
	
	printf("\tSales Return Report Display:\n\n");
	
	getFromDate:
	printf("\tFrom Date\t(dd mm yyyy): ");
	x= scanf("%2d%2d%4d", &fd, &fm, &fy);
	
	findMonthDays(&mDays, fd, fm, fy);
	if(!x || fd>mDays || fm>12){
		fflush(stdin);
		printf("\tInvalid From Date!\n");
		goto getFromDate;
	}
	
	getToDate:
	printf("\tTo Date\t\t(dd mm yyyy): ");
	x= scanf("%2d%2d%4d", &td, &tm, &ty);
	
	findMonthDays(&mDays, td, tm, ty);
	if(!x || td>mDays || tm>12){
		fflush(stdin);
		printf("\tInvalid To Date!\n");
		goto getToDate;
	}
	totalFromDate= (fd + fm*30 + fy*360);
	totalToDate= (td + tm*30 + ty*360);
	getDate(p);
	totalNowDate= (p->d + p->m*30 + p->y*360);
	if(totalToDate<totalFromDate || totalToDate>totalNowDate){
		printf("\tInvalid To Date!\n");
		goto getToDate;
	}
	displayInvReportHead();
	printf("\tProduct Sales Return:\n\n");
	printf("\tFrom Date: %02d/%02d/%02d\t\t\tTo Date: %02d/%02d/%02d\n", fd, fm, fy, td, tm, ty);
	displayProdS_ReturnHead();
	displayProdS_ReturnList(totalFromDate, totalToDate);
	displayLongBottomLine();
	getch();
}

void prodStockReport(){
	int fd, fm, fy, td, tm, ty, x, mDays;
	long int totalFromDate, totalToDate, totalDate, totalNowDate;
	struct product *p, pd;
	p=&pd;
	
	printf("\tStock Report Display:\n\n");
	
	getFromDate:
	printf("\tFrom Date\t(dd mm yyyy): ");
	x= scanf("%2d%2d%4d", &fd, &fm, &fy);
	
	findMonthDays(&mDays, fd, fm, fy);
	if(!x || fd>mDays || fm>12){
		fflush(stdin);
		printf("\tInvalid From Date!\n");
		goto getFromDate;
	}
	
	getToDate:
	printf("\tTo Date\t\t(dd mm yyyy): ");
	x= scanf("%2d%2d%4d", &td, &tm, &ty);
	
	findMonthDays(&mDays, td, tm, ty);
	if(!x || td>mDays || tm>12){
		fflush(stdin);
		printf("\tInvalid To Date!\n");
		goto getToDate;
	}
	totalFromDate= (fd + fm*30 + fy*360);
	totalToDate= (td + tm*30 + ty*360);
	getDate(p);
	totalNowDate= (p->d + p->m*30 + p->y*360);
	if(totalToDate<totalFromDate || totalToDate>totalNowDate){
		printf("\tInvalid To Date!\n");
		goto getToDate;
	}
	displayInvReportHead();
	printf("\tProduct Stock Report:\n\n");
	printf("\tFrom Date: %02d/%02d/%02d\t\t\tTo Date: %02d/%02d/%02d\n", fd, fm, fy, td, tm, ty);
	displayProdStockHead();
	displayProdStockList(totalFromDate, totalToDate);
	displayLongerBottomLine();
	getch();
}
