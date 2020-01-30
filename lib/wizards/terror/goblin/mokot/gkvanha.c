inherit "obj/monster";
reset(arg) {
string chat_str;
object money;
object weapon,armour;
::reset(arg);
if(arg) { return; }
set_level(35);
set_name("goblin");
set_alias("chemist");
set_short("A weird looking goblin chemist");
set_long("A weird looking, goblin with it's cauldron mixing herbs and chemicals.\n");
set_al(-10);
set_special(1);
set_log();
set_aggressive(0);
set_block_dir("se");
set_spell_chance(90, "exs ssh arr");
set_skill("cast essence", 100);
set_skill("cast acid", 100);
set_skill("cast arrow", 90);
set_skill("tumble", 75);
set_skill("quick spelling", 55);
set_skill("bludgeons", 55);
set_skill("attack", 45);
set_skill("mana control", 70);

money = clone_object("obj/money");
call_other(money, "set_money", random(4000)+1500);
move_object(money, this_object());

armour = clone_object("/wizards/terror/goblin/kamat/glegut.c");
move_object(armour, this_object());
init_command("wear leggings");

weapon = clone_object("/wizards/terror/goblin/kamat/gruaska.c");
move_object(weapon, this_object());
init_command("wield whip");

if (!chat_str) {
chat_str = allocate(3);
chat_str[0] =
"Chemist drops something and yells 'OU FUCK MAN!!!! you scared me'.\n";
chat_str[1] = 
"Chemist says 'Hey you get a fuck out of here' .\n";
chat_str[2] =
"Chemist sings ' OOhhhLALAla i love you baby.... HEY WHO are YOU' .\n";
load_chat(30, chat_str);
}
}
