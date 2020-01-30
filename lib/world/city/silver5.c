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

        add_exit("south","/world/city/silver6.c");
        add_exit("west","/world/city/ice7.c");
        add_exit("north","/world/city/silver4.c");

    short_desc = "On the central part of Silver street";
    long_desc = "########### You are on the crossing of Silver street and Ice street, which\n" + 
		"#    |    # is running east-west across many streets. This street is home\n" +
		"#-+--*    # to most of the citizens of Duranghom. This street is mostly\n" + 
		"#    |    # filled with good quality houses in which the citizens can spend\n" +
		"########### their nights. There are also some houses for rent. Emerald and\n" + 
		"Diamond streets are located much west. The Mainstreet of Duranghom is bahind\n" +
		"some distance in north.\n";
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
