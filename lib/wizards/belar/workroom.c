inherit "room/room";
object dragon;
reset(arg){
if(!dragon){
dragon = clone_object("/wizards/belar/monsu/dragon.c");
move_object(dragon, this_object());
}
add_exit("inn","/world/city/inn");
add_exit("cs","/world/city/cs");
add_exit("dwarf","/wizards/belar/dwarf/entrance.c");
add_exit("ent","/wizards/belar/ent/rooms/entrance.c");
short_desc = "Belar's home";
long_desc = "This is the home of mighty wizard Belar\n."+
	 "His staff and his robe is hanging at the wall..\n"+
	 "Belar's pet dragon is resting at firepace's warmth.\n"; 	
property = allocate(1);
property[0] = "no_summon";
}
