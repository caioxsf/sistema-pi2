#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include <windows.h>
#include <conio.h>
#define NAME 100
#define TF 100

typedef struct
{
    int codigo; // para verificar antes de colocar no vetor vMed
    int vMed; // vetor com o codigo do medico
    char vMedico[NAME]; // string com o nome do medico
}Medico;

typedef struct
{
      int paciente; // para verificar antes de colocar no vetor vPac
      int vPac; // vetor com o codigo do paciente
      char vPaciente[NAME]; // string com o nome do paciente
}Paciente;

typedef struct
{
    int procedimento; // para verificar antes de colocar no vetor vProc
    int vProc; // vetor com o codigo do procedimento
    char vProcedimento[NAME]; // string com o nome do procedimento
}Procedimento;

typedef struct 
{
    int lanc_med;
    int lanc_pac;
    int lanc_proc;
}Lancamento;

typedef struct
{
    Medico m;
    Paciente p;
    Procedimento proc;
    Lancamento lanc;
    int dia, mes, ano;
}Data;

//pesquisei como faz o gotoxy, ainda nao aprendi ao certo na faculdade

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//funcao de Cadastro de Medico
void funcaoCadastroMedico(Medico auxM[TF], int *tl)
{
    int cadastro,i;
    printf("CRM DO MEDICO: ");
    scanf("%d", &auxM[*tl].codigo);
    while(auxM[*tl].codigo!=0)
    {   
        if(*tl==0)
        {
            printf("NOME DO MEDICO: "); fflush(stdin);
            gets(auxM[*tl].vMedico);
            auxM[*tl].vMed=auxM[*tl].codigo;
            printf("\nCODIGO: %d - NOME: %s\n", auxM[*tl].vMed, auxM[*tl].vMedico);
            printf("CADASTRADO COM SUCESSO!\n");
            printf("------------------------------\n");
            (*tl)++;
        }
        else
        {
            cadastro=0;
            for(i=0;i<*tl;i++)
            {
                if(auxM[*tl].codigo==auxM[i].vMed)
                    cadastro++;
            }
            if(cadastro>0)
            {
                printf("CRM JA CADASTRADO NO BANDO DE DADOS!\n");
                printf("------------------------------\n");
            }
            else
            {
                printf("NOME: "); fflush(stdin);
                gets(auxM[*tl].vMedico);
                auxM[*tl].vMed=auxM[*tl].codigo;
                printf("\nCODIGO: %d - NOME: %s\n", auxM[*tl].vMed, auxM[*tl].vMedico);
                printf("CADASTRADO COM SUCESSO!\n");
                printf("------------------------------\n");
                (*tl)++;
            }   
        }
        printf("CRM DO MEDICO: ");
        scanf("%d", &auxM[*tl].codigo);
    }
}

//funcao de Cadastro de Paciente
void funcaoCadastroPaciente(Paciente auxP[TF], int *tl)
{
    int i,cadastro;
    printf("CODIGO DO PACIENTE: ");
    scanf("%d", &auxP[*tl].paciente);
    while(auxP[*tl].paciente!=0)
    {
        if(*tl==0)
        {
            printf("NOME DO PACIENTE: "); fflush(stdin);
            gets(auxP[*tl].vPaciente);
            auxP[*tl].vPac=auxP[*tl].paciente;
            printf("\nCODIGO: %d - NOME: %s\n", auxP[*tl].vPac, auxP[*tl].vPaciente);
            printf("CADASTRADO COM SUCESSO!\n");
            printf("------------------------------\n");
            (*tl)++;
        }
        else
        {
            cadastro=0;
            for(i=0;i<*tl;i++)
            {
                if(auxP[*tl].paciente==auxP[i].vPac)
                    cadastro++;
            }
            if(cadastro>0)
            {
                printf("PACIENTE JA CADASTRADO NO BANDO DE DADOS!\n");
                printf("------------------------------\n");
            }
            else
            {
                printf("NOME DO PACIENTE: "); fflush(stdin);
                gets(auxP[*tl].vPaciente);
                auxP[*tl].vPac=auxP[*tl].paciente;
                printf("\nCODIGO: %d - NOME: %s\n", auxP[*tl].vPac, auxP[*tl].vPaciente);
                printf("CADASTRADO COM SUCESSO!\n");
                printf("------------------------------\n");
                (*tl)++;
            }
        }

        printf("CODIGO DO PACIENTE: ");
        scanf("%d", &auxP[*tl].paciente);
    }

}

