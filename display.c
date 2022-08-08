void displayTitleHead(){
	struct product *p, pd;
	p= &pd;
	getDate(p);
	printf("\n");
	printf("\t\t\t\t\t\t\t\t\t--------------------\n");
	printf("\t\t\t\t\t\t\t\t\t| Date: %02d/%02d/%02d |\n", p->d, p->m, p->y);
	printf("\t\t\t\t\t\t\t\t\t--------------------\n");
	printf("\t\t\t***********************\n");
	printf("\t\t\t!!!-- SMART STORE --!!!\n");
	printf("\t\t\t***********************\n\n");
}

void displayFooterMenu(){
	printf("\n\n\n");
	printf("\t-------------------------------------------------------------------------------------------\n");
	printf("\t|  Back: ESC  |  Inventory: I  |  Purchase: P  |  Sales: S  | Stock Report: R |  Exit: X  |\n");
	printf("\t-------------------------------------------------------------------------------------------\n");
	printf("\n\n\tEnter Your Option: ");
}

void displayProdDetailHead(){
	printf("\n\t---------------------------------------------------------------------------------------");
	printf("\n\t| Code | Product Name                            | Quantity | Cost Price | Sell Price |");
	printf("\n\t---------------------------------------------------------------------------------------");
}
void displayProdPurchaseHead(){
	printf("\n\t-------------------------------------------------------------------------------------------------------");
	printf("\n\t| Code | Product Name                            | Quantity | Cost Price | Sell Price | Purchase Date |");
	printf("\n\t-------------------------------------------------------------------------------------------------------");
}

void displayProdP_ReturnHead(){
	printf("\n\t-------------------------------------------------------------------------------------------------------");
	printf("\n\t| Code | Product Name                            | Quantity | Cost Price | Sell Price | P Return Date |");
	printf("\n\t-------------------------------------------------------------------------------------------------------");
}

void displayProdSalesHead(){
	printf("\n\t-------------------------------------------------------------------------------------------------------");
	printf("\n\t| Code | Product Name                            | Quantity | Cost Price | Sell Price |  Sales Date   |");
	printf("\n\t-------------------------------------------------------------------------------------------------------");
}

void displayProdS_ReturnHead(){
	printf("\n\t-------------------------------------------------------------------------------------------------------");
	printf("\n\t| Code | Product Name                            | Quantity | Cost Price | Sell Price | S Return Date |");
	printf("\n\t-------------------------------------------------------------------------------------------------------");
}

void displayProdStockHead(){
	printf("\n\t--------------------------------------------------------------------------------------------------------------");
	printf("\n\t| Code | Name                    |Cost Price|Sell Price|Op Stock|Purchase|P Return| Sales  |S Return|C Stock |");
	printf("\n\t--------------------------------------------------------------------------------------------------------------");
}

void displayStruct(struct product *p){
	printf("\n\t| %-5s| %-40s|%9d |%11.2f |%11.2f |", p->code, p->name, p->qty, p->cp, p->sp);
}

void displayBottomLine(){
	printf("\n\t---------------------------------------------------------------------------------------\n");
}

void displayLongBottomLine(){
	printf("\n\t-------------------------------------------------------------------------------------------------------\n");
}

void displayLongerBottomLine(){
	printf("\n\t--------------------------------------------------------------------------------------------------------------");
}

void displayFileOption(){
	printf("\n");
	printf("\t----------------------\t\t-----------------\t\t----------------\n");
	printf("\t| ANY KEY - Continue |\t\t| CTRL+S - Save |\t\t| ESC - Cancel |\n");
	printf("\t----------------------\t\t-----------------\t\t----------------\n");
	printf("\n\tEnter Your Option: ");
}

void displayFileEditOption(){
	printf("\n");
	printf("\t--------------------\t\t-----------------\t\t----------------\n");
	printf("\t| ENTER - Continue |\t\t| CTRL+S - Save |\t\t| ESC - Cancel |\n");
	printf("\t--------------------\t\t-----------------\t\t----------------\n");
	printf("\n\tEnter Your Option: ");
}

void displayProdOption(){
	printf("\n");
	printf("\t----------------------\t\t----------------\n");
	printf("\t| ANY KEY - Continue |\t\t| ESC - Cancel |\n");
	printf("\t----------------------\t\t----------------\n");
	printf("\n\tEnter Your Option: ");
}

void displayLogOutOption(){
	printf("\n\n\t\tAre you Sure you want to EXIT?\n\n");
	printf("\t--------------------\t\t----------------\n");
	printf("\t| ENTER - Continue |\t\t| ESC - Cancel |\n");
	printf("\t--------------------\t\t----------------\n");
	printf("\n\tEnter Your Option: ");
}

void displayAddProdHead(){
	system("cls");
	displayTitleHead();
	printf("\t\t\t**| ADD PRODUCT |**\n\n");
}
void displayEditProdHead(){
	system("cls");
	displayTitleHead();
	printf("\t\t\t**| EDIT PRODUCT |**\n\n");
}

void displayPurProdHead(){
	system("cls");
	displayTitleHead();
	printf("\t\t\t**| PURCHASE PRODUCT |**\n\n");
}

void displayPurRetHead(){
	system("cls");
	displayTitleHead();
	printf("\t\t\t**| PURCHASE RETURN |**\n\n");
}

void displaySalesProdHead(){
	system("cls");
	displayTitleHead();
	printf("\t\t\t**| SELL PRODUCT |**\n\n");
}

void displaySalesRetHead(){
	system("cls");
	displayTitleHead();
	printf("\t\t\t**| SALES RETURN |**\n\n");
}

void displayInvReportHead(){
	system("cls");
	displayTitleHead();
	printf("\t\t\t**| INVENTORY REPORT |**\n\n");
}
