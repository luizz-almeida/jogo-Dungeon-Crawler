#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

#define linha_m 12
#define linha_vila 21
#define linhas 21
#define linha 21
#define linha_m2 14
#define linha_ul 25
#define coluna_vila 20
#define coluna 20
#define colunas 20
#define coluna_m 10
#define coluna_m2 20
#define coluna_ul 25
#define maX_monstro 10


void desenhar(char mapas[linhas][colunas]);
void gamer_over();
void vitoria();
void registro_monster();
void registrar_boss();

int nivel_arma = 1;
int fase = 0;
int i, j, m, opcao;
int arma = 0;
int tem_chave = 0;
int dinhero_colt = 0;
int vida_jogador = 3;
int jl = 17;
int jc = 3;
char jd = '^';
int l_m[maX_monstro];
int c_m[maX_monstro];
int t_m[maX_monstro];
int num_monster = 0;
int boss_l, boss_c;
int boss_fase = 0;
int boss_turno = 0;

char mapa_vila[linha_vila][coluna_vila] = {
    "********************",
    "*                = *",
    "*  F               *",
    "*                  *",
    "*  B               *",
    "*                  *",
    "********           *",
    "*A     *           *",
    "*                  *",
    "*********  *********",
    "        *  *        ",
    "        *  *        ",
    "        *  *        ",
    "*********  *        ",
    "*          *        ",
    "*          *        ",
    "*          *        ",
    "*          *        ",
    "*          *        ",
    "************        ",
    "                    "
};

char mapa1[linha][coluna] = {
    "********************",
    "*k                k*",
    "*                  *",
    "*     X            *",
    "*                  *",
    "*                 X*",
    "*            ### ##*",
    "*          Y #     *",
    "*k           #k  D *",
    "*********  *********",
    "        *  *        ",
    "        *  *        ",
    "        *  *        ",
    "*********  *        ",
    "*          *        ",
    "*   ***************",
    "*  ####          #*",
    "*        # # #   #*",
    "*#########      ##*",
    "*@k          # #L *",
    "*******************"
};

char mapa2[linha_m2][coluna_m2] = {
    "********************",
    "*k                k*",
    "*                  *",
    "*     X           Y*",
    "*                  *",
    "*                  *",
    "*          ##### ##*",
    "*          #      Y*",
    "*k      X  #k      *",
    "*          #       *",
    "*          #       *",
    "*          #       *",
    "*k        @#X    D *",
    "********************"
};

char mapa3[linha_m][coluna_m] = {
    "**********",
    "*  M     *",
    "*        *",
    "*        *",
    "*   D    *",
    "*        *",
    "*        *",
    "*        *",
    "*        *",
    "*        *",
    "*   L    *",
    "**********"
};

char mapa4[linha_ul][coluna_ul] = {
    "*************************",
    "*                       *",
    "*          Z            *",
    "*                       *",
    "*                       *",
    "*                       *",
    "*                       *",
    "*                       *",
    "*  ###           ###    *",
    "*          Y            *",
    "*                       *",
    "*   Y             Y     *",
    "*                       *",
    "*                       *",
    "*          X            *",
    "*                       *",
    "*  ###     Y     ###    *",
    "*                       *",
    "*   X                X  *",
    "*                       *",
    "*                       *",
    "*                       *",
    "*                       *",
    "*                       *",
    "*************************"
};

void desenhar(char mapas[linhas][colunas]) {
    if(fase == 0) {
        system("cls");
        for(i = 0; i < linha_vila; i++) {
            for(j = 0; j < coluna_vila; j++) {
                if(i == jl && j == jc) printf("%c", jd);
                else printf("%c", mapa_vila[i][j]);
            }
            printf("\n");
        }
    }
    else if(fase == 1) {
        system("cls");
        for(i = 0; i < linha; i++) {
            for(j = 0; j < coluna; j++) {
                if(i == jl && j == jc) printf("%c", jd);
                else printf("%c", mapa1[i][j]);
            }
            printf("\n");
        }
    }
    else if(fase == 2) {
        system("cls");
        for(i = 0; i < linha_m2; i++) {
            for(j = 0; j < coluna_m2; j++) {
                if(i == jl && j == jc) printf("%c", jd);
                else printf("%c", mapa2[i][j]);
            }
            printf("\n");
        }
    }
    else if(fase == 3) {
        system("cls");
        for(i = 0; i < linha_m; i++) {
            for(j = 0; j < coluna_m; j++) {
                if(i == jl && j == jc) printf("%c", jd);
                else printf("%c", mapa3[i][j]);
            }
            printf("\n");
        }
    }
    else {
        system("cls");
        for(i = 0; i < linha_ul; i++) {
            for(j = 0; j < coluna_ul; j++) {
                if(i == jl && j == jc) printf("%c", jd);
                else printf("%c", mapa4[i][j]);
            }
            printf("\n");
        }
    }
    printf("\n");
    printf("\tSTATUS\n");
    printf(" VIDA:%d \t| chave:%d\t| dinheiro:%d\t| arma:%d%s\n",
        vida_jogador, tem_chave, dinhero_colt, arma,
        nivel_arma == 2 ? " [ENCANTADA]" : "");
}

