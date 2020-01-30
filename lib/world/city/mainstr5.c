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

        add_exit("east","/world/city/cs.c");
        add_exit("north","/room/bank.c");
        add_exit("west","/world/city/mainstr4.c");
        add_exit("south","/world/city/inn.c");

    short_desc = "On central part of Mainstreet";
    long_desc = "########### This is the Mainstreet of Duranghom running east and\n"+ 
                "# C  B  | # west. This old and large street is usually crowded\n"+
                "#-+--*--O-# with merchants and travellers that wander across this\n"+
                "#    I  | # big city, busily looking for a place to stay for the\n"+
                "########### night and food for their long travels. To the west is\n"+
                "the western gate and just east is the central square. This street\n"+ 
                "draws a line across the city, dividing it in northern and southern\n"+
                "parts. The first, and only, bank of Duranghom is located in north\n"+
                "from here and the inn is to the south.\n";
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
