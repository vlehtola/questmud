inherit "obj/monster";

reset(arg) {
  object weapon;
  ::reset(arg);
  if(arg) { return; }
  set_mage(1);
  set_level(35);
  set_name("archmage");
  set_alias("mage");
  set_short("An archmage");
  set_long("This is one of the guards of the GrandMage. They are dressed\n" +
           "in the cloak that the Grand mage wishes them to wear.\n");
  set_al(0);
  set_al_aggr(200);
  set_aggressive(1);
  set_init_ob(this_object());

  weapon = clone_object("/wizards/gynter/area2/city2/eq/arch_cloak");
  move_object(weapon, this_object());
  init_command("wear cloak");

  set_skill("cast divine", 100);
  set_skill("cast heal", 100);
  set_skill("cast major", 100);
  set_skill("channel", 100);
  set_skill("quick chant", 100);
}

monster_init() {
  if(!this_player()->query_quests("Strakhand, Kill the mage")) { return 1; }
}
/*
catch_tell(str) {
  string tmp1,tmp2,target_name;
  ::catch_tell(str);
  if(sscanf(str, "%s attacks %s!", tmp1, tmp2) == 2) {
  if(tmp2 != "Mage") return;
  if(this_player()->query_npc() || !this_player()->query_name() == tmp1) {
   return;
  } else if(!this_player()->query_npc() && this_player()->query_name() == tmp1) {
   this_object()->attack_ob(find_player(lower_case(tmp1)));
   }
  }
}
*/