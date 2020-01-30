inherit "room/room";
object monster;

reset(arg) {
	if(!monster) {
	monster = clone_object("/wizards/rimber/cave/citizen.c");
	move_object(monster, this_object());
	}
	if(arg) return;
	set_light(3);
	short_desc = "Dweller city";
 long_desc = "The dark dweller city lies deep inside the mountain.\n"+
  "The houses have been built inside rocks. The streets\n"+
  "are narrow and rough. Odd green crystal glow on the\n"+
  "top of a metallic pole.\n";
	items = allocate(4);
	items[0] = "crystal";
        items[1] = "The crystal radiate green light.";
	items[2] = "pole";
	items[3] = "The pole is made of iron.";
	add_exit("north","/wizards/rimber/cave/room27.c");
	add_exit("west","/wizards/rimber/cave/room30.c");
 set_not_out(1);
}
