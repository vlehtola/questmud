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

        add_exit("east","/world/city/silcop1.c");
        add_exit("south","/world/city/silver3.c");
        add_exit("north","/world/city/silver1.c");

    short_desc = "On the northern part of Silver street";
    long_desc = "########### You are on Silver street running north-south next to a street\n" + 
		"#    | WWW# leading to Copper street. This street is home to most of the\n" +
		"#    *--+-# citizens of Duranghom. The street is mostly filled with good\n" + 
		"#    |    # quality houses in which the citizens can spend their nights.\n" +
		"########### There are also some houses for rent. Copper street is located\n" + 
		"some distance in east. The Mainstreet of Duranghom is behind some distance\n"+
                "in south.\n";
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
