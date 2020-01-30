inherit "obj/monster";
reset(arg) {
object weapon;
object armour;
object money;
::reset(arg);
if(arg) { return; }
set_level(25);
set_name("guard");
set_alias("goblin");
set_short("A huge goblin guard");
set_long("A huge goblin guard guarding The goblin chemist.\n");
set_al(-5);
set_block_dir("northwest");
set_aggressive(1);
set_log();
money = clone_object("obj/money");
call_other(money, "set_money", random(1200)+250);
move_object(money, this_object());

weapon = clone_object("/wizards/terror/goblin/kamat/gsword.c");
move_object(weapon, this_object());
init_command("wield sword");
armour = clone_object("/wizards/terror/goblin/kamat/ghelm.c");
move_object(armour, this_object());
init_command("wear helm");
}
