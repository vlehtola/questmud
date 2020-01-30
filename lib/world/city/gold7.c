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

        add_exit("north","/world/city/gold6.c");
        add_exit("south","/world/city/gold8.c");
        add_exit("west","/room/ability_room");

    short_desc = "On the southern part of Gold street";
    long_desc = "########### You are on the Gold street running north and south through\n" + 
                "# Ar |    # the city. This large street is part of Duranghoms downtown.\n" +
                "#  Ab*    # On both sides of the road, there are big wooden houses, homes\n" +
                "#    |    # of many families that have lived in Duranghom for centuries.\n" +
                "########### The Central Square lies in north and the south gate in south.\n";
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
