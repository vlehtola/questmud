inherit "room/room";
 
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/armwoman");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","wizards/nalle/jerusalem/armb1");
  add_exit("east","wizards/nalle/jerusalem/arma2");
  short_desc = "South-western part of the Armenian Quarter";
  long_desc =
"This is south-western part of the Armenian quarter of \n" +
"Jerusalem. This is a poor residential area, but the people\n" +
"here are at least better of then their neighbours living\n" +           
"a few blocks to the east, amongst all the brothels and\n" +
"worst criminals.\n";
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


