#include <iostream>
#include <fstream>
#include <cstring>

char errMsg[100];
char buff[100];
int varCount = 0;
int functCount = 0;
int fd;

enum nodetype {
    OPERATOR = 1,
    IDENTIFICATOR = 2,
    NUMAR = 3,
    NUMAR_FLOAT = 4
};

struct info_var {
    int int_val;
    float float_val;
    char char_val;
    char string_val[500];
};

struct variabila {
    char nume[100];
    char tip[10];
    int isConst;
    int inClass;
    int arrSize;
    int arr[100];
    struct info_var info;
} symbolTable[100];

struct param {
    char nume[200];
    char tip[20];
} temp[10];

struct func {
    char nume[200];
    char tip[20];
    unsigned int nrArgs;
    int inClass;
    char tipParam[200];
    struct param val[30];
} symbolTableFunction[200];


void print_error()
{
    std::cout << "Eroare: " << errMsg << "\n";
}

void initialize()
{
    for(int i = 0; i < 100; i++)
    {
        memset(symbolTable[i].nume, 0, sizeof(symbolTable[i].nume));
        memset(symbolTable[i].tip, 0, sizeof(symbolTable[i].tip));
        symbolTable[i].info.int_val = 0;
        symbolTable[i].info.float_val = 0;
        symbolTable[i].arrSize = 0;
        strcpy(symbolTable[i].info.string_val, "");
        symbolTable[i].info.char_val = '\0';
    }
}

/*add nume clasa*/
void addInTable(int isconst, int arrsize, const char s[], const char tip[], int val_int, float val_float, const char *carac, const char *strv, int inclasa, int yylineno)
{
   /*declaratieVariabila(Clasa)*/

   if(strcmp(tip, "tip") == 0)
   {
      int aux = varCount - 1;

      while(strcmp(symbolTable[aux].tip, "") == 0 && aux >= 0)
      {
         strcpy(symbolTable[aux].tip, s);
         symbolTable[aux].isConst = isconst;
         symbolTable[aux].inClass = inclasa;
         aux--;
      }
   }
   else
   {
      /*lista_id*/

      if(strcmp(tip, "variabila") == 0)
      {
         int esteDejaDecl = 0;

         for(int i = 0; i < varCount; i++)
         {
            if(strcmp(symbolTable[i].nume, s) == 0)
            {
               esteDejaDecl = 1;
               break;
            }
         }

         if(esteDejaDecl)
         {
            std::sprintf(errMsg, "Linia %d, variabila %s a mai fost declarata!",yylineno, s);
            print_error();
            exit(EXIT_FAILURE);
         }
         else
         {
            strcpy(symbolTable[varCount].nume, s);
            symbolTable[varCount].arrSize = arrsize;
            symbolTable[varCount].info.int_val = val_int;
            symbolTable[varCount].info.float_val = val_float;
            symbolTable[varCount].info.char_val = carac[0];
            strcpy(symbolTable[varCount].info.string_val, strv);
            varCount++;
         }
      }
   }
}

void Verif(char s[], int yylineno, int vec)
{
   /*statement*/

   int i;
   int existaVariabila = 0;

   for(i = 0; i < varCount; i++)
   {
      if(strcmp(symbolTable[i].nume, s) == 0)
      {
         existaVariabila = 1;
         break;
      }
   }

   if(existaVariabila == 0)
   {
      std::sprintf(errMsg, "Linia %d, variabila %s nu este declarata!",yylineno, s);
      print_error();
      exit(EXIT_FAILURE);
   }
   else
   {
     /*nu e array, dar s a specificat o dimensiune*/
     if(vec > 0 && symbolTable[i].arrSize  == 0)
     {
        std::sprintf(errMsg, "Linia %d, variabila %s nu este un array!",yylineno, s);
        print_error();
        exit(EXIT_FAILURE);
     }
     else if(vec == 0 && symbolTable[i].arrSize > 0)
     {
        /*e array, dar nu s-a specificat o dimensiune*/

        std::sprintf(errMsg, "Linia %d, variabila %s este un array!",yylineno, s);
        print_error();
        exit(EXIT_FAILURE);
     }
   }
}

