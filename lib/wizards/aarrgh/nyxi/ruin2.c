inherit "room/room";

object monster;

reset(arg)  {
set_light(0);
set_not_out(1);
            add_exit("west", "/wizards/aarrgh/nyxi/ruin1");
            short_desc = "Ancient ruins";
	    long_desc = "These ancient ruins radiate demonic presence. Darkness fills the area.\n"
  			"Strong impulses of ghastly force can be sensed.\n"
 			"Some odd markings have been drawn on the ground.\n";


items = allocate(2);
items[0] = "markings";
items[1] = "You look closer and notice something written. It says: BRO NRUT\n";
}

long(str) {
    ::long(str);
    if (str == "markings") {
	if (!monster) {
	  monster = clone_object("/wizards/aarrgh/nyxi/mon/monsu");
	  move_object(monster, this_object());
	  say("Suddenly something flashes and a horrible Demon arrives from a portal of some evil kind!\n");
	  tell_object(this_player(), "There is a flash and portal appears. A horrible Demon arrives!\n");
this_player()->set_quest("Discover markings");
	}
	call_other("/wizards/aarrgh/nyxi/down1.c","set_looked",1);
    }
}
