
   SOIENT
       Tab_groupes UN VECTEUR ( 8 ) DE ( ENTIER , ENTIER , ENTIER , ENTIER ) ;
       /* entier; id de chaque equipe*/
       Sg, sh UNE STRUCTURE ( ENTIER , ENTIER , ENTIER , ENTIER ) ;
       Tab_grpmatch UN VECTEUR ( 8 ) DE LISTE DE ( ENTIER , ENTIER , ENTIER , ENTIER ) ;
       tab_eq_nom un vecteur(32) de chaine;
       tab_eq_totbuts un vecteur (32) de entier;
       P UN POINTEUR VERS UNE LISTE DE ( ENTIER , ENTIER , ENTIER , ENTIER ) ;
       Tab_eq_pts UN VECTEUR ( 32 ) DE ENTIER ;
       tab_eq_rep un vecteur(32) de entier;
       nomeq une chaine;
       id un entier;
       Tab_grp_cls1 UN VECTEUR ( 8 ) DE ENTIER ;
       Tab_grp_cls2 UN VECTEUR ( 8 ) DE ENTIER ;
       arb_match un arb de (entier, entier, entier, entier);
       pi une pile de arb de (entier, entier, entier, entier);
       tab_phase2 un vecteur(15) de (entier, entier, entier, entier);
       I , K , J UN ENTIER ;
       eqfav un entier;
       maxsc un entier;
       {les procedures de la phase1}
       Creer_tabgrp UN ACTION ;
       creer_tabeqnom un action;
       Creer_tabgrpmatch UN ACTION ;
       creer_tab_rep un action;
       ideq un action;
       eq_gagn un action;
       Init_tabeq UN ACTION ;
       Sim_hasard UN ACTION ;
       sim_eqfav un action;
       Sim_eqfav_has un action;
       sim_eqch un action;
       sim_maxsc un action;
       Class_eq UN ACTION ;
       affichage un action;
       affichage_phase1 un action;
       res1, res2, rep1,rep2, eq1,eq2, alea un entier;
       {les procedures de la phase2}
       creer_tab_phase2 un action;
       creer_arb_match une fonction(arb de (entier, entier, entier, entier) );
       inordre un action;
       parcourenlargeur un action;
       parlarginv un action;
       ph2_sim_hasard un action;
       ph2_sim_eqfav un action;
       affichage_arb un action;
       ph2_sim_eqfav2 un action;
       creer_tabtotbuts un action ;
       ph2_sim_resph12 un action;
       ph2_sim_resph12_2 un action;
       ph2_sim_eqfavresph1 un action;
       ph2sim_eqfavresph12 un action;
       eqfavresph12 un action;
       ch, eqg un entier;
       eqgafnfin un action;
       eqgagnante une chaine;
       affichage_phase2 un action;
   DEBUT
       APPEL Creer_tabgrp ( Tab_groupes ) ;
       APPEL Creer_tabgrpmatch ( Tab_grpmatch ) ;
       APPEL Init_tabeq ( Tab_eq_pts ) ;
       appel creer_tab_rep(tab_eq_rep);
       appel creer_tabeqnom(tab_eq_nom);
       /*Exemple d'une simulation par hasard*/
       appel sim_hasard(tab_grpmatch, tab_eq_pts);
       appel class_eq(Tab_eq_pts , Tab_grp_cls1 , Tab_grp_cls2 ) ;
       appel affichage_phase1(tab_grpmatch, tab_eq_nom, tab_eq_pts );
       appel creer_tab_phase2(tab_phase2, tab_grp_cls1, tab_grp_cls2);
       arb_match:= creer_arb_match(tab_phase2, arb_match, 1, 16);
       appel ph2_sim_hasard(arb_match);
       appel affichage_phase2(arb_match, tab_eq_nom);

   FIN
   ACTION Creer_tabgrp ( Tab_groupes )
   SOIENT
       Tab_groupes UN VECTEUR ( 8 ) DE ( ENTIER , ENTIER , ENTIER , ENTIER ) ;
       I , K UN ENTIER ;
       Sg UNE STRUCTURE ( ENTIER , ENTIER , ENTIER , ENTIER ) ;

   DEBUT
       K := 1 ;
       POUR I := 1 , 8
           INIT_STRUCT ( Sg , [ K , K + 1 , K + 2 , K + 3 ] ) ;
           AFF_ELEMENT ( Tab_groupes [ I ] , Sg ) ;
           K := K + 4 ;

       FINPOUR ;

   FIN
   ACTION Creer_tabgrpmatch ( Tab_grpmatch )
   SOIENT
       Tab_grpmatch UN VECTEUR ( 8 ) DE LISTE DE ( ENTIER , ENTIER , ENTIER , ENTIER ) ;
       Lm UNE LISTE DE ( ENTIER , ENTIER , ENTIER , ENTIER ) ;
       Sgm UNE LISTE DE ( ENTIER , ENTIER , ENTIER , ENTIER ) ;
       P UN POINTEUR VERS UNE LISTE DE ( ENTIER , ENTIER , ENTIER , ENTIER ) ;

   DEBUT
       POUR I := 1 , 8
           Sg := ELEMENT ( Tab_groupes [ I ] ) ;
           Lm := NIL ;
           POUR J := STRUCT ( Sg , 1 ) , STRUCT ( Sg , 3 )
               POUR K := J + 1 , STRUCT ( Sg , 4 )
                   ALLOUER ( Sgm ) ;
                   CREER_LISTE ( Sgm , [ [ J , K , 0 , 0 ] ] ) ;
                   P := Lm ;
                   SI P = NIL
                       Lm := Sgm ;

                   SINON
                       TQ SUIVANT ( P ) <> NIL
                           P := SUIVANT ( P ) ;

                       FTQ ;
                       AFF_ADR ( P , Sgm ) ;

                   FINSI ;
                   Sgm := NIL ;

               FINPOUR ;

           FINPOUR ;
           AFF_ELEMENT ( Tab_grpmatch [ I ] , Lm ) ;

       FINPOUR ;

   FIN
   ACTION Sim_hasard ( Tab_grpmatch , Tab_eq_pts )
   SOIENT
       Tab_grpmatch UN VECTEUR ( 8 ) DE LISTE DE ( ENTIER , ENTIER , ENTIER , ENTIER ) ;
       Tab_eq_pts UN VECTEUR ( 32 ) DE ENTIER ;
       P UN POINTEUR VERS UNE LISTE DE ( ENTIER , ENTIER , ENTIER , ENTIER ) ;
       S UNE STRUCTURE ( ENTIER , ENTIER , ENTIER , ENTIER ) ;
       I UN ENTIER ;
       Eq1 , Eq2 : ENTIER ;
       Res1 , Res2 : ENTIER ;
       Pts : ENTIER ;

   DEBUT
       POUR I := 1 , 8
           P := ELEMENT ( Tab_grpmatch [ I ] ) ;
           TQ P <> NIL
               S := VALEUR ( P ) ;
               Eq1 := STRUCT ( S , 1 ) ;
               Eq2 := STRUCT ( S , 2 ) ;
               Res1 := ALEANOMBRE ( 10) ;
               Res2 := ALEANOMBRE ( 10) ;
               INIT_STRUCT ( S , [ Eq1 , Eq2 , Res1 , Res2 ] ) ;
               AFF_VAL ( P , S ) ;
               appel eq_gagn(eq1,eq2,res1,res2, tab_eq_pts);
               P := SUIVANT ( P ) ;

           FTQ ;

       FINPOUR ;

   FIN

   action eq_gagn(eq1,eq2,res1,res2, tab_eq_pts)
   soient
         eq1,eq2,res1,res2,pts un entier;
         tab_eq_pts un vecteur(32) de entier;
   DEBUT
        SI Res1 > Res2
              /*l'equipe 1 est gagnate*/
                   Pts := ELEMENT ( Tab_eq_pts [ Eq1 ] ) + 3 ;
                   AFF_ELEMENT ( Tab_eq_pts [ Eq1 ] , Pts ) ;


               FINSI ;
               SI Res1 < Res2
              /*l'equipe 2 est gagnate*/
                   Pts := ELEMENT ( Tab_eq_pts [ Eq2 ] ) + 3 ;
                   AFF_ELEMENT ( Tab_eq_pts [ Eq2 ] , Pts ) ;


               FINSI ;
               SI Res1 = Res2
              /*le match est null*/
                   Pts := ELEMENT ( Tab_eq_pts [ Eq1 ] ) + 1 ;
                   AFF_ELEMENT ( Tab_eq_pts [ Eq1 ] , Pts ) ;
                   Pts := ELEMENT ( Tab_eq_pts [ Eq2 ] ) + 1 ;
                   AFF_ELEMENT ( Tab_eq_pts [ Eq2 ] , Pts ) ;

               FINSI ;
   FIN
   ACTION Init_tabeq ( Tab_eq ) ;
   SOIENT
       Tab_eq UN VECTEUR ( 32 ) DE ENTIER ;
       I UN ENTIER ;

   DEBUT
       POUR I := 1 , 32
           AFF_ELEMENT ( Tab_eq [ I ] , 0 ) ;

       FINPOUR ;

   FIN
   ACTION Class_eq ( Tab_eq_pts , Tab_grp_cls1 , Tab_grp_cls2 ) ;
   SOIENT
       Tab_eq_pts UN VECTEUR ( 32 ) DE ENTIER ;
       Tab_grp_cls1 UN VECTEUR ( 8 ) DE ENTIER ;
       Tab_grp_cls2 UN VECTEUR ( 8 ) DE ENTIER ;
       T UN VECTEUR ( 4 ) DE ENTIER ;
       I UN ENTIER ;
       J , K , L UN ENTIER ;
       Pts UN ENTIER ;
       Maxi UN ENTIER ;
       Pos UN ENTIER ;

   DEBUT
       POUR I := 1 , 8
           K := ( I - 1 ) * 3 + I ;
           J := K ;
           L := 1 ;
           TQ J <= K + 3
               Pts := ELEMENT ( Tab_eq_pts [ J ] ) ;
               AFF_ELEMENT ( T [ L ] , Pts ) ;
               J := J + 1 ;
               L := L + 1 ;

           FTQ ;
           Maxi := 0 ;
           POUR L := 1 , 4
               Pts := ELEMENT ( T [ L ] ) ;
               SI Pts > Maxi
                   Maxi := Pts ;
                   Pos := L ;

               FINSI ;

           FINPOUR ;
           Pos := K + Pos - 1 ;
           AFF_ELEMENT ( Tab_grp_cls1 [ I ] , Pos ) ;
           AFF_ELEMENT ( T [ Pos - K + 1 ] , 0 ) ;
           Maxi := 0 ;
           POUR L := 1 , 4
               Pts := ELEMENT ( T [ L ] ) ;
               SI Pts > Maxi
                   Maxi := Pts ;
                   Pos := L ;

               FINSI ;

           FINPOUR ;
           Pos := K + Pos - 1 ;
           AFF_ELEMENT ( Tab_grp_cls2 [ I ] , Pos ) ;

       FINPOUR ;

   FIN

