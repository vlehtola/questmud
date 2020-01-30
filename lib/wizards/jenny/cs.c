inherit "room/room";
object monster,fountain;

init() {
   ::init();
   add_action("map", "map");
}

reset(arg) {
if(arg) return;

if (!fountain) {
                fountain = clone_object("/world/objects/fountain");
                move_object(fountain, this_object());
  }

if (!monster) {
                monster = clone_object("/wizards/jenny/city/guards/cityguard.c");
                move_object(monster, this_object());
 }

        add_exit("east","/world/city/mainstr6.c");
        add_exit("west","/world/city/mainstr5.c");
        add_exit("north","/world/city/gold3.c");
        add_exit("south","/world/city/gold5.c");

    short_desc = "On Central Square of Duranghom";
    long_desc = "########### This is the Central Square of Duranghom between the\n"+ 
                "# B  |  P # Mainstreet and Gold street. This crowdy square is\n"+
                "#-+--*--+-# crowded almost around the clock as the merchants\n"+ 
                "# I  |  Ba# keep their selling booths open all the time. Travellers\n"+
                "########### passing through the city stop here to ask advise and to\n"+ 
                "buy food. A few beggars beg for food in the corners of the square. \n"+ 
                "The guards patrol here looking for criminals and pick-pockets.\n"+
                "Better keep an eye at your money.\n";

}

map(arg) {
   if (arg) {
        return 0;
   }
   cat("/world/city/map");
   return 1;
}
