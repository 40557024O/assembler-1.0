typedef struct line *obcode_ptr;
typedef struct line
{
    char *label=0;
    char *mnemonic=0;
    char *symbolic=0;
    int format;
}obcode;
bool optab(char opcode[],char value[]);
bool assembler_directive(char opcode[]);
void formattab(obcode_ptr A);
void symtab_insert(char label[],int loc);
bool symtab_find(char label[]);
