
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define max 1000
#define tam 1000

typedef struct {

	char nome[max];
	int idade;
	int rg;
	int estudante;
	int dia, mes, ano;
	int show;
	int dia2;
	int excluido;

} Cadastro;

int setcolor(char color);
void consultas();
void compra();
void cancela();
void cancela2();
void altera();
void lista();
void lista2();
void ajuda();


int main() {

	int op2, opcao;

	do {
		system("cls");
		setcolor(15);
		printf("-----------------------SHOWS MORUMBI 2024-----------------------\n\n");
		setcolor(15);
		printf("1- Consultar shows, datas disponiveis e valor\n");
		printf("2- Comprar ingresso\n");
		printf("3- Cancelar compra\n");
		printf("4- Alterar dados\n");
		printf("5- Lista de pessoas de determinado show com determinado nome\n");
		printf("6- Lista de pessoas de determinado show com determinada idade\n");
		setcolor(12);
		printf("7- Sair\n\n");
		setcolor(8);
		printf("Digite a opcao desejada: ");
		setcolor(15);
		
		opcao = getch();

		switch (opcao) {

			case '1':
				system("cls");
				consultas();
				break;

			case '2':
				system("cls");
				int i;
				compra();
				break;

			case '3':
				printf("Deseja fazer exclusao logica ou fisica? (1- Logica; 2-Fisica): ");
				scanf("%d",&op2);
				getchar();
				system("cls");
				if(op2 == 1) {
					cancela2();
				} else
					cancela();
				break;

			case '4':
				system("cls");
				altera();
				break;

			case '5':
				getchar();
				system("cls");
				lista();
				break;


			case '6':
				system("cls");
				lista2();
				break;

			case '7':
				system("cls");
				setcolor(15);
				printf("by ");
				printf("Kiq ");
				printf("e ");
				printf("Sophia ");
				setcolor(4);
				printf("<3\n");
				setcolor(8);
				return 0;
			
			case 0:
				opcao = getch();
				if (opcao == 59) {
					system("cls");
					ajuda();
					getch();
				}
				
			break;

			default:
			printf("Digite uma opcao valida! \n\n");
			break;
		}	
	

	} while(opcao != 7);


	return 0;
}


void consultas() {

	setcolor(15);
	printf("-------------------SHOWS E DATAS MORUMBI 2024--------------------\n\n");
	setcolor(4);
	printf("1- The Weeknd\n");
	setcolor(15);
	printf("1.1- 23/10/2024\n");
	printf("1.2- 29/10/2024\n\n");

	setcolor(5);
	printf("2- Chase Atlantic\n");
	setcolor(15);
	printf("2.1- 09/11/2024\n");
	printf("2.2- 12/11/2024\n\n");

	setcolor(9);
	printf("3- Adele\n");
	setcolor(15);
	printf("3.1- 17/11/2024\n");
	printf("3.2- 19/11/2024\n\n");
	
	setcolor(15);
	printf("Todos os show possuem um valor de ");
	setcolor(12);
	printf("R$296.98 por ingresso");
	setcolor(15);
	printf(".\n");
	getch();
	system("cls");

}


