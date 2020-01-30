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

        add_exit("north","/world/city/gold1.c");
        add_exit("south","/world/city/gold3.c");
// Castle entrance is to east, but it was removed by rag --Jenny

    short_desc = "On the northern part of Gold street";
    long_desc = "########### You are on the Gold street running north and south through\n" + 
		"#    |    # the city. This large street is part of Duranghom's downtown.\n" +
		"#    *    # On both sides of the road, there are big wooden houses, homes\n" +
		"#    |    # of many families that have lived in Duranghom for centuries.\n" +
		"########### The Central Square lies in south and the north gate in north.\n";
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