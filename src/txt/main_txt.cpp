#include "AffichageTXT.h"
#include "txtJeu.h"

int main ( int argc, char** argv ) {
    termClear();
	World wor;
	txtBoucle(wor);
  wor.~World();
    termClear();
	return 0;
}
