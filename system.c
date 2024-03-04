#include<stdio.h>
#include<string.h>
#include<ctype.h>


//funcao menu principal
char funcaoMenu(char m)
{
    printf("\n[A] CADASTRO\n");
    printf("[B] EXCLUSAO\n");
    printf("[C] LANCAMENTO\n");
    printf("[D] RELATORIO\n");
    printf("[ESC] FINALIZAR\n\n");
    fflush(stdin);
    m=getch();
    m=toupper(m);
    return m;
}

//funcao do menu do cadastro
char funcaoMenuCadastro(char m)
{
    printf("\n[A] MEDICOS\n");
    printf("[B] PACIENTES\n");
    printf("[C] PROCEDIMENTOS\n");
    printf("[ESC] RETORNAR\n\n");
    fflush(stdin);
    m=getch();
    m=toupper(m);
    return m;
}

int main ()
{
    char menu,menu_cadastro;

    //funcao do menu principal junto com o while principal (ESC ENCERRA)
    menu=funcaoMenu(menu);
    while(menu!=27)
    {
        switch(menu)
        {
            //case do menu de cadastro junto com a funcao
            case 'A':
                menu_cadastro=funcaoMenuCadastro(menu_cadastro);
            break;

            case 'D':
                menu_cadastro=funcaoMenuCadastro(menu_cadastro);
            break;
        }
        menu=funcaoMenu(menu);
    }
}