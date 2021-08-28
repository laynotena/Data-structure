//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "IMF_HW3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#define MaxSize 21
int square[MaxSize][MaxSize];

TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}

void MagicSquare_lu(int n)
{   int i, j, k, l, data;

	for (i = 0; i < n; i++)
	   for (j = 0; j < n; j++)
			square[i][j] = 0;
	if (Form1->RadioButton5->Checked)
	{	i =0;
		j = (n-1)/2;
	}
	else if (Form1->RadioButton6->Checked)
	{	i =(n-1)/2;
		j = 0;
	}
	else if (Form1->RadioButton7->Checked)
	{	i =(n-1)/2;
		j = n-1;
	}
	else if (Form1->RadioButton8->Checked)
	{	i = n-1;
		j = (n-1)/2;
	}
	else
	{ShowMessage("�п�ܤ@�� Start Point!");
	 return;
	}
	square[i][j] = 1;
	data = 2;

	if (Form1->RadioButton1->Checked)
	{   while (data <= n*n)
		{   k = (i-1<0) ? n-1 : i-1;
			l = (j-1<0) ? n-1 : j-1;
			if (square[k][l] > 0 ) i = (i+1)%n;
			else {i = k;
				  j = l;
				 }
		square[i][j] = data++;
		}
	}
	else if (Form1->RadioButton2->Checked)
	{	while (data <= n*n)
		{   k = (i-1<0) ? n-1 : i-1;
			l = (j+1==n) ? 0 : j+1;
			if (square[k][l] > 0 ) i = (i+1)%n;
			else {i = k;
				  j = l;
				 }
		square[i][j] = data++;
		}
	}
	else if (Form1->RadioButton3->Checked)
	{	while (data <= n*n)
		{k = (i+1==n) ? 0 : i+1;
		 l = (j-1<0) ? n-1 : j-1;
		 if (square[k][l] > 0)	i = (i+n-1)%n;
		 else{i = k;
			  j = l;
			 }
		 square[i][j] = data++;
		}
	}
	else if (Form1->RadioButton4->Checked)
	{	while (data <= n*n)
		{k = (i+1==n) ? 0 : i+1;
		 l = (j+1==n) ? 0 : j+1;
		 if (square[k][l] > 0)	i = (i+n-1)%n;
		 else{i = k;
			  j = l;
			 }
		 square[i][j] = data++;
		}
	}
	else
	{ShowMessage("�п�ܤ@��move direction!");
	 return;
	}
}

void printSquare(int n)
{   int i, j, k;
	int block = IntToStr(n*n).Length()+2, blank_len;

	String line;
	String str;
		for (i = 0; i < n; i++)
		{   line = "";
			for (j = 0; j < n; j++)
			{   line += IntToStr(square[i][j]) + "  ";

			}
			Form1->Memo1->Lines->Add(line);
		}
        for (i = 0; i < n; i++)
		{   line = "";
			for (j = 0; j < n; j++)
			{   str = IntToStr(square[i][j]);
				blank_len = block - str.Length();
				for (k = 0; k < blank_len; k++) line += " ";
				line += IntToStr(square[i][j]) + "  ";
			}
			Form1->Memo2->Lines->Add(line);
			Form1->RichEdit1->Lines->Add(line+"\n");

		}
		Form1->StringGrid1->RowCount = n;
		Form1->StringGrid1->ColCount = n;
		for (i = 0; i < n; i++)
		{   Form1->StringGrid1->ColWidths[i] = 36;
			for (j = 0; j < n; j++)
			{   Form1->StringGrid1->Cells[j][i] = IntToStr(square[i][j]);

			}

		}
}


//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{	int n = StrToInt(Edit1->Text);

	if ((n>MaxSize)||(n<1))
	{	ShowMessage("��J����L�j�A�����B�z�C");
		return;
	}
	else if ((n%2)==0)
	{	ShowMessage("��J�����`�����ơA�����B�z�C");
		return;
	}

	MagicSquare_lu(n);
	Form1->Memo1->Lines->Add("---Magic Square "+ IntToStr(n)+"x"+IntToStr(n)+"---");
	Form1->Memo2->Lines->Add("---Magic Square "+ IntToStr(n)+"x"+IntToStr(n)+"---");
	Form1->RichEdit1->Lines->Add("---Magic Square "+ IntToStr(n)+"x"+IntToStr(n)+"---");
	printSquare(n);
}
//---------------------------------------------------------------------------



