inherit "obj/monster";
object weapon;
reset(arg) {
   ::reset(arg);

set_name("guard");
set_level(30);
set_aggressive(1);
set_gender(1);
set_race("human");
set_block_dir("north");
set_block_message("The guard grunts 'Go away. You have no business there.'");
set_alias("Guard");
set_short("A guard, blocking your way north");
set_long("A guard, hired to keep thieves away from  the tower.\n"+
"He apparently seems convinced you have no business here.\n");
weapon = clone_object("/wizards/nalle/jerusalem/eq/normalsword");
move_object(weapon, this_object());
init_command("wield sword");
}