//funcao de Cadastro de Procedimento
void funcaoCadastroProcedimento(Procedimento auxProc[TF], int *tl)
{
    int cadastro,i;
    printf("CODIGO DO PROCEDIMENTO: ");
    scanf("%d", &auxProc[*tl].procedimento);
    while(auxProc[*tl].procedimento!=0)
    {
        if (*tl==0)
        {
            printf("NOME DO PROCEDIMENTO: "); fflush(stdin);
            gets(auxProc[*tl].vProcedimento);
            auxProc[*tl].vProc=auxProc[*tl].procedimento;
            printf("\nCODIGO: %d - NOME: %s\n", auxProc[*tl].vProc, auxProc[*tl].vProcedimento);
            printf("CADASTRADO COM SUCESSO!\n");
            printf("------------------------------\n");
            (*tl)++;
        }
        else
        {
            cadastro=0;
            for(i=0;i<*tl;i++)
            {
                if(auxProc[*tl].procedimento==auxProc[i].vProc)
                    cadastro++;
            }
            if(cadastro>0)
            {
                printf("PACIENTE JA CADASTRADO NO BANDO DE DADOS!\n");
                printf("------------------------------\n");
            }
            else
            {
                printf("NOME DO PROCEDIMENTO: "); fflush(stdin);
                gets(auxProc[*tl].vProcedimento);
                auxProc[*tl].vProc=auxProc[*tl].procedimento;
                printf("\nCODIGO: %d - NOME: %s\n", auxProc[*tl].vProc, auxProc[*tl].vProcedimento);
                printf("CADASTRADO COM SUCESSO!\n");
                printf("------------------------------\n");
                (*tl)++;
            }
        }
        printf("CODIGO DO PROCEDIMENTO: ");
        scanf("%d", &auxProc[*tl].procedimento);    
    }
}