void compra() {

	Cadastro cad;


	FILE *arq1, *arq2, *arq3, *estd;

	arq1 = fopen("weeknd.bin", "a+b");

	arq2 = fopen("chase.bin", "a+b");

	arq3 = fopen("adele.bin", "a+b");

	estd = fopen("estudante.bin", "a+b");

	if(!arq1) {
		setcolor(12);
		printf("Erro ao abrir 'weeknd.bin'!\n");
		exit(1);
	}

	if(!arq2) {
		setcolor(12);
		printf("Erro ao abrir 'chase.bin'!\n");
		exit(1);
	}

	if(!arq3) {
		setcolor(12);
		printf("Erro ao abrir 'adele.bin'!\n");
		exit(1);
	}

	if(!estd) {
		setcolor(12);
		printf("Erro ao abrir 'estudante.bin'!\n");
		exit(1);
	}


	setcolor(15);
	printf("------------------COMPRA DE INGRESSO------------------\n\n");
	setcolor(4);
	printf("1- The Weeknd\n");
	setcolor(5);
	printf("2- Chase Atlantic\n");
	setcolor(9);
	printf("3- Adele\n\n");





	setcolor(8);
	printf("Digite a opcao desejada: ");
	setcolor(15);
	scanf("%d",&cad.show);


	if(cad.show == 1) {
		setcolor(15);
		printf("\nDias disponiveis:\n");
		setcolor(15);
		printf("1- ");
		printf("23/10/2024\n");
		setcolor(15);
		printf("2- ");
		printf("29/10/2024\n");

	} else if(cad.show == 2) {
		setcolor(15);
		printf("\nDias disponiveis:\n");
		setcolor(15);
		printf("1- ");
		printf("09/11/2024\n");
		setcolor(15);
		printf("2- ");
		printf("12/11/2024\n");

	} else if(cad.show == 3) {
		setcolor(15);
		printf("\nDias disponiveis:\n");
		setcolor(15);
		printf("1- ");
		printf("17/11/2024\n");
		setcolor(15);
		printf("2- ");
		printf("19/11/2024\n");
	}

	printf("\n");
	do {
		setcolor(8);
		printf("Digite a opcao desejada: ");
		setcolor(15);
		scanf("%d",&cad.dia2);

		if(cad.dia2 < 1 || cad.dia2 > 2){
			setcolor(12);
			printf("Digite uma opcao valida!\n\n");
			setcolor(15);
		}

	printf("\n");
	} while(cad.dia2 < 1 || cad.dia2 > 2);

	getchar();
	setcolor(8);
	printf("Nome: ");
	setcolor(15);
	fgets(cad.nome, max, stdin);
	cad.nome[strcspn(cad.nome, "\n")] = '\0';

	setcolor(8);
	printf("Idade: ");
	setcolor(15);
	scanf("%d",&cad.idade);
	getchar();

	setcolor(8);
	printf("Data de nascimento (dd mm aaaa): ");
	setcolor(15);
	scanf("%d %d %d",&cad.dia, &cad.mes, &cad.ano);
	getchar();

	setcolor(8);
	printf("RG: ");
	setcolor(15);
	scanf("%d",&cad.rg);
	getchar();

	setcolor(8);
	printf("Estudante? (1-Sim, 2-Nao): ");
	setcolor(15);
	scanf("%d",&cad.estudante);
	getchar();
	cad.excluido = 0;


	if(cad.show == 1) {
		fwrite(&cad, sizeof(Cadastro), 1, arq1);
	}
	if(cad.show == 2) {
		fwrite(&cad, sizeof(Cadastro), 1, arq2);
	}
	if(cad.show == 3) {
		fwrite(&cad, sizeof(Cadastro), 1, arq3);
	}


	if(cad.estudante == 1) {
		fwrite(&cad, sizeof(Cadastro), 1, estd);
	}



	fclose(arq1);
	fclose(arq2);
	fclose(arq3);
	fclose(estd);
	getch();
	system("cls");
}


