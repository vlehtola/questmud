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

        add_exit("west","/world/city/mainstr7.c");
        add_exit("east","/world/city/mainstr9.c");
        add_exit("north","/world/shops/general_store.c");

    short_desc = "On eastern part of Mainstreet";
    long_desc = "########### This is the Mainstreet of Duranghom running east and\n" + 
		"# |  G  Me# west. This old and large street is usually crowded\n" +
		"#-+--*--+-# with merchants and travellers that wander across this\n" + 
		"# |       # big city, busily looking for a place to stay for the\n" +
		"########### night and food for their long travels. To the west is\n" +
		"the central square and to the east the eastern gate. This street\n" + 
		"draws a line across the city, dividing it in northern and southern\n" +
		"parts. You notice that the General store of Duranghom is located\n" +
		"in north.\n";
  set_light(3);
}

map(arg) {
   if (arg) {
        return 0;
   }
   cat("/world/city/mapsor/x/18");
   return 1;
}
