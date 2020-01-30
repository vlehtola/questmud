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

        add_exit("north","/world/city/emerald2.c");
        add_exit("south","/world/city/emerald4");
        add_exit("east","/world/city/teleportroom");
        add_exit("west","/world/city/diaeme2.c");

    short_desc = "On the central part of Emerald street";
    long_desc = "########### You are on Emerald street, next to a small street which leads\n" + 
                "#    |    # to Diamond street. This street is home to most of the rich\n" +
                "#-+--*Tl  # people of Duranghom. The Mainstreet of Duranghom is located\n" + 
                "# A  |    # some distance in south from here. The teleport room of city\n"+
                "########### Duranghom is located in the eastern side of the street.\n";
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
