inherit "obj/monster";
object weapon;
reset(arg) {
   ::reset(arg);

set_name("bookseller");
set_level(21);
set_al(0);
set_gender(1);
set_race("human");
set_alias("man");
set_short("A man selling books");
set_long("An elderly man intent on keeping his bookstore clean.\n");
weapon = clone_object("/wizards/nalle/jerusalem/eq/broom");
move_object(weapon, this_object());
init_command("wield broom");
}


