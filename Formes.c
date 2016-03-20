#include "Formes.h"
#include <SDL/SLD.h>


struct zone_s {
  int Taille; // Taille de la zone.
};

struct carre_s {
  SDL_Rect taille; // Taille du carré ( h, w ).
  float angle; // Angle de rotation du carré.
};

struct cercle_s {
  int rayon; // rayon du cerle.
};

struct geometrie_s {
  int type;
  union{
    struct zone_s zone; // type 0
    struct carre_s carre; // type 1
    struct cercle_s cerle; // type 2
  };
};

struct operation_s {
  int operation;  // L'operation effectuée ( ADD == 0, SUB == 1 ).
  SDL_Rect position; // la position ou sera effectuée l'operation ( x, y );
  struct geometrie_s geometrie; // La geometrie concernée;
};
