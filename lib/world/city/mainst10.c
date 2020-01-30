inherit "room/room";
object monster,monster2;
init() {
   ::init();
   add_action("east", "east");
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

        add_exit("west","/world/city/mainstr9.c");
        add_exit("east","/world/city/eastgate.c");
        add_exit("north","/world/city/copper2.c");
        add_exit("south","/world/city/copper3.c");

    short_desc = "On eastern part of Mainstreet";
    long_desc = "########### This is the Mainstreet of Duranghom between Copper\n" + 
		"#  Me | TT# street. This old and large street is usually crowded\n" +
		"#--+--*-==# with merchants and travellers that wander across this\n" + 
		"#     | TT# big city, busily looking for a place to stay for the\n" +
		"########### night and food for their long travels. A long way to \n" +
		"the west is large the central square of the city. This old street\n" + 
		"draws a line across the city, dividing it in north and south parts.\n" +
		"The big east gate stands proudly, guarding the city just east from here.\n";
  set_light(3);

}

map(arg) {
   int *coords;
   string file;
   object map;

   if (arg) {
        return 0;
   }

   map = (object) "/wizards/moonstar/muut/map";

   file = file_name(environment(this_player()));
   coords = map->to_coords(file);
   map->drawmap(coords[0], coords[1]);

   return 1;
}


status east() {
  if(this_player()) return 0;
  if(previous_object()->query_monster()) return 1;
}
