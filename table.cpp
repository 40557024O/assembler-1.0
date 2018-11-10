#include<stdio.h>
#include<iostream>
#include <unordered_map>
#include<string.h>
#include"table.h"

using namespace std;

bool optab(char opcode[],char value[])
{

    //declaration container and iterator
    std::unordered_map<std::string,std::string> optab;
    //optab<string, string>::iterator iter;
    //optab<string, string>::reverse_iterator iter_r;

    //insert element
    optab["ADD"]="18";
    optab["ADDF"]="58";
    optab["ADDR"]="90";
    optab["AND"]="40";
    optab["CLEAR"]="B4";
    optab["COMP"]="28";
    optab["COMPF"]="88";
    optab["COMPR"]="A0";
    optab["DIV"]="24";
    optab["DIVF"]="64";
    optab["DIVR"]="9C";
    optab["FIX"]="C4";
    optab["FLOAT"]="C0";
    optab["HIO"]="F4";
    optab["J"]="3C";
    optab["JEQ"]="30";
    optab["JGT"]="34";
    optab["JLT"]="38";
    optab["JSUB"]="48";
    optab["LDA"]="00";
    optab["LDB"]="68";
    optab["LDCH"]="50";
    optab["LDF"]="70";
    optab["LDL"]="08";
    optab["LDS"]="6C";
    optab["LDT"]="74";
    optab["LDX"]="04";
    optab["LPS"]="D0";
    optab["MUL"]="20";
    optab["MULF"]="60";
    optab["MULR"]="98";
    optab["NORM"]="C8";
    optab["OR"]="44";
    optab["RD"]="D8";
    optab["RMO"]="AC";
    optab["RSUB"]="4C";
    optab["SHFTL"]="A4";
    optab["SHFTR"]="A8";
    optab["SIO"]="F0";
    optab["SSK"]="EC";
    optab["STA"]="0C";
    optab["STB"]="78";
    optab["STCH"]="54";
    optab["STF"]="80";
    optab["STI"]="D4";
    optab["STL"]="14";
    optab["STS"]="7C";
    optab["STSW"]="E8";
    optab["STT"]="84";
    optab["STX"]="10";
    optab["SUB"]="1C";
    optab["SUBF"]="5C";
    optab["SUBR"]="94";
    optab["SVC"]="B0";
    optab["TD"]="E0";
    optab["TIO"]="F8";
    optab["TIX"]="2C";
    optab["TIXR"]="B8";
    optab["WD"]="DC";

    std::unordered_map<std::string,string>::const_iterator got = optab.find (opcode);
    /*find if the string in optable*/
    if ( got == optab.end() )
    {
        return false;
    }
    else
    {   /*turn the value into char*/
        strcpy(value,got->second.c_str());
        return true;
    }

}

bool assembler_directive(char opcode[])
{
    std::unordered_map<std::string,std::string> adtab;
    adtab["START"]=1;
    adtab["END"]=1;
    adtab["RESW"]=1;
    adtab["RESB"]=1;
    adtab["WORD"]=1;
    adtab["BYTE"]=1;
    adtab["BASE"]=1;
    std::unordered_map<std::string,string>::const_iterator got = adtab.find (opcode);
    /*find if the string in optable*/
    if ( got == adtab.end() )
    {
        return false;
    }
    else
    {
        return true;
    }

}

void formattab(obcode_ptr A)
{
    std::unordered_map<std::string,int> formattab;
    formattab["ADDR"]=2;
    formattab["CLEAR"]=2;
    formattab["COMPR"]=2;
    formattab["DIVR"]=2;
    formattab["FIX"]=1;
    formattab["FLOAT"]=1;
    formattab["HIO"]=1;
    formattab["MULR"]=2;
    formattab["RMO"]=2;
    formattab["SHFLT"]=2;
    formattab["SIO"]=1;
    formattab["SUBR"]=2;
    formattab["SVC"]=2;
    formattab["TIO"]=1;
    formattab["TIXR"]=2;
    std::unordered_map<std::string,int>::const_iterator got = formattab.find (A->mnemonic);
    /*find if the string in optable*/
    if ( got != formattab.end() )
    {
        A->format=got->second;
    }

}


void symtab_insert(char label[],int loc)
{
    std::unordered_map<std::string,int> symtab;
    symtab[label]=loc;
}

bool symtab_find(char label[])
{
    std::unordered_map<std::string,int> symtab;
    std::unordered_map<std::string,int>::const_iterator got = symtab.find (label);
    /*find if the string in optable*/
    if ( got == symtab.end() )
    {
        return false;
    }
    else
    {
        return true;
    }

}
