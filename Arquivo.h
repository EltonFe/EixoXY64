//---------------------------------------------------------------------------

#ifndef ArquivoH
#define ArquivoH
//---------------------------------------------------------------------------
#include <System.Types.hpp>
#include <System.Classes.hpp>
#include <vector>
#include <iterator>
#include <System.Math.hpp>
#include <stdlib.h>
#include <malloc.h>
#include <vector>
using namespace std;


using namespace std;

namespace Name_Arquivos{


	struct Dados_Atributos
	{
		int Contador_Atr;
		 int ContadorCircle_Atr;
		 float *MXo_Atr;
		 float *LXo_Atr;
		 float *MYo_Atr;
		 float *LYo_Atr;
		 float  *MZo_Atr;
		 float  *LZo_Atr;
		 DWORD *Color_Atr;
		 float  *MAlpha_Atr;
		 float  *LAlpha_Atr;
		 float  *MMVetorG_Atr;
		 float  *LMVetorG_Atr;
		 float Alpha_Beta_Teta_Atr[3];

		 float **Center_Atr;
		 float *AZo_Atr;
		 float *BZo_Atr;
		 float *A_Atr;
		 float *B_Atr;
		 DWORD *Color_Circle_Atr;
		 float Alpha_Beta_Teta_Circle_Atr[3];




	};


	class Atributos
	{
		public:
			int Contador_Atr;
			int ContadorCircle_Atr;
			float *MXo_Atr;
			float *LXo_Atr;
			float *MYo_Atr;
			float *LYo_Atr;
			float  *MZo_Atr;
			float  *LZo_Atr;
			DWORD *Color_Atr;
			float  *MAlpha_Atr;
			float  *LAlpha_Atr;
			float  *MMVetorG_Atr;
			float  *LMVetorG_Atr;
			float Alpha_Beta_Teta_Atr[3];

			float **Center_Atr;
			float *AZo_Atr;
			float *BZo_Atr;
			float *A_Atr;
			float *B_Atr;
			DWORD *Color_Circle_Atr;
			float Alpha_Beta_Teta_Circle_Atr[3];




			float Kx_Atr;
			float Ky_Atr;


		//------------------------------------------------------------------
		Atributos();
		struct Dados_Atributos dados_Objeto;
		float  * Realocar(float *Poneteiro,int Tamanho);
		int  * Realocar(int *Ponteiro,int Tamanho);
		struct Dados_Atributos AlocandoAtributos(int tamanho,int tamanho_Circle,struct Dados_Atributos dados);
		void AlocandoAtributos(int tamanho,int tamanho_Circle,struct Dados_Atributos *dados);
		float *Alocando(float *Ponteiro,int Tamanho);
		int *Alocando(int *Ponteiro,int Tamanho);
		UnicodeString Teste() ;



	};

	class Elipse{

	private:
			int ContadorCircle_Atr;

			float *AZo_Atr;
			float *BZo_Atr;
			float *A_Atr;
			float *B_Atr;
            float *CX;
			float *CY;
			float *CZ;
			DWORD *Color_Circle_Atr;
			int *TipoElipse_Atr;
			float Alpha_Beta_Teta_Circle_Atr[3];

			//Tmp_Variaveis-----------------------------------------------------

			int Tmp_ContadorCircle_Atr;
			float **Tmp_Center_Atr;
			float *Tmp_AZo_Atr;
			float *Tmp_BZo_Atr;
			float *Tmp_A_Atr;
			float *Tmp_B_Atr;
			DWORD *Tmp_Color_Circle_Atr;
			int *Tmp_TipoElipse_Atr;


	public:
			Elipse();

            float **Center_Atr;
			void AlocaElipse_Atr(int Count);
			void SetContadorCircle_Atr(int CCircle);
			int GetContadorCircle_Atr();
			void SetCenter_Atr(float **C_Atr);
			void SetCenter_Atr(float **,int);
			void SetCenter_Atr(float,float,float,int);
			float **GetCenter_Atr();
			void GetCenter_Atr(float **,int );
			void SetAZo_Atr(float *);
			void SetAZo_Atr(float,int);
			float *GetAZo_Atr();
			void SetBZo_Atr(float *);
			void SetBZo_Atr(float,int);
			float *GetBZo_Atr();
			float GetBZo_Atr(int);
			void SetA_Atr(float *);
			void SetA_Atr(float ,int);
			float *GetA_Atr();
			float GetA_Atr(int Index);
            float GetAZo_Atr(int Index);
			void SetB_Atr(float *);
			void SetB_Atr(float,int);
			float *GetB_Atr();
			float GetB_Atr(int Index);
			void SetCX(float _CX,int Index);
			void SetCX(float *_CX);
			float GetCX(int Index);
			float *GetCX();

			void SetCY(float _CY,int Index);
			void SetCY(float *_CY);
			float GetCY(int Index);
			float *GetCY();

			void SetCZ(float _CZ,int Index);
			void SetCZ(float *_CZ);
			float GetCZ(int Index);
			float *GetCZ();

