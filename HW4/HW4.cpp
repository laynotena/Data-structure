//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "HW4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#define possible_direction 8


TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void stackFull()
{ShowMessage("StackFull!");
 return;
}

void stackEmpty()
{ShowMessage("StackEmpty!");
 return;
}

int m,n;
int maze[20][20];
int top = -1;
struct offset
{int dx, dy;
};
struct offset move[possible_direction];
struct position
{   int x,y;
	int dir;
};
struct position stack [200];

void push(struct position data)
{	if (top == m*n-1 ) stackFull();
	else stack[++top] = data;
}

struct position pop()
{   if (top == -1) stackEmpty();
	else return stack[top--];
}

void path(int m, int n)
{int i,j,u,v;
 String str;
 struct position step;
 int mark[200][200];
 boolean found = false;

 move[0].dx = -1; move[0].dy = 0;
 move[1].dx = -1; move[1].dy = 1;
 move[2].dx = 0; move[2].dy = 1;
 move[3].dx = 1; move[3].dy = 1;
 move[4].dx = 1; move[4].dy = 0;
 move[5].dx = 1; move[5].dy = -1;
 move[6].dx = 0; move[6].dy = -1;
 move[7].dx = -1; move[7].dy = -1;

 Form1->Memo2->Lines->Add("m="+IntToStr(m)+" n="+IntToStr(n));
 Form1->Memo2->Lines->Add(found);
 for (i = 0; i <= m+1; i++)
 { for (j = 0; j <= n+1; j++)
   {    mark[i][j] = maze[i][j];
   }
 }

 step.x = step.y = 1;
 step.dir = 2;
 push(step);

 Form1->Memo2->Lines->Add("push step :"+IntToStr(step.x)+","+IntToStr(step.y)+","+IntToStr(step.dir));

 while(top != -1)
	  {step = pop();
	   Form1->Memo2->Lines->Add("pop step :"+IntToStr(step.x)+","+IntToStr(step.y)+","+IntToStr(step.dir));
	   while((step.dir<=7) && (!found))
			{   //(u,v) = 自(i,j)欲嘗試的下一步座標
				u = step.x+move[step.dir].dx;
				v = step.y+move[step.dir].dy;
				int x = step.dir;
				Form1->Memo2->Lines->Add("..(u,v)="+IntToStr(u)+","+IntToStr(v));
				Form1->Memo2->Lines->Add("..from:"+IntToStr(step.x)+","+IntToStr(step.y)+","+IntToStr(x));

				if((u==m) && (v==n+1))
					{   found = true; //成功找到出口，輸出路徑，可以停止
						str = "("+IntToStr(m)+","+IntToStr(n)+")";
						Form1->StringGrid1->Cells[step.y][step.x] = "->";
						Form1->StringGrid2->Cells[step.y][step.x] = "->";
						Form1->StringGrid1->Cells[0][1] = "->";
						Form1->StringGrid2->Cells[0][1] = "->";
						Form1->StringGrid1->Cells[n+1][m] = "->";
						Form1->StringGrid2->Cells[n+1][m] = "->";
						while (top != -1)
							  {step = pop();
							   str = "("+IntToStr(step.x)+","+IntToStr(step.y)+","+IntToStr(step.dir)+")-->"+str;
							   Form1->StringGrid1->Cells[step.y][step.x] = "->";
							   Form1->StringGrid2->Cells[step.y][step.x] = "->";
							   Form1->StringGrid3->Cells[step.y][step.x] = "->";
							   Form1->StringGrid4->Cells[step.y][step.x] = "->";
							   Form1->StringGrid5->Cells[step.y][step.x] = "->";
							  }
						Form1->Memo2->Lines->Add(str);

					}
				else if((maze[u][v]==0) && (mark[u][v]==0)) //(u,v)可以走，且不曾走過
					   {    mark[u][v] = 1;
							Form1->StringGrid1->Cells[v][u] = "*";
							Form1->StringGrid2->Cells[v][u] = "*";

							push(step);
							Form1->Memo2->Lines->Add("push step :"+IntToStr(step.x)+","+IntToStr(step.y)+","+IntToStr(step.dir));
							step.x = u; step.y = v; step.dir = 0;
							Form1->Memo2->Lines->Add("step"+IntToStr(u)+","+IntToStr(v)+","+IntToStr(step.dir));
					   }
				else step.dir +=1;
			}


	  }
 if ((step.dir == 8)&&(found = false))
 	Form1->Memo2->Lines->Add("此迷宮無出路");
}



