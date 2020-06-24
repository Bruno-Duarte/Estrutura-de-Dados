#ifndef MENUS_H
#define MENUS_H

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "Listas/ListaEncadeada.h"
#include "Listas/ListaDuplamenteEncadeada.h"
#include "Listas/ListaCircularEncadeada.h"
#include "Pilha/Pilha.h"
#include "Fila/Fila.h"
#include "Menus.h"

template<class Type>
class Menus {
public:
	Menus(ListaEncadeada<Type> le, ListaDuplamenteEncadeada<Type> ld,
	      ListaCircularEncadeada<Type> lc, Pilha<Type> pd,
		  Fila<Type> fd);

	void exibeMenuPrincipal();
	void menuListaEncadeada();
	void exibeMenuListaEncadeada();
	void menuListaDuplamenteEncadeada();
	void exibeMenuListaDuplamenteEncadeada();
	void menuListaCircularEncadeada();
	void exibeMenuListaCircularEncadeada();
	void menuPilha();
	void exibeMenuPilha();
	void menuFila();
	void exibeMenuFila();


	~Menus();

	ListaEncadeada<Type> le;
	ListaDuplamenteEncadeada<Type> ld;
	ListaCircularEncadeada<Type> lc;
	Pilha<Type> pd;
	Fila<Type> fd;
};

template<class Type>
Menus<Type>::Menus(ListaEncadeada<Type> le, ListaDuplamenteEncadeada<Type> ld,
	     ListaCircularEncadeada<Type> lc, Pilha<Type> pd,
	     Fila<Type> fd){

	this->le = le;
	this->ld = ld;
	this->lc = lc;
	this->pd = pd;
	this->fd = fd;

	char op[3];
	int opcao;

	do {
		exibeMenuPrincipal();
		cout << endl << "Introduza a opção desejada: ";
		cin >> op;
		opcao = atoi(op);
		switch(opcao){
			case 1:
			{
				menuListaEncadeada();
				break;
			}
			case 2:
			{
				menuListaDuplamenteEncadeada();
				break;
			}
			case 3:
			{
				menuListaCircularEncadeada();
				break;
			}
			case 4:
			{
				menuPilha();
				break;
			}
			case 5:
			{
				menuFila();
				break;
			}
			default:
				cout << ((opcao == 6) ? "\nSaindo do Programa...\n" : "\nOpção inválida!\n\n");
		}
	} while(opcao != 6);
}

template<class Type>
void Menus<Type>::exibeMenuPrincipal(){
	cout << endl << "IMPLEMENTAÇÃO DE LISTAS, PILHAS E FILAS DINÂMICAS" << endl << endl
	     << "1. Lista Simplesmente Encadeada" << endl
	     << "2. Lista Duplamente Encadeada" << endl
	     << "3. Lista Circular Encadeada" << endl
	     << "4. Pilha" << endl
	     << "5. Fila" << endl
	     << "6. SAIR" << endl;
}