void atacados(int l, int c) {
    char alvo;

    if(fase == 1) {
        if(l < 0 || l >= linha   || c < 0 || c >= coluna)   return;
        alvo = mapa1[l][c];
        if(alvo == 'X' || alvo == 'Y') {
            mapa1[l][c] = '$';
            printf("inimigo derrotado!"); Sleep(500);
            for(m = 0; m < num_monster; m++) {
                if(l_m[m]==l && c_m[m]==c) {
                    l_m[m]=l_m[num_monster-1]; c_m[m]=c_m[num_monster-1]; t_m[m]=t_m[num_monster-1];
                    num_monster--; break;
                }
            }
        }
        if(alvo == 'k') mapa1[l][c] = '$';
    }
    else if(fase == 2) {
        if(l < 0 || l >= linha_m2 || c < 0 || c >= coluna_m2) return;
        alvo = mapa2[l][c];
        if(alvo == 'X' || alvo == 'Y') {
            mapa2[l][c] = '$';
            printf("inimigo derrotado!"); Sleep(500);
            for(m = 0; m < num_monster; m++) {
                if(l_m[m]==l && c_m[m]==c) {
                    l_m[m]=l_m[num_monster-1]; c_m[m]=c_m[num_monster-1]; t_m[m]=t_m[num_monster-1];
                    num_monster--; break;
                }
            }
        }
        if(alvo == 'k') mapa2[l][c] = '$';
    }
    else if(fase == 4) {
        if(l < 0 || l >= linha_ul || c < 0 || c >= coluna_ul) return;
        alvo = mapa4[l][c];
        if(alvo == 'X' || alvo == 'Y') {
            mapa4[l][c] = '$';
            printf("inimigo derrotado!"); Sleep(500);
            for(m = 0; m < num_monster; m++) {
                if(l_m[m]==l && c_m[m]==c) {
                    l_m[m]=l_m[num_monster-1]; c_m[m]=c_m[num_monster-1]; t_m[m]=t_m[num_monster-1];
                    num_monster--; break;
                }
            }
        }
        if(alvo == 'Z') {
            mapa4[l][c] = ' ';
            printf("\nBOSS DERROTADO!\n"); Sleep(1000);
            vitoria();
        }
        if(alvo == 'k') mapa4[l][c] = '$';
    }
}

void efeito_ataque(int area[][2], int tamanho) {
    int lmax, cmax;
    if(fase == 0)      { lmax = linha_vila; cmax = coluna_vila; }
    else if(fase == 1) { lmax = linha;      cmax = coluna; }
    else if(fase == 2) { lmax = linha_m2;   cmax = coluna_m2; }
    else if(fase == 3) { lmax = linha_m;    cmax = coluna_m; }
    else               { lmax = linha_ul;   cmax = coluna_ul; }

    for(i = 0; i < tamanho; i++) {
        int l = area[i][0], c = area[i][1];
        if(l < 0 || l >= lmax || c < 0 || c >= cmax) continue;
        char *cel;
        if(fase == 0)      cel = &mapa_vila[l][c];
        else if(fase == 1) cel = &mapa1[l][c];
        else if(fase == 2) cel = &mapa2[l][c];
        else if(fase == 3) cel = &mapa3[l][c];
        else               cel = &mapa4[l][c];
        if(*cel == ' ') *cel = '!';
    }

    desenhar(NULL);
    Sleep(150);

    for(i = 0; i < tamanho; i++) {
        int l = area[i][0], c = area[i][1];
        if(l < 0 || l >= lmax || c < 0 || c >= cmax) continue;
        char *cel;
        if(fase == 0)      cel = &mapa_vila[l][c];
        else if(fase == 1) cel = &mapa1[l][c];
        else if(fase == 2) cel = &mapa2[l][c];
        else if(fase == 3) cel = &mapa3[l][c];
        else               cel = &mapa4[l][c];
        if(*cel == '!') *cel = ' ';
    }
}

