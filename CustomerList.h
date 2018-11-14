//---------------------------------------------------------------------------

#ifndef CustomerListH
#define CustomerListH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TForm4 : public TForm
{
__published:	// IDE-managed Components
TADOConnection *ADOConnection1;
	TButton *btnAddNew;
	TStringGrid *gridCustomerList;
	TADOTable *ADOTable1;
	TADODataSet *ADODataSet1;
	void __fastcall btnAddNewClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall gridCustomerListSelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect);
private:	// User declarations
public:		// User declarations
	__fastcall TForm4(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
//---------------------------------------------------------------------------
#endif
