inherit "obj/monster";
int i;

reset(arg) {
  string chat_str;
  ::reset();
  set_level(random(3) + 30);
  set_name("gran'h");
  set_alias("man");
  set_alt_name("owner");
  set_short("Gran'h, the owner of carpet shop");
  set_gender(1);
  set_race("orc");
  set_long("Gran'h is a tall Orcish man. He is smiling at you politely behind the\n" + 
           "counter. Gran'h's teeth are shining white and he is wearing very clean\n" + 
           "clothes. He is in every way much cleaner than an average Orc would be.\n" + 
           "Despite the superficial politeness this man surely knows how to defend\n" + 
           "against carpet robbers and such people.\n");
  
  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Gran'h shows you some colourful carpets from the shelves.\n";
    chat_str[1] = "Gran'h blinks his eye at you: 'You can have a discount for this one.'\n";
    chat_str[2] = "Gran'h smiles at you and says: 'Most of my family have worked in the carpet business.'\n";
  }
  load_chat(3, chat_str);

  set_max_hp(query_hp() + 2500);
  set_hp(query_max_hp());
  if(!present("robes", this_object())) { move_object(clone_object("/wizards/ahma/orc/eq/salerobes"), this_object()); init_command("wear robes"); }
  set_skill("kick", 100);
  set_skill_chance("kick", 50);
  set_skill("dodge", 40);
  set_skill("weapon parry", 30);
  set_skill("parry", 40);
  set_skill("foresee attack", 10);
  set_skill("alertness", 15);
  set_al(-10);
  set_special(99);
}

special_move() {
  if(i) return;
  say("Gran'h pulls a knife behind a counter and wields it on his right hand.\n");
  move_object(clone_object("/wizards/ahma/orc/eq/knife"), this_object());
  init_command("wield knife");
  i++;
}

catch_tell(str) {
  string plr, who;
  object ob;
  if(sscanf(str,"%s attacks %s", plr, who) == 2) {
    ob = find_player(lower_case(plr));
    if(!ob || who == "Gran'h" || who == "owner") { return; }
    say("Gran'h shouts: 'Don't you dare to attack my customers!!'\n");
    attack_object(ob);
  }
}
