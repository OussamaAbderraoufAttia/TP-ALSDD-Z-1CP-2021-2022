/**--------------------------------------------------------**/
/**       C o n v e r s i o n   Z vers C (Standard)        **/
/**             Réalisée par Pr D.E ZEGOUR                 **/
/**             E S I - Alger                              **/
/**             Copywrite 2014                             **/
/**--------------------------------------------------------**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef int bool ;
typedef char * string255 ;

#define True 1
#define False 0

/** Implémentation **\: TABLEAU DE STRUCTURES**/

/** Structures statiques **/

typedef struct Tiiii Type_Tiiii  ;
typedef Type_Tiiii * Typestr_Tiiii ;
typedef int Type1_Tiiii  ;
typedef int Type2_Tiiii  ;
typedef int Type3_Tiiii  ;
typedef int Type4_Tiiii  ;
struct Tiiii
  {
    Type1_Tiiii Champ1 ;
    Type2_Tiiii Champ2 ;
    Type3_Tiiii Champ3 ;
    Type4_Tiiii Champ4 ;
  };

Type1_Tiiii Struct1_Tiiii ( Typestr_Tiiii S)
  {
    return  S->Champ1 ;
  }

Type2_Tiiii Struct2_Tiiii ( Typestr_Tiiii S)
  {
    return  S->Champ2 ;
  }

Type3_Tiiii Struct3_Tiiii ( Typestr_Tiiii S)
  {
    return  S->Champ3 ;
  }

Type4_Tiiii Struct4_Tiiii ( Typestr_Tiiii S)
  {
    return  S->Champ4 ;
  }

void Aff_struct1_Tiiii ( Typestr_Tiiii S, Type1_Tiiii Val )
  {
     S->Champ1 = Val ;
  }

void Aff_struct2_Tiiii ( Typestr_Tiiii S, Type2_Tiiii Val )
  {
     S->Champ2 = Val ;
  }

void Aff_struct3_Tiiii ( Typestr_Tiiii S, Type3_Tiiii Val )
  {
     S->Champ3 = Val ;
  }

void Aff_struct4_Tiiii ( Typestr_Tiiii S, Type4_Tiiii Val )
  {
     S->Champ4 = Val ;
  }


/** Tableaux **/

typedef Typestr_Tiiii Typeelem_V8Tiiii ;
typedef Typeelem_V8Tiiii * Typevect_V8Tiiii ;

Typeelem_V8Tiiii Element_V8Tiiii ( Typevect_V8Tiiii V , int I1  )
  {
    return  *(V +  (I1-1)  ) ;
  }

void Aff_element_V8Tiiii ( Typevect_V8Tiiii V  , int I1 ,  Typeelem_V8Tiiii Val )
  {
    Typeelem_V8Tiiii _Temp ;
    _Temp = malloc(sizeof(Type_Tiiii));
    /* Affectation globale de structure */
    _Temp->Champ1 = Val->Champ1;
    _Temp->Champ2 = Val->Champ2;
    _Temp->Champ3 = Val->Champ3;
    _Temp->Champ4 = Val->Champ4;
    Val = _Temp ;
    *(V +  (I1-1)  ) = Val ;
  }


/** Implémentation **\: TABLEAU DE LISTES DE STRUCTURES**/

/** Listes lin?aires cha?n?es **/

typedef Typestr_Tiiii Typeelem_LTiiii   ;
typedef struct Maillon_LTiiii * Pointeur_LTiiii ;

struct Maillon_LTiiii
  {
    Typeelem_LTiiii  Val ;
    Pointeur_LTiiii Suiv ;
  } ;

Pointeur_LTiiii Allouer_LTiiii (Pointeur_LTiiii *P)
  {
    *P = (struct Maillon_LTiiii *) malloc( sizeof( struct Maillon_LTiiii)) ;
    (*P)->Val = malloc(sizeof(Type_Tiiii));
    (*P)->Suiv = NULL;
  }

void Aff_val_LTiiii(Pointeur_LTiiii P, Typeelem_LTiiii Val)
  {
    Typeelem_LTiiii _Temp ;
    _Temp = malloc(sizeof(Type_Tiiii));
    /* Affectation globale de structure */
    _Temp->Champ1 = Val->Champ1;
    _Temp->Champ2 = Val->Champ2;
    _Temp->Champ3 = Val->Champ3;
    _Temp->Champ4 = Val->Champ4;
    Val = _Temp ;
    P->Val = Val ;
  }

void Aff_adr_LTiiii( Pointeur_LTiiii P,  Pointeur_LTiiii Q)
  {
    P->Suiv = Q ;
  }

Pointeur_LTiiii Suivant_LTiiii(  Pointeur_LTiiii P)
  { return( P->Suiv ) ;  }

Typeelem_LTiiii Valeur_LTiiii( Pointeur_LTiiii P)
  { return( P->Val) ; }

void Liberer_LTiiii ( Pointeur_LTiiii P)
  { free (P);}


/** Tableaux **/

typedef Pointeur_LTiiii Typeelem_V8LTiiii ;
typedef Typeelem_V8LTiiii * Typevect_V8LTiiii ;

Typeelem_V8LTiiii Element_V8LTiiii ( Typevect_V8LTiiii V , int I1  )
  {
    return  *(V +  (I1-1)  ) ;
  }

void Aff_element_V8LTiiii ( Typevect_V8LTiiii V  , int I1 ,  Typeelem_V8LTiiii Val )
  {
    *(V +  (I1-1)  ) = Val ;
  }


/** Implémentation **\: TABLEAU DE CHAINES DE CARACTERES**/

/** Tableaux **/

typedef string255 Typeelem_V32s ;
typedef Typeelem_V32s * Typevect_V32s ;

Typeelem_V32s Element_V32s ( Typevect_V32s V , int I1  )
  {
    return  *(V +  (I1-1)  ) ;
  }

void Aff_element_V32s ( Typevect_V32s V  , int I1 ,  Typeelem_V32s Val )
  {
   strcpy( *(V +  (I1-1)  ) , Val );
  }


/** Implémentation **\: TABLEAU DE ENTIERS**/

/** Tableaux **/

typedef int Typeelem_V32i ;
typedef Typeelem_V32i * Typevect_V32i ;

Typeelem_V32i Element_V32i ( Typevect_V32i V , int I1  )
  {
    return  *(V +  (I1-1)  ) ;
  }

void Aff_element_V32i ( Typevect_V32i V  , int I1 ,  Typeelem_V32i Val )
  {
    *(V +  (I1-1)  ) = Val ;
  }


/** Implémentation **\: TABLEAU DE ENTIERS**/

/** Tableaux **/

typedef int Typeelem_V8i ;
typedef Typeelem_V8i * Typevect_V8i ;

Typeelem_V8i Element_V8i ( Typevect_V8i V , int I1  )
  {
    return  *(V +  (I1-1)  ) ;
  }

void Aff_element_V8i ( Typevect_V8i V  , int I1 ,  Typeelem_V8i Val )
  {
    *(V +  (I1-1)  ) = Val ;
  }


/** Implémentation **\: ARBRE BINAIRE DE STRUCTURES**/

/** Arbres de recherche binaire **/

typedef Typestr_Tiiii Typeelem_ATiiii   ;
typedef struct Noeud_ATiiii * Pointeur_ATiiii ;

struct Noeud_ATiiii
  {
    Typeelem_ATiiii  Val ;
    Pointeur_ATiiii Fg ;
    Pointeur_ATiiii Fd ;
    Pointeur_ATiiii Pere ;
   } ;

Typeelem_ATiiii Info_ATiiii( Pointeur_ATiiii P )
  { return P->Val;   }

Pointeur_ATiiii Fg_ATiiii( Pointeur_ATiiii P)
  { return P->Fg ; }

Pointeur_ATiiii Fd_ATiiii( Pointeur_ATiiii P)
  { return P->Fd ; }

Pointeur_ATiiii Pere_ATiiii( Pointeur_ATiiii P)
  { return P->Pere ; }

void Aff_info_ATiiii ( Pointeur_ATiiii P, Typeelem_ATiiii Val)
  {
    Typeelem_ATiiii _Temp ;
    _Temp = malloc(sizeof(Type_Tiiii));
    /* Affectation globale de structure */
    _Temp->Champ1 = Val->Champ1;
    _Temp->Champ2 = Val->Champ2;
    _Temp->Champ3 = Val->Champ3;
    _Temp->Champ4 = Val->Champ4;
    Val = _Temp ;
     P->Val = Val ;
  }

void Aff_fg_ATiiii( Pointeur_ATiiii P, Pointeur_ATiiii Q)
  { P->Fg =  Q;  }

void Aff_fd_ATiiii( Pointeur_ATiiii P, Pointeur_ATiiii Q)
  { P->Fd =  Q ; }

void Aff_pere_ATiiii( Pointeur_ATiiii P, Pointeur_ATiiii Q)
  { P->Pere =  Q ; }

void Creernoeud_ATiiii( Pointeur_ATiiii *P)
  {
    *P = (struct Noeud_ATiiii *) malloc( sizeof( struct Noeud_ATiiii))   ;
    (*P)->Val = malloc(sizeof(Type_Tiiii));
    (*P)->Fg = NULL;
    (*P)->Fd = NULL;
    (*P)->Pere = NULL;
  }

void Liberernoeud_ATiiii( Pointeur_ATiiii P)
  { free( P ) ; }


/** Implémentation **\: PILE DE ARBRES BINAIRES DE STRUCTURES**/
/** Piles **/

typedef Pointeur_ATiiii Typeelem_PATiiii ;
typedef struct Maillon_PATiiii * Pointeur_PATiiii ;
typedef   Pointeur_PATiiii  Typepile_PATiiii  ;

struct Maillon_PATiiii
  {
    Typeelem_PATiiii  Val ;
    Pointeur_PATiiii Suiv ;
  } ;

void Creerpile_PATiiii( Pointeur_PATiiii *P )
  { *P = NULL ; }

bool Pilevide_PATiiii ( Pointeur_PATiiii P )
  { return  (P == NULL ); }

void Empiler_PATiiii ( Pointeur_PATiiii *P,  Typeelem_PATiiii Val )
  {
    Pointeur_PATiiii Q;

    Q = (struct Maillon_PATiiii *) malloc( sizeof( struct Maillon_PATiiii))   ;
    Q->Val = Val ;
    Q->Suiv = *P;
    *P = Q;
  }

void Depiler_PATiiii ( Pointeur_PATiiii *P,  Typeelem_PATiiii *Val )
  {
    Pointeur_PATiiii Sauv;

    if (! Pilevide_PATiiii (*P) )
      {
        *Val = (*P)->Val ;
        Sauv = *P;
        *P = (*P)->Suiv;
        free(Sauv);
      }
    else printf ("%s \n", "Pile vide");
  }


/** Implémentation **\: TABLEAU DE STRUCTURES**/

/** Tableaux **/

typedef Typestr_Tiiii Typeelem_V15Tiiii ;
typedef Typeelem_V15Tiiii * Typevect_V15Tiiii ;

Typeelem_V15Tiiii Element_V15Tiiii ( Typevect_V15Tiiii V , int I1  )
  {
    return  *(V +  (I1-1)  ) ;
  }

void Aff_element_V15Tiiii ( Typevect_V15Tiiii V  , int I1 ,  Typeelem_V15Tiiii Val )
  {
    Typeelem_V15Tiiii _Temp ;
    _Temp = malloc(sizeof(Type_Tiiii));
    /* Affectation globale de structure */
    _Temp->Champ1 = Val->Champ1;
    _Temp->Champ2 = Val->Champ2;
    _Temp->Champ3 = Val->Champ3;
    _Temp->Champ4 = Val->Champ4;
    Val = _Temp ;
    *(V +  (I1-1)  ) = Val ;
  }

/** Pour les variables temporaires **/
typedef Typestr_Tiiii Typeelem_V1Tiiii;
typedef Typeelem_V1Tiiii Typetab_V1Tiiii[1];


/** Implémentation **\: TABLEAU DE ENTIERS**/

/** Tableaux **/

typedef int Typeelem_V4i ;
typedef Typeelem_V4i * Typevect_V4i ;

Typeelem_V4i Element_V4i ( Typevect_V4i V , int I1  )
  {
    return  *(V +  (I1-1)  ) ;
  }

void Aff_element_V4i ( Typevect_V4i V  , int I1 ,  Typeelem_V4i Val )
  {
    *(V +  (I1-1)  ) = Val ;
  }


/** Implémentation **\: FILE DE ARBRES BINAIRES DE STRUCTURES**/
/** Files d'attente **/

typedef Pointeur_ATiiii Typeelem_FATiiii ;
typedef  struct Filedattente_FATiiii * Pointeur_FATiiii ;
typedef  struct Maillon_FATiiii * Ptliste_FATiiii ;

struct Maillon_FATiiii
  {
    Typeelem_FATiiii Val ;
    Ptliste_FATiiii Suiv  ;
  };

struct Filedattente_FATiiii
  {
    Ptliste_FATiiii Tete, Queue ;
  };

void Creerfile_FATiiii ( Pointeur_FATiiii *Fil   )
  {
    *Fil = (struct Filedattente_FATiiii *) malloc( sizeof( struct Filedattente_FATiiii)) ;
    (*Fil)->Tete = NULL ;
    (*Fil)->Queue = NULL ;
  }

bool Filevide_FATiiii (Pointeur_FATiiii Fil  )
  { return  Fil->Tete == NULL ;}

void Enfiler_FATiiii ( Pointeur_FATiiii Fil , Typeelem_FATiiii Val   )
  {
    Ptliste_FATiiii Q;

    Q = (struct Maillon_FATiiii *) malloc( sizeof( struct Maillon_FATiiii))   ;
    Q->Val = Val ;
    Q->Suiv = NULL;
    if ( ! Filevide_FATiiii(Fil) )
      Fil->Queue->Suiv = Q ;
    else Fil->Tete = Q;
      Fil->Queue = Q;
  }

void Defiler_FATiiii (Pointeur_FATiiii Fil, Typeelem_FATiiii *Val )
  {
    if (! Filevide_FATiiii(Fil) )
      {
        *Val = Fil->Tete->Val ;
        Fil->Tete =  Fil->Tete->Suiv;
      }
    else printf ("%s \n", "File d'attente vide");
  }


/** Variables du programme principal **/
Typevect_V8Tiiii Tab_groupes;
Typestr_Tiiii Sg;
Typestr_Tiiii Sh;
Typevect_V8LTiiii Tab_grpmatch;
Typevect_V32s Tab_eq_nom;
Typevect_V32i Tab_eq_totbuts;
Pointeur_LTiiii P=NULL;
Typevect_V32i Tab_eq_pts;
Typevect_V32i Tab_eq_rep;
string255 Nomeq;
int Id;
Typevect_V8i Tab_grp_cls1;
Typevect_V8i Tab_grp_cls2;
Pointeur_ATiiii Arb_match=NULL;
Pointeur_PATiiii Pi=NULL;
Typevect_V15Tiiii Tab_phase2;
int I;
int K;
int J;
int Eqfav;
int Maxsc;
int Res1;
int Res2;
int Rep1;
int Rep2;
int Eq1;
int Eq2;
int Alea;
int Ch;
int Eqg;
string255 Eqgagnante;
int _Px1;
int _Px2;
int _Izw;  /** Variable de contrôle **/

/** Fonctions standards **/

int Aleanombre( int N )
  { return ( rand() % N ); }

int Mod( int a, int b)
  { return ( a % b ); }


/** Initialisation d'une structure **/
void Init_struct_Tiiii ( Typestr_Tiiii S, Type_Tiiii S_ )
  {
    S->Champ1 = S_.Champ1 ;
    S->Champ2 = S_.Champ2 ;
    S->Champ3 = S_.Champ3 ;
    S->Champ4 = S_.Champ4 ;
  }


/** Cr?ation d'une liste **/
void Creer_liste_LTiiii ( Pointeur_LTiiii *L, Typetab_V1Tiiii Tab, int N)
  {
    int I ;
    Pointeur_LTiiii P, Q ;

    *L =NULL;
    for( I=1;I<=N;++I)
      {
        Allouer_LTiiii( &Q ) ;
        Aff_val_LTiiii (Q, Tab[I-1]);
        Aff_adr_LTiiii (Q, NULL);
        if (*L == NULL)
          *L = Q ;
        else Aff_adr_LTiiii (P, Q);
        P = Q ;
      }
  }


