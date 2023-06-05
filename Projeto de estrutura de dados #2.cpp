#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//estrutura de dados principal do projeto
struct produto
{
	string nome;
	string desc;
	float preco;
	int quantidade;
};

//SORT STRINGS
//Funcao booleana de retorno para checar a ordem decrescente de strings usando a funcao padrao sort()
bool compareProdutoDec(const produto &prod1, const produto &prod2)
{
    if(prod2.nome < prod1.nome)
    {
    	return 1;
	}
	else
	{
    	return 0;
	}
}
//Funcao booleana de retorno para checar a ordem crescente de strings usando a funcao padrao sort()
bool compareProdutoCrec(const produto &prod1, const produto &prod2)
{
    if(prod2.nome > prod1.nome)
    {
    	return 1;
	}
	else
	{
    	return 0;
	}
}

//BUSCAS
//Busca binaria que trabalha com variaveis inteiras dentro da struct produto
int binarySearchInt(produto arr[], int l, int r, int x)
{
    while (l <= r) 
	{
        int m = l + (r - l) / 2;
 
        if (arr[m].preco == x)
        {
			return m;
		}
        if (arr[m].preco < x)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return -1;
}

//Busca binaria que trabalha com variaveis strings dentro da struct produto
int binarySearchString(produto arr[], string x,int n)
{
    int l = 0 ;
    int r = n - 1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
 
		int res = -1000;   
		
        if (x == (arr[m].nome))
        {
            res = 0;
    	}
        if (res == 0)
        {
            return m;
        }
        if (x > (arr[m].nome))
        {
            l = m + 1;
    	}
    	else
        {
            r = m - 1;
        }
    }
    return -1;
}

//Busca linear que trabalha com variaveis strings dentro da struct produto
int linearSearchString(produto arr[], int N, string x)
{
    for (int i = 0; i < N; i++)
    {
        if (arr[i].nome == x)
        {
            return i;
        }
    }
	return -1;
}

//HEAP SORT INT DECRESCENTE
//As funcoes abaixo sao as funcoes para o heap sort de inteiros dentro da struct produto em ordem decrescente
void heapifyDec(produto arr[], int N, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    
    if (l < N && arr[l].preco < arr[largest].preco)
    {
        largest = l;
    }

    if (r < N && arr[r].preco < arr[largest].preco)
    {
        largest = r;
    }

    if (largest != i)
	{
        swap(arr[i], arr[largest]);
        heapifyDec(arr, N, largest);
    }
}

void heapSortDec(produto arr[], int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
    {
        heapifyDec(arr, N, i);
	}

    for (int i = N - 1; i > 0; i--)
	{
        swap(arr[0], arr[i]);
        heapifyDec(arr, i, 0);
    }
}

//HEAP SORT INT CRESCENTE
//As funcoes abaixo sao as funcoes para o heap sort de inteiros dentro da struct produto em ordem decrescente
void heapify(produto arr[], int N, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    
    if (l < N && arr[l].preco > arr[largest].preco)
    {
        largest = l;
    }

    if (r < N && arr[r].preco > arr[largest].preco)
    {
        largest = r;
    }

    if (largest != i)
	{
        swap(arr[i], arr[largest]);
        heapify(arr, N, largest);
    }
}

