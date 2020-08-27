//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitEixoXY.h"
#include "Arquivo.h"
#include <fstream>
#include <string.h>

using Name_Arquivos::Objetos;
using Name_Arquivos::Line;
using std::ifstream;
using std::ofstream;


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"


//Varia veis Globais --------------------------------------------------------

TEixoXY *EixoXY;
bool Move=false;
TPoint MP[2];
float FullLKx[100];
float FullLKy[100];

int Contador;
int KOx=1000;
int KOy=580;
int Kx=1000;
int Ky=580;
int Contar=0;
bool Libera_Draw=true;
float ABT[3];
float **Mxyz1=0;
float **Lxyz1=0;
//Prototipacao Funcoes Globais-----------------------------------------------

float **Realocar_Ponteiro_Duplo(float **,int );
int **Realocar_Ponteiro_Duplo(int **,int );
void Eixos(TCanvas *Plano,int Kx,int Ky);
void Limpa_Lines(TCanvas *Plano,int **FullMLK,int Countador_Line);
float OX(float x);
float OY(float y);
int X(int x);
int Y(int y);
int Configura(float Desk, int x);

//---------------------------------------------------------------------------
__fastcall TEixoXY::TEixoXY(TComponent* Owner)
	: TForm(Owner)
{
	Objetos_Atr=new Objetos[1]();
	Mxyz1=0;
	FullMLK=0;
	Objetos_Atr[0].Lines_Atr->GetAlpha_B_T(ABT);
	Contador_Line=0;
	Contador_Circle=0;
	P_Circle=0;
	Kx=Configura((int)Kx,1);
	Ky=Configura((int)Ky,-1);
	KOx=Configura((int)KOx,1);
	KOy=Configura((int)KOy,-1);

}

int Configura(float Desk, int x){
float k;
float k2;

	if (x<1){
		k=1080;
		k2=Screen->DesktopHeight;
	}else {
 		 k=1920;
 		 k2=Screen->DesktopWidth;
 	 }

return (k2/k)*Desk;
}


float *TEixoXY::Realocar(float *Ponteiro,int Tamanho){
float *Tmp_Ponteiro=0;

	Tmp_Ponteiro=Ponteiro;
	Tmp_Ponteiro=(float *)realloc(Tmp_Ponteiro,Tamanho*sizeof(float));

	Ponteiro=Tmp_Ponteiro;
	return Ponteiro;

}

int *TEixoXY::Realocar(int *Ponteiro,int Tamanho){
int *Tmp_Ponteiro=0;

	Tmp_Ponteiro=Ponteiro;
	Tmp_Ponteiro=(int *)realloc(Tmp_Ponteiro,Tamanho*sizeof(int));

	Ponteiro=Tmp_Ponteiro;
	return Ponteiro;

}

unsigned long  *TEixoXY::Realocar(unsigned long *Ponteiro,int Tamanho){
unsigned long *Tmp_Ponteiro=0;

	Tmp_Ponteiro=Ponteiro;
	Tmp_Ponteiro=(unsigned long *)realloc(Tmp_Ponteiro,Tamanho*sizeof(unsigned long));

	Ponteiro=Tmp_Ponteiro;

	return Ponteiro;

}
TPoint **TEixoXY::Realocar_Ponteiro_DuploC(TPoint **Ponteiro,int Tamanho){

TPoint **Tmp_Ponteiro=0;

	   Tmp_Ponteiro=Ponteiro;
	   Tmp_Ponteiro=(TPoint **)realloc(Tmp_Ponteiro,Tamanho*sizeof(TPoint*));
	   for(int i=0;i<Tamanho;i++){
			Tmp_Ponteiro[i]=0;
			Tmp_Ponteiro[i]=(TPoint*)realloc(Tmp_Ponteiro[i],51*sizeof(TPoint));

	   }
	   Ponteiro=Tmp_Ponteiro;
	return Ponteiro;


}

void Rotacao_Vetores_3D_Circle_MP2(float xyz[3],float xe,float ye, float  ze, float Alpha_Beta_Teta[3])
{

	if(EixoXY->RBVisaoYoZ->Checked){
		//Yo
		xyz[0]=xe*(Sin(Alpha_Beta_Teta[0])*Sin(Alpha_Beta_Teta[1])*Cos(Alpha_Beta_Teta[2])+
			Cos(Alpha_Beta_Teta[0])*Sin(Alpha_Beta_Teta[2]))+ye*(-Sin(Alpha_Beta_Teta[0])*Sin(Alpha_Beta_Teta[1])*Sin(Alpha_Beta_Teta[2])+
			Cos(Alpha_Beta_Teta[0])*Cos(Alpha_Beta_Teta[2]))+ze*(-Sin(Alpha_Beta_Teta[0])*Cos(Alpha_Beta_Teta[1]));


		//Zo
		xyz[1]=xe*(-Cos(Alpha_Beta_Teta[0])*Sin(Alpha_Beta_Teta[1])*Cos(Alpha_Beta_Teta[2])+
			Sin(Alpha_Beta_Teta[0])*Sin(Alpha_Beta_Teta[2]))+ye*(Cos(Alpha_Beta_Teta[0])*Sin(Alpha_Beta_Teta[1])*Sin(Alpha_Beta_Teta[2])+
			Sin(Alpha_Beta_Teta[0])*Cos(Alpha_Beta_Teta[2]))+ze*(Cos(Alpha_Beta_Teta[0])*Cos(Alpha_Beta_Teta[1]));

	}





	if(EixoXY->RBVisaoXoY->Checked){
		//Xo
		xyz[0]=xe*(Cos(Alpha_Beta_Teta[1])*Cos(Alpha_Beta_Teta[2])) -
			( ye*Cos( Alpha_Beta_Teta[1])*Sin(Alpha_Beta_Teta[2]))+ze*Sin(Alpha_Beta_Teta[1]);

		//Yo
		xyz[1]=xe*(Sin(Alpha_Beta_Teta[0])*Sin(Alpha_Beta_Teta[1])*Cos(Alpha_Beta_Teta[2])+
			Cos(Alpha_Beta_Teta[0])*Sin(Alpha_Beta_Teta[2]))+ye*(-Sin(Alpha_Beta_Teta[0])*Sin(Alpha_Beta_Teta[1])*Sin(Alpha_Beta_Teta[2])+
			Cos(Alpha_Beta_Teta[0])*Cos(Alpha_Beta_Teta[2]))+ze*(-Sin(Alpha_Beta_Teta[0])*Cos(Alpha_Beta_Teta[1]));


	}




	if(EixoXY->RBVisaoXoZ->Checked){
		//Xo
        xyz[0]=xe*(Cos(Alpha_Beta_Teta[1])*Cos(Alpha_Beta_Teta[2])) -
		( ye*Cos( Alpha_Beta_Teta[1])*Sin(Alpha_Beta_Teta[2]))+ze*Sin(Alpha_Beta_Teta[1]);
		//Zo
		xyz[1]=xe*(-Cos(Alpha_Beta_Teta[0])*Sin(Alpha_Beta_Teta[1])*Cos(Alpha_Beta_Teta[2])+
		Sin(Alpha_Beta_Teta[0])*Sin(Alpha_Beta_Teta[2]))+ye*(Cos(Alpha_Beta_Teta[0])*Sin(Alpha_Beta_Teta[1])*Sin(Alpha_Beta_Teta[2])+
		Sin(Alpha_Beta_Teta[0])*Cos(Alpha_Beta_Teta[2]))+ze*(Cos(Alpha_Beta_Teta[0])*Cos(Alpha_Beta_Teta[1]));


	}




}