void cancela() {

	Cadastro cad;
	FILE *arq1, *arq2, *arq3, *estd;
	int opcao, rg, achou = 0, estuda;

	arq1 = fopen("weeknd.bin", "r+b");
	arq2 = fopen("chase.bin", "r+b");
	arq3 = fopen("adele.bin", "r+b");
	estd = fopen("estudante.bin", "r+b");

	if (!arq1 || !arq2 || !arq3 || !estd) {
		setcolor(12);
		printf("Erro ao abrir um dos arquivos!\n");
		exit(1);
	}

	
	printf("----------------Cancelamento de compra----------------\n\n");
	
	setcolor(4);
	printf("1- The Weeknd\n");
	setcolor(5);
	printf("2- Chase Atlantic\n");
	setcolor(9);
	printf("3- Adele\n\n");
	setcolor(8);
	printf("Digite a opcao de show que voce comprou: ");
	setcolor(15);
	scanf("%d", &opcao);
	setcolor(8);
	printf("Digite o seu RG: ");
	setcolor(15);
	scanf("%d", &rg);
	setcolor(8);
	printf("Voce eh estudante? (1-Sim; 2-Nao): ");
	setcolor(15);
	scanf("%d", &estuda);

	FILE *arq = NULL;
	if (opcao == 1) arq = arq1;
	else if (opcao == 2) arq = arq2;
	else if (opcao == 3) arq = arq3;

	if (arq != NULL) {
		FILE *tempFile = fopen("temp.bin", "wb");
		if (!tempFile) {
			setcolor(12);
			printf("Erro ao criar o arquivo temporario!\n");
			exit(1);
		}

		while (fread(&cad, sizeof(Cadastro), 1, arq) == 1) {
			if (cad.rg != rg) {
				fwrite(&cad, sizeof(Cadastro), 1, tempFile);
			} else {
				//exclui, ou seja, nao escreve no arq temporario
				setcolor(15);
				printf("\n\nCancelamento da compra referente ao RG %d realizado com sucesso no arquivo do show!\n", cad.rg);
				achou = 1;
			}
		}

		fclose(arq);
		fclose(tempFile);


		remove(opcao == 1 ? "weeknd.bin" : (opcao == 2 ? "chase.bin" : "adele.bin"));
		rename("temp.bin", opcao == 1 ? "weeknd.bin" : (opcao == 2 ? "chase.bin" : "adele.bin"));
	}

	if (estuda == 1) {
		FILE *tempEstudante = fopen("estudante_temp.bin", "wb");
		if (!tempEstudante) {
			setcolor(12);
			printf("Erro ao criar o arquivo temporário para estudante!\n");
			exit(1);
		}

		while (fread(&cad, sizeof(Cadastro), 1, estd) == 1) {
			if (cad.rg != rg) {
				fwrite(&cad, sizeof(Cadastro), 1, tempEstudante);
			} else {
				setcolor(15);
				printf("\n\nCancelamento da compra referente ao RG %d realizado com sucesso no arquivo de estudantes!\n", cad.rg);
				achou = 1;
			}
		}

		fclose(estd);
		fclose(tempEstudante);


		remove("estudante.bin");
		rename("estudante_temp.bin", "estudante.bin");
	}

	if (!achou) {
		setcolor(15);
		printf("Nao ha nenhuma compra realizada no RG informado %d.\n\n", rg);
	}
	getchar();
	getchar();
	system("cls");

}

void cancela2() {
	Cadastro cad;
	FILE *arq1, *arq2, *arq3;
	int opcao, rg, achou = 0;

	arq1 = fopen("weeknd.bin", "r+b");
	arq2 = fopen("chase.bin", "r+b");
	arq3 = fopen("adele.bin", "r+b");

	if (!arq1 || !arq2 || !arq3) {
		setcolor(12);
		printf("Erro ao abrir um dos arquivos!\n");
		exit(1);
	}

	setcolor(15);
	printf("----------------Cancelamento de compra----------------\n\n");
	setcolor(4);
	printf("1- The Weeknd\n");
	setcolor(5);
	printf("2- Chase Atlantic\n");
	setcolor(9);
	printf("3- Adele\n\n");
	setcolor(8);
	printf("Digite a opcao de show que voce comprou: ");
	setcolor(15);
	scanf("%d", &opcao);
	setcolor(8);
	printf("Digite o seu RG: ");
	setcolor(15);
	scanf("%d", &rg);

	FILE *arq = NULL;
	if (opcao == 1) arq = arq1;
	else if (opcao == 2) arq = arq2;
	else if (opcao == 3) arq = arq3;

	if (!arq) {
		setcolor(12);
		printf("Opcao de show invalida!\n");
		setcolor(15);
		fclose(arq1);
		fclose(arq2);
		fclose(arq3);
		return;
	}


	while (fread(&cad, sizeof(Cadastro), 1, arq) == 1) {
		if (cad.rg == rg && cad.excluido == 0) { //verifiquei se nao foi excluido antes
			cad.excluido = 1; // marco como excluido
			fseek(arq, -sizeof(Cadastro), SEEK_CUR); //colto para reescrever no local correto
			fwrite(&cad, sizeof(Cadastro), 1, arq); //reescrevo o registro
			achou = 1;
			break;
		}
	}



	if (achou) {
		setcolor(15);
		printf("Registro com RG %d marcado como excluido com sucesso!\n", rg);
	} else {
		setcolor(12);
		printf("Registro com RG %d nao encontrado ou ja foi excluido!\n", rg);
		setcolor(15);
	}

	fclose(arq);
	fclose(arq1);
	fclose(arq2);
	fclose(arq3);
	getchar();
	getchar();
	system("cls");
}



