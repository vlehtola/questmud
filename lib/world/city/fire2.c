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

        add_exit("east","/world/city/fire3.c");
        add_exit("west","/world/city/emerald2.c");

    short_desc = "On the western part of Fire street";
    long_desc = "########### You are on Fire street running next to Emerald Street, which\n" + 
		"# | WWWWTT# is to east from here. This street is home to most of the richest\n" +
		"#u+--*--+-# travellers who pass through Duranghom. This street is mostly\n" + 
		"# |       # filled with high quality rent-rooms which the travellers can\n" +
		"########### rent for the night. Gold and Silver streets are located east of\n" +
		"here and Emerald street is to the west. The North gate is located behind a\n" + 
		"little distance in northest.\n";
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