/** Prototypes des fonctions **/

void Creer_tabgrp (Typevect_V8Tiiii *Tab_groupes);
void Creer_tabgrpmatch (Typevect_V8LTiiii *Tab_grpmatch);
void Sim_hasard (Typevect_V8LTiiii *Tab_grpmatch , Typevect_V32i *Tab_eq_pts);
void Eq_gagn (int *Eq1 , int *Eq2 , int *Res1 , int *Res2 , Typevect_V32i *Tab_eq_pts);
void Init_tabeq (Typevect_V32i *Tab_eq);
void Class_eq (Typevect_V32i *Tab_eq_pts , Typevect_V8i *Tab_grp_cls1 , Typevect_V8i *Tab_grp_cls2);
void Sim_eqch (Typevect_V8LTiiii *Tab_grpmatch , Typevect_V32i *Tab_eq_pts , int *Eqch);
void Sim_eqfav (Typevect_V8LTiiii *Tab_grpmatch , Typevect_V32i *Tab_eq_pts , Typevect_V32i *Tab_eq_rep);
void Sim_eqfav_has (Typevect_V8LTiiii *Tab_grpmatch , Typevect_V32i *Tab_eq_rep , Typevect_V32i *Tab_eq_pts);
void Sim_maxsc (Typevect_V8LTiiii *Tab_grpmatch , Typevect_V32i *Tab_eq_pts , int *Maxsc);
void Affichage (Typevect_V8LTiiii *Tab_grpmatch , Typevect_V32i *Tab_eq_pts);
void Creer_tab_rep (Typevect_V32i *Tab_eq_rep);
void Creer_tab_phase2 (Typevect_V15Tiiii *Tab_phase2 , Typevect_V8i *Tab_grp_cls1 , Typevect_V8i *Tab_grp_cls2);
Pointeur_ATiiii Creer_arb_match (Typevect_V15Tiiii *Tab_phase2 , Pointeur_ATiiii *Arb_match , int *I , int *N) ;
void Inordre (Pointeur_ATiiii *R);
void Parcourenlargeur (Pointeur_ATiiii *R);
void Parlarginv (Pointeur_ATiiii *R , Pointeur_PATiiii *Pi);
void Affichage_arb (Pointeur_PATiiii *Pi);
void Ph2_sim_hasard (Pointeur_ATiiii *Arb_match);
void Ph2_sim_eqfav (Pointeur_ATiiii *Arb_match , Typevect_V15Tiiii *Tab_phase2 , Typevect_V32i *Tab_eq_rep);
void Ph2_sim_eqfav2 (Typevect_V15Tiiii *Tab_phase2 , Typevect_V32i *Tab_eq_rep);
void Creer_tabtotbuts (Typevect_V8LTiiii *Tab_grpmatch , Typevect_V32i *Tab_eq_totbuts);
void Ph2_sim_resph12 (Pointeur_ATiiii *Arb_match , Typevect_V32i *Tab_eq_totbuts , int *Ch);
void Ph2_sim_resph12_2 (Pointeur_PATiiii *Pi , Typevect_V32i *Tab_eq_totbuts , int *Ch);
void Ph2_sim_eqfavresph1 (Pointeur_ATiiii *Arb_match , Typevect_V32i *Tab_eq_rep , Typevect_V32i *Tab_eq_totbuts , int *Ch);
void Ph2sim_eqfavresph12 (Pointeur_PATiiii *Pi , Typevect_V32i *Tab_eq_rep , Typevect_V32i *Tab_eq_totbuts , int *Ch);
void Eqfavresph12 (Typestr_Tiiii *Sh , Typevect_V32i *Tab_eq_rep , Typevect_V32i *Tab_eq_totbuts , int *Ch);
void Eqgafnfin (Pointeur_ATiiii *Arb_match , int *Eqg);
void Creer_tabeqnom (Typevect_V32s *Tab_eq_nom);
void Ideq (string255 *Nomeq , int *Id , Typevect_V32s *Tab_eq_nom);
void Affichage_phase1 (Typevect_V8LTiiii *Tab_grpmatch , Typevect_V32s *Tab_eq_nom , Typevect_V32i *Tab_eq_pts);
void Affichage_phase2 (Pointeur_ATiiii *Arb_match , Typevect_V32s *Tab_eq_nom);

void Creer_tabgrp (Typevect_V8Tiiii *Tab_groupes)
  {
    /** Variables locales **/
    int I;
    int K;
    Typestr_Tiiii Sg;
    Type_Tiiii S_Sg;

    /** Corps du module **/
   Sg = malloc(sizeof(Type_Tiiii));
   K  =  1 ;
   for( I  =  1 ;I <=  8 ; ++I){
     S_Sg.Champ1 = K ;
     S_Sg.Champ2 = K+1 ;
     S_Sg.Champ3 = K+2 ;
     S_Sg.Champ4 = K+3 ;
     Init_struct_Tiiii ( Sg , S_Sg )  ;
     Aff_element_V8Tiiii ( *Tab_groupes , I   , Sg ) ;
     K  =  K + 4 ;

   } ;

  }
void Creer_tabgrpmatch (Typevect_V8LTiiii *Tab_grpmatch)
  {
    /** Variables locales **/
    Pointeur_LTiiii Lm=NULL;
    Pointeur_LTiiii Sgm=NULL;
    Pointeur_LTiiii P=NULL;
      Typetab_V1Tiiii T_Sgm;
    Type_Tiiii S_Sgm;
    int _Izw;  /** Variable de contrôle **/

    /** Corps du module **/
   int _Izw2;for (_Izw2=0; _Izw2<1; ++_Izw2)
     T_Sgm[_Izw2] = malloc(sizeof(Type_Tiiii));
   for( I  =  1 ;I <=  8 ; ++I){
    /* Affectation globale de structure */
     Sg->Champ1 =   Element_V8Tiiii ( Tab_groupes , I   )->Champ1;
     Sg->Champ2 =   Element_V8Tiiii ( Tab_groupes , I   )->Champ2;
     Sg->Champ3 =   Element_V8Tiiii ( Tab_groupes , I   )->Champ3;
     Sg->Champ4 =   Element_V8Tiiii ( Tab_groupes , I   )->Champ4;
;
     Lm  =  NULL ;
     for( J  =  Struct1_Tiiii ( Sg  ) ;J <=  Struct3_Tiiii ( Sg  ) ; ++J){
       for( K  =  J + 1 ;K <=  Struct4_Tiiii ( Sg  ) ; ++K){
         Allouer_LTiiii (& Sgm ) ;
         S_Sgm.Champ1 = J ;
         S_Sgm.Champ2 = K ;
         S_Sgm.Champ3 = 0 ;
         S_Sgm.Champ4 = 0 ;
         *T_Sgm [ 0 ] = S_Sgm ;
         Creer_liste_LTiiii (&Sgm , T_Sgm , 1 )  ;
         P  =  Lm ;
         if( P == NULL) {
           Lm  =  Sgm ;
           }
         else
           {
           while( Suivant_LTiiii ( P ) != NULL) {
             P  =  Suivant_LTiiii ( P ) ;

           } ;
           Aff_adr_LTiiii ( P , Sgm ) ;

         } ;
         Sgm  =  NULL ;

       } ;

     } ;
     Aff_element_V8LTiiii ( *Tab_grpmatch , I   , Lm ) ;

   } ;

  }
void Sim_hasard (Typevect_V8LTiiii *Tab_grpmatch , Typevect_V32i *Tab_eq_pts)
  {
    /** Variables locales **/
    Pointeur_LTiiii P=NULL;
    Typestr_Tiiii S;
    int I;
    int Eq1;
    int Eq2;
    int Res1;
    int Res2;
    int Pts;
    Type_Tiiii S_S;

    /** Corps du module **/
   S = malloc(sizeof(Type_Tiiii));
   for( I  =  1 ;I <=  8 ; ++I){
     P  =  Element_V8LTiiii ( *Tab_grpmatch , I   ) ;
     while( P != NULL) {
    /* Affectation globale de structure */
       S->Champ1 =   Valeur_LTiiii ( P )->Champ1;
       S->Champ2 =   Valeur_LTiiii ( P )->Champ2;
       S->Champ3 =   Valeur_LTiiii ( P )->Champ3;
       S->Champ4 =   Valeur_LTiiii ( P )->Champ4;
;
       Eq1  =  Struct1_Tiiii ( S  ) ;
       Eq2  =  Struct2_Tiiii ( S  ) ;
       Res1  =  Aleanombre(10 ) ;
       Res2  =  Aleanombre(10 ) ;
       S_S.Champ1 = Eq1 ;
       S_S.Champ2 = Eq2 ;
       S_S.Champ3 = Res1 ;
       S_S.Champ4 = Res2 ;
       Init_struct_Tiiii ( S , S_S )  ;
       Aff_val_LTiiii ( P , S ) ;
       Eq_gagn ( & Eq1 , & Eq2 , & Res1 , & Res2 , & *Tab_eq_pts ) ;
       P  =  Suivant_LTiiii ( P ) ;

     } ;

   } ;

  }
void Eq_gagn (int *Eq1 , int *Eq2 , int *Res1 , int *Res2 , Typevect_V32i *Tab_eq_pts)
  {
    /** Variables locales **/
    int Pts;

    /** Corps du module **/
  /*l'equipe 1 est gagnate*/
   if( *Res1 > *Res2) {
     Pts  =  Element_V32i ( *Tab_eq_pts , *Eq1   ) + 3 ;
     Aff_element_V32i ( *Tab_eq_pts , *Eq1   , Pts ) ;

   } ;
  /*l'equipe 2 est gagnate*/
   if( *Res1 < *Res2) {
     Pts  =  Element_V32i ( *Tab_eq_pts , *Eq2   ) + 3 ;
     Aff_element_V32i ( *Tab_eq_pts , *Eq2   , Pts ) ;

   } ;
  /*le match est null*/
   if( *Res1 == *Res2) {
     Pts  =  Element_V32i ( *Tab_eq_pts , *Eq1   ) + 1 ;
     Aff_element_V32i ( *Tab_eq_pts , *Eq1   , Pts ) ;
     Pts  =  Element_V32i ( *Tab_eq_pts , *Eq2   ) + 1 ;
     Aff_element_V32i ( *Tab_eq_pts , *Eq2   , Pts ) ;

   } ;

  }
void Init_tabeq (Typevect_V32i *Tab_eq)
  {
    /** Variables locales **/
    int I;

    /** Corps du module **/
   for( I  =  1 ;I <=  32 ; ++I){
     Aff_element_V32i ( *Tab_eq , I   , 0 ) ;

   } ;

  }
void Class_eq (Typevect_V32i *Tab_eq_pts , Typevect_V8i *Tab_grp_cls1 , Typevect_V8i *Tab_grp_cls2)
  {
    /** Variables locales **/
    Typevect_V4i T;
    int I;
    int J;
    int K;
    int L;
    int Pts;
    int Maxi;
    int Pos;

    /** Corps du module **/
   T = malloc(4 * sizeof(int));
   for( I  =  1 ;I <=  8 ; ++I){
     K  =  ( I - 1 ) * 3 + I ;
     J  =  K ;
     L  =  1 ;
     while( J <= K + 3) {
       Pts  =  Element_V32i ( *Tab_eq_pts , J   ) ;
       Aff_element_V4i ( T , L   , Pts ) ;
       J  =  J + 1 ;
       L  =  L + 1 ;

     } ;
     Maxi  =  0 ;
     for( L  =  1 ;L <=  4 ; ++L){
       Pts  =  Element_V4i ( T , L   ) ;
       if( Pts > Maxi) {
         Maxi  =  Pts ;
         Pos  =  L ;

       } ;

     } ;
     Pos  =  K + Pos - 1 ;
     Aff_element_V8i ( *Tab_grp_cls1 , I   , Pos ) ;
     Aff_element_V4i ( T , Pos - K + 1   , 0 ) ;
     Maxi  =  0 ;
     for( L  =  1 ;L <=  4 ; ++L){
       Pts  =  Element_V4i ( T , L   ) ;
       if( Pts > Maxi) {
         Maxi  =  Pts ;
         Pos  =  L ;

       } ;

     } ;
     Pos  =  K + Pos - 1 ;
     Aff_element_V8i ( *Tab_grp_cls2 , I   , Pos ) ;

   } ;

  }
void Sim_eqch (Typevect_V8LTiiii *Tab_grpmatch , Typevect_V32i *Tab_eq_pts , int *Eqch)
  {
    /** Variables locales **/
    Pointeur_LTiiii P=NULL;
    Typestr_Tiiii S;
    int I;
    int Eq1;
    int Eq2;
    int Res1;
    int Res2;
    int Pts;
    Type_Tiiii S_S;

    /** Corps du module **/
   S = malloc(sizeof(Type_Tiiii));
   for( I  =  1 ;I <=  8 ; ++I){
     P  =  Element_V8LTiiii ( *Tab_grpmatch , I   ) ;
     while( P != NULL) {
    /* Affectation globale de structure */
       S->Champ1 =   Valeur_LTiiii ( P )->Champ1;
       S->Champ2 =   Valeur_LTiiii ( P )->Champ2;
       S->Champ3 =   Valeur_LTiiii ( P )->Champ3;
       S->Champ4 =   Valeur_LTiiii ( P )->Champ4;
;
       Eq1  =  Struct1_Tiiii ( S  ) ;
       Eq2  =  Struct2_Tiiii ( S  ) ;
      /*l'equipe 1 favorite doit gagner*/
       if( Eq1 == *Eqch) {
         Res1  =  Aleanombre(10 ) ;
         Res2  =  Aleanombre(10 ) ;
         while( Res1 < Res2) {
           Res1  =  Aleanombre(10 ) ;
           Res2  =  Aleanombre(10 ) ;

         } ;

       } ;
      /*l'equipe 2 favorite doit gagner*/
       if( Eq2 == *Eqch) {
         Res1  =  Aleanombre(10 ) ;
         Res2  =  Aleanombre(10 ) ;
         while( Res1 > Res2) {
           Res1  =  Aleanombre(10 ) ;
           Res2  =  Aleanombre(10 ) ;

         } ;

       } ;
       if( Eq1 != *Eqch) {
         if( Eq2 != *Eqch) {
           Res1  =  Aleanombre(10 ) ;
           Res2  =  Aleanombre(10 ) ;

         } ;

       } ;
       S_S.Champ1 = Eq1 ;
       S_S.Champ2 = Eq2 ;
       S_S.Champ3 = Res1 ;
       S_S.Champ4 = Res2 ;
       Init_struct_Tiiii ( S , S_S )  ;
       Aff_val_LTiiii ( P , S ) ;
       Eq_gagn ( & Eq1 , & Eq2 , & Res1 , & Res2 , & *Tab_eq_pts ) ;
       P  =  Suivant_LTiiii ( P ) ;

     } ;

   } ;

  }