void  TEixoXY::Draw_Elipse(TCanvas *Plano,Objetos *Objetos_Atr,TPoint **P_Circle){



float sx1;
float sy1;
float sz1;
float Circle_XYZ[3];





int *TipoElipse=Objetos_Atr[0].Elipse_Atr->GetTipoElipse_Atr();



for(int j=0;j<Objetos_Atr[0].Elipse_Atr->GetContadorCircle_Atr();j++){
        float A=Objetos_Atr[0].Elipse_Atr->GetA_Atr(j);
		float B=Objetos_Atr[0].Elipse_Atr->GetB_Atr(j);
		float AZ=Objetos_Atr[0].Elipse_Atr->GetAZo_Atr(j);
		float BZ=Objetos_Atr[0].Elipse_Atr->GetBZo_Atr(j);



		for (int i=0;i<51;i++){

		switch(TipoElipse[j]){

		case 0:

				sx1=A*Cos(i*((2*M_PI)/50)) + Objetos_Atr[0].Elipse_Atr->GetCX(j);
				sy1=B*Sin(i*((2*M_PI)/50)) + Objetos_Atr[0].Elipse_Atr->GetCY(j);
				sz1=AZ*Cos(i*((2*M_PI)/50))+BZ*Sin((i*((2*M_PI)/50)))+ Objetos_Atr[0].Elipse_Atr->GetCZ(j);

			break;

		case 1:


				sx1=A*Cos((i*((2*M_PI)/50)))+ Objetos_Atr[0].Elipse_Atr->GetCX(j);
				sz1=B*Sin(i*((2*M_PI)/50))+ Objetos_Atr[0].Elipse_Atr->GetCZ(j);
				sy1=AZ*Cos((i*((2*M_PI)/50)))+BZ*Sin((i*((2*M_PI)/50)))+ Objetos_Atr[0].Elipse_Atr->GetCY(j);


			break;

		case 2:

				sy1=A*Cos((i*((2*M_PI)/50)))+ Objetos_Atr[0].Elipse_Atr->GetCY(j);
				sz1=B*Sin(i*((2*M_PI)/50))+ Objetos_Atr[0].Elipse_Atr->GetCZ(j);
				sx1=AZ*Cos((i*((2*M_PI)/50)))+BZ*Sin((i*((2*M_PI)/50)))+ Objetos_Atr[0].Elipse_Atr->GetCX(j);

			break;
		default:

				sx1=0;
				sy1=0;
				sz1=0;
			break;

		}





				  Rotacao_Vetores_3D_Circle_MP2( Circle_XYZ,sx1,sy1,sz1,Objetos_Atr[0].GetAlpha_B_T());




		P_Circle[j][i].x=(int) X(RoundTo(Circle_XYZ[0],0));
		P_Circle[j][i].y= (int)Y(RoundTo(Circle_XYZ[1],0));


		}





	Plano->Pen->Color=(TColor)Objetos_Atr[0].Elipse_Atr->GetColor_Circle_Atr(j);
	Plano->Polyline(P_Circle[j],50);

	}

    FElipse->BtnElipse->Enabled=true;

}



