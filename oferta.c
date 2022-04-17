#include "oferta.h"
#include <string.h>
#include <stdlib.h>


Oferta creeaza_oferta(char* tip, char* adresa, int suprafata,int pret)
{
	/*creeaza o noua oferta
	* tip,adresa - string; pret,suprafata - intreg
	* oferta - Oferta
	* pre: tip si adresa sa nu fie stringul vid,tipul sa fie-teren,casa sau apartament, pret si suprafata sa nu fie <=0
	* post: oferta - valida
	*/
	Oferta offer;
	int lungime_tip, lungime_adresa;
	lungime_tip = strlen(tip) + 1;
	lungime_adresa = strlen(adresa) + 1;
	offer.tip = (char*)malloc(lungime_tip * sizeof(char));
	strcpy(offer.tip, tip);
	offer.adresa = (char*)malloc(lungime_adresa * sizeof(char));
	strcpy(offer.adresa, adresa);
	offer.suprafata = suprafata;
	offer.pret = pret;
	return offer;

}

void distruge_oferta(Oferta* offer)
{
	/*distruge oferta existenta (elibereaza memoria alocata)
	offer - Oferta
	pre: offer - valida
	post: spatiul de memorie eliberat
	*/
	free(offer->tip);
	free(offer->adresa);

	offer->tip = NULL;
	offer->adresa = NULL;
	offer->suprafata = -1;
	offer->pret = -1;
}

int valideaza_oferta(Oferta* offer)
{

	/*valideaza oferta existenta
	offer- Oferta
	pre: offer - valida
	post: valideaza_oferta = 1, daca tipul este invalid
							2, daca adresa este invalida
							3, daca pretul este invalid
							4,daca suprafata este invalida
							0, daca oferta este valida
	*/
	int tip_invalid = 1, adresa_invalida = 2, pret_invalid = 3, supraf_invalida=4,oferta_valida = 0;
	if (strcmp(offer->adresa, "") == 0)
		return adresa_invalida;
	if (strcmp(offer->tip, "teren")!= 0 && strcmp(offer->tip, "apartament")!=0 && strcmp(offer->tip, "casa")!=0)
		return tip_invalid;
	if (offer->pret < 0)
		return pret_invalid;
	if (offer->suprafata <= 0)
		return supraf_invalida;
	return oferta_valida;

}

int verifica_egalitate_intre_oferte(Oferta oferta_1, Oferta oferta_2)
{
	/*verifica daca doua oferte sunt identice
	pre: oferta_1, oferta_2 - valide
	post: verifica_egalitate_intre_oferte = 1, ofertele sunt identice
												  0, altfefl
	*/
	int oferte_identice = 1, oferte_diferite = 0;
	if (strcmp(oferta_1.tip, oferta_2.tip) == 0 && strcmp(oferta_1.adresa, oferta_2.adresa) == 0 && oferta_1.suprafata==oferta_2.suprafata)
		return oferte_identice;
	return oferte_diferite;
}

Oferta copiaza_oferta(Oferta* offer)
{
	/*copiaza atributele unei oferte
	offer- Oferta
	pre: offer - valida
	*/
	return creeaza_oferta(offer->tip, offer->adresa, offer->suprafata,offer->pret);
}