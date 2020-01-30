inherit "room/room";
object monster;

reset(arg) {
if(arg) return;
        if (!monster) {
                monster = clone_object("/wizards/jenny/linnake/mosut/elite_guard.c");
                move_object(monster, this_object());
        }

        add_exit("west","/wizards/jenny/linnake/huoneet/prison22.c");
        add_exit("east","/wizards/jenny/linnake/huoneet/prison20.c");

        short_desc = "You are walking in a narrow hallway";
        long_desc = "You are walking in a narrow hallway that leads to the captains\n"+
                    "room. There are some torches burning near you and the floor is\n"+
                    "very dusty. This place smells like puke, old socks and liquor.\n"+
                    "You can hear prisoners screaming from their cells.\n";
}
