//---------------------------------------------------------------------------

#ifndef JobH
#define JobH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ADODB.hpp>
#include <ComCtrls.hpp>
#include <DB.hpp>
#include <DBCtrls.hpp>
//---------------------------------------------------------------------------
class TForm6 : public TForm
{
__published:	// IDE-managed Components
	TButton *btnSave;
	TADOConnection *ADOConnection1;
	TPageControl *PageControl1;
	TTabSheet *TabSheet2;
	TLabel *lblStartTime;
	TLabel *lblEndTime;
	TDateTimePicker *DateTimePicker1;
	TDateTimePicker *DateTimePicker2;
	TTabSheet *TabSheet1;
	TLabel *lblCustomer;
	TLabel *lblDescription;
	TLabel *lblStatus;
	TLabel *lblAssigned;
	TLabel *lblJobNumber;
	TEdit *txtJob;
	TDBLookupComboBox *ddlCustomer;
	TADOTable *ADOTable_customer;
	TDataSource *DataSource_Customer;
	TADOTable *ADOTable_job;
	TDataSource *DataSource_Job;
	TADOTable *ADOTable_Status;
	TDataSource *DataSource_Status;
	TDBLookupComboBox *ddlStatus;
	TDBLookupComboBox *ddlAssigned;
	TADOTable *ADOTable_assigned;
	TDataSource *DataSource_assigned;
	TMemo *memo1;
	void __fastcall btnSaveClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm6(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm6 *Form6;
//---------------------------------------------------------------------------
#endif
