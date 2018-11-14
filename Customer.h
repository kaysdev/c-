//---------------------------------------------------------------------------

#ifndef CustomerH
#define CustomerH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
    TLabel *lblFirstName;
	TLabel *lblLastName;
	TLabel *Label1;
	TEdit *txtFirstName;
	TEdit *txtLastName;
	TEdit *txtMobileNumber;
	TButton *btnSave;
	TADOConnection *ADOConnection1;
	void __fastcall btnSaveClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
