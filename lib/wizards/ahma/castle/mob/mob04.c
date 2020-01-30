inherit "obj/monster";

reset(arg) {
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(7)+21);
  set_name("dog");
  set_alias("demon");
  set_short("Flame dog");
  set_long("This dog-sized demon is under heavy fire. You are not sure if you can see the\n" + 
           "actual body at all from the flames. Its bright yellow eyes stare at you.\n" + 
           "Demon's sharp set of teeth can be seen as it growls like any other dog-like\n" + 
           "animal. Its flaming tail and one of its feets is in the air, indicating that\n" + 
           "it is ready to attack if even a slightest false move is made.\n");
  set_al(-45);
  set_aggressive(0);
  set_resists("fire",100);
  
  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "The dog growls at you.\n";
    chat_str[1] = "The dog digs a corpse lying on a ground.\n";
    chat_str[2] = "The dog eyes you awaringly.\n";
  }
  load_chat(3, chat_str);  
  
}