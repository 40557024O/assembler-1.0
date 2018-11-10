#include<stdio.h>
#include"table.h"
#include"sicxe.h"
#include<string.h>
void token(char tok[],char opcode[],obcode_ptr A)
{
    for(int i=0; tok!=NULL; i++)
    {
        if(format4(tok))
        {
            A->format=4;
            A->mnemonic=tok;
        }
        else if(optab(tok,opcode)||assembler_directive(tok))
        {
            A->mnemonic=tok;
        }
        else if (i==0)
        {
            A->label=tok;
        }
        else
        {
            A->symbolic=tok;
        }
        tok=strtok(NULL," \t");

    }
}

bool format4(char mnemonic[])
{
    if(mnemonic[0]=='+')
    {
        return true;
    }
    return false;
}

int countbyte(char symbolic[])
{
    int LOCCTR=0;

    if(symbolic[0]=='C')
    {
        char *temp=strtok(symbolic,"'C");
        LOCCTR=strlen(temp);

    }
    else if(symbolic[0]=='X')
    {
        char *temp=strtok(symbolic,"'X");
        LOCCTR=strlen(temp)/2;
    }
    return LOCCTR;

}
void resettoken(obcode_ptr A)
{
    A->label="";
    A->mnemonic="";
    A->symbolic="";
    A->format=3;
}

