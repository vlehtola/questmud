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

        add_exit("north","/world/city/emerald9.c");
        add_exit("east","/world/city/wood2.c");
    short_desc = "On the southern part of Emerald street";
    long_desc = "########### You are on the crossing of Emerald street and Wood street.\n" + 
                "#  W |    # Wood, Gold and Silver streets are located to east from\n" +
                "#  W *--+-# here. The Mainstreet of Duranghom is located much north\n" + 
                "#  WWWWWWW# from here. This old street has all kinds of shops scattered\n" +
                "########### to each side of the street. The high wall arises up over\n" +

                "your head in west and south from here.\n";
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
