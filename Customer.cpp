//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Customer.h"
#include "CustomerList.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm3::btnSaveClick(TObject *Sender)
{
	if(this->btnSave->Caption == "Close")
	{
		this->Close();
	}
	else
	{
		//when first name textbox is empty
		if(this->txtFirstName->Text.Trim() == "")
		{
			ShowMessage("Please enter valid first name!");
		}
		//when last name textbox is empty
		else if(this->txtLastName->Text.Trim() == "")
		{
			ShowMessage("Please enter valid last name!");
		}
		//when mobile number textbox is empty
		else if(this->txtMobileNumber->Text.Trim() == "")
		{
			ShowMessage("Please enter valid mobile number!");
		}
		//when the mobile number length is less than 8 characters
		else if(this->txtMobileNumber->Text.Length() < 8)
		{
			ShowMessage("Please enter valid mobile number!");
		}
		//when all the fields are filled in the form
		else
		{
			TADOQuery* ADOQuery;
			/* SQL Query to insert the customer data into customer table*/
			String SQLStr = "INSERT INTO Customer (first_name,last_name, \
							mobile_number) VALUES ('"+this->txtFirstName->Text\
							+ "', '" + this->txtLastName->Text + "','"
							+ this->txtMobileNumber->Text + "');";
			ADOQuery = new TADOQuery(this);
			ADOQuery->Connection = ADOConnection1;

			ADOQuery->Prepared = true;
			ADOQuery->SQL->Clear();
			ADOQuery->SQL->Add(SQLStr);
			try
			{
				ADOQuery->ExecSQL(); // this will save the customer record in database
				ADOQuery->Close();
				int rowCounter=1;
				Form4->ADOTable1->Active = false;
				Form4->ADOTable1->Active = true;
				Form4->ADOTable1->Refresh();

				while (!Form4->ADOTable1->Eof)
				{
					Form4->gridCustomerList->Cells[0][rowCounter] =
								Form4->ADOTable1->FieldByName("customer_id")->AsString;
					Form4->gridCustomerList->Cells[1][rowCounter] =
								Form4->ADOTable1->FieldByName("first_name")->AsString;
					Form4->gridCustomerList->Cells[2][rowCounter] =
								Form4->ADOTable1->FieldByName("last_name")->AsString;
					Form4->gridCustomerList->Cells[3][rowCounter] =
								Form4->ADOTable1->FieldByName("mobile_number")->AsString;
					rowCounter++;
					Form4->ADOTable1->Next();
				}
				Form4->gridCustomerList->RowCount = rowCounter;
				Form4->gridCustomerList->Refresh();
				Form4->ADOTable1->First();

				ShowMessage("Record Saved");
				this->Close();

			}
			catch (EADOError& e)
			{
				MessageDlg("Error while connecting", mtError,
						  TMsgDlgButtons() << mbOK, 0);
				return;
			}
		}
	}
}
//---------------------------------------------------------------------------
//empty form fields on form show
void __fastcall TForm3::FormShow(TObject *Sender)
{
	//when click on Grid data from list page
	if(this->txtFirstName->Text != "")
	{
		this->txtFirstName->Enabled = false;
		this->txtLastName->Enabled = false;
		this->txtMobileNumber->Enabled = false;
		this->btnSave->Caption = "Close";
	}
    //when click on Add button
	else
	{
		this->txtFirstName->Enabled = true;
		this->txtLastName->Enabled = true;
		this->txtMobileNumber->Enabled = true;
		this->btnSave->Caption = "Save";
	}
}
//---------------------------------------------------------------------------
