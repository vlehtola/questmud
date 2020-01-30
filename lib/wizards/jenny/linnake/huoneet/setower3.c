inherit "room/room";
object monster;

reset(arg) {
if(arg) return;
        if (!monster) {
                monster = clone_object("/wizards/jenny/linnake/mosut/alconte.c");
                move_object(monster, this_object());
        }

        add_exit("down","/wizards/jenny/linnake/huoneet/setower2.c");
        
        short_desc = "southeast tower";
        long_desc = "This is one of the four towers of Roxen, it is decorated\n"+
                    "nicely and there are few chairs, table and two beds in here.\n"+
                    "Small lantern is hanging from the ceiling and dusty old\n"+
                    "carpet is on the floor, after all this place is quite\n"+
                    "comfortable\n";
}
