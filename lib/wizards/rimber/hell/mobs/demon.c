inherit "obj/monster";
string wepa;

reset(arg) {
 object weapon;
 ::reset(arg);
 if(arg) return;
 switch(random(2)) {
  case 0 : wepa = "/wizards/rimber/hell/obj/mace.c";
  break;
  case 1 : wepa = "/wizards/rimber/hell/obj/ssword.c";
  break;
 }
 weapon = clone_object(wepa);
 switch(random(9)) {
 case 0..1 :
  set_level(15);
  set_name("demon");
  set_short("A small demon");
  set_skill("kick", 50);
  break;
 case 2 :
   set_level(20);
  set_name("demon");
  set_skill("kick", 100);
  set_short("A human size demon");
  move_object(weapon, this_object());
  init_command("wield sword");
  init_command("wield mace");
  break;
 case 3 :
  set_level(23+random(6));
  set_name("demon");
  set_skill("strike", 50);
  set_short("A large demon");
  move_object(weapon, this_object());
  init_command("wield sword");
  init_command("wield mace");
  break;
 case 4 :
  set_level(30);
  set_name("demon");
  set_skill("strike", 90);
  set_short("An exceptional large demon");
  move_object(weapon, this_object());
  init_command("wield sword");
  init_command("wield mace");
  set_alias("demon");
  break;
 case 5 :
  set_level(33+random(6));
  set_name("demon");
  set_skill("strike", 90);
  set_skill("double strike", 70);
  set_short("A HUGE demon");
  move_object(weapon, this_object());
  init_command("wield sword");
  init_command("wield mace");
  set_alias("demon");
  break;
 case 6 :
  set_level(15+random(9));
  set_name("lich");
  set_short("A small lich");
  set_alias("lich");
  set_spell_chance(50, "exs fla blt");
set_skill("cast essence", 90);
  set_skill("cast fire", 50);
  set_skill("cast bolt", 60);
  set_skill("mana control", 45);
  break;
 case 7..8 :
  set_level(25+random(6));
  set_name("lich");
  set_short("A lich");
  set_alias("lich");
  set_spell_chance(90, "exs poi arr");
set_skill("cast essence", 90);
  set_skill("cast poison", 90);
  set_skill("cast arrow", 80);
  set_skill("mana control", 80);
  break;
}
 set_race("demon");
 set_long("Demoni.\n");
}
