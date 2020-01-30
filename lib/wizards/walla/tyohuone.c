#include "room.h"
 
#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();
 
object monster,monster2,monster3;
 
extra_reset() {
    items = allocate(2);
    items[0] = "stairway";
    items[1] = "All you can see is darkness";
    if (!monster) {
        monster = clone_object("/wizards/walla/hujee/testi/janina");
        move_object(monster, this_object());
    }
    if (!monster2) {
        monster2 = clone_object("/wizards/walla/linda");
        move_object(monster2, this_object());
    }
if (!monster3) {
        monster3 = clone_object("/wizards/walla/mariah");
        move_object(monster3, this_object());
    }
 
}
 
EIGHT_EXIT("world/city/inn", "inn",
         "wizards/walla/chessboard/hut", "chess",
         "wizards/walla/workroom2", "next",
         "wizards/walla/area/cs","jercs",
         "wizards/walla/area/cem23","lebi",
         "wizards/shadow/shortban","irmeli",
 "wizards/walla/strahd/tpath","strahdpath",
         "wizards/walla/kkk/entrance","kkk",
"Walla's Room of Justice",
         "|------i   |    /-----i  /-----i     /-----i  |------ |----- \n" +
         "|      |   |    |        |          |       | |       |      \n" +
         "|------/   |    i-----i  i-----i    |       | |---    |----  \n" +
         "|          |          |        |    |       | |       |      \n" +
         "|          |    i-----/  i-----/     i-----/  |       |      \n", 3)
 
 
