inherit "room/room";
inherit "room/door";
int door_number;
object ob;
reset (arg) {
        if(!ob) {
                ob = clone_object("/wizards/neophyte/city/monst/walker");
                move_object(ob, this_object());
        }
    if(arg) return;
    short_desc = "Anchor street";
        long_desc = "+#####+ The anchor street runs towards to the west\n"+
                    "|##H##| and east. The street looks quite silent and\n"+
                    "+--*--+ empty. The city walls are surrounding the\n"+
                    "######| city. A huge wooden house is built on the\n"+
                    "     #+ block. The owner of the house must be very\n"+
                    "        rich, because the house is as big as the block.\n";
   add_exit("west","/wizards/neophyte/city/schooner5");
   add_exit("east","/wizards/neophyte/city/sailor5");
     door_reset();
     door_number = 1;
     set_door_label("bronze door", 1);
     set_door_dir("north", "/wizards/neophyte/city/house/house1", 1);
     set_door_link("/wizards/neophyte/city/house/house1", 1);
     set_door_code("112", 1);
     set_locked(1, 1);
   }

init() {
   ::init();
   door_init();
   add_action("map", "map");
}

map(arg) {
   if (arg) {
        return 0;
   }
   cat("/wizards/neophyte/city/map");
   return 1;
}
