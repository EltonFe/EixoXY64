//---------------------------------------------------------------------------

#ifndef UnitEixoXYH
#define UnitEixoXYH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "UnitConstrucaoLine.h"
#include "UnitElipse.h"
#include "Arquivo.h"
#include <string.h>
#include <Vcl.Menus.hpp>
#include <Vcl.Dialogs.hpp>
using Name_Arquivos::Objetos;
using Name_Arquivos::Line;
//---------------------------------------------------------------------------
class TEixoXY : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPanel *Panel2;
	TRadioButton *Line;
	TLabel *Teste;
	TRadioButton *Cancela_Line;
	TLabel *DrawCursor;
	TTimer *Tempo_Eixo;
	TTimer *Tempo_Draw;
	TColorBox *Cores;
	TPanel *Panel3;
	TButton *ButtonEixo_Zo;
	TButton *BEixoYo;
	TButton *BEixoXo;
	TPanel *Panel4;
	TButton *BDiminuir;
	TPanel *Panel5;
	TRadioGroup *RGVisao;
	TRadioButton *RBVisaoXoZ;
	TRadioButton *RBVisaoXoY;
	TRadioButton *RBVisaoYoZ;
	TRadioGroup *RGLine;
	TButton *BAumentar;
	TEdit *EdtXo;
	TEdit *EdtYo;
	TEdit *EdtZo;
	TPopupMenu *PMEixoXY;
	TMenuItem *ConstruirLinha1;
	TButton *BtnSalvar;
	TButton *BtnAbrir;
	TSaveDialog *DlgSalvar;
	TMenuItem *PElipse;
	TOpenDialog *DlgAbrir;
	void __fastcall FormMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall FormMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall Tempo_DrawTimer(TObject *Sender);
	void __fastcall ButtonEixo_ZoClick(TObject *Sender);
	void __fastcall Tempo_EixoTimer(TObject *Sender);
	void __fastcall LineClick(TObject *Sender);
	void __fastcall RBVisaoXoZClick(TObject *Sender);
	void __fastcall RBVisaoXoYClick(TObject *Sender);
	void __fastcall BEixoYoClick(TObject *Sender);
	void __fastcall BEixoXoClick(TObject *Sender);
	void __fastcall RBVisaoYoZClick(TObject *Sender);
	void __fastcall BAumentarClick(TObject *Sender);
	void __fastcall BDiminuirClick(TObject *Sender);
	void __fastcall ConstruirLinha1Click(TObject *Sender);
	void __fastcall BtnSalvarClick(TObject *Sender);
	void __fastcall PElipseClick(TObject *Sender);
	void __fastcall BtnAbrirClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
	Objetos *Objetos_Atr;
	int Contador_Line;
    int Contador_Circle;
	int **FullMLK;
	TPoint **P_Circle;
	void Draw_Elipse(TCanvas *Plano,Objetos *,TPoint **P_Circle);
    float ABT[3];
	void Draw_Lines(TCanvas *Plano,Objetos *,int **);
	void Grava_Arquivo(Objetos *Objetos_Atr,char *Nome_Arquivo);
	void Ler_Arquivo(Objetos *Objetos_Atr,char *Nome_Arquivo);
	float *Realocar(float *Ponteiro,int Tamanho);
	int *Realocar(int *Ponteiro,int Tamanho);
	TPoint **Realocar_Ponteiro_DuploC(TPoint **Ponteiro,int Tamanho);
	void Limpa_Elipses(TCanvas *,TPoint **,int);
	unsigned long *Realocar(unsigned long *,int );
	__fastcall TEixoXY(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TEixoXY *EixoXY;
//---------------------------------------------------------------------------
#endif
