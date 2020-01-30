inherit "obj/monster";
object weapon;
reset(arg) {
   ::reset(arg);

set_name("guard");
set_level(21);
set_gender(1);
set_race("human");
set_block_dir("south");
set_block_message("The guard grunts 'Go away. You have no business there.'");
set_alias("Guard");
set_short("A guard, blocking your way south");
set_long("A young guard, hired to keep thieves from entering the tower.\n"+
"He apparently seems convinced you have no business here.\n");
weapon = clone_object("/wizards/nalle/jerusalem/eq/shortsword");
move_object(weapon, this_object());
init_command("wield sword");
}
