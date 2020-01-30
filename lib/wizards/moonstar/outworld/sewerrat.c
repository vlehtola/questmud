inherit "obj/monster";

reset(arg) {
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(4)+30);
  set_name("sewer rat");
  set_alias("animal");
  set_alt_name("rat");
  set_short("A hairy sewer rat");
  set_long("A ball-shaped, hairy figure is almost four feet tall. Rat's brown fur\n" + 
           "is wet all over the creature due to the water flowing in the tunnel.\n" + 
           "Rat's small, black eyes shimmer weakly as it sniffs the sewer walls.\n" + 
           "Sharp claws can be seen peeking under the thick hair of this animal.\n");
  
  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Sewer rat squeaks ratfully.\n";
    chat_str[1] = "Sewer rat drinks the crappy water.\n";
    chat_str[2] = "Sewer rat swings its tail in the air.\n";
  }
  load_chat(3, chat_str);
  set_max_hp(query_hp() + 800);
  set_hp(query_max_hp());
  set_dex(query_dex() * 2);
  set_str(query_str() + 40);
  set_animal();
  set_skill("dodge", 70);
  set_skill("foresee attack", 30);
  set_skill("alertness", 50);
  set_skill("tumble", 20);
  set_al(-40);
}
