inherit "room/room";
object monster, monster2;

reset(arg) {
if(!monster) {
  monster = clone_object("guard");
  move_object(monster, this_object());
}
if(!monster2) {
  monster2 = clone_object("guard");
  move_object(monster2, this_object());
}

if(arg) return;

add_exit("north","cas1");
add_exit("out","cas0");

        short_desc = "Inside a castle";
long_desc = "This is the entrance to the dark castle of torments.\n"
"This section of the castle is mainly used for resting\n"
"and there are a few beds to be seen in the western corner.\n"
"The echo of lost souls screaming shake the restless night\n"
"for they want to be freed.\n";

items = allocate(2);
items[0] = "beds";
items[1] = "A blood covered bed!";

set_light(4);
}
