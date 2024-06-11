//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TEdit *title;
	TEdit *director;
	TEdit *year;
	TButton *save;
	TListBox *list;
	TButton *edit;
	TButton *del;
	TComboBox *genre;
	TButton *clear;
	TLabel *tlabel;
	TLabel *rlabel;
	TLabel *tlabel2;
	TLabel *rlabel2;
	TLabel *slabel;
	TComboBox *sorting;
	TLabel *Label7;
	TRadioGroup *stan;
	void __fastcall saveClick(TObject *Sender);
	void __fastcall editClick(TObject *Sender);
	void __fastcall delClick(TObject *Sender);
	void __fastcall clearAllClick(TObject *Sender);
	void __fastcall sortingChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
