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
       long_desc = "The cave ceiling seems to descend northwards. Dripstones\n"+
                "reach down from the ceiling. Water flows down their surface\n"+
                "making large puddles on the ground.\n"+
                "The sound of dripping water sounds now less distant.\n"+
                "A white sign is hanging on the northern wall.\n";
	items = allocate(2);
	items[0] = "sign";
	items[1] = "'Dark dweller city. Stay away!'";
 	add_exit("north", "/wizards/rimber/cave/room7.c");
        add_exit("east", "/wizards/rimber/cave/room6b.c");
	add_exit("west", "/wizards/rimber/cave/room4.c");
 set_not_out(1);
}