template<class Type>
void Menus<Type>::menuListaEncadeada(){
	char op[3];
	int opcao;
	do {
		exibeMenuListaEncadeada();
		cout << endl << "Introduza a opção desejada: ";
		cin >> op;
		opcao = atoi(op);
		switch(opcao){
			case 1:
			{
				Type num1;
				cout << endl << "Insira um número inteiro: ";
				cin >> num1;
				le.add(num1);
				break;
			}
			case 2:
			{
				Type num2;
				cout << endl << "Insira um número inteiro: ";
				cin >> num2;
				le.addOrdenado(num2);
				break;
			}
			case 3:
			{
				Type num3;
				cout << endl << "Insira um número inteiro: ";
				cin >> num3;
				le.addFim(num3);
				break;
			}
			case 4:
			{
				if(!le.isEmpty()){
					cout << endl << "EXIBINDO LISTA" << endl;
					le.print();
				} else {
					cout << endl << "Não há elementos a ser exibido" 
					     << endl << endl;
				}
					break;
			}
			case 5:
			{
				cout << ((le.isEmpty() == true) ? "\nLista vazia\n" : "\nLista não vazia\n");
				break;
			}
			case 6:
			{
				Type num;
				cout << endl << "Que valor você deseja procurar?\n>>> ";
				cin >> num;
				cout << ((le.search(num)) ? "\nValor encontrado\n\n" : "\nValor não encontrado\n\n");
				break;
			}
			case 7:
			{
				int tam = le.size();
				cout << endl << "O tamanho da lista é " << tam << endl;
				break;
			}
			case 8:
			{
				cout << ((le.isEmpty() == true) ? "\nNão há elementos a ser removido\n\n" : "\nPrimeiro elemento removido\n\n");
				le.removeInicio();
				break;
			}
			case 9:
			{
				Type num;
				cout << endl << "Que valor você deseja remover?" 
				     << endl << ">>> ";
				cin >> num;
				le.remove(num);
				if(!le.isEmpty()){
					if(le.search(num)) {
						le.remove(num);
						cout << endl << "Elemento " << num << " removido" << endl;
					} else {
						cout << endl << "Elemento " << num << " não está na lista!" << endl;
					}
				} else {
					cout << endl << "Impossível remover de uma lista vazia" 
					     << endl << endl;
				}
				break;
			}
			case 10:
			{
				cout << ((le.isEmpty() == true) ? "\nNão há elementos a ser removido\n\n" : "\nÚltimo elemento removido\n\n");
				le.removeFim();
				break;
			}
			default:
				cout << ((opcao == 11) ? "\nVoltando...\n\n" : "\nOpção inválida!\n\n");
		}
	} while(opcao != 11);
}

template<class Type>
void Menus<Type>::exibeMenuListaEncadeada(){
	cout << endl << "MENU LISTA ENCADEADA" << endl << endl
	     << " 1. Adicionar valor no início da lista" << endl
	     << " 2. Adicionar valor ordenadamente na lista" << endl
	     << " 3. Adicionar valor no fim da lista" << endl
	     << " 4. Imprimir a lista" << endl
	     << " 5. Verificar se a lista está vazia" << endl
	     << " 6. Procurar valor" << endl
	     << " 7. Mostrar tamanho da lista" << endl
	     << " 8. Remover valor do início" << endl
	     << " 9. Remover um valor qualquer" << endl
	     << "10. Remover valor do final" << endl
	     << "11. Voltar" << endl << endl;
}

template<class Type>
void Menus<Type>::menuListaDuplamenteEncadeada(){
	char op[3];
	int opcao;
	do {
		exibeMenuListaDuplamenteEncadeada();
		cout << endl << "Introduza a opção desejada: ";
		cin >> op;
		opcao = atoi(op);
		switch(opcao){
			case 1:
			{
				Type num;
				cout << endl << endl << "Insira um número inteiro: ";
				cin >> num;
				ld.add(num);
				break;
			}
			case 2:
			{
				Type num;
				cout << endl << endl << "Insira um número inteiro: ";
				cin >> num;
				ld.addOrdenado(num);
				break;
			}
			case 3:
			{
				Type num;
				cout << endl << endl << "Insira um número inteiro: ";
				cin >> num;
				ld.addFim(num);
				break;
			}
			case 4:
			{
				if(!ld.isEmpty()){
					cout << endl << "EXIBINDO LISTA" << endl;
					ld.print();
				} else {
					cout << endl << "Não há elementos a ser exibido" 
					     << endl << endl;
				}
				break;
			}
			case 5:
			{
				if(!ld.isEmpty()){
					cout << endl << "EXIBINDO LISTA AO CONTRÁRIO" << endl;
					ld.reversePrint();
				} else {
					cout << endl << "Não há elementos a ser exibido" 
					     << endl << endl;
				}
				break;
			}
			case 6:
			{
				cout << ((ld.isEmpty() == true) ? "\nLista vazia\n": "\nLista não vazia\n");
				break;
			}
			case 7:
			{
				Type num;
				cout << endl << "Que valor você deseja procurar?"
				     << endl << ">>> ";
				cin >> num;
				cout << ((ld.search(num)) ? "\nValor encontrado\n\n" : "\nValor não encontrado\n\n");
				break;
			}
			case 8:
			{
				int tam = ld.size();
				cout << endl << "O tamanho da lista é " << tam << endl;
				break;
			}
			case 9:
			{
				if(!ld.isEmpty()){
					ld.removeInicio();
					cout << endl << endl << "Elemento removido do início" 
					     << endl;
				} else {
					cout << endl << "Impossível remover de uma lista vazia" 
					     << endl << endl;
				}
				break;
			}
			case 10:
			{
				Type num;
				cout << endl << "Que valor você deseja remover?"
				     << endl << ">>> ";
				cin >> num;
				if(!ld.isEmpty()){
					if(ld.search(num)) {
						ld.remove(num);
						cout << endl << "Elemento " << num << " removido" 
						     << endl;
					} else {
						cout << endl << "Elemento " << num << " não está na lista" << endl;
					}
				} else {
					cout << endl << "Impossível remover de uma lista vazia" 
					     << endl << endl;
				}
				break;
			}
			case 11:
			{
				if(!ld.isEmpty()){
					ld.removeFim();
					cout << endl << "Último elemento removido" << endl;
				} else {
					cout << endl << "Impossível remover de uma lista vazia" 
					     << endl;
				}
			}
			break;
			default:
				cout << ((opcao == 12) ? "\nVoltando...\n" : "\nOpção inválida!\n");
		}
	} while(opcao != 12);
}

