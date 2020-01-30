inherit "room/room";

reset(arg) {
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
	add_exit("north", "/wizards/rimber/cave/room22.c");
	add_exit("south", "/wizards/rimber/cave/room28.c");
	add_exit("east", "/wizards/rimber/cave/room25.c");
 set_not_out(1);
}