void ataque() {
    if(arma == 1) {
        int tamanho = (nivel_arma == 2) ? 9 : 6;
        int area[9][2];

        if(jd == '^') { int tmp[9][2] = {{jl-1,jc-1},{jl-1,jc},{jl-1,jc+1},{jl-2,jc-1},{jl-2,jc},{jl-2,jc+1},{jl-3,jc-1},{jl-3,jc},{jl-3,jc+1}}; memcpy(area,tmp,sizeof(tmp)); }
        if(jd == 'v') { int tmp[9][2] = {{jl+1,jc-1},{jl+1,jc},{jl+1,jc+1},{jl+2,jc-1},{jl+2,jc},{jl+2,jc+1},{jl+3,jc-1},{jl+3,jc},{jl+3,jc+1}}; memcpy(area,tmp,sizeof(tmp)); }
        if(jd == '<') { int tmp[9][2] = {{jl-1,jc-1},{jl,jc-1},{jl+1,jc-1},{jl-1,jc-2},{jl,jc-2},{jl+1,jc-2},{jl-1,jc-3},{jl,jc-3},{jl+1,jc-3}}; memcpy(area,tmp,sizeof(tmp)); }
        if(jd == '>') { int tmp[9][2] = {{jl-1,jc+1},{jl,jc+1},{jl+1,jc+1},{jl-1,jc+2},{jl,jc+2},{jl+1,jc+2},{jl-1,jc+3},{jl,jc+3},{jl+1,jc+3}}; memcpy(area,tmp,sizeof(tmp)); }  // ← corrigido jc+3

        efeito_ataque(area, tamanho);
        for(i = 0; i < tamanho; i++) atacados(area[i][0], area[i][1]);
    }

    if(arma == 2) {
        int alcance = (nivel_arma == 2) ? 6 : 4;
        int area[6][2];

        if(jd == '^') { int tmp[6][2] = {{jl-1,jc},{jl-2,jc},{jl-3,jc},{jl-4,jc},{jl-5,jc},{jl-6,jc}}; memcpy(area,tmp,sizeof(tmp)); }
        if(jd == 'v') { int tmp[6][2] = {{jl+1,jc},{jl+2,jc},{jl+3,jc},{jl+4,jc},{jl+5,jc},{jl+6,jc}}; memcpy(area,tmp,sizeof(tmp)); }
        if(jd == '<') { int tmp[6][2] = {{jl,jc-1},{jl,jc-2},{jl,jc-3},{jl,jc-4},{jl,jc-5},{jl,jc-6}}; memcpy(area,tmp,sizeof(tmp)); }
        if(jd == '>') { int tmp[6][2] = {{jl,jc+1},{jl,jc+2},{jl,jc+3},{jl,jc+4},{jl,jc+5},{jl,jc+6}}; memcpy(area,tmp,sizeof(tmp)); }

        efeito_ataque(area, alcance);
        for(i = 0; i < alcance; i++) atacados(area[i][0], area[i][1]);
    }

    if(arma == 3) {
        int tamanho = (nivel_arma == 2) ? 10 : 8;
        int area[10][2] = {
            {jl-1,jc-1},{jl-1,jc},{jl-1,jc+1},
            {jl,  jc-1},          {jl,  jc+1},
            {jl+1,jc-1},{jl+1,jc},{jl+1,jc+1},
            {0,0},{0,0}
        };
        if(nivel_arma == 2) {
            if(jd == '^') { area[8][0]=jl-2; area[8][1]=jc; area[9][0]=jl-3; area[9][1]=jc; }
            if(jd == 'v') { area[8][0]=jl+2; area[8][1]=jc; area[9][0]=jl+3; area[9][1]=jc; }
            if(jd == '<') { area[8][0]=jl; area[8][1]=jc-2; area[9][0]=jl; area[9][1]=jc-3; }
            if(jd == '>') { area[8][0]=jl; area[8][1]=jc+2; area[9][0]=jl; area[9][1]=jc+3; }
        }
        efeito_ataque(area, tamanho);
        for(i = 0; i < tamanho; i++) atacados(area[i][0], area[i][1]);
    }
}

