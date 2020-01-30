inherit "obj/monster";
object weapon;
reset(arg) {
   ::reset(arg);
if(arg) return;
set_name("boy");
set_level(10);
set_gender(1);
set_race("human");
set_alias("boy");
set_short("A young boy is here playing");
set_long("You look at the small boy and try to figure out what he \n"+
"is doing. You think hes trying to sculpture something out of the \n"+
"ice. He sculptures a look-alike wolf from it, examines a bit,\n"+
"shakes his head and smashes it. Then he starts over.\n");
weapon = clone_object("/wizards/shadow/Wolf/weapons/iceknife");
move_object(weapon, this_object());
init_command("wield dagger");
}
