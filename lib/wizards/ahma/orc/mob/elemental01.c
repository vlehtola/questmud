inherit "obj/monster";

reset(arg) {
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(3) + 35);
  set_name("elemental");
  set_race("elemental");
  set_short("A small earth elemental");
  set_long("This earth elemental seems to be a size of an Orcish kid. Though the\n" + 
           "elemental is quite small it seems to possess superior strength in its\n" + 
           "stony and muscular arms. The elemental stares at you like it would not\n" + 
           "have seen an humanoid creature before.\n");

  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Elemental stares at you curiously.\n";
    chat_str[1] = "Elemental makes a ball out of dust on the ground and throws it at you.\n";
    chat_str[2] = "Elemental giggles inanely.\n";
  }
  load_chat(3, chat_str);

  set_max_hp(query_hp() + 2000);
  set_hp(query_max_hp());
  set_str(query_str() + 50);
  set_skill("kick", 80);
  set_skill_chance("kick", 50);
  set_skill("critical", 50);
  set_skill("enhance criticals", 20);
  set_skill("find weakness", 30);
  set_resists("electric", 100);
  set_al(-5);
}
