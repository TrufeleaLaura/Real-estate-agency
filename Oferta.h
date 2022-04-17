#pragma once

typedef struct {
	char* tip;
	char* adresa;
	int pret,suprafata;
}Oferta;

Oferta creeaza_oferta(char* tip, char* adresa, int suprafata,int pret);

void distruge_oferta(Oferta* offer);

Oferta copiaza_oferta(Oferta* offer);

int valideaza_oferta(Oferta* offer);