void funcaoLancamento(Data auxD[TF], Medico auxM[TF], Procedimento auxProc[TF], Paciente auxP[TF], int *l, int *tm, int *tlpp, int *tp, int *tproc, int *tllanc)
{
    int i, cadC=0, cadP=0, cadProc=0;
    printf("\nLANCAMENTO DE PROCEDIMENTO (0 ENCERRA)\n");
    printf("CRM DO MEDICO: ");
    scanf("%d", &auxD[*l].m.codigo);
    printf("CODIGO DO PACIENTE: ");
    scanf("%d", &auxD[*l].p.paciente);
    printf("CODIGO DO PROCEDIMENTO: ");
    scanf("%d", &auxD[*l].proc.procedimento);

    while(auxD[*l].m.codigo!=0 && auxD[*l].p.paciente!=0 && auxD[*l].proc.procedimento!=0)
    {
        cadC=0;
        for(i=0;i<*tm;i++)
        {
            if(auxD[*l].m.codigo==auxM[i].vMed)
                cadC=1;
        }
        cadP=0;
        for(i=0;i<*tp;i++)
        {
            if(auxD[*l].p.paciente==auxP[i].vPac)
                cadP=1;
        }
        cadProc=0;
        for(i=0;i<*tproc;i++)
        {
            if(auxD[*l].proc.procedimento==auxProc[i].vProc)
                cadProc=1;
        }

        if (cadC==0 || cadP==0 || cadProc==0)
            printf("Ocorreu um erro, tente novamente!\n");
        else
        {
            cadC=0;
            cadP=0;
            cadProc=0;
            for(i=0;i<*tllanc;i++)
            {
                if(auxD[*l].m.codigo==auxD[i].lanc.lanc_med)
                    cadC=1;
            }
            if (cadC==1) 
               printf("Medico ja esta com consulta marcada!\n");
            else
            {
                printf("Dia: ");
                scanf("%d", &auxD[*tlpp].dia);
                printf("Mes: ");
                scanf("%d", &auxD[*tlpp].mes);
                printf("Ano: ");
                scanf("%d", &auxD[*tlpp].ano);
                
                auxD[*tllanc].lanc.lanc_med=auxD[*l].m.codigo; //adiciona o codigo do medico no vetor lanc_med
                auxD[*tllanc].lanc.lanc_pac=auxD[*l].p.paciente; //adiciona o codigo do paciente no vetor lanc_pac
                auxD[*tllanc].lanc.lanc_proc=auxD[*l].proc.procedimento; //adiciona o codigo do paciente no vetor lanc_proc
                printf("\nPROCEDIMENTO CADASTRADO COM SUCESSO!\n");
                printf("------------------------------\n");
                (*tllanc)++;
                (*tlpp)++;
            }
        }

        printf("\nLANCAMENTO DE PROCEDIMENTO (0 ENCERRA)\n");
        printf("CRM DO MEDICO: ");
        scanf("%d", &auxD[*l].m.codigo);
        printf("CODIGO DO PACIENTE: ");
        scanf("%d", &auxD[*l].p.paciente);
        printf("CODIGO DO PROCEDIMENTO: ");
        scanf("%d", &auxD[*l].proc.procedimento);
    }
}

