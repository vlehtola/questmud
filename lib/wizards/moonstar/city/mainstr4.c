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

        add_exit("east","/world/city/mainstr5.c");
        add_exit("west","/world/city/mainstr3");
        add_exit("north","/guilds/channel/r01.c");

    short_desc = "On western part of Mainstreet";
    long_desc = "########### This is the Mainstreet of Duranghom running east and\n" + 
                "# |  C  B # west. This old and large street is usually crowded\n" +
                "#-+--*--+-# with merchants and travellers that wander across this\n" + 
                "# |     I # big city, busily looking for a place to stay for the\n" +
                "########### night and food for their long travels. To the west is\n" +
                "the western gate and to the east the central square. This street\n" + 
                "draws a line across the city, dividing it in northern and southern\n" +
                "parts. In north lies the holy Church of Duranghom.\n";
  set_light(3);


}

map(arg) {
   if (arg) {
        return 0;
   }
   cat("/world/city/mapsor/x/6");
   return 1;
}
