inherit "room/room";
 
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/salesman");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("west","wizards/nalle/jerusalem/armc2");
  add_exit("south","wizards/nalle/jerusalem/armb3");
  short_desc = "The Hart El-Yahud. Northern part.";
  long_desc =
"This is northern part of the Hart El-Yahud, the so called\n" +
"Jewish section of the Armenian quarter. Despite the name\n" +
"'Armenian Quarter' a good number of Jews inhabit this\n" +           
"part of Jerusalem, almost half of the houses are owned\n" +
"by Jews. The Hart El-Yahud being the better side of the\n" +
"Armenian quarter all the houses look more or less neat\n";
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


