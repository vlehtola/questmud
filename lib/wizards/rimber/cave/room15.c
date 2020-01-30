inherit "room/room";
object monster, monster1, monster2;

reset(arg) {
	int a,b,c;
	a = random(13);
	b = random(13);
	c = random(13);
	if(!monster) {
	monster = clone_object("/wizards/rimber/cave/dweller.c");
	move_object(monster, this_object());
	}
	if(!monster1) {
	monster1 = clone_object("/wizards/rimber/cave/dweller.c");
	move_object(monster1, this_object());
	}
	if(!monster2) {
	monster2 = clone_object("/wizards/rimber/cave/dweller.c");
	move_object(monster2, this_object());
	}
	if(arg) return;
	set_light(2);
	short_desc = "Dweller city";
        long_desc = "The cave is really damp. Puddles speckle the floor.\n"+
         "A distant sound of a dripping water echoes in the tunnels.\n"+
         "The walls glitter oddly because of the slowly\n"+
		"dripping water. Anyone could go crazy in here.\n";
	add_exit("south", "/wizards/rimber/cave/"+b);
	add_exit("north", "/wizards/rimber/cave/"+c);
	add_exit("west", "/wizards/rimber/cave/"+a);
	add_exit("east", "/wizards/rimber/cave/room16.c");
 set_not_out(1);
}