void Sim_eqfav (Typevect_V8LTiiii *Tab_grpmatch , Typevect_V32i *Tab_eq_pts , Typevect_V32i *Tab_eq_rep)
  {
    /** Variables locales **/
    Pointeur_LTiiii P=NULL;
    Typestr_Tiiii S;
    int I;
    int Eq1;
    int Eq2;
    int Res1;
    int Res2;
    int Rep1;
    int Rep2;
    int Pts;
    Type_Tiiii S_S;

    /** Corps du module **/
   S = malloc(sizeof(Type_Tiiii));
   for( I  =  1 ;I <=  8 ; ++I){
     P  =  Element_V8LTiiii ( *Tab_grpmatch , I   ) ;
     while( P != NULL) {
    /* Affectation globale de structure */
       S->Champ1 =   Valeur_LTiiii ( P )->Champ1;
       S->Champ2 =   Valeur_LTiiii ( P )->Champ2;
       S->Champ3 =   Valeur_LTiiii ( P )->Champ3;
       S->Champ4 =   Valeur_LTiiii ( P )->Champ4;
;
       Eq1  =  Struct1_Tiiii ( S  ) ;
       Eq2  =  Struct2_Tiiii ( S  ) ;
       Rep1  =  Element_V32i ( *Tab_eq_rep , Eq1   ) ;
       Rep2  =  Element_V32i ( *Tab_eq_rep , Eq2   ) ;
      /*l'equipe1 doit gagner*/
       if( Rep1 - Rep2 >= 5) {
         Res1  =  Aleanombre(10 ) ;
         Res2  =  Aleanombre(10 ) ;
         while( Res1 < Res2) {
           Res1  =  Aleanombre(10 ) ;
           Res2  =  Aleanombre(10 ) ;

         } ;

       } ;
       if( Rep1 - Rep2 < 5) {
         if( Rep1 - Rep2 >= 0) {
           Res1  =  Aleanombre(10 ) ;
           Res2  =  Aleanombre(10 ) ;
           while( Res1 != Res2) {
             Res1  =  Aleanombre(10 ) ;
             Res2  =  Aleanombre(10 ) ;

           } ;

         } ;

       } ;
      /*l'equipe2 doit gagner*/
       if( Rep2 - Rep1 >= 5) {
         Res1  =  Aleanombre(10 ) ;
         Res2  =  Aleanombre(10 ) ;
         while( Res2 < Res1) {
           Res1  =  Aleanombre(10 ) ;
           Res2  =  Aleanombre(10 ) ;

         } ;

       } ;
       if( Rep2 - Rep1 < 5) {
         if( Rep2 - Rep1 >= 0) {
           Res1  =  Aleanombre(10 ) ;
           Res2  =  Aleanombre(10 ) ;
           while( Res1 != Res2) {
             Res1  =  Aleanombre(10 ) ;
             Res2  =  Aleanombre(10 ) ;

           } ;

         } ;

       } ;
       S_S.Champ1 = Eq1 ;
       S_S.Champ2 = Eq2 ;
       S_S.Champ3 = Res1 ;
       S_S.Champ4 = Res2 ;
       Init_struct_Tiiii ( S , S_S )  ;
       Aff_val_LTiiii ( P , S ) ;
       Eq_gagn ( & Eq1 , & Eq2 , & Res1 , & Res2 , & *Tab_eq_pts ) ;
       P  =  Suivant_LTiiii ( P ) ;

     } ;

   } ;

  }
void Sim_eqfav_has (Typevect_V8LTiiii *Tab_grpmatch , Typevect_V32i *Tab_eq_rep , Typevect_V32i *Tab_eq_pts)
  {
    /** Variables locales **/
    Pointeur_LTiiii P=NULL;
    Typestr_Tiiii S;
    int I;
    int Eq1;
    int Eq2;
    int Res1;
    int Res2;
    int Rep1;
    int Rep2;
    int Difrep;
    int Pts;
    int Pos;
    Type_Tiiii S_S;

    /** Corps du module **/
   S = malloc(sizeof(Type_Tiiii));
   for( I  =  1 ;I <=  8 ; ++I){
     P  =  Element_V8LTiiii ( *Tab_grpmatch , I   ) ;
     while( P != NULL) {
    /* Affectation globale de structure */
       S->Champ1 =   Valeur_LTiiii ( P )->Champ1;
       S->Champ2 =   Valeur_LTiiii ( P )->Champ2;
       S->Champ3 =   Valeur_LTiiii ( P )->Champ3;
       S->Champ4 =   Valeur_LTiiii ( P )->Champ4;
;
       Eq1  =  Struct1_Tiiii ( S  ) ;
       Eq2  =  Struct2_Tiiii ( S  ) ;
       Rep1  =  Element_V32i ( *Tab_eq_rep , Eq1   ) ;
       Rep2  =  Element_V32i ( *Tab_eq_rep , Eq2   ) ;
       if( Rep1 > Rep2) {
         Difrep  =  Rep1 - Rep2 ;
        /*La difference serait superieure ou egale a 1*/
         Pos  =  Aleanombre ( Difrep + 15 ) ;
        /*L'equipe 1 doit gagner*/
         if( Pos < Difrep) {
           Res1  =  Aleanombre(10 ) ;
           Res2  =  Aleanombre(10 ) ;
           while( Res1 < Res2) {
             Res1  =  Aleanombre(10 ) ;
             Res2  =  Aleanombre(10 ) ;

           } ;
           }
         else
           {
          /*Le match doit etre null*/
           if( Pos < Difrep + 10) {
             Res1  =  Aleanombre(10 ) ;
             Res2  =  Aleanombre(10 ) ;
             while( Res1 != Res2) {
               Res1  =  Aleanombre(10 ) ;
               Res2  =  Aleanombre(10 ) ;

             } ;
             }
          /*L'equipe 2 doit gagner*/
           else
             {
             Res1  =  Aleanombre(10 ) ;
             Res2  =  Aleanombre(10 ) ;
             while( Res2 < Res1) {
               Res1  =  Aleanombre(10 ) ;
               Res2  =  Aleanombre(10 ) ;

             } ;

           } ;

         } ;

       } ;
      /*Le match doit etre null*/
       if( Rep1 == Rep2) {
         Res1  =  Aleanombre(10 ) ;
         Res2  =  Aleanombre(10 ) ;
         while( Res1 != Res2) {
           Res1  =  Aleanombre(10 ) ;
           Res2  =  Aleanombre(10 ) ;

         } ;

       } ;
       if( Rep1 < Rep2) {
         Difrep  =  Rep2 - Rep1 ;
         Pos  =  Aleanombre ( Difrep + 15 ) ;
        /*L'equipe 2 doit gagner*/
         if( Pos < Difrep) {
           Res1  =  Aleanombre(10 ) ;
           Res2  =  Aleanombre(10 ) ;
           while( Res2 < Res1) {
             Res1  =  Aleanombre(10 ) ;
             Res2  =  Aleanombre(10 ) ;

           } ;
           }
         else
           {
          /*Le match doit etre null*/
           if( Pos < Difrep + 10) {
             Res1  =  Aleanombre(10 ) ;
             Res2  =  Aleanombre(10 ) ;
             while( Res1 != Res2) {
               Res1  =  Aleanombre(10 ) ;
               Res2  =  Aleanombre(10 ) ;

             } ;
             }
          /*L'equipe 1 doit gagner*/
           else
             {
             Res1  =  Aleanombre(10 ) ;
             Res2  =  Aleanombre(10 ) ;
             while( Res1 < Res2) {
               Res1  =  Aleanombre(10 ) ;
               Res2  =  Aleanombre(10 ) ;

             } ;

           } ;

         } ;

       } ;
       S_S.Champ1 = Eq1 ;
       S_S.Champ2 = Eq2 ;
       S_S.Champ3 = Res1 ;
       S_S.Champ4 = Res2 ;
       Init_struct_Tiiii ( S , S_S )  ;
       Aff_val_LTiiii ( P , S ) ;
       Eq_gagn ( & Eq1 , & Eq2 , & Res1 , & Res2 , & *Tab_eq_pts ) ;
       P  =  Suivant_LTiiii ( P ) ;

     } ;

   } ;

  }
void Sim_maxsc (Typevect_V8LTiiii *Tab_grpmatch , Typevect_V32i *Tab_eq_pts , int *Maxsc)
  {
    /** Variables locales **/
    Pointeur_LTiiii P=NULL;
    Typestr_Tiiii S;
    int I;
    int Eq1;
    int Eq2;
    int Res1;
    int Res2;
    int Pts;
    Type_Tiiii S_S;

    /** Corps du module **/
   S = malloc(sizeof(Type_Tiiii));
   for( I  =  1 ;I <=  8 ; ++I){
     P  =  Element_V8LTiiii ( *Tab_grpmatch , I   ) ;
     while( P != NULL) {
    /* Affectation globale de structure */
       S->Champ1 =   Valeur_LTiiii ( P )->Champ1;
       S->Champ2 =   Valeur_LTiiii ( P )->Champ2;
       S->Champ3 =   Valeur_LTiiii ( P )->Champ3;
       S->Champ4 =   Valeur_LTiiii ( P )->Champ4;
;
       Eq1  =  Struct1_Tiiii ( S  ) ;
       Eq2  =  Struct2_Tiiii ( S  ) ;
       Res1  =  Aleanombre(10 ) ;
       Res2  =  Aleanombre(10 ) ;
       S_S.Champ1 = Eq1 ;
       S_S.Champ2 = Eq2 ;
       S_S.Champ3 = Res1 ;
       S_S.Champ4 = Res2 ;
       Init_struct_Tiiii ( S , S_S )  ;
       Aff_val_LTiiii ( P , S ) ;
      /*l'equipe 1 est gagnate comme son resultat est superieure a maxsc*/
       if( Res1 > *Maxsc) {
         Pts  =  Element_V32i ( *Tab_eq_pts , Eq1   ) + 3 ;
         Aff_element_V32i ( *Tab_eq_pts , Eq1   , Pts ) ;

       } ;
      /*l'equipe 2 est gagnate comme son resultat est superieure a maxsc*/
       if( Res2 > *Maxsc) {
         Pts  =  Element_V32i ( *Tab_eq_pts , Eq2   ) + 3 ;
         Aff_element_V32i ( *Tab_eq_pts , Eq2   , Pts ) ;

       } ;
      /*l'equipe 1 a un resultat egal a maxsc donc c'est considéré comme null */
       if( Res1 == *Maxsc) {
         Pts  =  Element_V32i ( *Tab_eq_pts , Eq1   ) + 1 ;
         Aff_element_V32i ( *Tab_eq_pts , Eq1   , Pts ) ;

       } ;
      /*l'equipe 2 a un resultat egal a maxsc donc c'est considéré comme null */
       if( Res2 == *Maxsc) {
         Pts  =  Element_V32i ( *Tab_eq_pts , Eq2   ) + 1 ;
         Aff_element_V32i ( *Tab_eq_pts , Eq2   , Pts ) ;

       } ;
       P  =  Suivant_LTiiii ( P ) ;

     } ;

   } ;

  }
void Affichage (Typevect_V8LTiiii *Tab_grpmatch , Typevect_V32i *Tab_eq_pts)
  {
    /** Variables locales **/
    Typestr_Tiiii Sg;
    Pointeur_LTiiii P=NULL;
    int I;
    int K;

    /** Corps du module **/
   Sg = malloc(sizeof(Type_Tiiii));
   K  =  1 ;
   for( J  =  1 ;J <=  8 ; ++J){
     printf ( " %s", "groupe" );
     printf ( " %d", J ) ;
     P  =  Element_V8LTiiii ( *Tab_grpmatch , 1   ) ;
     while( P != NULL) {
    /* Affectation globale de structure */
       Sg->Champ1 =   Valeur_LTiiii ( P )->Champ1;
       Sg->Champ2 =   Valeur_LTiiii ( P )->Champ2;
       Sg->Champ3 =   Valeur_LTiiii ( P )->Champ3;
       Sg->Champ4 =   Valeur_LTiiii ( P )->Champ4;
;
       printf ( " %s", "match: " ) ;
       /** Ecriture d'une structure */
       printf ( " %d", Sg->Champ1 );
       printf ( " %d", Sg->Champ2 );
       printf ( " %d", Sg->Champ3 );
       printf ( " %d", Sg->Champ4 ) ;
       P  =  Suivant_LTiiii ( P ) ;

     } ;
     printf ( " %s", "" );
     printf ( " %s", "" ) ;
     for( I  =  K ;I <=  K + 3 ; ++I){
       printf ( " %s", "eq, " );
       printf ( " %d", I ) ;
       printf ( " %d", Element_V32i(*Tab_eq_pts,I) );
       printf ( " %s", "pts." ) ;

     } ;
     K  =  K + 4 ;
     printf ( " %s", "-------------" );
     printf ( " %s", "" ) ;

   } ;

  }
void Creer_tab_rep (Typevect_V32i *Tab_eq_rep)
  {
    /** Variables locales **/
    int I;
    int Rep;

    /** Corps du module **/
   Aff_element_V32i ( *Tab_eq_rep , 1   , 42 ) ;
   Aff_element_V32i ( *Tab_eq_rep , 2   , 47 ) ;
   Aff_element_V32i ( *Tab_eq_rep , 3   , 52 ) ;
   Aff_element_V32i ( *Tab_eq_rep , 4   , 39 ) ;
   Aff_element_V32i ( *Tab_eq_rep , 5   , 76 ) ;
   Aff_element_V32i ( *Tab_eq_rep , 6   , 51 ) ;
   Aff_element_V32i ( *Tab_eq_rep , 7   , 59 ) ;
   Aff_element_V32i ( *Tab_eq_rep , 8   , 41 ) ;
   Aff_element_V32i ( *Tab_eq_rep , 9   , 78 ) ;
   Aff_element_V32i ( *Tab_eq_rep , 10   , 55 ) ;
   Aff_element_V32i ( *Tab_eq_rep , 11   , 51 ) ;
   Aff_element_V32i ( *Tab_eq_rep , 12   , 51 ) ;
   Aff_element_V32i ( *Tab_eq_rep , 13   , 72 ) ;
   Aff_element_V32i ( *Tab_eq_rep , 14   , 61 ) ;
   Aff_element_V32i ( *Tab_eq_rep , 15   , 52 ) ;
   Aff_element_V32i ( *Tab_eq_rep , 16   , 54 ) ;
   Aff_element_V32i ( *Tab_eq_rep , 17   , 82 ) ;
   Aff_element_V32i ( *Tab_eq_rep , 18   , 76 ) ;
   Aff_element_V32i ( *Tab_eq_rep , 19   , 54 ) ;
   Aff_element_V32i ( *Tab_eq_rep , 20   , 56 ) ;
   Aff_element_V32i ( *Tab_eq_rep , 21   , 59 ) ;
   Aff_element_V32i ( *Tab_eq_rep , 22   , 67 ) ;
   Aff_element_V32i ( *Tab_eq_rep , 23   , 57 ) ;
   Aff_element_V32i ( *Tab_eq_rep , 24   , 59 ) ;
   Aff_element_V32i ( *Tab_eq_rep , 25   , 81 ) ;
   Aff_element_V32i ( *Tab_eq_rep , 26   , 49 ) ;
   Aff_element_V32i ( *Tab_eq_rep , 27   , 55 ) ;
   Aff_element_V32i ( *Tab_eq_rep , 28   , 51 ) ;
   Aff_element_V32i ( *Tab_eq_rep , 29   , 74 ) ;
   Aff_element_V32i ( *Tab_eq_rep , 30   , 64 ) ;
   Aff_element_V32i ( *Tab_eq_rep , 31   , 63 ) ;
   Aff_element_V32i ( *Tab_eq_rep , 32   , 51 ) ;

  }
void Creer_tab_phase2 (Typevect_V15Tiiii *Tab_phase2 , Typevect_V8i *Tab_grp_cls1 , Typevect_V8i *Tab_grp_cls2)
  {
    /** Variables locales **/
    int I;
    int J;
    Typestr_Tiiii Sg;
    Type_Tiiii S_Sg;

    /** Corps du module **/
   Sg = malloc(sizeof(Type_Tiiii));
   S_Sg.Champ1 = 0 ;
   S_Sg.Champ2 = 0 ;
   S_Sg.Champ3 = 0 ;
   S_Sg.Champ4 = 0 ;
   Init_struct_Tiiii ( Sg , S_Sg )  ;
   for( I  =  1 ;I <=  7 ; ++I){
     Aff_element_V15Tiiii ( *Tab_phase2 , I   , Sg ) ;

   } ;
   J  =  1 ;
   for( I  =  8 ;I <=  15 ; ++I){
     if( Mod ( J , 2 ) == 0) {
       S_Sg.Champ1 = Element_V8i(*Tab_grp_cls1,J) ;
       S_Sg.Champ2 = Element_V8i(*Tab_grp_cls2,J-1) ;
       S_Sg.Champ3 = 0 ;
       S_Sg.Champ4 = 0 ;
       Init_struct_Tiiii ( Sg , S_Sg )  ;
       }
     else
       {
       S_Sg.Champ1 = Element_V8i(*Tab_grp_cls1,J) ;
       S_Sg.Champ2 = Element_V8i(*Tab_grp_cls2,J+1) ;
       S_Sg.Champ3 = 0 ;
       S_Sg.Champ4 = 0 ;
       Init_struct_Tiiii ( Sg , S_Sg )  ;

     } ;
     Aff_element_V15Tiiii ( *Tab_phase2 , I   , Sg ) ;
     J  =  J + 1 ;

   } ;

  }
