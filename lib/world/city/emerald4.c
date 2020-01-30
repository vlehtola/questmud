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

        add_exit("north","/world/city/emerald3.c");
        add_exit("south","/world/city/mainstr3");
        add_exit("west","/world/shops/weapon_shop.c");

    short_desc = "On the central part of Emerald street";
    long_desc = "########### You are on Emerald street next to the Mainstreet street of\n" + 
                "# A  |    # Duranghom. This street is home to most of the rich\n" +
                "#  We*    # people of Duranghom. The Mainstreet of Duranghom is located\n" + 
                "#    |    # just south of here. This old street has all kinds of shops\n" +
                "########### scattered to each side of the street. The old-traditioned\n" +
                "weapon smith's shop is located just west of here.\n";
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