void TEixoXY::Grava_Arquivo(Objetos *Objetos_Atr,char *Nome_Arquivo){

int Contador_Line=Objetos_Atr[0].Lines_Atr->GetContador_Line();
int Contador_Circle=Objetos_Atr[0].Elipse_Atr->GetContadorCircle_Atr();

	ShowMessage("Contador_Line: "+IntToStr(Contador_Line));

	if((Contador_Line>0)||(Contador_Circle>0)){

		ofstream Arquivo_WR(Nome_Arquivo,ios::binary);

		if(!Arquivo_WR){

			ShowMessage("Erro ao Tentar Gravar o Arquivo!!");

		}else{


                Arquivo_WR.write(reinterpret_cast<const char*>(&Contador_Line),sizeof(int));
				Arquivo_WR.write(reinterpret_cast<const char*>(&Contador_Circle),sizeof(int));
				Arquivo_WR.write(reinterpret_cast<const char*>(Objetos_Atr[0].GetAlpha_B_T()),3*sizeof(float));


				if(Contador_Line>0){


					Arquivo_WR.write(reinterpret_cast<const char *>(Objetos_Atr[0].Lines_Atr->GetMAlpha_Atr()),Contador_Line*sizeof(float));
                    Arquivo_WR.write(reinterpret_cast<const char *>(Objetos_Atr[0].Lines_Atr->GetLAlpha_Atr()),Contador_Line*sizeof(float));
					Arquivo_WR.write(reinterpret_cast<const char *>(Objetos_Atr[0].Lines_Atr->GetMVetor_Atr()),Contador_Line*sizeof(float));
					Arquivo_WR.write(reinterpret_cast<const char *>(Objetos_Atr[0].Lines_Atr->GetLVetor_Atr()),Contador_Line*sizeof(float));
					Arquivo_WR.write(reinterpret_cast<const char *>(Objetos_Atr[0].Lines_Atr->GetMZo_Atr()),Contador_Line*sizeof(float));
					Arquivo_WR.write(reinterpret_cast<const char *>(Objetos_Atr[0].Lines_Atr->GetLZo_Atr()),Contador_Line*sizeof(float));
					Arquivo_WR.write(reinterpret_cast<const char *>(Objetos_Atr[0].Lines_Atr->GetCor_Line()),Contador_Line*sizeof(unsigned long));

				}



				if (Contador_Circle>0) {

                    Arquivo_WR.write(reinterpret_cast<const char *>(Objetos_Atr[0].Elipse_Atr->GetA_Atr()),Contador_Circle*sizeof(float));
					Arquivo_WR.write(reinterpret_cast<const char *>(Objetos_Atr[0].Elipse_Atr->GetB_Atr()),Contador_Circle*sizeof(float));
					Arquivo_WR.write(reinterpret_cast<const char *>(Objetos_Atr[0].Elipse_Atr->GetAZo_Atr()),Contador_Circle*sizeof(float));
					Arquivo_WR.write(reinterpret_cast<const char *>(Objetos_Atr[0].Elipse_Atr->GetBZo_Atr()),Contador_Circle*sizeof(float));
					Arquivo_WR.write(reinterpret_cast<const char *>(Objetos_Atr[0].Elipse_Atr->GetCX()),Contador_Circle*sizeof(float));
					Arquivo_WR.write(reinterpret_cast<const char *>(Objetos_Atr[0].Elipse_Atr->GetCY()),Contador_Circle*sizeof(float));
					Arquivo_WR.write(reinterpret_cast<const char *>(Objetos_Atr[0].Elipse_Atr->GetCZ()),Contador_Circle*sizeof(float));
					Arquivo_WR.write(reinterpret_cast<const char *>(Objetos_Atr[0].Elipse_Atr->GetTipoElipse_Atr()),Contador_Circle*sizeof(float));
					Arquivo_WR.write(reinterpret_cast<const char *>(Objetos_Atr[0].Elipse_Atr->GetColor_Circle_Atr()),Contador_Circle*sizeof(float));

				}



				ShowMessage("Gravacao Completa "+AnsiString(Nome_Arquivo));
				Arquivo_WR.close();
			}




	}else
		ShowMessage("Não Há Linhas ou Elipses");





}
void TEixoXY::Ler_Arquivo(Objetos *Objetos_Atr,char * Nome_Arquivo){

int Contador_Line=0;
int Contador_Circle=0;
float *Tmp_MAlpha=0;
float *Tmp_LAlpha=0;
float *Tmp_MVetor=0;
float *Tmp_LVetor=0;
float *Tmp_MZo=0;
float *Tmp_LZo=0;
float Tmp_ABT[3];
unsigned long *TmpCor_Line=0;

float *Tmp_A_Atr=0;
float *Tmp_B_Atr=0;
float *Tmp_AZo_Atr=0;
float *Tmp_BZo_Atr=0;
float *Tmp_CX=0;
float *Tmp_CY=0;
float *Tmp_CZ=0;
unsigned long *Tmp_Color_Circle_Atr=0;
int *Tmp_TipoElipse_Atr=0;
float Tmp_Alpha_B_T[3];



		if(EixoXY->Contador_Circle>0)
			Limpa_Elipses(EixoXY->Canvas,EixoXY->P_Circle,EixoXY->Contador_Circle);
		if(EixoXY->Contador_Line>0)
            Limpa_Lines(EixoXY->Canvas,FullMLK,EixoXY->Contador_Line);



		ifstream Arquivo_RR(Nome_Arquivo,ios::binary|ios::in);

		if(Arquivo_RR){


					Arquivo_RR.read(reinterpret_cast<char*>(&Contador_Line),sizeof(int));

					Arquivo_RR.read(reinterpret_cast<char*>(&Contador_Circle),sizeof(int));

					Arquivo_RR.close();

				if((Contador_Line>0)||(Contador_Circle>0)){

					ifstream Arquivo_RR(Nome_Arquivo,ios::binary|ios::in);

					if(Arquivo_RR){


					Arquivo_RR.read(reinterpret_cast<char*>(&Contador_Line),sizeof(int));

					Arquivo_RR.read(reinterpret_cast<char*>(&Contador_Circle),sizeof(int));
					Arquivo_RR.read(reinterpret_cast<char*>(Tmp_Alpha_B_T),3*sizeof(float));

					EixoXY->Objetos_Atr[0].SetAlpha_B_T(Tmp_Alpha_B_T);
                    for(int i=0;i<3;i++)
							EixoXY->ABT[i]=Tmp_Alpha_B_T[i];


						if(Contador_Line>0){

							Tmp_MAlpha=EixoXY->Realocar(Tmp_MAlpha,Contador_Line);
							Tmp_LAlpha=EixoXY->Realocar(Tmp_LAlpha,Contador_Line);
							Tmp_MVetor=EixoXY->Realocar(Tmp_MVetor,Contador_Line);
							Tmp_LVetor=EixoXY->Realocar(Tmp_LVetor,Contador_Line);
							Tmp_MZo=EixoXY->Realocar(Tmp_MZo,Contador_Line);
							Tmp_LZo=EixoXY->Realocar(Tmp_LZo,Contador_Line);

							TmpCor_Line=EixoXY->Realocar(TmpCor_Line,Contador_Line);

							Sleep(200);



							Arquivo_RR.read(reinterpret_cast<char *>(Tmp_MAlpha),Contador_Line*sizeof(float));
							Arquivo_RR.read(reinterpret_cast<char *>(Tmp_LAlpha),Contador_Line*sizeof(float));
							Arquivo_RR.read(reinterpret_cast<char *>(Tmp_MVetor),Contador_Line*sizeof(float));
							Arquivo_RR.read(reinterpret_cast<char *>(Tmp_LVetor),Contador_Line*sizeof(float));
							Arquivo_RR.read(reinterpret_cast<char *>(Tmp_MZo),Contador_Line*sizeof(float));
							Arquivo_RR.read(reinterpret_cast<char *>(Tmp_LZo),Contador_Line*sizeof(float));

							Arquivo_RR.read(reinterpret_cast<char *>(TmpCor_Line),Contador_Line*sizeof(unsigned long));



							EixoXY->Objetos_Atr[0].Lines_Atr->Alocando_Line(Contador_Line);
							EixoXY->FullMLK=Realocar_Ponteiro_Duplo(EixoXY->FullMLK,Contador_Line);

							for(int i=0;i<Contador_Line;i++){

								EixoXY->Objetos_Atr[0].Lines_Atr->SetContador_Line(Contador_Line);
								EixoXY->Objetos_Atr[0].Lines_Atr->SetMAlpha_Atr(Tmp_MAlpha[i],i);
								EixoXY->Objetos_Atr[0].Lines_Atr->SetLAlpha_Atr(Tmp_LAlpha[i],i);
								EixoXY->Objetos_Atr[0].Lines_Atr->SetMVetor_Atr(Tmp_MVetor[i],i);
								EixoXY->Objetos_Atr[0].Lines_Atr->SetLVetor_Atr(Tmp_LVetor[i],i);
								EixoXY->Objetos_Atr[0].Lines_Atr->SetMZo_Atr(Tmp_MZo[i],i);
								EixoXY->Objetos_Atr[0].Lines_Atr->SetLZo_Atr(Tmp_LZo[i],i);
								EixoXY->Objetos_Atr[0].Lines_Atr->SetCor_Line(TmpCor_Line[i],i);

							}




							EixoXY->Contador_Line=Contador_Line;


						}



						if(Contador_Circle>0){

							Tmp_A_Atr=EixoXY->Realocar(Tmp_A_Atr,Contador_Circle);
							Tmp_B_Atr=EixoXY->Realocar(Tmp_B_Atr,Contador_Circle);
							Tmp_AZo_Atr=EixoXY->Realocar(Tmp_AZo_Atr,Contador_Circle);
							Tmp_BZo_Atr=EixoXY->Realocar(Tmp_BZo_Atr,Contador_Circle);
							Tmp_CX=EixoXY->Realocar(Tmp_CX,Contador_Circle);
							Tmp_CY=EixoXY->Realocar(Tmp_CY,Contador_Circle);
							Tmp_CZ=EixoXY->Realocar(Tmp_CZ,Contador_Circle);
							Tmp_Color_Circle_Atr=EixoXY->Realocar(Tmp_Color_Circle_Atr,Contador_Circle);
							Tmp_TipoElipse_Atr=EixoXY->Realocar(Tmp_TipoElipse_Atr,Contador_Circle);
							EixoXY->P_Circle=EixoXY->Realocar_Ponteiro_DuploC(EixoXY->P_Circle,Contador_Circle);


							EixoXY->Objetos_Atr[0].Elipse_Atr->AlocaElipse_Atr(Contador_Circle);

							Sleep(200);

							Arquivo_RR.read(reinterpret_cast<char *>(Tmp_A_Atr),Contador_Circle*sizeof(float));
							Arquivo_RR.read(reinterpret_cast< char *>(Tmp_B_Atr),Contador_Circle*sizeof(float));
							Arquivo_RR.read(reinterpret_cast< char *>(Tmp_AZo_Atr),Contador_Circle*sizeof(float));
							Arquivo_RR.read(reinterpret_cast< char *>(Tmp_BZo_Atr),Contador_Circle*sizeof(float));
							Arquivo_RR.read(reinterpret_cast< char *>(Tmp_CX),Contador_Circle*sizeof(float));
							Arquivo_RR.read(reinterpret_cast< char *>(Tmp_CY),Contador_Circle*sizeof(float));
							Arquivo_RR.read(reinterpret_cast< char *>(Tmp_CZ),Contador_Circle*sizeof(float));
							Arquivo_RR.read(reinterpret_cast< char *>(Tmp_TipoElipse_Atr),Contador_Circle*sizeof(int));

							Arquivo_RR.read(reinterpret_cast< char *>(Tmp_Color_Circle_Atr),Contador_Circle*sizeof(unsigned long));



							EixoXY->Objetos_Atr[0].Elipse_Atr->SetA_Atr(Tmp_A_Atr);
							EixoXY->Objetos_Atr[0].Elipse_Atr->SetB_Atr(Tmp_B_Atr);
							EixoXY->Objetos_Atr[0].Elipse_Atr->SetAZo_Atr(Tmp_AZo_Atr);
							EixoXY->Objetos_Atr[0].Elipse_Atr->SetBZo_Atr(Tmp_BZo_Atr);
							EixoXY->Objetos_Atr[0].Elipse_Atr->SetCX(Tmp_CX);
							EixoXY->Objetos_Atr[0].Elipse_Atr->SetCY(Tmp_CY);
							EixoXY->Objetos_Atr[0].Elipse_Atr->SetCZ(Tmp_CZ);
							EixoXY->Objetos_Atr[0].Elipse_Atr->SetTipoElipse_Atr(Tmp_TipoElipse_Atr);
							EixoXY->Objetos_Atr[0].Elipse_Atr->SetColor_Circle_Atr(Tmp_Color_Circle_Atr);
							EixoXY->Objetos_Atr[0].Elipse_Atr->SetContadorCircle_Atr(Contador_Circle);

                            EixoXY->Contador_Circle=Contador_Circle;

						}

					}else{
							ShowMessage("Erro de Leitura ..."+AnsiString(Nome_Arquivo));

							Arquivo_RR.close();

						}







					ShowMessage("Leitura Completa...");

					EixoXY->Draw_Elipse(EixoXY->Canvas,EixoXY->Objetos_Atr,EixoXY->P_Circle);


				}

			Arquivo_RR.close();

		}else{

				ShowMessage("Erro de Leitura ...");

				 Arquivo_RR.close();

			}









	Libera_Draw=true;
}
void TEixoXY::Limpa_Elipses(TCanvas *Plano,TPoint **P_Circle,int Contador_Circle){
	Plano->Pen->Color=clWhite;
	for(int i=0;i<Contador_Circle;i++){

		Plano->Polyline(P_Circle[i],50);

	}



}

