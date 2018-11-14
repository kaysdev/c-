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
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TForm5 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TADOConnection *ADOConnection1;
	TADOQuery *ADOQuery1;
	TDataSource *DataSource1;
	TAutoIncField *ADOQuery1job_id;
	TIntegerField *ADOQuery1job_number;
	TMemoField *ADOQuery1job_description;
	TStringField *ADOQuery1customer_name;
	TStringField *ADOQuery1mobile_number;
	TStringField *ADOQuery1user_name;
	TFloatField *ADOQuery1time_spent;
	TStringField *ADOQuery1status_name;
	TStringGrid *gridJobList;
	TADODataSet *ADODataSet1;
	TAutoIncField *ADODataSet1job_id;
	TIntegerField *ADODataSet1job_number;
	TIntegerField *ADODataSet1customer_id;
	TMemoField *ADODataSet1job_description;
	TIntegerField *ADODataSet1status_id;
	TIntegerField *ADODataSet1assigned_to;
	TFloatField *ADODataSet1time_spent;
	TDateTimeField *ADODataSet1entry_date;
	TDateTimeField *ADODataSet1last_update_date;
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