Pointeur_ATiiii Creer_arb_match (Typevect_V15Tiiii *Tab_phase2 , Pointeur_ATiiii *Arb_match , int *I , int *N)
  {
    /** Variables locales **/
    Pointeur_ATiiii Creer_arb_match2 =NULL;
    Pointeur_ATiiii P=NULL;
    Typestr_Tiiii Sg;
    Pointeur_ATiiii _Px1=NULL;
    int _Px2;
    Pointeur_ATiiii _Px3=NULL;
    int _Px4;

    /** Corps du module **/
   Sg = malloc(sizeof(Type_Tiiii));
  /*Le cas de base*/
   if( *I < *N)   {
     Creernoeud_ATiiii (& P ) ;
    /* Affectation globale de structure */
     Sg->Champ1 =   Element_V15Tiiii ( *Tab_phase2 , *I   )->Champ1;
     Sg->Champ2 =   Element_V15Tiiii ( *Tab_phase2 , *I   )->Champ2;
     Sg->Champ3 =   Element_V15Tiiii ( *Tab_phase2 , *I   )->Champ3;
     Sg->Champ4 =   Element_V15Tiiii ( *Tab_phase2 , *I   )->Champ4;
;
     Aff_info_ATiiii ( P , Sg ) ;
     *Arb_match  =  P ;
    /*inserer le fils gauche*/
     _Px1 =  Fg_ATiiii ( *Arb_match ) ;
     _Px2 =  2 * *I ;
     Aff_fg_ATiiii ( *Arb_match , Creer_arb_match ( & *Tab_phase2 , &_Px1, &_Px2, & *N ) ) ;
    /*inserer le fils droite*/
     _Px3 =  Fd_ATiiii ( *Arb_match ) ;
     _Px4 =  2 * *I + 1 ;
     Aff_fd_ATiiii ( *Arb_match , Creer_arb_match ( & *Tab_phase2 , &_Px3, &_Px4, & *N ) ) ;

   } ;
   Creer_arb_match2  =  *Arb_match ;

   return Creer_arb_match2 ;
  }
void Inordre (Pointeur_ATiiii *R)
  {
    /** Variables locales **/
    Pointeur_ATiiii _Px1=NULL;
    Type_Tiiii _Struct_Temp1;
    Pointeur_ATiiii _Px2=NULL;

    /** Corps du module **/
   if( *R != NULL) {
     _Px1 =  Fg_ATiiii ( *R ) ;
     Inordre ( &_Px1) ;
     printf ( " %s", "" );
     /** Ecriture d'une structure */
     _Struct_Temp1 = *Info_ATiiii(*R);
     printf ( " %d", _Struct_Temp1.Champ1 );
     printf ( " %d", _Struct_Temp1.Champ2 );
     printf ( " %d", _Struct_Temp1.Champ3 );
     printf ( " %d", _Struct_Temp1.Champ4 );
     printf ( " %s", "" ) ;
     _Px2 =  Fd_ATiiii ( *R ) ;
     Inordre ( &_Px2) ;

   } ;

  }
void Parcourenlargeur (Pointeur_ATiiii *R)
  {
    /** Variables locales **/
    Pointeur_ATiiii P=NULL;
    Pointeur_FATiiii F=NULL;
    Typestr_Tiiii Sg;
    Type_Tiiii _Struct_Temp2;

    /** Corps du module **/
   Sg = malloc(sizeof(Type_Tiiii));
   Creerfile_FATiiii (& F ) ;
   if( *R != NULL) {
     Enfiler_FATiiii ( F , *R ) ;

   } ;
   while( ! Filevide_FATiiii ( F )) {
     Defiler_FATiiii ( F , &P ) ;
     /** Ecriture d'une structure */
     _Struct_Temp2 = *Info_ATiiii(P);
     printf ( " %d", _Struct_Temp2.Champ1 );
     printf ( " %d", _Struct_Temp2.Champ2 );
     printf ( " %d", _Struct_Temp2.Champ3 );
     printf ( " %d", _Struct_Temp2.Champ4 ) ;
     if( Fg_ATiiii ( P ) != NULL) {
       Enfiler_FATiiii ( F , Fg_ATiiii ( P ) ) ;

     } ;
     if( Fd_ATiiii ( P ) != NULL) {
       Enfiler_FATiiii ( F , Fd_ATiiii ( P ) ) ;

     } ;

   } ;

  }
void Parlarginv (Pointeur_ATiiii *R , Pointeur_PATiiii *Pi)
  {
    /** Variables locales **/
    Pointeur_ATiiii P=NULL;
    Pointeur_FATiiii F=NULL;
    Typestr_Tiiii Sg;

    /** Corps du module **/
   Sg = malloc(sizeof(Type_Tiiii));
   Creerfile_FATiiii (& F ) ;
   Creerpile_PATiiii (& *Pi ) ;
   if( *R != NULL) {
     Enfiler_FATiiii ( F , *R ) ;
     Empiler_PATiiii (& *Pi , *R ) ;

   } ;
   while( ! Filevide_FATiiii ( F )) {
     Defiler_FATiiii ( F , &P ) ;
     if( Fd_ATiiii ( P ) != NULL) {
       Enfiler_FATiiii ( F , Fd_ATiiii ( P ) ) ;
       Empiler_PATiiii (& *Pi , Fd_ATiiii ( P ) ) ;

     } ;
     if( Fd_ATiiii ( P ) != NULL) {
       Enfiler_FATiiii ( F , Fg_ATiiii ( P ) ) ;
       Empiler_PATiiii (& *Pi , Fg_ATiiii ( P ) ) ;

     } ;

   } ;

  }
void Affichage_arb (Pointeur_PATiiii *Pi)
  {
    /** Variables locales **/
    Pointeur_ATiiii P=NULL;
    Type_Tiiii _Struct_Temp3;

    /** Corps du module **/
   while( ! Pilevide_PATiiii ( *Pi )) {
     Depiler_PATiiii (& *Pi , &P ) ;
     /** Ecriture d'une structure */
     _Struct_Temp3 = *Info_ATiiii(P);
     printf ( " %d", _Struct_Temp3.Champ1 );
     printf ( " %d", _Struct_Temp3.Champ2 );
     printf ( " %d", _Struct_Temp3.Champ3 );
     printf ( " %d", _Struct_Temp3.Champ4 ) ;

   } ;

  }
void Ph2_sim_hasard (Pointeur_ATiiii *Arb_match)
  {
    /** Variables locales **/
    Pointeur_PATiiii Pi=NULL;
    Pointeur_ATiiii P=NULL;
    Typestr_Tiiii Sg;
    Typestr_Tiiii Sh;
    int I;
    int Eq1;
    int Eq2;
    int Res1;
    int Res2;
    int Alea;
    Type_Tiiii S_Sg;
    Type_Tiiii S_Sh;

    /** Corps du module **/
   Sg = malloc(sizeof(Type_Tiiii));
   Sh = malloc(sizeof(Type_Tiiii));
   Parlarginv ( & *Arb_match , & Pi ) ;
   I  =  1 ;
   while( I <= 8) {
     Depiler_PATiiii (& Pi , &P ) ;
    /* Affectation globale de structure */
     Sg->Champ1 =   Info_ATiiii ( P )->Champ1;
     Sg->Champ2 =   Info_ATiiii ( P )->Champ2;
     Sg->Champ3 =   Info_ATiiii ( P )->Champ3;
     Sg->Champ4 =   Info_ATiiii ( P )->Champ4;
;
     Res1  =  Aleanombre(20 ) ;
     Res2  =  Aleanombre(20 ) ;
     S_Sg.Champ1 = Struct1_Tiiii(Sg) ;
     S_Sg.Champ2 = Struct2_Tiiii(Sg) ;
     S_Sg.Champ3 = Res1 ;
     S_Sg.Champ4 = Res2 ;
     Init_struct_Tiiii ( Sg , S_Sg )  ;
     Aff_info_ATiiii ( P , Sg ) ;
     I  =  I + 1 ;

   } ;
   I  =  1 ;
   while( I <= 7) {
     Depiler_PATiiii (& Pi , &P ) ;
    /* Affectation globale de structure */
     Sg->Champ1 =   Info_ATiiii ( Fd_ATiiii ( P ) )->Champ1;
     Sg->Champ2 =   Info_ATiiii ( Fd_ATiiii ( P ) )->Champ2;
     Sg->Champ3 =   Info_ATiiii ( Fd_ATiiii ( P ) )->Champ3;
     Sg->Champ4 =   Info_ATiiii ( Fd_ATiiii ( P ) )->Champ4;
;
    /* Affectation globale de structure */
     Sh->Champ1 =   Info_ATiiii ( P )->Champ1;
     Sh->Champ2 =   Info_ATiiii ( P )->Champ2;
     Sh->Champ3 =   Info_ATiiii ( P )->Champ3;
     Sh->Champ4 =   Info_ATiiii ( P )->Champ4;
;
     Res1  =  Struct3_Tiiii ( Sg  ) ;
     Res2  =  Struct4_Tiiii ( Sg  ) ;
    /*l'equipe 1 est gagnante*/
     if( Res1 > Res2) {
       S_Sh.Champ1 = Struct1_Tiiii(Sh) ;
       S_Sh.Champ2 = Struct1_Tiiii(Sg) ;
       S_Sh.Champ3 = Aleanombre(20) ;
       S_Sh.Champ4 = Aleanombre(20) ;
       Init_struct_Tiiii ( Sh , S_Sh )  ;
       Aff_info_ATiiii ( P , Sh ) ;

     } ;
    /*le match est nul, affectuer un tirage au sort*/
     if( Res1 == Res2) {
       Alea  =  Aleanombre(2 ) ;
      /*l'equipe 1 est gagnante*/
       if( Alea == 1) {
         S_Sh.Champ1 = Struct1_Tiiii(Sh) ;
         S_Sh.Champ2 = Struct1_Tiiii(Sg) ;
         S_Sh.Champ3 = Aleanombre(20) ;
         S_Sh.Champ4 = Aleanombre(20) ;
         Init_struct_Tiiii ( Sh , S_Sh )  ;
         Aff_info_ATiiii ( P , Sh ) ;
         }
      /*l'equipe 2 est gagnante*/
       else
         {
         S_Sh.Champ1 = Struct2_Tiiii(Sh) ;
         S_Sh.Champ2 = Struct2_Tiiii(Sg) ;
         S_Sh.Champ3 = Aleanombre(20) ;
         S_Sh.Champ4 = Aleanombre(20) ;
         Init_struct_Tiiii ( Sh , S_Sh )  ;
         Aff_info_ATiiii ( P , Sh ) ;

       } ;

     } ;
    /*l'equipe 2 est gagnante*/
     if( Res1 < Res2) {
       S_Sh.Champ1 = Struct2_Tiiii(Sh) ;
       S_Sh.Champ2 = Struct2_Tiiii(Sg) ;
       S_Sh.Champ3 = Aleanombre(20) ;
       S_Sh.Champ4 = Aleanombre(20) ;
       Init_struct_Tiiii ( Sh , S_Sh )  ;
       Aff_info_ATiiii ( P , Sh ) ;

     } ;
    /* Affectation globale de structure */
     Sg->Champ1 =   Info_ATiiii ( Fg_ATiiii ( P ) )->Champ1;
     Sg->Champ2 =   Info_ATiiii ( Fg_ATiiii ( P ) )->Champ2;
     Sg->Champ3 =   Info_ATiiii ( Fg_ATiiii ( P ) )->Champ3;
     Sg->Champ4 =   Info_ATiiii ( Fg_ATiiii ( P ) )->Champ4;
;
     Res1  =  Struct3_Tiiii ( Sg  ) ;
     Res2  =  Struct4_Tiiii ( Sg  ) ;
    /*l'equipe 1 est gagnante*/
     if( Res1 > Res2) {
       S_Sh.Champ1 = Struct1_Tiiii(Sg) ;
       S_Sh.Champ2 = Struct2_Tiiii(Sh) ;
       S_Sh.Champ3 = Aleanombre(20) ;
       S_Sh.Champ4 = Aleanombre(20) ;
       Init_struct_Tiiii ( Sh , S_Sh )  ;
       Aff_info_ATiiii ( P , Sh ) ;

     } ;
    /*le match est nul, affectuer un tirage au sort*/
     if( Res1 == Res2) {
       Alea  =  Aleanombre(2 ) ;
      /*l'equipe 1 est gagnante*/
       if( Alea == 1) {
         S_Sh.Champ1 = Struct1_Tiiii(Sg) ;
         S_Sh.Champ2 = Struct2_Tiiii(Sh) ;
         S_Sh.Champ3 = Aleanombre(20) ;
         S_Sh.Champ4 = Aleanombre(20) ;
         Init_struct_Tiiii ( Sh , S_Sh )  ;
         Aff_info_ATiiii ( P , Sh ) ;
         }
      /*l'equipe 2 est gagnante*/
       else
         {
         S_Sh.Champ1 = Struct2_Tiiii(Sg) ;
         S_Sh.Champ2 = Struct2_Tiiii(Sh) ;
         S_Sh.Champ3 = Aleanombre(20) ;
         S_Sh.Champ4 = Aleanombre(20) ;
         Init_struct_Tiiii ( Sh , S_Sh )  ;
         Aff_info_ATiiii ( P , Sh ) ;

       } ;

     } ;
    /*l'equipe 2 est gagnante*/
     if( Res1 < Res2) {
       S_Sh.Champ1 = Struct2_Tiiii(Sg) ;
       S_Sh.Champ2 = Struct2_Tiiii(Sh) ;
       S_Sh.Champ3 = Aleanombre(20) ;
       S_Sh.Champ4 = Aleanombre(20) ;
       Init_struct_Tiiii ( Sh , S_Sh )  ;
       Aff_info_ATiiii ( P , Sh ) ;

     } ;
     I  =  I + 1 ;

   }
  }
