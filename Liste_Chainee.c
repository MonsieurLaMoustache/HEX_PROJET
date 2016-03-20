#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>

#include "Liste_Chainee.h"

struct cellule_s {
  void * data;
  size_t size;
  struct cellule_s * prev;
  struct cellule_s * next;
};

struct liste_s {
  struct cellule_s * head;
  struct cellule_s * tail;
};

LISTE * InitListe( void ){
  LISTE * l = malloc( sizeof( LISTE ) );
  l->head = NULL;
  l->tail = NULL;
  return l;
}

bool Empty( const LISTE * l ){
  return l->head == NULL;
}

void PushFront( LISTE * l, void * data, size_t size ){
  struct cellule_s * cell = malloc( sizeof( struct cellule_s ) );
  cell->size = size;
  memcpy( cell->data, data, size );

  if( Empty( l ) ){
    cell->prev = NULL;
    cell->next = NULL;
    l->head = cell;
    l->tail = cell;
  }
  else{
    cell->prev = NULL;
    cell->next = l->head;
    (l->head)->prev = cell;
    l->head = cell;
  }
}
