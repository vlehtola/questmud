inherit "obj/monster";

reset(arg) {
  object ring;
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(4)+39);
  set_name("fire elemental");
  set_alt_name("elemental");
  set_alias("lesser");
  set_short("Lesser fire elemental");
  set_long("This at least seven feet tall flaming creature has been summoned from the\n" + 
           "plane of fire. The elemental is fully consisted from fire and other hot matter.\n" + 
           "The fire elemental is standing still, its flames flickering. Hot air surrounds\n" + 
           "the elemental in large scale, making you feel uncomfortably sweaty. Summoned\n" + 
           "creature from plane of Fire is ready to carry out its summoners will, which\n" + 
           "is most definitely to get rid of you. Elemental leers at you with its evil\n" + 
           "eyes. No obvious weapons can be seen with the creature, but its flaming arms\n" + 
           "and feet.\n");
  set_max_hp(query_hp() + 5000);
  set_hp(query_max_hp());
  set_str(query_str() + 50);
  set_int(query_int() + 500);
  set_al(-20);
  set_aggressive(0);
  set_resists("fire",100);
  set_resists("cold", 10+random(10));
  set_mage();
  
  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Fire elemental seems to float around the room.\n";
    chat_str[1] = "Fire elemental bounces a fire ball in its hands.\n";
    chat_str[2] = "Fire elemental sets some cavern flies on fire around it.\n";
  }
  load_chat(3, chat_str);

  ring = clone_object("/wizards/ahma/castle/eq/rring");
  move_object(ring, this_object());
  init_command("tune_ring to cold");
  init_command("wear ring");
}