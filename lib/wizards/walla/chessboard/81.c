#include "room.h" 
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object monster;
 
extra_reset() {
    set_not_out(3);
 
    if (!monster) {
        monster = clone_object("/wizards/walla/chessboard/monsters/btower");
        move_object(monster, this_object());
    }
}
 
THREE_EXIT("wizards/walla/chessboard/82", "east",
         "wizards/walla/chessboard/72","northeast",
         "wizards/walla/chessboard/71", "north",
         "On a black square in the chessboard",
         "You are on a black square of the chessboard.\n" +
         "This is the black tower's place. \n", 3)