void funcaoExclusao(Data auxD[TF], Medico auxM[TF], Paciente auxP[TF], Procedimento auxProc[TF], int *l, int *tllanc, int *tlm, int *tp, int *tproc)
{
    char m;
    int pos, i, cadM, cadP, cadProc, achou;
    *l=0;


    printf("[A]   MEDICOS\n");
    printf("[B]   PACIENTES\n");
    printf("[C]   PROCEDIMENTOS\n");
    printf("[ESC] RETORNAR\n\n");
    fflush(stdin);
    m=getch();
    m=toupper(m);

    while (m!=27)
    {
        switch(m)
        {
            case 'A':
                printf("CRM DO MEDICO: ");
                scanf("%d", &auxD[*l].m.codigo);
                while(auxD[*l].m.codigo!=0)
                {
                    achou=0;
                    for(i=0;i<*tlm;i++)
                    {
                        if(auxD[*l].m.codigo==auxM[i].vMed)
                            achou=1;
                    }
                    if (achou==1)
                    {
                        cadM=0;
                        for (i=0;i<*tllanc;i++)
                        {
                            if(auxD[*l].m.codigo==auxD[i].lanc.lanc_med)
                                cadM=1;
                        }
                        if (cadM==1)
                            printf("Esse medico ja tem consulta marcada, tente novamente!\n");
                        else
                        {
                            pos=0;
                            while(auxD[*l].m.codigo!=auxM[pos].vMed && pos<*tlm)
                                pos++;
                            if(pos<*tlm)
                            {
                                for(i=pos;i<*tlm;i++)
                                {
                                    auxM[i].vMed=auxM[i+1].vMed;
                                    strcpy(auxM[i].vMedico,auxM[i+1].vMedico);
                                }
                                (*tlm)--;
                                printf("MEDICO EXCLUIDO COM SUCESSO!\n");
                                printf("------------------------------\n");
                            }
                        }
                    }
                    else
                        printf("CRM DO MEDICO NAO ENCONTRADO!\n");
                    
                    printf("CRM DO MEDICO: ");
                    scanf("%d", &auxD[*l].m.codigo);
                }
            break;

            case 'B':
                printf("CODIGO DO PACIENTE: ");
                scanf("%d", &auxD[*l].p.paciente);
                while (auxD[*l].p.paciente!=0)
                {
                    achou=0;
                    for(i=0;i<*tp;i++)
                    {
                        if(auxD[*l].p.paciente==auxP[i].vPac)
                            achou=1;
                    }
                    if(achou==1)
                    {
                        cadP=0;
                        for(i=0;i<*tllanc;i++)
                        {
                            if(auxD[*l].p.paciente==auxD[i].lanc.lanc_pac)
                                cadP=1;
                        }
                        if(cadP==1)
                            printf("Esse paciente ja tem consulta marcada, tente novamente!\n");
                        else
                        {
                            pos=0;
                            while(auxD[*l].p.paciente!=auxP[pos].vPac && pos<*tp)
                                pos++;
                            if(pos<*tp)
                            {
                                for(i=pos;i<*tp;i++)
                                {
                                    auxP[i].vPac=auxP[i+1].paciente;
                                    strcpy(auxP[i].vPaciente,auxP[i+1].vPaciente);
                                }
                                (*tp)--;
                                printf("PACIENTE EXCLUIDO COM SUCESSO!\n");
                                printf("------------------------------\n");
                            }
                        }
                    }
                    else
                        printf("CODIGO DO PACIENTE NAO ENCONTRADO!\n");

                    printf("CODIGO DO PACIENTE: ");
                    scanf("%d", &auxD[*l].p.paciente);
                }
            break;

            case 'C':
                printf("CODIGO DO PROCEDIMENTO: ");
                scanf("%d", &auxD[*l].proc.procedimento);
    
                while(auxD[*l].proc.procedimento!=0)
                {
                    achou=0;
                    for(i=0;i<*tproc;i++)
                    {
                        if(auxD[*l].proc.procedimento==auxProc[i].vProc)
                            achou=1;
                    }
                    if(achou==1)
                    {
                        cadProc=0;
                        for(i=0;i<*tllanc;i++)
                        {
                            if(auxD[*l].proc.procedimento==auxD[i].lanc.lanc_proc)
                                 cadProc=1;
                        }
                        if(cadProc==1)
                             printf("Esse procedimento ja esta sendo usado em uma consulta, tente novamente!\n");
                         else
                        {
                            pos=0;
                            while(auxD[*l].proc.procedimento!=auxProc[pos].vProc && pos<*tproc)
                                pos++;
                            if (pos<*tproc)
                            {
                                for(i=pos;i<*tproc;i++)
                                {
                                    auxProc[i].vProc=auxProc[i+1].vProc;
                                    strcpy(auxProc[i].vProcedimento,auxProc[i+1].vProcedimento);
                                }
                                printf("PACIENTE EXCLUIDO COM SUCESSO!\n");
                                printf("------------------------------\n");
                                (*tproc)--;
                            }
                        }
                    }
                    else
                        printf("CODIGO DO PROCEDIMENTO NAO ENCONTRADO!\n");

                    printf("CODIGO DO PROCEDIMENTO: ");
                    scanf("%d", &auxD[*l].proc.procedimento);
                }
            break;
        }

        system("cls");
        printf("[A]   MEDICOS\n");
        printf("[B]   PACIENTES\n");
        printf("[C]   PROCEDIMENTOS\n");
        printf("[ESC] RETORNAR\n\n");
        fflush(stdin);
        m=getch();
        m=toupper(m);
    }
    
}

