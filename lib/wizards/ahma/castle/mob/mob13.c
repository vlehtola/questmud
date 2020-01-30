inherit "obj/monster";

reset(arg) {
  object shield, sword;
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(3)+35);
  set_name("novice fighter");
  set_alt_name("demon");
  set_alias("fighter");
  set_short("Novice demon fighter");
  set_long("Apprentice fighter is looking for someone to challenge it into a duel. Demon\n" + 
           "knows, that the skills do not help it if it's dead, so it picks its opponents\n" + 
           "carefully, after consideration. The demon leers at you calculatingly, like\n" + 
           "considering if the duel with you would be victorious for him. The creature\n" + 
           "does not look as sturdy as real barbarian-fighters, but it still must know\n" + 
           "something about using the sword and shield it is carrying with itself all the\n" + 
           "time.\n");
  set_max_hp(query_hp() + 600);
  set_hp(query_max_hp());
  set_str(query_str() + 35);
  set_dex(query_dex() + 20);
  set_al(-20);
  set_aggressive(0);
  set_resists("fire",100);
  set_skill_chance("kick", 80);
  set_skill("shield parry", 40);
  set_skill("parry", 40);
  set_skill("shield bash", 40);
  set_skill("riposte", 60);

  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Novice fighter leers at you suspiciously.\n";
    chat_str[1] = "Novice fighter boasts with its skills.\n";
    chat_str[2] = "Novice fighter almost trips on a rock lying on the ground.\n";
  }
  load_chat(3, chat_str);
  
   sword = clone_object("/world/eq/weapons/shortsword");
   move_object(sword, this_object());
   init_command("wield sword");

   shield = clone_object("/wizards/ahma/castle/eq/shield");
   move_object(shield, this_object());
   init_command("wield shield");
}