void __fastcall TForm1::Button1Click(TObject *Sender)
{FILE*fp; //Define fp as a poitner pointing to some file (with data type FILE) in HD
 String out;
 int i, j;
 int grid_size = StrToInt(Edit1->Text);
 AnsiString infile; //Use builder's string(AnsiString) to ease the conversion (into const char*)
 if (OpenDialog1->Execute())
 {  infile = OpenDialog1->FileName;
	fp = fopen(infile.c_str(), "r+");
	//c_str函數的傳回值是const char*, 即把AnsiString轉成const char*給fopen使用

	fscanf(fp, "%d %d",&m,&n); //Read in two integers m&n
	Memo2->Lines->Add("(m,n)="+IntToStr(m)+","+IntToStr(n));
	for (i = 0; i < m; i++) //Read in m*n 0/1/2's into maze[][]
		for (j = 0; j < n; j++)
			fscanf(fp,"%d",&maze[i+1][j+1]);

	for (i = 0; i <= m; i++) { maze[i][0] = 2; maze[i][n+1] = 2;}
	for (j = 0; j <= n; j++) { maze[0][j] = 2; maze[m+1][j] = 2;}
	maze[1][0] = 0; maze[m][n+1] = 0; maze[m+1][n+1] = 2;
	fclose(fp);

	for (i = 0; i < m+2; i++) //Print out maze[][] in Memo2
	{   out="";
		for (j = 0; j < n+2; j++) out+=" "+IntToStr(maze[i][j]);
		Memo2->Lines->Add(out);
	}
	//Print out maze [][] in StringGrid1,2,3,4
	StringGrid1->RowCount = m+2;
	StringGrid1->ColCount = n+2;
	StringGrid2->RowCount = m+2;
	StringGrid2->ColCount = n+2;
	StringGrid3->RowCount = m+2;
	StringGrid3->ColCount = n+2;
	StringGrid4->RowCount = m+2;
	StringGrid4->ColCount = n+2;
	StringGrid5->RowCount = m+2;
	StringGrid5->ColCount = n+2;
	for (i = 0; i < m+2; i++)
		for (j = 0; j < n+2; j++)
		   {StringGrid1->Cells[j][i]=maze[i][j];
			StringGrid2->Cells[j][i]=maze[i][j];
			StringGrid3->Cells[j][i]=maze[i][j];
			StringGrid4->Cells[j][i]=maze[i][j];
			StringGrid5->Cells[j][i]=maze[i][j];
		   }

	StringGrid2->DefaultDrawing = false; // 可避免垂直分隔線過粗
	StringGrid3->DefaultDrawing = false;
	StringGrid4->DefaultDrawing = false;
	StringGrid5->DefaultDrawing = false;

	StringGrid2->FixedCols = 0;   StringGrid2->FixedRows = 0;
	StringGrid3->FixedCols = 0;   StringGrid3->FixedRows = 0;
	StringGrid4->FixedCols = 0;   StringGrid4->FixedRows = 0;
	StringGrid5->FixedCols = 0;   StringGrid5->FixedRows = 0;
	StringGrid5->GridLineWidth = 0;


	for (i=0; i<m+2; i++)
		{StringGrid2->RowHeights[i] = grid_size;
		 StringGrid3->RowHeights[i] = grid_size;
		 StringGrid4->RowHeights[i] = grid_size;
		 StringGrid5->RowHeights[i] = grid_size;
		}
	for (i=0; i<n+2; i++)
		{StringGrid2->ColWidths[i] = grid_size;
		 StringGrid3->ColWidths[i] = grid_size;
		 StringGrid4->ColWidths[i] = grid_size;
		 StringGrid5->ColWidths[i] = grid_size;
		}
	StringGrid2->Refresh();
	StringGrid3->Refresh();
	StringGrid4->Refresh();
	StringGrid5->Refresh();

 }

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{FILE*fp;
 String out;
 int i, j;
 AnsiString infile;
 if (SaveDialog1->Execute()) //確認SaveDialog1讀取檔案成功
 { //取SaveDialog1所開啟的檔案名稱, 將檔案名稱轉為char格式後用fopen開啟此檔案
  AnsiString file_name = SaveDialog1->FileName;
  FILE*fp = fopen(file_name.c_str(),"w"); //"w"表示開以寫檔的方式開啟
  //利用fprintf將g_matrix中的元素寫入fp, 當需要換行時使用putc將'\n'加入fp中
  if (fp)
  { fprintf(fp, "%d %d", m, n);
	//putc('\n',fp);
	for (i = 1; i < m+1; i++)
	{   putc('\n',fp);
		for (j = 1; j < n+1; j++)
		{   fprintf(fp, "%d", maze[i][j]);
		}
	}
	fclose(fp);//寫完檔後請關檔
  }
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{int grid_size = StrToInt(Edit1->Text);
 int i,m,n;
 m = StringGrid1->RowCount;
 n = StringGrid1->ColCount;
for (i=0; i<m; i++)
	{StringGrid2->RowHeights[i] = grid_size;
	 StringGrid3->RowHeights[i] = grid_size;
	 StringGrid4->RowHeights[i] = grid_size;
	 StringGrid5->RowHeights[i] = grid_size;
	}
for (i=0; i<n; i++)
	{StringGrid2->ColWidths[i] = grid_size;
	 StringGrid3->ColWidths[i] = grid_size;
	 StringGrid4->ColWidths[i] = grid_size;
	 StringGrid5->ColWidths[i] = grid_size;
	}
StringGrid2->Refresh();
StringGrid3->Refresh();
StringGrid4->Refresh();
StringGrid5->Refresh();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button4Click(TObject *Sender)
{ path(m,n);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::StringGrid2DrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State)
{StringGrid2->Canvas->Brush->Color = clWhite;
 StringGrid2->Canvas->Font->Color = clBlue;
 StringGrid2->Canvas->FillRect(Rect);
 AnsiString text = StringGrid2->Cells[ACol][ARow];
 StringGrid2->Canvas->TextRect(Rect, Rect.Left+8, Rect.Top+8, text);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::StringGrid2Click(TObject *Sender)
{ TRect Recto = StringGrid1->CellRect(StringGrid1->Col, StringGrid1->Row);
  int width = Recto.Width(); int height = Recto.Height();
  Label2->Caption = "Cell:["+IntToStr(StringGrid2->Col)+","+IntToStr(StringGrid2->Row)+"]="+StringGrid2->Cells[StringGrid2->Col][StringGrid2->Row];
  Label3->Caption = "Size:"+IntToStr(width)+"X"+IntToStr(height);
  Label4->Caption = StringGrid1->Cells[StringGrid2->Col][StringGrid2->Row];
}
//---------------------------------------------------------------------------

void __fastcall TForm1::StringGrid3DrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State)
{AnsiString text = StringGrid2->Cells[ACol][ARow];
 if (text == "0")
 StringGrid3->Canvas->Brush->Color = TColor RGB(249, 205, 173);
 else if (text == "->")
 StringGrid3->Canvas->Brush->Color = TColor RGB(254, 67, 101);
 else if (text == "2")
 StringGrid3->Canvas->Brush->Color = TColor RGB(34, 8, 7);
 else if (text == "*")
 StringGrid3->Canvas->Brush->Color = TColor RGB(252, 157, 154);
 else
 StringGrid3->Canvas->Brush->Color = TColor RGB(23, 44, 60);
 StringGrid3->Canvas->FillRect(Rect);
 StringGrid3->Canvas->TextRect(Rect, Rect.Left+6, Rect.Top+8, text);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::StringGrid4DrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State)
{AnsiString text = StringGrid2->Cells[ACol][ARow];
 if (text == "0")
 StringGrid4->Canvas->Brush->Color = TColor RGB(249, 205, 173) ;
 else if (text == "2")
 StringGrid4->Canvas->Brush->Color = TColor RGB(34, 8, 7);
 else if (text == "->")
 StringGrid4->Canvas->Brush->Color = TColor RGB(254, 67, 101);
 else if (text == "*")
 StringGrid4->Canvas->Brush->Color = TColor RGB(252, 157, 154);
 else StringGrid4->Canvas->Brush->Color = TColor RGB(23, 44, 60);
 StringGrid4->Canvas->FillRect(Rect);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::StringGrid5DrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
		  TGridDrawState State)
{AnsiString text = StringGrid2->Cells[ACol][ARow];
 if (text=="0")
 StringGrid5->Canvas->Brush->Color = TColor RGB(249, 205, 173);
 else if (text == "2")
 StringGrid5->Canvas->Brush->Color = TColor RGB(34, 8, 7);
 else if (text == "->")
 StringGrid5->Canvas->Brush->Color = TColor RGB(254, 67, 101);
 else if (text == "*")
 StringGrid5->Canvas->Brush->Color = TColor RGB(252, 157, 154);
 else
	 StringGrid5->Canvas->Brush->Color = TColor RGB(23, 44, 60);
	 StringGrid5->Canvas->FillRect(Rect);
}
//---------------------------------------------------------------------------