void Ph2_sim_eqfav (Pointeur_ATiiii *Arb_match , Typevect_V15Tiiii *Tab_phase2 , Typevect_V32i *Tab_eq_rep)
  {
    /** Variables locales **/
    Typestr_Tiiii Sg;
    Typestr_Tiiii Sh;
    int I;
    int J;
    int Alea;
    int Eq1;
    int Eq2;
    int Rep1;
    int Rep2;
    int Res1;
    int Res2;
    Type_Tiiii S_Sg;
    int _Px1;
    int _Px2;

    /** Corps du module **/
   Sg = malloc(sizeof(Type_Tiiii));
   Sh = malloc(sizeof(Type_Tiiii));
   for( I  =  8 ;I <=  15 ; ++I){
    /* Affectation globale de structure */
     Sg->Champ1 =   Element_V15Tiiii ( *Tab_phase2 , I   )->Champ1;
     Sg->Champ2 =   Element_V15Tiiii ( *Tab_phase2 , I   )->Champ2;
     Sg->Champ3 =   Element_V15Tiiii ( *Tab_phase2 , I   )->Champ3;
     Sg->Champ4 =   Element_V15Tiiii ( *Tab_phase2 , I   )->Champ4;
;
     Eq1  =  Struct1_Tiiii ( Sg  ) ;
     Eq2  =  Struct2_Tiiii ( Sg  ) ;
     Rep1  =  Element_V32i ( *Tab_eq_rep , Eq1   ) ;
     Rep2  =  Element_V32i ( *Tab_eq_rep , Eq2   ) ;
    /*l'equipe1 doit gagner*/
     if( Rep1 - Rep2 >= 5) {
       Res1  =  Aleanombre(10 ) ;
       Res2  =  Aleanombre(10 ) ;
       while( Res1 < Res2) {
         Res1  =  Aleanombre(10 ) ;
         Res2  =  Aleanombre(10 ) ;

       } ;

     } ;
     if( Rep1 - Rep2 < 5) {
       if( Rep1 - Rep2 >= 0) {
         Res1  =  Aleanombre(10 ) ;
         Res2  =  Aleanombre(10 ) ;
         while( Res1 != Res2) {
           Res1  =  Aleanombre(10 ) ;
           Res2  =  Aleanombre(10 ) ;

         } ;

       } ;

     } ;
    /*l'equipe2 doit gagner*/
     if( Rep2 - Rep1 > 5) {
       Res1  =  Aleanombre(10 ) ;
       Res2  =  Aleanombre(10 ) ;
       while( Res2 < Res1) {
         Res1  =  Aleanombre(10 ) ;
         Res2  =  Aleanombre(10 ) ;

       } ;

     } ;
     if( Rep2 - Rep1 < 5) {
       if( Rep2 - Rep1 >= 0) {
         Res1  =  Aleanombre(10 ) ;
         Res2  =  Aleanombre(10 ) ;
         while( Res1 != Res2) {
           Res1  =  Aleanombre(10 ) ;
           Res2  =  Aleanombre(10 ) ;

         } ;

       } ;

     } ;
     S_Sg.Champ1 = Eq1 ;
     S_Sg.Champ2 = Eq2 ;
     S_Sg.Champ3 = Res1 ;
     S_Sg.Champ4 = Res2 ;
     Init_struct_Tiiii ( Sg , S_Sg )  ;
     Aff_element_V15Tiiii ( *Tab_phase2 , I   , Sg ) ;

   } ;
   Ph2_sim_eqfav2 ( & *Tab_phase2 , & *Tab_eq_rep ) ;
   _Px1 =  1 ;
   _Px2 =  16 ;
   *Arb_match  =  Creer_arb_match ( & *Tab_phase2 , & *Arb_match , &_Px1, &_Px2) ;

  }
void Ph2_sim_eqfav2 (Typevect_V15Tiiii *Tab_phase2 , Typevect_V32i *Tab_eq_rep)
  {
    /** Variables locales **/
    Typestr_Tiiii Sg;
    Typestr_Tiiii Sh;
    int I;
    int J;
    int Alea;
    int Eq1;
    int Eq2;
    int Rep1;
    int Rep2;
    int Res1;
    int Res2;
    Type_Tiiii S_Sh;

    /** Corps du module **/
   Sg = malloc(sizeof(Type_Tiiii));
   Sh = malloc(sizeof(Type_Tiiii));
   J  =  15 ;
   for( I  =  7 ;I >=  1   ; --I){
    /* Affectation globale de structure */
     Sh->Champ1 =   Element_V15Tiiii ( *Tab_phase2 , I   )->Champ1;
     Sh->Champ2 =   Element_V15Tiiii ( *Tab_phase2 , I   )->Champ2;
     Sh->Champ3 =   Element_V15Tiiii ( *Tab_phase2 , I   )->Champ3;
     Sh->Champ4 =   Element_V15Tiiii ( *Tab_phase2 , I   )->Champ4;
;
    /* Affectation globale de structure */
     Sg->Champ1 =   Element_V15Tiiii ( *Tab_phase2 , J   )->Champ1;
     Sg->Champ2 =   Element_V15Tiiii ( *Tab_phase2 , J   )->Champ2;
     Sg->Champ3 =   Element_V15Tiiii ( *Tab_phase2 , J   )->Champ3;
     Sg->Champ4 =   Element_V15Tiiii ( *Tab_phase2 , J   )->Champ4;
;
     Res1  =  Struct3_Tiiii ( Sg  ) ;
     Res2  =  Struct4_Tiiii ( Sg  ) ;
    /*l'equipe 1 est gagnante*/
     if( Res1 > Res2) {
       S_Sh.Champ1 = Struct1_Tiiii(Sh) ;
       S_Sh.Champ2 = Struct1_Tiiii(Sg) ;
       S_Sh.Champ3 = 0 ;
       S_Sh.Champ4 = 0 ;
       Init_struct_Tiiii ( Sh , S_Sh )  ;

     } ;
    /*le match est nul, affectuer un tirage au sort*/
     if( Res1 == Res2) {
       Alea  =  Aleanombre(2 ) ;
      /*l'equipe 1 est gagnante*/
       if( Alea == 1) {
         S_Sh.Champ1 = Struct1_Tiiii(Sh) ;
         S_Sh.Champ2 = Struct1_Tiiii(Sg) ;
         S_Sh.Champ3 = 0 ;
         S_Sh.Champ4 = 0 ;
         Init_struct_Tiiii ( Sh , S_Sh )  ;
         }
      /*l'equipe 2 est gagnante*/
       else
         {
         S_Sh.Champ1 = Struct1_Tiiii(Sh) ;
         S_Sh.Champ2 = Struct2_Tiiii(Sg) ;
         S_Sh.Champ3 = 0 ;
         S_Sh.Champ4 = 0 ;
         Init_struct_Tiiii ( Sh , S_Sh )  ;

       } ;

     } ;
    /*l'equipe 2 est gagnante*/
     if( Res1 < Res2) {
       S_Sh.Champ1 = Struct1_Tiiii(Sh) ;
       S_Sh.Champ2 = Struct2_Tiiii(Sg) ;
       S_Sh.Champ3 = 0 ;
       S_Sh.Champ4 = 0 ;
       Init_struct_Tiiii ( Sh , S_Sh )  ;

     } ;
     J  =  J - 1 ;
    /* Affectation globale de structure */
     Sg->Champ1 =   Element_V15Tiiii ( *Tab_phase2 , J   )->Champ1;
     Sg->Champ2 =   Element_V15Tiiii ( *Tab_phase2 , J   )->Champ2;
     Sg->Champ3 =   Element_V15Tiiii ( *Tab_phase2 , J   )->Champ3;
     Sg->Champ4 =   Element_V15Tiiii ( *Tab_phase2 , J   )->Champ4;
;
     Res1  =  Struct3_Tiiii ( Sg  ) ;
     Res2  =  Struct4_Tiiii ( Sg  ) ;
    /*l'equipe 1 est gagnante*/
     if( Res1 > Res2) {
       S_Sh.Champ1 = Struct1_Tiiii(Sg) ;
       S_Sh.Champ2 = Struct2_Tiiii(Sh) ;
       S_Sh.Champ3 = 0 ;
       S_Sh.Champ4 = 0 ;
       Init_struct_Tiiii ( Sh , S_Sh )  ;

     } ;
    /*le match est nul, affectuer un tirage au sort*/
     if( Res1 == Res2) {
       Alea  =  Aleanombre(2 ) ;
      /*l'equipe 1 est gagnante*/
       if( Alea == 1) {
         S_Sh.Champ1 = Struct1_Tiiii(Sg) ;
         S_Sh.Champ2 = Struct2_Tiiii(Sh) ;
         S_Sh.Champ3 = 0 ;
         S_Sh.Champ4 = 0 ;
         Init_struct_Tiiii ( Sh , S_Sh )  ;
         }
      /*l'equipe 2 est gagnante*/
       else
         {
         S_Sh.Champ1 = Struct2_Tiiii(Sg) ;
         S_Sh.Champ2 = Struct2_Tiiii(Sh) ;
         S_Sh.Champ3 = 0 ;
         S_Sh.Champ4 = 0 ;
         Init_struct_Tiiii ( Sh , S_Sh )  ;

       } ;

     } ;
    /*l'equipe 2 est gagnante*/
     if( Res1 < Res2) {
       S_Sh.Champ1 = Struct2_Tiiii(Sg) ;
       S_Sh.Champ2 = Struct2_Tiiii(Sh) ;
       S_Sh.Champ3 = 0 ;
       S_Sh.Champ4 = 0 ;
       Init_struct_Tiiii ( Sh , S_Sh )  ;

     } ;
     Eq1  =  Struct1_Tiiii ( Sh  ) ;
     Eq2  =  Struct2_Tiiii ( Sh  ) ;
     Rep1  =  Element_V32i ( *Tab_eq_rep , Eq1   ) ;
     Rep2  =  Element_V32i ( *Tab_eq_rep , Eq2   ) ;
    /*l'equipe1 doit gagner*/
     if( Rep1 - Rep2 >= 5) {
       Res1  =  Aleanombre(10 ) ;
       Res2  =  Aleanombre(10 ) ;
       while( Res1 < Res2) {
         Res1  =  Aleanombre(10 ) ;
         Res2  =  Aleanombre(10 ) ;

       } ;

     } ;
     if( Rep1 - Rep2 < 5) {
       if( Rep1 - Rep2 >= 0) {
         Res1  =  Aleanombre(10 ) ;
         Res2  =  Aleanombre(10 ) ;
         while( Res1 != Res2) {
           Res1  =  Aleanombre(10 ) ;
           Res2  =  Aleanombre(10 ) ;

         } ;

       } ;

     } ;
    /*l'equipe2 doit gagner*/
     if( Rep2 - Rep1 >= 5) {
       Res1  =  Aleanombre(10 ) ;
       Res2  =  Aleanombre(10 ) ;
       while( Res2 < Res1) {
         Res1  =  Aleanombre(10 ) ;
         Res2  =  Aleanombre(10 ) ;

       } ;

     } ;
     if( Rep2 - Rep1 < 5) {
       if( Rep2 - Rep1 >= 0) {
         Res1  =  Aleanombre(10 ) ;
         Res2  =  Aleanombre(10 ) ;
         while( Res1 != Res2) {
           Res1  =  Aleanombre(10 ) ;
           Res2  =  Aleanombre(10 ) ;

         } ;

       } ;

     } ;
     S_Sh.Champ1 = Eq1 ;
     S_Sh.Champ2 = Eq2 ;
     S_Sh.Champ3 = Res1 ;
     S_Sh.Champ4 = Res2 ;
     Init_struct_Tiiii ( Sh , S_Sh )  ;
     Aff_element_V15Tiiii ( *Tab_phase2 , I   , Sh ) ;
     J  =  J - 1 ;

   } ;

  }
void Creer_tabtotbuts (Typevect_V8LTiiii *Tab_grpmatch , Typevect_V32i *Tab_eq_totbuts)
  {
    /** Variables locales **/
    Pointeur_LTiiii P=NULL;
    Typestr_Tiiii Sg;
    int I;

    /** Corps du module **/
   Sg = malloc(sizeof(Type_Tiiii));
   Init_tabeq ( & *Tab_eq_totbuts ) ;
   for( I  =  1 ;I <=  8 ; ++I){
     P  =  Element_V8LTiiii ( *Tab_grpmatch , I   ) ;
     while( P != NULL) {
    /* Affectation globale de structure */
       Sg->Champ1 =   Valeur_LTiiii ( P )->Champ1;
       Sg->Champ2 =   Valeur_LTiiii ( P )->Champ2;
       Sg->Champ3 =   Valeur_LTiiii ( P )->Champ3;
       Sg->Champ4 =   Valeur_LTiiii ( P )->Champ4;
;
       Aff_element_V32i ( *Tab_eq_totbuts , Struct1_Tiiii ( Sg  )   , Struct3_Tiiii ( Sg  ) + Element_V32i ( *Tab_eq_totbuts , Struct1_Tiiii ( Sg  )   ) ) ;
       Aff_element_V32i ( *Tab_eq_totbuts , Struct2_Tiiii ( Sg  )   , Struct4_Tiiii ( Sg  ) + Element_V32i ( *Tab_eq_totbuts , Struct2_Tiiii ( Sg  )   ) ) ;
       P  =  Suivant_LTiiii ( P ) ;

     } ;

   } ;

  }
void Ph2_sim_resph12 (Pointeur_ATiiii *Arb_match , Typevect_V32i *Tab_eq_totbuts , int *Ch)
  {
    /** Variables locales **/
    Pointeur_PATiiii Pi=NULL;
    Pointeur_ATiiii P=NULL;
    Typestr_Tiiii Sg;
    Typestr_Tiiii Sh;
    int Eq1;
    int Eq2;
    int Res1;
    int Res2;
    int Buts1;
    int Buts2;
    Type_Tiiii S_Sg;

    /** Corps du module **/
   Sg = malloc(sizeof(Type_Tiiii));
   Sh = malloc(sizeof(Type_Tiiii));
   Parlarginv ( & *Arb_match , & Pi ) ;
   for( I  =  1 ;I <=  8 ; ++I){
     Depiler_PATiiii (& Pi , &P ) ;
    /* Affectation globale de structure */
     Sg->Champ1 =   Info_ATiiii ( P )->Champ1;
     Sg->Champ2 =   Info_ATiiii ( P )->Champ2;
     Sg->Champ3 =   Info_ATiiii ( P )->Champ3;
     Sg->Champ4 =   Info_ATiiii ( P )->Champ4;
;
     Eq1  =  Struct1_Tiiii ( Sg  ) ;
     Eq2  =  Struct2_Tiiii ( Sg  ) ;
     Buts1  =  Element_V32i ( *Tab_eq_totbuts , Eq1   ) ;
     Buts2  =  Element_V32i ( *Tab_eq_totbuts , Eq2   ) ;
    /*l'equipe1 doit gagner*/
     if( Buts1 - Buts2 >= 5) {
       Res1  =  Aleanombre(10 ) ;
       Res2  =  Aleanombre(10 ) ;
       while( Res1 < Res2) {
         Res1  =  Aleanombre(10 ) ;
         Res2  =  Aleanombre(10 ) ;

       } ;

     } ;
     if( Buts1 - Buts2 < 5) {
       if( Buts1 - Buts2 >= 0) {
         Res1  =  Aleanombre(10 ) ;
         Res2  =  Aleanombre(10 ) ;
         while( Res1 != Res2) {
           Res1  =  Aleanombre(10 ) ;
           Res2  =  Aleanombre(10 ) ;

         } ;

       } ;

     } ;
    /*l'equipe2 doit gagner*/
     if( Buts2 - Buts1 >= 5) {
       Res1  =  Aleanombre(10 ) ;
       Res2  =  Aleanombre(10 ) ;
       while( Res2 < Res1) {
         Res1  =  Aleanombre(10 ) ;
         Res2  =  Aleanombre(10 ) ;

       } ;

     } ;
     if( Buts2 - Buts1 < 5) {
       if( Buts2 - Buts1 >= 0) {
         Res1  =  Aleanombre(10 ) ;
         Res2  =  Aleanombre(10 ) ;
         while( Res1 != Res2) {
           Res1  =  Aleanombre(10 ) ;
           Res2  =  Aleanombre(10 ) ;

         } ;

       } ;

     } ;
     S_Sg.Champ1 = Eq1 ;
     S_Sg.Champ2 = Eq2 ;
     S_Sg.Champ3 = Res1 ;
     S_Sg.Champ4 = Res2 ;
     Init_struct_Tiiii ( Sg , S_Sg )  ;
     Aff_info_ATiiii ( P , Sg ) ;
     if( *Ch == 1) {
       Buts1  =  Buts1 + Res1 ;
       Aff_element_V32i ( *Tab_eq_totbuts , Eq1   , Buts1 ) ;
       Buts2  =  Buts2 + Res2 ;
       Aff_element_V32i ( *Tab_eq_totbuts , Eq2   , Buts2 ) ;

     } ;

   } ;
   Ph2_sim_resph12_2 ( & Pi , & *Tab_eq_totbuts , & *Ch ) ;

  }
