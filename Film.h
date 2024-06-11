//---------------------------------------------------------------------------
#ifndef FilmH
#define FilmH
class Film
{
    public:
		AnsiString tytul;
		AnsiString rezyser;
		AnsiString rodzaj;
		int rok;
		int poz;
		Film(AnsiString tytul, AnsiString rezyser, AnsiString rodzaj, int rok,
			int poz);
};
//---------------------------------------------------------------------------
#endif