void Limpa_Lines(TCanvas *Plano,int **FullMLK,int Countador_Line){

TPoint MP[2];

	for (int i = 0; i < Countador_Line; i++) {
		MP[0].x=FullMLK[i][0];
		MP[0].y=FullMLK[i][1];
		MP[1].x=FullMLK[i][2];
		MP[1].y=FullMLK[i][3];

		Plano->Pen->Color=clWhite;
		Plano->Polyline(MP,1);

	}
}


float **Realocar_Ponteiro_Duplo(float **Ponteiro,int Count){


	Ponteiro=(float **)realloc(Ponteiro,Count*sizeof(float*));
	for(int i=0;i<Count;i++){
		Ponteiro[i]=0;
		Ponteiro[i]=(float*)realloc(Ponteiro[i],2*sizeof(float));
	}

   return Ponteiro;
}

int **Realocar_Ponteiro_Duplo(int **Ponteiro,int Count){

	Ponteiro=(int**)realloc(Ponteiro,Count*sizeof(int *));

	for(int i=0;i<Count;i++){
		Ponteiro[i]=0;
		Ponteiro[i]=(int*)realloc(Ponteiro[i],4*sizeof(int));
	}

	return Ponteiro;

}





void TEixoXY::Draw_Lines(TCanvas *Plano,Objetos *Objetos_Atr,int **FullMLK){

TPoint P1[2];
float Mxyz[2];
float Lxyz[2];
float xo;
float yo;
float zo;
float *ABT=0;


ABT=Objetos_Atr[0].GetAlpha_B_T();



try{
	for(int i=0;i<Objetos_Atr[0].Lines_Atr->GetContador_Line();i++){


		if(RBVisaoXoY->Checked){

			xo=Cos(Objetos_Atr[0].Lines_Atr->GetMAlpha_Atr(i))*Objetos_Atr[0].Lines_Atr->GetMVetor_Atr(i);
			yo=Sin(Objetos_Atr[0].Lines_Atr->GetMAlpha_Atr(i))*Objetos_Atr[0].Lines_Atr->GetMVetor_Atr(i);
			zo=Objetos_Atr[0].Lines_Atr->GetMZo_Atr(i);



			Mxyz[0]=(xo)*(Cos(ABT[1])*Cos(ABT[2])) -( yo*Cos( ABT[1])*Sin(ABT[2]))+zo*Sin(ABT[1]);

			Mxyz[1]=(xo)*(Sin(ABT[0])*Sin(ABT[1])*Cos(ABT[2])+
				Cos(ABT[0])*Sin(ABT[2]))+(yo)*(-Sin(ABT[0])*Sin(ABT[1])*Sin(ABT[2])+
				Cos(ABT[0])*Cos(ABT[2]))+zo*(-Sin(ABT[0])*Cos(ABT[1]));


			xo=Cos(Objetos_Atr[0].Lines_Atr->GetLAlpha_Atr(i))*Objetos_Atr[0].Lines_Atr->GetLVetor_Atr(i);
			yo=Sin(Objetos_Atr[0].Lines_Atr->GetLAlpha_Atr(i))*Objetos_Atr[0].Lines_Atr->GetLVetor_Atr(i);
			zo=Objetos_Atr[0].Lines_Atr->GetLZo_Atr(i);


			Lxyz[0]=(xo)*(Cos(ABT[1])*Cos(ABT[2])) - yo*Cos( ABT[1])* Sin(ABT[2])+zo*Sin(ABT[1]);

			Lxyz[1]=(xo)*(Sin(ABT[0])*Sin(ABT[1])*Cos(ABT[2])+
				Cos(ABT[0])*Sin(ABT[2]))+( yo )*(-Sin(ABT[0])*Sin(ABT[1])*Sin(ABT[2])+
				Cos(ABT[0])*Cos(ABT[2]))+zo*(-Sin(ABT[0])*Cos(ABT[1]));

			FullMLK[i][0]=P1[0].x=X(RoundTo(Mxyz[0],0));
			FullMLK[i][1]=P1[0].y=Y(RoundTo(Mxyz[1],0));
			FullMLK[i][2]=P1[1].x=X(RoundTo(Lxyz[0],0));
			FullMLK[i][3]=P1[1].y=Y(RoundTo(Lxyz[1],0));
			Plano->Pen->Color=(TColor)Objetos_Atr[0].Lines_Atr->GetCor_Line(i);

			Plano->Polyline(P1,1);

		}

		if(RBVisaoXoZ->Checked){

			xo=Cos(Objetos_Atr[0].Lines_Atr->GetMAlpha_Atr(i))*Objetos_Atr[0].Lines_Atr->GetMVetor_Atr(i);
			yo=Sin(Objetos_Atr[0].Lines_Atr->GetMAlpha_Atr(i))*Objetos_Atr[0].Lines_Atr->GetMVetor_Atr(i);
			zo=Objetos_Atr[0].Lines_Atr->GetMZo_Atr(i);

			Mxyz[0]=(xo)*(Cos(ABT[1])*Cos(ABT[2])) -( yo*Cos( ABT[1])*Sin(ABT[2]))+zo*Sin(ABT[1]);

			Mxyz[1]=(xo)*(-Cos(ABT[0])*Sin(ABT[1])*Cos(ABT[2])+
					Sin(ABT[0])*Sin(ABT[2]))+(yo)*(Cos(ABT[0])*Sin(ABT[1])*Sin(ABT[2])+
					Sin(ABT[0])*Cos(ABT[2]))+zo*(Cos(ABT[0])*Cos(ABT[1]));

			xo=Cos(Objetos_Atr[0].Lines_Atr->GetLAlpha_Atr(i))*Objetos_Atr[0].Lines_Atr->GetLVetor_Atr(i);
			yo=Sin(Objetos_Atr[0].Lines_Atr->GetLAlpha_Atr(i))*Objetos_Atr[0].Lines_Atr->GetLVetor_Atr(i);
			zo=Objetos_Atr[0].Lines_Atr->GetLZo_Atr(i);

			Lxyz[0]=(xo)*(Cos(ABT[1])*Cos(ABT[2])) - yo*Cos( ABT[1])* Sin(ABT[2])+zo*Sin(ABT[1]);

			Lxyz[1]=(xo  )*(-Cos(ABT[0])*Sin(ABT[1])*Cos(ABT[2])+
				Sin(ABT[0])*Sin(ABT[2]))+(yo)*(Cos(ABT[0])*Sin(ABT[1])*Sin(ABT[2])+
				Sin(ABT[0])*Cos(ABT[2]))+zo*(Cos(ABT[0])*Cos(ABT[1]));

			FullMLK[i][0]=P1[0].x=X(RoundTo(Mxyz[0],0));
			FullMLK[i][1]=P1[0].y=Y(RoundTo(Mxyz[1],0));
			FullMLK[i][2]=P1[1].x=X(RoundTo(Lxyz[0],0));
			FullMLK[i][3]=P1[1].y=Y(RoundTo(Lxyz[1],0));
			Plano->Pen->Color=(TColor)Objetos_Atr[0].Lines_Atr->GetCor_Line(i);

			Plano->Polyline(P1,1);


		}


		if(RBVisaoYoZ->Checked){

			xo=Cos(Objetos_Atr[0].Lines_Atr->GetMAlpha_Atr(i))*Objetos_Atr[0].Lines_Atr->GetMVetor_Atr(i);
			yo=Sin(Objetos_Atr[0].Lines_Atr->GetMAlpha_Atr(i))*Objetos_Atr[0].Lines_Atr->GetMVetor_Atr(i);
			zo=Objetos_Atr[0].Lines_Atr->GetMZo_Atr(i);

			Mxyz[0]=(xo)*(Sin(ABT[0])*Sin(ABT[1])*Cos(ABT[2])+
				Cos(ABT[0])*Sin(ABT[2]))+(yo)*(-Sin(ABT[0])*Sin(ABT[1])*Sin(ABT[2])+
				Cos(ABT[0])*Cos(ABT[2]))+zo*(-Sin(ABT[0])*Cos(ABT[1]));

			Mxyz[1]=(xo)*(-Cos(ABT[0])*Sin(ABT[1])*Cos(ABT[2])+
				Sin(ABT[0])*Sin(ABT[2]))+(yo)*(Cos(ABT[0])*Sin(ABT[1])*Sin(ABT[2])+
				Sin(ABT[0])*Cos(ABT[2]))+zo*(Cos(ABT[0])*Cos(ABT[1]));

			xo=Cos(Objetos_Atr[0].Lines_Atr->GetLAlpha_Atr(i))*Objetos_Atr[0].Lines_Atr->GetLVetor_Atr(i);
			yo=Sin(Objetos_Atr[0].Lines_Atr->GetLAlpha_Atr(i))*Objetos_Atr[0].Lines_Atr->GetLVetor_Atr(i);
			zo=Objetos_Atr[0].Lines_Atr->GetLZo_Atr(i);

			Lxyz[0]=(xo)*(Sin(ABT[0])*Sin(ABT[1])*Cos(ABT[2])+
				Cos(ABT[0])*Sin(ABT[2]))+( yo )*(-Sin(ABT[0])*Sin(ABT[1])*Sin(ABT[2])+
				Cos(ABT[0])*Cos(ABT[2]))+zo*(-Sin(ABT[0])*Cos(ABT[1]));

			Lxyz[1]=(xo  )*(-Cos(ABT[0])*Sin(ABT[1])*Cos(ABT[2])+
				Sin(ABT[0])*Sin(ABT[2]))+(yo)*(Cos(ABT[0])*Sin(ABT[1])*Sin(ABT[2])+
				Sin(ABT[0])*Cos(ABT[2]))+zo*(Cos(ABT[0])*Cos(ABT[1]));

			FullMLK[i][0]=P1[0].x=X(RoundTo(Mxyz[0],0));
			FullMLK[i][1]=P1[0].y=Y(RoundTo(Mxyz[1],0));
			FullMLK[i][2]=P1[1].x=X(RoundTo(Lxyz[0],0));
			FullMLK[i][3]=P1[1].y=Y(RoundTo(Lxyz[1],0));
			Plano->Pen->Color=(TColor)Objetos_Atr[0].Lines_Atr->GetCor_Line(i);

			Plano->Polyline(P1,1);


		}





	}



}catch(Exception &ex){

ShowMessage("Erro ao Imprimir o Grafico");

}




}


