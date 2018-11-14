//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Login.h"
#include "Dashboard.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btnLoginClick(TObject *Sender)
{
    //if no user is selected and password is empty as well
	if(this->ddlUser->Text=="Select User" && this->txtPassword->Text=="")
	{
		ShowMessage("Please select valid user and enter valid password!");
	}
	//when user is not selected
	else if(this->ddlUser->Text=="Select User")
	{
		ShowMessage("Please select valid user!");
	}
	//when no password is entered
	else if(this->txtPassword->Text=="")
	{
		ShowMessage("Please enter valid password!");
	}
	//when both user and password is entered
	else if(this->txtPassword->Text!="" && this->ddlUser->Text!="Select User")
	{
		ADODataSet1->Parameters->ParamByName("user_name")->Value = this->ddlUser->Text;
		ADODataSet1->Parameters->ParamByName("password")->Value = this->txtPassword->Text;
		ADODataSet1->Close();
		ADODataSet1->Open();
		if(ADODataSet1->FieldByName("user_name")->AsString == this->ddlUser->Text)
		{
			Form2->ShowModal();
			//ShowMessage("success");
		}
		else
		{
			ShowMessage("Invalid Credentials!!!");
		}
	}
}


void __fastcall TForm1::FormShow(TObject *Sender)
{
	ADOTable1->Active=true;
	while (!ADOTable1->Eof)
	{
		ddlUser->Items->Add(ADOTable1->FieldByName("user_name")->AsString);
		ADOTable1->Next();
	}
	ADOTable1->First();
}
