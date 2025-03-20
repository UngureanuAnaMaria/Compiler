%{
#include "compiler.h"
#include <iostream>
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
%}

/* tipurile de date care vor fi utilizate pentru valorile semantice ale tokenurilor */
%union {
    float floatval;
    int intval;
    char* strval;
    class AST* tree;
}

/* tokenurile folosite in gramatica si tipurile de date asociate lor */

%token <strval> LEQ GEQ NEQ EQ RETURN BFCT EFCT
%token <strval> AND OR
%token <strval> ID
%token <strval> STRING
%token <strval> TIP ASSIGN BGIN END CLASS ECLASS IF EIF ELSE
%token <strval> FOR EFOR CONSTANT WHILE EWHILE DO EVAL TYPEOF
%token <strval> CHAR
%token <intval> NR
%token <floatval> NR_FLOAT
%type <strval> lista_apel
%type <strval> opr 
%type <intval> cond  
%type <intval> cond_expr
%type <strval> param
%type <strval> lista_param
%type <strval> pseudo_e
%type <tree> e
%start progr
%left OR 
%left AND
%left NEQ EQ
%left LEQ GEQ '<' '>'
%left '-' '+'
%left '/' '*'

%{
int yyerror(const char *);
int yylex(void);
%}

%%

/* regula progr indica ca programul incepe cu sectiunea1 si dupa cu rest1 si dupa afiseza un mesaj daca analiza sintactica a fost corecta */
/* regula rest1 indica ca programul continua cu sectiunea2 si apoi cu rest2 */
/* regula rest2 ... sectiunea3 si dupa cu un bloc de cod(tip main de exp) */

progr: sectiunea1 rest1 {std::cout << "program corect sintactic\n";}
     ;

rest1 : sectiunea2 rest2
      ;

rest2 : sectiunea3 bloc
      ;

/* regula sectiunea1 poate contine o declaratie de variabila(sau o succesiune de declaratii) urmat de ; */

sectiunea1 : declaratieVariabila ';'
           | sectiunea1 declaratieVariabila ';'
           ;

sectiunea2 : declaratieFunctie 
           | sectiunea2 declaratieFunctie 
           ;

sectiunea3 : clasa
           | sectiunea3 clasa
           ;

/* regula pt declararea variabilelor in afara claselor. Declaratia incepe cu tipul urmat de o lista de identificatori (*$1 - tipul variabilei) */

declaratieVariabila : TIP lista_id { addInTable(0, 0, $1, "tip", 0, 0, "", "", 0, yylineno); }
                    | CONSTANT TIP lista_id {addInTable(1, 0, $1, "tip", 0, 0, "", "", 0, yylineno);}
                    ;

/* declaratie variabile in clasa  */

declaratieVariabilaClasa : TIP lista_id { addInTable(0, 0, $1, "tip", 0, 0, "", "", 1, yylineno); }
                         | CONSTANT TIP lista_id {addInTable(1, 0, $1, "tip", 0, 0, "", "", 1, yylineno);}
                         ;

/*$9 = e*/

declaratieFunctie : TIP ID '(' lista_param ')' BFCT list EFCT { addInTableFunction($1, $2, "tip", yylineno, 0, $4);}
                  | TIP ID '(' ')' BFCT list EFCT { addInTableFunction($1, $2, "tip", yylineno, 0, nullptr);}
                  | TIP ID '(' lista_param ')' BFCT list RETURN e ';' EFCT { int val = evalAST($9, yylineno); addInTableFunction($1, $2, "tip", yylineno, 0, $4);}
                  | TIP ID '(' ')' BFCT list RETURN e ';' EFCT { int val = evalAST($8, yylineno); addInTableFunction($1, $2, "tip", yylineno, 0, nullptr);}
                  ;

declaratieFunctieClasa : TIP ID '(' lista_param ')' { addInTableFunction($1, $2, "tip", yylineno, 1, $4);}
                       | TIP ID '(' ')' { addInTableFunction($1, $2, "tip", yylineno, 1, nullptr);}
                       ;

/*Daca avem doar un parametru, atunci rezultatul este parametrul respectiv $$ = $1. In caz contrar se apelează functia ConstrRaspuns pentru a construi o reprezentare a intregii liste de parametri*/

lista_param : param {$$ = $1;} 
            | param ',' lista_param { $$ = ConstrRaspuns($1, $3, ",");}
            ;
            
/*se apeleaza functia ConstrRaspuns cu tipul $1 si numele $2, iar rezultatul este asignat variabilei $$*/

param : TIP ID {
                $$ = ConstrRaspuns($1, $2, " ");
               }
      ; 

/*constr o clasa cu numele $2*/

clasa : CLASS ID interior_clasa ECLASS {Clasa($2);}
      ;

