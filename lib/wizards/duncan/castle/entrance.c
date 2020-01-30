

inherit "room/room";
object sign;
reset(arg) {

if(!sign) {
  sign = clone_object("/wizards/duncan/castle/object/sign.c");
  move_object(sign, this_object());
}

if(arg) return;
        set_light(4);

short_desc = ("In front of the ancient castle");
long_desc= 
"An ancient castle has been built here a long time ago. The castle is on the top\n"+
"of the hills. It offers protection from the sea and from the land. Walls of the\n"+
"castle are so high, that it's impossible to climb up. There are two cannon's\n"+ 
"placed on the top of the south wall. A deep moat has been dug in front of the\n"+
"castle. The moat is full of crystal-clear water and some huge green animals.\n"+
"A wooden drawbridge is lowered to the ground, leading inside to the castle.\n"+
"An iron gate is pulled up.\n";

add_exit("drawbridge","/wizards/duncan/castle/r1.c");
add_exit("out","/wizards/duncan/workroom.c");


items = allocate(6);
items[0] = "moat";
items[1] = "The moat is full of crystal-clear water and there are some green animals swimming around.";
items[2] = "cannon";
items[3] = "On the top of the castle's south wall you can see two rusty cannon's.";
items[4] = "gate";
items[5] = "The iron gate has been pulled up.";

 call_other("wizards/irmeli/castle/drop_rock_d.c", "start_rocks", 1);
}
