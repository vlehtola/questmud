
inherit"obj/monster";
reset(arg) {
object armour;
::reset(arg);
if(arg) return;
set_name("jinx");
set_alias("wizard");
set_short("Archwizard Jinx");
set_long(
"He is very old man sitting in his chair behind the desk. He has a black robe\n
+ "with white strapes on it. He smells awful, he has weared that robe for 137\n"
+ "years. Archwizard Jinx has a pencil made of red dragons scalemail.\n";
set_skill ("attack", 100);
set_skill ("stun", 80);
set_skill ("find weakness", 80);
set_skill ("critical", 75);
set_level(70);
set_race("human");
set_wc(48);
set_ac(50);
set_aggressive(0);
set_spell_chance(100, "exs zzt blt");
set_skill("cast essence", 100);
set_skill("cast electricity", 100);
set_skill("cast bolt", 100);
add_money(728);

    armour = clone_object("/wizards/siggy/area/unseen/jirobe");
    move_object(armour, this_object());
    init_command("wear robe");

}