template<class Type>
void Menus<Type>::exibeMenuListaDuplamenteEncadeada(){
	cout << endl << "MENU LISTA DUPLAMENTE ENCADEADA" << endl << endl
	     << " 1. Adicionar valor no início da lista" << endl
	     << " 2. Adicionar valor ordenadamente na lista" << endl
	     << " 3. Adicionar valor no fim da lista" << endl
	     << " 4. Imprimir lista" << endl
	     << " 5. Imprimir lista na ordem inversa" << endl
	     << " 6. Verificar se a lista está vazia" << endl
	     << " 7. Buscar valor" << endl
	     << " 8. Mostrar tamanho da lista" << endl
	     << " 9. Remover elemento do início" << endl
	     << "10. Remover um valor qualquer" << endl
	     << "11. Remover valor do final" << endl
	     << "12. Voltar" << endl;
}

template<class Type>
void Menus<Type>::menuListaCircularEncadeada(){
	char op[3];
	int opcao;
	do {
		exibeMenuListaCircularEncadeada();
		cout << endl << endl << "Introduza a opção desejada: ";
		cin >> op;
		opcao = atoi(op);
		switch(opcao){
			case 1:
			{
				Type num;
				cout << endl << "Insira um número inteiro: ";
				cin >> num;
				lc.add(num);
				break;
			}
			case 2:
			{
				Type num;
				cout << endl << "Insira um número inteiro: ";
				cin >> num;
				lc.addOrdenado(num);
				break;
			}
			case 3:
			{
				Type num;
				cout << endl << "Insira um número inteiro: ";
				cin >> num;
				lc.addFim(num);
				break;
			}
			case 4:
			{
				if(!lc.isEmpty()){
					cout << endl << "EXIBINDO LISTA" << endl;
					lc.print();
				} else {
					cout << endl << "Não há elementos a ser exibido" 
					     << endl << endl;
				}
				break;
			}
			case 5:
			{
				cout << ((!lc.isEmpty()) ? "\nLista vazia\n\n" : "\nLista não vazia\n\n");
				break;
			}
			case 6:
			{
				Type num;
				cout << endl << "Que valor você deseja buscar?" 
				     << endl << ">>> ";
				cin >> num;
				cout << ((lc.search(num) == false) ? "\nValor não encontrado\n\n" : "\nValor encontrado\n\n");
				break;
			}
			case 7:
			{
				int tam = lc.size();
				cout << endl << "O tamanho da lista é " << tam << endl << endl;
				break;
			}
			case 8:
			{
				if(!lc.isEmpty()){
					lc.removeInicio();
					cout << endl << "Elemento removido do início" << endl << endl;
				} else {
					cout << endl << "Impossível remover de uma lista vazia" 
					     << endl << endl;
				}
				break;
			}
			case 9:
			{
				Type num;
				cout << endl << "Que valor você deseja remover?" 
				     << endl << ">>> ";
				cin >> num;
				if(!lc.isEmpty()){
					if(lc.search(num)) {
						lc.remove(num);
						cout << endl << "Elemento " << num << " removido" << endl;
					} else {
						cout << endl << "Elemento " << num << " não está na lista!" << endl;
					}
				} else {
					cout << endl << "Impossível remover de uma lista vazia" 
					     << endl << endl;
				}
				break;
			}
			case 10:
			{
				if(lc.isEmpty()){
					lc.removeFim();
					cout << endl << "Último elemento removido" << endl;
				} else {
					cout << endl << "Impossível remover de uma lista vazia" 
					     << endl;
				}
				break;
			}
			default:
				cout << ((opcao == 11) ? "\nVoltando...\n" : "\nOpção inválida!\n\n");
		}
	} while(opcao != 11);
}

