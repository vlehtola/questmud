inherit "obj/monster";

reset(arg) {
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(4)+40);
  set_name("alligator");
  set_alias("animal");
  set_short("A huge white alligator");
  set_long("Strong and angry-looking alligator moves wildly around the tunnel. The\n" + 
           "animal moves on its four legs, where grows four long claws in each of\n" + 
           "them. Alligator's brownish teeth look ugly and extremely lethal. Animal's\n" + 
           "white skin looks very thick and slimy, some small leeches can be seen on\n" + 
           "it.\n");

  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Alligator roars loudly.\n";
    chat_str[1] = "Alligator swings its long tail.\n";
    chat_str[2] = "Alligator growls and shows its teeth to you.\n";
  }
  load_chat(3, chat_str);
  set_max_hp(query_hp() + 4000);
  set_hp(query_max_hp());
  set_str(query_str() + 100);
  set_animal();
  set_skill("critical", 60);
  set_skill("enhance critical", 40);
  set_skill("find weakness", 43);
  set_skill("doublehit", 30);
  set_skill("dodge", 60);
  set_skill("alertness", 50);
  set_skill("foresee attack", 40);
  set_skill("tumble", 20);
  set_al(-60);
}