void altera() {
    Cadastro cad;
    FILE *arq1, *arq2, *arq3, *estd;
    int opcao, rg, achou = 0, estuda;

    arq1 = fopen("weeknd.bin", "r+b");
    arq2 = fopen("chase.bin", "r+b");
    arq3 = fopen("adele.bin", "r+b");
    estd = fopen("estudante.bin", "r+b");

    if (!arq1 || !arq2 || !arq3 || !estd) {
        setcolor(12);
        printf("Erro ao abrir um dos arquivos!\n");
        exit(1);
    }

    setcolor(15);
    printf("------------------Alteracao de dados------------------\n\n");

    setcolor(4);
    printf("1- The Weeknd\n");
    setcolor(5);
    printf("2- Chase Atlantic\n");
    setcolor(9);
    printf("3- Adele\n\n");
    setcolor(8);
    printf("Digite a opcao de show que voce comprou: ");
    setcolor(15);
    scanf("%d", &opcao);
    setcolor(8);
    printf("\nDigite o seu RG: ");
    setcolor(15);
    scanf("%d", &rg);
    setcolor(8);
    printf("Voce eh estudante? (1-Sim; 2-Nao): ");
    setcolor(15);
    scanf("%d", &estuda);
    getchar();
    printf("\n");

    FILE *arq = NULL;
    if (opcao == 1) arq = arq1;
    else if (opcao == 2) arq = arq2;
    else if (opcao == 3) arq = arq3;

    if (arq != NULL) {
        FILE *tempFile = fopen("temp.bin", "wb");
        if (!tempFile) {
            setcolor(12);
            printf("Erro ao criar o arquivo temporario!\n");
            exit(1);
        }

        while (fread(&cad, sizeof(Cadastro), 1, arq) == 1) {
            if (rg == cad.rg) {
                if (cad.estudante == 2 && estuda == 1 || cad.excluido == 1) {
                    setcolor(12);
                    printf("Nao ha ninguem com os dados informados!\n");
                    achou = -1;
                    break;
                }

                setcolor(15);
                printf("Dados salvos ate o momento: %s, %d ano(s), %d/%d/%d, RG: %d, ", 
                       cad.nome, cad.idade, cad.dia, cad.mes, cad.ano, cad.rg);
                if (cad.estudante == 1) {
                    printf("Estudante.\n\n");
                } else {
                    printf("Nao estudante.\n\n");
                }

                
                
                setcolor(8);
                printf("Nome: ");
                setcolor(15);
                fgets(cad.nome, max, stdin);
                cad.nome[strcspn(cad.nome, "\n")] = '\0';

                setcolor(8);
                printf("Idade: ");
                setcolor(15);
                scanf("%d", &cad.idade);
                getchar();

                setcolor(8);
                printf("Data de nascimento (dd mm aaaa): ");
                setcolor(15);
                scanf("%d %d %d", &cad.dia, &cad.mes, &cad.ano);
                getchar();

                setcolor(8);
                printf("RG: ");
                setcolor(15);
                scanf("%d", &cad.rg);
                getchar();

                setcolor(8);
                printf("Estudante? (1-Sim, 2-Nao): ");
                setcolor(15);
                scanf("%d", &cad.estudante);
                getchar();

                achou = 1;
            }
            
           
            fwrite(&cad, sizeof(Cadastro), 1, tempFile);
        }

        fclose(arq);
        fclose(tempFile);

        
        if (achou > 0) {
           if (opcao == 1) {
    	remove("weeknd.bin");
    	rename("temp.bin", "weeknd.bin");
		}else if (opcao == 2) {
    	remove("chase.bin");
    	rename("temp.bin", "chase.bin");
		}else if (opcao == 3) {
    	remove("adele.bin");
    	rename("temp.bin", "adele.bin");
		}
            setcolor(15);
            printf("\nAlteracao realizada com sucesso!\n");
        }

     
        if (!achou) {
            setcolor(12);
            printf("\nNao ha nenhuma compra realizada com o rg %d.\n", rg);
        }

    }

    fclose(arq1);
    fclose(arq2);
    fclose(arq3);
    fclose(estd);
    getchar();
    system("cls");
}