action sim_eqch(Tab_grpmatch , Tab_eq_pts, eqch )
   SOIENT
       Tab_grpmatch UN VECTEUR ( 8 ) DE LISTE DE ( ENTIER , ENTIER , ENTIER , ENTIER ) ;
       eqch un entier;
       Tab_eq_pts UN VECTEUR ( 32 ) DE ENTIER ;
       P UN POINTEUR VERS UNE LISTE DE ( ENTIER , ENTIER , ENTIER , ENTIER ) ;
       S UNE STRUCTURE ( ENTIER , ENTIER , ENTIER , ENTIER ) ;
       I UN ENTIER ;
       Eq1 , Eq2 : ENTIER ;
       Res1 , Res2 : ENTIER ;
       Pts : ENTIER ;

   DEBUT
     POUR I := 1 , 8
           P := ELEMENT ( Tab_grpmatch [ I ] ) ;
           TQ P <> NIL
               S := VALEUR ( P ) ;
               Eq1 := STRUCT ( S , 1 ) ;
               Eq2 := STRUCT ( S , 2 ) ;
               si eq1= eqch /*l'equipe 1 favorite doit gagner*/
                  Res1 := ALEANOMBRE ( 10) ;
                  Res2 := ALEANOMBRE ( 10) ;
                  tq res1< res2
                     Res1 := ALEANOMBRE ( 10) ;
                     Res2 := ALEANOMBRE ( 10) ;
                  FTQ;

               FINSI;
               si eq2= eqch /*l'equipe 2 favorite doit gagner*/
                  Res1 := ALEANOMBRE ( 10) ;
                  Res2 := ALEANOMBRE ( 10) ;
                  tq res1> res2
                     Res1 := ALEANOMBRE ( 10) ;
                     Res2 := ALEANOMBRE ( 10) ;
                  FTQ;
               FINSI;
               si eq1<> eqch
                  si eq2<> eqch
                     Res1 := ALEANOMBRE ( 10) ;
                     Res2 := ALEANOMBRE ( 10) ;
                  FINSI;
               FINSI;
               INIT_STRUCT ( S , [ Eq1 , Eq2 , Res1 , Res2 ] ) ;
               AFF_VAL ( P , S ) ;
               appel eq_gagn(eq1,eq2,res1,res2, tab_eq_pts);
               P := SUIVANT ( P ) ;

           FTQ ;

       FINPOUR ;
   FIN