/*add nume clasa*/

void addInTableFunction(const char tipp[], const char s[], const char type[], int yylineno, int clasa, char param[])
{
    /*declaratieFuntie(Clasa)*/

    if(!strcmp(type, "tip"))
    {
        for(int i = 0; i < functCount; i++)
            if(!strcmp(symbolTableFunction[i].nume, s))
            {
                std::sprintf(errMsg, "Linia %d, functia %s nu este definita!",yylineno, s);
                print_error();
                exit(EXIT_FAILURE);
            }

        strcpy(symbolTableFunction[functCount].nume, s);
        strcpy(symbolTableFunction[functCount].tip, tipp);
        symbolTableFunction[functCount].inClass = clasa;
        symbolTableFunction[functCount].nrArgs = 0;

        memset(symbolTableFunction[functCount].tipParam, 0, sizeof(symbolTableFunction[functCount].tipParam));

        /*list_param, param*/

        if(strcmp(param, ""))
        {
            char *p = strtok(param, ",");
            while(p != NULL)
            {
                char aux[100];
                char p1[100];

                strcpy(p1, strchr(p, ' '));
                strncpy(aux, p, strlen(p) - strlen(p1));/*tip param*/

                strcat(symbolTableFunction[functCount].tipParam, aux);
                strcat(symbolTableFunction[functCount].tipParam, ",");
                strcpy(symbolTableFunction[functCount].val[symbolTableFunction[functCount].nrArgs].tip, aux);
                strcpy(symbolTableFunction[functCount].val[symbolTableFunction[functCount].nrArgs].nume, p + strlen(aux));
                symbolTableFunction[functCount].nrArgs++;
                p = strtok(NULL, ",");
            }
            symbolTableFunction[functCount].tipParam[strlen(symbolTableFunction[functCount].tipParam) - 1] = '\0';
        }
        functCount++;
    }
}

void VerifFct(char s[], char param[], int yylineno)
{
    /*statement*/

    int i;
    int existaFunctie = 0;

    for(i = 0; i < functCount; i++)
    {
        if(!strcmp(symbolTableFunction[i].nume, s))
        {
            existaFunctie = 1;
            break;
        }
    }
    if(!existaFunctie)
    {
        std::sprintf(errMsg, "Linia %d, functia %s nu este definita!",yylineno, s);
        print_error();
        exit(EXIT_FAILURE);
    }
    else
    {
        if(strcmp(param, symbolTableFunction[i].tipParam))
        {
            std::sprintf(errMsg, "Linia %d, functia %s nu este apelata corect!",yylineno, s);
            print_error();
            exit(EXIT_FAILURE);
        }
    }
}

void Clasa(char s[])
{
  /*clasa*/

   int aux = varCount - 1;

   while(symbolTable[aux].inClass && aux >= 0)
   {
      char auxchar[100];
      memset(auxchar, 0, sizeof(auxchar));

      strcpy(auxchar, symbolTable[aux].nume);
      strcpy(symbolTable[aux].nume, s);
      strcat(symbolTable[aux].nume,".");
      strcat(symbolTable[aux].nume, auxchar);
      symbolTable[aux].inClass = 0;

      aux--;
   }

   aux = functCount - 1;

   while(symbolTableFunction[aux].inClass && aux >= 0)
   {
      char auxchar[100];
      memset(auxchar, 0, sizeof(auxchar));

      strcpy(auxchar, symbolTableFunction[aux].nume);
      strcpy(symbolTableFunction[aux].nume, s);
      strcat(symbolTableFunction[aux].nume,".");
      strcat(symbolTableFunction[aux].nume, auxchar);
      symbolTableFunction[aux].inClass = 0;

      aux--;
   }
}

/*pt arbore*/