void dialogo_ferreiro() {
    system("cls");
    printf("        +-----------------------------+\n");
    printf("        |       FERRERA LAUFEY        |\n");
    printf("        +-----------------------------+\n");
    Sleep(1000); system("cls");
    printf("ola meu pequenino!\n"); Sleep(3000);
    printf("Entao voce realmente pretende entrar na masmorra?\n"); Sleep(3000);
    printf("Tome. Voce vai precisar disso\n"); Sleep(3000);
    system("cls");
    do {
        printf("escolha uma arma\n");
        printf("1. Espada - area 3x2 a sua frente\n");
        printf("2. Arco   - linha reta a sua frente\n");
        printf("3. Cajado - ao seu redor\n");
        if(scanf("%d", &opcao) != 1) {
            printf("Entrada invalida.\n");
            while(getchar() != '\n');
            Sleep(1500); system("cls"); continue;
        }
    } while(opcao < 1 || opcao > 3);

    switch(opcao) {
        case 1: arma = 1; printf("boa escolha mas eu escolheria o arco\n"); break;
        case 2: arma = 2; printf("boa escolha mas eu escolheria a espada\n"); break;
        case 3: arma = 3; printf("boa escolha mas eu escolheria a espada\n"); break;
    }
    Sleep(1500); system("cls");
}

void dialogo_npc_a() {
    system("cls");
    printf("        +-----------------------------+\n");
    printf("        |           PHILIP            |\n");
    printf("        +-----------------------------+\n");
    Sleep(800); system("cls");
    printf("oque voce esta fazendo aqui, garoto?\n"); Sleep(3000);
    printf("voce nao sabe que logo a frente existe a masmorra Haguromo\n"); Sleep(3000);
    printf("la existem diversos goblins e orcs\n"); Sleep(3000);
    printf("dizem que ninguem volta de la\n"); Sleep(3000);
    system("cls");
}

void dialogo_npc_b() {
    system("cls");
    printf("        +-----------------------------+\n");
    printf("        |           JOFFREY           |\n");
    printf("        +-----------------------------+\n");
    Sleep(800); system("cls");
    printf("ha muito tempo atras um grupo de guerreiros decidiu explorar esta masmorra!\n"); Sleep(3000);
    printf("e apenas um deles retornou, falou que ha um tesouro no fundo!\n"); Sleep(3000);
    printf("todavia ha um lorde orc protegendo este tesouro!\n"); Sleep(3000);
    system("cls");
}

void dialogo_maga() {
    system("cls");
    printf("        +-----------------------------+\n");
    printf("        |        MAGA MEGERA          |\n");
    printf("        +-----------------------------+\n");
    Sleep(1000); system("cls");
    printf("saudacoes pequenino!\n"); Sleep(3000);
    printf("no seu nivel atual voce nao vai arranhar o lorde orc!\n"); Sleep(3000);
    printf("mas eu posso encantar sua arma. Deseja?\n");
    printf("1. Sim\n2. Nao\nEscolha: ");

    int escolha;
    scanf("%d", &escolha);

    if(escolha == 1) {
        nivel_arma = 2;
        tem_chave++; // da a chave para abrir a porta
        if(arma == 1) printf("\nagora sua espada tem um alcance maior!\n");
        if(arma == 2) printf("\nagora seu arco atira mais longe!\n");
        if(arma == 3) printf("\nagora seu cajado recebeu um poder ainda maior!\n");
        printf("e tome esta chave para seguir em frente.\n");
    } else {
        printf("\ncomo quiser, aventureiro. Boa sorte assim mesmo!\n");
    }
    Sleep(2000); system("cls");
}

void dialogo_lord() {
    system("cls");
    printf("        +-----------------------------+\n");
    printf("        |          LORD ORC           |\n");
    printf("        +-----------------------------+\n");
    Sleep(1000); system("cls");
    printf("ORRRRR\n"); Sleep(1000);
    printf("orrrr orrr orororr\n"); Sleep(1000);
    printf("orrrr orrr orr orororr\n"); Sleep(1000);
}

