#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "teste.h"
#include "Oferta.h"
#include "listaoferta.h"
#include "service.h"



void test_creeaza_distruge_oferta()
{
	//functie de test pentru crearea si distrugerea unei oferte
	char test_tip[15] = "casa", test_adresa[15] = "strada ploiesti";
	int test_pret ,test_suprafata;
	test_suprafata = 500;
	test_pret = 10000;

	
	Oferta oferta_1= creeaza_oferta(test_tip, test_adresa, test_suprafata,test_pret);
	assert(strcmp(oferta_1.tip, test_tip) == 0);
	assert(strcmp(oferta_1.adresa, test_adresa) == 0);
	assert(oferta_1.suprafata==test_suprafata);
	assert(oferta_1.pret==test_pret);
	
	

	distruge_oferta(&oferta_1);
	assert(oferta_1.tip == NULL);
	assert(oferta_1.adresa == NULL);
	assert(oferta_1.pret == -1);
	assert(oferta_1.suprafata = -1);


}

void test_valideaza_oferta()
{
	//functie de test pentru validarea unei oferte

	char test_tip[30] , test_adresa[30] ;
	int test_pret , test_suprafata ;

	strcpy(test_tip, "casa");
	strcpy(test_adresa, "strada ploiesti");
	test_suprafata = 500;
	test_pret = 9800;
	Oferta oferta_1 = creeaza_oferta(test_tip, test_adresa, test_suprafata, test_pret);
	assert(valideaza_oferta(&oferta_1) == 0);
	distruge_oferta(&oferta_1);
	
	strcpy(test_tip, "");
	strcpy(test_adresa, "str andronescu");
	test_suprafata = 500;
	test_pret = 9800;
	Oferta oferta_2 = creeaza_oferta(test_tip, test_adresa, test_suprafata, test_pret);
	assert(valideaza_oferta(&oferta_2) == 1);
	distruge_oferta(&oferta_2);

	strcpy(test_tip, "apartament");
	strcpy(test_adresa, "");
	test_suprafata = 500;
	test_pret = 9800;
	Oferta oferta_3 = creeaza_oferta(test_tip, test_adresa, test_suprafata, test_pret);
	assert(valideaza_oferta(&oferta_3) == 2);
	distruge_oferta(&oferta_3);
	

	strcpy(test_tip, "teren");
	strcpy(test_adresa, "str ploiesti");
	test_suprafata = -1;
	test_pret = 5000;
	Oferta oferta_4 = creeaza_oferta(test_tip, test_adresa, test_suprafata, test_pret);
	assert(valideaza_oferta(&oferta_4) == 4);
	distruge_oferta(&oferta_4);

	strcpy(test_tip, "teren");
	strcpy(test_adresa, "str ploiesti");
	test_suprafata = 100;
	test_pret = -5;
	Oferta oferta_5 = creeaza_oferta(test_tip, test_adresa, test_suprafata, test_pret);
	assert(valideaza_oferta(&oferta_5) == 3);
	distruge_oferta(&oferta_5);
}


void test_creeaza_distruge_lista()
{
	//functie de test pentru crearea si distrugerea unei liste
	Listaoferte lista_oferte = creeaza_lista_oferte(10);
	assert(lista_oferte.numar_oferte == 0);
	distruge_lista_oferte(&lista_oferte);
}

