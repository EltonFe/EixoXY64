//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitConstrucaoLine.h"
#include "UnitEixoXY.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TConstrucaoLines *ConstrucaoLines;
int Count=0;
int Conta_Ponto=1;

bool EixoXo(float xo,float yo, float *Alphat,float *MVetorXY);
//---------------------------------------------------------------------------
__fastcall TConstrucaoLines::TConstrucaoLines(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
bool EixoXo(float xo,float yo, float *Alphat,float *MVetorXY){

float MXYVetor;

float MVetorXY1;
float Alphat1=0;






MVetorXY1=Sqrt((xo*xo) +(yo*yo));
if (MVetorXY1<0) {
		*Alphat=0;
		*MVetorXY=0;
		 return 0;
		 }

if((xo==0)&&(yo==0)){
*Alphat=0;
*MVetorXY=0;
return 0;

}

	MXYVetor=MVetorXY1;


	*MVetorXY=MVetorXY1;

	 if (xo==0) {
		 if (yo>0){
			*Alphat=M_PI/2;

		 return 0;

		}
	 if (yo<0) {
		*Alphat=-M_PI/2;

	  return 0;
	 }


}else{

	  if (yo==0) {
		if(xo>0){
			*Alphat=0;
			return 0;
		}
		if(xo<0){
			*Alphat=M_PI;

			 return 0;
		}


	  }

	  if ((xo<0)&&(yo<0)) {
		 try{
		 xo=-xo;

		 Alphat1=acos(xo/MVetorXY1)+M_PI;
		 xo=-xo;
		 }catch(Exception &ex){
		  ShowMessage("Divis�o por Zero");


		 }


	  }


		  if ((xo<0)&&(yo>0)) {
		  try{
		xo=-xo;

		Alphat1=M_PI-acos(xo/MVetorXY1);

		xo=-xo;
		  }catch(Exception &ex){
		  ShowMessage("Divis�o por Zero");
		  }
		  }

	  if ((xo>0)&&(yo<0)) {
		 try{
		 Alphat1=2*M_PI-acos(xo/MVetorXY1);
		  }catch(Exception &ex){
		  ShowMessage("Divis�o por Zero");
		  }
	  }

	  if ((xo>0)&&(yo>0)) {
		try{
		 Alphat1=acos(xo/MVetorXY1);
		 }
		 catch(Exception &ex){
		 ShowMessage("Divis�o por Zero");
		 }
	  }

	  }



	*Alphat=Alphat1;





  return 0;

}
int **Realocar_Ponteiro_DuploC(int **Ponteiro,int Count){

int **Tmp_Ponteiro=Ponteiro;
bool Testa=true;

	do{

		Tmp_Ponteiro=(int**)realloc(Tmp_Ponteiro,Count*sizeof(int *));

		for(int i=0;i<Count;i++){
			Tmp_Ponteiro[i]=0;
			Tmp_Ponteiro[i]=(int*)realloc(Tmp_Ponteiro[i],4*sizeof(int));
		}

		if(Tmp_Ponteiro==NULL){

			Tmp_Ponteiro=0;
			Tmp_Ponteiro=Ponteiro;
			Testa=true;

		}else{

				Testa=false;
				Ponteiro=Tmp_Ponteiro;
			}

	}while(Testa);

	return Ponteiro;

}

//------------------------------------------------------------------------------
void __fastcall TConstrucaoLines::BConstruirLineClick(TObject *Sender)
{
float xo=EdtXo->Text.ToDouble();
float yo=EdtYo->Text.ToDouble();
float zo=EdtZo->Text.ToDouble();
float Angulo_Line;
float Modulo_Line;


    EixoXY->Objetos_Atr[0].Lines_Atr->Alocando_Line(EixoXY->Contador_Line+1);
	EixoXY->Objetos_Atr[0].Lines_Atr->SetCor_Line((unsigned long )Cores->Selected,EixoXY->Contador_Line);

	if((Count%2)==0){

		Count++;

		EixoXY->FullMLK=Realocar_Ponteiro_DuploC(EixoXY->FullMLK, EixoXY->Contador_Line+1);


		EixoXo(xo,yo,&Angulo_Line,&Modulo_Line);
		EixoXY->Objetos_Atr[0].Lines_Atr->SetMAlpha_Atr(Angulo_Line,EixoXY->Contador_Line);
		EixoXY->Objetos_Atr[0].Lines_Atr->SetMVetor_Atr(Modulo_Line,EixoXY->Contador_Line);
		EixoXY->Objetos_Atr[0].Lines_Atr->SetMZo_Atr(zo,EixoXY->Contador_Line);
		LMPonto->Caption="P1:"+IntToStr(Conta_Ponto)+"->( "+FloatToStr(xo)+",  "+FloatToStr(yo)+", "+FloatToStr(zo)+");";




	}else{


            EixoXo(xo,yo,&Angulo_Line,&Modulo_Line);
			EixoXY->Objetos_Atr[0].Lines_Atr->SetLAlpha_Atr(Angulo_Line,EixoXY->Contador_Line);
			EixoXY->Objetos_Atr[0].Lines_Atr->SetLVetor_Atr(Modulo_Line,EixoXY->Contador_Line);
			EixoXY->Objetos_Atr[0].Lines_Atr->SetLZo_Atr(zo,EixoXY->Contador_Line);
			LLPonto->Caption="P2:"+IntToStr(Conta_Ponto)+"->( "+FloatToStr(xo)+",  "+FloatToStr(yo)+", "+FloatToStr(zo)+");";
			Count++;
			EixoXY->Contador_Line++;
			EixoXY->Objetos_Atr[0].Lines_Atr->SetContador_Line(EixoXY->Contador_Line);
			Conta_Ponto++;
		}







  Sleep(300);

}
//---------------------------------------------------------------------------

