inherit "obj/monster";
object weapon;
reset(arg) {
   ::reset(arg);

set_name("monk");
set_level(33);
set_race("human");
set_gender(1);
set_alias("Monk");
set_short("A sleeping monk");
set_long("This monk seems to have been put to guard duty\n"+
"straight after coming from the winecellar.\n");
weapon = clone_object("/wizards/nalle/jerusalem/eq/staff");
move_object(weapon, this_object());
init_command("wield staff");
}
