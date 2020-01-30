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

        add_exit("south","/world/city/diamond2.c");
        add_exit("east","/world/city/diaeme1.c");

    short_desc = "On the northern part of Diamond street";
    long_desc = "########### You are on Diamond street running north-east. There is a small\n" + 
                "# WWWWWWWW# street leading to Emerald street east of here. The richest people\n" +
                "# W *--+--# of Duranghom live here. The large city walls rise very high\n" + 
                "# W |     # over your head, as the city does not want to have any \n" +
                "########### unexpected visitors. The Mainstreet of Duranghom is located\n" +
                "far away in south of here. The large north wall is just next to you as is the\n" + 
                "west wall. All kinds of shops are scattered by the sides of this street.\n";
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
