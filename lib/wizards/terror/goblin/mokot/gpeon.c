inherit "obj/monster";
reset(arg) {
::reset(arg);
if(arg) { return; }
set_level(16);
set_name("peon");
set_alias("goblin");
set_short("A goblin peon");
set_long("Just an ordinary goblin digging ground and farming vegetables.\n");
set_al(10);
set_aggressive(0);
}