			void SetColor_Circle_Atr(DWORD *);
			void SetColor_Circle_Atr(DWORD,int);
			DWORD *GetColor_Circle_Atr();
            DWORD GetColor_Circle_Atr(int Index);
			void SetAlpha_Beta_Teta_Circle_Atr(float *);
			float *GetAlpha_Beta_Teta_Atr();
			void SetTipoElipse_Atr(int *);
			void SetTipoElipse_Atr(int,int);
			int *GetTipoElipse_Atr();
			int GetTipoElipse_Atr(int Index);









	};

	class Line{
		private:
		float *MAlpha_Atr;
		float *MVetor_Atr;
		float *LAlpha_Atr;
		float *LVetor_Atr;
		float *MXo_Atr;
		float *LXo_Atr;
		float *MYo_Atr;
		float *LYo_Atr;
		float *MZo_Atr;
		float *LZo_Atr;
		unsigned long *Cor_Line;

		//Tmp_Var---------------------------------------------------------------

		float *Tmp_MA;
		float *Tmp_LA;
		float *Tmp_MV;
		float *Tmp_LV;
		float *Tmp_MX;
		float *Tmp_LX;
		float *Tmp_MY;
		float *Tmp_LY;
		float *Tmp_MZ;
		float *Tmp_LZ;
		unsigned long *Tmp_CL;



		int Contador_Line;
		float Alpha_B_T[3];


		public:

		Line();
		float *Realocar(float *Ponteiro,int Count);
		unsigned long * Realocar(unsigned long *Ponteiro,int Count);
		int  *Realocar_Int(int *Ponteiro,int Tamanho);
		void Alocando_Line(int Count);
		//----------------------------------------------------------------------
		void SetMAlpha_Atr(float Valor,int Index);
		void SetLAlpha_Atr(float Valor,int Index);
		void SetMVetor_Atr(float Valor,int Index);
		void SetLVetor_Atr(float Valor,int Index);
		void SetMXo_Atr(float Valor,int Index);
		void SetLXo_Atr(float Valor,int Index);
		void SetMYo_Atr(float Valor,int Index);
		void SetLYo_Atr(float Valor,int Index);
		void SetMZo_Atr(float Valor,int Index);
		void SetLZo_Atr(float Valor,int Index);
        void SetAlpha_B_T_Atr(float *);
		void SetCor_Line(unsigned long Valor,int Index);
		void SetContador_Line(int Valor);
		//----------------------------------------------------------------------

		float GetMAlpha_Atr(int Index);
		float *GetMAlpha_Atr();
		float GetLAlpha_Atr(int Index);
		float *GetLAlpha_Atr();
		float GetMVetor_Atr(int Index);
		float *GetMVetor_Atr();
		float GetLVetor_Atr(int Index);
		float *GetLVetor_Atr();



		float GetMZo_Atr(int Index);
		float *GetMZo_Atr();
		float GetLZo_Atr(int Index);
		float *GetLZo_Atr();
		float *GetAlpha_B_T(float *ABT);
		float *GetAlpha_B_T();
		float *GetMAlpha_AtrPtr();
		unsigned long GetCor_Line(int Index);
		unsigned long *GetCor_Line();
        int GetContador_Line();









	};





   class Objetos :public Atributos
	{
		private:
		bool Visao_XY;
		bool Visao_XZ;
		float Alpha_B_T[3];


		public :

		//---------------------------------------------------------------------

		//---------------------------------------------------------------------
		Elipse *Elipse_Atr;
		Line *Lines_Atr;

		bool Chave_Point;
		float **Mxy;
		float **Lxy;
		TList *List;
		TPoint **Point;
		TPoint *P2;


		vector<TPoint *> VectorP2;
		vector<int> InteiroVetor;
		vector<int>::iterator IteradorInteiro;
		vector<TPoint *>::iterator IteradorTPoint;
		int Count_Line;
		UnicodeString Teste();
		Objetos();
		void Draw_Parametros(Objetos *arquivo);

		float ***Draw_Elipse();
		void Rotacao_Vetores_3D_Circle_MP2(float xyz[3],float xe,float ye, float  ze, float Alpha_Beta_Teta[3]);

		float ** Aloca_P1(int Count);
		TPoint **Aloca_TPoint(int Count);
//		void  Aloca_Point(int count,TPoint ***p1);
		float X(float x);
		float Y(float y);

		void SetVisao_XY(bool);
		bool GetVisao_XY();
		void SetVisao_XZ(bool);
		bool GetVisao_XZ();
		void SetAlpha_B_T(float ABT,int Index);
		void SetAlpha_B_T(float ABT[3]);
		float * GetAlpha_B_T();
		float GetAlpha_B_T(int Index);








	};

	class Arquivo:public Atributos{
	public:
		int Count_Line;
		char Nome[100];





		Arquivo();
		void Abrir_Arquivo(char *Nome_Arquivo,struct Dados_Atributos *arquivo);
		void Salvar_Arquivo(char *nome_Arquivo,struct Dados_Atributos *dados);




	};








}


#endif