void lista() {
	Cadastro cad;
	FILE *arq1, *arq2, *arq3;
	int opcao, achou = 0;
	char nome[max];

	arq1 = fopen("weeknd.bin", "r+b");
	arq2 = fopen("chase.bin", "r+b");
	arq3 = fopen("adele.bin", "r+b");

	if (!arq1 || !arq2 || !arq3) {
		setcolor(12);
		printf("Erro ao abrir um dos arquivos!\n");
		exit(1);
	}
	
	setcolor(15);
	printf("------------Lista de pessoas de determinado show com determinado nome-----------\n\n");
	setcolor(8);
	printf("Digite a opcao correspondente ao show desejado \n");
	setcolor(4);
	printf("1-The Weeknd; ");
	setcolor(5);
	printf("2-Chase Atlantic; ");
	setcolor(9);
	printf("3-Adele: ");
	setcolor(15);
	scanf("%d", &opcao);
	getchar();
	system("cls");

	FILE *arq = NULL;
	if (opcao == 1) {
		setcolor(4);
		printf("----------The Weeknd----------\n\n");
		setcolor(15);
		arq = arq1;
	} else if (opcao == 2) {
		setcolor(5);
		printf("----------Chase Atlantic----------\n\n");
		setcolor(15);
		arq = arq2;
	} else if (opcao == 3) {
		setcolor(9);
		printf("----------Adele----------\n\n");
		setcolor(15);
		arq = arq3;
	}

	if (!arq) {
		setcolor(12);
		printf("Erro ao abrir o arquivo selecionado.\n\n");
		fclose(arq1);
		fclose(arq2);
		fclose(arq3);
		exit(1);
	}

	setcolor(8);
	printf("Digite o nome completo da pessoa que voce deseja procurar: ");
	setcolor(15);
	fgets(nome, max, stdin);
	nome[strcspn(nome, "\n")] = '\0';
	printf("\n");

	char ajuda1[max], ajuda2[max];

	for (int i = 0; i < strlen(nome); i++) {
		ajuda1[i] = tolower(nome[i]);
	}
	ajuda1[strlen(nome)] = '\0';

	while (fread(&cad, sizeof(Cadastro), 1, arq) == 1) {

		if (cad.excluido == 1) {
			continue;
		}

		for (int i = 0; i < strlen(cad.nome); i++) {
			ajuda2[i] = tolower(cad.nome[i]);
		}
		ajuda2[strlen(cad.nome)] = '\0';

		if (strcasecmp(ajuda1, ajuda2) == 0) {
			
			setcolor(8);
			printf("Nome: ");
			setcolor(15);
			printf("%s\n", cad.nome);
			setcolor(8);
			printf("Idade: ");
			setcolor(15);
			printf("%d\n", cad.idade);
			setcolor(8);
			printf("Data de nascimento: ");
			setcolor(15);
			printf("%d/%d/%d\n", cad.dia, cad.mes, cad.ano);
			setcolor(8);
			printf("RG: ");
			setcolor(15);
			printf("%d\n", cad.rg);
			if (cad.estudante == 1) {
				setcolor(15);
				printf("Estudante.\n");
			} else {
				setcolor(12);
				printf("Nao eh estudante.\n");
			}
			printf("\n\n");
			achou++;
		}
	}

	if (achou == 0) {
		setcolor(12);
		printf("\nNao ha ninguem cadastrado com o nome informado!\n");
		setcolor(15);
	}

	fclose(arq);
	fclose(arq1);
	fclose(arq2);
	fclose(arq3);
	getchar();
	system("cls");
}