template<class Type>
void Menus<Type>::exibeMenuListaCircularEncadeada(){
	cout << endl << "MENU LISTA CIRCULAR ENCADEADA" << endl << endl
	     << " 1. Adicionar valor no início da lista" << endl
	     << " 2. Adicionar valor ordenadamente na lista" << endl
	     << " 3. Adicionar valor no fim da lista" << endl
	     << " 4. Imprimir lista" << endl
	     << " 5. Verificar se a lista está vazia" << endl
	     << " 6. Buscar valor" << endl
	     << " 7. Mostrar tamanho da lista" << endl
	     << " 8. Remover elemento do início" << endl
	     << " 9. Remover um valor qualquer" << endl
	     << "10. Remover valor do final" << endl
	     << "11. Voltar" << endl;
}

template<class Type>
void Menus<Type>::menuPilha(){
	char op[3];
	int opcao;
	do {
		exibeMenuPilha();
		cout << endl << endl << "Introduza a opção desejada: ";
		cin >> op;
		opcao = atoi(op);
		switch(opcao){
			case 1:
			{
				Type num;
				cout << endl << "Insira um número inteiro: ";
				cin >> num;
				pd.push(num);
				break;
			}
			case 2:
			{
				if(!pd.isEmpty())
					cout << endl << "O valor do topo da pilha é " 
					     << pd.top() << endl;
				else
					cout << endl << "Pilha vazia" << endl;
				break;
			}
			case 3:
			{
				cout << endl << "O tamanho da pilha é " << pd.size() << endl;
				break;
			}
			case 4:
			{
				if(!pd.isEmpty()){
					int num;
					cout << "Que valor você deseja buscar?" 
					     << endl << ">> ";
					cin >> num;
					cout << ((pd.search(num)) ? "\nElemento encontrado\n\n" : "\nElemento não encontrado\n\n");
			  } else {
					cout << "Impossível buscar em uma pilha vazia" 
					     << endl;
				}
				break;
			}
			case 5:
			{
				cout << ((pd.isEmpty()) ? "\nPilha vazia\n\n" : "\nPilha não vazia\n\n");
				break;
			}
			case 6:
			{
				if(pd.isEmpty()){
					cout << endl << "Pilha vazia" << endl;
				} else {
					cout << endl << "Pilha" << endl;
					pd.print();
				}
				break;
			}
			case 7:
			{
				if(!pd.isEmpty()){
					pd.pop();
					cout << endl << "Elemento removido" << endl;
				} else {
					cout << endl << "Impossível remover de uma pilha vazia" 
					     << endl;
				}
				break;
			}
			case 8:
			{
				if(!pd.isEmpty()){
					pd.clear();
					cout << endl << "A pilha foi apagada" << endl;
				} else {
					cout << endl << "Impossível apagar uma pilha não existente" 
					     << endl;
				}
				break;
			}
			default:
			cout << ((opcao == 9) ? "\nVoltando...\n" : "\nOpção inválida!\n\n");
		}
	} while(opcao != 9);
}

