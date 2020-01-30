inherit "room/room";
object shaman;

reset(arg) {
        if(arg) return;
	if(!shaman) {
	shaman = clone_object("/wizards/rimber/cave/shaman.c");
	move_object(shaman, this_object());
	}
	set_light(3);
	short_desc = "In the shaman's hut";
 long_desc = "The hut is dimly lit. The only source of light seems\n"+
  "to be a dying fire in the firepit. Few claypots are scattered\n"+
  "on the floor. A desk filled with scrolls, bones and entrails\n"+
  "can be seen in the back of the room.\n";
  items = allocate(4);
  items[0] = "claypots";
  items[1] = "The claypots are scattered around the room.";
  items[2] = "desk";
  items[3] = "The desk is red of blood. The air around the desk stinks.";
	add_exit("out", "/wizards/rimber/cave/room40.c");
}
