inherit "room/room";
 
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/walla/jerusalem/monsters/zephaniah");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","wizards/nalle/jerusalem/vd2");
  add_exit("west","wizards/walla/jerusalem/armenia/12");
  add_exit("south","wizards/walla/jerusalem/armenia/23");
  short_desc = "Rabbath-Ammon, the mainway";
  long_desc =
"This is Rabbath-Ammon. This road, which curves like a\n" +
"snake between the houses, is named after the armenian\n" +
 "settlement of Rabbath-Ammon, situated in the arabic\n" +           
"peninsula. The road twitches forward and the streets are\n" +
"really narrow, with clothes hung on ropes above you.\n";
}
 
init() {
    ::init();
   add_action("map", "map");
}
 
map(arg) {
    if (arg) {
        return 0;
    }
   cat("/wizards/nalle/jerusalem/map");
   return 1;
}   