void Ph2_sim_resph12_2 (Pointeur_PATiiii *Pi , Typevect_V32i *Tab_eq_totbuts , int *Ch)
  {
    /** Variables locales **/
    Pointeur_ATiiii P=NULL;
    Typestr_Tiiii Sg;
    Typestr_Tiiii Sh;
    int Eq1;
    int Eq2;
    int Res1;
    int Res2;
    int Alea;
    int Buts1;
    int Buts2;
    Type_Tiiii S_Sh;

    /** Corps du module **/
   Sg = malloc(sizeof(Type_Tiiii));
   Sh = malloc(sizeof(Type_Tiiii));
   I  =  1 ;
   while( I <= 7) {
     Depiler_PATiiii (& *Pi , &P ) ;
    /* Affectation globale de structure */
     Sg->Champ1 =   Info_ATiiii ( Fd_ATiiii ( P ) )->Champ1;
     Sg->Champ2 =   Info_ATiiii ( Fd_ATiiii ( P ) )->Champ2;
     Sg->Champ3 =   Info_ATiiii ( Fd_ATiiii ( P ) )->Champ3;
     Sg->Champ4 =   Info_ATiiii ( Fd_ATiiii ( P ) )->Champ4;
;
    /* Affectation globale de structure */
     Sh->Champ1 =   Info_ATiiii ( P )->Champ1;
     Sh->Champ2 =   Info_ATiiii ( P )->Champ2;
     Sh->Champ3 =   Info_ATiiii ( P )->Champ3;
     Sh->Champ4 =   Info_ATiiii ( P )->Champ4;
;
     Eq1  =  Struct1_Tiiii ( Sg  ) ;
     Eq2  =  Struct2_Tiiii ( Sg  ) ;
     Buts1  =  Element_V32i ( *Tab_eq_totbuts , Eq1   ) ;
     Buts2  =  Element_V32i ( *Tab_eq_totbuts , Eq2   ) ;
     Res1  =  Struct3_Tiiii ( Sg  ) ;
     Res2  =  Struct4_Tiiii ( Sg  ) ;
    /*l'equipe 1 est gagnante*/
     if( Res1 > Res2) {
       S_Sh.Champ1 = Struct1_Tiiii(Sh) ;
       S_Sh.Champ2 = Struct1_Tiiii(Sg) ;
       S_Sh.Champ3 = 0 ;
       S_Sh.Champ4 = 0 ;
       Init_struct_Tiiii ( Sh , S_Sh )  ;

     } ;
    /*le match est nul, affectuer un tirage au sort*/
     if( Res1 == Res2) {
       Alea  =  Aleanombre(2 ) ;
      /*l'equipe 1 est gagnante*/
       if( Alea == 1) {
         S_Sh.Champ1 = Struct1_Tiiii(Sh) ;
         S_Sh.Champ2 = Struct1_Tiiii(Sg) ;
         S_Sh.Champ3 = 0 ;
         S_Sh.Champ4 = 0 ;
         Init_struct_Tiiii ( Sh , S_Sh )  ;
         }
      /*l'equipe 2 est gagnante*/
       else
         {
         S_Sh.Champ1 = Struct2_Tiiii(Sh) ;
         S_Sh.Champ2 = Struct2_Tiiii(Sg) ;
         S_Sh.Champ3 = 0 ;
         S_Sh.Champ4 = 0 ;
         Init_struct_Tiiii ( Sh , S_Sh )  ;

       } ;

     } ;
    /*l'equipe 2 est gagnante*/
     if( Res1 < Res2) {
       S_Sh.Champ1 = Struct2_Tiiii(Sh) ;
       S_Sh.Champ2 = Struct2_Tiiii(Sg) ;
       S_Sh.Champ3 = 0 ;
       S_Sh.Champ4 = 0 ;
       Init_struct_Tiiii ( Sh , S_Sh )  ;

     } ;
    /* Affectation globale de structure */
     Sg->Champ1 =   Info_ATiiii ( Fg_ATiiii ( P ) )->Champ1;
     Sg->Champ2 =   Info_ATiiii ( Fg_ATiiii ( P ) )->Champ2;
     Sg->Champ3 =   Info_ATiiii ( Fg_ATiiii ( P ) )->Champ3;
     Sg->Champ4 =   Info_ATiiii ( Fg_ATiiii ( P ) )->Champ4;
;
     Res1  =  Struct3_Tiiii ( Sg  ) ;
     Res2  =  Struct4_Tiiii ( Sg  ) ;
    /*l'equipe 1 est gagnante*/
     if( Res1 > Res2) {
       S_Sh.Champ1 = Struct1_Tiiii(Sg) ;
       S_Sh.Champ2 = Struct2_Tiiii(Sh) ;
       S_Sh.Champ3 = 0 ;
       S_Sh.Champ4 = 0 ;
       Init_struct_Tiiii ( Sh , S_Sh )  ;

     } ;
    /*le match est nul, affectuer un tirage au sort*/
     if( Res1 == Res2) {
       Alea  =  Aleanombre(2 ) ;
      /*l'equipe 1 est gagnante*/
       if( Alea == 1) {
         S_Sh.Champ1 = Struct1_Tiiii(Sg) ;
         S_Sh.Champ2 = Struct2_Tiiii(Sh) ;
         S_Sh.Champ3 = 0 ;
         S_Sh.Champ4 = 0 ;
         Init_struct_Tiiii ( Sh , S_Sh )  ;
         }
      /*l'equipe 2 est gagnante*/
       else
         {
         S_Sh.Champ1 = Struct2_Tiiii(Sg) ;
         S_Sh.Champ2 = Struct2_Tiiii(Sh) ;
         S_Sh.Champ3 = 0 ;
         S_Sh.Champ4 = 0 ;
         Init_struct_Tiiii ( Sh , S_Sh )  ;

       } ;

     } ;
    /*l'equipe 2 est gagnante*/
     if( Res1 < Res2) {
       S_Sh.Champ1 = Struct2_Tiiii(Sg) ;
       S_Sh.Champ2 = Struct2_Tiiii(Sh) ;
       S_Sh.Champ3 = 0 ;
       S_Sh.Champ4 = 0 ;
       Init_struct_Tiiii ( Sh , S_Sh )  ;

     } ;
     Eq1  =  Struct1_Tiiii ( Sh  ) ;
     Eq2  =  Struct2_Tiiii ( Sh  ) ;
     Buts1  =  Element_V32i ( *Tab_eq_totbuts , Eq1   ) ;
     Buts2  =  Element_V32i ( *Tab_eq_totbuts , Eq2   ) ;
    /*l'equipe1 doit gagner*/
     if( Buts1 - Buts2 >= 5) {
       Res1  =  Aleanombre(10 ) ;
       Res2  =  Aleanombre(10 ) ;
       while( Res1 < Res2) {
         Res1  =  Aleanombre(10 ) ;
         Res2  =  Aleanombre(10 ) ;

       } ;

     } ;
     if( Buts1 - Buts2 < 5) {
       if( Buts1 - Buts2 >= 0) {
         Res1  =  Aleanombre(10 ) ;
         Res2  =  Aleanombre(10 ) ;
         while( Res1 != Res2) {
           Res1  =  Aleanombre(10 ) ;
           Res2  =  Aleanombre(10 ) ;

         } ;

       } ;

     } ;
    /*l'equipe2 doit gagner*/
     if( Buts2 - Buts1 >= 5) {
       Res1  =  Aleanombre(10 ) ;
       Res2  =  Aleanombre(10 ) ;
       while( Res2 < Res1) {
         Res1  =  Aleanombre(10 ) ;
         Res2  =  Aleanombre(10 ) ;

       } ;

     } ;
     if( Buts2 - Buts1 < 5) {
       if( Buts2 - Buts1 >= 0) {
         Res1  =  Aleanombre(10 ) ;
         Res2  =  Aleanombre(10 ) ;
         while( Res1 != Res2) {
           Res1  =  Aleanombre(10 ) ;
           Res2  =  Aleanombre(10 ) ;

         } ;

       } ;

     } ;
     S_Sh.Champ1 = Eq1 ;
     S_Sh.Champ2 = Eq2 ;
     S_Sh.Champ3 = Res1 ;
     S_Sh.Champ4 = Res2 ;
     Init_struct_Tiiii ( Sh , S_Sh )  ;
     Aff_info_ATiiii ( P , Sh ) ;
     if( *Ch == 1) {
       Buts1  =  Buts1 + Res1 ;
       Aff_element_V32i ( *Tab_eq_totbuts , Eq1   , Buts1 ) ;
       Buts2  =  Buts2 + Res2 ;
       Aff_element_V32i ( *Tab_eq_totbuts , Eq2   , Buts2 ) ;

     } ;
     I  =  I + 1 ;

   } ;

  }
void Ph2_sim_eqfavresph1 (Pointeur_ATiiii *Arb_match , Typevect_V32i *Tab_eq_rep , Typevect_V32i *Tab_eq_totbuts , int *Ch)
  {
    /** Variables locales **/
    Pointeur_PATiiii Pi=NULL;
    Pointeur_ATiiii P=NULL;
    Typestr_Tiiii Sg;
    Typestr_Tiiii Sh;
    int Eq1;
    int Eq2;
    int Res1;
    int Res2;
    int Buts1;
    int Buts2;
    int Rep1;
    int Rep2;
    Type_Tiiii S_Sg;

    /** Corps du module **/
   Sg = malloc(sizeof(Type_Tiiii));
   Sh = malloc(sizeof(Type_Tiiii));
   Parlarginv ( & *Arb_match , & Pi ) ;
   for( I  =  1 ;I <=  8 ; ++I){
     Depiler_PATiiii (& Pi , &P ) ;
    /* Affectation globale de structure */
     Sg->Champ1 =   Info_ATiiii ( P )->Champ1;
     Sg->Champ2 =   Info_ATiiii ( P )->Champ2;
     Sg->Champ3 =   Info_ATiiii ( P )->Champ3;
     Sg->Champ4 =   Info_ATiiii ( P )->Champ4;
;
     Eq1  =  Struct1_Tiiii ( Sg  ) ;
     Eq2  =  Struct2_Tiiii ( Sg  ) ;
     Rep1  =  Element_V32i ( *Tab_eq_rep , Eq1   ) ;
     Rep2  =  Element_V32i ( *Tab_eq_rep , Eq2   ) ;
     Buts1  =  Element_V32i ( *Tab_eq_totbuts , Eq1   ) ;
     Buts2  =  Element_V32i ( *Tab_eq_totbuts , Eq2   ) ;
    /*l'equipe1 doit gagner*/
     if( ( Rep1 - Rep2 >= 5 )) {
       Res1  =  Aleanombre(10 ) ;
       Res2  =  Aleanombre(10 ) ;
       while( Res1 < Res2) {
         Res1  =  Aleanombre(10 ) ;
         Res2  =  Aleanombre(10 ) ;

       } ;

     } ;
     if( Rep1 - Rep2 < 5) {
       if( Rep1 - Rep2 >= 0) {
        /*l'equipe1 doit gagner*/
         if( Buts1 > Buts2) {
           Res1  =  Aleanombre(10 ) ;
           Res2  =  Aleanombre(10 ) ;
           while( Res1 < Res2) {
             Res1  =  Aleanombre(10 ) ;
             Res2  =  Aleanombre(10 ) ;

           } ;

         } ;
         if( Buts1 < Buts2) {
           Res1  =  Aleanombre(10 ) ;
           Res2  =  Aleanombre(10 ) ;
           while( Res2 < Res1) {
             Res1  =  Aleanombre(10 ) ;
             Res2  =  Aleanombre(10 ) ;

           } ;

         } ;
         if( Buts1 == Buts2) {
           Res1  =  Aleanombre(10 ) ;
           Res2  =  Aleanombre(10 ) ;
           while( Res1 != Res2) {
             Res1  =  Aleanombre(10 ) ;
             Res2  =  Aleanombre(10 ) ;

           } ;

         } ;

       } ;

     } ;
    /*l'equipe2 doit gagner*/
     if( Rep2 - Rep1 > 5) {
       Res1  =  Aleanombre(10 ) ;
       Res2  =  Aleanombre(10 ) ;
       while( Res2 < Res1) {
         Res1  =  Aleanombre(10 ) ;
         Res2  =  Aleanombre(10 ) ;

       } ;

     } ;
     if( Rep2 - Rep1 < 5) {
       if( Rep2 - Rep1 >= 0) {
        /*l'equipe1 doit gagner*/
         if( Buts1 > Buts2) {
           Res1  =  Aleanombre(10 ) ;
           Res2  =  Aleanombre(10 ) ;
           while( Res1 < Res2) {
             Res1  =  Aleanombre(10 ) ;
             Res2  =  Aleanombre(10 ) ;

           } ;

         } ;
         if( Buts1 < Buts2) {
           Res1  =  Aleanombre(10 ) ;
           Res2  =  Aleanombre(10 ) ;
           while( Res2 < Res1) {
             Res1  =  Aleanombre(10 ) ;
             Res2  =  Aleanombre(10 ) ;

           } ;

         } ;
         if( Buts1 == Buts2) {
           Res1  =  Aleanombre(10 ) ;
           Res2  =  Aleanombre(10 ) ;
           while( Res1 != Res2) {
             Res1  =  Aleanombre(10 ) ;
             Res2  =  Aleanombre(10 ) ;

           } ;

         } ;

       } ;

     } ;
     S_Sg.Champ1 = Eq1 ;
     S_Sg.Champ2 = Eq2 ;
     S_Sg.Champ3 = Res1 ;
     S_Sg.Champ4 = Res2 ;
     Init_struct_Tiiii ( Sg , S_Sg )  ;
     Aff_info_ATiiii ( P , Sg ) ;
     if( *Ch == 1) {
       Buts1  =  Buts1 + Res1 ;
       Aff_element_V32i ( *Tab_eq_totbuts , Eq1   , Buts1 ) ;
       Buts2  =  Buts2 + Res2 ;
       Aff_element_V32i ( *Tab_eq_totbuts , Eq2   , Buts2 ) ;

     } ;

   } ;
   Ph2sim_eqfavresph12 ( & Pi , & *Tab_eq_rep , & *Tab_eq_totbuts , & *Ch ) ;

  }