void vitoria() {
    system("cls");
    printf("        +-----------------------------+\n");
    printf("        |           VITORIA           |\n");
    printf("        +-----------------------------+\n");
    Sleep(2000); system("cls");
    printf("parabens voce venceu!\n"); Sleep(1000);
    printf("agradeco por voce ter jogado o meu jogo\n"); Sleep(1000);
    printf("espero que voce tenha gostado\n"); Sleep(3000);
    system("cls");
    printf("        +-----------------------------+\n");
    printf("        |           CREDITOS          |\n");
    printf("        +-----------------------------+\n");
    Sleep(1500);
    printf("Desenvolvido por:\nbattata\n"); Sleep(1500);
    printf("obrigado por jogar!\n"); Sleep(2000);
    exit(0);
}

void interacao() {
    int frente_l = jl, frente_c = jc;
    if(jd == '^') frente_l--;
    if(jd == 'v') frente_l++;
    if(jd == '<') frente_c--;
    if(jd == '>') frente_c++;

    char obj;
    if(fase == 0)      obj = mapa_vila[frente_l][frente_c];
    else if(fase == 1) obj = mapa1[frente_l][frente_c];
    else if(fase == 2) obj = mapa2[frente_l][frente_c];
    else if(fase == 3) obj = mapa3[frente_l][frente_c];
    else               obj = mapa4[frente_l][frente_c];

    if(obj == 'F') { dialogo_ferreiro(); return; }
    if(obj == 'A') { dialogo_npc_a();   return; }
    if(obj == 'B') { dialogo_npc_b();   return; }
    if(obj == 'M') { dialogo_maga();    return; }

    if(obj == '@') {
        tem_chave++;
        if(fase == 0)      mapa_vila[frente_l][frente_c] = ' ';
        else if(fase == 1) mapa1[frente_l][frente_c] = ' ';
        else if(fase == 2) mapa2[frente_l][frente_c] = ' ';
        else if(fase == 3) mapa3[frente_l][frente_c] = ' ';
        else               mapa4[frente_l][frente_c] = ' ';
        printf("\nvoce pegou uma chave! Chaves: %d\n", tem_chave);
        Sleep(800);
    }
    else if(obj == 'D') {
        if(tem_chave > 0) {
            tem_chave--;
            if(fase == 0)      mapa_vila[frente_l][frente_c] = '=';
            else if(fase == 1) mapa1[frente_l][frente_c] = '=';
            else if(fase == 2) mapa2[frente_l][frente_c] = '=';
            else if(fase == 3) mapa3[frente_l][frente_c] = '=';
            else               mapa4[frente_l][frente_c] = '=';
            printf("\nporta aberta!\n");
            Sleep(800);
        } else {
            printf("\nporta fechada!\n");
            Sleep(800);
        }
    }
    if(obj == '$') {
        dinhero_colt++;
        if(fase == 0)      mapa_vila[frente_l][frente_c] = ' ';
        else if(fase == 1) mapa1[frente_l][frente_c] = ' ';
        else if(fase == 2) mapa2[frente_l][frente_c] = ' ';
        else if(fase == 3) mapa3[frente_l][frente_c] = ' ';
        else               mapa4[frente_l][frente_c] = ' ';
        printf("\nvoce pegou dinheiro: %d\n", dinhero_colt);
        Sleep(800);
    }
}

void gamer_over() {
    Sleep(500); system("cls");
    printf("DUNGEON CRAWLER! reiniciando");
    for(i = 0; i < 3; i++) { printf("."); fflush(stdout); Sleep(500); }
    printf("\nvoce morreu! Quer jogar de novo?\n");
    printf("1. sim\n2. nao\nEscolha: ");
    int op;
    scanf("%d", &op);
    switch(op) {
        case 1:
            printf("Reiniciando");
            for(i = 0; i < 3; i++) { printf("."); fflush(stdout); Sleep(500); }
            printf("\naperte qualquer tecla para continuar");
            getch();
            break;
        case 2:
            printf("Ate mais!\n"); exit(0);
            break;
        default:
            printf("Opcao invalida.\n"); gamer_over(); break;
    }
    jl = 17; jc = 3;
    fase = 0;
    vida_jogador = 3;
    tem_chave = 0;
    nivel_arma = 1;
    arma = 0;
}

