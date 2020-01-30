inherit "obj/monster";

reset(arg) {
object money;
object armour;
::reset(arg);
if(arg) { return; }
set_level(29);
set_name("bat");
set_alias("vampire");
set_short("A large vampire bat");
set_long("You see a large vampire bat hanging from caves ceiling.\n"+
"Large bat is looking at you hungrily it smells fresh blood from you.\n"+
"You think that this bat is mother of all bats in this place.\n"+
"You discover some blood on bat's teeth.....\n");
set_al(-10);
set_aggressive(0);        
set_log();

money = clone_object("obj/money");
call_other(money, "set_money", random(500)+700);
move_object(money, this_object());

armour = clone_object("/wizards/terror/goblin/kamat/bcloak.c");
move_object(armour, this_object());
init_command("wear cloak");
}