void Ph2sim_eqfavresph12 (Pointeur_PATiiii *Pi , Typevect_V32i *Tab_eq_rep , Typevect_V32i *Tab_eq_totbuts , int *Ch)
  {
    /** Variables locales **/
    Pointeur_ATiiii P=NULL;
    Typestr_Tiiii Sg;
    Typestr_Tiiii Sh;
    int Eq1;
    int Eq2;
    int Res1;
    int Res2;
    int Buts1;
    int Buts2;
    int Rep1;
    int Rep2;
    Type_Tiiii S_Sh;

    /** Corps du module **/
   Sg = malloc(sizeof(Type_Tiiii));
   Sh = malloc(sizeof(Type_Tiiii));
   I  =  1 ;
   while( I <= 7) {
     Depiler_PATiiii (& *Pi , &P ) ;
    /* Affectation globale de structure */
     Sg->Champ1 =   Info_ATiiii ( Fd_ATiiii ( P ) )->Champ1;
     Sg->Champ2 =   Info_ATiiii ( Fd_ATiiii ( P ) )->Champ2;
     Sg->Champ3 =   Info_ATiiii ( Fd_ATiiii ( P ) )->Champ3;
     Sg->Champ4 =   Info_ATiiii ( Fd_ATiiii ( P ) )->Champ4;
;
    /* Affectation globale de structure */
     Sh->Champ1 =   Info_ATiiii ( P )->Champ1;
     Sh->Champ2 =   Info_ATiiii ( P )->Champ2;
     Sh->Champ3 =   Info_ATiiii ( P )->Champ3;
     Sh->Champ4 =   Info_ATiiii ( P )->Champ4;
;
     Eq1  =  Struct1_Tiiii ( Sg  ) ;
     Eq2  =  Struct2_Tiiii ( Sg  ) ;
     Res1  =  Struct3_Tiiii ( Sg  ) ;
     Res2  =  Struct4_Tiiii ( Sg  ) ;
    /*l'equipe 1 est gagnante*/
     if( Res1 > Res2) {
       S_Sh.Champ1 = Struct1_Tiiii(Sh) ;
       S_Sh.Champ2 = Struct1_Tiiii(Sg) ;
       S_Sh.Champ3 = 0 ;
       S_Sh.Champ4 = 0 ;
       Init_struct_Tiiii ( Sh , S_Sh )  ;

     } ;
    /*le match est nul, affectuer un tirage au sort*/
     if( Res1 == Res2) {
       Alea  =  Aleanombre(2 ) ;
      /*l'equipe 1 est gagnante*/
       if( Alea == 1) {
         S_Sh.Champ1 = Struct1_Tiiii(Sh) ;
         S_Sh.Champ2 = Struct1_Tiiii(Sg) ;
         S_Sh.Champ3 = 0 ;
         S_Sh.Champ4 = 0 ;
         Init_struct_Tiiii ( Sh , S_Sh )  ;
         }
      /*l'equipe 2 est gagnante*/
       else
         {
         S_Sh.Champ1 = Struct2_Tiiii(Sh) ;
         S_Sh.Champ2 = Struct2_Tiiii(Sg) ;
         S_Sh.Champ3 = 0 ;
         S_Sh.Champ4 = 0 ;
         Init_struct_Tiiii ( Sh , S_Sh )  ;

       } ;

     } ;
    /*l'equipe 2 est gagnante*/
     if( Res1 < Res2) {
       S_Sh.Champ1 = Struct2_Tiiii(Sh) ;
       S_Sh.Champ2 = Struct2_Tiiii(Sg) ;
       S_Sh.Champ3 = 0 ;
       S_Sh.Champ4 = 0 ;
       Init_struct_Tiiii ( Sh , S_Sh )  ;

     } ;
    /* Affectation globale de structure */
     Sg->Champ1 =   Info_ATiiii ( Fg_ATiiii ( P ) )->Champ1;
     Sg->Champ2 =   Info_ATiiii ( Fg_ATiiii ( P ) )->Champ2;
     Sg->Champ3 =   Info_ATiiii ( Fg_ATiiii ( P ) )->Champ3;
     Sg->Champ4 =   Info_ATiiii ( Fg_ATiiii ( P ) )->Champ4;
;
     Res1  =  Struct3_Tiiii ( Sg  ) ;
     Res2  =  Struct4_Tiiii ( Sg  ) ;
    /*l'equipe 1 est gagnante*/
     if( Res1 > Res2) {
       S_Sh.Champ1 = Struct1_Tiiii(Sg) ;
       S_Sh.Champ2 = Struct2_Tiiii(Sh) ;
       S_Sh.Champ3 = 0 ;
       S_Sh.Champ4 = 0 ;
       Init_struct_Tiiii ( Sh , S_Sh )  ;

     } ;
    /*le match est nul, affectuer un tirage au sort*/
     if( Res1 == Res2) {
       Alea  =  Aleanombre(2 ) ;
      /*l'equipe 1 est gagnante*/
       if( Alea == 1) {
         S_Sh.Champ1 = Struct1_Tiiii(Sg) ;
         S_Sh.Champ2 = Struct2_Tiiii(Sh) ;
         S_Sh.Champ3 = 0 ;
         S_Sh.Champ4 = 0 ;
         Init_struct_Tiiii ( Sh , S_Sh )  ;
         }
      /*l'equipe 2 est gagnante*/
       else
         {
         S_Sh.Champ1 = Struct2_Tiiii(Sg) ;
         S_Sh.Champ2 = Struct2_Tiiii(Sh) ;
         S_Sh.Champ3 = 0 ;
         S_Sh.Champ4 = 0 ;
         Init_struct_Tiiii ( Sh , S_Sh )  ;

       } ;

     } ;
    /*l'equipe 2 est gagnante*/
     if( Res1 < Res2) {
       S_Sh.Champ1 = Struct2_Tiiii(Sg) ;
       S_Sh.Champ2 = Struct2_Tiiii(Sh) ;
       S_Sh.Champ3 = 0 ;
       S_Sh.Champ4 = 0 ;
       Init_struct_Tiiii ( Sh , S_Sh )  ;

     } ;
     Eqfavresph12 ( & Sh , & *Tab_eq_rep , & *Tab_eq_totbuts , & *Ch ) ;
     Aff_info_ATiiii ( P , Sh ) ;
     I  =  I + 1 ;

   } ;

  }
void Eqfavresph12 (Typestr_Tiiii *Sh , Typevect_V32i *Tab_eq_rep , Typevect_V32i *Tab_eq_totbuts , int *Ch)
  {
    /** Variables locales **/
    int Eq1;
    int Eq2;
    int Res1;
    int Res2;
    int Buts1;
    int Buts2;
    int Rep1;
    int Rep2;
    Type_Tiiii S_Sh;

    /** Corps du module **/
   Eq1  =  Struct1_Tiiii ( *Sh  ) ;
   Eq2  =  Struct2_Tiiii ( *Sh  ) ;
   Rep1  =  Element_V32i ( *Tab_eq_rep , Eq1   ) ;
   Rep2  =  Element_V32i ( *Tab_eq_rep , Eq2   ) ;
   Buts1  =  Element_V32i ( *Tab_eq_totbuts , Eq1   ) ;
   Buts2  =  Element_V32i ( *Tab_eq_totbuts , Eq2   ) ;
  /*l'equipe1 doit gagner*/
   if( ( Rep1 - Rep2 >= 5 )) {
     Res1  =  Aleanombre(10 ) ;
     Res2  =  Aleanombre(10 ) ;
     while( Res1 < Res2) {
       Res1  =  Aleanombre(10 ) ;
       Res2  =  Aleanombre(10 ) ;

     } ;

   } ;
   if( Rep1 - Rep2 < 5) {
     if( Rep1 - Rep2 >= 0) {
      /*l'equipe1 doit gagner*/
       if( Buts1 > Buts2) {
         Res1  =  Aleanombre(10 ) ;
         Res2  =  Aleanombre(10 ) ;
         while( Res1 < Res2) {
           Res1  =  Aleanombre(10 ) ;
           Res2  =  Aleanombre(10 ) ;

         } ;

       } ;
       if( Buts1 < Buts2) {
         Res1  =  Aleanombre(10 ) ;
         Res2  =  Aleanombre(10 ) ;
         while( Res2 < Res1) {
           Res1  =  Aleanombre(10 ) ;
           Res2  =  Aleanombre(10 ) ;

         } ;

       } ;
       if( Buts1 == Buts2) {
         Res1  =  Aleanombre(10 ) ;
         Res2  =  Aleanombre(10 ) ;
         while( Res1 != Res2) {
           Res1  =  Aleanombre(10 ) ;
           Res2  =  Aleanombre(10 ) ;

         } ;

       } ;

     } ;

   } ;
  /*l'equipe2 doit gagner*/
   if( Rep2 - Rep1 > 5) {
     Res1  =  Aleanombre(10 ) ;
     Res2  =  Aleanombre(10 ) ;
     while( Res2 < Res1) {
       Res1  =  Aleanombre(10 ) ;
       Res2  =  Aleanombre(10 ) ;

     } ;

   } ;
   if( Rep2 - Rep1 < 5) {
     if( Rep2 - Rep1 >= 0) {
      /*l'equipe1 doit gagner*/
       if( Buts1 > Buts2) {
         Res1  =  Aleanombre(10 ) ;
         Res2  =  Aleanombre(10 ) ;
         while( Res1 < Res2) {
           Res1  =  Aleanombre(10 ) ;
           Res2  =  Aleanombre(10 ) ;

         } ;

       } ;
       if( Buts1 < Buts2) {
         Res1  =  Aleanombre(10 ) ;
         Res2  =  Aleanombre(10 ) ;
         while( Res2 < Res1) {
           Res1  =  Aleanombre(10 ) ;
           Res2  =  Aleanombre(10 ) ;

         } ;

       } ;
       if( Buts1 == Buts2) {
         Res1  =  Aleanombre(10 ) ;
         Res2  =  Aleanombre(10 ) ;
         while( Res1 != Res2) {
           Res1  =  Aleanombre(10 ) ;
           Res2  =  Aleanombre(10 ) ;

         } ;

       } ;

     } ;

   } ;
   S_Sh.Champ1 = Eq1 ;
   S_Sh.Champ2 = Eq2 ;
   S_Sh.Champ3 = Res1 ;
   S_Sh.Champ4 = Res2 ;
   Init_struct_Tiiii ( *Sh , S_Sh )  ;
   if( *Ch == 1) {
     Buts1  =  Buts1 + Res1 ;
     Aff_element_V32i ( *Tab_eq_totbuts , Eq1   , Buts1 ) ;
     Buts2  =  Buts2 + Res2 ;
     Aff_element_V32i ( *Tab_eq_totbuts , Eq2   , Buts2 ) ;

   } ;

  }
void Eqgafnfin (Pointeur_ATiiii *Arb_match , int *Eqg)
  {
    /** Variables locales **/
    Typestr_Tiiii Sg;
    int Alea;

    /** Corps du module **/
   Sg = malloc(sizeof(Type_Tiiii));
    /* Affectation globale de structure */
   Sg->Champ1 =   Info_ATiiii ( *Arb_match )->Champ1;
   Sg->Champ2 =   Info_ATiiii ( *Arb_match )->Champ2;
   Sg->Champ3 =   Info_ATiiii ( *Arb_match )->Champ3;
   Sg->Champ4 =   Info_ATiiii ( *Arb_match )->Champ4;
;
  /*l'equipe 1 est gagnante*/
   if( Struct3_Tiiii ( Sg  ) > Struct4_Tiiii ( Sg  )) {
     *Eqg  =  Struct1_Tiiii ( Sg  ) ;

   } ;
   if( Struct3_Tiiii ( Sg  ) < Struct4_Tiiii ( Sg  )) {
     *Eqg  =  Struct2_Tiiii ( Sg  ) ;

   } ;
  /*le match est nul, affectuer un tirage au sort*/
   if( Struct3_Tiiii ( Sg  ) == Struct4_Tiiii ( Sg  )) {
     Alea  =  Aleanombre(2 ) ;
    /*l'equipe 1 est gagnante*/
     if( Alea == 1) {
       *Eqg  =  Struct1_Tiiii ( Sg  ) ;
       }
    /*l'equipe 2 est gagnante*/
     else
       {
       *Eqg  =  Struct2_Tiiii ( Sg  ) ;

     } ;

   } ;

  }
void Creer_tabeqnom (Typevect_V32s *Tab_eq_nom)
  {

    /** Corps du module **/
   Aff_element_V32s ( *Tab_eq_nom , 1   , "QAT" ) ;
   Aff_element_V32s ( *Tab_eq_nom , 2   , "ECU" ) ;
   Aff_element_V32s ( *Tab_eq_nom , 3   , "SNG" ) ;
   Aff_element_V32s ( *Tab_eq_nom , 4   , "NLD" ) ;
   Aff_element_V32s ( *Tab_eq_nom , 5   , "ENG" ) ;
   Aff_element_V32s ( *Tab_eq_nom , 6   , "IRN" ) ;
   Aff_element_V32s ( *Tab_eq_nom , 7   , "USA" ) ;
   Aff_element_V32s ( *Tab_eq_nom , 8   , "WAL" ) ;
   Aff_element_V32s ( *Tab_eq_nom , 9   , "ARG" ) ;
   Aff_element_V32s ( *Tab_eq_nom , 10   , "SAU" ) ;
   Aff_element_V32s ( *Tab_eq_nom , 11   , "MXO" ) ;
   Aff_element_V32s ( *Tab_eq_nom , 12   , "POL" ) ;
   Aff_element_V32s ( *Tab_eq_nom , 13   , "FRA" ) ;
   Aff_element_V32s ( *Tab_eq_nom , 14   , "DAN" ) ;
   Aff_element_V32s ( *Tab_eq_nom , 15   , "TUN" ) ;
   Aff_element_V32s ( *Tab_eq_nom , 16   , "UKR" ) ;
   Aff_element_V32s ( *Tab_eq_nom , 17   , "ESP" ) ;
   Aff_element_V32s ( *Tab_eq_nom , 18   , "GER" ) ;
   Aff_element_V32s ( *Tab_eq_nom , 19   , "JAP" ) ;
   Aff_element_V32s ( *Tab_eq_nom , 20   , "AUS" ) ;
   Aff_element_V32s ( *Tab_eq_nom , 21   , "BEL" ) ;
   Aff_element_V32s ( *Tab_eq_nom , 22   , "CAN" ) ;
   Aff_element_V32s ( *Tab_eq_nom , 23   , "MAR" ) ;
   Aff_element_V32s ( *Tab_eq_nom , 24   , "HRV" ) ;
   Aff_element_V32s ( *Tab_eq_nom , 25   , "BRA" ) ;
   Aff_element_V32s ( *Tab_eq_nom , 26   , "SRB" ) ;
   Aff_element_V32s ( *Tab_eq_nom , 27   , "CHE" ) ;
   Aff_element_V32s ( *Tab_eq_nom , 28   , "CMR" ) ;
   Aff_element_V32s ( *Tab_eq_nom , 29   , "PRT" ) ;
   Aff_element_V32s ( *Tab_eq_nom , 30   , "GHA" ) ;
   Aff_element_V32s ( *Tab_eq_nom , 31   , "URY" ) ;
   Aff_element_V32s ( *Tab_eq_nom , 32   , "KOR" ) ;

  }