void movimento_jogador(char teclas) {
    int nova_jl = jl, nova_jc = jc;

    if(teclas == 'w'){ nova_jl--; jd = '^'; }
    if(teclas == 's'){ nova_jl++; jd = 'v'; }
    if(teclas == 'a'){ nova_jc--; jd = '<'; }
    if(teclas == 'd'){ nova_jc++; jd = '>'; }

    char celula;
    if(fase == 0)      celula = mapa_vila[nova_jl][nova_jc];
    else if(fase == 1) celula = mapa1[nova_jl][nova_jc];
    else if(fase == 2) celula = mapa2[nova_jl][nova_jc];
    else if(fase == 3) celula = mapa3[nova_jl][nova_jc];
    else               celula = mapa4[nova_jl][nova_jc];

    if(celula != '*' && celula != 'D' && celula != 'k'
       && celula != 'F' && celula != 'M' && celula != 'B' && celula != 'A') {
        jl = nova_jl;
        jc = nova_jc;
    }

    
    if(celula == '#') {
        vida_jogador--;
        printf("\nVoce perdeu uma vida! Vidas: %d\n", vida_jogador);
        Sleep(800);
    }

    if(vida_jogador <= 0) {
        printf("GAME OVER.\n"); Sleep(500); gamer_over();
    }

    // trocas de fase
    if(fase == 0 && mapa_vila[jl][jc] == '=') {
        system("cls"); printf("\nENTRANDO NA MASMORRA\n");
        for(i=0;i<3;i++){printf(".");fflush(stdout);Sleep(500);}
        fase = 1; jl = 2; jc = 10;
        registro_monster();
    }
    if(fase == 1 && mapa1[jl][jc] == 'L') {
        system("cls"); printf("\nSEGUNDO ANDAR\n");
        for(i=0;i<3;i++){printf(".");fflush(stdout);Sleep(500);}
        fase = 2; jl = 2; jc = 2;
        registro_monster();
    }
    if(fase == 2 && mapa2[jl][jc] == 'L') {
        system("cls"); printf("\nSALA DO MAGO\n");
        for(i=0;i<3;i++){printf(".");fflush(stdout);Sleep(500);}
        fase = 3; jl = 9; jc = 4;
    }
    if(fase == 3 && mapa3[jl][jc] == 'L') {
        system("cls"); printf("\nANDAR DO BOSS\n");
        for(i=0;i<3;i++){printf(".");fflush(stdout);Sleep(500);}
        fase = 4; jl = 23; jc = 12;
        registrar_boss();
        registro_monster();
        dialogo_lord();
    }
}

void menu() {
    Sleep(500); system("cls");
    printf("DUNGEON CRAWLER! iniciando");
    for(i=0;i<3;i++){printf(".");fflush(stdout);Sleep(500);}
    printf("\n Bem-vindo ao jogo DUNGEON CRAWLER!\n");
    printf("1. Jogar\n");
    printf("2. Tutorial\n");
    printf("3. Sair\n");
    printf("Escolha uma opcao: ");
    int op;
    scanf("%d", &op);
    switch(op) {
        case 1:
            printf("Iniciando o jogo");
            for(i=0;i<3;i++){printf(".");fflush(stdout);Sleep(500);}
            printf("\naperte qualquer tecla para continuar");
            getch();
            break;
        case 2:
            system("cls");
            printf("=== TUTORIAL ===\n\n");
            printf("CONTROLES:\n");
            printf("  w/a/s/d  mover\n");
            printf("  i        interagir\n");
            printf("  o        atacar\n\n");
            printf("SIMBOLOS:\n");
            printf("  *  parede    #  espinho\n");
            printf("  k  caixa     @  chave\n");
            printf("  D  porta     =  porta aberta\n");
            printf("  L  escada    X  monstro aleatorio\n");
            printf("  Y  perseguidor  Z  boss\n\n");
            printf("Pressione qualquer tecla para voltar...\n");
            getch();
            menu();
            break;
        case 3:
            system("cls");
            printf("=== CREDITOS ===\n\n");
            printf("Desenvolvido por:\n  battata\n\n");
            printf("Obrigado por jogar!\n");
            Sleep(2000); exit(0);
            break;
        default:
            printf("Opcao invalida.\n"); menu(); break;
    }
}

void registro_monster() {
    num_monster = 0;
    int lmax, cmax;

    if(fase == 1)      { lmax = linha;    cmax = coluna; }
    else if(fase == 2) { lmax = linha_m2; cmax = coluna_m2; }
    else               { lmax = linha_ul; cmax = coluna_ul; }

    for(i = 0; i < lmax; i++) {
        for(j = 0; j < cmax; j++) {
            char cel;
            if(fase == 1)      cel = mapa1[i][j];
            else if(fase == 2) cel = mapa2[i][j];
            else               cel = mapa4[i][j];

            if(cel == 'X') { l_m[num_monster]=i; c_m[num_monster]=j; t_m[num_monster]=1; num_monster++; }
            if(cel == 'Y') { l_m[num_monster]=i; c_m[num_monster]=j; t_m[num_monster]=2; num_monster++; }
        }
    }
}

