
#include "room.h" 
#undef EXTRA_RESET
#define EXTRA_RESET\
        set_not_out(1);
 
int box_found, box_open;
 
init() {
  add_action("search", "search");
  add_action("pull", "pull");
  add_action("open", "open");
  add_action("pull", "draw");
  add_action("search", "kick");
  add_action("close", "close");
  ::init();
}
close(str) {
  if(str == "box") {
    if(box_open) {
      write("You close the box.\n");
      say(this_player()->query_name()+" closes the box.\n");
      box_open = 0;
      return 1;
    } else {
      write("It's already closed.\n");
      return 1;
    }
  }
}
 
pull(str) {
            
  if(box_open) {
    write("You pull the lever and go away.\n");
    say(this_player()->query_name()+" jumps in a hole and the lid closes behind "+
        "it.\n");
    box_open = 0;
    move_object(this_player(), "/wizards/walla/strahd/mpath");
    say(this_player()->query_name()+" falls out of the air.\n");
    return 1;
  }
}
 
open(str) {
  if(box_found) {
    write("You open the box and jee.\n");
    box_open = 1;
    return 1;
  }
}
 
long(str) {
  ::long(str);
  if(str == "box") {
    if(box_open) {
      write("A BOX, JEE, this is actually a  "+
            "BOX, A FUCKING ASSHOLE BOX.\n");
      return 1;
    } else {
      write("You see nothing special.\n");
      return 1;
    }
  }
  if(str == "lever") {
 if(box_open) {   
      write("A fucking LEVER.\n");
      return 1;
    } else {
      write("You see nothing special.\n");
      return 1;
    }
  }
  if(str == "handle") {
    if(box_found) {
      write("This is a handle. "+
            "It's rusty, but one could still open the FUCKING BOX with it.\n");
      return 1;
    } else {
      write("You see nothing special.\n");
      return 1;
    }
  }
  if(str == "box" || str == "sand") {
    if(box_found) {
      write("The Box is now found"+
            "Close it again, think of something, SCHMUCK.\n");
      return 1;
    } else {
      write("Just dust, and wait a minute, it looks like there is something under it.\n");
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
 
search(str) {
  if(str == "box" || str == "sand") {
    if (box_found) { hide("box"); return 1; }
    write("You blow the dust away and discover to your surprise ... a manhole.\n");
    say(capitalize(this_player()->query_name())+" gently blows the dust away only to reveal "+
            "a manhole under it.\n");
    box_found = 1;
    return 1;
  }
}
 
 hide(str) {
  if(str == "box") {
    if (box_found) {
      write("You hide the hole and push the dust back.\n");
      say(capitalize(this_player()->query_name())+ " quickly puts the dust back "+
          "from where it came.\n");
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

 
