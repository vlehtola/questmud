inherit "obj/monster";

string chat_str;
reset(arg) {
object armour;
object weapon;
object weapon2;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(5) + 55);
   set_str(random(10)+350);
  set_name("dwarf");
  set_race("dwarf");
  set_alias("guard");
  set_gender(1);
  set_skills("tumble", 100);
  set_skills("counter spell", 100);
  set_skills("double strike", 100);
  set_skills("strike", 100);
  set_skill_chance("strike",50);
  set_short("A scared looking guard");
  set_long("Strong looking guard, but there is something strange\n"+
           "in this dwarf. This little one shivers in fear and can \n"+
           "barely keep his axe in his hand.\n");
  set_al(40);
  set_aggressive(0);
  set_max_hp(query_hp() + 10000);
  set_hp(query_max_hp());
  set_block_dir("northeast");

armour = clone_object("/wizards/kaappi/mine/kamat/plate.c");
move_object(armour, this_object());
init_command("wear armour");

weapon = clone_object("/wizards/kaappi/mine/kamat/gshield.c");
move_object(weapon, this_object());
init_command("wield shield");

weapon2 = clone_object("/wizards/kaappi/mine/kamat/gaxe.c");
move_object(weapon2, this_object());
init_command("wield axe");

if (!chat_str) {
  chat_str = allocate(1);
  chat_str[0] = "Guard says: 'P-please, d-don't go forward!\n"+
                "L-long time ago we were mining in this part of these tunnels.\n"+           
                "Then suddenly i-it st-started... And.. No.. I can't even say i-it.\n"+
                "But.. I can't let you go forward!\n";
}
load_chat(2, chat_str); }
