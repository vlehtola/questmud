inherit "room/room";
 
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/beggar");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","wizards/nalle/jerusalem/vd8");
  add_exit("west","wizards/nalle/jerusalem/gola1");
  add_exit("east","wizards/nalle/jerusalem/gola3");
  add_exit("south","wizards/nalle/jerusalem/golb2");
  short_desc = "The way to Golgatha";
  long_desc =
"You are on a cobblestoned road leading to the south,\n" +
"meandering upwards between houses and other buildings up\n" +
"to a hill, further away. There must be something happening\n" +           
"here, because there are a good number people cheering and\n"
"booing at the same time, but you cannot quite make out what.\n";
}
 
init() {
    ::init();
   add_action("map", "map");
}
 
map(arg) {
    if (arg) {
        return 0;
    }
   cat("/wizards/nalle/jerusalem/gmap");
   return 1;
}   