void funcaoRelatorio(Medico auxM[TF], Paciente auxP[TF], Procedimento auxProc[TF], int *tlm, int *tlp, int *tlproc)
{
    char m;
    int i,y;
    printf("[A]   MEDICOS\n");
    printf("[B]   PACIENTES\n");
    printf("[C]   PROCEDIMENTOS\n");
    printf("[ESC] RETORNAR\n");
    fflush(stdin);
    m=getch();
    m=toupper(m);
    
    while(m!=27)
    {
        switch(m)
        {
            case'A':
                printf("\nRELATORIO DE MEDICOS!\n");
                y=14;
                for(i=0;i<*tlm;i++)
                {
                    gotoxy(0,y);
                    printf("NOME: [%s]", auxM[i].vMedico);
                    gotoxy(30,y);
                    printf("CODIGO: [%d]\n", auxM[i].vMed);
                    y++;
                }
                system("pause");
                system("cls");
            break;

            case 'B':
                printf("\nRELATORIO DE PACIENTES\n");
                y=14;
                for(i=0;i<*tlp;i++)     
                {
                    gotoxy(0,y);
                    printf("NOME: [%s]", auxP[i].vPaciente);
                    gotoxy(30,y);
                    printf("CODIGO: [%d]\n", auxP[i].vPac);
                    y++;
                }
                system("pause");
                system("cls");
            break;

            case 'C':
                printf("\nRELATORIO DE PROCEDIMENTOS\n");
                y=14;
                for(i=0;i<*tlproc;i++)
                {
                    gotoxy(0,y);
                    printf("NOME: [%s]", auxProc[i].vProcedimento);
                    gotoxy(30,y);
                    printf("CODIGO: [%d]\n", auxProc[i].vProc);
                    y++;
                }
                system("pause");
                system("cls");
            break;
        }
        printf("[A]   MEDICOS\n");
        printf("[B]   PACIENTES\n");
        printf("[C]   PROCEDIMENTOS\n");
        printf("[ESC] RETORNAR\n");
        fflush(stdin);
        m=getch();
        m=toupper(m);
    }

}
//funcao menu principal
char funcaoMenu()
{
    char m;
    printf("[A]   CADASTRO\n");
    printf("[B]   EXCLUSAO\n");
    printf("[C]   LANCAMENTO\n");
    printf("[D]   RELATORIO\n");
    printf("[ESC] FINALIZAR\n\n");
    fflush(stdin);
    m=getch();
    m=toupper(m);
    return m;
}

//funcao do menu do cadastro
char funcaoMenuCadastro()
{
    char m;
    printf("[A]   MEDICOS\n");
    printf("[B]   PACIENTES\n");
    printf("[C]   PROCEDIMENTOS\n");
    printf("[ESC] RETORNAR\n\n");
    fflush(stdin);
    m=getch();
    m=toupper(m);
    return m;
}

int main ()
{
    int TLM=0, TLP=0, TLPR=0, TL=0, TLPP=0, TL_LANC=0;
    int L=0;
    char menu, menu_cadastro;
    Medico auxM[TF];
    Paciente auxP[TF];
    Procedimento auxProc[TF];
    Data auxD[TF];

    //funcao do menu principal junto com o while principal (ESC ENCERRA)
    menu=funcaoMenu();
    while(menu!=27)
    {
        if (menu>=65 && menu<=68)
        {
            switch(menu)
            {
                //case do menu de cadastro junto com a funcao
                case 'A':
                    system("cls");
                    menu_cadastro=funcaoMenuCadastro();
                    switch(menu_cadastro)
                    {
                        case 'A':
                            funcaoCadastroMedico(auxM,&TLM);
                            system("cls");
                        break;

                        case 'B':
                            funcaoCadastroPaciente(auxP,&TLP);
                            system("cls");
                        break;

                        case 'C':
                            funcaoCadastroProcedimento(auxProc,&TLPR);
                            system("cls");
                        break;
                    }
                break;

                case 'B':
                    funcaoExclusao(auxD,auxM,auxP,auxProc,&L,&TL_LANC,&TLM,&TLP,&TLPR);
                    system("cls");
                break;

                case 'C':
                    funcaoLancamento(auxD,auxM,auxProc,auxP,&TL,&TLM,&TLPP,&TLP,&TLPR,&TL_LANC);
                    system("cls");
                break;

                case 'D':
                    funcaoRelatorio(auxM,auxP,auxProc,&TLM,&TLP,&TLPR);
                    system("cls");
                break;
            }
        }
        system("cls");
        menu=funcaoMenu();
    }
}