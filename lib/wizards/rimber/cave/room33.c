inherit "room/room";
object monster, monster1, monster2;

reset(arg) {
int a,c,d;
a = random(13);
c = random(13);
d = random(13);
if(!monster) {
monster = clone_object("/wizards/rimber/cave/dweller.c");
move_object(monster, this_object());
}
if(!monster1) {
monster1 = clone_object("/wizards/rimber/cave/dweller.c");
move_object(monster1, this_object());
}
if(!monster2) {
monster2 = clone_object("/wizards/rimber/cave/dweller.c");
move_object(monster2, this_object());
}
if(arg) return;
set_light(2);
short_desc = "Dweller city";
long_desc = "Cave is really damp. Puddles speckles the floor.\n"+
"Distant sound of a dripping water echoes on the tunnels\n"+
"and sometimes sound of footsteps seems to come from next\n"+
"to you. Walls glitter oddly because of the slowly\n"+
"dripping water. Anyone could go crazy in here.\n";
add_exit("south", "/wizards/rimber/cave/"+d);
add_exit("north", "/wizards/rimber/cave/"+a);
add_exit("west", "/wizards/rimber/cave/room34.c");
add_exit("east", "/wizards/rimber/cave/"+c);
 set_not_out(1);
}
