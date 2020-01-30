inherit "room/room";
object g1,g2,g3;
reset (arg) {
                if(!g1) {
                        g1 = clone_object("/wizards/neophyte/city/monst/guard1");
                        move_object(g1, this_object());
                }
        if(!g2) {
                g2 = clone_object("/wizards/neophyte/city/monst/guard1");
                move_object(g2, this_object());
        }
        if(!g3) {
                g3 = clone_object("/wizards/neophyte/city/monst/guard1");
                move_object(g3, this_object());
        }

    if(arg) return;
        short_desc = "Guard post";
        long_desc = "This is the place where the guards come rest after their duties. The walls\n"+
                    "are painted in blue, representing the sea and decorated with nets and\n"+
                    "stuff related to sea. On the floor is a simple mat, which brings some\n"+
                    "cosiness in here. On the backside of the room is placed a couple of old\n"+
                    "and not so cousy looking beds.\n";

   items = allocate(6);
   items[0] = "mat";
   items[1] = "The mat is covering the floor. It's simple looking, but it brings cosiness in the room";
   items[2] = "bed";
   items[3] = "The old bed is placed backside of the room";

   set_not_out(1);
   set_light(3);
   add_exit("south","/wizards/neophyte/city/keel1");
}

