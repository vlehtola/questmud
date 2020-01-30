inherit "room/room";
object ob;
reset (arg) {
        if(!ob) {
                ob = clone_object("/wizards/neophyte/city/monst/walker");
                move_object(ob,this_object());
        }

    if(arg) return;
        short_desc = "Rudder street";
        long_desc = "+--+--+ At the rudder street, which continues its way\n"+
                    "###|### to the north and south. There are lots of\n"+
                    "###*### drunken sailors and pirates walking near that\n"+
                    "###|#In seventh sea inn. There seems to be lots of life\n"+
                    "        in the city streets.\n";
   add_exit("north","/wizards/neophyte/city/rudder3");
   add_exit("south","/wizards/neophyte/city/rudder5");
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