void test_adauga_oferta_in_lista()
{
	//functie de test pentru adaugarea unei oferte in lista
	Listaoferte lista_oferte = creeaza_lista_oferte(2);
	assert(lista_oferte.numar_oferte == 0);

	char test_tip[30], test_adresa[30];
	int test_suprafata,test_pret;

	strcpy(test_tip, "casa");
	strcpy(test_adresa, "aa");
	test_pret = 56;
	test_suprafata = 80;
	Oferta oferta_1 = creeaza_oferta(test_tip, test_adresa, test_suprafata,test_pret);
	adauga_oferta_in_lista(&lista_oferte, oferta_1);

	assert(lista_oferte.numar_oferte == 1);

	strcpy(test_tip, "apartament");
	strcpy(test_adresa, "bb");
	test_pret = 56;
	test_suprafata = 80;
	Oferta oferta_2 = creeaza_oferta(test_tip, test_adresa, test_suprafata, test_pret);
	adauga_oferta_in_lista(&lista_oferte, oferta_2);

	assert(lista_oferte.numar_oferte == 2);

	Oferta offer = returneaza_oferta_de_pe_pozitie(&lista_oferte, 0);
	assert(strcmp(offer.tip, "casa") == 0);
	assert(strcmp(offer.adresa, "aa") == 0);
	Oferta oferta_5 = returneaza_oferta_de_pe_pozitie(&lista_oferte, 1);
	assert(strcmp(oferta_5.tip, "apartament") == 0);
	assert(strcmp(oferta_5.adresa, "bb") == 0);

	strcpy(test_tip, "c");
	strcpy(test_adresa, "c");
	test_pret = 56;
	test_suprafata = 80;
	Oferta oferta_3 = creeaza_oferta(test_tip, test_adresa, test_suprafata,test_pret);
	adauga_oferta_in_lista(&lista_oferte, oferta_3);

	assert(lista_oferte.numar_oferte == 3);
	assert(lista_oferte.capacitate_lista == 4);

	distruge_lista_oferte(&lista_oferte);
}

void test_cauta_oferta_in_lista()
{
	//functie de test pentru cautarea unei oferte in lista
	Listaoferte lista_oferte = creeaza_lista_oferte(2);
	assert(lista_oferte.numar_oferte == 0);
	char test_tip[30], test_adresa[30];
	int test_pret,test_suprafata;
	strcpy(test_tip, "casa");
	strcpy(test_adresa, "aa");
	test_pret = 56;
	test_suprafata = 80;
	Oferta oferta_1 = creeaza_oferta(test_tip, test_adresa, test_suprafata,test_pret);
	adauga_oferta_in_lista(&lista_oferte, oferta_1);
	assert(lista_oferte.numar_oferte == 1);

	int pozitie_oferta_gasita = cauta_oferta_in_lista(&lista_oferte, oferta_1);
	assert(pozitie_oferta_gasita == 0);

	strcpy(test_tip, "apartament");
	strcpy(test_adresa, "bb");
	test_pret = 56;
	test_suprafata = 80;
	Oferta oferta_2 = creeaza_oferta(test_tip, test_adresa, test_suprafata,test_pret);

	pozitie_oferta_gasita = cauta_oferta_in_lista(&lista_oferte, oferta_2);
	assert(pozitie_oferta_gasita == -1);

	distruge_lista_oferte(&lista_oferte);
	distruge_oferta(&oferta_2);
}

void test_actualizare_oferta()
{
	//functie de test pentru actualizarea pretului unei oferte din lista
	Listaoferte lista_oferte = creeaza_lista_oferte(2);
	assert(lista_oferte.numar_oferte == 0);
	char test_tip[30], test_adresa[30];
	int test_pret,test_suprafata;
	strcpy(test_tip, "casa");
	strcpy(test_adresa, "aa");
	test_pret = 56;
	test_suprafata = 80;
	Oferta oferta_1 = creeaza_oferta(test_tip, test_adresa, test_suprafata,test_pret);
	adauga_oferta_in_lista(&lista_oferte, oferta_1);
	assert(lista_oferte.numar_oferte == 1);
	strcpy(test_tip, "apartament");
	strcpy(test_adresa, "bb");
	test_pret = 56;
	test_suprafata = 80;
	Oferta oferta_2 = creeaza_oferta(test_tip, test_adresa, test_suprafata,test_pret);
	adauga_oferta_in_lista(&lista_oferte, oferta_2);
	assert(lista_oferte.numar_oferte == 2);

	int pozitie_cautata = cauta_oferta_in_lista(&lista_oferte, oferta_2);
	assert(pozitie_cautata == 1);
	actualizare_oferta(&lista_oferte, 66, pozitie_cautata);

	Oferta oferta_actualizata = returneaza_oferta_de_pe_pozitie(&lista_oferte, pozitie_cautata);
	assert(oferta_actualizata.pret == 66);

	distruge_lista_oferte(&lista_oferte);
}

