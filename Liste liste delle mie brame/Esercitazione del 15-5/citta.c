#define _GNU_SOURCE   // permette di usare estensioni GNU
#include <stdio.h>    // permette di usare scanf printf
#include <stdlib.h>   // conversioni stringa/numero rand() abs() exit() etc ...
#include <stdbool.h>  // gestisce tipo bool (per variabili booleane)
#include <assert.h>   // permette di usare la funzione assert
#include <string.h>   // permette di usare le funzioni per le stringhe strlen, strcmp
#include <math.h>     // permette di usare sin cos e altre funzioni matematiche avanzate
#include "coordinate.h"
#include "citta.h"

// ------- oggetto citta e funzioni per la sua manipolazione -------------
void stampa_citta(citta *c, FILE *f)
{
  fprintf(f,"%s: ", c->nome);
  stampa_coordinate(c->coord,f);
}

// confronta a e b restituendo -1 se a e' piu' a nord di b
int piuanord(citta *a, citta *b)
{
  return latitudinepiuanord(a->coord,b->coord);
}

// confronta a e b restituendo -1 se a e' piu' vicina ad Alessandria di b
int vicinoAL(citta *a, citta *b)
{
  coordinate upo;
  upo.lat = 44.922667;
  upo.lon = 8.616993;
  double a_dist = distanza(a->coord,upo);
  double b_dist = distanza(b->coord,upo);
  if(a_dist<b_dist) return -1;
  if(a_dist>b_dist) return 1;
  return 0;
}

// confronta a e b restituendo -1 se a e' piu' vicina ad Alessandria di b
int vicino_citta(citta *a, citta *b, citta* citta)
{
 
  double a_dist = distanza(a->coord,citta->coord);
  double b_dist = distanza(b->coord,citta->coord);
  if(a_dist<b_dist) return -1;
  if(a_dist>b_dist) return 1;
  return 0;
}

