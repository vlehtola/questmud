#include "room.h" 
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object monster;
 
extra_reset() {
    set_not_out(3);
 
    if (!monster) {
        monster = clone_object("/wizards/walla/chessboard/monsters/bknight");
        move_object(monster, this_object());
    }
}
 
FIVE_EXIT("wizards/walla/chessboard/81", "west",
         "wizards/walla/chessboard/83","east",
         "wizards/walla/chessboard/72", "north",
         "wizards/walla/chessboard/71", "northwest",          
         "wizards/walla/chessboard/73","northeast",
         "On a white square in the chessboard",
         "You are on a white square of the chessboard.\n" +
         "This is the black knight's place. \n", 3)




