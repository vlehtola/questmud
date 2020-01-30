inherit "obj/monster";
int h;

reset(arg) {
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(3)+25);
  set_name("hans");
  set_alias("attendant");
  set_alt_name("man");
  set_gender(1);
  set_race("orc");
  set_short("Hans Barakk, the attendant of Chief Tas'gand");
  set_long("A medium-sized Orcish man is wearing a long violet robe on him. This\n" + 
           "man's whole being indicates of some sort of officiality. Hans is Chief\n" + 
           "Tas'gand's right-hand man, his trusted attendant. Seems that before\n" + 
           "your arrival Hans was working on some papers which now lay all around\n" + 
           "his desk.\n");
  
  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Hans apologizes: 'I'm sorry, but I cannot do anything for you right now.'\n";
    chat_str[1] = "Hans says: 'There has been something odd about chief lately.'\n";
    chat_str[2] = "Hans says: 'Excuse me but I have some paperwork to do.'\n";
  }
  load_chat(3, chat_str);

  if(!present("robes", this_object())) { move_object(clone_object("/wizards/ahma/orc/eq/hansrobes"), this_object()); init_command("wear robes"); }
  if(!present("pen", this_object())) { move_object(clone_object("/wizards/ahma/orc/eq/pen"), this_object()); init_command("wield pen"); }

  set_special(80);
  set_dead_ob(this_object());
}

special_move() {
  if(!h) {
  init_command("operate pen");
  h++; }
}

monster_died() {
  if(h) {
  init_command("operate pen");
  }
  return 0;
}
