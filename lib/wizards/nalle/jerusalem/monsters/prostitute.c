inherit "obj/monster";
object weapon;
reset(arg) {
   ::reset(arg);

set_name("woman");
set_level(21);
set_al(0);
set_gender(2);
set_race("human");
set_alias("prostitute");
set_short("A scantily dressed prostitute");
set_long("One of the many protitutes of the Armenian quarter.\n");
weapon = clone_object("/wizards/nalle/jerusalem/eq/knife");
move_object(weapon, this_object());
init_command("wield dagger");
}

init() {
    ::init();
   add_action("score", "score");
}

score() {
   cat("/wizards/nalle/jerusalem/pros.txt");
   return 1;
}
