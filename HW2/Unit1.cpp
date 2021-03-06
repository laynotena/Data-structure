//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
# define SWAP(x, y, t) (t=x, x=y, y=t)

//SWAP(Macro)


char list[9] = {'A','B','C','D','E','F','G','H','I'};
int counter = 0;
int count1 = 0;
int count = 0;
int counts = 0;
int counts1 = 0;

TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}

void perm (char *list, int k, int n)
{ //要先產生c[k],...,c[n-1]的所有排列
int i, tmp ;
if (k == n-1) //終結條件成立時輸出此項排列
	{   String a = list; // Convert char* list to String a
		a = a.SubString(1,n); //The first n characters of a
		//a.SubString(1,n) ==> the n-char starting from a[1]
		Form1->Memo1->Lines->Add(a+"["+IntToStr(count++)+"]");
	}
else //讓c[k]固定不動，求perm(c[], k+1, n)
	{   for (i = k; i < n; i++) //讓c[k]-c[n-1]輪流當c[k]
		{   SWAP(list[k],list[i],tmp);
			perm(list, k+1, n);
			SWAP(list[k], list[i], tmp);

		}

	}
}

void perm_tracing (char *list, int k, int n)
{	int i, tmp ;
	if (k == n-1)
		{   String a = list;
			a = a.SubString(1,n);
			Form1->Memo2->Lines->Add("==>(k, n)=("+IntToStr(k)+" ,"+IntToStr(n)+")! k==n-1 print !");
			Form1->Memo2->Lines->Add(a+"["+IntToStr(counts++)+"]");
		}
	else //讓c[k]固定不動，求perm(c[], k+1, n)
		{   for (i = k; i < n; i++) //讓c[k]-c[n-1]輪流當c[k]
			{   SWAP(list[k],list[i],tmp);
                String a = list;
				a = a.SubString(1,n);
				Form1->Memo2->Lines->Add(">i="+IntToStr(i)+" (k,n)=("+IntToStr(k)+" , "+IntToStr(n)+"), swap[k, i] = ["+IntToStr(k)+" , "+IntToStr(i)+"] , list[] ="+a) ;
				perm_tracing(list, k+1, n);
				SWAP(list[k], list[i], tmp);
				Form1->Memo2->Lines->Add(">i="+IntToStr(i)+" (k,n)=("+IntToStr(k)+" , "+IntToStr(n)+"), swap[k, i] = ["+IntToStr(k)+" , "+IntToStr(i)+"] , list[] ="+a) ;
			}

		}
}

void permStr(String in_string, int k, int n)
{   int i, tmp;
	if (k==n)
	Form1->Memo1->Lines->Add(in_string+"["+IntToStr(count1++)+"]");
	else
	{   for (i = k; i <= n; i++)
		{   SWAP(in_string[k], in_string[i],tmp);
			permStr(in_string, k+1, n);
			SWAP(in_string[k], in_string[i], tmp);
		}

	}
}


void permStr_tracing(String in_string, int k, int n)
{   int i, tmp;
	if (k==n)
		{
		Form1->Memo2->Lines->Add("==>(k, n)=("+IntToStr(k)+" ,"+IntToStr(n)+")! k==n print !");
		Form1->Memo2->Lines->Add(in_string+"["+IntToStr(counts1++)+"]");
		}
	else
	{   for (i = k; i <= n; i++)
		{   SWAP(in_string[k], in_string[i],tmp);
			Form1->Memo2->Lines->Add(">i="+IntToStr(i)+" (k,n)=("+IntToStr(k)+" , "+IntToStr(n)+"), swap[k, i] = ["+IntToStr(k)+" , "+IntToStr(i)+"] , list[] ="+in_string) ;
			permStr_tracing(in_string, k+1, n);
			SWAP(in_string[k], in_string[i], tmp);
			Form1->Memo2->Lines->Add(">i="+IntToStr(i)+" (k,n)=("+IntToStr(k)+" , "+IntToStr(n)+"), swap[k, i] = ["+IntToStr(k)+" , "+IntToStr(i)+"] , list[] ="+in_string) ;
		}

	}
}


void Hanoi (int disk, String source, String spare, String destination)
{
	if (disk==1)
		{
			Form1->Memo1->Lines->Add("Step "+IntToStr(counter++)+": Move the top disk from tower "+source+" to tower "+destination);
		}
		else
		{   Hanoi(disk-1, source, destination,spare);

			Hanoi(1, source, spare, destination);
			Hanoi(disk-1, spare, source, destination);
		}


  }


//---------------------------------------------------------------------------



void __fastcall TForm1::Button1Click(TObject *Sender)
{   int n, k;
	count = 0;
	counts = 0;
	k = StrToInt(Edit1 ->Text);
	n = StrToInt(Edit2 ->Text);
	perm(list, k, n); //傳入list陣列、起始註標k與結束註標n
	Form1->Memo1->Lines->Add("----------------------------");
	if (CheckBox1->Checked)	Form1->Memo2->Lines->Add("Go ==> (k, n) = ("+IntToStr(k)+", "+IntToStr(n)+") ");
	if (CheckBox1->Checked) perm_tracing(list, k, n);

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender)
{	char ch[100];
	int n, k, i;
	count = 0;
	counts = 0;
	String a = Edit3->Text;

	for (i = 0; i < a.Length(); i++)ch[i] = a[i+1];
	ch[i] = '\0';


	n = Edit3->Text.Length();
	k = StrToInt(Edit4 ->Text);
	perm(ch, k, n); //傳入list陣列、起始註標k與結束註標n
	Form1->Memo1->Lines->Add("----------------------------");
	if (CheckBox1->Checked)	Form1->Memo2->Lines->Add("Go ==> (k, n) = ("+IntToStr(k)+", "+IntToStr(n)+") ");
	if (CheckBox1->Checked) perm_tracing(ch, k, n);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{   String in_string;
	int k, n;
	count1 = 0;
	counts1 = 0;
	in_string = Edit3->Text;
	k = StrToInt(Edit4->Text);
	n = in_string.Length();
	permStr(in_string, k+1, n);
	Form1->Memo1->Lines->Add("----------------------------");
	if (CheckBox1->Checked)	Form1->Memo2->Lines->Add("Go ==> (k, n) = ("+IntToStr(k)+", "+IntToStr(n)+") ");
	if (CheckBox1->Checked) permStr_tracing(in_string, k+1, n);

}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button4Click(TObject *Sender)
{
	int disk = StrToInt(Edit5->Text);
    counter = 0;
	Hanoi(disk, "A", "B", "C");
	Form1->Memo1->Lines->Add("-----"+IntToStr(counter)+" steps in total for "+disk+" disks -----");

}
//---------------------------------------------------------------------------