int X(int x){
return x+Kx;
}


int Y(int y){
return Ky-y;
}




//---------------------------------------------------------------------------
bool EixoXo(float xo,float yo,float zo,  float *Alphat,float *MVetorXY){

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
		  ShowMessage("Divisão por Zero");


		 }


	  }


		  if ((xo<0)&&(yo>0)) {
		  try{
		xo=-xo;

		Alphat1=M_PI-acos(xo/MVetorXY1);

		xo=-xo;
		  }catch(Exception &ex){
		  ShowMessage("Divisão por Zero");
		  }
		  }

	  if ((xo>0)&&(yo<0)) {
		 try{
		 Alphat1=2*M_PI-acos(xo/MVetorXY1);
		  }catch(Exception &ex){
		  ShowMessage("Divisão por Zero");
		  }
	  }

	  if ((xo>0)&&(yo>0)) {
		try{
		 Alphat1=acos(xo/MVetorXY1);
		 }
		 catch(Exception &ex){
		 ShowMessage("Divisão por Zero");
		 }
	  }

	  }



	*Alphat=Alphat1;





  return 0;

}

float OX(float x){

return (x-KOx);

}

float OY(float y){
  return (int)(KOy-y);
}

//--------------------------------------------------------------------------
//Imprime Os Eixos Cartesianos
void Eixos(TCanvas *Plano,int Kx,int Ky){
TPoint P1[2];

	P1[0].x=0;
	P1[0].y=Ky;
	P1[1].x=Screen->DesktopWidth;
    P1[1].y=Ky;
	Plano->Pen->Color=clBlack;
	Plano->Polyline(P1,1);

	if(EixoXY->RBVisaoXoY->Checked){

		P1[0].x=Kx;
		P1[0].y=0;
		P1[1].x=Kx;
		P1[1].y=Screen->DesktopHeight;
		Plano->Pen->Color=clPurple;
		Plano->Polyline(P1,1);
	}

	if(EixoXY->RBVisaoXoZ->Checked){

		P1[0].x=Kx;
		P1[0].y=0;
		P1[1].x=Kx;
		P1[1].y=Screen->DesktopHeight;
		Plano->Pen->Color=clLime;
		Plano->Polyline(P1,1);
	}

		if(EixoXY->RBVisaoYoZ->Checked){

		P1[0].x=Kx;
		P1[0].y=0;
		P1[1].x=Kx;
		P1[1].y=Screen->DesktopHeight;
		Plano->Pen->Color=clAqua;
		Plano->Polyline(P1,1);
	}




}
//---------------------------------------------------------------------------
void __fastcall TEixoXY::FormMouseMove(TObject *Sender, TShiftState Shift, int X, int Y)