void test_sterge_oferta()
{
	//functie de test pentru stergerea unei oferte din lista
	Listaoferte lista_oferte = creeaza_lista_oferte(2);
	assert(lista_oferte.numar_oferte == 0);
	char test_tip[30], test_adresa[30];
	int test_pret,test_suprafata;
	strcpy(test_tip, "casa");
	strcpy(test_adresa, "aa");
	test_pret = 56;
	test_suprafata = 80;
	Oferta oferta_1 = creeaza_oferta(test_tip, test_adresa, test_suprafata,test_pret);
	adauga_oferta_in_lista(&lista_oferte, oferta_1);
	assert(lista_oferte.numar_oferte == 1);
	strcpy(test_tip, "apartament");
	strcpy(test_adresa, "bb");
	test_suprafata = 66;
	test_pret = 80;
	Oferta oferta_2 = creeaza_oferta(test_tip, test_adresa, test_suprafata,test_pret);
	adauga_oferta_in_lista(&lista_oferte, oferta_2);
	assert(lista_oferte.numar_oferte == 2);
	strcpy(test_tip, "c");
	strcpy(test_adresa, "cc");
	test_suprafata = 76;
	test_pret = 80;
	Oferta oferta_3 = creeaza_oferta(test_tip, test_adresa, test_suprafata,test_pret);
	adauga_oferta_in_lista(&lista_oferte, oferta_3);
	assert(lista_oferte.numar_oferte == 3);

	sterge_oferta_din_lista(&lista_oferte, 1);
	assert(lista_oferte.numar_oferte == 2);

	int pozitie_cautat = cauta_oferta_in_lista(&lista_oferte, oferta_2);
	assert(pozitie_cautat == -1);

	distruge_lista_oferte(&lista_oferte);
}

void test_service_adauga()
{
	//functie de test pentru service-ul de adaugare a unei oferte

	Listaoferte lista_oferte = creeaza_lista_oferte(2);
	char test_tip[30], test_adresa[30];
	int test_suprafata, succes_adaugare_oferta,test_pret;
	strcpy(test_tip, "casa");
	strcpy(test_adresa, "aa");
	test_suprafata = 56;
	test_pret = 80;

	assert(lista_oferte.numar_oferte == 0);
	succes_adaugare_oferta = service_adauga_oferta(&lista_oferte, test_tip, test_adresa, test_suprafata,test_pret);
	assert(succes_adaugare_oferta == 0);
	assert(lista_oferte.numar_oferte == 1);
	strcpy(test_tip, "");
	strcpy(test_adresa, "aa");
	test_suprafata = 56;
	test_pret = 80;
	succes_adaugare_oferta = service_adauga_oferta(&lista_oferte, test_tip, test_adresa, test_suprafata,test_pret);
	assert(succes_adaugare_oferta == 1);
	assert(lista_oferte.numar_oferte == 1);
	strcpy(test_tip, "casa");
	strcpy(test_adresa, "");
	test_suprafata = 56;
	test_pret = 80;
	succes_adaugare_oferta= service_adauga_oferta(&lista_oferte, test_tip, test_adresa, test_suprafata,test_pret);
	assert(succes_adaugare_oferta == 2);
	assert(lista_oferte.numar_oferte == 1);
	strcpy(test_tip, "casa");
	strcpy(test_adresa, "aa");
	test_suprafata = 56;
	test_pret = -3;
	succes_adaugare_oferta = service_adauga_oferta(&lista_oferte, test_tip, test_adresa, test_suprafata,test_pret);
	assert(succes_adaugare_oferta == 3);
	assert(lista_oferte.numar_oferte == 1);
	/**strcpy(test_tip, "casa");
	strcpy(test_adresa, "aa");
	test_suprafata = 56;
	test_pret = 80;
	succes_adaugare_oferta = service_adauga_oferta(&lista_oferte, test_tip, test_adresa, test_suprafata,test_pret);
	assert(succes_adaugare_oferta == 0);
	assert(lista_oferte.numar_oferte == 2);
	assert(lista_oferte.lista[0].pret == 112);*/


	distruge_lista_oferte(&lista_oferte);
}

