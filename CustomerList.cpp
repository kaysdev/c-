//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CustomerList.h"
#include "Customer.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm4::btnAddNewClick(TObject *Sender)
{
//	frmCustomer->txtFirstName->Text = "";
//	frmCustomer->txtLastName->Text = "";
//	frmCustomer->txtMobileNumber->Text = "";
//	frmCustomer->ShowModal();
	Form3->txtFirstName->Text = "";
	Form3->txtLastName->Text = "";
    Form3->txtMobileNumber->Text = "";
	Form3->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::FormCreate(TObject *Sender)
{
    //to display the column name in TStringGrid
	gridCustomerList->Cells[0][0] = "Customer Id";
	gridCustomerList->ColWidths[0] = 80;
	gridCustomerList->Cells[1][0] = "First Name";
	gridCustomerList->ColWidths[1] = 80;
	gridCustomerList->Cells[2][0] = "Last Name";
	gridCustomerList->ColWidths[2] = 80;
	gridCustomerList->Cells[3][0] = "Mobile Number";
	gridCustomerList->ColWidths[3] = 100;
	int rowCounter = 1;
	gridCustomerList->RowCount = ADODataSet1->RecordCount+1;
	//to fill customer data in the TStringGrid
	while (!ADODataSet1->Eof)
	{
		gridCustomerList->Cells[0][rowCounter] =
					/*ADOTable1->FieldByName("customer_id")->AsString;*/
					ADODataSet1->FieldByName("customer_id")->AsString;
		gridCustomerList->Cells[1][rowCounter] =
					/*ADOTable1->FieldByName("first_name")->AsString;*/
					ADODataSet1->FieldByName("first_name")->AsString;
		gridCustomerList->Cells[2][rowCounter] =
					/*ADOTable1->FieldByName("last_name")->AsString;*/
					ADODataSet1->FieldByName("last_name")->AsString;
		gridCustomerList->Cells[3][rowCounter] =
					/*ADOTable1->FieldByName("mobile_number")->AsString;*/
					ADODataSet1->FieldByName("mobile_number")->AsString;
		rowCounter++;
		ADODataSet1->Next();
	}

	ADODataSet1->First();
}
//---------------------------------------------------------------------------

//on click on cell of TStringGrid
void __fastcall TForm4::gridCustomerListSelectCell(TObject *Sender,
		int ACol, int ARow, bool &CanSelect)
{
	if(ARow != 0)  // if the header row is not selected
	{
		Form3->txtFirstName->Text = gridCustomerList->Cells[1][ARow];
		Form3->txtLastName->Text = gridCustomerList->Cells[2][ARow];
		Form3->txtMobileNumber->Text = gridCustomerList->Cells[3][ARow];
		Form3->ShowModal();
	}
}
