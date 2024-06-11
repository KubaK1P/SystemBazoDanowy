//---------------------------------------------------------------------------

#pragma hdrstop
#include "Film.h"

Film::Film(AnsiString tytul, AnsiString rezyser, AnsiString rodzaj, int rok,
	int poz)
	{
		this->tytul = tytul;
		this->rezyser = rezyser;
		this->rodzaj = rodzaj;
		this->rok = rok;
		this->poz = poz;
	};

//---------------------------------------------------------------------------
#pragma package(smart_init)

