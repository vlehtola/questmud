inherit "room/room";
object sneek;

reset(arg) {
	if(!sneek) {
	sneek = clone_object("/wizards/rimber/cave/sneek.c");
	move_object(sneek, this_object());
	}
	if(arg) return;
	set_light(3);
	short_desc = "Dweller city";
 long_desc = "The dark dweller city lies deep inside the mountain.\n"+
  "The houses have been built inside rocks. The streets\n"+
  "are narrow and rough. Odd green crystal glow on the\n"+
  "top of a metallic pole. You stand in an alley and there\n"+
  "is only one exit - the one you came from.\n";
        items = allocate(4);
	items[0] = "crystal";
	items[1] = "Crystals radiates green light";
	items[2] = "pole";
	items[3] = "The pole is made of iron.";
	add_exit("up", "/wizards/rimber/cave/room48.c");
 set_not_out(1);
}
