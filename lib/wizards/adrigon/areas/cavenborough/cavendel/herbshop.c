inherit "room/room";

object monster;
reset (arg)
{
if(!monster){
monster = clone_object ("wizards/adrigon/cavenborough/cavendel/monsters/herbalist.c");
move_object(monster, this_object());
}
if(arg) return;

add_exit ("north","wizards/adrigon/cavenborough/cavendel/tcroad3.c");
add_exit ("south","wizards/adrigon/cavenborough/cavendel/herbback.c");

short_desc = "The Herbalist Shop";
long_desc =
"Mixed fragnance of the hundreds of plants is the first thing to notice when\n" +
"entering this room. Shelves on the walls are full flowerpots and dried plants.\n" +
"A Counter is on back of the room. Large windows provide the light to the room\n" +
"in daylight. A door leads to the back room and living quarters\n";

items = allocate(4);
items[0] = "counter";
items[1] = "The mahogany desk is polished and it gleams in the light. It contains\n" +
	   "two locked drawers.\n";
items[2] = "windows";
items[3] = "Two large windows stand on the north wall. White window frames look\n" +
	   "old. The street can be observed very good from inside through the\n" +
	   "windows.\n";
	   
}