void heapSort(produto arr[], int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
    {
        heapify(arr, N, i);
	}

    for (int i = N - 1; i > 0; i--)
	{
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

//PRINTS
//Funcao para imprimir todos os produtos de um array dando preferencia para o nome
void printProdutosN(produto prdts[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		cout << i + 1;
		cout << "-----------" << endl;
		cout << "Nome      : " << prdts[i].nome << endl;
		cout << "Descricao : " << prdts[i].desc << endl;
		cout << "Preco     : " << prdts[i].preco << endl;
		cout << "Quantidade: " << prdts[i].quantidade << endl;
		cout << endl;
	}
	cout << endl;
}
//Funcao para imprimir todos os produtos de um array dando preferencia para o preco
void printProdutosP(produto prdts[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		cout << i + 1;
		cout << "-----------" << endl;
		cout << "Preco     : " << prdts[i].preco << endl;
		cout << "Nome      : " << prdts[i].nome << endl;
		cout << "Descricao : " << prdts[i].desc << endl;
		cout << "Quantidade: " << prdts[i].quantidade << endl;
		cout << endl;
	}
	cout << endl;
}
//Funcao para imprimir um produto especifico usando sua posicao(index) no array
void printBusca(produto prdts[], int index)
{
	cout << "Produto encontrado:" << endl;
	cout << "Nome      : " << prdts[index].nome << endl;
	cout << "Descricao : " << prdts[index].desc << endl;
	cout << "Preco     : " << prdts[index].preco << endl;
	cout << "Quantidade: " << prdts[index].quantidade << endl;
}
//Funcao que retorna um produto para a substituicao de um produto dentro de um array
produto updateProduto(produto prod[], int index)
{
	produto tempp;
					
	cout << "Digite as novas informacoes do produto:" << endl;
	cout << "Nome       - ";
	cin >> tempp.nome;
	cout << "Descricao  - ";
	cin >> tempp.desc;
	cout << "Preco      - ";
	while(!(cin >> tempp.preco))
	{
	    cout << "Comando invalido, tente de novo: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cout << "Quantidade - ";
	while(!(cin >> tempp.quantidade))
	{
	    cout << "Comando invalido, tente de novo: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	return tempp;
}

int main()
{
	vector<produto> prdts;//Vetor principal para todas as operacoes com a struct produto
	int esc, menu;
	
	while(1)
	{
		system("cls");
		cout << "  _____                                           _        _    TM" << endl;
		cout << " |_   _|                                         | |      | |  " << endl;
		cout << "   | |  ___  __ _  __ _  ___ _ __ ___   __ _ _ __| | _____| |_ " << endl;
		cout << "   | | / __|/ _` |/ _` |/ __| '_ ` _ \\ / _` | '__| |/ / _ \\ __|" << endl;
		cout << "  _| |_\\__ \\ (_| | (_| | (__| | | | | | (_| | |  |   <  __/ |_ " << endl;
		cout << " |_____|___/\\__,_|\\__,_|\\___|_| |_| |_|\\__,_|_|  |_|\\_\\___|\\__|" << endl << endl << endl;
		cout << "1 - Inserir produto manualmente" << endl;//case 1
		cout << "2 - Fazer upload de arquivo" << endl;//case 2
		cout << "3 - Buscar produto" << endl;//case3
		cout << "4 - Remover produto" << endl;//case4
		cout << "5 - Atualizar produto" << endl;//case5
		cout << "6 - Imprimir" << endl;//case6
		cout << "7 - Sair" << endl;//case7
		
		/*Essa logica while ira se repetir inumeras vezes durante o restante do codigo.
		Ela serve para fazer um tratamento de dados de entrada, permitindo somente inteiros
		suportados pelo buffer de entrada e em um certo intervalo de serem considerados.
		Ou seja, tem a principal funcao de proteger o codigo de quebrar recebendo um inteiro
		fora do intervalo de escolhas ou outras variaveis. O que tambem torna o uso do default
		em switches desnecessario, ja que o dado de entrada nunca ira sair do intervalo posto no while*/
		while(!(cin >> menu) || menu > 7 || menu < 1)
		//    ^^^^^^^^^^^^^     ^^^^^^^^    ^^^^^^^^
		//    protege o         maior num   menor num
		//    buffer                do intervalo 
		{
	        cout << "Comando invalido, tente de novo: ";
	        cin.clear();
	        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
		
		switch(menu)
		{
			case 1:
				{
					produto tempp;//Criacao de um produto temporario para o pushback no vector
					//Interacao com o usuario e entrada de dados
					system("cls");
					cout << "Digite as informacoes do produto:" << endl;
					cout << "Nome       - ";
					cin >> tempp.nome;
					cout << "Descricao  - ";
					cin >> tempp.desc;
					cout << "Preco      - ";
					while(!(cin >> tempp.preco))
					{
					    cout << "Comando invalido, tente de novo: ";
				        cin.clear();
				        cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
					cout << "Quantidade - ";
					while(!(cin >> tempp.quantidade))
					{
					    cout << "Comando invalido, tente de novo: ";
				        cin.clear();
				        cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
					
					prdts.push_back(tempp);
					
					cout << "Produto inserido com sucesso!" << endl;
					system("pause");	
				}
				break;
			case 2:
				{
					produto temppp;
					string line, preco, quantidade;//Strings necessarias para a leitura de dados do arquivo CSV
					
					system("cls");
					cout << "Nome necessario do arquivo: Isaacmarket" << endl;
					system("pause");
				    
				    ifstream file;//Criacao da variavel que armazena o arquivo CSV
				
				    file.open("Isaacmarket.csv");
				
				    if(!file.is_open())
					{
				        cout << "Arquivo nao encontrado!" << endl;
				        system("pause");
				        break;
				    }
					for (produto temppp; getline(file, temppp.nome, ';')//Enquanto o ainda tiver linhas para ler 
					&& getline(file, temppp.desc, ';')                  //o codigo continuara lendo o arquivo 
					&& getline(file, preco, ';')                        //e armazenando seus dados em strings
					&& getline(file, quantidade); )                     
					{
						temppp.preco = stof(preco);//Converte os dados de preco de string para float
						temppp.quantidade = stoi(quantidade);//Converte os dados de quantidade de string para int
				    	prdts.push_back(temppp);//Pushback de todos os dados lidos como produto no vector
					}
					
					cout << "Produtos inseridos com sucesso!" << endl;
					system("pause");
				}
				break;
			
			case 3:
				{
					int index;
					string nomep;
					
					int n = prdts.size();//Um array e criado para facilitar operacoes 
					produto arr[n];      //de impressao, sort e busca
				    for (int i = 0; i < n; i++) 
					{
				        arr[i] = prdts[i];
				    }
				    
				    sort(arr, arr+n, &compareProdutoCrec);
				    
				    system("cls");
				    cout << "Digite o nome do produto que deseja encontrar: ";
				    cin >> nomep;
				    
				    index = binarySearchString(arr, nomep, n);
				    
				    if (index == -1)
				    {
			            cout << ("Produto nao encontrado!") << endl;
			        }
			        else
			        {
			            printBusca(arr, index);
			        }
			        system("pause");
				}
				break;
				
			case 4:
				{
					int index;
					int n = prdts.size();//Um array e criado para facilitar operacoes
					produto arr[n];      //de impressao, sort e busca
				    for (int i = 0; i < n; i++) 
					{
				        arr[i] = prdts[i];
				    }
				    
				    system("cls");
					printProdutosN(arr, n);
				    
				    cout << "Digite o numero do produto que deseja deletar: ";
				    while(!(cin >> index) || index > prdts.size() || index < 1)
					{
				        cout << "Comando invalido, tente de novo: ";
					    cin.clear();
					    cin.ignore(numeric_limits<streamsize>::max(), '\n');
				    }
					prdts.erase((prdts.begin()+(index-1)));
					//Uso da funcao .erase da biblioteca vector
					//que facilita a remocao de dados em qualquer posicao do vector
					
					cout << "Produto deletado com sucesso!" << endl;
					system("pause");
				}
				break;
				
			case 5:
				{
					int esc5, index, att;
					string nomep;
					
					int n = prdts.size();//Um array e criado para facilitar operacoes
					produto arr[n];      //de impressao, sort e busca
				    for (int i = 0; i < n; i++) 
					{
				        arr[i] = prdts[i];
				    }
					
					system("cls");
					cout << "Selecione a forma de busca:" << endl;
					cout << "1 - buscar por nome" << endl;
					cout << "2 - ver lista completa de produtos" << endl;
					while(!(cin >> esc5) || esc5 > 2 || esc5 < 1)
					{
						cout << "Comando invalido, tente de novo: ";
					    cin.clear();
					    cin.ignore(numeric_limits<streamsize>::max(), '\n');
				    }
				    if(esc5 == 1)
				    {
				    	cout << "Digite o nome do produto que deseja encontrar: ";
						cin >> nomep;
						
						/*O codigo da opcao ao usuario de buscar por nome o produto
						O que causa o uso da busca linear, porque o array precisa manter
						as posicoes originais do vector para o produto correto ser alterado*/
						
						index = linearSearchString(arr, n, nomep);
						if (index == -1)
						{
						    cout << ("Produto nao encontrado") << endl;
						    system("pause");
						    break;
						}
						else
				        {
				            printBusca(arr, index);
				            cout << "Atualizar produto?" << endl;
				            cout << "1 - Sim" << endl;
				            cout << "2 - Nao" << endl;
				            while(!(cin >> att) || att > 2 || att < 1)
							{
						        cout << "Comando invalido, tente de novo: ";
						        cin.clear();
						        cin.ignore(numeric_limits<streamsize>::max(), '\n');
					        }
					        if(att == 1)
					        {
					        	produto tempp;
					        	
					        	tempp = updateProduto(arr, index);
					        	
					        	prdts.insert(prdts.begin()+(index-1), tempp);
					        	prdts.erase(prdts.begin()+(index));
					        	
					        	cout << "Produto atualizado com sucesso!" << endl;
					        	system("pause");
							}
							else
							{
								cout << "Retornando para o menu..." << endl;
								system("pause");
							}
				        }
					}
				    else
					{
						printProdutosN(arr, n);
						
						cout << "Digite o numero do produto que deseja atualizar: " << endl;
						while(!(cin >> index) || index > prdts.size() || index < 1)
						{
					        cout << "Comando invalido, tente de novo: ";
					        cin.clear();
					        cin.ignore(numeric_limits<streamsize>::max(), '\n');
					    }	
						cout << endl;					
				        printBusca(arr, index-1);
				        cout << "Atualizar produto?" << endl;
				        cout << "1 - Sim" << endl;
				        cout << "2 - Nao" << endl;
			            while(!(cin >> att) || att > 2 || att < 1)
						{
					        cout << "Comando invalido, tente de novo: ";
					        cin.clear();
					        cin.ignore(numeric_limits<streamsize>::max(), '\n');
				        }
				        if(att == 1)
				        {
				        	produto tempp;
				        	
				        	tempp = updateProduto(arr, index);
				        	
				        	prdts.insert(prdts.begin()+(index-1), tempp);
				        	prdts.erase(prdts.begin()+(index));
					        	
				        	cout << "Produto atualizado com sucesso!" << endl;
				        	system("pause");
						}							
						else
						{
							cout << "Retornando para o menu..." << endl;
							system("pause");
						}
			        }
				}
				break;
				
			case 6:
				{
					int esc6, escdece;
					
					int n = prdts.size();//Um array e criado para facilitar operacoes
					produto arr[n];      //de impressao, sort e busca
				    for (int i = 0; i < n; i++) 
					{
				        arr[i] = prdts[i];
				    }
					
					system("cls");
					cout << "Selecione a forma de visualizacao:" << endl;
					cout << "1 - Preco" << endl;
					cout << "2 - Nome" << endl;
					while(!(cin >> esc6) || esc6 > 2 || esc6 < 1)
					{
				        cout << "Comando invalido, tente de novo: ";
				        cin.clear();
				        cin.ignore(numeric_limits<streamsize>::max(), '\n');
			        }
					if(esc6 == 1)
					{
						cout << "Selecione a ordem de visualizacao:" << endl;
						cout << "1 - Crescente" << endl;
						cout << "2 - Decrescente" << endl;
						while(!(cin >> escdece) || escdece > 2 || escdece < 1)
						{
				 	        cout << "Comando invalido, tente de novo: ";
					        cin.clear();
					        cin.ignore(numeric_limits<streamsize>::max(), '\n');
				        }
				        if(escdece == 1)
				        {
							heapSort(arr, n);
							system("cls");
							printProdutosP(arr, n);
							system("pause");
						}
						else
						{
							heapSortDec(arr, n);
							system("cls");
							printProdutosP(arr, n);
							system("pause");											
						}
					}
					else
					{
						cout << "Selecione a ordem de visualizacao:" << endl;
						cout << "1 - Crescente" << endl;
						cout << "2 - Decrescente" << endl;
						while(!(cin >> escdece) || escdece > 2 || escdece < 1)
						{
					        cout << "Comando invalido, tente de novo: ";
					        cin.clear();
					        cin.ignore(numeric_limits<streamsize>::max(), '\n');
				        }
				        if(escdece == 1)
						{
			        		sort(arr, arr+n, &compareProdutoCrec);
			        		system("cls");
							printProdutosN(arr, n);
							system("pause");
						}
						else
						{
							sort(arr, arr+n, &compareProdutoDec);
							system("cls");
							printProdutosN(arr, n);
							system("pause");
						}
					}
				}
				break;
				
			case 7:
				cout << "Encerrando.";
				exit(1);
				break;	
		}
	}
	return 0;
}