inherit "room/room";
 
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/armwoman");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","wizards/nalle/jerusalem/armc3");
  add_exit("west","wizards/nalle/jerusalem/armb2");
  add_exit("south","wizards/nalle/jerusalem/arma3");
  add_exit("enter","wizards/nalle/jerusalem/zephouse");
  short_desc = "The Hart El-Yahud. Central part.";
  long_desc =
"This is central part of the Hart El-Yahud, the so called\n" +
"Jewish section of the Armenian quarter, which covers most\n" +
"of the eastern part of the Armenian quarter. This part of\n" +           
"the town seems a bit wealthir then the western part, and\n" +
"really narrow, with clothes hung on ropes above you.\n" +
"there are not all that many beggars here\n";
}
 
init() {
    ::init();
   add_action("map", "map");
}
 
map(arg) {
    if (arg) {
        return 0;
    }
   cat("/wizards/nalle/jerusalem/amap");
   return 1;
}   


