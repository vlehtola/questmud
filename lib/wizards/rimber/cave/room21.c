inherit "room/room";
object monster, monster1;

reset(arg) {
	if(!monster) {
	monster = clone_object("/wizards/rimber/cave/citizen.c");
        move_object(monster, this_object());
	}
	if(!monster1) {
	monster1 = clone_object("/wizards/rimber/cave/citizen.c");
        move_object(monster1, this_object());
	}
	if(arg) return;
	set_light(3);
	short_desc = "Dweller city";
 long_desc = "The dark dweller city lies deep inside the mountain.\n"+
  "The houses have been built inside rocks. The street\n"+
  "is narrow and rough. Odd green crystal glows on the\n"+
  "top of a metallic pole.\n";
	items = allocate(4);
	items[0] = "crystal";
        items[1] = "The crystal radiates green light.";
	items[2] = "pole";
	items[3] = "The pole is made of iron.";
	add_exit("up", "/wizards/rimber/cave/room18.c");
	add_exit("west", "/wizards/rimber/cave/room20.c");
 set_not_out(1);
}
