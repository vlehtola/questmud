inherit "room/room";
object monster,monster2;
init() {
   ::init();
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

        add_exit("west","/world/city/mainstr6.c");
        add_exit("east","/world/city/mainstr8.c");
        add_exit("north","/world/city/silver3.c");
        add_exit("south","/world/city/silver4.c");

    short_desc = "On eastern part of Mainstreet";
    long_desc = "########### This is the Mainstreet of Duranghom between Silver\n" + 
		"# P  |  G # street. This old and large street is usually crowded\n" +
		"#-+--*--+-# with merchants and travellers that wander across this\n" + 
		"# Ba |    # big city, busily looking for a place to stay for the\n" +
		"########### night and food for their long travels. To the west is\n" +
		"the central square and to the east the eastern gate. This street\n" + 
		"draws a line across the city, dividing it in northern and southern\n" +
		"parts. The houses in the north part seem to be in better condition.\n" +
		"Silver street leads to north and south from here.\n";
  set_light(3);

}

map(arg) {
   if (arg) {
        return 0;
   }
   cat("/world/city/mapsor/e4");
   return 1;
}
