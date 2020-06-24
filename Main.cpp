#include "Listas/ListaEncadeada.h"
#include "Listas/ListaDuplamenteEncadeada.h"
#include "Listas/ListaCircularEncadeada.h"
#include "Pilha/Pilha.h"
#include "Fila/Fila.h"

#include "Menus.h"

int main(){
	// declaração de objetos TAD
	ListaEncadeada<int> le;
	ListaDuplamenteEncadeada<int> ld;
	ListaCircularEncadeada<int> lc;
	Pilha<int> pd;
	Fila<int> fd;

	// Demonstra as TADs
	Menus<int> executa(le, ld, lc, pd, fd);

	return 0;
}
