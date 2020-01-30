inherit "room/room";

int giggle;

reset(arg) {
  if (giggle == 21) {
  remove_exit("down","wizards/nalle/jerusalem/armc1d.c");
  }
  if(arg) return;
  add_exit("south","wizards/nalle/jerusalem/armb1");
  add_exit("east","wizards/nalle/jerusalem/armc2");
  short_desc = "North-western part of the Armenian Quarter";
  long_desc =
"You are in the north-western part of the Armenian\n" +
"Quarter of Jerusalem. A small fountain has been mounted\n" +
"in the middle of this part of the town. The fountain is\n" +
"very nice and all, but there is no water coming out of it.\n";
}

init() {
    ::init();
   add_action("push", "push");
   add_action("map", "map");
}

push(str) {
 if (str != "pedestal") { return 0; }
 if (giggle == 21) { return 0; }
  giggle = 21;
  write("You firmly push the fountain's pedastal revealing a passage down.\n");
  say(this_player()->query_name()+" firmly pushes the fountain's base revealing a secret passage.\n"); 
  add_exit("down", "/wizards/nalle/jerusalem/armc1d.c");
  return 1;
}

map(arg) {
    if (arg) {
        return 0;
    }
   cat("/wizards/nalle/jerusalem/amap");
   return 1;
}
