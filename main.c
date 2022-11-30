#include <stdio.h>
#include <string.h>
#include <locale.h>

void forca(int estado){
              if(estado==0){
                printf("===JOGADOR 2===");
                printf("\n------------");
                printf("\n|          |");
                printf("\n|");
                printf("\n|");
                printf("\n|");
                printf("\n|");
                printf("\n|");
                printf("\n-");
              } else if(estado==1){
                printf("===JOGADOR 2===");
                printf("\n------------");
                printf("\n|          |");
                printf("\n|          0");
                printf("\n|");
                printf("\n|");
                printf("\n|");
                printf("\n|");
                printf("\n-");
              } else if(estado==2){
                printf("===JOGADOR 2===");
                printf("\n------------");
                printf("\n|          |");
                printf("\n|          0");
                printf("\n|          |");
                printf("\n|");
                printf("\n|");
                printf("\n|");
                printf("\n-");
              } else if(estado==3){
                printf("===JOGADOR 2===");
                printf("\n------------");
                printf("\n|          |");
                printf("\n|          0");
                printf("\n|         -|");
                printf("\n|           ");
                printf("\n|");
                printf("\n|");
                printf("\n-");
              } else if(estado==4){
                printf("===JOGADOR 2===");
                printf("\n------------");
                printf("\n|          |");
                printf("\n|          0");
                printf("\n|         -|-");
                printf("\n|           ");
                printf("\n|");
                printf("\n|");
                printf("\n-");
              } else if(estado==5){
                printf("===JOGADOR 2===");
                printf("\n------------");
                printf("\n|          |");
                printf("\n|          0");
                printf("\n|         -|-");
                printf("\n|         /  ");
                printf("\n|");
                printf("\n|");
                printf("\n-");
              } else if(estado==6){
                printf("===JOGADOR 2===");
                printf("\n------------");
                printf("\n|          |");
                printf("\n|          0");
                printf("\n|         -|-");
                printf("\n|         / \\ ");
                printf("\n|");
                printf("\n|------Perdeu o game!---------");
                printf("\n======JOGADOR 1 WINS======");
                printf("\n-");
              }
            }
            void limpa_tela(){
              for(int i=0;i<30;i++){
                printf("\n");
              }
            }


int main(void) {

int valor;

printf ("Digite um valor referente a opção desejada: \n");
printf ("1.INICIAR JOGO!\n");
printf ("2.CRÉDITOS.\n");
printf ("3.RANKING.\n");
printf ("4.CADASTRAR PALAVRA.\n");
printf ("5.Sair!\n");
scanf("%d", &valor);



char p_sec[100];//palavra secreta
          printf("---------JOGADOR 1:----------\n");
          printf("Digite a Palavra Secreta:\n");
          fgets(p_sec, 100, stdin); //getstring
          printf("A palavra secreta é: %s", p_sec);
          printf("A palavra tem %lu caracteres", strlen(p_sec)-1);
          limpa_tela();

char palavra;

  switch ( valor )
  {
    case 1 :
        printf ("1.INICIANDO JOGO!\n");

        char p_sec[100];//palavra secreta
          printf("---------JOGADOR 1:----------\n");
          printf("Digite a Palavra Secreta:\n");
          fgets(p_sec, 100, stdin); //getstring
          printf("A palavra secreta é: %s", p_sec);
          printf("A palavra tem %lu caracteres", strlen(p_sec)-1);
          limpa_tela();



             //retira o ultimo caracter de p_sec que esta a mais devido a captura ser com fgets()
              p_sec[strlen(p_sec)-1]='\0';
              char p_tela[100];//palavra para tela
              strcpy(p_tela, p_sec);//copia de p_sec
              //substitui letras por '_'
              for(int i=0;i<strlen(p_tela);i++){
               p_tela[i]='_';
              }

          int erros = 0;
          while(1){
            //imprimir a forca
            limpa_tela();
            forca(erros);
            //imprimir os underline/underscores '_' para cada letra da palavra secreta, ou seja, imprimir p_tela
            printf("\nAdivinhe: ");
            //colocar os espacos entre os underlines
            for(int i=0;i<strlen(p_tela);i++){
              printf("%c ", p_tela[i]);
            }
            //recebe a letra
            printf("\nLetra: ");
            char letra;
            scanf(" %c", &letra);//o espaço antes do % é por conta do repl.it usado via web...
            //se letra correta atualiza palavra na tela
            //verifica se a letra esta correta
            int sera_que_errou=1;//1=sim 0=nao
            for(int i=0;i<strlen(p_tela); i++){
              if(letra==p_sec[i]){//certo
                p_tela[i]=letra;
                sera_que_errou=0;
              }
            }
            //senao, incrementa erros
            if(sera_que_errou==1){
              erros++;

              }

            //verifica se o jogo acabou
            //verifica se ganhou
            //verifica se p_sec é igual a p_tela
            if(strcmp(p_tela,p_sec)==0){
              //ENTAO ganhou
              printf("\nAcertou: ");
              for(int i=0;i<strlen(p_tela);i++){
                printf("%c ", p_tela[i]);
              }
              printf("\n-------Venceu! Parabéns!!!---------");
              printf("\n---------JOGADOR 2 wins!---------");
              break;
            }
            //verifica se perdeu
            if(erros==6){
              //perdeu
              forca(erros);
              break;
            }
          }


    break;

    case 2 :
    printf ("2.CRÉDITOS!\n");
    printf ("Pedro Henrique e Mateus Guerra.\n");
    break;

    case 3 :
    printf ("3.RANKING.\n");
    printf ("JOGADOR 2 - 1 ACERTO.\n");
    break;

    case 4 :

    printf ("4.CADASTRAR PALAVRA: \n");
    scanf("%c", &palavra);
    printf("Palavra cadastrada!");
    break;

    case 5 :
    printf ("5.Sair.\n");
    break;

    default :
    printf ("VALOR INVÁLIDO!\n");
  }








  return 0;
}
