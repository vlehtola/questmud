inherit "obj/monster";
reset(arg) {

::reset(arg);
if(arg) { return; }
set_level(24);
set_name("snake");
set_alias("snake");
set_short("A dangerous, lizard-like snake");
set_long("The snake has no limbs or backbone, but still it's dangerous and\n"+
         "very capable to kill bigger animals, bigger than itself. Its red,\n"+
         "round eyes, long, bifurcated tongue and sharp, poisonious teeth,\n"+
         "makes the snake dangerous, one of the most feared animals.\n");
set_al(0);
set_aggressive(0);
set_gender(0);
set_animal(1);
}