{
TPoint P1;
  float Ang,Mtar;






	if ((Line->Checked)&&(::Move)) {

			EixoXY->Canvas->Pen->Color=clWhite;
			if((MP[1].x>0)||(MP[1].y>0)){

				EixoXY->Canvas->Polyline(MP,1);

			}

			P1=EixoXY->ScreenToClient(Mouse->CursorPos);
			FullLKx[Contador]=MP[1].x=P1.x;
			FullLKy[Contador]=MP[1].y=P1.y;

			EixoXY->Canvas->Pen->Color=clRed;

			EixoXY->Canvas->Polyline(MP,1);


  	}


	DrawCursor->Top=Y+20;
	DrawCursor->Left=X+15;


	DrawCursor->Caption="{ ("+FloatToStr(::OX(X))+") ; ("+FloatToStr(OY(Y))+") }";
}
//---------------------------------------------------------------------------
void __fastcall TEixoXY::FormMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{

TPoint P1;
float Angulo;
float Modulo_Line;




	P1=EixoXY->ScreenToClient(Mouse->CursorPos);

	if ((Button== mbLeft)&&(Line->Checked)){

		Objetos_Atr[0].Lines_Atr->Alocando_Line(Contador_Line+1);
		FullMLK=Realocar_Ponteiro_Duplo(FullMLK,Contador_Line+1);

		Objetos_Atr[0].Lines_Atr->SetCor_Line(Cores->Selected,Contador_Line);
        Contador_Line=Objetos_Atr[0].Lines_Atr->GetContador_Line();


		if(Contar<1){










		}




		if(RBVisaoXoY->Checked){

			Contar++;

			if ((Line->Checked)&&(Contar==1)) {

				MP[0].x=P1.x;
				MP[0].y=P1.y;



				EixoXo((float)::OX(MP[0].x),(float)::OY(MP[0].y),0,&Angulo,&Modulo_Line);

				Objetos_Atr[0].Lines_Atr->SetMAlpha_Atr(Angulo,Contador_Line);
				Objetos_Atr[0].Lines_Atr->SetMVetor_Atr(Modulo_Line,Contador_Line);
				Objetos_Atr[0].Lines_Atr->SetMZo_Atr(EdtZo->Text.ToDouble(),Contador_Line);

				::Move=true;
			}


			if ((Line->Checked)&&(Contar==2)){

				EixoXo((float)::OX(MP[1].x),(float)::OY(MP[1].y),0,&Angulo,&Modulo_Line);
				Objetos_Atr[0].Lines_Atr->SetLAlpha_Atr(Angulo,Contador_Line);
				Objetos_Atr[0].Lines_Atr->SetLVetor_Atr(Modulo_Line,Contador_Line);
                Objetos_Atr[0].Lines_Atr->SetLZo_Atr(EdtZo->Text.ToDouble(),Contador_Line);

				Teste->Caption=FloatToStr(Objetos_Atr[0].Lines_Atr->GetLAlpha_Atr(Contador_Line));



				::Move=false;
				Contar=0;



				Mxyz1=Realocar_Ponteiro_Duplo(Mxyz1,Contador_Line+1);
				Lxyz1=Realocar_Ponteiro_Duplo(Mxyz1,Contador_Line+1);
				Contador_Line++;
				Objetos_Atr[0].Lines_Atr->SetContador_Line(Contador_Line);
				Draw_Lines(EixoXY->Canvas,Objetos_Atr,FullMLK);

			}

		}

		if(RBVisaoXoZ->Checked){

			Contar++;
			float Yo=EdtYo->Text.ToDouble();

				if ((Line->Checked)&&(Contar==1)) {


					MP[0].x=P1.x;
					MP[0].y=P1.y;



					EixoXo((float)::OX(MP[0].x),Yo,0,&Angulo,&Modulo_Line);

					Objetos_Atr[0].Lines_Atr->SetMAlpha_Atr(Angulo,Contador_Line);
					Objetos_Atr[0].Lines_Atr->SetMVetor_Atr(Modulo_Line,Contador_Line);
					Objetos_Atr[0].Lines_Atr->SetMZo_Atr(::OY(MP[0].y),Contador_Line);
					Objetos_Atr[0].Lines_Atr->SetMYo_Atr(Yo,Contador_Line);
					::Move=true;
				}

				if ((Line->Checked)&&(Contar==2)){

					EixoXo((float)::OX(MP[1].x),Yo,0,&Angulo,&Modulo_Line);
					Objetos_Atr[0].Lines_Atr->SetLAlpha_Atr(Angulo,Contador_Line);
					Objetos_Atr[0].Lines_Atr->SetLVetor_Atr(Modulo_Line,Contador_Line);
					Objetos_Atr[0].Lines_Atr->SetLZo_Atr(::OY(MP[1].y),Contador_Line);
					Objetos_Atr[0].Lines_Atr->SetLYo_Atr(Yo,Contador_Line);
					Teste->Caption=FloatToStr(Objetos_Atr[0].Lines_Atr->GetLAlpha_Atr(Contador_Line));



					::Move=false;
					Contar=0;



					Mxyz1=Realocar_Ponteiro_Duplo(Mxyz1,Contador_Line+1);
					Lxyz1=Realocar_Ponteiro_Duplo(Mxyz1,Contador_Line+1);
					Contador_Line++;
					Objetos_Atr[0].Lines_Atr->SetContador_Line(Contador_Line);
					Draw_Lines(EixoXY->Canvas,Objetos_Atr,FullMLK);

				}







		}

		if(RBVisaoYoZ->Checked){

			Contar++;
			float Xo=EdtXo->Text.ToDouble();

				if ((Line->Checked)&&(Contar==1)) {

					MP[0].x=P1.x;
					MP[0].y=P1.y;



					EixoXo(Xo,(float)::OX(MP[0].x),0,&Angulo,&Modulo_Line);

					Objetos_Atr[0].Lines_Atr->SetMAlpha_Atr(Angulo,Contador_Line);
					Objetos_Atr[0].Lines_Atr->SetMVetor_Atr(Modulo_Line,Contador_Line);
					Objetos_Atr[0].Lines_Atr->SetMZo_Atr(::OY(MP[0].y),Contador_Line);
					Objetos_Atr[0].Lines_Atr->SetMXo_Atr(Xo,Contador_Line);
					::Move=true;
				}

				if ((Line->Checked)&&(Contar==2)){

					EixoXo(Xo,(float)::OX(MP[1].x),0,&Angulo,&Modulo_Line);
					Objetos_Atr[0].Lines_Atr->SetLAlpha_Atr(Angulo,Contador_Line);
					Objetos_Atr[0].Lines_Atr->SetLVetor_Atr(Modulo_Line,Contador_Line);
					Objetos_Atr[0].Lines_Atr->SetLZo_Atr(::OY(MP[1].y),Contador_Line);
                    Objetos_Atr[0].Lines_Atr->SetLXo_Atr(Xo,Contador_Line);
					Teste->Caption=FloatToStr(Objetos_Atr[0].Lines_Atr->GetLAlpha_Atr(Contador_Line));



					::Move=false;
					Contar=0;



					Mxyz1=Realocar_Ponteiro_Duplo(Mxyz1,Contador_Line+1);
					Lxyz1=Realocar_Ponteiro_Duplo(Mxyz1,Contador_Line+1);
					Contador_Line++;
					Objetos_Atr[0].Lines_Atr->SetContador_Line(Contador_Line);
					Draw_Lines(EixoXY->Canvas,Objetos_Atr,FullMLK);

				}







		}


		if (Contar>4) {
			 Contar=0;
		}


	}






}
//---------------------------------------------------------------------------