action sim_eqfav(tab_grpmatch, tab_eq_pts, tab_eq_rep)
   SOIENT
       Tab_grpmatch UN VECTEUR ( 8 ) DE LISTE DE ( ENTIER , ENTIER , ENTIER , ENTIER ) ;
       Tab_eq_pts UN VECTEUR ( 32 ) DE ENTIER ;
       tab_eq_rep un vecteur(32) de entier;
       P UN POINTEUR VERS UNE LISTE DE ( ENTIER , ENTIER , ENTIER , ENTIER ) ;
       S UNE STRUCTURE ( ENTIER , ENTIER , ENTIER , ENTIER ) ;
       I UN ENTIER ;
       Eq1 , Eq2 : ENTIER ;
       Res1 , Res2 : ENTIER ;
       rep1, rep2 : entier;
       Pts : ENTIER ;

   DEBUT
       POUR I := 1 , 8
           P := ELEMENT ( Tab_grpmatch [ I ] ) ;
           TQ P <> NIL
               S := VALEUR ( P ) ;
               Eq1 := STRUCT ( S , 1 ) ;
               Eq2 := STRUCT ( S , 2 ) ;
               rep1 := element(tab_eq_rep[eq1]);
               rep2 := element(tab_eq_rep[eq2]);
               si rep1-rep2>=5  /*l'equipe1 doit gagner*/
                  Res1 := ALEANOMBRE ( 10) ;
                  Res2 := ALEANOMBRE ( 10) ;
                  tq res1< res2
                     Res1 := ALEANOMBRE ( 10) ;
                     Res2 := ALEANOMBRE ( 10) ;
                  FTQ;
               FINSI;
               si rep1-rep2 <5
                  si rep1-rep2>=0
                     Res1 := ALEANOMBRE ( 10) ;
                     Res2 := ALEANOMBRE ( 10) ;
                     tq res1<> res2
                        Res1 := ALEANOMBRE ( 10) ;
                        Res2 := ALEANOMBRE ( 10) ;
                     FTQ;
                  FINSI;
               FINSI;
               si rep2-rep1>=5 /*l'equipe2 doit gagner*/
                  Res1 := ALEANOMBRE ( 10) ;
                  Res2 := ALEANOMBRE ( 10) ;
                  tq res2< res1
                     Res1 := ALEANOMBRE ( 10) ;
                     Res2 := ALEANOMBRE ( 10) ;
                  FTQ;
               FINSI;
               si rep2-rep1<5
                  si rep2-rep1>=0
                     Res1 := ALEANOMBRE ( 10) ;
                     Res2 := ALEANOMBRE ( 10) ;
                     tq res1<> res2
                        Res1 := ALEANOMBRE ( 10) ;
                        Res2 := ALEANOMBRE ( 10) ;
                     FTQ;
                  FINSI;
               FINSI;
               INIT_STRUCT ( S , [ Eq1 , Eq2 , Res1 , Res2 ] ) ;
               AFF_VAL ( P , S ) ;
               appel eq_gagn(eq1,eq2,res1,res2, tab_eq_pts);
               P := SUIVANT ( P ) ;

           FTQ ;

       FINPOUR ;

   FIN


  ACTION Sim_eqfav_has( Tab_grpmatch ,tab_eq_rep, Tab_eq_pts )
   SOIENT
       Tab_grpmatch UN VECTEUR ( 8 ) DE LISTE DE ( ENTIER , ENTIER , ENTIER , ENTIER ) ;
       Tab_eq_pts UN VECTEUR ( 32 ) DE ENTIER ;
       tab_eq_rep un vecteur(32) de entier;
       P UN POINTEUR VERS UNE LISTE DE ( ENTIER , ENTIER , ENTIER , ENTIER ) ;
       S UNE STRUCTURE ( ENTIER , ENTIER , ENTIER , ENTIER ) ;
       I UN ENTIER ;
       Eq1 , Eq2 : ENTIER ;
       Res1 , Res2 : ENTIER ;
       rep1, rep2 : entier;
       difrep un entier;
       Pts : ENTIER ;
       pos: entier; {pos: la possibilté d'une equipe pour qu'elle gagne}

   DEBUT
       POUR I := 1 , 8
           P := ELEMENT ( Tab_grpmatch [ I ] ) ;
           TQ P <> NIL
               S := VALEUR ( P ) ;
               Eq1 := STRUCT ( S , 1 ) ;
               Eq2 := STRUCT ( S , 2 ) ;
               rep1 := element(tab_eq_rep[eq1]);
               rep2 := element(tab_eq_rep[eq2]);
               si rep1> rep2
                  difrep:= rep1-rep2; {La difference serait superieure ou egale a 1}
                  pos:= aleanombre(difrep+15);
                  si pos< difrep {L'equipe 1 doit gagner}
                     Res1 := ALEANOMBRE ( 10) ;
                     Res2 := ALEANOMBRE ( 10) ;
                     tq res1< res2
                        Res1 := ALEANOMBRE ( 10) ;
                        Res2 := ALEANOMBRE ( 10) ;
                     FTQ;
                  SINON
                       si pos < difrep+10 {Le match doit etre null}
                          Res1 := ALEANOMBRE ( 10) ;
                          Res2 := ALEANOMBRE ( 10) ;
                          tq res1<> res2
                             Res1 := ALEANOMBRE ( 10) ;
                             Res2 := ALEANOMBRE ( 10) ;
                          FTQ;
                       sinon {L'equipe 2 doit gagner}
                             Res1 := ALEANOMBRE ( 10) ;
                             Res2 := ALEANOMBRE ( 10) ;
                             tq res2< res1
                                Res1 := ALEANOMBRE ( 10) ;
                                Res2 := ALEANOMBRE ( 10) ;
                             FTQ;
                       FINSI;
                  FINSI;
               FINSI;
               si rep1=rep2 {Le match doit etre null}
                  Res1 := ALEANOMBRE ( 10) ;
                  Res2 := ALEANOMBRE ( 10) ;
                       tq res1<> res2
                             Res1 := ALEANOMBRE ( 10) ;
                             Res2 := ALEANOMBRE ( 10) ;
                       FTQ;
               FINSI;
               si rep1 <rep2
                  difrep:= rep2-rep1;
                  pos:= aleanombre(difrep+15);
                  si pos< difrep {L'equipe 2 doit gagner}
                     Res1 := ALEANOMBRE ( 10) ;
                     Res2 := ALEANOMBRE ( 10) ;
                     tq res2< res1
                        Res1 := ALEANOMBRE ( 10) ;
                        Res2 := ALEANOMBRE ( 10) ;
                     FTQ;
                  SINON
                       si pos < difrep+10 {Le match doit etre null}
                          Res1 := ALEANOMBRE ( 10) ;
                          Res2 := ALEANOMBRE ( 10) ;
                          tq res1<> res2
                             Res1 := ALEANOMBRE ( 10) ;
                             Res2 := ALEANOMBRE ( 10) ;
                          FTQ;
                       sinon {L'equipe 1 doit gagner}
                             Res1 := ALEANOMBRE ( 10) ;
                             Res2 := ALEANOMBRE ( 10) ;
                             tq res1< res2
                                Res1 := ALEANOMBRE ( 10) ;
                                Res2 := ALEANOMBRE ( 10) ;
                             FTQ;
                       FINSI;
                  FINSI;
               FINSI;
               INIT_STRUCT ( S , [ Eq1 , Eq2 , Res1 , Res2 ] ) ;
               AFF_VAL ( P , S ) ;
               appel eq_gagn(eq1,eq2,res1,res2, tab_eq_pts);
               P := SUIVANT ( P ) ;

           FTQ ;

       FINPOUR ;

   FIN
action sim_maxsc(tab_grpmatch, tab_eq_pts, maxsc)
soient
       Tab_grpmatch UN VECTEUR ( 8 ) DE LISTE DE ( ENTIER , ENTIER , ENTIER , ENTIER ) ;
       Tab_eq_pts UN VECTEUR ( 32 ) DE ENTIER ;
       maxsc un entier;
       P UN POINTEUR VERS UNE LISTE DE ( ENTIER , ENTIER , ENTIER , ENTIER ) ;
       S UNE STRUCTURE ( ENTIER , ENTIER , ENTIER , ENTIER ) ;
       I UN ENTIER ;
       Eq1 , Eq2 : ENTIER ;
       Res1 , Res2 : ENTIER ;
       Pts : ENTIER ;
DEBUT
     POUR I := 1 , 8
           P := ELEMENT ( Tab_grpmatch [ I ] ) ;
           TQ P <> NIL
               S := VALEUR ( P ) ;
               Eq1 := STRUCT ( S , 1 ) ;
               Eq2 := STRUCT ( S , 2 ) ;
               Res1 := ALEANOMBRE ( 10) ;
               Res2 := ALEANOMBRE ( 10) ;
               INIT_STRUCT ( S , [ Eq1 , Eq2 , Res1 , Res2 ] ) ;
               AFF_VAL ( P , S ) ;
               SI Res1 > maxsc
              /*l'equipe 1 est gagnate comme son resultat est superieure a maxsc*/
                   Pts := ELEMENT ( Tab_eq_pts [ Eq1 ] ) + 3 ;
                   AFF_ELEMENT ( Tab_eq_pts [ Eq1 ] , Pts ) ;


               FINSI ;
               SI res2>maxsc
              /*l'equipe 2 est gagnate comme son resultat est superieure a maxsc*/
                   Pts := ELEMENT ( Tab_eq_pts [ Eq2 ] ) + 3 ;
                   AFF_ELEMENT ( Tab_eq_pts [ Eq2 ] , Pts ) ;


               FINSI ;
               SI Res1 = maxsc
              /*l'equipe 1 a un resultat egal a maxsc donc c'est considéré comme null */
                   Pts := ELEMENT ( Tab_eq_pts [ Eq1 ] ) + 1 ;
                   AFF_ELEMENT ( Tab_eq_pts [ Eq1 ] , Pts ) ;

               FINSI ;
               si res2= maxsc
               /*l'equipe 2 a un resultat egal a maxsc donc c'est considéré comme null */
                   Pts := ELEMENT ( Tab_eq_pts [ Eq2 ] ) + 1 ;
                   AFF_ELEMENT ( Tab_eq_pts [ Eq2 ] , Pts ) ;
               FINSI;
               P := SUIVANT ( P ) ;

           FTQ ;

       FINPOUR ;
FIN

action affichage(tab_grpmatch, tab_eq_pts);
soient
      Tab_grpmatch UN VECTEUR ( 8 ) DE LISTE DE ( ENTIER , ENTIER , ENTIER , ENTIER ) ;
      Tab_eq_pts UN VECTEUR ( 32 ) DE ENTIER ;
      Sg UNE STRUCTURE ( ENTIER , ENTIER , ENTIER , ENTIER ) ;
      P UN POINTEUR VERS UNE LISTE DE ( ENTIER , ENTIER , ENTIER , ENTIER ) ;
      i,k un entier;

DEBUT
       k:= 1;
       pour j:=1, 8
            ecrire('groupe', j);
            p:= element(tab_grpmatch[1]);
            tq p<>nil
               sg:= valeur(p);
               ecrire('match: ');
               ecrire(sg);
               p:= suivant(p);
            FTQ;
            ecrire('','');
            pour i:=k, k+3
                 ecrire('eq, ',i);
                 ecrire(element(tab_eq_pts[i]), 'pts.');
            FINPOUR;
            k:= k+4;
            ecrire('-------------','');
       FINPOUR;
FIN


action creer_tab_rep(tab_eq_rep)
soient
      tab_eq_rep un vecteur(32) de entier;
      i un entier;
      rep un entier;

DEBUT
     aff_element(tab_eq_rep[1], 42); aff_element(tab_eq_rep[2], 47);
     aff_element(tab_eq_rep[3], 52); aff_element(tab_eq_rep[4], 39);
     aff_element(tab_eq_rep[5], 76); aff_element(tab_eq_rep[6], 51);
     aff_element(tab_eq_rep[7], 59); aff_element(tab_eq_rep[8], 41);
     aff_element(tab_eq_rep[9], 78); aff_element(tab_eq_rep[10], 55);
     aff_element(tab_eq_rep[11], 51); aff_element(tab_eq_rep[12], 51);
     aff_element(tab_eq_rep[13], 72); aff_element(tab_eq_rep[14], 61);
     aff_element(tab_eq_rep[15], 52); aff_element(tab_eq_rep[16], 54);
     aff_element(tab_eq_rep[17], 82); aff_element(tab_eq_rep[18], 76);
     aff_element(tab_eq_rep[19], 54); aff_element(tab_eq_rep[20], 56);
     aff_element(tab_eq_rep[21], 59); aff_element(tab_eq_rep[22], 67);
     aff_element(tab_eq_rep[23], 57); aff_element(tab_eq_rep[24], 59);
     aff_element(tab_eq_rep[25], 81); aff_element(tab_eq_rep[26], 49);
     aff_element(tab_eq_rep[27], 55); aff_element(tab_eq_rep[28], 51);
     aff_element(tab_eq_rep[29], 74); aff_element(tab_eq_rep[30], 64);
     aff_element(tab_eq_rep[31], 63); aff_element(tab_eq_rep[32], 51);
FIN
action creer_tab_phase2(tab_phase2, tab_grp_cls1, tab_grp_cls2)
soient
      tab_phase2 un vecteur(15) de (entier, entier, entier, entier);
      tab_grp_cls1 un vecteur(8) de entier;
      tab_grp_cls2 un vecteur(8) de entier;
      i,j un entier;
      sg une structure (entier, entier, entier, entier);

DEBUT
     init_struct(sg, [0,0,0,0]);
     pour i:= 1, 7
          aff_element(tab_phase2[i], sg);
     FINPOUR;
     j:= 1;
     pour i:=8,15
          si mod(j,2)=0
             init_struct(sg, [element(tab_grp_cls1[j]), element(tab_grp_cls2[j-1]), 0,0]);
          SINON
             init_struct(sg, [element(tab_grp_cls1[j]), element(tab_grp_cls2[j+1]), 0,0]);
          FINSI;
          aff_element(tab_phase2[i], sg);
          j:= j+1;
     FINPOUR;
FIN

fonction creer_arb_match(tab_phase2, arb_match, i, n):  arb de (entier, entier, entier, entier);
soient
     tab_phase2 un vecteur(15) de (entier, entier, entier, entier);
     arb_match un arb de (entier, entier, entier, entier);
     i,n un entier;
     p un pointeur vers un arb de (entier, entier, entier, entier);
     sg une structure (entier, entier, entier, entier);
DEBUT
     si i<n: {Le cas de base}
             creernoeud(p);
             sg:= element(tab_phase2[i]);
             aff_info(p, sg);
             arb_match:= p;
             {inserer le fils gauche}
             aff_fg(arb_match, creer_arb_match(tab_phase2, fg(arb_match), 2*i, n));
             {inserer le fils droite}
             aff_fd(arb_match, creer_arb_match(tab_phase2, fd(arb_match), 2*i+1, n));
     FINSI;
     creer_arb_match:= arb_match;

FIN


action inordre(r)
soient
      r un arb de  (entier, entier, entier, entier);
DEBUT
     si r<>nil
        appel inordre(fg(r));
        ecrire('',info(r), '');
        appel inordre(fd(r));
     FINSI;
FIN

action parcourenlargeur(r)
soient
      r un arb de (entier, entier, entier, entier);
      p un pointeur vers un arb de  (entier, entier, entier, entier);
      f une file de arb de (entier, entier, entier, entier);
      sg une structure (entier, entier, entier, entier);
DEBUT
     CREERFILE ( F );
     si r<>nil
        enfiler(f,r);
     FINSI;
     TQ non FILEVIDE ( F)
        defiler(f,p);
        ecrire(info(p));
        SI fg(p)<> nil
           enfiler(f, fg(p));
        FINSI;
        SI fd(p)<> nil
           enfiler(f, fd(p));
        FINSI;
     FTQ;

FIN
action parlarginv(r,pi)
soient
      r un arb de (entier, entier, entier, entier);
      p un pointeur vers un arb de  (entier, entier, entier, entier);
      f une file de arb de (entier, entier, entier, entier);
      pi une pile de arb de (entier, entier, entier, entier);
      sg une structure (entier, entier, entier, entier);
DEBUT
     CREERFILE ( F );
     creerpile(pi);
     si r<>nil
        enfiler(f,r);
        empiler(pi,r);
     FINSI;
     TQ non FILEVIDE ( F)
        defiler(f,p);
        SI fd(p)<> nil
           enfiler(f, fd(p));
           empiler(pi,fd(p));
        FINSI;
        SI fd(p)<> nil
           enfiler(f, fg(p));
           empiler(pi, fg(p));
        FINSI;
     FTQ;

FIN

action affichage_arb(pi)
soient
      pi une pile de arb de (entier, entier, entier, entier);
      p un pointeur vers un arb de (entier, entier, entier, entier);
DEBUT
     tq non pilevide(pi)
        depiler(pi, p);
        ecrire(info(p));
     FTQ;
FIN


action ph2_sim_hasard(arb_match)
soient
      arb_match un arb de (entier, entier, entier, entier);
      pi une pile de arb de (entier, entier, entier, entier);
      p un pointeur vers un arb de (entier, entier, entier, entier);
      sg une structure (entier, entier, entier, entier);
      sh une structure (entier, entier, entier, entier);
      i un entier;
      eq1, eq2 un entier;
      res1, res2 un entier;
      alea un entier;
DEBUT
     appel parlarginv(arb_match, pi);
     i:=1;
     TQ i<=8
        depiler(pi, p);
        sg:= info(p);
        res1:= aleanombre(20);
        res2:= aleanombre(20);
        init_struct(sg, [struct(sg,1), struct(sg,2), res1, res2] );
        aff_info(p, sg);
        i:= i+1;
     FTQ;
     i:= 1;
     TQ i<=7
        depiler(pi,p);
        sg:= info(fd(p));
        sh:= info(p);
        res1:= struct(sg, 3);
        res2:= struct(sg,4);
        si res1>res2 {l'equipe 1 est gagnante}
              init_struct(sh, [struct(sh,1), struct(sg,1),aleanombre(20),aleanombre(20)]);
              aff_info(p, sh);
             FINSI;

             SI res1= res2 {le match est nul, affectuer un tirage au sort}
                alea:= aleanombre(2);
                si alea= 1 {l'equipe 1 est gagnante}
                   init_struct(sh, [struct(sh,1), struct(sg,1),aleanombre(20),aleanombre(20)]);
                   aff_info(p, sh);
                sinon {l'equipe 2 est gagnante}
                      init_struct(sh, [struct(sh,2), struct(sg,2),aleanombre(20),aleanombre(20)]);
                      aff_info(p, sh);
                Finsi;
             FINSI;

             si res1<res2 {l'equipe 2 est gagnante}
                init_struct(sh, [struct(sh,2), struct(sg,2),aleanombre(20),aleanombre(20)]);
                aff_info(p, sh);
             FINSI;
        sg:= info(fg(p));
        res1:= struct(sg, 3);
        res2:= struct(sg,4);
        si res1>res2 {l'equipe 1 est gagnante}
              init_struct(sh, [struct(sg,1), struct(sh,2),aleanombre(20),aleanombre(20)]);
              aff_info(p, sh);
             FINSI;

             SI res1= res2 {le match est nul, affectuer un tirage au sort}
                alea:= aleanombre(2);
                si alea= 1 {l'equipe 1 est gagnante}
                   init_struct(sh, [struct(sg,1), struct(sh,2),aleanombre(20),aleanombre(20)]);
                   aff_info(p, sh);
                sinon {l'equipe 2 est gagnante}
                      init_struct(sh, [struct(sg,2), struct(sh,2),aleanombre(20),aleanombre(20)]);
                      aff_info(p, sh);
                Finsi;
             FINSI;

             si res1<res2 {l'equipe 2 est gagnante}
                init_struct(sh, [struct(sg,2), struct(sh,2),aleanombre(20),aleanombre(20)]);
                aff_info(p, sh);
             FINSI;
     i:= i+1;
     FTQ


FIN

action ph2_sim_eqfav(arb_match, tab_phase2, tab_eq_rep)
soient
      arb_match un arb de (entier, entier, entier, entier);
      tab_phase2 un vecteur(15) de (entier, entier, entier, entier);
      tab_eq_rep un vecteur(32) de entier;
      sg, sh une structure (entier, entier, entier, entier);
      i,j, alea un entier;
      eq1,eq2,rep1,rep2, res1, res2 un entier;
DEBUT
     pour i:=8, 15
        sg:= element(tab_phase2[i]);
        eq1:= struct(sg,1);
        eq2:= struct(sg,2);
        rep1 := element(tab_eq_rep[eq1]);
        rep2 := element(tab_eq_rep[eq2]);
        si rep1-rep2>=5  /*l'equipe1 doit gagner*/
                  Res1 := ALEANOMBRE ( 10) ;
                  Res2 := ALEANOMBRE ( 10) ;
                  tq res1< res2
                     Res1 := ALEANOMBRE ( 10) ;
                     Res2 := ALEANOMBRE ( 10) ;
                  FTQ;
               FINSI;
               si rep1-rep2 <5
                  si rep1-rep2>=0
                     Res1 := ALEANOMBRE ( 10) ;
                     Res2 := ALEANOMBRE ( 10) ;
                     tq res1<> res2
                        Res1 := ALEANOMBRE ( 10) ;
                        Res2 := ALEANOMBRE ( 10) ;
                     FTQ;
                  FINSI;
               FINSI;
               si rep2-rep1> 5 /*l'equipe2 doit gagner*/
                  Res1 := ALEANOMBRE ( 10) ;
                  Res2 := ALEANOMBRE ( 10) ;
                  tq res2< res1
                     Res1 := ALEANOMBRE ( 10) ;
                     Res2 := ALEANOMBRE ( 10) ;
                  FTQ;
               FINSI;
               si rep2-rep1<5
                  si rep2-rep1>=0
                     Res1 := ALEANOMBRE ( 10) ;
                     Res2 := ALEANOMBRE ( 10) ;
                     tq res1<> res2
                        Res1 := ALEANOMBRE ( 10) ;
                        Res2 := ALEANOMBRE ( 10) ;
                     FTQ;
                  FINSI;
               FINSI;
               INIT_STRUCT ( Sg , [ Eq1 , Eq2 , Res1 , Res2 ] ) ;
               aff_element(tab_phase2[i], sg);
     FINPOUR;
     appel ph2_sim_eqfav2(tab_phase2, tab_eq_rep);
     arb_match:= creer_arb_match(tab_phase2, arb_match, 1, 16);
FIN

action ph2_sim_eqfav2(tab_phase2, tab_eq_rep)
soient
      tab_phase2 un vecteur(15) de (entier, entier, entier, entier);
      tab_eq_rep un vecteur(32) de entier;
      sg, sh une structure (entier, entier, entier, entier);
      i,j, alea un entier;
      eq1,eq2,rep1,rep2, res1, res2 un entier;
DEBUT
     j:= 15;
     pour i:=7, 1, -1
           sh:= element(tab_phase2[i]);
           sg:= element(tab_phase2[j]);
          res1:= struct(sg, 3);
          res2:= struct(sg,4);
        si res1>res2 {l'equipe 1 est gagnante}
              init_struct(sh, [struct(sh,1), struct(sg,1),0,0]);

             FINSI;

             SI res1= res2 {le match est nul, affectuer un tirage au sort}
                alea:= aleanombre(2);
                si alea= 1 {l'equipe 1 est gagnante}
                   init_struct(sh, [struct(sh,1), struct(sg,1),0,0]);

                sinon {l'equipe 2 est gagnante}
                      init_struct(sh, [struct(sh,1), struct(sg,2),0,0]);

                Finsi;
             FINSI;

             si res1<res2 {l'equipe 2 est gagnante}
                init_struct(sh, [struct(sh,1), struct(sg,2),0,0]);

             FINSI;
          j:= j-1;
              sg:= element(tab_phase2[j]);
              res1:= struct(sg, 3);
              res2:= struct(sg,4);
               si res1>res2 {l'equipe 1 est gagnante}
              init_struct(sh, [struct(sg,1), struct(sh,2),0,0]);
             FINSI;

             SI res1= res2 {le match est nul, affectuer un tirage au sort}
                alea:= aleanombre(2);
                si alea= 1 {l'equipe 1 est gagnante}
                   init_struct(sh, [struct(sg,1), struct(sh,2),0,0]);

                sinon {l'equipe 2 est gagnante}
                      init_struct(sh, [struct(sg,2), struct(sh,2),0,0]);

                Finsi;
             FINSI;

             si res1<res2 {l'equipe 2 est gagnante}
                init_struct(sh, [struct(sg,2), struct(sh,2),0,0]);

             FINSI;
             eq1:= struct(sh,1);
             eq2:= struct(sh,2);
             rep1 := element(tab_eq_rep[eq1]);
             rep2 := element(tab_eq_rep[eq2]);
             si rep1-rep2>=5  /*l'equipe1 doit gagner*/
                  Res1 := ALEANOMBRE ( 10) ;
                  Res2 := ALEANOMBRE ( 10) ;
                  tq res1< res2
                     Res1 := ALEANOMBRE ( 10) ;
                     Res2 := ALEANOMBRE ( 10) ;
                  FTQ;
               FINSI;
               si rep1-rep2 <5
                  si rep1-rep2>=0
                     Res1 := ALEANOMBRE ( 10) ;
                     Res2 := ALEANOMBRE ( 10) ;
                     tq res1<> res2
                        Res1 := ALEANOMBRE ( 10) ;
                        Res2 := ALEANOMBRE ( 10) ;
                     FTQ;
                  FINSI;
               FINSI;
               si rep2-rep1>=5 /*l'equipe2 doit gagner*/
                  Res1 := ALEANOMBRE ( 10) ;
                  Res2 := ALEANOMBRE ( 10) ;
                  tq res2< res1
                     Res1 := ALEANOMBRE ( 10) ;
                     Res2 := ALEANOMBRE ( 10) ;
                  FTQ;
               FINSI;
               si rep2-rep1<5
                  si rep2-rep1>=0
                     Res1 := ALEANOMBRE ( 10) ;
                     Res2 := ALEANOMBRE ( 10) ;
                     tq res1<> res2
                        Res1 := ALEANOMBRE ( 10) ;
                        Res2 := ALEANOMBRE ( 10) ;
                     FTQ;
                  FINSI;
               FINSI;
               INIT_STRUCT ( Sh , [ Eq1 , Eq2 , Res1 , Res2 ] ) ;
             aff_element(tab_phase2[i], sh);
             j:= j-1;
     FINPOUR;
FIN

action creer_tabtotbuts(tab_grpmatch, tab_eq_totbuts)
soient
      Tab_grpmatch UN VECTEUR ( 8 ) DE LISTE DE ( ENTIER , ENTIER , ENTIER , ENTIER ) ;
      tab_eq_totbuts un vecteur (32) de entier;
      p un pointeur vers une LISTE DE ( ENTIER , ENTIER , ENTIER , ENTIER ) ;
      sg une structure ( ENTIER , ENTIER , ENTIER , ENTIER ) ;
      i un entier;

DEBUT
     appel init_tabeq(tab_eq_totbuts);
     pour i:=1, 8
          p:= element(tab_grpmatch[i]);
          tq p<>nil
             sg:= valeur(p);
             aff_element(tab_eq_totbuts[struct(sg,1)], struct(sg,3)+ element(tab_eq_totbuts[struct(sg,1)]) );
             aff_element(tab_eq_totbuts[struct(sg,2)], struct(sg,4)+ element(tab_eq_totbuts[struct(sg,2)]) );
          p:= suivant(p);
          FTQ;
     FINPOur;

FIN



action ph2_sim_resph12(arb_match, tab_eq_totbuts, ch)
soient
       arb_match un arb de (entier, entier, entier, entier);
       tab_eq_totbuts un vecteur (32) de entier;
       pi une pile de  arb de (entier, entier, entier, entier);
       p un pointeur vers un arb de (entier, entier, entier, entier);
       sg, sh une structure (entier, entier, entier, entier);
       eq1,eq2,res1,res2, buts1,buts2 un entier;
       ch un entier; {si ch=0 -> selon les res phase1, si ch=1 -> selon les res phase1 et phase2}
DEBUT
     appel parlarginv(arb_match, pi);
     pour i:=1,8
          depiler(pi,p);
          sg:= info(p);
          eq1:= struct(sg, 1);
          eq2:= struct(sg, 2);
          buts1:= element(tab_eq_totbuts[eq1]);
          buts2:= element(tab_eq_totbuts[eq2]);
          si buts1-buts2>=5  /*l'equipe1 doit gagner*/
                  Res1 := ALEANOMBRE ( 10) ;
                  Res2 := ALEANOMBRE ( 10) ;
                  tq res1< res2
                     Res1 := ALEANOMBRE ( 10) ;
                     Res2 := ALEANOMBRE ( 10) ;
                  FTQ;
               FINSI;
               si buts1-buts2 <5
                  si buts1-buts2>=0
                     Res1 := ALEANOMBRE ( 10) ;
                     Res2 := ALEANOMBRE ( 10) ;
                     tq res1<> res2
                        Res1 := ALEANOMBRE ( 10) ;
                        Res2 := ALEANOMBRE ( 10) ;
                     FTQ;
                  FINSI;
               FINSI;
               si buts2-buts1>=5 /*l'equipe2 doit gagner*/
                  Res1 := ALEANOMBRE ( 10) ;
                  Res2 := ALEANOMBRE ( 10) ;
                  tq res2< res1
                     Res1 := ALEANOMBRE ( 10) ;
                     Res2 := ALEANOMBRE ( 10) ;
                  FTQ;
               FINSI;
               si buts2-buts1<5
                  si buts2-buts1>=0
                     Res1 := ALEANOMBRE ( 10) ;
                     Res2 := ALEANOMBRE ( 10) ;
                     tq res1<> res2
                        Res1 := ALEANOMBRE ( 10) ;
                        Res2 := ALEANOMBRE ( 10) ;
                     FTQ;
                  FINSI;
               FINSI;
               INIT_STRUCT ( Sg , [ Eq1 , Eq2 , Res1 , Res2 ] ) ;
               aff_info(p, sg);
               si ch=1
                  buts1:= buts1+res1;
                  aff_element(tab_eq_totbuts[eq1], buts1);
                  buts2:= buts2+res2;
                  aff_element(tab_eq_totbuts[eq2], buts2);
               FINSI;
     FINPOUR;
     appel ph2_sim_resph12_2(pi, tab_eq_totbuts, ch);
FIN

action ph2_sim_resph12_2(pi, tab_eq_totbuts, ch)
soient
       tab_eq_totbuts un vecteur (32) de entier;
       pi une pile de  arb de (entier, entier, entier, entier);
       p un pointeur vers un arb de (entier, entier, entier, entier);
       sg, sh une structure (entier, entier, entier, entier);
       eq1,eq2,res1,res2,alea, buts1,buts2 un entier;
       ch un entier;
DEBUT
     i:= 1;
     TQ i<=7
        depiler(pi,p);
        sg:= info(fd(p));
        sh:= info(p);
        eq1:= struct(sg, 1);
        eq2:= struct(sg, 2);
        buts1:= element(tab_eq_totbuts[eq1]);
        buts2:= element(tab_eq_totbuts[eq2]);
        res1:= struct(sg, 3);
        res2:= struct(sg,4);
        si res1>res2 {l'equipe 1 est gagnante}
              init_struct(sh, [struct(sh,1), struct(sg,1),0,0]);
             FINSI;

             SI res1= res2 {le match est nul, affectuer un tirage au sort}
                alea:= aleanombre(2);
                si alea= 1 {l'equipe 1 est gagnante}
                   init_struct(sh, [struct(sh,1), struct(sg,1),0,0]);
                sinon {l'equipe 2 est gagnante}
                      init_struct(sh, [struct(sh,2), struct(sg,2),0,0]);
                Finsi;
             FINSI;

             si res1<res2 {l'equipe 2 est gagnante}
                init_struct(sh, [struct(sh,2), struct(sg,2),0,0]);
             FINSI;
        sg:= info(fg(p));
        res1:= struct(sg, 3);
        res2:= struct(sg,4);
        si res1>res2 {l'equipe 1 est gagnante}
              init_struct(sh, [struct(sg,1), struct(sh,2),0,0]);
             FINSI;

             SI res1= res2 {le match est nul, affectuer un tirage au sort}
                alea:= aleanombre(2);
                si alea= 1 {l'equipe 1 est gagnante}
                   init_struct(sh, [struct(sg,1), struct(sh,2),0,0]);
                sinon {l'equipe 2 est gagnante}
                      init_struct(sh, [struct(sg,2), struct(sh,2),0,0]);
                Finsi;
             FINSI;

             si res1<res2 {l'equipe 2 est gagnante}
                init_struct(sh, [struct(sg,2), struct(sh,2),0,0]);
             FINSI;
             eq1:= struct(sh, 1);
             eq2:= struct(sh, 2);
             buts1:= element(tab_eq_totbuts[eq1]);
             buts2:= element(tab_eq_totbuts[eq2]);
             si buts1-buts2>=5  /*l'equipe1 doit gagner*/
                  Res1 := ALEANOMBRE ( 10) ;
                  Res2 := ALEANOMBRE ( 10) ;
                  tq res1< res2
                     Res1 := ALEANOMBRE ( 10) ;
                     Res2 := ALEANOMBRE ( 10) ;
                  FTQ;
               FINSI;
               si buts1-buts2 <5
                  si buts1-buts2>=0
                     Res1 := ALEANOMBRE ( 10) ;
                     Res2 := ALEANOMBRE ( 10) ;
                     tq res1<> res2
                        Res1 := ALEANOMBRE ( 10) ;
                        Res2 := ALEANOMBRE ( 10) ;
                     FTQ;
                  FINSI;
               FINSI;
               si buts2-buts1>=5 /*l'equipe2 doit gagner*/
                  Res1 := ALEANOMBRE ( 10) ;
                  Res2 := ALEANOMBRE ( 10) ;
                  tq res2< res1
                     Res1 := ALEANOMBRE ( 10) ;
                     Res2 := ALEANOMBRE ( 10) ;
                  FTQ;
               FINSI;
               si buts2-buts1<5
                  si buts2-buts1>=0
                     Res1 := ALEANOMBRE ( 10) ;
                     Res2 := ALEANOMBRE ( 10) ;
                     tq res1<> res2
                        Res1 := ALEANOMBRE ( 10) ;
                        Res2 := ALEANOMBRE ( 10) ;
                     FTQ;
                  FINSI;
               FINSI;
               INIT_STRUCT ( Sh , [ Eq1 , Eq2 , Res1 , Res2 ] ) ;
               aff_info(p, sh);
               si ch=1
                  buts1:= buts1+res1;
                  aff_element(tab_eq_totbuts[eq1], buts1);
                  buts2:= buts2+res2;
                  aff_element(tab_eq_totbuts[eq2], buts2);
               FINSI;
     i:= i+1;
     FTQ;
FIN

action ph2_sim_eqfavresph1(arb_match, tab_eq_rep, tab_eq_totbuts, ch)
soient
       arb_match un arb de (entier, entier, entier, entier);
       tab_eq_rep un vecteur(32) de entier;
       tab_eq_totbuts un vecteur (32) de entier;
       pi une pile de  arb de (entier, entier, entier, entier);
       p un pointeur vers un arb de (entier, entier, entier, entier);
       sg, sh une structure (entier, entier, entier, entier);
       eq1,eq2,res1,res2, buts1,buts2,rep1,rep2 un entier;
       ch un entier;
DEBUT
     appel parlarginv(arb_match, pi);
     pour i:=1,8
          depiler(pi,p);
          sg:= info(p);
          eq1:= struct(sg,1);
          eq2:= struct(sg,2);
          rep1:= element(tab_eq_rep[eq1]);
          rep2:= element(tab_eq_rep[eq2]);
          buts1:= element(tab_eq_totbuts[eq1]);
          buts2:= element(tab_eq_totbuts[eq2]);
          si (rep1-rep2>=5)   /*l'equipe1 doit gagner*/
                  Res1 := ALEANOMBRE ( 10) ;
                  Res2 := ALEANOMBRE ( 10) ;
                  tq res1< res2
                     Res1 := ALEANOMBRE ( 10) ;
                     Res2 := ALEANOMBRE ( 10) ;
                  FTQ;
               FINSI;
               si rep1-rep2 <5
                  si rep1-rep2>=0
                     si buts1>buts2
                     /*l'equipe1 doit gagner*/
                         Res1 := ALEANOMBRE ( 10) ;
                         Res2 := ALEANOMBRE ( 10) ;
                         tq res1< res2
                            Res1 := ALEANOMBRE ( 10) ;
                            Res2 := ALEANOMBRE ( 10) ;
                         FTQ;
                     FINSI;
                     si buts1<buts2
                        Res1 := ALEANOMBRE ( 10) ;
                        Res2 := ALEANOMBRE ( 10) ;
                        tq res2< res1
                           Res1 := ALEANOMBRE ( 10) ;
                           Res2 := ALEANOMBRE ( 10) ;
                        FTQ;
                     FINSI;
                     si buts1=buts2
                        Res1 := ALEANOMBRE ( 10) ;
                        Res2 := ALEANOMBRE ( 10) ;
                        tq res1<> res2
                           Res1 := ALEANOMBRE ( 10) ;
                           Res2 := ALEANOMBRE ( 10) ;
                        FTQ;
                     FINSI;
                  FINSI;
               FINSI;
               si rep2-rep1> 5 /*l'equipe2 doit gagner*/
                  Res1 := ALEANOMBRE ( 10) ;
                  Res2 := ALEANOMBRE ( 10) ;
                  tq res2< res1
                     Res1 := ALEANOMBRE ( 10) ;
                     Res2 := ALEANOMBRE ( 10) ;
                  FTQ;
               FINSI;
               si rep2-rep1<5
                  si rep2-rep1>=0
                     si buts1>buts2
                     /*l'equipe1 doit gagner*/
                         Res1 := ALEANOMBRE ( 10) ;
                         Res2 := ALEANOMBRE ( 10) ;
                         tq res1< res2
                            Res1 := ALEANOMBRE ( 10) ;
                            Res2 := ALEANOMBRE ( 10) ;
                         FTQ;
                     FINSI;
                     si buts1<buts2
                        Res1 := ALEANOMBRE ( 10) ;
                        Res2 := ALEANOMBRE ( 10) ;
                        tq res2< res1
                           Res1 := ALEANOMBRE ( 10) ;
                           Res2 := ALEANOMBRE ( 10) ;
                        FTQ;
                     FINSI;
                     si buts1=buts2
                        Res1 := ALEANOMBRE ( 10) ;
                        Res2 := ALEANOMBRE ( 10) ;
                        tq res1<> res2
                           Res1 := ALEANOMBRE ( 10) ;
                           Res2 := ALEANOMBRE ( 10) ;
                        FTQ;
                     FINSI;
                  FINSI;
               FINSI;
               INIT_STRUCT ( Sg , [ Eq1 , Eq2 , Res1 , Res2 ] ) ;
               aff_info(p,sg);
               si ch=1
                  buts1:= buts1+res1;
                  aff_element(tab_eq_totbuts[eq1], buts1);
                  buts2:= buts2+res2;
                  aff_element(tab_eq_totbuts[eq2], buts2);
               FINSI;
     FINPOUR;
     appel ph2sim_eqfavresph12(pi, tab_eq_rep, tab_eq_totbuts, ch);
FIN

action ph2sim_eqfavresph12(pi, tab_eq_rep, tab_eq_totbuts, ch)
soient
       tab_eq_rep un vecteur(32) de entier;
       tab_eq_totbuts un vecteur (32) de entier;
       pi une pile de  arb de (entier, entier, entier, entier);
       p un pointeur vers un arb de (entier, entier, entier, entier);
       sg, sh une structure (entier, entier, entier, entier);
       eq1,eq2,res1,res2, buts1,buts2,rep1,rep2 un entier;
       ch un entier;
DEBUT
     i:= 1;
     TQ i<=7
        depiler(pi,p);
        sg:= info(fd(p));
        sh:= info(p);
        eq1:= struct(sg, 1);
        eq2:= struct(sg, 2);
        res1:= struct(sg, 3);
        res2:= struct(sg,4);
        si res1>res2 {l'equipe 1 est gagnante}
              init_struct(sh, [struct(sh,1), struct(sg,1),0,0]);
        FINSI;

        SI res1= res2 {le match est nul, affectuer un tirage au sort}
           alea:= aleanombre(2);
           si alea= 1 {l'equipe 1 est gagnante}
              init_struct(sh, [struct(sh,1), struct(sg,1),0,0]);
           sinon {l'equipe 2 est gagnante}
              init_struct(sh, [struct(sh,2), struct(sg,2),0,0]);
           Finsi;
        FINSI;

             si res1<res2 {l'equipe 2 est gagnante}
                init_struct(sh, [struct(sh,2), struct(sg,2),0,0]);
             FINSI;
        sg:= info(fg(p));
        res1:= struct(sg, 3);
        res2:= struct(sg,4);
        si res1>res2 {l'equipe 1 est gagnante}
              init_struct(sh, [struct(sg,1), struct(sh,2),0,0]);
             FINSI;

             SI res1= res2 {le match est nul, affectuer un tirage au sort}
                alea:= aleanombre(2);
                si alea= 1 {l'equipe 1 est gagnante}
                   init_struct(sh, [struct(sg,1), struct(sh,2),0,0]);
                sinon {l'equipe 2 est gagnante}
                      init_struct(sh, [struct(sg,2), struct(sh,2),0,0]);
                Finsi;
             FINSI;

             si res1<res2 {l'equipe 2 est gagnante}
                init_struct(sh, [struct(sg,2), struct(sh,2),0,0]);
             FINSI;
             appel eqfavresph12(sh, tab_eq_rep, tab_eq_totbuts, ch);
             aff_info(p,sh);
        i:= i+1;
     FTQ;
FIN
action eqfavresph12(sh, tab_eq_rep, tab_eq_totbuts,ch)
soient
      tab_eq_rep un vecteur(32) de entier;
      tab_eq_totbuts un vecteur (32) de entier;
      sh une structure (entier, entier, entier, entier);
      eq1,eq2,res1,res2, buts1,buts2,rep1,rep2 un entier;
      ch un entier;
DEBUT
          eq1:= struct(sh,1);
          eq2:= struct(sh,2);
          rep1:= element(tab_eq_rep[eq1]);
          rep2:= element(tab_eq_rep[eq2]);
          buts1:= element(tab_eq_totbuts[eq1]);
          buts2:= element(tab_eq_totbuts[eq2]);
          si (rep1-rep2>=5)   /*l'equipe1 doit gagner*/
                  Res1 := ALEANOMBRE ( 10) ;
                  Res2 := ALEANOMBRE ( 10) ;
                  tq res1< res2
                     Res1 := ALEANOMBRE ( 10) ;
                     Res2 := ALEANOMBRE ( 10) ;
                  FTQ;
               FINSI;
               si rep1-rep2 <5
                  si rep1-rep2>=0
                     si buts1>buts2
                     /*l'equipe1 doit gagner*/
                         Res1 := ALEANOMBRE ( 10) ;
                         Res2 := ALEANOMBRE ( 10) ;
                         tq res1< res2
                            Res1 := ALEANOMBRE ( 10) ;
                            Res2 := ALEANOMBRE ( 10) ;
                         FTQ;
                     FINSI;
                     si buts1<buts2
                        Res1 := ALEANOMBRE ( 10) ;
                        Res2 := ALEANOMBRE ( 10) ;
                        tq res2< res1
                           Res1 := ALEANOMBRE ( 10) ;
                           Res2 := ALEANOMBRE ( 10) ;
                        FTQ;
                     FINSI;
                     si buts1=buts2
                        Res1 := ALEANOMBRE ( 10) ;
                        Res2 := ALEANOMBRE ( 10) ;
                        tq res1<> res2
                           Res1 := ALEANOMBRE ( 10) ;
                           Res2 := ALEANOMBRE ( 10) ;
                        FTQ;
                     FINSI;
                  FINSI;
               FINSI;
               si rep2-rep1> 5 /*l'equipe2 doit gagner*/
                  Res1 := ALEANOMBRE ( 10) ;
                  Res2 := ALEANOMBRE ( 10) ;
                  tq res2< res1
                     Res1 := ALEANOMBRE ( 10) ;
                     Res2 := ALEANOMBRE ( 10) ;
                  FTQ;
               FINSI;
               si rep2-rep1<5
                  si rep2-rep1>=0
                     si buts1>buts2
                     /*l'equipe1 doit gagner*/
                         Res1 := ALEANOMBRE ( 10) ;
                         Res2 := ALEANOMBRE ( 10) ;
                         tq res1< res2
                            Res1 := ALEANOMBRE ( 10) ;
                            Res2 := ALEANOMBRE ( 10) ;
                         FTQ;
                     FINSI;
                     si buts1<buts2
                        Res1 := ALEANOMBRE ( 10) ;
                        Res2 := ALEANOMBRE ( 10) ;
                        tq res2< res1
                           Res1 := ALEANOMBRE ( 10) ;
                           Res2 := ALEANOMBRE ( 10) ;
                        FTQ;
                     FINSI;
                     si buts1=buts2
                        Res1 := ALEANOMBRE ( 10) ;
                        Res2 := ALEANOMBRE ( 10) ;
                        tq res1<> res2
                           Res1 := ALEANOMBRE ( 10) ;
                           Res2 := ALEANOMBRE ( 10) ;
                        FTQ;
                     FINSI;
                  FINSI;
               FINSI;
               INIT_STRUCT ( Sh , [ Eq1 , Eq2 , Res1 , Res2 ] ) ;
               si ch=1
                  buts1:= buts1+res1;
                  aff_element(tab_eq_totbuts[eq1], buts1);
                  buts2:= buts2+res2;
                  aff_element(tab_eq_totbuts[eq2], buts2);
               FINSI;
FIN

action eqgafnfin(arb_match, eqg)
soient
       arb_match un arb de (entier, entier, entier, entier);
       eqg un entier;
       sg une structure (entier, entier, entier, entier);
       alea un entier;
DEBUT
     sg:= info(arb_match);
     si struct(sg,3)> struct(sg,4) {l'equipe 1 est gagnante}
        eqg:= struct(sg,1);
     FINSI;
     si struct(sg,3)< struct(sg,4)
        eqg:= struct(sg,2);
     FINSI;
     si struct(sg,3)= struct(sg,4) {le match est nul, affectuer un tirage au sort}
        alea:= aleanombre(2);
        si alea= 1 {l'equipe 1 est gagnante}
           eqg:= struct(sg,1);
        sinon {l'equipe 2 est gagnante}
           eqg:= struct(sg,2);
        Finsi;
     FINSI;
FIN

action creer_tabeqnom(tab_eq_nom)
soient
      tab_eq_nom un vecteur(32) de chaine;
DEBUT
     aff_element(tab_eq_nom[1], 'QAT'); aff_element(tab_eq_nom[2], 'ECU');
     aff_element(tab_eq_nom[3], 'SNG'); aff_element(tab_eq_nom[4], 'NLD');
     aff_element(tab_eq_nom[5], 'ENG'); aff_element(tab_eq_nom[6], 'IRN');
     aff_element(tab_eq_nom[7], 'USA'); aff_element(tab_eq_nom[8], 'WAL');
     aff_element(tab_eq_nom[9], 'ARG'); aff_element(tab_eq_nom[10], 'SAU');
     aff_element(tab_eq_nom[11], 'MXO'); aff_element(tab_eq_nom[12], 'POL');
     aff_element(tab_eq_nom[13], 'FRA'); aff_element(tab_eq_nom[14], 'DAN');
     aff_element(tab_eq_nom[15], 'TUN'); aff_element(tab_eq_nom[16], 'UKR');
     aff_element(tab_eq_nom[17], 'ESP'); aff_element(tab_eq_nom[18], 'GER');
     aff_element(tab_eq_nom[19], 'JAP'); aff_element(tab_eq_nom[20], 'AUS');
     aff_element(tab_eq_nom[21], 'BEL'); aff_element(tab_eq_nom[22], 'CAN');
     aff_element(tab_eq_nom[23], 'MAR'); aff_element(tab_eq_nom[24], 'HRV');
     aff_element(tab_eq_nom[25], 'BRA'); aff_element(tab_eq_nom[26], 'SRB');
     aff_element(tab_eq_nom[27], 'CHE'); aff_element(tab_eq_nom[28], 'CMR');
     aff_element(tab_eq_nom[29], 'PRT'); aff_element(tab_eq_nom[30], 'GHA');
     aff_element(tab_eq_nom[31], 'URY'); aff_element(tab_eq_nom[32], 'KOR');

FIN
action ideq(nomeq, id, tab_eq_nom)
soient
      nomeq une chaine;
      id un entier;
      tab_eq_nom un vecteur(32) de chaine;
DEBUT
     id:=1;
     TQ nomeq<> element(tab_eq_nom[id])
        id:= id+1;
     FTQ;
FIN

action affichage_phase1(tab_grpmatch, tab_eq_nom, tab_eq_pts)
soient
      Tab_grpmatch UN VECTEUR ( 8 ) DE LISTE DE ( ENTIER , ENTIER , ENTIER , ENTIER ) ;
      p un pointeur vers une LISTE DE ( ENTIER , ENTIER , ENTIER , ENTIER ) ;
      tab_eq_nom un vecteur(32) de chaine;
      tab_eq_pts un vecteur(32) de entier;
      T UN VECTEUR ( 4 ) DE ENTIER ;
      sg une structure ( ENTIER , ENTIER , ENTIER , ENTIER ) ;
      i,j,k,l,pos,pts,maxi un entier;
      eq1, eq2,eq une chaine;
DEBUT
     pour i:=1,8
          p:= element(tab_grpmatch[i]);
          ecrire('#======================Groupe',i,'======================#');
          TQ p<> nil
            sg:= valeur(p);
            eq1:= element(tab_eq_nom[struct(sg,1)]);
            eq2:= element(tab_eq_nom[struct(sg,2)]);
            ecrire('   ',eq1,'   ',struct(sg,3),'   ',struct(sg,4), '   ',eq2,'   ');
            p:= suivant(p);
          FTQ;
     FINPOUR;
      POUR I := 1 , 8
           ecrire('#======================Groupe',i,'======================#');
           K := ( I - 1 ) * 3 + I ;
           J := K ;
           L := 1 ;
           TQ J <= K + 3
               Pts := ELEMENT ( Tab_eq_pts [ J ] ) ;
               AFF_ELEMENT ( T [ L ] , Pts ) ;
               J := J + 1 ;
               L := L + 1 ;

           FTQ ;
           pos:= 1;
           Maxi := 0 ;
           POUR L := 1 , 4
               Pts := ELEMENT ( T [ L ] ) ;
               SI Pts > Maxi
                   Maxi := Pts ;
                   Pos := L ;

               FINSI ;

           FINPOUR ;
           pos:= k+pos -1;
           eq:= element(tab_eq_nom[pos]);
           ecrire(eq, '   ',maxi);
           AFF_ELEMENT ( T [ Pos - K + 1 ] , 0 ) ;
           pos:= 1;
           Maxi := 0 ;
           POUR L := 1 , 4
               Pts := ELEMENT ( T [ L ] ) ;
               SI Pts > Maxi
                   Maxi := Pts ;
                   Pos := L ;

               FINSI ;

           FINPOUR ;

           Pos := K + Pos - 1 ;
           eq:= element(tab_eq_nom[pos]);
           ecrire(eq, '   ',maxi);
           AFF_ELEMENT ( T [ Pos - K + 1 ] , 0 ) ;
           pos:= 1;
           Maxi := 0 ;
           POUR L := 1 , 4
               Pts := ELEMENT ( T [ L ] ) ;
               SI Pts > Maxi
                   Maxi := Pts ;
                   Pos := L ;

               FINSI ;

           FINPOUR ;
           Pos := K + Pos - 1 ;
           eq:= element(tab_eq_nom[pos]);
           ecrire(eq, '   ',maxi);
           AFF_ELEMENT ( T [ Pos - K + 1 ] , 0 ) ;
           pos:= 1;
           Maxi := 0 ;
           POUR L := 1 , 4
               Pts := ELEMENT ( T [ L ] ) ;
               SI Pts > Maxi
                   Maxi := Pts ;
                   Pos := L ;

               FINSI ;

           FINPOUR ;
           Pos := K + Pos - 1 ;
           eq:= element(tab_eq_nom[pos]);
           ecrire(eq, '   ',maxi);
       FINPOUR ;

FIN
action affichage_phase2(arb_match, tab_eq_nom)
soient
      arb_match un arb de (entier, entier, entier, entier);
      tab_eq_nom un vecteur(32) de chaine;
      pi une pile de arb de  (entier, entier, entier, entier);
      p un pointeur vers un arb de  (entier, entier, entier, entier);
      sg une structure (entier, entier, entier, entier);
      eq1,eq2 une chaine;
      i un entier;
debut
     ecrire('#------------------------#');
     ecrire('l''arbre de tournoi');
     ecrire('#------------------------#');
     appel parlarginv(arb_match, pi);
     pour i:=1,8
        depiler(pi,p);
        sg:= info(p);
        eq1:= element(tab_eq_nom[struct(sg,1)]);
        eq2:= element(tab_eq_nom[struct(sg,2)]);
        ecrire(eq1, struct(sg,3), struct(sg,4), eq2);
    FINPOUR;
    ecrire('#------------------------#');
    pour i:=1,4
         depiler(pi,p);
        sg:= info(p);
        eq1:= element(tab_eq_nom[struct(sg,1)]);
        eq2:= element(tab_eq_nom[struct(sg,2)]);
        ecrire(eq1, struct(sg,3), struct(sg,4), eq2);
    FINPOUR;
    ecrire('#------------------------#');
    pour i:=1,2
         depiler(pi,p);
        sg:= info(p);
        eq1:= element(tab_eq_nom[struct(sg,1)]);
        eq2:= element(tab_eq_nom[struct(sg,2)]);
        ecrire(eq1, struct(sg,3), struct(sg,4), eq2);
    FINPOUR;
    ecrire('#------------------------#');
    depiler(pi,p);
        sg:= info(p);
        eq1:= element(tab_eq_nom[struct(sg,1)]);
        eq2:= element(tab_eq_nom[struct(sg,2)]);
        ecrire(eq1, struct(sg,3), struct(sg,4), eq2);

FIN


