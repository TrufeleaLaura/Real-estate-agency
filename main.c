//#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <stdio.h>
#include <string.h>
#include "teste.h"
#include "listaoferta.h"
#include "Oferta.h"
#include "service.h"


void ui_adauga_oferta_in_lista(Listaoferte* lista_oferte)
{
	/*functie de ui pentru adaugarea unei oferte in lista
	lista_oferte - Listaoferte
	pre: lista_oferte valida
	post: -
	*/
	char tip[30], adresa[30], reziduu_citire[20];
	int suprafata, pret,status_adaugare;
	printf("Introduceti tipul ofertei:\n");
	gets_s(tip, 30);
	printf("Introduceti adresa:\n");
	gets_s(adresa, 30);
	printf("Introduceti suprafata:\n");
	scanf("%d", &suprafata);
	printf("Introduceti pretul :\n");
	scanf("%d", &pret);
	gets_s(reziduu_citire, 20);

	status_adaugare = service_adauga_oferta(lista_oferte, tip, adresa, suprafata,pret);
	if (status_adaugare == 1 || status_adaugare == 2 || status_adaugare == 3 || status_adaugare==4)
	{
		printf("Oferta invalida!\n");
		return;
	}
	printf(" Oferta adaugata cu succes!\n");
}


void ui_afiseaza_oferte(Listaoferte* lista_oferte)
{
	/*functie care afiseaza ofertele din lista
	lista_oferte - Listaoferte
	pre: lista_oferte valida
	post: -
	*/
	for (int i = 0; i < lista_oferte->numar_oferte; i++)
		printf("%s %s %d %d\n", lista_oferte->lista[i].tip, lista_oferte->lista[i].adresa, lista_oferte->lista[i].suprafata,lista_oferte->lista[i].pret);
}



void ui_actualizare_oferta(Listaoferte* lista_oferte)
{
	/*functie de ui pentru actualizarea  unei oferte
	lista_oferte - Lista_oferte
	pre: lista_oferte valida
	post: -
	*/
	char tip[30], adresa[30], reziduu_citire[20];
	int pret_actualizat, status_actualizare,suprafata;

	printf("Introduceti tipul ofertei:\n");
	gets_s(tip, 30);
	printf("Introduceti adresa:\n");
	gets_s(adresa, 30);
	printf("Introduceti pretul nou:\n");
	scanf("%d", &pret_actualizat);
	printf("Introduceti suprafata:\n");
	scanf("%d", &suprafata);
	gets_s(reziduu_citire, 20);

	status_actualizare = service_actualizare_oferta(lista_oferte,tip,adresa, pret_actualizat, suprafata);

	if (status_actualizare == -1)
	{
		printf("Oferta inexistenta!\n");
		return;
	}
	else
		printf("Oferta actualizata cu succes!\n");
}


void ui_sterge_oferta_din_lista(Listaoferte* lista_oferte)
{
	/*functie de ui pentru stergerea unei oferte din lista
	lista_oferte - Lista_oferte
	pre: lista_oferte valida
	post: -
	*/
	char tip[30], adresa[30];
	int status_stergere,suprafata;

	printf("Introduceti tipul ofertei:\n");
	gets_s(tip, 30);
	printf("Introduceti adresa:\n");
	gets_s(adresa, 30);
	printf("Introduceti suprafata:\n");
	scanf("%d", &suprafata);

	status_stergere = service_sterge_oferta(lista_oferte, tip, adresa,suprafata);

	if (status_stergere == -1)
	{
		printf("Oferta inexistenta!\n");
		return;
	}
	else
		printf("Oferta stearsa cu succes!\n");
}

void ui_filtreaza_oferte(Listaoferte* lista_oferte)
{
	/*functie de ui pentru filtrarea ofertelor dupa un anumit tip
	lista_oferte-Listaoferte
	pre: lista_oferte valida
	post:lista filtrata-Listaoferte daca sunt oferte care sunt de acel tip
	*/
	char tip[30];
	printf("Introduceti tipul ofertei dupa care doriti filtrarea:\n");
	gets_s(tip, 30);
	Listaoferte filteredList = filteroffers(lista_oferte, tip);
	if (filteredList.numar_oferte==0)
	{
		printf("Nu exista oferte care sa aiba acest tip!");
		return;
	}
	ui_afiseaza_oferte (&filteredList);
	distruge_lista_oferte(&filteredList);
}


void ui_sortare_pret(Listaoferte* lista_oferte)
{
	/* functie de ui pentru sortarea ofertelor  dupa pret
	pre:lista_oferte-Listaoferte
	post:sortlist-listaoferte sortata  dupa pret
	*/
	int ordine;
	printf("Introduceti ordinea pe care o doriti.\nTastati 1 pentru ordine crescatoare, 0 pentru descrescatoare:\n");
	scanf("%d", &ordine);
	Listaoferte sortl = sortare(lista_oferte,ordine,comparare_pret);
	if (sortl.numar_oferte == 0)
	{
		printf("Nu exista inca oferte in lista!");
		return;
	}
	ui_afiseaza_oferte(&sortl);
	distruge_lista_oferte(&sortl);
}

void ui_sortare_tip(Listaoferte* lista_oferte)
{
	/* functie de ui pentru sortarea ofertelor  dupa tip
	pre:lista_oferte-Listaoferte
	post:sortlist-listaoferte sortata  dupa tip
	*/
	int ordine;
	printf("Introduceti ordinea pe care o doriti.\nTastati 1 pentru ordine crescatoare, 0 pentru descrescatoare:\n");
	scanf("%d", &ordine);
	Listaoferte sortl = sortare(lista_oferte, ordine,comparare_tip);
	if (sortl.numar_oferte == 0)
	{
		printf("Nu exista inca oferte in lista!");
		return;
	}
	ui_afiseaza_oferte(&sortl);
	distruge_lista_oferte(&sortl);
}

void UI()
{
	//meniul aplicatiei
	Listaoferte lista_oferte = creeaza_lista_oferte(10);
	int cmd;
	char reziduu_citire[20];
	printf("0. Iesire\n1. Adauga oferta\n2.Sterge o anumita oferta.\n3.Actualizeaza o anumita oferta\n4.Filtreaza ofertele dupa un anumit tip\n5.Sortare oferte  dupa pret.\n6.Sortare oferte  dupa tip.\n7.Afiseaza toate ofertele\n");
	while (1)
	{
		printf("Introduceti comanda:\n");
		scanf("%d", &cmd);
		gets_s(reziduu_citire, 20);
		if (cmd == 0)
			break;
		if (cmd == 1)
			ui_adauga_oferta_in_lista(&lista_oferte);
		if (cmd == 2)
			ui_sterge_oferta_din_lista(&lista_oferte);
		if (cmd == 3)
			ui_actualizare_oferta(&lista_oferte);
		if (cmd == 4)
			ui_filtreaza_oferte(&lista_oferte);
		if (cmd == 5)
			ui_sortare_pret(&lista_oferte);
		if (cmd == 6)
			ui_sortare_tip(&lista_oferte);
		if (cmd == 7)
			ui_afiseaza_oferte(&lista_oferte);
		
	

	}

	distruge_lista_oferte(&lista_oferte);
}

int main()
{
	UI();
	ruleaza_toate_testele();
	_CrtDumpMemoryLeaks();
	return 0;
}