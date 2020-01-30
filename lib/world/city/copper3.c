inherit "room/room";
object monster;
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

        add_exit("north","/world/city/mainst10.c");
        add_exit("west","/world/city/silcop4.c");

    short_desc = "On southern part of Copper street";
    long_desc = "########### This is the Copper street. This part of the city is the \n" + 
		"#     | TT# poorest. There are only old and broken buildings. The\n" +
		"#--+--* T # poorest people of Duranghom are living in these buildings.\n" + 
		"#  |    W # The large Mainstreet of Duranghom is located just north of\n" +
		"########### here, and unlike this street, it is crowded with travellers\n" +
		"and merchants. The large east wall is located next to you, proudly\n" + 
		"guarding the city from bandits and thieves.\n";
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
