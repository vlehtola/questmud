inherit "room/room";
object monster, monster1, monster2;

reset(arg) {
	if(!monster) {
	monster = clone_object("/wizards/rimber/cave/citizen.c");
	move_object(monster, this_object());
	}
	if(!monster1) {
	monster1 = clone_object("/wizards/rimber/cave/citizen.c");
	move_object(monster1, this_object());
	}
	if(!monster2) {
	monster2 = clone_object("/wizards/rimber/cave/citizen.c");
	move_object(monster2, this_object());
	}
	if(arg) return;
	set_light(3);
	short_desc = "Dweller city";
 long_desc = "The dark dweller city lies deep inside the mountain.\n"+
  "The houses have been built inside rocks. The streets\n"+
 "are narrow and rough. Odd green crystal glows on the\n"+
  "top of a metallic pole.\n";
	items = allocate(4);
	items[0] = "crystal";
        items[1] = "The crystal radiates green light.";
	items[2] = "pole";
	items[3] = "The pole is made of iron.";
	add_exit("north","/wizards/rimber/cave/room26.c");
	add_exit("west","/wizards/rimber/cave/room29.c");
	add_exit("east","/wizards/rimber/cave/room31.c");
 set_not_out(1);
}
