#include <stdio.h>
#include <string.h>


int main(){
    adicionarMangas();
}


void adicionarMangas()
{
    FILE *ponteiroArquivoAdc; // ponteiro do arquivo
    char nomeDoManga[50];
    int capituloAtual;

    ponteiroArquivoAdc = fopen("mangasECapitulos.txt", "a"); // abrindo o arquivo 

    if (ponteiroArquivoAdc == NULL){

        printf("Erro na abertura do arquivo");
        return 1; 
    }
    else{
        printf("Escreva o nome do mangá: ");
        gets(nomeDoManga);
        if ((verificarManga(nomeDoManga)) == 1){
            exit(0);
        }

        fflush(stdin);

        printf("Escreva o número do capitulo que você está");
        scanf("%d", &capituloAtual);

        fprintf(ponteiroArquivoAdc, "%s\n %d\n", nomeDoManga,capituloAtual);


        fclose(ponteiroArquivoAdc);

        printf("Dados salvos com sucesso!");

    }
    return 0;
} 

int verificarManga(char nomeDoManga[50]) {
    FILE *ponteiroArquivoVrf;
    char VrfNomeDoManga[50];
    char nomeDoMangaVrf[50];

    strcpy(nomeDoMangaVrf, nomeDoManga);

    ponteiroArquivoVrf = fopen("mangasECapitulos.txt", "r");

    if (ponteiroArquivoVrf == NULL) {
        printf("Erro na abertura do arquivo\n");
        return;
    }

    while (fgets(VrfNomeDoManga, 50, ponteiroArquivoVrf) != NULL) {
        
        VrfNomeDoManga[strcspn(VrfNomeDoManga, "\n")] = 0;

        if (strcmp(VrfNomeDoManga, nomeDoMangaVrf) == 0) {
            printf("Este mangá já foi cadastrado!\n");
            fclose(ponteiroArquivoVrf);
            return 0; 
        }
    }

    fclose(ponteiroArquivoVrf);
}