sectiuneaclasa1 : declaratieVariabilaClasa ';'
                | sectiuneaclasa1 declaratieVariabilaClasa ';'
                ;

sectiuneaclasa2 : declaratieFunctieClasa ';'
                | sectiuneaclasa2 declaratieFunctieClasa ';'
                ;

interior_clasa : sectiuneaclasa1 sectiuneaclasa2
               | sectiuneaclasa1
               | sectiuneaclasa2
               ;

/*yylineno - linia curenta*/
/*cand avem doar un identificator ID(nume) il add in tabela cu tipul variabila*/
/* ID[nr] vector, $3 dimensiune*/
/*ID ',' lista_id lista identificatori*/
/*ID ASSIGN e, identificatorului i s-a atribuit o expresie, care e evaluata de Eval, si dupa adaugat in tabela valoarea expresiei*/
/*ID ASSIGN NR_FLOAT, CHAR, STRING se atribuie valoarea in tabel $3*/

lista_id : ID {addInTable(0, 0, $1, "variabila", 0, 0, "", "", 0, yylineno);}
         | ID '[' NR ']' { addInTable(0, $3, $1, "variabila", 0, 0, "", "", 0, yylineno);}
         | ID ',' lista_id { addInTable(0, 0, $1, "variabila", 0, 0, "", "", 0, yylineno);}
         | ID '[' NR ']' ',' lista_id { addInTable(0, $3, $1, "variabila", 0, 0, "", "", 0, yylineno);}
         | ID ASSIGN e { int val = Eval($3, yylineno); addInTable(0, 0, $1, "variabila", val, 0, "", "", 0, yylineno);}
         | ID ASSIGN e ',' lista_id { int val = Eval($3, yylineno); addInTable(0, 0, $1, "variabila", 0, 0, "", "", 0, yylineno);}
         | ID ASSIGN NR_FLOAT { addInTable(0, 0, $1, "variabila", 0, $3, "", "", 0, yylineno);}
         | ID ASSIGN NR_FLOAT ',' lista_id { addInTable(0, 0, $1, "variabila", 0, $3, "", "", 0, yylineno);}
         | ID ASSIGN STRING { addInTable(0, 0, $1, "variabila", 0, 0, "", $3, 0, yylineno);}
         | ID ASSIGN STRING ',' lista_id { addInTable(0, 0, $1, "variabila", 0, 0, "", $3, 0, yylineno);}
         | ID ASSIGN CHAR { addInTable(0, 0, $1, "variabila", 0, 0, $3, "", 0, yylineno);}
         | ID ASSIGN CHAR ',' lista_id { addInTable(0, 0, $1, "variabila", 0, 0, $3, "", 0, yylineno);}
         ;
      
/* bloc */
bloc : BGIN list END
     ;

     
/*interioarul unei functii*/

list : statement ';' 
     | list statement ';'
     | list if 
     | list for
     | list do
     | list while
     ;

/* instructiune */
/*def statement*/
/*ID ASSIGN e variabila si verific in Verif daca e deja declarata sau daca face parte dintr un vector, evaluez expresia si actualizez tabela cu tipul si val ei*/
/*ID '(' lista_apel ')' verif daca e deja declarata sau daca exista parametrii $3, adica corect apelata*/
/*pseudo_e e o expresie, TYPEOF'(' pseudo_e ')' afiseaza tipul expr*/
/*ID '.' ID ASSIGN e atribuirea unei expr unei variabile membru a unei clase*/


statement: ID ASSIGN e  { 
                            Verif($1, yylineno, 0);
                            if(strcmp(getIdType($1), "int"))
                            {
                                std::sprintf(errMsg, "Linia %d, tip de date diferit", yylineno);
                                print_error();
                                std::exit(0);
                            }
                            int val = Eval($3, yylineno);
                            actualizareTabel($1, "int", val, yylineno, 0, "");
                        }
         | ID '(' lista_apel ')' {VerifFct($1, $3, yylineno);}
         | TYPEOF '(' pseudo_e ')' {std::cout << $3 << "\n";}
         | EVAL '(' e ')' {std::cout << Eval($3, yylineno) << "\n";}
         | EVAL '(' cond_expr ')' {
              if($3 == 1) std::cout<<"true"<<"\n";
              else std::cout<<"false"<<"\n";
         }
         | ID '.' ID ASSIGN e { 
                                std::snprintf(buff,100,"%s.%s", $1, $3);
                                Verif(buff, yylineno, 0);
                                if(strcmp(getIdType($1), "int"))
                                {
                                    std::sprintf(errMsg, "Linia %d, tip de date diferit", yylineno);
                                    print_error();
                                    std::exit(0);
                                }
                                int val = Eval($5, yylineno);
                                actualizareTabel(buff, "int", val, yylineno, 0, "");
                              }
         | ID ASSIGN NR_FLOAT {
                                Verif($1, yylineno, 0);
                                if(strcmp(getIdType($1), "float"))
                                {
                                    std::sprintf(errMsg, "Linia %d, tip de date diferit", yylineno);
                                    print_error();
                                    std::exit(0);
                                }
                                actualizareTabel($1, "float", 0, yylineno, $3, "");
                              }
         | ID '.' ID '(' lista_apel ')' {
                                            std::snprintf(buff,100,"%s.%s", $1, $3);
                                            VerifFct(buff, $5, yylineno);

                                        }
         | ID '[' NR ']' ASSIGN e { Verif($1, yylineno, $3);}
         ;

