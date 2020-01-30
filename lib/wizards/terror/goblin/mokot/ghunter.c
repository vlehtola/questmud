inherit "obj/monster";
reset(arg) {
object money;
object weapon;
::reset(arg);
if(arg) { return; }
set_level(22);
set_name("goblin");
set_alias("hunter");
set_short("A ragged goblin hunter");
set_long("A ragged goblin hunter looking for something.\n");
set_al(0);
set_aggressive(0);
set_log();
set_skill("attack", 65);
set_skill("axes", 65);
money = clone_object("/obj/money");
call_other(money, "set_money", random(150)+150);
move_object(money, this_object());
weapon = clone_object("/wizards/terror/goblin/kamat/gaxe.c");
move_object(weapon, this_object());
init_command("wield axe");
}
