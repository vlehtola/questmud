inherit "obj/monster";
object weapon;
reset(arg) {
   ::reset(arg);

set_name("man");
set_level(30);
set_aggressive(1);
set_exp(640000);
set_race("human");
set_al(-10);
set_gender(1);
set_alias("figure");
set_block_dir("down");
set_short("A grotesque figure with a hunched back");
set_long("This man strangely reminds you of the story of Quasimodo.\n");
weapon = clone_object("/wizards/nalle/jerusalem/eq/normalsword");
move_object(weapon, this_object());
init_command("wield sword");
}


