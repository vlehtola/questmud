inherit "room/room";
 
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/beggar");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","wizards/nalle/jerusalem/armc2");
  add_exit("west","wizards/nalle/jerusalem/armb1");
  add_exit("east","wizards/nalle/jerusalem/armb3");
  add_exit("south","wizards/nalle/jerusalem/arma2");
  short_desc = "Central part of the Armenian Quarter";
  long_desc =
"This is central part of the Armenian Quarter of Jerusalem.\n" +
"This does not look like a very pleasant environment to live\n" +
"in, there is on sanitation and the people here do not look\n" +           
"very kind, to say the least. The extreme financial conditions\n" +
"have driven a good percentage of the inhabitants of this part\n" +
"of the town to crime or prostitution.\n";
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


