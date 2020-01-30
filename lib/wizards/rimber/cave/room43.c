inherit "room/room";
object monster, monster1, monster2;

reset(arg) {
	int b,c,d;
	b = random(13);
	c = random(13);
	d = random(13);
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
		"dripping water. Anyone could go crazy in here.\n"+
		"You notice a small white stone.\n";
	add_exit("south", "/wizards/rimber/cave/"+d);
	add_exit("north", "/wizards/rimber/cave/room44.c");
	add_exit("west", "/wizards/rimber/cave/"+c);
	add_exit("east", "/wizards/rimber/cave/"+b);
 set_not_out(1);
}
