#pragma once
#include "Oferta.h"

typedef struct
{
	Oferta* lista;
	int capacitate_lista;
	int numar_oferte;
}Listaoferte;

Listaoferte creeaza_lista_oferte(int capacitate_lista);

void distruge_lista_oferte(Listaoferte* lista_oferte);

Oferta returneaza_oferta_de_pe_pozitie(Listaoferte* lista_oferte, int pozitie);

void adauga_oferta_in_lista(Listaoferte* lista_oferte, Oferta offer);

void actualizare_oferta(Oferta* lista_oferte, int pret_actualizat, int pozitie);

void sterge_oferta_din_lista(Oferta* lista_oferte, int pozitie);

void redimensioneaza_lista_oferte(Listaoferte* lista_oferte);

Listaoferte copiaza_lista_oferte(Listaoferte* lista_oferte);
