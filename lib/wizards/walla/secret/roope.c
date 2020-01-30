#include "room.h" 
#undef EXTRA_RESET
#define EXTRA_RESET\
        set_not_out(1);
 
int tower_pushed, hole_open;
 
init() {
  add_action("push", "move");
  add_action("push", "push");
  add_action("open", "open");
  add_action("push", "kick");
  add_action("jump", "jump");
  add_action("close", "close");
  ::init();
}
close(str) {
  if(str == "hole") {
    if(hole_open) {
      write("You close the hole.\n");
      say(this_player()->query_name()+" closes the hole.\n");
      hole_open = 0;
      return 1;
    } else {
      write("It's already closed.\n");
      return 1;
    }
  }
}
 
jump(str) {
            
  if(hole_open) {
    write("You jump down into the hole, and hear the lid slamming behind you.\n");
    say(this_player()->query_name()+" jumps in a hole and the lid closes behind "+
        "it.\n");
    hole_open = 0;
    move_object(this_player(), "/wizards/walla/strahd/mpath");
    say(this_player()->query_name()+" falls out of the air.\n");
    return 1;
  }
}
 
open(str) {
  if(tower_pushed) {
    write("You open the manhole and discover a big hole in it.\n");
    hole_open = 1;
    return 1;
  }
}
 
long(str) {
  ::long(str);
  if(str == "hole") {
    if(hole_open) {
      write("A little, dark, unexplored hole. It's very deep, but I think one could JUMP there to "+
            "get where it leads.\n");
      return 1;
    } else {
      write("You see nothing special.\n");
      return 1;
    }
  }
  if(str == "hole") {
 if(tower_pushed) {   
      write("A dirty manhole. A rusty handle is attached to it.\n");
      return 1;
    } else {
      write("You see nothing special.\n");
      return 1;
    }
  }
  if(str == "handle") {
    if(tower_pushed) {
      write("This is a handle. "+
            "It's rusty, but one could still open the hole with it.\n");
      return 1;
    } else {
      write("You see nothing special.\n");
      return 1;
    }
  }
  if(str == "tower" || str == "rocks") {
    if(tower_pushed) {
      write("The tower covered the hole making it almost unfindable.. "+
            "why couldn't it do it again?\n");
      return 1;
    } else {
      write("It looks like there is something unusual under one.\n");
      return 1;
    }
  }
}
 
id(str) {
  if(str == "hole") { return 1; }
 if(str == "handle") { return 1; }                 
  if(str == "hole") { return 1; }
  if(str == "tower" || str == "rocks") { return 1; }
}
 
push(str) {
  if(str == "tower" || str == "rocks") {
    if (tower_pushed) { hide("hole"); return 1; }
    write("You push the tower away and see a hole under it.\n");
    say(capitalize(this_player()->query_name())+" kicks the tower away with "+
            "great effort.\n");
    tower_pushed = 1;
    return 1;
  }
}
 
 hide(str) {
  if(str == "hole") {
    if (tower_pushed) {
      write("You hide the hole with a nearby rock.\n");
      say(capitalize(this_player()->query_name())+ " quickly hides something under "+
          "a rock.\n");
      tower_pushed = 0;
      return 1;
    } else {
      write("The hole is already hided.\n");
      return 1;
    }
  }
}
 
ONE_EXIT( "/wizards/walla/workroom", "home",
  "Dead end",                         
           "No light sources are nearby, making this place really dim.\n" +
           "Walls, ceiling and floor are all pure stone.\n" +
           "Some water drops on rocks making loud sounds.\n", 1)