void __fastcall TEixoXY::Tempo_DrawTimer(TObject *Sender)
{
	if(Libera_Draw){
		if(Contador_Line>0){


			Draw_Lines(EixoXY->Canvas,Objetos_Atr,FullMLK);



		}

		if(Contador_Circle>0)
			Draw_Elipse(EixoXY->Canvas,Objetos_Atr,P_Circle);
	}




}
//---------------------------------------------------------------------------

void __fastcall TEixoXY::ButtonEixo_ZoClick(TObject *Sender)
{
	Cancela_Line->Checked=true;
	Limpa_Lines(EixoXY->Canvas,FullMLK,Contador_Line);
	Limpa_Elipses(EixoXY->Canvas,P_Circle,Contador_Circle);

	ABT[2]+=M_PI/80;
	Objetos_Atr[0].SetAlpha_B_T(ABT);

	Draw_Lines(EixoXY->Canvas,Objetos_Atr,FullMLK);
	Draw_Elipse(EixoXY->Canvas,Objetos_Atr,P_Circle);

}
//---------------------------------------------------------------------------

void __fastcall TEixoXY::Tempo_EixoTimer(TObject *Sender)
{


	Eixos(EixoXY->Canvas,Kx,Ky);
}
//---------------------------------------------------------------------------

void __fastcall TEixoXY::LineClick(TObject *Sender)
{
	Limpa_Lines(EixoXY->Canvas,FullMLK,Contador_Line);
	memset(ABT,0,3*sizeof(float));
    Objetos_Atr[0].Lines_Atr->SetAlpha_B_T_Atr(ABT);
}
//---------------------------------------------------------------------------

void __fastcall TEixoXY::RBVisaoXoZClick(TObject *Sender)
{
	Limpa_Lines(EixoXY->Canvas,FullMLK,Contador_Line);
    Limpa_Elipses(EixoXY->Canvas,P_Circle,Contador_Circle);
	Draw_Lines(EixoXY->Canvas,Objetos_Atr,FullMLK);
	EdtXo->Enabled=false;
	EdtZo->Enabled=false;
	EdtYo->Enabled=true;
    EdtXo->Text="0,0";
	EdtYo->Text="0,0";
	EdtZo->Text="0,0";
}
//---------------------------------------------------------------------------

void __fastcall TEixoXY::RBVisaoXoYClick(TObject *Sender)
{

	Limpa_Lines(EixoXY->Canvas,FullMLK,Contador_Line);
    Limpa_Elipses(EixoXY->Canvas,P_Circle,Contador_Circle);
	Draw_Lines(EixoXY->Canvas,Objetos_Atr,FullMLK);
	EdtXo->Enabled=false;
	EdtYo->Enabled=false;
	EdtZo->Enabled=true;
	EdtXo->Text="0,0";
	EdtYo->Text="0,0";
	EdtZo->Text="0,0";
}
//---------------------------------------------------------------------------

void __fastcall TEixoXY::BEixoYoClick(TObject *Sender)
{
	Cancela_Line->Checked=true;
	Limpa_Lines(EixoXY->Canvas,FullMLK,Contador_Line);
	Limpa_Elipses(EixoXY->Canvas,P_Circle,Contador_Circle);
	ABT[1]+=M_PI/80;
	Objetos_Atr[0].SetAlpha_B_T(ABT);
	Draw_Lines(EixoXY->Canvas,Objetos_Atr,FullMLK);
	Draw_Elipse(EixoXY->Canvas,Objetos_Atr,P_Circle);
}
//---------------------------------------------------------------------------

