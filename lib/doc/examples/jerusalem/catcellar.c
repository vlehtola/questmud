#include "room.h"

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/blmonk");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","/wizards/nalle/jerusalem/catcellar2");
  add_exit("up","/wizards/nalle/jerusalem/catb7");
  short_desc = "The wine cellar";
  long_desc =
 "You are in a large room lit by torches. The smell of fermenting\n"+
 "wine is obvious. There are many barrels to your north, and the\n"+
 "same staircase you took down, leads back up.\n";
}
