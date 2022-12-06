#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <allegro.h>
#include "fichier.h"

int main()
{
    srand(time(NULL));
    allegro_init();
    install_keyboard();
    install_mouse();
    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,1020,768,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    Menu(); ///Appel du menu
    return 0;
}

END_OF_MAIN();
