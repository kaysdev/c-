//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "JobList.h"
#include "Job.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm5::Button1Click(TObject *Sender)
{
	Form6->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm5::DBGrid1DblClick(TObject *Sender)
{
	ShowMessage("Hello");
}
//---------------------------------------------------------------------------



void __fastcall TForm5::FormCreate(TObject *Sender)
{
	//to display the column name in TStringGrid
	gridJobList->Cells[0][0] = "Job Id";
	gridJobList->ColWidths[0] = 50;
	gridJobList->Cells[1][0] = "Job Number";
	gridJobList->ColWidths[1] = 70;
	gridJobList->Cells[2][0] = "Description";
	gridJobList->ColWidths[2] = 110;
	gridJobList->Cells[3][0] = "Customer";
	gridJobList->ColWidths[3] = 80;
	gridJobList->Cells[4][0] = "Mobile Number";
	gridJobList->ColWidths[4] = 80;
	gridJobList->Cells[5][0] = "Status";
	gridJobList->ColWidths[5] = 60;
	gridJobList->Cells[6][0] = "Technician";
	gridJobList->ColWidths[6] = 80;
	gridJobList->Cells[7][0] = "Time Spent";
	gridJobList->ColWidths[7] = 70;
	int rowCounter = 1;

    //to fill customer data in the TStringGrid
//	while (!DataSource1->DataSet->Eof)
//	{
//	  	gridJobList->Cells[0][rowCounter] =
//					ADOTable1->FieldByName("customer_id")->AsString;
//		gridJobList->Cells[1][rowCounter] =
//					ADOTable1->FieldByName("first_name")->AsString;
//		gridJobList->Cells[2][rowCounter] =
//					ADOTable1->FieldByName("last_name")->AsString;
//		gridJobList->Cells[3][rowCounter] =
//					ADOTable1->FieldByName("mobile_number")->AsString;
//		rowCounter++;
//		ADOTable1->Next();
//	}
//	gridCustomerList->RowCount = rowCounter;
//	ADOTable1->First();
	gridJobList->RowCount = ADODataSet1->RecordCount+1;
	//to fill customer data in the TStringGrid
	while (!ADODataSet1->Eof)
	{
		gridJobList->Cells[0][rowCounter] =
					/*ADOTable1->FieldByName("customer_id")->AsString;*/
					ADODataSet1->FieldByName("job_id")->AsString;
		gridJobList->Cells[1][rowCounter] =
					/*ADOTable1->FieldByName("first_name")->AsString;*/
					ADODataSet1->FieldByName("job_number")->AsString;
		gridJobList->Cells[2][rowCounter] =
					/*ADOTable1->FieldByName("last_name")->AsString;*/
					ADODataSet1->FieldByName("job_description")->AsString;
		gridJobList->Cells[3][rowCounter] =
					/*ADOTable1->FieldByName("mobile_number")->AsString;*/
					ADODataSet1->FieldByName("customer_id")->AsString;
		gridJobList->Cells[4][rowCounter] =
					/*ADOTable1->FieldByName("customer_id")->AsString;*/
					ADODataSet1->FieldByName("mobile_number")->AsString;
		gridJobList->Cells[5][rowCounter] =
					/*ADOTable1->FieldByName("first_name")->AsString;*/
					ADODataSet1->FieldByName("status_id")->AsString;
		gridJobList->Cells[6][rowCounter] =
					/*ADOTable1->FieldByName("last_name")->AsString;*/
					ADODataSet1->FieldByName("assigned_to")->AsString;
		gridJobList->Cells[7][rowCounter] =
					/*ADOTable1->FieldByName("mobile_number")->AsString;*/
					ADODataSet1->FieldByName("time_spent")->AsString;
		rowCounter++;
		ADODataSet1->Next();
	}

	ADODataSet1->First();
}
//---------------------------------------------------------------------------