void __fastcall TEixoXY::BEixoXoClick(TObject *Sender)
{
	Cancela_Line->Checked=true;
	Limpa_Lines(EixoXY->Canvas,FullMLK,Contador_Line);
	Limpa_Elipses(EixoXY->Canvas,P_Circle,Contador_Circle);

	ABT[0]+=M_PI/80;
	Objetos_Atr[0].SetAlpha_B_T(ABT);
	Draw_Lines(EixoXY->Canvas,Objetos_Atr,FullMLK);
    Draw_Elipse(EixoXY->Canvas,Objetos_Atr,P_Circle);
}
//---------------------------------------------------------------------------

void __fastcall TEixoXY::RBVisaoYoZClick(TObject *Sender)
{
	Limpa_Lines(EixoXY->Canvas,FullMLK,Contador_Line);
	Limpa_Elipses(EixoXY->Canvas,P_Circle,Contador_Circle);
	Draw_Lines(EixoXY->Canvas,Objetos_Atr,FullMLK);
	EdtYo->Enabled=false;
	EdtZo->Enabled=false;
	EdtXo->Enabled=true;
    EdtXo->Text="0,0";
	EdtYo->Text="0,0";
	EdtZo->Text="0,0";
}
//---------------------------------------------------------------------------

void __fastcall TEixoXY::BAumentarClick(TObject *Sender)
{
	Limpa_Lines(EixoXY->Canvas,FullMLK,Contador_Line);
	for (int i = 0; i < Contador_Line; i++) {
		Objetos_Atr[0].Lines_Atr->SetMVetor_Atr(Objetos_Atr[0].Lines_Atr->GetMVetor_Atr(i)*1.1,i);
		Objetos_Atr[0].Lines_Atr->SetLVetor_Atr(Objetos_Atr[0].Lines_Atr->GetLVetor_Atr(i)*1.1,i);
		Objetos_Atr[0].Lines_Atr->SetMZo_Atr(Objetos_Atr[0].Lines_Atr->GetMZo_Atr(i)*1.1,i);
		Objetos_Atr[0].Lines_Atr->SetLZo_Atr(Objetos_Atr[0].Lines_Atr->GetLZo_Atr(i)*1.1,i);

	}

	for(int i=0;i<Contador_Circle;i++){
		Objetos_Atr[0].Elipse_Atr->SetA_Atr(Objetos_Atr[0].Elipse_Atr->GetA_Atr(i)*1.1,i);
		Objetos_Atr[0].Elipse_Atr->SetB_Atr(Objetos_Atr[0].Elipse_Atr->GetB_Atr(i)*1.1,i);
		Objetos_Atr[0].Elipse_Atr->SetAZo_Atr(Objetos_Atr[0].Elipse_Atr->GetAZo_Atr(i)*1.1,i);
		Objetos_Atr[0].Elipse_Atr->SetBZo_Atr(Objetos_Atr[0].Elipse_Atr->GetBZo_Atr(i)*1.1,i);
		Objetos_Atr[0].Elipse_Atr->SetCX(Objetos_Atr[0].Elipse_Atr->GetCX(i)*1.1,i);
		Objetos_Atr[0].Elipse_Atr->SetCY(Objetos_Atr[0].Elipse_Atr->GetCY(i)*1.1,i);
		Objetos_Atr[0].Elipse_Atr->SetCZ(Objetos_Atr[0].Elipse_Atr->GetCZ(i)*1.1,i);




	}


	Draw_Lines(EixoXY->Canvas,Objetos_Atr,FullMLK);

}
//---------------------------------------------------------------------------

void __fastcall TEixoXY::BDiminuirClick(TObject *Sender)
{


    Limpa_Lines(EixoXY->Canvas,FullMLK,Contador_Line);

	for (int i = 0; i < Contador_Line; i++) {

		Objetos_Atr[0].Lines_Atr->SetMVetor_Atr(Objetos_Atr[0].Lines_Atr->GetMVetor_Atr(i)/1.1,i);
		Objetos_Atr[0].Lines_Atr->SetLVetor_Atr(Objetos_Atr[0].Lines_Atr->GetLVetor_Atr(i)/1.1,i);
		Objetos_Atr[0].Lines_Atr->SetMZo_Atr(Objetos_Atr[0].Lines_Atr->GetMZo_Atr(i)/1.1,i);
		Objetos_Atr[0].Lines_Atr->SetLZo_Atr(Objetos_Atr[0].Lines_Atr->GetLZo_Atr(i)/1.1,i);

	}
    	for(int i=0;i<Contador_Circle;i++){
		Objetos_Atr[0].Elipse_Atr->SetA_Atr(Objetos_Atr[0].Elipse_Atr->GetA_Atr(i)/1.1,i);
		Objetos_Atr[0].Elipse_Atr->SetB_Atr(Objetos_Atr[0].Elipse_Atr->GetB_Atr(i)/1.1,i);
		Objetos_Atr[0].Elipse_Atr->SetAZo_Atr(Objetos_Atr[0].Elipse_Atr->GetAZo_Atr(i)/1.1,i);
		Objetos_Atr[0].Elipse_Atr->SetBZo_Atr(Objetos_Atr[0].Elipse_Atr->GetBZo_Atr(i)/1.1,i);
		Objetos_Atr[0].Elipse_Atr->SetCX(Objetos_Atr[0].Elipse_Atr->GetCX(i)/1.1,i);
		Objetos_Atr[0].Elipse_Atr->SetCY(Objetos_Atr[0].Elipse_Atr->GetCY(i)/1.1,i);
		Objetos_Atr[0].Elipse_Atr->SetCZ(Objetos_Atr[0].Elipse_Atr->GetCZ(i)/1.1,i);




	}

	Draw_Lines(EixoXY->Canvas,Objetos_Atr,FullMLK);

}
//---------------------------------------------------------------------------

void __fastcall TEixoXY::ConstruirLinha1Click(TObject *Sender)
{
	ConstrucaoLines->Visible=true;
}
//---------------------------------------------------------------------------

void __fastcall TEixoXY::BtnSalvarClick(TObject *Sender)
{
   UnicodeString Nome_Arquivo;
   char  N_Arquivo[500];

	if(DlgSalvar->Execute()){

		Nome_Arquivo=DlgSalvar->FileName;

		for(int i=0;i<Nome_Arquivo.Length();i++){
			N_Arquivo[i]=(char)Nome_Arquivo[i+1];

		}

		N_Arquivo[ Nome_Arquivo.Length()]='\0';

	}


   Grava_Arquivo(Objetos_Atr,N_Arquivo);

}
//---------------------------------------------------------------------------

void __fastcall TEixoXY::PElipseClick(TObject *Sender)
{

	FElipse->Visible=true;

}
//---------------------------------------------------------------------------

void __fastcall TEixoXY::BtnAbrirClick(TObject *Sender)
{
AnsiString Nome_Arquivo;

	Libera_Draw=false;

	Cancela_Line->Checked=true;

char  N_Arquivo[500];

	if(DlgAbrir->Execute()){

		Nome_Arquivo=DlgAbrir->FileName;



	}


   Ler_Arquivo(Objetos_Atr,Nome_Arquivo.c_str());
}
//---------------------------------------------------------------------------



