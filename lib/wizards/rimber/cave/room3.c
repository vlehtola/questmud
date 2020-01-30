inherit "room/room";
object gunthar;

reset(arg) {
        if(arg) return;
	if(!gunthar) {
	gunthar = clone_object("/wizards/rimber/cave/gunthar.c");
	move_object(gunthar, this_object());
	}
	set_light(3);
	short_desc = "Dark and damp cavern";
       long_desc = "The cave here is very spacious. Ceiling vanishes into\n"+
              "the darkness. A small stream flows across the cave.\n"+
               "Some blankets lie next to the stream. The ground near\n"+
               "the blankets is blackened.\n";
	items = allocate(6);
	items[0] = "stream";
        items[1] = "A small stream flows from north and continues across the cave.";
	items[2] = "blankets";
	items[3] = "It looks like somebody lives here.";
	items[4] = "ground";
        items[5] = "The blackened circle of stones on the ground seems to be an old fireplace.";
	add_exit("north", "/wizards/rimber/cave/room3b.c");
	add_exit("east", "/wizards/rimber/cave/room4.c");
 set_not_out(1);
}
