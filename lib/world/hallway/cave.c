#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET\
        set_not_out(1);

int rock_lifted, panel_open;

init() {
  add_action("lift", "move");
  add_action("lift", "lift");
  add_action("open", "open");
  add_action("hide", "hide");
  add_action("crawl", "crawl");
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
    } else {
      write("It's already closed.\n");
      return 1;
    }
  }
}

crawl(str) {
  if(panel_open) {
    write("You crawl down the tunnel and close the panel behind you.\n");
    say(this_player()->query_name()+" crawls in a hole and closes the panel covering "+
	"it.\n");
    panel_open = 0;
    move_object(this_player(), "/guilds/fighter/barbarian");
    say(this_player()->query_name()+" crawls out of the hole.\n");
    return 1;
  }
}

open(str) {
  if(rock_lifted) {
    write("You open the panel and discover a small hole behind it.\n");
    panel_open = 1;
    return 1;
  }
}

long(str) {
  ::long(str);
  if(str == "hole") {
    if(panel_open) {
      write("A little, dark, unexplored hole. It's so small that one should crawl to "+
	    "get through it.\n");
      return 1;
    } else {
      write("You see nothing special.\n");
      return 1;
    }
  }
  if(str == "panel") {
    if(rock_lifted) {
      write("A wooden panel. A rusty handle is attached to it.\n");
      return 1;
    } else {
      write("You see nothing special.\n");
      return 1;
    }
  }
  if(str == "handle") {
    if(rock_lifted) {
      write("This is a handle. "+
	    "It's rusty, but one could still open the panel with it.\n");
      return 1;
    } else {
      write("You see nothing special.\n");
      return 1;
    }
  }
  if(str == "rock" || str == "rocks") {
    if(rock_lifted) {
      write("One rock covered the panel making it almost unfindable.. "+
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
  if(str == "panel") { return 1; }
  if(str == "rock" || str == "rocks") { return 1; }
}

lift(str) {
  if(str == "rock" || str == "rocks") {
    if (rock_lifted) { hide("panel"); return 1; }
    write("You lift one rock up and see a panel under it.\n");
    say(capitalize(this_player()->query_name())+" lifts one rock up with "+
            "great effort.\n");
    rock_lifted = 1;
    return 1;
  }
}

hide(str) {
  if(str == "panel") {
    if (rock_lifted) {
      write("You hide the panel with a nearby rock.\n");
      say(capitalize(this_player()->query_name())+ " quickly hides something under "+
	  "a rock.\n");
      rock_lifted = 0;
      return 1;
    } else {
      write("The panel is already hided.\n");
      return 1;
    }
  }
}

ONE_EXIT(  "/world/hallway/hall3", "west",
     	   "Dead end",
	   "No light sources are nearby, making this place really dim.\n" +
	   "Walls, ceiling and floor are all pure stone.\n" +
	   "Some water drops on rocks making loud sounds.\n", 1)