void Ideq (string255 *Nomeq , int *Id , Typevect_V32s *Tab_eq_nom)
  {

    /** Corps du module **/
   *Id  =  1 ;
   while(strcmp( *Nomeq, Element_V32s ( *Tab_eq_nom , *Id   )) != 0 ) {
     *Id  =  *Id + 1 ;

   } ;

  }
  void Affichage_phase1 (Typevect_V8LTiiii *Tab_grpmatch , Typevect_V32s *Tab_eq_nom , Typevect_V32i *Tab_eq_pts)
    {
      /** Variables locales **/
      Pointeur_LTiiii P=NULL;
      Typevect_V4i T;
      Typestr_Tiiii Sg;
      int I;
      int J;
      int K;
      int L;
      int Pos;
      int Pts;
      int Maxi;
      string255 Eq1;
      string255 Eq2;
      string255 Eq;

      /** Corps du module **/
     T = malloc(4 * sizeof(int));
     Sg = malloc(sizeof(Type_Tiiii));
     Eq1 = malloc(255 * sizeof(char));
     Eq2 = malloc(255 * sizeof(char));
     Eq = malloc(255 * sizeof(char));
     printf("%s", "Les rencontres de FIFA2022");
     for( I  =  1 ;I <=  8 ; ++I){
       P  =  Element_V8LTiiii ( *Tab_grpmatch , I   ) ;
       printf ( "\n %s", "#======================Groupe" );
       printf ( " %d", I );
       printf ( " %s", "======================#" ) ;
       while( P != NULL) {
      /* Affectation globale de structure */
         Sg->Champ1 =   Valeur_LTiiii ( P )->Champ1;
         Sg->Champ2 =   Valeur_LTiiii ( P )->Champ2;
         Sg->Champ3 =   Valeur_LTiiii ( P )->Champ3;
         Sg->Champ4 =   Valeur_LTiiii ( P )->Champ4;
  ;
         strcpy (Eq1,   Element_V32s ( *Tab_eq_nom , Struct1_Tiiii ( Sg  )   )) ;
         strcpy (Eq2,   Element_V32s ( *Tab_eq_nom , Struct2_Tiiii ( Sg  )   )) ;
         printf ( "\n %25s", Eq1 );
         printf ( " %d", Struct3_Tiiii(Sg) );
         printf("%s", "-");
         printf ( "%d", Struct4_Tiiii(Sg) );
         printf ( " %2s\n", Eq2 );
         P  =  Suivant_LTiiii ( P ) ;

       } ;

     } ;
     printf("\n%25s", "Le classement des equipes par groupe" );
     for( I  =  1 ;I <=  8 ; ++I){
       printf ( " \n%s", "#======================Groupe" );
       printf ( " %d", I );
       printf ( " %s", "======================#" ) ;
       K  =  ( I - 1 ) * 3 + I ;
       J  =  K ;
       L  =  1 ;
       while( J <= K + 3) {
         Pts  =  Element_V32i ( *Tab_eq_pts , J   ) ;
         Aff_element_V4i ( T , L   , Pts ) ;
         J  =  J + 1 ;
         L  =  L + 1 ;

       } ;
       Pos  =  1 ;
       Maxi  =  0 ;
       for( L  =  1 ;L <=  4 ; ++L){
         Pts  =  Element_V4i ( T , L   ) ;
         if( Pts > Maxi) {
           Maxi  =  Pts ;
           Pos  =  L ;

         } ;

       } ;
       Pos  =  K + Pos - 1 ;
       strcpy (Eq,   Element_V32s ( *Tab_eq_nom , Pos   )) ;
       printf ( "\n%25s", Eq );
       printf ( " %s", "   " );
       printf ( " %2d\n", Maxi ) ;
       Aff_element_V4i ( T , Pos - K + 1   , 0 ) ;
       Pos  =  1 ;
       Maxi  =  0 ;
       for( L  =  1 ;L <=  4 ; ++L){
         Pts  =  Element_V4i ( T , L   ) ;
         if( Pts > Maxi) {
           Maxi  =  Pts ;
           Pos  =  L ;

         } ;

       } ;
       Pos  =  K + Pos - 1 ;
       strcpy (Eq,   Element_V32s ( *Tab_eq_nom , Pos   )) ;
       printf ( "\n%25s", Eq );
       printf ( " %s", "   " );
       printf ( " %2d\n", Maxi ) ;
       Aff_element_V4i ( T , Pos - K + 1   , 0 ) ;
       Pos  =  1 ;
       Maxi  =  0 ;
       for( L  =  1 ;L <=  4 ; ++L){
         Pts  =  Element_V4i ( T , L   ) ;
         if( Pts > Maxi) {
           Maxi  =  Pts ;
           Pos  =  L ;

         } ;

       } ;
       Pos  =  K + Pos - 1 ;
       strcpy (Eq,   Element_V32s ( *Tab_eq_nom , Pos   )) ;
       printf ( "\n%25s", Eq );
       printf ( " %s", "   " );
       printf ( " %2d\n", Maxi ) ;
       Aff_element_V4i ( T , Pos - K + 1   , 0 ) ;
       Pos  =  1 ;
       Maxi  =  0 ;
       for( L  =  1 ;L <=  4 ; ++L){
         Pts  =  Element_V4i ( T , L   ) ;
         if( Pts > Maxi) {
           Maxi  =  Pts ;
           Pos  =  L ;

         } ;

       } ;
       Pos  =  K + Pos - 1 ;
       strcpy (Eq,   Element_V32s ( *Tab_eq_nom , Pos   )) ;
       printf ( "\n%25s", Eq );
       printf ( " %s", "   " );
       printf ( " %2d\n", Maxi ) ;

     } ;

    }
    void Affichage_phase2 (Pointeur_ATiiii *Arb_match , Typevect_V32s *Tab_eq_nom)
        {
          /** Variables locales **/
          Pointeur_PATiiii Pi=NULL;
          Pointeur_ATiiii P=NULL;
          Typestr_Tiiii Sg;
          string255 Eq1;
          string255 Eq2;
          int I;

          /** Corps du module **/
         Sg = malloc(sizeof(Type_Tiiii));
         Eq1 = malloc(255 * sizeof(char));
         Eq2 = malloc(255 * sizeof(char));
         Parlarginv ( & *Arb_match , & Pi ) ;
         for( I  =  1 ;I <=  8 ; ++I){
           Depiler_PATiiii (& Pi , &P ) ;
          /* Affectation globale de structure */
           Sg->Champ1 =   Info_ATiiii ( P )->Champ1;
           Sg->Champ2 =   Info_ATiiii ( P )->Champ2;
           Sg->Champ3 =   Info_ATiiii ( P )->Champ3;
           Sg->Champ4 =   Info_ATiiii ( P )->Champ4;
     ;
           strcpy (Eq1,   Element_V32s ( *Tab_eq_nom , Struct1_Tiiii ( Sg  )   )) ;
           strcpy (Eq2,   Element_V32s ( *Tab_eq_nom , Struct2_Tiiii ( Sg  )   )) ;

           if(I==1){
              printf ( "%15s", Eq1 );
           }else{
             if (Mod(I,2)!=0){
               printf ( " %8s", Eq1 );
             }else{
               printf ( " %8s", Eq1 );
             }

           }

           printf ( " %d", Struct3_Tiiii(Sg) );
           printf("-");
           printf ( "%d", Struct4_Tiiii(Sg) );
           if(I==8){
              printf ( "%s\n", Eq2 ) ;
           }else{
           printf ( " %s", Eq2 ) ;

         }

       } ;



              printf("%19s %15s %17s %13s %17s %14s %18s %14s\n", "|", "|", "|", "|", "|", "|", "|", "|");
              printf("%19s %15s %17s %13s %17s %14s %18s %14s\n", "|", "|", "|", "|", "|", "|", "|", "|");
              printf(" %33s %31s %32s %33s\n", "---------------", "-------------", "--------------", "--------------");
              printf("%26s %33s %32s %33s\n", "|","|", "|", "|");
              printf("%26s %33s %32s %33s\n", "|","|", "|", "|");
         for( I  =  1 ;I <=  4 ; ++I){
           Depiler_PATiiii (& Pi , &P ) ;
          /* Affectation globale de structure */
           Sg->Champ1 =   Info_ATiiii ( P )->Champ1;
           Sg->Champ2 =   Info_ATiiii ( P )->Champ2;
           Sg->Champ3 =   Info_ATiiii ( P )->Champ3;
           Sg->Champ4 =   Info_ATiiii ( P )->Champ4;
     ;

           strcpy (Eq1,   Element_V32s ( *Tab_eq_nom , Struct1_Tiiii ( Sg  )   )) ;
           strcpy (Eq2,   Element_V32s ( *Tab_eq_nom , Struct2_Tiiii ( Sg  )   )) ;
           switch(I){
             case 1:printf ( "%22s", Eq1 ); break;
             case 2:printf ( "%26s", Eq1 ); break;
             default : printf ( "%25s", Eq1 ); break;
           }
           printf ( " %d", Struct3_Tiiii(Sg) );
           printf("-");
           printf ( "%d", Struct4_Tiiii(Sg) );
           printf ( " %s", Eq2 ) ;

         } ;
         printf("\n%26s %33s %32s %33s \n", "|", "|", "|", "|");
         printf("%26s %33s %32s %33s \n", "|", "|", "|", "|");
         printf("%59s %66s\n", "---------------------------------", "---------------------------------");
         printf("%41s %67s", "|","|");
         printf("\n");
         for( I  =  1 ;I <=  2 ; ++I){
           Depiler_PATiiii (& Pi , &P ) ;
          /* Affectation globale de structure */
           Sg->Champ1 =   Info_ATiiii ( P )->Champ1;
           Sg->Champ2 =   Info_ATiiii ( P )->Champ2;
           Sg->Champ3 =   Info_ATiiii ( P )->Champ3;
           Sg->Champ4 =   Info_ATiiii ( P )->Champ4;
     ;
           strcpy (Eq1,   Element_V32s ( *Tab_eq_nom , Struct1_Tiiii ( Sg  )   )) ;
           strcpy (Eq2,   Element_V32s ( *Tab_eq_nom , Struct2_Tiiii ( Sg  )   )) ;
           if(I==1){
             printf ( "%38s", Eq1 );
             printf ( " %d", Struct3_Tiiii(Sg) );
             printf("-");
             printf ( "%d", Struct4_Tiiii(Sg) );
             printf ( " %s", Eq2 ) ;
           }else{
             printf ( "%60s", Eq1 );
             printf ( " %d", Struct3_Tiiii(Sg) );
             printf("-");
             printf ( "%d", Struct4_Tiiii(Sg) );
             printf ( " %s", Eq2 ) ;
           }


         } ;
         printf("\n%41s %67s \n", "|", "|");
         printf("%41s %67s \n", "|", "|");
         printf("%108s \n", "-------------------------------------------------------------------");
         printf("%74s\n", "|");
         printf("%74s\n", "|");
         Depiler_PATiiii (& Pi , &P ) ;
          /* Affectation globale de structure */
         Sg->Champ1 =   Info_ATiiii ( P )->Champ1;
         Sg->Champ2 =   Info_ATiiii ( P )->Champ2;
         Sg->Champ3 =   Info_ATiiii ( P )->Champ3;
         Sg->Champ4 =   Info_ATiiii ( P )->Champ4;
     ;
         strcpy (Eq1,   Element_V32s ( *Tab_eq_nom , Struct1_Tiiii ( Sg  )   )) ;
         strcpy (Eq2,   Element_V32s ( *Tab_eq_nom , Struct2_Tiiii ( Sg  )   )) ;
         printf ( "%70s", Eq1 );
         printf ( " %d", Struct3_Tiiii(Sg) );
         printf("-");
         printf ( "%d", Struct4_Tiiii(Sg) );
         printf ( " %s", Eq2 ) ;
         printf("\n");
        }

  int main(int argc, char *argv[])
    {
      Tab_groupes = malloc(8 * sizeof(Typestr_Tiiii));
    int _Izw2;for (_Izw2=0; _Izw2<8; ++_Izw2)
      Tab_groupes[_Izw2] = malloc( sizeof(Type_Tiiii ));
    Sg = malloc(sizeof(Type_Tiiii));
    Sh = malloc(sizeof(Type_Tiiii));
    Tab_grpmatch = malloc(8 * sizeof(Pointeur_LTiiii));
    int _Izw3;for (_Izw3=0; _Izw3<8; ++_Izw3)
      Tab_grpmatch[_Izw3] = malloc( sizeof(Pointeur_LTiiii ));
    Tab_eq_nom = malloc(32 * 255  * sizeof(char));
    int _Izw4;for (_Izw4=0; _Izw4<32; ++_Izw4)
      Tab_eq_nom[_Izw4]= malloc(255 * sizeof(char));
    Tab_eq_totbuts = malloc(32 * sizeof(int));
    Tab_eq_pts = malloc(32 * sizeof(int));
    Tab_eq_rep = malloc(32 * sizeof(int));
    Nomeq = malloc(255 * sizeof(char));
    Tab_grp_cls1 = malloc(8 * sizeof(int));
    Tab_grp_cls2 = malloc(8 * sizeof(int));
    Tab_phase2 = malloc(15 * sizeof(Typestr_Tiiii));
    int _Izw5;for (_Izw5=0; _Izw5<15; ++_Izw5)
      Tab_phase2[_Izw5] = malloc( sizeof(Type_Tiiii ));
    Eqgagnante = malloc(255 * sizeof(char));
    Creer_tabgrp ( & Tab_groupes ) ;
    Creer_tabgrpmatch ( & Tab_grpmatch ) ;
    Init_tabeq ( & Tab_eq_pts ) ;
    Creer_tab_rep ( & Tab_eq_rep ) ;
    Creer_tabeqnom ( & Tab_eq_nom ) ;
   /*Exemple d'une simulation par hasard*/
   int _Px1, _Px2, _Px3, _Px4;
   printf("         _______       ________        ________          \n");
printf("        /______/      /_______/       /___ ___/                                                                          \n");
printf("       //            //                  //                                                                                    \n");
printf("      //____        //                  //                                                                                           \n");
printf("     /_____/        ((_____            //            ~~ TP ALGORITHMIQUE ET STRUCTURE DES DONNEES DYNAMIQUES ~~   \n");
printf("    //                      )         //                   \n");
printf("   //                      //        //                   \n");
printf("  //_____          ______ //     ___//___                               \n");
printf("  | _____/        /______//     /_______/                                \n");
printf("\n \n");
printf("                         ######       ###########    ##########   ###########    ########          ######       ######    \n");
printf("                        #      #      ##                 ##       ##            ##      ##        ##    ##     ##    ##    \n");
printf("                        ##    ##      ##                 ##       ##            ##      ##             ##           ## \n");
printf("                         #   ##       ##                 ##       ##            ##      ##            ##           ##  \n");
printf("                          # ##        #########          ##       #########     ##########           ##           ##       \n");
printf("                           ##         ##                 ##       ##            ##      ##          ##           ##       \n");
printf("                          ## ##       ##                 ##       ##            ##      ##         ##           ##     \n");
printf("                          ##  ##      ##                 ##       ##            ##      ##        ##           ##         \n");
printf("                           ## #       ##             ##########   ##            ##      ##        #########    #########         \n");
printf("\n\t\t\tRealise par: Attia Oussama Abderraouf et Hammadouche Manar");

   int choix=0;
     printf("\n\n\n\n\tSimulation de la phase 1 selon une critere: ");
     printf("\n\t%s","Les criteres de simulation:");
     printf("\n\t\t\t%s","1-Selon le hasard.");
     printf("\n\t\t\t%s","2-selon l'equipe favorite (choisie selon un classement predefini).");
     printf("\n\t\t\t%s","3-Selon le hasard et l'equipe favorite.");
     printf("\n\t\t\t%s","4-Selon une equipe choisie.");
     printf("\n\t\t\t%s","5-Selon un max score defini.");
     printf("\n\t%s", "-->Entrez votre choix:  ");
     scanf("%d",&choix);
     switch(choix){
       case 1: Sim_hasard ( & Tab_grpmatch , & Tab_eq_pts ) ; break;
       case 2: Sim_eqfav ( & Tab_grpmatch , & Tab_eq_pts , & Tab_eq_rep ) ; break;

        case 3: Sim_eqfav_has ( & Tab_grpmatch , & Tab_eq_rep , & Tab_eq_pts ) ; break;
        case 4: printf("Donnez le nom de l'equipe (En 3 lettres majuscules): ");  scanf ( " %[^\n]", Nomeq ) ;
        Ideq ( & Nomeq , & Id , & Tab_eq_nom );
         Sim_eqch ( & Tab_grpmatch , & Tab_eq_pts , & Id ) ;
                break;
        case 5: printf("Donnez le max score(0..9) : "); scanf("%d", &Maxsc); Sim_maxsc ( & Tab_grpmatch , & Tab_eq_pts , & Maxsc ) ; break;
        default: printf("Ressayez de nouveaux");
     }
     if ((choix<6) && (choix>0)){
       Class_eq ( & Tab_eq_pts , & Tab_grp_cls1 , & Tab_grp_cls2 ) ;
     Affichage_phase1 ( & Tab_grpmatch , & Tab_eq_nom , & Tab_eq_pts ) ;
   }



    Creer_tab_phase2 ( & Tab_phase2 , & Tab_grp_cls1 , & Tab_grp_cls2 ) ;
    _Px1 =  1 ;
    _Px2 =  16 ;
    Arb_match  =  Creer_arb_match ( & Tab_phase2 , & Arb_match , &_Px1, &_Px2) ;
    int choix2 ;
    printf("\n\n\n\n\tSimulation de la phase 2 selon une critere: ");
    printf("\n\t%s","Les criteres de simulation:");
    printf("\n\t\t\t%s","1-Selon le hasard.");
    printf("\n\t\t\t%s","2-selon l'equipe favorite (choisie selon un classement predefini).");
    printf("\n\t\t\t%s","3-Selon les resultats de la phase1.");
    printf("\n\t\t\t%s","4-Selon les resultats de la phase1 et la phase2.");
    printf("\n\t\t\t%s","5-selon l'equipe favorite et les resultats de la phase1.");
    printf("\n\t\t\t%s","6-selon l'equipe favorite et les resultats de la phase1 et la phase2.");
    printf("\n\t%s", "-->Entrez votre choix:  ");
    scanf("%d",&choix2);
    switch (choix2){
      case 1: Ph2_sim_hasard ( & Arb_match ) ; break;

      case 2: Ph2_sim_eqfav ( & Arb_match , & Tab_phase2 , & Tab_eq_rep ) ; break;

      case 3:  _Px1 =  0 ;
              Ph2_sim_resph12 ( & Arb_match , & Tab_eq_totbuts , &_Px1) ; break;

      case 4:  _Px2 =  1 ;
              Ph2_sim_resph12 ( & Arb_match , & Tab_eq_totbuts , &_Px2) ; break;

      case 5: _Px3 =  0 ;
              Ph2_sim_eqfavresph1 ( & Arb_match , & Tab_eq_rep , & Tab_eq_totbuts , &_Px3) ; break;

      case 6: _Px4 =  1 ;
              Ph2_sim_eqfavresph1 ( & Arb_match , & Tab_eq_rep , & Tab_eq_totbuts , &_Px4) ; break;

      default: printf("Ressayez de nouveaux");
    }
    if ((choix2<7) && (choix2>0)){
        Affichage_phase2 ( & Arb_match , & Tab_eq_nom ) ;
    }



     system("PAUSE");
     return 0;
    }