int getIdValue(char s[], int yylineno)
{
    for(int i = 0; i < varCount; i++)
    {
        if(strcmp(symbolTable[i].nume, s) == 0)
        {
            if(symbolTable[i].arrSize > 0)
            {
                std::sprintf(errMsg, "Linia %d, array %s folosit incorect", yylineno, s);
                print_error();
                exit(EXIT_FAILURE);
            }
            return symbolTable[i].info.int_val;
        }
    }
    return 0;
}

char* getIdType(char s[])
{
    /*statement*/

    for(int i = 0; i < varCount; i++)
        if(!strcmp(symbolTable[i].nume, s))
            return symbolTable[i].tip;
    return (char *)"no type";
}

class AST {
public:
  char nume[50];
  AST* st;
  AST *dr;
  nodetype nodeType;

  AST(const char* nume, AST* st, AST* dr, nodetype type) {
    strcpy(this->nume, strdup(nume));
    this->st = st;
    this->dr = dr;
    this->nodeType = type;
  }

private:
  static void evalAST(class AST* tree, int yylineno);
};

int evalAST(class AST* tree, int yylineno)
{
    if(tree->st == nullptr && tree->dr == nullptr)
    {
        if(tree->nodeType == IDENTIFICATOR)
        {
            char tip[10];
            memset(tip, 0, 10);
            strcpy(tip, getIdType(tree->nume));
            if(!strcmp(tip, "char"))
            {
                std::sprintf(errMsg, "Linia %d: variabila %s este de tip char!", yylineno, tree->nume);
                print_error();
                exit(EXIT_FAILURE);
            }
            else
            if(!strcmp(tip, "string"))
            {
                std::sprintf(errMsg, "Linia %d: variabila %s este de tip string!", yylineno, tree->nume);
                print_error();
                exit(EXIT_FAILURE);
            }
            else
            {
                if(!strcmp(tip, "int"))
                    return getIdValue(tree->nume, yylineno);
           }
        }
        else
        {
            if(tree->nodeType == NUMAR)
                return atoi(tree->nume);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        int val_stanga, val_dreapta;
        val_stanga = evalAST(tree->st, yylineno);
        val_dreapta = evalAST(tree->dr, yylineno);
        if(!strcmp(tree->nume, "+")) {return val_stanga + val_dreapta;}
        if(!strcmp(tree->nume, "-")) {return val_stanga - val_dreapta;}
        if(!strcmp(tree->nume, "*")) {return val_stanga * val_dreapta;}
        if(!strcmp(tree->nume, "/"))
        {
            if(val_dreapta) {return val_stanga / val_dreapta;}
            else
            {
                std::sprintf(errMsg, "Linia %d, impartirea la 0 nu se poate efectua!", yylineno);
                print_error();
                exit(EXIT_FAILURE);
            }
        }
    }
    return 0;
}

const char *TypeOf(class AST* tree, float nrfloat, int boolval, char sir_str[], char chr_sir[], int yylineno)
{
    if(tree == nullptr)
    {
        if(nrfloat != 0)
            return (char*)"float";
        if(boolval != 0)
            return (char*)"bool";
        if(strcmp(sir_str, ""))
            return (char*)"string";
        if(strcmp(chr_sir, ""))
            return (char*)"char";
    }
    else
    {
        if(tree->st == nullptr && tree->dr == nullptr)
        {
            if(tree->nodeType == IDENTIFICATOR)
            {
                char tip[10];
                memset(tip, 0, 10);
                strcpy(tip, getIdType(tree->nume));
                if(!strcmp(tip, "int"))
                    return (char*)"int";
                if(!strcmp(tip, "bool"))
                    return (char*)"bool";
                if(!strcmp(tip, "float"))
                    return (char*)"float";
            }
            else
            {
                int x = evalAST(tree, yylineno);
                return "int";
            }
        }
    }
    return nullptr;
}

int Eval(class AST* tree, int yylineno) {
   return  evalAST(tree, yylineno);
}

int getArrVal(const char nume[], int id, int yylineno)
{
    for(int i = 0; i < varCount; i++)
    {
        if(!strcmp(symbolTable[i].nume, nume))
        {
            if(symbolTable[i].arrSize >= id)
                return symbolTable[i].arr[id];
            else
            {
                std::sprintf(errMsg, "Linia %d, pozitie depasita!", yylineno);
                print_error();
                exit(EXIT_FAILURE);
            }
        }
    }
    std::sprintf(errMsg, "Linia %d, array inexistent!", yylineno);
    print_error();
    return 0;
}

void actualizareTabel(const char nume[], const char tip[], int value, int yylineno, float fvalue, const char svalue[])
{
    for(int i = 0; i < varCount; i++)
    {
        if(!strcmp(symbolTable[i].nume, nume))
        {
            if(strcmp(symbolTable[i].tip, tip))
            {
                std::sprintf(errMsg, "Linia %d, tip de date diferit!", yylineno);
                print_error();
                exit(EXIT_FAILURE);
            }
            if(!strcmp(tip, "int") || !strcmp(tip, "bool"))
                symbolTable[i].info.int_val = value;
            else
                if(!strcmp(tip, "float"))
                    symbolTable[i].info.float_val = fvalue;
                else
                    if(!strcmp(tip, "string"))
                        strcpy(symbolTable[i].info.string_val, svalue);
                    else
                        if(!strcmp(tip, "char"))
                            symbolTable[i].info.char_val = svalue[1];
            break;
        }
    }
}

char *ConstrRaspuns(const char sir1[], const char sir2[], const char inter[2])
{
    char *p;
    p = (char*)(malloc(strlen(sir1) + strlen(sir2) + 1));
    strcpy(p, sir1);
    strcat(p, inter);
    strcat(p, sir2);
    return p;
}

char *FctRetType(char fct[])
{
    for(int i = 0; i < functCount; i++)
        if(!strcmp(symbolTableFunction[i].nume, fct))
            return symbolTableFunction[i].tip;
    return nullptr;
}

void printVars(std::ofstream& fd)
{
    char sp[2];
    strcpy(sp, " ");

    for (int i = 0; i < varCount; i++) {
        fd << symbolTable[i].nume << " ";
        fd << sp;
        if(symbolTable[i].isConst == 1)
        fd << "const ";
        fd << symbolTable[i].tip << " ";
        fd << sp;

        if (!strcmp(symbolTable[i].tip, "int")) {fd << symbolTable[i].info.int_val;}
        else if (!strcmp(symbolTable[i].tip, "string")) {fd << symbolTable[i].info.string_val;}
        else if (!strcmp(symbolTable[i].tip, "float")) {fd << symbolTable[i].info.float_val;}
        else if (!strcmp(symbolTable[i].tip, "char")) {fd << symbolTable[i].info.char_val;}
        else if (!strcmp(symbolTable[i].tip, "bool")) {
           if(symbolTable[i].info.int_val == 1) fd << "true";
           else fd<<"false";}
        fd << "\n";
    }
}

void printFunctions(std::ofstream& fd) 
{
    char sp[2];
    strcpy(sp, " ");

    for (int i = 0; i < functCount; i++) {
        fd << symbolTableFunction[i].tip << " ";
        fd << sp;
        fd << symbolTableFunction[i].nume << " ";
        fd << sp;
        fd << "(";

        for (int j = 0; j < symbolTableFunction[i].nrArgs - 1; j++) {
            fd << symbolTableFunction[i].val[j].tip << symbolTableFunction[i].val[j].nume << ",";
            fd << sp;
        }

        if (symbolTableFunction[i].nrArgs != 0) {
            fd << symbolTableFunction[i].val[symbolTableFunction[i].nrArgs - 1].tip;
            fd << symbolTableFunction[i].val[symbolTableFunction[i].nrArgs - 1].nume;
        }

        fd << ")";
        fd << "\n";
    }
}
