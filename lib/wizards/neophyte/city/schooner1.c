inherit "room/room";
object ob;
reset (arg) {
        if(!ob) {
                ob = clone_object("/wizards/neophyte/city/monst/walker");
                move_object(ob,this_object());
        }
    if(arg) return;
        short_desc = "Crossing of the schooner ant barrel street";
        long_desc = "  ##### You are on the crossing of schooner and barrel\n"+
                    "  #*--+ streets. The schooner street continues to the\n"+
                    "  #|### south and barrel street to the east. The street\n"+
                    "  #+### is totally empty and silent, because of the\n"+
                    "        graveyard. The graveyard is surrounded by high\n"+
                    "        fence.\n";
   add_exit("east","/wizards/neophyte/city/barrel1");
   add_exit("south","/wizards/neophyte/city/schooner2");
}

init() {
   ::init();
   add_action("map", "map");
}

map(arg) {
   if (arg) {
        return 0;
   }
   cat("/wizards/neophyte/city/map");
   return 1;
}
