//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dashboard.h"
#include "CustomerList.h"
#include "JobList.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Customer1Click(TObject *Sender)
{
	Form4->ShowModal();
	//ShowMessage("Customer");
}
//---------------------------------------------------------------------------
// on click on job menu bar; job list will be open
void __fastcall TForm2::Jobs2Click(TObject *Sender)
{
	//fmrJobList->ShowModal();
	Form5->ShowModal();
	//ShowMessage("Jobs");
}