void lista2() {
	Cadastro cad;
	FILE *arq1, *arq2, *arq3;
	int opcao, achou = 0, idade;

	arq1 = fopen("weeknd.bin", "r+b");
	arq2 = fopen("chase.bin", "r+b");
	arq3 = fopen("adele.bin", "r+b");

	if (!arq1 || !arq2 || !arq3) {
		setcolor(12);
		printf("Erro ao abrir um dos arquivos!\n");
		exit(1);
	}

	setcolor(15);
	printf("------------Lista de pessoas de determinado show com determinada idade-----------\n\n");
	setcolor(8);
	printf("Digite a opcao correspondente ao show desejado \n");
	setcolor(4);
	printf("1-The Weeknd; ");
	setcolor(5);
	printf("2-Chase Atlantic; ");
	setcolor(9);
	printf("3-Adele: ");
	setcolor(15);
	scanf("%d", &opcao);
	getchar();
	system("cls");

	FILE *arq = NULL;
	if (opcao == 1) {
		setcolor(4);
		printf("----------The Weeknd----------\n\n");
		setcolor(15);
		arq = arq1;
	} else if (opcao == 2) {
		setcolor(5);
		printf("----------Chase Atlantic----------\n\n");
		setcolor(15);
		arq = arq2;
	} else if (opcao == 3) {
		setcolor(9);
		printf("----------Adele----------\n\n");
		setcolor(15);
		arq = arq3;
	}

	if (!arq) {
		setcolor(12);
		printf("Erro ao abrir o arquivo selecionado.\n\n");
		fclose(arq1);
		fclose(arq2);
		fclose(arq3);
		exit(1);
	}

	setcolor(8);
	printf("Digite a idade desejada: ");
	setcolor(15);
	scanf("%d", &idade);
	getchar();
	printf("\n");

	while (fread(&cad, sizeof(Cadastro), 1, arq) == 1) {
		// estou verificando se houve exclusão lógica
		if (cad.excluido == 1) {
			continue; // pulando registros excluidos
		}

		if (idade == cad.idade) {
			setcolor(8);
			printf("Nome: ");
			setcolor(15);
			printf("%s\n", cad.nome);
			setcolor(8);
			printf("Idade: ");
			setcolor(15);
			printf("%d\n", cad.idade);
			setcolor(8);
			printf("Data de nascimento: ");
			setcolor(15);
			printf("%d/%d/%d\n", cad.dia, cad.mes, cad.ano);
			setcolor(8);
			printf("RG: ");
			setcolor(15);
			printf("%d\n", cad.rg);
			if (cad.estudante == 1) {
				setcolor(15);
				printf("Estudante.\n");
			} else {
				setcolor(12);
				printf("Nao eh estudante.\n");
				setcolor(15);
			}
			printf("\n\n");
			achou++;
		}
	}

	if (achou == 0) {
		setcolor(12);
		printf("Nao ha ninguem com a idade informada!\n");
		setcolor(15);
	}

	fclose(arq);
	fclose(arq1);
	fclose(arq2);
	fclose(arq3);
	getchar();
	system("cls");
}

int setcolor(char color){
	
	HANDLE h;
	
	h = GetStdHandle (STD_OUTPUT_HANDLE);
	return SetConsoleTextAttribute (h, color);
	
}

void ajuda(){
	
	char texto[tam];
	FILE *help, *kaka;
	
		kaka = fopen("kaka.txt","w+");
	
	if(!kaka){
		printf("Erro ao abrir o arquivo!");
		exit(1);
	}
	
	help = fopen("sort.txt","r+");
	
	if(!help){
		printf("Erro ao abrir o arquivo 1!");
		exit(1);
	}
	
	
	
	while(fgets(texto, tam, help)!= NULL){
		
		for(int i = 0;texto[i]!='\n'; i++){
			texto[i] = texto[i] - 3;
		}
		fprintf(kaka, "%s\n", texto);
		printf("%s\n",texto);
		
	}
	
	fclose(kaka);
	fclose(help);
	getchar();
}
