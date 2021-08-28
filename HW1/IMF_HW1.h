//---------------------------------------------------------------------------

#ifndef IMF_HW1H
#define IMF_HW1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TEdit *Edit1;
	TMemo *Memo1;
	TLabel *Label1;
	TEdit *Edit2;
	TLabel *Label2;
	TButton *Button2;
	TMemo *Memo2;
	TCheckBox *CheckBox1;
	TMemo *Memo3;
	TButton *Button3;
	TMemo *Memo4;
	TButton *Button4;
	TCheckBox *CheckBox2;
	TLabel *Label3;
	TEdit *Edit3;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif