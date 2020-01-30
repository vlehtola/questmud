#include "room.h" 
#undef EXTRA_RESET
#define EXTRA_RESET\
        set_not_out(1);
 
int lever_pulled, box_open;
 
init() {
  add_action("open", "open");
  add_action("pull", "draw");
  add_action("pull", "pull");
  add_action("open", "kick");
  add_action("jump", "jump");
  add_action("close", "close");
  ::init();
}
close(str) {
  if(str == "box") {
    if(box_open) {
      write("You carefully close the box.\n");
      say(this_player()->query_name()+" carefully closes the red box.\n");
      boxe_open = 0;
      return 1;
    } else {
      write("It's already closed.\n");
      return 1;
    }
  }
}
 
pull(str) {
            
  if(box_open) {
    write("You pull the lever and something happens to you.\n");
    say(this_player()->query_name()+" pulls the lever and dissapears leaving a puff of smoke behind "+
        "him.\n");
    box_open = 0;
    move_object(this_player(), "/wizards/walla/strahd/entrance");
    say(this_player()->query_name()+" just suddenly is there.\n");
    return 1;
  }
}
 
open(str) {
  if(box_found) {
    write("You open the box, and see a red lever in it.\n");
    boxe_open = 1;
    return 1;
  }
}
 
long(str) {
  ::long(str);
  if(str == "lever") {
    if(box_open) {
      write("A big, red lever which has a note, saying : 'Don't Touch ! "+
            "Maybe you should'nt.\n");
      return 1;
    } else {
      write("You see nothing special.\n");
      return 1;
    }
  }
  if(str == "box") {
 if(box_found) {   
      write("A red box, with inscriptions on it.\n");
      return 1;
    } else {
      write("You see nothing special.\n");
      return 1;
    }
  }
  if(str == "handle") {
    if(box_found) {
      write("This is a handle. "+
            "It's rusty, but one could still open the box with it.\n");
      return 1;
    } else {
      write("You see nothing special.\n");
      return 1;
    }
  }
  if(str == "box" || str == "sand") {
    if(box_found) {
      write("The box used to be sealed, but now, do you think "+
            "you would be able to reseal it.\n");
      return 1;
    } else {
      write("The room looks pretty normal, except for that big red box on the wall.\n");
      return 1;
    }
  }
}
 
id(str) {
  if(str == "box") { return 1; }
 if(str == "handle") { return 1; }                 
  if(str == "lever") { return 1; }
  if(str == "dust" || str == "rocks") { return 1; }
}
 
open(str) {
  if(str == "box" || str == "sand") {
    if (box_found) { hide("box"); return 1; }
    write("You blow the dust away and discover to your surprise ... a manhole.\n");
    say(capitalize(this_player()->query_name())+" gently blows the dust away only to reveal "+
            "a manhole under it.\n");
    dust_blown = 1;
    return 1;
  }
}
 
 hide(str) {
  if(str == "box") {
    if (box_found) {
      write("You seal the box again, with the guards intestins as seal.\n");
      say(capitalize(this_player()->query_name())+ " seals the box with some intestins "+
          "from the corpse of the guard.\n");
      box_found = 0;
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
