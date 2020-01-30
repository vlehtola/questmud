#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET\
        set_not_out(1);
 
int barrel_moved,panel_open;
 
init() {
  ::init();
  add_action("move", "move");
  add_action("knock", "knock");
  add_action("close", "close");
  add_action("enter", "enter");
}
 close(str) {
  if(str == "panel") {
    if(panel_open) {
      write("You close the hole in the wall.\n");
      say(this_player()->query_name()+" closes the panel.\n");
      panel_open = 0;
      return 1;
    } else {
      write("It's already closed.\n");
      return 1;
    }
  }
}
 
enter(str) {
if(panel_open) {   
    write("You enter through the wall, but accidentaly step on a button that triggers a closing mechanism.\n");
    say(this_player()->query_name()+" enters through the wall, and the wall closes "+
        "behind him.\n");
    panel_open = 0;
    move_object(this_player(), "/wizards/walla/jericho/rooms/mcellar/2");
    say(this_player()->query_name()+" enters through the wall.\n");
    return 1;
  }
}
 
knock(str) {
  if(barrel_moved) {
    write("You knock three times on the wall, and to your surprise, it slides open.\n");
    panel_open = 1;
    return 1;
   }
}
 
long(str) {
  ::long(str);
  if(str == "wall") {
    if(panel_open) {
      write("A portion of the wall has moved to one side, and has left a gap, that one could "+
            "enter, to get to the other side.\n");
      return 1;
    } else {
      write("You see nothing special.\n");
      return 1;
    }
  }
  if(str == "wall") {
    if(barrel_moved) {  
      write("A wooden wall, with markings on one spot.\n");
      return 1;
    } else {
      write("say what?\n");
      return 1;
    }
  }
  if(str == "barrel") {
    if(barrel_moved) {
      write("The barrel was hiding a portion of the wall, which has some "+
            "markings on it. They almost seem like knuckle marks.\n");
      return 1;
    } else {
      write("There seems to be some sort peculiarity with the wall behind "+
            "the barrel. Maybe you could move it.\n");
return 1;
    }
  }
}
 
id(str) {
  if(str == "panel") { return 1; }
  if(str == "barrel") { return 1; }
}
 
move(str) {
  if(str == "barrel") {
    if (barrel_moved) { replace("panel"); return 1; }
    write("You move the barrel, and get a better look at the peculiar wall.\n");
    say(capitalize(this_player()->query_name())+" moves the barrel, and gets a closer "+
            "look of the wall.\n");
    barrel_moved = 1;
    return 1;
  }
}
 
 replace(str) {
  if(str == "panel") {
    if (barrel_moved) {
      write("You put the barrel back to where you found it.\n");
      say(capitalize(this_player()->query_name())+ " moves the barrel back to where "+
          "it was.\n");
      barrel_moved = 0;
      return 1;
    } else {
      write("The barrel is already in its right place.\n");
      return 1;
    }
  }
}
 
 ONE_EXIT( "/wizards/walla/jericho/rooms/mosque2", "up",
           "In the cellar",
           "You are standing in the cellar of the mosque. It seems like\n" +
           "a completely normal cellar, although you have to wonder why\n" +
           "it was so heavily guarded. Some barrels by the far wall \n" +
           "catch your attention. \n", 2)
 
