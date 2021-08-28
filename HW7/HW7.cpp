//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "HW7.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"


TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}


//---------------------------------------------------------------------------

int i, j;
int found1[20];
int W1[20][20];

void SSAD(int W[20][20], int u)
{   int i,j,k,v,a;
	int n = StrToInt(Form1->Edit1->Text);
	int D[n];
	int found[n];
	int from[n];

	int range = StrToInt(Form1->Edit2->Text);
	int max_range = StrToInt(Form1->Edit3->Text);
	int LargeInt = StrToInt(Form1->Edit4->Text);

	Form1->StringGrid2 -> RowCount = n+1;
	Form1->StringGrid2 -> ColCount = n+2;
	for (i = 0; i < n; i++)
	{   Form1->StringGrid2->Cells[0][i+1] = i;
		Form1->StringGrid2->Cells[i+1][0] = i;
	}
	Form1->StringGrid2->Cells[n+1][0] = "from";

	j = 0;
	for (i = 0; i < n; i++)
	{	D[i] = W[i][j];
		from[i] = u;
	}

	for (i = 0; i < n; i++) found[i] = 0;
	found[u] = 1; D[u] =0;

	for (i = 0; i < n; i++)
		Form1->Memo1->Lines->Add("u = "+IntToStr(u)+"D["+IntToStr(i)+"] = "+ IntToStr(D[i]));

	int dist;
	int min;


	for( a=0; a< n; a++)
	{   dist =  99999;
		min = dist;

		for (i = 0; i < n; i++)
		{	if (found[i]==0 )
			{   if (D[i] < min && D[i]!=0)
					{	min = D[i];
						k = i;
					}
			}
		}
		found[k] = 1;

		Form1->Memo1->Lines->Add("k= "+IntToStr(k)+"min ="+IntToStr(min));

		if (u==5)
		{for (i = 0; i < n; i++)
			{	Form1->StringGrid2->Cells[a+1][i+1] = D[i];
				Form1->StringGrid2->Cells[n+1][i+1] = from[i];
			}
		}

		for (v = 0; v < n-1; v++)
		{
			Form1->Memo1->Lines->Add("D[k] = "+IntToStr(D[k])+" k,v "+IntToStr(W[k][v]));

			if (found[v] == 0 && D[v]!=0 )
			{   if (D[v]< D[k]+W[k][v]) D[v] = D[v];
				else{
					D[v] = D[k]+W[k][v];
					from[v] = k;
                    }
			}

		}

	}
	for (i = 0; i < n; i++)
	{found1[i] = found[i];
	}

}



void __fastcall TForm1::Button2Click(TObject *Sender)
{
int n = StrToInt(Form1->Edit1->Text);
int range = StrToInt(Form1->Edit2->Text);
int max_range = StrToInt(Form1->Edit3->Text);
int LargeInt = StrToInt(Form1->Edit4->Text);

	StringGrid1 -> RowCount = n+1;
	StringGrid1 -> ColCount = n+1;
	for (i = 0 ; i < n; i++)
	{   StringGrid1->Cells[0][i+1] = i;
		StringGrid1->Cells[i+1][0] = i;
	}

	int ** W = new int * [n];

	if (W != NULL)
	{   for (i = 0; i < n; i++) delete W[i];
	}


	for (i = 0; i < n; i++)
		W[i] = new int [n];

	for (i = 0; i < n; i++)
	{   for (j = i+1; j < n; j++)
		{   W[i][j] = rand()%range + 1;
			if (W[i][j] > max_range) W[i][j] = LargeInt;
			W[j][i] = W[i][j];
		}

		W[i][i] = LargeInt;
	}

	for (i = 1; i < n+1; i++)
		{	for (j = 1; j < n+1; j++)
			{	StringGrid1 -> Cells[i][j] = W[i-1][j-1];
				W1[i-1][j-1] = W[i-1][j-1];
			}

		}


}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
   SSAD(W1, 0);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{   int n = StrToInt(Form1->Edit1->Text);
	int A[20][20];
	int k;
	StringGrid3 -> RowCount = n+1;
	StringGrid3 -> ColCount = n+1;
	for (i = 0 ; i < n; i++)
	{   StringGrid3->Cells[0][i+1] = i;
		StringGrid3->Cells[i+1][0] = i;
	}
	for (i = 0; i < n; i++)
	{   for (j = 0; j < n; j++)
		{   A[i][j] = W1[i][j];
		}
	}
	for (k = 0; k < n; k++)
	{   for (i = 0; i < n; i++)
		{   for (j = 0; j < n; j++)
			{   if (A[i][j] < A[i][k]+A[k][j]) A[i][j] = A[i][j];
				else A[i][j] = A[i][k]+A[k][j];
				if (i == j) A[i][j] = 0;
			}

		}

	}

	for (i = 0; i < n; i++)
	{   for (j = 0; j < n; j++)
		{   StringGrid3->Cells[i+1][j+1] = A[j][i];
		}

	}


}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button5Click(TObject *Sender)
{   
	int n = StrToInt(Form1->Edit1->Text);
	StringGrid4 -> RowCount = n+1;
	StringGrid4 -> ColCount = n+1;

	for (i = 0 ; i < n; i++)
	{   StringGrid4->Cells[0][i+1] = i;
		StringGrid4->Cells[i+1][0] = i;
	}
	for (i = 0; i < n; i++)
	{   SSAD(W1,i);
		for (j = 0; j < n; j++)
			StringGrid4->Cells[j+1][i+1] = found1[j];
	}
}
//---------------------------------------------------------------------------

