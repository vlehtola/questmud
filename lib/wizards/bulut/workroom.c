#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
int x;
int rock_lifted;
int panel_open;


init() {
  add_action("lift", "move");
  add_action("lift", "lift");
 add_action("close", "close");

  ::init();

}

close(str) {
  if(str == "panel") {
    if(panel_open) {
      write("You close the panel.\n");
      say(this_player()->query_name()+" closes the panel.\n");
      panel_open = 0;
      return 1;
      remove_exit("east");
    } else {
      write("It's already closed.\n");
      return 1;
    }
  }
}

lift(arg) {
    write("You open the panel and discover a salainen paikka eastiin.\n");
    panel_open = 1;
    return 1;
    add_exit("east");
}

extra_reset() {
move_object("wizards/bulut/jukebox.c", this_object());
}

TWO_EXIT("/world/city/cs","cs",
"/wizards/bulut/forl/road1","forest",
"kissa",
"onse... seon\n",3)