void test_service_actualizare_oferta()
{
	//functie de test pentru service-ul de actualizare a unei oferte
	Listaoferte lista_oferte = creeaza_lista_oferte(2);
	char test_tip[30], test_adresa[30];
	int test_suprafata, test_pret,succes_adaugare_oferta;
	strcpy(test_tip, "casa");
	strcpy(test_adresa, "aa");
	test_suprafata = 56;
	test_pret = 80;

	assert(lista_oferte.numar_oferte == 0);
	succes_adaugare_oferta = service_adauga_oferta(&lista_oferte, test_tip, test_adresa, test_suprafata,test_pret);
	assert(succes_adaugare_oferta == 0);
	assert(lista_oferte.numar_oferte == 1);
	int succes_actualizare_pret;
	succes_actualizare_pret = service_actualizare_oferta(&lista_oferte, test_tip, test_adresa,78,test_suprafata);
	assert(succes_actualizare_pret== 0);
	assert(lista_oferte.lista[0].pret == 78);
	strcpy(test_tip, "apartament");
	strcpy(test_adresa, "bb");
	succes_actualizare_pret = service_actualizare_oferta(&lista_oferte, test_tip, test_adresa, 78,test_suprafata);
	assert(succes_actualizare_pret == -1);

	distruge_lista_oferte(&lista_oferte);
}

void test_service_sterge_oferta()
{
	//functie de test pentru service-ul de stergere a unei oferte
	Listaoferte lista_oferte = creeaza_lista_oferte(2);
	char test_tip[30], test_adresa[30];
	int test_suprafata, test_pret,succes_adaugare_oferta;
	strcpy(test_tip, "casa");
	strcpy(test_adresa, "aa");
	test_suprafata = 56;
	test_pret = 80;

	assert(lista_oferte.numar_oferte == 0);
	succes_adaugare_oferta = service_adauga_oferta(&lista_oferte, test_tip, test_adresa, test_suprafata,test_pret);
	assert(succes_adaugare_oferta == 0);
	assert(lista_oferte.numar_oferte == 1);
	strcpy(test_tip, "apartament");
	strcpy(test_adresa, "bb");
	test_suprafata = 56;
	test_pret = 80;
	succes_adaugare_oferta = service_adauga_oferta(&lista_oferte, test_tip, test_adresa, test_suprafata,test_pret);
	assert(succes_adaugare_oferta == 0);
	assert(lista_oferte.numar_oferte == 2);

	int succes_stergere_oferta;
	succes_stergere_oferta= service_sterge_oferta(&lista_oferte, "casa", "aa",test_suprafata);
	assert(succes_stergere_oferta == 0);
	assert(lista_oferte.numar_oferte == 1);
	succes_stergere_oferta = service_sterge_oferta(&lista_oferte, test_tip, test_adresa,test_suprafata);
	assert(succes_stergere_oferta == 0);
	assert(lista_oferte.numar_oferte == 0);
	succes_stergere_oferta = service_sterge_oferta(&lista_oferte, test_tip, test_adresa);
	assert(succes_stergere_oferta == -1);
	assert(lista_oferte.numar_oferte == 0);

	distruge_lista_oferte(&lista_oferte);
}

void test_service_filtrare_oferte()
{
	char test_tip[30], test_adresa[30];
	int test_suprafata, test_pret, succes_adaugare_oferta;
	strcpy(test_tip, "casa");
	strcpy(test_adresa, "aa");
	test_suprafata = 56;
	test_pret = 80;
	Listaoferte lista_oferte = creeaza_lista_oferte(3);
	assert(lista_oferte.numar_oferte == 0);
	succes_adaugare_oferta = service_adauga_oferta(&lista_oferte, test_tip, test_adresa, test_suprafata, test_pret);
	strcpy(test_tip, "apartament");
	strcpy(test_adresa, "bb");
	test_suprafata = 56;
	test_pret = 80;
	succes_adaugare_oferta = service_adauga_oferta(&lista_oferte, test_tip, test_adresa, test_suprafata, test_pret);
	strcpy(test_tip, "apartament");
	strcpy(test_adresa, "cfgjnh");
	test_suprafata = 56;
	test_pret = 80;
	succes_adaugare_oferta = service_adauga_oferta(&lista_oferte, test_tip, test_adresa, test_suprafata, test_pret);
	Listaoferte lista_filtrata = filteroffers(&lista_oferte, "casa");
	assert(lista_filtrata.numar_oferte == 1);
	Listaoferte lista_filtrata_2 = filteroffers(&lista_oferte, "apartament");
	assert(lista_filtrata_2.numar_oferte == 2);
	distruge_lista_oferte(&lista_oferte);
	distruge_lista_oferte(&lista_filtrata);
	distruge_lista_oferte(&lista_filtrata_2);
}

