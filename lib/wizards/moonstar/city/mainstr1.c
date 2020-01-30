inherit "room/room";
object monster,monster2;
init() {
   ::init();
   add_action("west","west");
   add_action("map", "map");
}

reset(arg) {
if(arg) return;

if (!monster) {
                monster = clone_object("/world/monsters/citizen.c");
                move_object(monster, this_object());
  }

if (!monster2) {
                monster2 = clone_object("/wizards/jenny/city/guards/cityguard.c");
                move_object(monster2, this_object());
 }

        add_exit("east","/world/city/mainstr2.c");
        add_exit("west","/world/city/westgate.c");
        add_exit("north","/world/city/diamond4.c");
        add_exit("south","/world/city/diamond6.c");

    short_desc = "On western part of Mainstreet";
    long_desc = "########### This is the Mainstreet of Duranghom between Diamond\n" + 
                "# TT |    # street. This old and large street is usually crowded\n" +
                "# ==-*--+-# with merchants and travellers that wander across this\n" + 
                "# TT |  Ms# big city, busily looking for a place to stay for the\n" +
                "########### night and food for their long travels. To the west is\n" +
                "the western gate and to the east the central square. This street\n" + 
                "draws a line across the city, dividing it in northern and southern\n" +
                "parts. The houses in north seem to be better built.\n";
  set_light(3);



}

map(arg) {
   if (arg) {
        return 0;
   }
   cat("/world/city/mapsor/5");
   return 1;
}

status west() {
  if(this_player()) return 0;
  if(previous_object()->query_monster()) return 1;
}

