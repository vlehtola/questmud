inherit "obj/monster";
object weapon;
object armour;
reset(arg) {
   ::reset(arg);
if(arg) return;
set_name("Man");
set_level(35);
set_gender(1);
set_race("human");
set_alias("man");
set_short("An ice-man is here painting pictures to the walls");
set_long("You look at the man who draws wolf pictures to the icy walls.\n"+
"He notices you, growls a little and gets back to work.\n"+
"His drawings look just like the real thing. He must a real\n"+
"artist around these parts.\n");
set_aggressive(0);
weapon = clone_object("/wizards/shadow/Wolf/weapons/icepick");
move_object(weapon, this_object());
init_command("wield dagger");
}


