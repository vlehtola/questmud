inherit "obj/monster";

reset(arg) {
  object sword1, sword2, plate;
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(4)+40);
  set_name("combat master");
  set_alt_name("demon");
  set_alias("master");
  set_short("Demon combat master");
  set_long("Very skillful and agile-looking demon fighter. It has quite many rank badges\n" + 
           "attached to its bone breastplate's chest part, making it respected among other\n" + 
           "demons. From time to time this demon makes some amazing combat movements with\n" + 
           "its two bone swords, like trying to brag you with them. Also seems, that this\n" + 
           "demon is communicating with other demons only by shouting angrily and noisily.\n" + 
           "The noisy figure seems confident and ready to take on the challenge at any time.\n");
  set_max_hp(query_hp() + 5500);
  set_hp(query_max_hp());
  set_str(query_str() + 60);
  set_al(-50);
  set_aggressive(0);
  set_resists("fire",100);
  set_skill("tremendous blow", 52);
  set_skill_chance("tremendous blow", 20);
  set_skill("two weapons combat", 100);
  set_skill("dodge", 70);
  set_skill("tumble", 50);
  set_skill("weapon parry", 80);
  
  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Combat master makes amazing moves with its swords.\n";
    chat_str[1] = "Combat master shouts angrily something to you.\n";
    chat_str[2] = "Combat master taps its foot on the ground.\n";
  }
  load_chat(3, chat_str);
  
  sword1 = clone_object("/wizards/ahma/castle/eq/bonesword");
  move_object(sword1, this_object());
  init_command("wield sword");
  
  sword2 = clone_object("/wizards/ahma/castle/eq/bonesword");
  move_object(sword2, this_object());
  init_command("wield sword");
  
  plate = clone_object("/wizards/ahma/castle/eq/boneplate");
  move_object(plate, this_object());
  init_command("wear plate");
}
