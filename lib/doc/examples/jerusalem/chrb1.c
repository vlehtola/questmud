inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/salesman");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","wizards/nalle/jerusalem/chrc1");
  add_exit("east","wizards/nalle/jerusalem/chrb2");
  add_exit("south","wizards/nalle/jerusalem/chra1");
  short_desc = "Western part of the Christian quarter";
  long_desc =
"This is the western part of the Christian quarter of the city of\n" +
"Jerusalem. There is a lid leading to the sewage system of Jerusalem\n" +
"that you might be able to enter, if only you would open the lid of\n" + 
"course. The houses in this area are look like they are meant \n" +
"for salesmen, and for exercising commercial activities in general.\n" +
"There roads here lead to the south, the north and to the west. There\n" +
"are quite many people here.\n";
}

init() {
    ::init();
   add_action("map", "map");
   add_action("open", "open");
}

open(str) {
  if(str == "lid") {
  say(this_player()->query_name()+" opens the lid of the entry to the sewers and jumps down into the darkness.\n");
  write("You open the lid and enter the sewers.\n");
  move_object(this_player(), "/wizards/nalle/jerusalem/sewa1.c");
  say(this_player()->query_name()+" descends a ladder that leads to the christian quarter.\n");
  return 1;
  }
    return 1;
}

map(arg) {
    if (arg) {
        return 0;
    }
   cat("/wizards/nalle/jerusalem/cmap");
   return 1;
}

