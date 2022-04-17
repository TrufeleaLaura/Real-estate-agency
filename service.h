#pragma once

#include "Listaoferta.h"
#include "Oferta.h"

//typedef int(*Functie_comparare)(Oferta* offer_1, Oferta* offer_2, int ordine);

int service_adauga_oferta(Listaoferte* lista_oferte, char* tip, char* adresa, int suprafata,int pret);

int service_actualizare_oferta(Listaoferte* lista_oferte, char* tip, char* adresa, int pret_actualizat);

int service_sterge_oferta(Listaoferte* lista_oferte, char* tip, char* adresa);

Listaoferte filteroffers(Listaoferte* lista_oferte, char* tip);

Listaoferte sortare_pret(Listaoferte* lista_oferte, int ordine);

int comparare_tip(Oferta* offer_1, Oferta* offer_2, int ordine);

int comparare_pret(Oferta* offer_1, Oferta* offer_2, int ordine);

Listaoferte sortare(Listaoferte* lista_oferte, int ordine, int(*comparare_tip)(Oferta*, Oferta*, int));