template<class Type>
void Menus<Type>::exibeMenuPilha(){
	cout << endl << "MENU PILHA DINÂMICA" << endl << endl
	     << "1. Adicionar valor na pilha" << endl
	     << "2. Consultar topo" << endl
	     << "3. Tamanho da pilha" << endl
	     << "4. Buscar elemento" << endl
	     << "5. Verificar se a pilha está vazia" << endl
	     << "6. Imprimir" << endl
	     << "7. Remover elemento" << endl
	     << "8. Apagar todos os elementos" << endl
	     << "9. Voltar" << endl;
}

template<class Type>
void Menus<Type>::menuFila(){
	char op[3];
	int opcao;
	do {
		exibeMenuFila();
		cout << endl << endl << "Introduza a opção desejada: ";
		cin >> op;
		opcao = atoi(op);
		switch(opcao){
			case 1:
			{
				Type num;
				cout << endl << "Insira um número inteiro: ";
				cin >> num;
				fd.enqueue(num);
				break;
			}
			case 2:
			{
				if(!fd.isEmpty())
					cout << endl << "O primeiro elemento é " 
					     << fd.front() << endl;
				else
					cout << endl << "Fila vazia" << endl;
				break;
			}
			case 3:
			{
				if(!fd.isEmpty())
					cout << endl << "O último elemento é " 
					     << fd.back() << endl;
				else
					cout << endl << "Fila vazia" << endl;
				break;
			}
			case 4:
			{
				cout << endl << "O tamanho da fila é " 
				     << fd.size() << endl;
				break;
			}
			case 5:
			{
				if(!fd.isEmpty()){
					Type num;
					cout << endl << "Que valor você deseja buscar?\n>> ";
					cin >> num;
					cout << ((fd.search(num) == true) ? "\nElemento encontrado\n\n" : "\nElemento não encontrado\n");
			  } else {
					cout << endl << "Impossível buscar em um fila inexistente" 
					     << endl << endl;
				}
				break;
			}
			case 6:
			{
				cout << ((fd.isEmpty() == true) ? "\nFila vazia\n\n" : "\nFila não vazia\n\n");
				break;
			}
			case 7:
			{
				if(fd.isEmpty()){
					cout << endl << "Fila vazia" << endl;
				} else {
					cout << endl << "Fila" << endl;
					fd.print();
				}
				break;
			}
			case 8:
			{
				if(!fd.isEmpty()){
					fd.dequeue();
					cout << endl << "Elemento removido" << endl;
				} else {
					cout << endl << "Impossível remover de uma fila vazia" 
					     << endl;
				}
				break;
			}
			case 9:
			{
				if(!fd.isEmpty()){
					fd.clear();
					cout << endl << "A fila foi apagada" << endl;
				} else {
					cout << endl << "Impossível apagar de uma fila inexistente" 
					     << endl;
				}
				break;
			}
			default:
			cout << ((opcao == 10) ? "\nVoltando...\n" : "\nOpção inválida!\n\n");
		}
	} while(opcao != 10);
}

template<class Type>
void Menus<Type>::exibeMenuFila(){
	cout << endl << "MENU FILA DINÂMICA" << endl << endl
	     << " 1. Adicionar valor na fila" << endl
	     << " 2. Consultar primeiro" << endl
	     << " 3. Consultar último" << endl
	     << " 4. Tamanho da fila" << endl
	     << " 5. Buscar elemento" << endl
	     << " 6. Verificar se a fila está vazia" << endl
	     << " 7. Imprimir" << endl
	     << " 8. Remover elemento" << endl
	     << " 9. Apagar todos elementos" << endl
	     << "10. Voltar" << endl;
}

template<class Type>
Menus<Type>::~Menus(){ };

#endif
