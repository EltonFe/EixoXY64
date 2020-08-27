//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("UnitEixoXY.cpp", EixoXY);
USEFORM("UnitConstrucaoLine.cpp", ConstrucaoLines);
USEFORM("UnitElipse.cpp", FElipse);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TEixoXY), &EixoXY);
		Application->CreateForm(__classid(TConstrucaoLines), &ConstrucaoLines);
		Application->CreateForm(__classid(TFElipse), &FElipse);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
