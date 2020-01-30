#include "room.h" 
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object monster;
 
extra_reset() {
    set_not_out(3);
 
    if (!monster) {
        monster = clone_object("/wizards/walla/chessboard/monsters/wtower");
        move_object(monster, this_object());
    }
}
 
THREE_EXIT("wizards/walla/chessboard/17", "west",
         "wizards/walla/chessboard/27","southwest",
         "wizards/walla/chessboard/28", "south",
         "On a black square in the chessboard",
         "You are on a black square of the chessboard.\n" +
         "This is the white tower's place. \n", 3)
