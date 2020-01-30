inherit "room/room";
 
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/armman");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","wizards/nalle/jerusalem/vd2");
  add_exit("west","wizards/nalle/jerusalem/armc1");
  add_exit("east","wizards/nalle/jerusalem/armc3");
  add_exit("south","wizards/nalle/jerusalem/armb2");
  short_desc = "Northern part of the Armenian Quarter";
  long_desc =
"You have arrived into the northern part of the Armenian\n" +
"Quarter of Jerusalem. The Via Dolorosa is is to your north\n" +           
"and roads to the other parts of this quarter meander to\n" +
"the west, south and east. This area seems more or less poor\n" +
"and there are small piles of waste and rubble here and there.\n";
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


