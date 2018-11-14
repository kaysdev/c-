//---------------------------------------------------------------------------

#ifndef JobListH
#define JobListH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TForm5 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TADOConnection *ADOConnection1;
	TADOQuery *ADOQuery1;
	TDataSource *DataSource1;
	TStringGrid *gridJobList;
	TAutoIncField *ADOQuery1job_id;
	TIntegerField *ADOQuery1job_number;
	TMemoField *ADOQuery1job_description;
	TStringField *ADOQuery1customer_name;
	TStringField *ADOQuery1mobile_number;
	TStringField *ADOQuery1status_name;
	TStringField *ADOQuery1user_name;
	TFloatField *ADOQuery1time_spent;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall DBGrid1DblClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm5(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm5 *Form5;
//---------------------------------------------------------------------------
#endif
