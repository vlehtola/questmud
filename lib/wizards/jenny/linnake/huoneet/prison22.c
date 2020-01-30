inherit "room/room";
object monster;

reset(arg) {
if(arg) return;
        if (!monster) {
                monster = clone_object("/wizards/jenny/linnake/mosut/rewalah.c");
                move_object(monster, this_object());
        }

        add_exit("east","/wizards/jenny/linnake/huoneet/prison21.c");

        short_desc = "You have entered the captains room";
        long_desc = "You are standing in a large room and when you looking around\n"+
                    "you notice bookshelves, desks and few chair. There is an\n"+ 
                    "odd smell coming from the barrel that is located next\n"+
                    "the desk. There are also some paintings on the walls.\n";
}
