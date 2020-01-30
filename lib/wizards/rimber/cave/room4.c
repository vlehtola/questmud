inherit "room/room";
object monster, monster1;

reset(arg) {
	if(!monster) {
	monster = clone_object("/wizards/rimber/cave/dweller.c");
	move_object(monster, this_object());
	}
	if(!monster1) {
	monster1 = clone_object("/wizards/rimber/cave/dweller.c");
	move_object(monster1, this_object());
	}
	set_light(3);
	short_desc = "Dark and damp cavern";
        long_desc = "The cave's ceiling seems to descend eastwards. Dripstones\n"+
             "reach down from the ceiling. Water flows down their surface\n"+
           "making large puddles on the ground.\n"+
               "The sound of dripping water sounds now less distant.\n";
		"sounds now less distant.\n";
 	add_exit("south", "/wizards/rimber/cave/room2.c");
	add_exit("east","/wizards/rimber/cave/room5.c");
	add_exit("west", "/wizards/rimber/cave/room3.c");
 set_not_out(1);
}
