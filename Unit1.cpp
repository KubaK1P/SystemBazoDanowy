//---------------------------------------------------------------------------

#include <vcl.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <vector>
#include <string>
#include<sstream>
#pragma hdrstop
#include "Unit1.h"
#include "Film.h"
using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
std::vector<Film*> filmy;

//---------------------------------------------------------------------------

bool toBool(string ip) {
   bool op;
   istringstream(ip) >> std::boolalpha >> op;
   return op;
}

__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	string line;    //declarations
	std::ifstream inFile("data.txt");
	int i = 0;
	AnsiString t;
	int r;
	AnsiString rd;
	AnsiString re;
	int p;
		while (getline(inFile, line))   //processing the file in groups of five lines
										//the file contains five atribtes for each Film Object
		{
			if(i==0)
			{
				t=line.c_str();
			}
			if(i==1)
			{
				r=stoi(line);
			}
			if(i==2)
			{
				rd=line.c_str();;
			}
			if(i==3)
			{
				re=line.c_str();;
			}
			if(i==4)
			{
				p=stoi(line);
				filmy.push_back(new Film(
					t,
					re,
					rd,
					r,
					p
				));
				i=-1;
			}
			i++;
		}

	inFile.close();    //close the file stream

	for(auto f: filmy)      //populate the list
	{
	   Form1->list->Items->Add(
		 f->tytul +" "+ f->rok
	   );
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::saveClick(TObject *Sender)
{
	filmy.push_back(new Film(
	   Form1->title->Text,
	   Form1->director->Text,
		Form1->genre->Text,
	   std::atoi(AnsiString(Form1->year->Text).c_str()),
	   Form1->stan->ItemIndex
	));    //add new Film object to the vector

	Form1->title->Text = *new System::UnicodeString("");      //reset input fields
	Form1->director->Text = *new System::UnicodeString("");
	Form1->year->Text = *new System::UnicodeString("");
	Form1->genre->ItemIndex = 0;
	Form1->stan->ItemIndex = 0;
	Form1->list->Items->Clear();

	for(auto f: filmy)  //populate the visual list element
	{
	   Form1->list->Items->Add(
		 f->tytul +" "+ f->rok
	   );
	}

	std::ofstream outFile("data.txt");
	for (const auto &e : filmy) outFile << e->tytul << "\n"<< e->rok << "\n"<< e->rodzaj << "\n"<< e->rezyser << "\n"<< e->poz << "\n";
	outFile.close();

	if(sorting->Text == "tytu³u")   //sort
	{
   sort(filmy.begin(), filmy.end(), [](const Film*lhs, const Film*rhs) {
	  return lhs->tytul < rhs->tytul;
   }
   );
   } else
   {
   sort(filmy.begin(), filmy.end(), [](const Film*lhs, const Film*rhs) {
	return lhs->rok < rhs->rok;
   }
   );
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::editClick(TObject *Sender)
{
	int selected = Form1->list->ItemIndex;
	Film *film = filmy[selected];

	Form1->title->Text = *new System::UnicodeString(film->tytul);  // display data to edit in the input boxes
	Form1->director->Text = *new System::UnicodeString(film->rezyser);
	Form1->year->Text = *new System::UnicodeString(film->rok);
	Form1->genre->Text =  *new System::UnicodeString(film->rodzaj);
	Form1->stan->ItemIndex = film->poz;

	filmy.erase(filmy.begin() + selected); //delete selected item
	Form1->list->Items->Clear();

	for(auto f: filmy)
	{
	   Form1->list->Items->Add(
		 f->tytul +" "+ f->rok
	   );
	}

		if(sorting->Text == "tytu³u")   //sort depending on criteria
		{
   sort(filmy.begin(), filmy.end(), [](const Film*lhs, const Film*rhs) {
	  return lhs->tytul < rhs->tytul;
   }
   );
   } else
   {
   sort(filmy.begin(), filmy.end(), [](const Film*lhs, const Film*rhs) {
	return lhs->rok < rhs->rok;
   }
   );
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::sortingChange(TObject *Sender)
{

	Form1->list->Items->Clear();   //cleear

	if(sorting->Text == "tytu³u")  //sort depending on criteria
	{
   sort(filmy.begin(), filmy.end(), [](const Film*lhs, const Film*rhs) {
	  return lhs->tytul < rhs->tytul;
   }
   );
   } else
   {
   sort(filmy.begin(), filmy.end(), [](const Film*lhs, const Film*rhs) {
	return lhs->rok < rhs->rok;
   }
   );
   }

	for(auto f: filmy)  //populate
	{
	   Form1->list->Items->Add(
		 f->tytul +" "+ f->rok
	   );
	}
}

void __fastcall TForm1::delClick(TObject *Sender)
{
	 int selected = Form1->list->ItemIndex;    //get the selected ITEM_INDEX and
	 filmy.erase(filmy.begin() + selected);    //delete the item
	 Form1->list->Items->Clear();

	 if(sorting->Text == "tytu³u") //sort filmy depending on criteria
		{
   sort(filmy.begin(), filmy.end(), [](const Film*lhs, const Film*rhs) {
	  return lhs->tytul < rhs->tytul;
   }
   );} else
   {
   sort(filmy.begin(), filmy.end(), [](const Film*lhs, const Film*rhs) {
	return lhs->rok < rhs->rok;
   }
   );
   }

	for(auto f: filmy)
	{
	   Form1->list->Items->Add(
		 f->tytul +" "+ f->rok
	   );   //add new elements to the visual list element
	}

	std::ofstream outFile("data.txt");
	outFile.open("data.txt", std::ofstream::out | std::ofstream::trunc);  //delete all from file to later update all content of THE LIST
	outFile.close();
	std::ofstream inFile("data.txt");
	for (const auto &e : filmy) inFile << e->tytul << "\n"<< e->rok << "\n"<< e->rodzaj << "\n"<< e->rezyser << "\n"<< e->poz << "\n";
	inFile.close();

}
//---------------------------------------------------------------------------
void __fastcall TForm1::clearAllClick(TObject *Sender)
{
	 filmy.clear();  //clear the vector
	 Form1->list->Items->Clear();    //clear the visual movie list
	 std::ofstream outFile("data.txt");
	 outFile.open("data.txt", std::ofstream::out | std::ofstream::trunc);  //delete contents of the file
	 outFile.close();
}


