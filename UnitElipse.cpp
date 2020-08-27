//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitElipse.h"
#include "UnitEixoXY.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFElipse *FElipse;
//---------------------------------------------------------------------------
__fastcall TFElipse::TFElipse(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFElipse::BtnElipseClick(TObject *Sender)
{

int Contador_Circle=EixoXY->Contador_Circle;

	BtnElipse->Enabled=false;

	EixoXY->Objetos_Atr[0].Elipse_Atr->AlocaElipse_Atr(Contador_Circle+1);
	EixoXY->P_Circle=EixoXY->Realocar_Ponteiro_DuploC(EixoXY->P_Circle,Contador_Circle+1);

	EixoXY->Objetos_Atr[0].Elipse_Atr->SetColor_Circle_Atr(Cores->Selected,Contador_Circle);

	EixoXY->Objetos_Atr[0].Elipse_Atr->SetA_Atr(EdtA->Text.ToDouble(),Contador_Circle);
	EixoXY->Objetos_Atr[0].Elipse_Atr->SetB_Atr(EdtB->Text.ToDouble(),Contador_Circle);
	EixoXY->Objetos_Atr[0].Elipse_Atr->SetAZo_Atr(EdtAZo->Text.ToDouble(),Contador_Circle);
	EixoXY->Objetos_Atr[0].Elipse_Atr->SetBZo_Atr(EdtBZo->Text.ToDouble(),Contador_Circle);

	double cx=EdtCentroX->Text.ToDouble();
	double cy=EdtCentroY->Text.ToDouble();
	double cz=EdtCentroZ->Text.ToDouble();
	EixoXY->Objetos_Atr[0].Elipse_Atr->SetCX(cx,Contador_Circle);
	EixoXY->Objetos_Atr[0].Elipse_Atr->SetCY(cy,Contador_Circle);
    EixoXY->Objetos_Atr[0].Elipse_Atr->SetCZ(cz,Contador_Circle);
	EixoXY->Objetos_Atr[0].Elipse_Atr->SetCenter_Atr((float)cx,(float)cy,(float)cz,Contador_Circle);

	if(RBEixoXY->Checked)
		EixoXY->Objetos_Atr[0].Elipse_Atr->SetTipoElipse_Atr(0,Contador_Circle);

	if(RBEixoXZ->Checked)
		EixoXY->Objetos_Atr[0].Elipse_Atr->SetTipoElipse_Atr(1,Contador_Circle);

	if(RBEixoYZ->Checked)
		EixoXY->Objetos_Atr[0].Elipse_Atr->SetTipoElipse_Atr(2,Contador_Circle);




	EixoXY->Contador_Circle++;
	EixoXY->Objetos_Atr[0].Elipse_Atr->SetContadorCircle_Atr(EixoXY->Contador_Circle);
    EixoXY->Objetos_Atr[0].SetAlpha_B_T(EixoXY->ABT);
	EixoXY->Draw_Elipse(EixoXY->Canvas,EixoXY->Objetos_Atr,EixoXY->P_Circle);
}
//---------------------------------------------------------------------------
