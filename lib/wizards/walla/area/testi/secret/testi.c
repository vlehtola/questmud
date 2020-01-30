#include "room.h" 
#undef EXTRA_RESET
#define EXTRA_RESET\
        set_not_out(1);
 
int dust_blown, manhole_open;
 
init() {
  add_action("blow", "move");
  add_action("blow", "blow");
  add_action("open", "open");
  add_action("eat", "kick");
  add_action("jump", "jump");
  add_action("close", "close");
  ::init();
}
close(str) {
  if(str == "manhole") {
    if(manhole_open) {
      write("You close the manhole.\n");
      say(this_player()->query_name()+" closes the manhole.\n");
      hole_open = 0;
      return 1;
    } else {
      write("It's already closed.\n");
      return 1;
    }
  }
}
 
jump(str) {
            
  if(manhole_open) {
    write("You jump down into the hole, and hear the lid slamming behind you.\n");
    say(this_player()->query_name()+" jumps in a hole and the lid closes behind "+
        "it.\n");
    manhole_open = 0;
    move_object(this_player(), "/wizards/walla/strahd/mpath");
    say(this_player()->query_name()+" falls out of the air.\n");
    return 1;
  }
}
 
open(str) {
  if(dust_blown) {
    write("You open the manhole and discover another big hole in it.\n");
    hole_open = 1;
    return 1;
  }
}
 
long(str) {
  ::long(str);
  if(str == "manhole") {
    if(manhole_open) {
      write("A big, dark, unexplored hole. It's very deep, but I think one could JUMP there to "+
            "get where it leads.\n");
      return 1;
    } else {
      write("You see nothing special.\n");
      return 1;
    }
  }
  if(str == "manhole") {
 if(dust_blown) {   
      write("A dirty manhole. A rusty handle is attached to it.\n");
      return 1;
    } else {
      write("You see nothing special.\n");
      return 1;
    }
  }
  if(str == "handle") {
    if(dust_blown) {
      write("This is a handle. "+
            "It's rusty, but one could still open the hole with it.\n");
      return 1;
    } else {
      write("You see nothing special.\n");
      return 1;
    }
  }
  if(str == "dust" || str == "sand") {
    if(dust_blown) {
      write("The dust covered that hole completly... "+
            "I think you should do it again!\n");
      return 1;
    } else {
      write("Just dust, and wait a minute, it looks like there is something under it.\n");
      return 1;
    }
  }
}
 
id(str) {
  if(str == "manhole") { return 1; }
 if(str == "handle") { return 1; }                 
  if(str == "hole") { return 1; }
  if(str == "dust" || str == "rocks") { return 1; }
}
 
blow(str) {
  if(str == "dust" || str == "sand") {
    if (dust_blown) { hide("manhole"); return 1; }
    write("You blow the dust away and discover to your surprise ... a manhole.\n");
    say(capitalize(this_player()->query_name())+" gently blows the dust away only to reveal "+
            "a manhole under it.\n");
    dust_blown = 1;
    return 1;
  }
}
 
 hide(str) {
  if(str == "hole") {
    if (dust_blown) {
      write("You hide the hole and push the dust back.\n");
      say(capitalize(this_player()->query_name())+ " quickly puts the dust back "+
          "from where it came.\n");
      tower_pushed = 0;
      return 1;
    } else {
      write("The manhole is now securely hidden. No one will know you went here.\n");
      return 1;
    }
  }
}
 
ONE_EXIT( "/wizards/walla/area/ispep-5", "east",
  "A dusty place",                         
           "It seems to have been a sandstorm here, because the ground is covered with dust.\n" +
           "To the east is Ispep Road, which is one of the mainstreets of Jericho.\n" +
           "This looks like some kind of Viewing Room.\n", 1)

