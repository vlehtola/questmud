inherit "obj/monster";
object weapon;
reset(arg) {
   ::reset(arg);
if(arg) return;
set_name("monk");
set_level(35);
set_race("human");
set_gender(1);
set_alias("Monk");
set_short("A benedictine monk");
set_long("A well built monk clad in brown robes.\n"+
"It seems he has developped a quite big stomach.\n");
}

