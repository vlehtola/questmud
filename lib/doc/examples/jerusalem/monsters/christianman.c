inherit "obj/monster";
object weapon;
reset(arg) {
   ::reset(arg);

set_name("man");
set_level(21);
set_gender(1);
set_race("human");
set_alias("Man");
set_short("A christian man");
set_long("A man in white wool, wondering around the street\n"+
"aimlessly. He seems to be middle aged.\n");
weapon = clone_object("/wizards/nalle/jerusalem/eq/normalsword");
move_object(weapon, this_object());
init_command("wield sword");
}

