inherit "obj/monster";

reset(arg) {
 object weapon;
 ::reset(arg);
 if(arg) return;
 set_level(80);
 set_log(1);
 set_race("demon");
 set_aggressive(1);
 set_short("Diablo the lord of chaos");
 set_long("Diablo on ihan sairaaan iso.\n");
 set_str(query_str()*2);
 set_con(query_con()*2);
 weapon = clone_object("/wizards/rimber/hell/obj/dweapon.c");
 move_object(weapon, this_object());
 init_command("wield maul");
}