void movimento_monster() {
    for(m = 0; m < num_monster; m++) {
        int nova_l = l_m[m], nova_c = c_m[m];

        if(t_m[m] == 1) {
            int dir = rand() % 4;
            if(dir == 0) nova_l--;
            if(dir == 1) nova_l++;
            if(dir == 2) nova_c--;
            if(dir == 3) nova_c++;
        }
        if(t_m[m] == 2) {
            int dl = jl - l_m[m], dc = jc - c_m[m];
            if(abs(dl) >= abs(dc)) { if(dl > 0) nova_l++; else nova_l--; }
            else                   { if(dc > 0) nova_c++; else nova_c--; }
        }

        char destino;
        if(fase == 1)      destino = mapa1[nova_l][nova_c];
        else if(fase == 2) destino = mapa2[nova_l][nova_c];
        else               destino = mapa4[nova_l][nova_c];

        if(destino == '*' || destino == '#' || destino == 'X' || destino == 'Y') continue;

        if(fase == 1) {
            mapa1[l_m[m]][c_m[m]] = ' '; l_m[m]=nova_l; c_m[m]=nova_c;
            mapa1[l_m[m]][c_m[m]] = (t_m[m]==1)?'X':'Y';
        } else if(fase == 2) {
            mapa2[l_m[m]][c_m[m]] = ' '; l_m[m]=nova_l; c_m[m]=nova_c;
            mapa2[l_m[m]][c_m[m]] = (t_m[m]==1)?'X':'Y';
        } else {
            mapa4[l_m[m]][c_m[m]] = ' '; l_m[m]=nova_l; c_m[m]=nova_c;
            mapa4[l_m[m]][c_m[m]] = (t_m[m]==1)?'X':'Y';
        }

        if(l_m[m] == jl && c_m[m] == jc) {
            vida_jogador--;
            printf("um inimigo te atacou! Vidas: %d\n", vida_jogador);
            Sleep(500);
            if(vida_jogador <= 0) gamer_over();
        }
    }
}

void movimento_boss() {
    boss_turno++;
    boss_fase = (boss_turno % 8 < 4) ? 0 : 1;

    if(boss_fase == 0) {
        int dl = (rand()%3)-1, dc = (rand()%3)-1;
        int al = boss_l+dl, ac = boss_c+dc;
        if(al > 0 && al < linha_ul-1 && ac > 0 && ac < coluna_ul-1)
            if(mapa4[al][ac] == ' ') mapa4[al][ac] = '#';
    }
    if(boss_fase == 1) {
        int nova_l = boss_l, nova_c = boss_c;
        int dl = jl-boss_l, dc = jc-boss_c;
        if(abs(dl) >= abs(dc)) { if(dl > 0) nova_l++; else nova_l--; }
        else                   { if(dc > 0) nova_c++; else nova_c--; }

        if(mapa4[nova_l][nova_c] == ' ') {
            mapa4[boss_l][boss_c] = ' ';
            boss_l = nova_l; boss_c = nova_c;
            mapa4[boss_l][boss_c] = 'Z';
        }
    }
    if(boss_l == jl && boss_c == jc) {
        vida_jogador--;
        printf("O BOSS TE ACERTOU! Vidas: %d\n", vida_jogador);
        Sleep(800);
        if(vida_jogador <= 0) gamer_over();
    }
}

void registrar_boss() {
    for(i = 0; i < linha_ul; i++)
        for(j = 0; j < coluna_ul; j++)
            if(mapa4[i][j] == 'Z') { boss_l = i; boss_c = j; }
}

int main() {
    char teclas;
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");
    menu();

    while(1) {
        if(fase == 0)      desenhar(mapa_vila);
        else if(fase == 1) desenhar(mapa1);
        else if(fase == 2) desenhar(mapa2);
        else if(fase == 3) desenhar(mapa3);
        else               desenhar(mapa4);

        printf(" Mova com w a s d: %c\n", teclas);
        teclas = getch();

        if(teclas == 'i')      interacao();
        else if(teclas == 'o') ataque();
        else                   movimento_jogador(teclas);

        if(fase > 0) movimento_monster();
        if(fase == 4) movimento_boss();
    }
    return 0;
}