/*evaluare conditie*/

cond : '(' cond ')' {$$ = $2;}
     | cond AND cond { int rez1=$1; int rez2=$3; 
                       $$=(rez1 && rez2);
                     }
     | cond OR cond { int rez1=$1; int rez2=$3;
                      $$=(rez1 || rez2);
                    }
     | e opr e { 
                int rez1=evalAST($1, yylineno); int rez2=evalAST($3, yylineno);
                if (strcmp($2, "<=")) $$=(rez1 <= rez2);
                if (strcmp($2, ">=")) $$=(rez1 >= rez2);
                if (strcmp($2, "!=")) $$=(rez1 != rez2);
                if (strcmp($2, "==")) $$=(rez1 == rez2);
                if (strcmp($2, ">")) $$=(rez1 > rez2);
                if (strcmp($2, "<")) $$=(rez1 < rez2);
                }
     ; 

cond_expr : '(' cond_expr ')' {$$ = $2;}
          | e opr e {
                int rez1 = evalAST($1, yylineno);
                int rez2 = evalAST($3, yylineno);
                if (strcmp($2, "<=")) $$ = (rez1 <= rez2);
                if (strcmp($2, ">=")) $$ = (rez1 >= rez2);
                if (strcmp($2, "!=")) $$ = (rez1 != rez2);
                if (strcmp($2, "==")) $$ = (rez1 == rez2);
                if (strcmp($2, ">")) $$ = (rez1 > rez2);
                if (strcmp($2, "<")) $$ = (rez1 < rez2);
            }
          ;

opr : LEQ {$$ = $1;}
    | GEQ {$$ = $1;}
    | NEQ {$$ = $1;}
    | EQ  {$$ = $1;}
    | '>' {$$ = const_cast<char*>(">");}
    | '<' {$$ = const_cast<char*>("<");}
    ;

if : IF '(' cond ')' list EIF
   | IF '(' cond ')' list ELSE list EIF
   ;

for : FOR '(' TIP ID ASSIGN e ';' cond ';' statement ')' list EFOR
    | FOR '(' ID ASSIGN e ';' cond ';' statement ')' list EFOR
    ;

do : DO list WHILE '(' cond ')' ';'
   ;

while : WHILE '(' cond ')' list EWHILE
      ;

/*dAST va fi in compilator.h*/
/*new AST("+", $1, $3, OPERATOR) + rad, $1 arb st, $3 arb drp, OPERATOR va fi tipul nodului, voi pune o enumerare de tipuri in compilator.h*/
/*expr poate primi un identificator si verif corect*/
/*memset setez memoria la 0*/
/*getArrVal($1, $3, yylineno); verific daca mai e loc in vector si return val din vector de pe poz $3*/

e : e '+' e { $$ = new AST("+", $1, $3, OPERATOR); }
  | e '-' e { $$ = new AST("-", $1, $3, OPERATOR); }
  | e '*' e { $$ = new AST("*", $1, $3, OPERATOR); }
  | e '/' e { $$ = new AST("/", $1, $3, OPERATOR); }
  | '(' e ')' { $$ = $2; }
  | ID { Verif($1, yylineno, 0); $$ = new AST($1, nullptr, nullptr, IDENTIFICATOR);}
  | NR { char nr[100]; memset(nr, 0, 100); std::sprintf(nr, "%d", $1); $$ = new AST(nr, nullptr, nullptr, NUMAR); }
  | ID '[' NR ']' {Verif($1, yylineno, 1); int val = getArrVal($1, $3, yylineno); char nr[100]; memset(nr, 0, 100); std::sprintf(nr, "%d", val); $$ = new AST(nr, nullptr, nullptr, NUMAR); }
  | ID '(' lista_apel ')' { VerifFct($1, $3, yylineno);
                            $$ = new AST("0", nullptr, nullptr, NUMAR);
                          }
  | ID '.' ID { std::snprintf(buff,100,"%s.%s", $1, $3); Verif(buff, yylineno, 0);  $$ = new AST($1, nullptr, nullptr, IDENTIFICATOR);}
  | ID '.' ID '(' lista_apel ')' { std::snprintf(buff,100,"%s.%s", $1, $3); VerifFct(buff, $3, yylineno); $$ = new AST("0", nullptr, nullptr, NUMAR);}
  ;

