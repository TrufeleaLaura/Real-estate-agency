#include "listaoferta.h"
#include "Oferta.h"
#include <stdlib.h>
#include <string.h>

Listaoferte creeaza_lista_oferte(int capacitate_lista)
{
	/*creeaza o lista noua de oferte
	capacitate_lista - intreg
	pre: capacitate_lista >0
	post: lista_oferte - Listaoferte valida
	*/
	Listaoferte lista_oferte;
	lista_oferte.lista = (Oferta*)malloc(capacitate_lista * sizeof(Oferta));
	lista_oferte.capacitate_lista = capacitate_lista;
	lista_oferte.numar_oferte = 0;
	return lista_oferte;
}

void distruge_lista_oferte(Listaoferte* lista_oferte)
{

	/*distruge o lista existenta de oferte (elibereaza memoria alocata)
	lista_oferte - Listaoferte
	pre: lista_oferte valida
	post: memoria a fost eliberata
	*/
	int i;
	for (i = 0; i < lista_oferte->numar_oferte; i++)
	{
		distruge_oferta(&lista_oferte->lista[i]);
	}
	free(lista_oferte->lista);
	lista_oferte->numar_oferte = 0;
}

int cauta_oferta_in_lista(Listaoferte* lista_oferte, Oferta offer)
{
	/*cauta o oferta in lista
	pre: lista_oferte valida; oferta valid
	post: cauta_oferta_in_lista = i, oferta este pe pozitia i in lista
									   -1, oferta nu este in lista
	*/
	int pozitie = -1;
	for (int i = 0; i < lista_oferte->numar_oferte && pozitie == -1; i++)
		if (verifica_egalitate_intre_oferte(lista_oferte->lista[i], offer) == 1)
			pozitie = i;
	return pozitie;
}

void adauga_oferta_in_lista(Listaoferte* lista_oferte, Oferta offer)
{
	/*adauga oferta in lista
	lista_oferta - Listaoferte
	offer - oferta
	pre: lista_oferte valida; offer valida
	post: lista_oferte-Listaoferte; lista_oferte' = lista_oferte+{offer}
	*/
	if (lista_oferte->numar_oferte == lista_oferte->capacitate_lista)
		redimensioneaza_lista_oferte(lista_oferte);
	lista_oferte->lista[lista_oferte->numar_oferte] = offer;
	lista_oferte->numar_oferte++;
}

void redimensioneaza_lista_oferte(Listaoferte* lista_oferte)
{
	/*mareste capacitatea maxima a listei de oferte
	lista_moferte - Listaoferte
	pre: lista_oferte valida
	post: lista_oferte'-Listaoferte; lista_oferte'.capacitate_lista = 2*lista_oferte.capacitate_lista
	*/
	int capacitate_noua = lista_oferte->capacitate_lista * 2;
	Oferta* lista_noua = (Oferta*)malloc(capacitate_noua * sizeof(Oferta));
	int i;
	for (i = 0; i < lista_oferte->numar_oferte; i++)
		lista_noua[i] = lista_oferte->lista[i];
	free(lista_oferte->lista);
	lista_oferte->lista = lista_noua;
	lista_oferte->capacitate_lista = capacitate_noua;
}

Oferta returneaza_oferta_de_pe_pozitie(Listaoferte* lista_oferte, int pozitie)
{
	/*returneaza o oferta de pe o pozitie data
	lista_oferte - Listaoferte
	pozitie - intreg
	pre: lista_oferte valida; pozitie>=0, pozitie<=numar_oferte
	post: -
	*/
	return lista_oferte->lista[pozitie];
}

Listaoferte copiaza_lista_oferte(Listaoferte* lista_oferte)
{
	/*copiaza continutul unei liste de oferte
	lista_oferte - Listaoferte
	pre: lista_oferte valida
	post: copie_lista_oferte = lista_oferte
	*/
	Listaoferte copie_lista_oferte = creeaza_lista_oferte(lista_oferte->capacitate_lista);
	for (int i = 0; i < lista_oferte->numar_oferte; i++)
	{
		Oferta offer = returneaza_oferta_de_pe_pozitie(lista_oferte, i);
		adauga_oferta_in_lista(&copie_lista_oferte, copiaza_oferta(&offer));
	}
	return copie_lista_oferte;
}

void actualizare_oferta(Listaoferte* lista_oferte, int pret_actualizat, int pozitie)
{
	/*actualizeaza pretul unei oferte din lista
	lista_oferte - Listaoferte
	pret_actualizat - intreg
	pozitie - intreg
	pre: lista_oferte valida; pret_actualizat > 0; pozitie>=0, pozitie<=numar_oferte
	*/
	lista_oferte->lista[pozitie].pret = pret_actualizat;
}

void sterge_oferta_din_lista(Listaoferte* lista_oferte, int pozitie)
{
	/*sterge o oferta din lista
	lista_oferte - Listaoferte
	pozitie - intreg
	pre: lista_oferte valida; pozite>=0, pozitie<=numar_oferte
	post: lista_oferte'-Listaoferte; lista_oferte' = lista_oferte-{oferta}
	*/
	Oferta* lista_noua = (Oferta*)malloc(lista_oferte->capacitate_lista * sizeof(Oferta));
	int pozitie_lista_noua = 0;
	for (int i = 0; i < lista_oferte->numar_oferte; i++)
		if (i != pozitie)
		{
			lista_noua[pozitie_lista_noua] = lista_oferte->lista[i];
			pozitie_lista_noua++;
		}
	distruge_oferta(&lista_oferte->lista[pozitie]);
	free(lista_oferte->lista);
	lista_oferte->lista = lista_noua;
	lista_oferte->numar_oferte--;
}