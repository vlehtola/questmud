//Fixed shield wielding -- Rag 21.4.04
inherit "obj/monster";

reset(arg) {
  object armour, weapon;
  ::reset(arg);
  if(arg) { return; }
  set_level(50);
  set_name("gate guard");
  set_race("dark elf");
  set_alias("guard");
  set_short("A gate guard.");
  set_long("This is one of the gate guards of the Dark elf city.\n"+
           "They are constantly on the edge and doesn't miss a thing..\n");
  set_al(-500);
//tuned by Moonstar 3.10.2004
  set_aggressive(0);
   set_skills("blades", 100);
   set_skills("slash", 80);
   set_skills("two weapons combat", 100);
   set_skills("critical",100);
   set_skills("doublehit", 100);
   set_skills("find weakness", 80);
   set_skills("stun",100);
   set_skills("double strike",100);
   set_skills("disarm",70);
   set_skill_chance("disarm", 70);
   set_skills("find weakness",80);
   set_skills("reflect spell",15);
   set_skills("strike",100);
   set_skill_chance("strike", 50);
  weapon = clone_object("/wizards/gynter/darke/eq/claymore");
  move_object(weapon, this_object());
  init_command("wield claymore");

  weapon = clone_object("/wizards/gynter/darke/eq/shield");
  move_object(weapon, this_object());
  init_command("wield shield");

  armour = clone_object("/wizards/gynter/darke/eq/plate_mail");
  move_object(armour, this_object());
  init_command("wear mail");

  armour = clone_object("/wizards/gynter/darke/eq/great_helm");
  move_object(armour, this_object());
  init_command("wear helmet");


}
