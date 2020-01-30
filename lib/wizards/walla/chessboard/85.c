#include "room.h" 
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object monster;
 
extra_reset() {
    set_not_out(3);
 
    if (!monster) {
        monster = clone_object("/wizards/walla/chessboard/monsters/bqueen");
        move_object(monster, this_object());
    }
}
 
FIVE_EXIT("wizards/walla/chessboard/84", "west",
         "wizards/walla/chessboard/86","east",
         "wizards/walla/chessboard/75", "north",
         "wizards/walla/chessboard/74", "northwest",          
         "wizards/walla/chessboard/76","northeast",
         "On a white square in the chessboard",
         "You are on a white square of the chessboard.\n" +
         "This is the black queen's place. \n", 3)