void test_copiaza_lista() 
{
	Listaoferte l1 = creeaza_lista_oferte(2);
	service_adauga_oferta(&l1, "casa","loo","500","80");
	service_adauga_oferta(&l1, "apartament", "loo", "500", "80");

	assert(l1.numar_oferte == 2);
	Listaoferte l2 = copiaza_lista_oferte(&l1);
	assert(l2.numar_oferte == 2);
	Oferta of = returneaza_oferta_de_pe_pozitie(&l2, 0);
	assert(strcmp(of.tip, "casa") == 0);

	distruge_lista_oferte(&l1);
	distruge_lista_oferte(&l2);

}

void test_comparare()
{
	Oferta offer_1 = creeaza_oferta("casa", "ploiesti", 500, 200);
	Oferta offer_2 = creeaza_oferta("apartament", "ploiesti", 500, 150);
	Oferta offer_3 = creeaza_oferta("teren", "ploiesti", 100, 50);
	int verif_1 = comparare_pret(&offer_1, &offer_2, 1);
	assert(verif_1 == 1);
	int verif_2 = comparare_pret(&offer_1, &offer_2, 0);
	assert(verif_2 == 0);
	int verif_3 = comparare_tip(&offer_1, &offer_2, 1);
	assert(verif_3 == 1);
	int verif_4 = comparare_tip(&offer_2, &offer_3, 0);
	assert(verif_4 == 1);
	int verif_5 = comparare_pret(&offer_3, &offer_2, 1);
	assert(verif_5 == 0);
	int verif_6 =comparare_tip(&offer_3, &offer_1, 0);
	assert(verif_6 == 0);
	distruge_oferta(&offer_1);
	distruge_oferta(&offer_2);
	distruge_oferta(&offer_3);
	
}

void test_sortare()
{
	Listaoferte l1 = creeaza_lista_oferte(2);
	service_adauga_oferta(&l1, "casa", "loo", 500, 80);
	service_adauga_oferta(&l1, "apartament", "loo", 500, 700);
	service_adauga_oferta(&l1, "teren", "ghv", 540, 89);
	assert(l1.numar_oferte==3);
	Listaoferte lstsort = sortare(&l1, 0,comparare_pret);
	Listaoferte lstsort_1 = sortare(&l1, 1,comparare_tip);
	assert(strcmp(returneaza_oferta_de_pe_pozitie(&lstsort, 0).tip,"apartament")==0);
	assert(returneaza_oferta_de_pe_pozitie(&lstsort, 1).pret == 89);
	assert(strcmp(returneaza_oferta_de_pe_pozitie(&lstsort_1, 0).adresa, "loo")==0);
	assert(returneaza_oferta_de_pe_pozitie(&lstsort_1, 1).pret == 80);
	distruge_lista_oferte(&lstsort);
	distruge_lista_oferte(&lstsort_1);
	distruge_lista_oferte(&l1);

}

void ruleaza_toate_testele()
{
	test_creeaza_distruge_lista();
	test_valideaza_oferta();
	test_adauga_oferta_in_lista();
	test_cauta_oferta_in_lista();
	test_actualizare_oferta();
	test_sterge_oferta();
	test_service_adauga();
	test_service_actualizare_oferta();
	test_service_sterge_oferta();
	test_service_filtrare_oferte();
	test_copiaza_lista();
	test_comparare();
	test_sortare();
}