/*pt TYPEOF*/
/*$$ = $1; rezultatul unei adunari de exp va fi tipul operandului/ pseudo_e $1*/
/*$$ = FctRetType($1) tipul de return al functiei*/

pseudo_e : pseudo_e '+' pseudo_e {
                                    if(strcmp($1, $3))
                                    {
                                        std::sprintf(errMsg, "Linia %d, tip de date diferit!", yylineno);
                                        print_error();
                                        std::exit(0);
                                    }
                                    $$ = $1;
                                 }
         | pseudo_e '-' pseudo_e {
                                    if(strcmp($1, $3))
                                    {
                                        std::sprintf(errMsg, "Linia %d, tip de date diferit!", yylineno);
                                        print_error();
                                        std::exit(0);
                                    }
                                    $$ = $1;
                                 }
         | pseudo_e '/' pseudo_e {
                                    if(strcmp($1, $3))
                                    {
                                        std::sprintf(errMsg, "Linia %d, tip de date diferit!", yylineno);
                                        print_error();
                                        std::exit(0);
                                    }
                                    $$ = $1;
                                 }
         | pseudo_e '*' pseudo_e {
                                    if(strcmp($1, $3))
                                    {
                                        std::sprintf(errMsg, "Linia %d, tip de date diferit!", yylineno);
                                        print_error();
                                        std::exit(0);
                                    }
                                    $$ = $1;
                                 }
         | '(' pseudo_e ')' { $$ = $2; }
         | ID {Verif($1, yylineno, 0); $$ = getIdType($1);}
         | NR {$$ = const_cast<char*>("int");}
         | NR_FLOAT {$$ = const_cast<char*>("float");}
         | ID '[' NR ']' {Verif($1, yylineno, 1); $$ = getIdType($1);}
         | ID '(' lista_apel ')' { VerifFct($1, $3, yylineno); $$ = FctRetType($1);}
         | ID '.' ID {std::snprintf(buff,100,"%s.%s", $1, $3); Verif($1, yylineno, 1); $$ = getIdType(buff);}
         | ID '.' ID '(' lista_apel ')' { std::snprintf(buff,100,"%s.%s", $1, $3); VerifFct(buff, $5, yylineno); $$ = FctRetType(buff);}
         ;

lista_apel : e {
                AST* tree = $1;
                if(tree->st == NULL && tree->dr == NULL)
                {
                    if(tree->nodeType == IDENTIFICATOR)
                        $$ = getIdType(tree->nume);
                    else
                        $$ = const_cast<char*>("int");
                }
                else
                    $$ = const_cast<char*>("int");
            }
           | lista_apel ',' e {
                    AST* tree = $3;
                    char tip[20];
                        if(tree->st == NULL && tree->dr == NULL)
                        {
                            if(tree->nodeType == IDENTIFICATOR)
                                strcpy(tip, getIdType(tree->nume));
                            else
                                strcpy(tip, "int");
                        }
                        else
                            strcpy(tip, "int");
                        strcpy(buff, $1);
                        strcat(buff, ",");
                        strcat(buff, tip);
                        $$ = buff;
                }
           | NR_FLOAT {$$ = const_cast<char*>("float");}
           | lista_apel ',' NR_FLOAT { std::snprintf(buff,100,"%s,float",$1); $$ = buff;}
           | CHAR {$$ = const_cast<char*>("char");}
           | lista_apel ',' CHAR {std::snprintf(buff,100,"%s,char",$1); $$ = buff;}
           | STRING {$$ = const_cast<char*>("string");}
           | lista_apel ',' STRING {std::snprintf(buff,100,"%s,string",$1); $$ = buff;}
           ;

%%

int yyerror(const char * s)
{
    std::cout<<"eroare: " << s << " la linia: " << yylineno <<"\n";
    return 0;
}


int main(int argc, char** argv) 
{
    std::ofstream fd("symbol_table.txt", std::ofstream::out | std::ofstream::trunc);/*pt tabela de simboluri*/
    
    if (!fd.is_open()) {
        std::cout << "Nu se poate deschide fisierul.\n";
        return 1;
    }

    initialize();/*init tabela cu val 0/nullptr*/

    yyin = fopen(argv[1], "r");
    
    yyparse();/*generează un arbore de analiză sintactică, în care nodurile arborelui corespund diferitelor producții ale gramaticii */
    printVars(fd);
    printFunctions(fd);

    return 0;
}
