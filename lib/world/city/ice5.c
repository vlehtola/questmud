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

        add_exit("east","/world/city/gold6.c");
        add_exit("west","/world/city/ice4.c");
        add_exit("south","/world/arena/entrance.c");

    short_desc = "On the central part of Ice street";
    long_desc = "########### You are on Ice street running east and west through the city.\n" +
		"# L     | # This street is part of Duranghom's downtown. On both sides\n" +
		"#-+--*--+-# of the road, there are big wooden houses, homes of many\n" +
		"# Au Ar | # families that have lived in Duranghom for centuries. The\n" +
		"########### Emerald street with its rich houses is located in west and\n" +
		"the gold street in east. Duranghom's city Battle Arena is located in south.\n";
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
