//---------------------------------------------------------------------------

#pragma hdrstop

#include "Arquivo.h"

#include <fstream>
#include <System.SysUtils.hpp>

#include <System.Math.hpp>
#include <malloc.h>
#include <stdlib>
#include <string>
#include <windows.h>

#define HeapAlloc(x) HeapAlloc(GetProcessHeap(),0,(x))
#define HeapRealloc(x,y) HeapReAlloc(GetProcessHeap(),0,x,y)
using std::strcpy;

using  Name_Arquivos::Objetos;
using Name_Arquivos::Arquivo;
using Name_Arquivos::Atributos;
using Name_Arquivos::Dados_Atributos;
using Name_Arquivos::Elipse;
using Name_Arquivos::Line;



float  * Realocar(float *Ponteiro,int Tamanho){

bool Testa=true;
float *Tmp_Ponteiro=Ponteiro;

	do{

		Tmp_Ponteiro=(float*) realloc(Tmp_Ponteiro,Tamanho*sizeof(float));

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

DWORD  * Realocar(DWORD *Ponteiro,int Tamanho){

bool Testa=true;
DWORD *Tmp_Ponteiro=Ponteiro;

	do{

		Tmp_Ponteiro=(DWORD*) realloc(Tmp_Ponteiro,Tamanho*sizeof(DWORD));

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

int  * Realocar_Int(int *Ponteiro,int Tamanho){


bool Testa=true;
int *Tmp_Ponteiro=Ponteiro;

	do{

		Tmp_Ponteiro=(int*) realloc(Tmp_Ponteiro,Tamanho*sizeof(int));

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




float **Realocar_PonteiroCenter(float **Ponteiro,int Tamanho){

float **Tmp_Ponteiro=0;
bool Testa=true;
	Tmp_Ponteiro=Ponteiro;

	do{

		Tmp_Ponteiro=(float **)realloc(Tmp_Ponteiro,Tamanho*sizeof(float *));

		for(int i=0;i<Tamanho;i++){

			Tmp_Ponteiro[i]=0;
			Tmp_Ponteiro[i]=(float*)realloc(Tmp_Ponteiro[i],3*sizeof(float));

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


	return  Ponteiro;

}


//---------------------------------------------------------------------------
#pragma package(smart_init)
//Class Line
//----------------------------------------------------------------------------

Line::Line(){

	Contador_Line=0;
	MAlpha_Atr=0;
	LAlpha_Atr=0;
	MVetor_Atr=0;
	LVetor_Atr=0;
	MXo_Atr=0;
	LXo_Atr=0;
	MYo_Atr=0;
	LYo_Atr=0;
	MZo_Atr=0;
	LZo_Atr=0;
	Cor_Line=0;
	for(int i=0;i<3;i++)
		Alpha_B_T[i]=0;

	Tmp_MA=0;
	Tmp_LA=0;
	Tmp_MV=0;
	Tmp_LV=0;
	Tmp_MX=0;
	Tmp_LX=0;
	Tmp_MY=0;
	Tmp_LY=0;
	Tmp_MZ=0;
	Tmp_LZ=0;
	Tmp_CL=0;

}

//------------------------------------------------------------------------------

float  *Line::Realocar(float *Ponteiro,int Tamanho){

   Ponteiro=(float*) realloc(Ponteiro,Tamanho*sizeof(float));
   return Ponteiro;

}

int *Line::Realocar_Int(int *Ponteiro,int Count){

	Ponteiro=(int *)realloc(Ponteiro,Count *sizeof(int));

	return Ponteiro;
}
unsigned long * Line::Realocar(unsigned long *Ponteiro,int Count){

	Ponteiro=(unsigned long *)realloc(Ponteiro,Count *sizeof(unsigned long));

	return Ponteiro;
}

void Line::Alocando_Line(int Count){

bool Testa=true;
int Contador=0;

	do{

		if(Count > 0){

			Tmp_MA=Realocar(Tmp_MA,Count);
			Tmp_LA=Realocar(Tmp_LA,Count);
			Tmp_MV=Realocar(Tmp_MV,Count);
			Tmp_LV=Realocar(Tmp_LV,Count);
			Tmp_MX=Realocar(Tmp_MX,Count);
			Tmp_LX=Realocar(Tmp_LX,Count);
			Tmp_MY=Realocar(Tmp_MY,Count);
			Tmp_LY=Realocar(Tmp_LY,Count);
			Tmp_MZ=Realocar(Tmp_MZ,Count);
			Tmp_LZ=Realocar(Tmp_LZ,Count);
			Tmp_CL=Realocar(Tmp_CL,Count);

			if((Tmp_MA!=NULL)&&(Tmp_LA!=NULL)&&(Tmp_MV!=NULL)&&(Tmp_LV!=NULL)&&(Tmp_MX!=NULL)&&
			(Tmp_LX!=NULL)&&(Tmp_MY!=NULL)&&(Tmp_LY!=NULL)&&(Tmp_MZ!=NULL)&&(Tmp_LZ!=NULL)){

				MAlpha_Atr=Tmp_MA;
				LAlpha_Atr=Tmp_LA;
				MVetor_Atr=Tmp_MV;
				LVetor_Atr=Tmp_LV;
				MXo_Atr=Tmp_MX;
				LXo_Atr=Tmp_LX;
				MYo_Atr=Tmp_MY;
				LYo_Atr=Tmp_LY;
				MZo_Atr=Tmp_MZ;
				LZo_Atr=Tmp_LZ;
				Cor_Line=Tmp_CL;

				Testa=false;
			}else{
					Tmp_MA=0;
					Tmp_LA=0;
					Tmp_MV=0;
					Tmp_LV=0;
					Tmp_MX=0;
					Tmp_LX=0;
					Tmp_MY=0;
					Tmp_LY=0;
					Tmp_MZ=0;
					Tmp_LZ=0;

					Tmp_MA=MAlpha_Atr;
					Tmp_LA=LAlpha_Atr;
					Tmp_MV=MVetor_Atr;
					Tmp_LV=LVetor_Atr;
					Tmp_MX=MXo_Atr;
					Tmp_LX=LXo_Atr;
					Tmp_MY=MYo_Atr;
					Tmp_LY=LYo_Atr;
					Tmp_MZ=MZo_Atr;
					Tmp_LZ=LZo_Atr;
					Tmp_CL=Cor_Line;

					Contador++;
					Testa=true;

				}


		}

	}while((Testa)&&(Contador<100));


}

void Line::SetMAlpha_Atr(float Valor,int Index){

	MAlpha_Atr[Index]=Valor;


}

void Line::SetLAlpha_Atr(float Valor,int Index){

	LAlpha_Atr[Index]=Valor;

}

void Line::SetMVetor_Atr(float Valor,int Index){

	MVetor_Atr[Index]=Valor;

}

void Line::SetLVetor_Atr(float Valor,int Index){


	LVetor_Atr[Index]=Valor;


}

void Line::SetMXo_Atr(float Valor,int Index){

	MXo_Atr[Index]=Valor;


}
void Line::SetLXo_Atr(float Valor,int Index){

	LXo_Atr[Index]=Valor;


}


void Line::SetMYo_Atr(float Valor,int Index){


	MYo_Atr[Index]=Valor;


}


void Line::SetLYo_Atr(float Valor,int Index){

	LYo_Atr[Index]=Valor;

}


void Line::SetContador_Line(int Valor){

	Contador_Line=Valor;

}

void Line::SetMZo_Atr(float Valor,int Index){

	MZo_Atr[Index]=Valor;

}


void Line::SetLZo_Atr(float Valor,int Index){

	LZo_Atr[Index]=Valor;


}

void Line::SetAlpha_B_T_Atr(float *ABT){
for(int i=0;i<3;i++)
	Alpha_B_T[i]=ABT[i];

}

void Line::SetCor_Line(unsigned long Valor,int Index){

	Cor_Line[Index]=Valor;

}



float *Line::GetAlpha_B_T(float *ABT){

	for(int i=0;i<3;i++)
		ABT[i]=Alpha_B_T[i];

		return  ABT;

}

float *Line::GetAlpha_B_T(){

	return Alpha_B_T;
}
//------------------------------------------------------------------------------


float Line::GetMAlpha_Atr(int Index){

	return MAlpha_Atr[Index];


}
float *Line::GetMAlpha_Atr(){

    return MAlpha_Atr;
}

float Line::GetLAlpha_Atr(int Index){

	return LAlpha_Atr[Index];

}
float *Line::GetLAlpha_Atr(){

return LAlpha_Atr;
}

float Line::GetMVetor_Atr(int Index){

	return MVetor_Atr[Index];

}
float *Line::GetMVetor_Atr(){

return MVetor_Atr;
}


float Line::GetLVetor_Atr(int Index){

	return LVetor_Atr[Index];

}
float *Line::GetLVetor_Atr(){

	return LVetor_Atr;

}

float Line::GetMZo_Atr(int Index){

return MZo_Atr[Index];

}
float *Line::GetMZo_Atr(){

return MZo_Atr;

}

float Line::GetLZo_Atr(int Index){


	return LZo_Atr[Index];

}
float *Line::GetLZo_Atr(){


	return LZo_Atr;

}

unsigned long Line::GetCor_Line(int Index){

	return Cor_Line[Index];

}

unsigned long *Line::GetCor_Line(){

	return Cor_Line;

}

float *Line::GetMAlpha_AtrPtr(){

	return MAlpha_Atr;

}

int Line::GetContador_Line(){

    return Contador_Line;

}

//------------------------------------------------------------------------------

//Class Objetos-----------------------------------------------------


Objetos::Objetos(){

	Elipse_Atr=new Elipse();
	Lines_Atr=new Line();

	Count_Line=0;
	Mxy=NULL;
	Lxy=NULL;
	Point=NULL;

	List=new TList();
	P2=new TPoint[2];
	Chave_Point=true;
	Visao_XY=true;
	Visao_XZ=false;
	for(int i=0;i<3;i++)
        Alpha_B_T[i]=0;

}

void Objetos::Draw_Parametros(Objetos *arquivo){

float **Mxyz1;
float **Lxyz1;

float MZY[2];
float LZY[2];
this->Count_Line=arquivo->dados_Objeto.Contador_Atr;


this->Count_Line=arquivo->Count_Line;

if(Count_Line>0){
	this->Mxy=Aloca_P1(this->Count_Line);
	this->Lxy= Aloca_P1(this->Count_Line);
	Mxyz1=Aloca_P1(this->Count_Line);
	Lxyz1= Aloca_P1(this->Count_Line);
	Point=Aloca_TPoint(this->Count_Line);

	}



int i;



try{

  if(Count_Line>0){

	IteradorInteiro=InteiroVetor.begin();
	IteradorTPoint=VectorP2.end();
	for(i=0;i<this->Count_Line;i++){


		Mxyz1[i][0]=(arquivo->dados_Objeto.MMVetorG_Atr[i]*Cos(arquivo->dados_Objeto.MAlpha_Atr[i]))*(Cos(arquivo->dados_Objeto.Alpha_Beta_Teta_Atr[1])*Cos(arquivo->dados_Objeto.Alpha_Beta_Teta_Atr[2])) -
		( (arquivo->dados_Objeto.MMVetorG_Atr[i]*Sin(arquivo->dados_Objeto.MAlpha_Atr[i]))*Cos( arquivo->dados_Objeto.Alpha_Beta_Teta_Atr[1])*Sin(arquivo->dados_Objeto.Alpha_Beta_Teta_Atr[2]))+
		arquivo->dados_Objeto.MZo_Atr[i]*Sin(arquivo->dados_Objeto.Alpha_Beta_Teta_Atr[1]);

		Mxyz1[i][1]=(arquivo->dados_Objeto.MMVetorG_Atr[i]*Cos(arquivo->dados_Objeto.MAlpha_Atr[i]))*(Sin(arquivo->dados_Objeto.Alpha_Beta_Teta_Atr[0])*
		Sin(arquivo->dados_Objeto.Alpha_Beta_Teta_Atr[1])*Cos(arquivo->dados_Objeto.Alpha_Beta_Teta_Atr[2])+
		Cos(arquivo->dados_Objeto.Alpha_Beta_Teta_Atr[0])*Sin(arquivo->dados_Objeto.Alpha_Beta_Teta_Atr[2]))+(arquivo->dados_Objeto.MMVetorG_Atr[i]*
		Sin(arquivo->dados_Objeto.MAlpha_Atr[i]))*(-Sin(arquivo->dados_Objeto.Alpha_Beta_Teta_Atr[0])*Sin(arquivo->dados_Objeto.Alpha_Beta_Teta_Atr[1])*
		Sin(arquivo->dados_Objeto.Alpha_Beta_Teta_Atr[2])+
		Cos(arquivo->dados_Objeto.Alpha_Beta_Teta_Atr[0])*Cos(arquivo->dados_Objeto.Alpha_Beta_Teta_Atr[2]))+arquivo->dados_Objeto.MZo_Atr[i]*
		(-Sin(arquivo->dados_Objeto.Alpha_Beta_Teta_Atr[0])*Cos(arquivo->dados_Objeto.Alpha_Beta_Teta_Atr[1]));


		Lxyz1[i][0]=(arquivo->dados_Objeto.LMVetorG_Atr[i]*Cos(arquivo->dados_Objeto.LAlpha_Atr[i]))*(Cos(arquivo->dados_Objeto.Alpha_Beta_Teta_Atr[1])*
		Cos(arquivo->dados_Objeto.Alpha_Beta_Teta_Atr[2])) -
		( (arquivo->dados_Objeto.LMVetorG_Atr[i]*Sin(arquivo->dados_Objeto.LAlpha_Atr[i]))*Cos( arquivo->dados_Objeto.Alpha_Beta_Teta_Atr[1])*
		Sin(arquivo->dados_Objeto.Alpha_Beta_Teta_Atr[2]))+arquivo->dados_Objeto.LZo_Atr[i]*Sin(arquivo->dados_Objeto.Alpha_Beta_Teta_Atr[1]);

		Lxyz1[i][1]=(arquivo->dados_Objeto.LMVetorG_Atr[i]*Cos(arquivo->dados_Objeto.LAlpha_Atr[i]))*(Sin(arquivo->dados_Objeto.Alpha_Beta_Teta_Atr[0])*
		Sin(arquivo->dados_Objeto.Alpha_Beta_Teta_Atr[1])*Cos(arquivo->dados_Objeto.Alpha_Beta_Teta_Atr[2])+
		Cos(arquivo->dados_Objeto.Alpha_Beta_Teta_Atr[0])*Sin(arquivo->dados_Objeto.Alpha_Beta_Teta_Atr[2]))+
		( arquivo->dados_Objeto.LMVetorG_Atr[i]*Sin(arquivo->dados_Objeto.LAlpha_Atr[i]) )*(-Sin(arquivo->dados_Objeto.Alpha_Beta_Teta_Atr[0])*
		Sin(arquivo->dados_Objeto.Alpha_Beta_Teta_Atr[1])*Sin(arquivo->dados_Objeto.Alpha_Beta_Teta_Atr[2])+
		Cos(arquivo->dados_Objeto.Alpha_Beta_Teta_Atr[0])*Cos(arquivo->dados_Objeto.Alpha_Beta_Teta_Atr[2]))+arquivo->dados_Objeto.LZo_Atr[i]*
		(-Sin(arquivo->dados_Objeto.Alpha_Beta_Teta_Atr[0])*Cos(arquivo->dados_Objeto.Alpha_Beta_Teta_Atr[1]));


	  Point[i][0].x=this->Mxy[i][0]= RoundTo(X(Mxyz1[i][0]),0);
	  Point[i][0].y=this->Mxy[i][1]= RoundTo(Y(Mxyz1[i][1]),0);
	  Point[i][1].x=this->Lxy[i][0]= RoundTo(X(Lxyz1[i][0]),0);
	  Point[i][1].y=this->Lxy[i][1]= RoundTo(Y(Lxyz1[i][1]),0);

	  P2[0].x=X(Mxyz1[i][0]);
	  P2[0].y=Y(Mxyz1[i][1]);
	  P2[1].x=X(Lxyz1[i][0]);
	  P2[1].y=Y(Lxyz1[i][1]);




	  IteradorInteiro=InteiroVetor.insert(IteradorInteiro,i);
	  IteradorTPoint=VectorP2.insert(IteradorTPoint,Point[i]);


	}
  }
}

catch(Exception &ex){


}

}


float ** Objetos::Aloca_P1(int Count){

float **p1;
if(Count>0){
p1=NULL;
p1=(float **)realloc(p1,Count*sizeof(float*));

for(int i=0;i<Count;i++){

	p1[i]=NULL;
	p1[i]=(float *)realloc(p1[i],2*sizeof(float));

 }}
 return p1;
}

TPoint ** Objetos::Aloca_TPoint(int Count){

TPoint **p1;
p1=NULL;
p1=(TPoint **)realloc(p1,Count*sizeof(TPoint*));

for(int i=0;i<Count;i++){

	p1[i]=NULL;
	p1[i]=(TPoint *)realloc(p1[i],2*sizeof(TPoint));

}
 return p1;
}






float Objetos::X(float x){
	return x+Kx_Atr;
}

float Objetos::Y(float y){
	return Ky_Atr-y;
}

void Objetos::SetAlpha_B_T(float ABT,int Index){

Alpha_B_T[Index]=ABT;

}
void Objetos::SetAlpha_B_T(float ABT[3]){

	for(int i=0;i<3;i++)
		Alpha_B_T[i]=ABT[i];

}
float * Objetos::GetAlpha_B_T(){

	return Alpha_B_T;

}
float Objetos::GetAlpha_B_T(int Index){

	return Alpha_B_T[Index];

}



Arquivo::Arquivo(){



}

UnicodeString Atributos::Teste(){
	return "Classe Atributos";

}

UnicodeString Objetos::Teste(){

return "Classe Objetos";
}

//-----------------------------------------------------------------------------
float ***Objetos::Draw_Elipse(){

float ***Point_Circle;
int ContadorCircle_Atr=Elipse_Atr->GetContadorCircle_Atr();

if (Chave_Point) {

	Point_Circle=(float ***)malloc(ContadorCircle_Atr*sizeof(float**));
	for(int i=0;i<ContadorCircle_Atr;i++){
		Point_Circle[i]=(float **)malloc(51*sizeof(float*));
	for(int j=0;j<51;j++)
		Point_Circle[i][j]=(float *)malloc(2*sizeof(float));
	}

	Chave_Point=false ;

}

TPoint **Point_C;

	Point_C=(TPoint **)malloc(ContadorCircle_Atr+1*sizeof(TPoint*));
	for(int j=0;j<ContadorCircle_Atr+1;j++)
		Point_C[j]=(TPoint*)malloc(51*sizeof(TPoint));

float sx1=300;
float sy1=150;
float sz1;
float x1;
float y1;
float Circle_XYZ[3];
float  Ang;
float  MVetor;
float Cnd=0;
float AngVar=((2*M_PI)/50);

float *AZ=Elipse_Atr->GetAZo_Atr();
float *BZ=Elipse_Atr->GetBZo_Atr();
float **Center=Elipse_Atr->GetCenter_Atr();
int *TipoElipse=Elipse_Atr->GetTipoElipse_Atr();
float *Alpha_Beta_Teta_Circle;
float *A=this->Elipse_Atr->GetA_Atr();
float *B=this->Elipse_Atr->GetB_Atr();


Alpha_Beta_Teta_Circle=Elipse_Atr->GetAlpha_Beta_Teta_Atr();



for(int j=0;j<ContadorCircle_Atr;j++){

		for (int i=0;i<51;i++){



		if(TipoElipse[j]==0){
		sx1= A[j]*Cos((i*((2*M_PI)/50)))+Center[j][0];
		sy1=B[j]*Sin(i*((2*M_PI)/50))+Center[j][1];
		sz1=AZ[j]*Cos((i*((2*M_PI)/50)))+BZ[j]*Sin((i*((2*M_PI)/50)))+Center[j][2];

		}

		if(TipoElipse[j]==1){

			sx1=A[j]*Cos((i*((2*M_PI)/50)))+Center[j][0];
			sz1=B[j]*Sin(i*((2*M_PI)/50))+Center[j][1];
			sy1=AZ[j]*Cos((i*((2*M_PI)/50)))+BZ[j]*Sin((i*((2*M_PI)/50)))+Center[j][2];

		}





				  Rotacao_Vetores_3D_Circle_MP2( Circle_XYZ,sx1,sy1,sz1,Alpha_Beta_Teta_Circle);




		Point_Circle[j][i][0]= X(Circle_XYZ[0]);
		Point_Circle[j][i][1]= Y(Circle_XYZ[1]);
		}







	}


	return Point_Circle;

}

void Objetos::Rotacao_Vetores_3D_Circle_MP2(float xyz[3],float xe,float ye, float  ze, float Alpha_Beta_Teta[3])
{
  float AX;
  float AY;
  float AZ;
  float T1;
  float T2;
  float T3;
  if(0){
  xyz[0]= Cos( Alpha_Beta_Teta[1]+M_PI/2)*Cos( Alpha_Beta_Teta[2])*xe - Cos(Alpha_Beta_Teta[1]+M_PI/2)*Sin(Alpha_Beta_Teta[2])*ye + Sin(Alpha_Beta_Teta[1]+M_PI/2)*ze;
  T1=Cos( Alpha_Beta_Teta[1]+M_PI/2)*Cos( Alpha_Beta_Teta[2])*xe;
  T2= - Cos(Alpha_Beta_Teta[1]+M_PI/2)*Sin(Alpha_Beta_Teta[2])*ye;
  T3=  Sin(Alpha_Beta_Teta[1]+M_PI/2)*ze;

  AX= RoundTo( (Sin(Alpha_Beta_Teta[0])*Sin(Alpha_Beta_Teta[1]+M_PI/2)*Cos(Alpha_Beta_Teta[2])+ Cos(Alpha_Beta_Teta[0])*Sin(Alpha_Beta_Teta[2])),-8);
  AY= RoundTo((-Sin(Alpha_Beta_Teta[0])*Sin(Alpha_Beta_Teta[1]+M_PI/2)*Sin(Alpha_Beta_Teta[2])+Cos(Alpha_Beta_Teta[0])*Cos(Alpha_Beta_Teta[2])),-8);
  AZ= RoundTo(-(Sin(Alpha_Beta_Teta[0])*Cos(Alpha_Beta_Teta[1]+M_PI/2)),-8);

  xyz[1]=AX*xe+AY*ye+AZ*ze;






  xyz[2]=(-Cos(Alpha_Beta_Teta[0])*Sin(Alpha_Beta_Teta[1]+M_PI/2)*Cos(Alpha_Beta_Teta[2])+Sin(Alpha_Beta_Teta[0])*Sin(Alpha_Beta_Teta[2]))*xe
  +(Cos(Alpha_Beta_Teta[0])*Sin(Alpha_Beta_Teta[1]+M_PI/2)*Sin(Alpha_Beta_Teta[2])+Sin(Alpha_Beta_Teta[0])*Cos(Alpha_Beta_Teta[2]))*ye
  +Cos(Alpha_Beta_Teta[0])*Cos(Alpha_Beta_Teta[1]+M_PI/2)*ze;

  }


   if(1){

	xyz[0]=xe*(Cos(Alpha_Beta_Teta[1])*Cos(Alpha_Beta_Teta[2])) -
	( ye*Cos( Alpha_Beta_Teta[1])*Sin(Alpha_Beta_Teta[2]))+ze*Sin(Alpha_Beta_Teta[1]);


		xyz[1]=xe*(Sin(Alpha_Beta_Teta[0])*Sin(Alpha_Beta_Teta[1])*Cos(Alpha_Beta_Teta[2])+
		Cos(Alpha_Beta_Teta[0])*Sin(Alpha_Beta_Teta[2]))+ye*(-Sin(Alpha_Beta_Teta[0])*Sin(Alpha_Beta_Teta[1])*Sin(Alpha_Beta_Teta[2])+
		Cos(Alpha_Beta_Teta[0])*Cos(Alpha_Beta_Teta[2]))+ze*(-Sin(Alpha_Beta_Teta[0])*Cos(Alpha_Beta_Teta[1]));






		xyz[2]=xe*(-Cos(Alpha_Beta_Teta[0])*Sin(Alpha_Beta_Teta[1])*Cos(Alpha_Beta_Teta[2])+
		Sin(Alpha_Beta_Teta[0])*Sin(Alpha_Beta_Teta[2]))+ye*(Cos(Alpha_Beta_Teta[0])*Sin(Alpha_Beta_Teta[1])*Sin(Alpha_Beta_Teta[2])+
		Sin(Alpha_Beta_Teta[0])*Cos(Alpha_Beta_Teta[2]))+ze*(Cos(Alpha_Beta_Teta[0])*Cos(Alpha_Beta_Teta[1]));


   }

}

void Objetos::SetVisao_XY(bool f){

	Visao_XY=f;

}
//-------------------------------------------------------------------------------------------------------

bool Objetos::GetVisao_XY(){

	return Visao_XY;

}
//-------------------------------------------------------------------------------------------------------

void Objetos::SetVisao_XZ(bool f){

	Visao_XZ=f;

}

//---------------------------------------------------------------------------------------------------------

bool Objetos::GetVisao_XZ(){


	return Visao_XZ;

}


void Arquivo::Abrir_Arquivo(char *Nome_Arquivo,struct Dados_Atributos *dados){

int tamanho_Line=0;
int tamanho_Circle=0;
	ifstream *Arquivo_RR=new ifstream(Nome_Arquivo,ios::in|ios::binary);
	if(!Arquivo_RR){

	}else{
	 Arquivo_RR->read(reinterpret_cast< char *>(&tamanho_Line),sizeof(int));
	 Arquivo_RR->read(reinterpret_cast< char *>(&tamanho_Circle),sizeof(int));
	 Arquivo_RR->close();


	Sleep(200);
		Arquivo_RR=new ifstream(Nome_Arquivo,ios::in|ios::binary);
	if(!Arquivo_RR){

		}else{

			*dados=AlocandoAtributos(tamanho_Line,tamanho_Circle,*dados);
			Arquivo_RR->read(reinterpret_cast< char *>(&dados->Contador_Atr),sizeof(int));
			Arquivo_RR->read(reinterpret_cast< char *>(&dados->ContadorCircle_Atr),sizeof(int));

			if(dados->Contador_Atr>0){
				Arquivo_RR->read(reinterpret_cast< char *>(dados->MXo_Atr),(dados->Contador_Atr)*sizeof(float));
				Arquivo_RR->read(reinterpret_cast< char *>(dados->LXo_Atr),(dados->Contador_Atr)*sizeof(float));
				Arquivo_RR->read(reinterpret_cast< char *>(dados->MYo_Atr),(dados->Contador_Atr)*sizeof(int));
				Arquivo_RR->read(reinterpret_cast< char *>(dados->LYo_Atr),(dados->Contador_Atr)*sizeof(int));
				Arquivo_RR->read(reinterpret_cast< char *>(dados->MZo_Atr),(dados->Contador_Atr)*sizeof(float));
				Arquivo_RR->read(reinterpret_cast< char *>(dados->LZo_Atr),(dados->Contador_Atr)*sizeof(float));

				Arquivo_RR->read(reinterpret_cast< char *>(dados->Color_Atr),(dados->Contador_Atr)*sizeof(DWORD));


				Arquivo_RR->read(reinterpret_cast< char *>(dados->MAlpha_Atr),(dados->Contador_Atr)*sizeof(float));
				Arquivo_RR->read(reinterpret_cast< char *>(dados->LAlpha_Atr),(dados->Contador_Atr)*sizeof(float));
				Arquivo_RR->read(reinterpret_cast< char *>(dados->MMVetorG_Atr),(dados->Contador_Atr)*sizeof(float));
				Arquivo_RR->read(reinterpret_cast< char *>(dados->LMVetorG_Atr),(dados->Contador_Atr)*sizeof(float));
				Arquivo_RR->read(reinterpret_cast< char *>(dados->Alpha_Beta_Teta_Atr),sizeof(dados->Alpha_Beta_Teta_Atr));

			}



			if(dados->ContadorCircle_Atr>0){


				for(int i=0;i< dados->ContadorCircle_Atr;i++)
				Arquivo_RR->read(reinterpret_cast< char *>(dados->Center_Atr[i]),3*sizeof(float));

				Arquivo_RR->read(reinterpret_cast< char *>(dados->AZo_Atr),(dados->ContadorCircle_Atr)*sizeof(float));
				Arquivo_RR->read(reinterpret_cast< char *>(dados->BZo_Atr),(dados->ContadorCircle_Atr)*sizeof(float));
				Arquivo_RR->read(reinterpret_cast< char *>(dados->A_Atr),(dados->ContadorCircle_Atr)*sizeof(float));
				Arquivo_RR->read(reinterpret_cast< char *>(dados->B_Atr),(dados->ContadorCircle_Atr)*sizeof(float));


				Arquivo_RR->read(reinterpret_cast< char *>(dados->Color_Circle_Atr),dados->ContadorCircle_Atr*sizeof(DWORD));

				Arquivo_RR->read(reinterpret_cast< char *>(dados->Alpha_Beta_Teta_Circle_Atr),sizeof(dados->Alpha_Beta_Teta_Circle_Atr));
			}


			Arquivo_RR->close();

		}






	}






}

void Arquivo::Salvar_Arquivo(char *nome_Arquivo,struct Dados_Atributos *dados){

int tamanho_Line=dados->Contador_Atr;
int tamanho_Circle=dados->ContadorCircle_Atr;

ofstream *arquivo_WR=new ofstream(nome_Arquivo,ios::out|ios::binary);

	if(arquivo_WR){

        arquivo_WR->write(reinterpret_cast<const char *>(&dados->Contador_Atr),sizeof(int));
		arquivo_WR->write(reinterpret_cast<const char *>(&dados->ContadorCircle_Atr),sizeof(int));

		if(tamanho_Line>0){


				arquivo_WR->write(reinterpret_cast<const char *>(dados->MXo_Atr),(dados->Contador_Atr)*sizeof(float));
				arquivo_WR->write(reinterpret_cast<const char *>(dados->LXo_Atr),(dados->Contador_Atr)*sizeof(float));
				arquivo_WR->write(reinterpret_cast<const char *>(dados->MYo_Atr),(dados->Contador_Atr)*sizeof(int));
				arquivo_WR->write(reinterpret_cast<const char *>(dados->LYo_Atr),(dados->Contador_Atr)*sizeof(int));
				arquivo_WR->write(reinterpret_cast<const char *>(dados->MZo_Atr),(dados->Contador_Atr)*sizeof(float));
				arquivo_WR->write(reinterpret_cast<const char *>(dados->LZo_Atr),(dados->Contador_Atr)*sizeof(float));

				arquivo_WR->write(reinterpret_cast<const char *>(dados->Color_Atr),(dados->Contador_Atr)*sizeof(DWORD));


				arquivo_WR->write(reinterpret_cast<const char *>(dados->MAlpha_Atr),(dados->Contador_Atr)*sizeof(float));
				arquivo_WR->write(reinterpret_cast<const char *>(dados->LAlpha_Atr),(dados->Contador_Atr)*sizeof(float));
				arquivo_WR->write(reinterpret_cast<const char *>(dados->MMVetorG_Atr),(dados->Contador_Atr)*sizeof(float));
				arquivo_WR->write(reinterpret_cast<const char *>(dados->LMVetorG_Atr),(dados->Contador_Atr)*sizeof(float));
				arquivo_WR->write(reinterpret_cast<const char *>(dados->Alpha_Beta_Teta_Atr),sizeof(dados->Alpha_Beta_Teta_Atr));
				arquivo_WR->close();

			}
		



	}





}




//Class Atributos--------------------------------------------------------------

Atributos::Atributos(){

	Contador_Atr=0;
	ContadorCircle_Atr=0;
	MXo_Atr=NULL;
	LXo_Atr=NULL;
	MYo_Atr=NULL;
	LYo_Atr=NULL;
	MZo_Atr=NULL;
	LZo_Atr=NULL;
	Color_Atr=NULL;
	MAlpha_Atr=NULL;
	LAlpha_Atr=NULL;
	MMVetorG_Atr=NULL;
	LMVetorG_Atr=NULL;
	Alpha_Beta_Teta_Atr[3];

	Color_Circle_Atr=NULL;

	A_Atr=NULL;
	B_Atr=NULL;
	AZo_Atr=NULL;
	BZo_Atr=NULL;
	Center_Atr=NULL;
	Kx_Atr=900.0;
	Ky_Atr=580.0;

    dados_Objeto.Contador_Atr=0;
	dados_Objeto.ContadorCircle_Atr=0;
	dados_Objeto.MXo_Atr=NULL;
	dados_Objeto.LXo_Atr=NULL;
	dados_Objeto.MYo_Atr=NULL;
	dados_Objeto.LYo_Atr=NULL;
	dados_Objeto.MZo_Atr=NULL;
	dados_Objeto.LZo_Atr=NULL;
	dados_Objeto.Color_Atr=NULL;
	dados_Objeto.MAlpha_Atr=NULL;
	dados_Objeto.LAlpha_Atr=NULL;
	dados_Objeto.MMVetorG_Atr=NULL;
	dados_Objeto.LMVetorG_Atr=NULL;
	for(int i=0;i<3;i++)
	Alpha_Beta_Teta_Atr[i]=0;

	dados_Objeto.Center_Atr=NULL;
	dados_Objeto.AZo_Atr=NULL;
	dados_Objeto.BZo_Atr=NULL;
	dados_Objeto.A_Atr=NULL;
	dados_Objeto.B_Atr=NULL;
	dados_Objeto.Color_Circle_Atr=NULL;
	for(int i=0;i<3;i++)
		Alpha_Beta_Teta_Circle_Atr[i]=0;


}

float  * Atributos::Realocar(float *Ponteiro,int Tamanho){


   return (float*) realloc(Ponteiro,Tamanho*sizeof(float));

}
int  * Atributos::Realocar(int *Ponteiro,int Tamanho){

	return (int*) realloc(Ponteiro,Tamanho*sizeof(int));

}

//------------------------------------------------------------------------------
struct Dados_Atributos Atributos::AlocandoAtributos(int tamanho_Line,int tamanho_Circle,struct Dados_Atributos dados){

int i=0;


	if(tamanho_Circle>0)

	{
		dados.Color_Circle_Atr=(DWORD *)realloc(dados.Color_Circle_Atr,tamanho_Circle*sizeof(DWORD));

		dados.B_Atr=Realocar(dados.B_Atr,tamanho_Circle);
		dados.AZo_Atr=Realocar(dados.AZo_Atr,tamanho_Circle);
		dados.BZo_Atr=	Realocar(dados.BZo_Atr,tamanho_Circle);





		dados.Center_Atr=(float**)realloc(dados.Center_Atr,tamanho_Circle*sizeof(float*));
		for(i=0;i<(dados.ContadorCircle_Atr);i++)
		{
			dados.Center_Atr[i] =NULL;
			dados.Center_Atr[i]=(float *)realloc(dados.Center_Atr[i],3*sizeof(float));

		}

	}



	dados.Color_Atr=NULL;
	dados.LAlpha_Atr=NULL;
	dados.MAlpha_Atr=NULL;
	dados.LMVetorG_Atr=NULL;
	dados.MZo_Atr=NULL;
	dados.LZo_Atr=NULL;
	dados.MXo_Atr=NULL;
	dados.LXo_Atr=NULL;
	dados.MYo_Atr=NULL;
	dados.LYo_Atr=NULL;

	if(tamanho_Line>0)
	{
		dados.Color_Atr=(DWORD *)realloc(dados.Color_Atr,tamanho_Line*sizeof(DWORD));
		dados.LAlpha_Atr=Realocar(dados.LAlpha_Atr,tamanho_Line);

		dados.MAlpha_Atr=Realocar(dados.MAlpha_Atr,tamanho_Line);
		dados.MMVetorG_Atr=Realocar(dados.MMVetorG_Atr,tamanho_Line);
		dados.LMVetorG_Atr=Realocar(dados.LMVetorG_Atr,tamanho_Line);
		dados.MZo_Atr=Realocar(dados.MZo_Atr,tamanho_Line);
		dados.LZo_Atr=Realocar(dados.LZo_Atr,tamanho_Line);
		dados.MXo_Atr=Realocar(dados.MXo_Atr,tamanho_Line);
		dados.LXo_Atr=Realocar(dados.LXo_Atr,tamanho_Line);
		dados.MYo_Atr=Realocar(dados.MYo_Atr,tamanho_Line);
		dados.LYo_Atr=Realocar(dados.LYo_Atr,tamanho_Line);
	}

 return dados;
}

void Atributos::AlocandoAtributos(int tamanho_Line,int tamanho_Circle,struct Dados_Atributos *dados){

int i=0;


	if(tamanho_Circle>0)

	{
		dados->Color_Circle_Atr=(DWORD *)realloc(dados->Color_Circle_Atr,tamanho_Circle*sizeof(DWORD));

		dados->B_Atr=Realocar(dados->B_Atr,tamanho_Circle);
		dados->AZo_Atr=Realocar(dados->AZo_Atr,tamanho_Circle);
		dados->BZo_Atr=	Realocar(dados->BZo_Atr,tamanho_Circle);





		dados->Center_Atr=(float**)realloc(dados->Center_Atr,tamanho_Circle*sizeof(float*));
		for(i=0;i<(dados->ContadorCircle_Atr);i++)
		{
			dados->Center_Atr[i] =NULL;
			dados->Center_Atr[i]=(float *)realloc(dados->Center_Atr[i],3*sizeof(float));

		}

	}





	if(tamanho_Line>0)
	{
		dados->Color_Atr=(DWORD *)realloc(dados->Color_Atr,tamanho_Line*sizeof(DWORD));
		dados->LAlpha_Atr=Realocar(dados->LAlpha_Atr,tamanho_Line);

		dados->MAlpha_Atr=Realocar(dados->MAlpha_Atr,tamanho_Line);
		dados->MMVetorG_Atr=Realocar(dados->MMVetorG_Atr,tamanho_Line);
		dados->LMVetorG_Atr=Realocar(dados->LMVetorG_Atr,tamanho_Line);
		dados->MZo_Atr=Realocar(dados->MZo_Atr,tamanho_Line);
		dados->LZo_Atr=Realocar(dados->LZo_Atr,tamanho_Line);
		dados->MXo_Atr=Realocar(dados->MXo_Atr,tamanho_Line);
		dados->LXo_Atr=Realocar(dados->LXo_Atr,tamanho_Line);
		dados->MYo_Atr=Realocar(dados->MYo_Atr,tamanho_Line);
		dados->LYo_Atr=Realocar(dados->LYo_Atr,tamanho_Line);
	}


}


Elipse::Elipse(){

			ContadorCircle_Atr=0;
			Center_Atr=0;
			AZo_Atr=0;
			BZo_Atr=0;
			A_Atr=0;
			B_Atr=0;
			Color_Circle_Atr=0;

			for(int i=0;i<3;i++)
			Alpha_Beta_Teta_Circle_Atr[i]=0;

			TipoElipse_Atr=0;
			CX=0;
			CY=0;
			CZ=0;







}

//-----------------------------------------------------------------------------------------------------------------------------

float Elipse::GetBZo_Atr(int Index){

	return BZo_Atr[Index];

}

float Elipse::GetAZo_Atr(int Index){

	return AZo_Atr[Index];

}

void Elipse::GetCenter_Atr(float **Center,int Index){

	Center[Index][0]=Center_Atr[Index][0];
	Center[Index][1]=Center_Atr[Index][1];
	Center[Index][2]=Center_Atr[Index][2];

}

DWORD Elipse::GetColor_Circle_Atr(int Index){

    return Color_Circle_Atr[Index];

}
float Elipse::GetA_Atr(int Index){

	return A_Atr[Index];
}

float Elipse::GetB_Atr(int Index){

	return B_Atr[Index];
}

void Elipse::AlocaElipse_Atr(int Count){

bool Testa=true;

	if(Count>0)

	{

			Color_Circle_Atr=Realocar(Color_Circle_Atr,Count);
			A_Atr=Realocar(A_Atr,Count);
			B_Atr=Realocar(B_Atr,Count);
			AZo_Atr=Realocar(AZo_Atr,Count);
			BZo_Atr=Realocar(BZo_Atr,Count);
			TipoElipse_Atr=Realocar_Int(TipoElipse_Atr,Count);
			CX=Realocar(CX,Count);
			CY=Realocar(CY,Count);
            CZ=Realocar(CZ,Count);


			Center_Atr=Realocar_PonteiroCenter(Center_Atr,Count);




	}



}


//------------------------------------------------------------------------------------------------------------------------------

void Elipse::SetContadorCircle_Atr(int CCircle){

	ContadorCircle_Atr=CCircle;



}

//--------------------------------------------------------------------------------------------------------------------------------

int Elipse::GetContadorCircle_Atr(){

return ContadorCircle_Atr;

}
//---------------------------------------------------------------------------------------------------------------------------------

void Elipse::SetCenter_Atr(float **C_Atr){


Center_Atr=C_Atr;


}
//--------------------------------------------------------------------------------------------------------------------------------

void Elipse::SetCenter_Atr(float **C_Atr,int Count){
	for(int i=0;i<3;i++)
	Center_Atr[Count][i]=C_Atr[Count][i];

}

void Elipse::SetCenter_Atr(float Xo,float Yo,float Zo,int Index){

	Center_Atr[Index][0]=Xo;
	Center_Atr[Index][1]=Yo;
	Center_Atr[Index][2]=Zo;

}

//------------------------------------------------------------------------------

void Elipse::SetAZo_Atr(float AZo,int Count){

	AZo_Atr[Count]=AZo;

}

//------------------------------------------------------------------------------
void Elipse::SetBZo_Atr(float BZo,int Count){

BZo_Atr[Count]=BZo;

}
//------------------------------------------------------------------------------

void Elipse::SetA_Atr(float A,int Count){

	A_Atr[Count]=A;

}
//------------------------------------------------------------------------------

void Elipse::SetB_Atr(float B,int Count){


	B_Atr[Count]=B;

}

//------------------------------------------------------------------------------

void Elipse::SetColor_Circle_Atr(DWORD Color,int Count){

	Color_Circle_Atr[Count]=Color;

}

//------------------------------------------------------------------------------

void Elipse::SetTipoElipse_Atr(int T_Elipse,int Count ){

	TipoElipse_Atr[Count]=T_Elipse;

}


//--------------------------------------------------------------------------------------------------------------------------------



float **Elipse::GetCenter_Atr(){

	return Center_Atr;

}

//--------------------------------------------------------------------------------------------------------------------------------

void Elipse::SetAZo_Atr(float *_AZo_Atr){

	AZo_Atr=_AZo_Atr;


}

//--------------------------------------------------------------------------------------------------------------------------------

float *Elipse::GetAZo_Atr(){



	return AZo_Atr;

}
//---------------------------------------------------------------------------------------------------------------------------------

void Elipse::SetBZo_Atr(float *_BZo_Atr){

	BZo_Atr=_BZo_Atr;

}

//---------------------------------------------------------------------------------------------------------------------------------

float * Elipse::GetBZo_Atr(){

	return BZo_Atr;


}

//---------------------------------------------------------------------------------------------------------------------------------

void Elipse::SetA_Atr(float * _A_Atr){

	A_Atr=_A_Atr;


}

//--------------------------------------------------------------------------------------------------------------------------------

float * Elipse::GetA_Atr(){

	return A_Atr;

}

//--------------------------------------------------------------------------------------------------------------------------------

void Elipse::SetB_Atr(float * _B_Atr){

	B_Atr=_B_Atr;

}

//--------------------------------------------------------------------------------------------------------------------------------

float * Elipse::GetB_Atr(){

	return this->B_Atr;
}
//------------------------------------------------------------------------------
void Elipse::SetCX(float _CX,int Index){

	CX[Index]=_CX;

}
//------------------------------------------------------------------------------

void Elipse::SetCX(float *_CX){

	CX=_CX;

}

//------------------------------------------------------------------------------

float Elipse::GetCX(int Index){

	return CX[Index];

}
//------------------------------------------------------------------------------

float *Elipse::GetCX(){

	return CX;

}

//---------------------------------------------------------------------------------------------------------------------------------

void Elipse::SetCY(float _CY,int Index){

	CY[Index]=_CY;

}

//------------------------------------------------------------------------------

void Elipse::SetCY(float *_CY){

	CY=_CY;
}
//------------------------------------------------------------------------------
float Elipse::GetCY(int Index){

	return CY[Index];
}
//------------------------------------------------------------------------------

float *Elipse::GetCY(){

	return CY;
}
//------------------------------------------------------------------------------
void Elipse::SetCZ(float _CZ,int Index){

	CZ[Index]=_CZ;
}

//------------------------------------------------------------------------------
void Elipse::SetCZ(float *_CZ){

	CZ=_CZ;
}
//------------------------------------------------------------------------------
float Elipse::GetCZ(int Index){


	return CZ[Index];
}
//------------------------------------------------------------------------------
float *Elipse::GetCZ(){

	return CZ;

}

//------------------------------------------------------------------------------

void Elipse::SetColor_Circle_Atr(DWORD *CC_Atr){

	Color_Circle_Atr=CC_Atr;

}

//---------------------------------------------------------------------------------------------------------------------------------

DWORD *Elipse::GetColor_Circle_Atr(){

	return Color_Circle_Atr;

}

//---------------------------------------------------------------------------------------------------------------------------------

void Elipse::SetAlpha_Beta_Teta_Circle_Atr(float ABT_Atr[3]){

for(int i=0;i<3;i++)
Alpha_Beta_Teta_Circle_Atr[i]=ABT_Atr[i];

}
//----------------------------------------------------------------------------------------------------------------------------------

float  *Elipse::GetAlpha_Beta_Teta_Atr(){

return Alpha_Beta_Teta_Circle_Atr;
}

//----------------------------------------------------------------------------------------------------------------------------------

void Elipse::SetTipoElipse_Atr(int * TElipse_Atr){

TipoElipse_Atr=TElipse_Atr;
}

//---------------------------------------------------------------------------------------------------------------------------------

int * Elipse::GetTipoElipse_Atr(){

return TipoElipse_Atr;

}

//------------------------------------------------------------------------------

int Elipse::GetTipoElipse_Atr(int Index){

	return TipoElipse_Atr[Index];

}
