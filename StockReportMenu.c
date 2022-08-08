#include "productReport.c"

void invReportMenu ()
{
	while(1){
		int opt;
		displayInvReportHead();
		printf("\t\t    REPORT TITLE\n");
		printf("\t\t    ------------\n");
		printf("\t\t1 - Purchase\n");
		printf("\t\t2 - Purchase Return\n");
		printf("\t\t3 - Sales\n");
		printf("\t\t4 - Sales Return\n");
		printf("\t\t5 - All in one\n");
		displayFooterMenu();
		
		opt= tolower(getch());
		
		switch(opt){
			case 49: //ASCII value '1'
				displayInvReportHead();
				prodPurchaseReport();				
				break;
			
			case 50: //ASCII value '2'
				displayInvReportHead();
				prodP_ReturnReport();
				break;
				
			case 51: //ASCII value '3'
				displayInvReportHead();
				prodSalesReport();
				break;
				
			case 52: //ASCII value '4'
				displayInvReportHead();
				prodS_ReturnReport();
				break;
				
			case 53: //ASCII value '5'
				displayInvReportHead();
				prodStockReport();
				break;

			case 27: //ASCII value 'ESC'
				return;
				
			default:
				operateFooter(opt);
				break;
		}
	}
}
