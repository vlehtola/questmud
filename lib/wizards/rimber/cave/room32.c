inherit "room/room";
object guard, guard1, thain;

reset(arg) {
	if(!guard) {
	guard = clone_object("/wizards/rimber/cave/guard.c");
	move_object(guard, this_object());
	}
	if(!guard1) {
	guard1 = clone_object("/wizards/rimber/cave/guard.c");
	move_object(guard1, this_object());
	}
	if(arg) return;
        if(!thain) {
       thain = clone_object("/wizards/rimber/cave/thain.c");
       move_object(thain, this_object());
       }
	short_desc = "Throne room";
	set_light(3);
 long_desc = "A spacious room with no other furniture than the throne\n"+
  "in sight. Six tall granite pillars rise up to the ceiling.\n"+
  "The ceiling is evenly concaved and there seems to be\n"+
  "a hole in the middle of it. Through the hole you see the sky.\n";
	items = allocate(2);
	items[0] = "throne";
        items[1] = "The throne is made of granite.";
	add_exit("south","/wizards/rimber/cave/room27.c");
}
