#include<stdio.h>
#include<string.h>
#include"table.h"
#include <stdlib.h>
#include"sicxe.h"
int main()
{
    char filename[20];
    printf("Please input file name(.txt)...\n");
    scanf("%s",filename);
    strcat(filename,".txt");

    FILE *fp=fopen(filename,"r");
    /*file does not open sucess*/
    if(!fp)
    {
        printf("the file doesn't open successfully.\n");
        return 1;
    }

    char s[20]= {};
    char opcode[10]= {};
    int LOCCTR=0;
    int starting_pos=0;
    obcode_ptr A;
    FILE *fp2=fopen("intermediate.txt","w");



    /*read the first line*/
    fscanf(fp,"%[^\n]%*c",s);
    /*cut the line into several token*/
    char *temp=strtok(s,"  \t");
    resettoken(A);
    token(temp,opcode,A);

    FILE *fp3=fopen("symbol_table.txt","w");

    while(!feof(fp))
    {
        if(!strcmp(A->mnemonic,"START"))
        {
            starting_pos=atoi(A->symbolic);
            LOCCTR=atoi(A->symbolic);
            /*write this line into intermediate.txt*/
            fprintf(fp2,"%X\t%s\t%s\t%s\n",LOCCTR,A->label,A->mnemonic,A->symbolic);
            fprintf(fp3,"%X\t%s\n",LOCCTR,A->label);
            //printf("%X\t%s\t%s\t%s\n",LOCCTR,A->label,A->mnemonic,A->symbolic);
            /*read next line*/
            fscanf(fp,"%[^\n]%*c",s);
            temp=strtok(s,"  \t");
            resettoken(A);
            token(temp,opcode,A);

        }
        else
        {
            LOCCTR=0;
            /*while opcode!=end*/
            while(strcmp(A->mnemonic,"END"))
            {
                fprintf(fp2,"%X\t%s\t%s\t%s\n",LOCCTR,A->label,A->mnemonic,A->symbolic);
                //printf("%X\t%s\t%s\t%s\n",LOCCTR,A->label,A->mnemonic,A->symbolic);
                /*if this line has label*/
                if (strlen(A->label) != 0)//( A->label != NULL &&strlen(A->label) != 0)
                {
                    if(symtab_find(A->label))
                    {
                        //設定錯誤旗標

                    }
                    else
                    {
                        //將label,LOCCTR插入
                        symtab_insert(A->label,LOCCTR);
                        printf("%X\t%s\t\n",LOCCTR,A->label);
                        fprintf(fp3,"%X\t%s\n",LOCCTR,A->label);
                    }
                }
                /*find opcode in optab*/
                if(optab(A->mnemonic,opcode)||A->format==4)
                {
                   formattab(A);
                   LOCCTR=LOCCTR+A->format;
                }
                else if(!strcmp(A->mnemonic,"WORD"))
                {
                    LOCCTR=LOCCTR+3;
                }
                else if(!strcmp(A->mnemonic,"RESW"))
                {
                    LOCCTR=LOCCTR+3*atoi(A->symbolic);
                }
                else if(!strcmp(A->mnemonic,"RESB"))
                {
                    LOCCTR=LOCCTR+atoi(A->symbolic);
                }
                else if(!strcmp(A->mnemonic,"BYTE"))
                {
                    LOCCTR=LOCCTR+countbyte(A->symbolic);
                }
                else
                {
                    /*設定錯誤旗標*/
                }




                /*read next line*/
                fscanf(fp,"%[^\n]%*c",s);
                temp=strtok(s,"  \t");
                resettoken(A);
                token(temp,opcode,A);

            }
            /*write the last line into intermediate.txt*/
            fprintf(fp2,"%s\t%s\t%s\n",A->label,A->mnemonic,A->symbolic);
            //printf("%X\t%s\t%s\t%s\n",LOCCTR,A->label,A->mnemonic,A->symbolic);
            /*save length of program*/
            int program_length=LOCCTR-starting_pos;
            fprintf(fp2,"program_length= %X ",program_length);



        }
    }
    fclose(fp3);
    fclose(fp);
    fclose(fp2);
}
