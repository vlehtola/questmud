inherit "obj/monster";

reset(arg) {
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(10)+15);
  set_name("demon");
  set_alias("tiny");
  set_short("Tiny fire demon");
  set_long("This demon is patrolling around the castle corridors and hallways. It is\n" + 
           "about four feet in height and does not look too dangerous by its physics,\n" + 
           "but because the monster is burning, you should keep some distance to it.\n" + 
           "The monster is leering at you very suspiciously, and it seems to be fully\n" + 
           "prepared for a combat.\n" + 
           "The monster has no visible armour and it seems to fight bare handed.\n");
  set_al(-40);
  set_aggressive(0);
  set_resists("fire",100);

  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Fire demon lets out some growling noises.\n";
    chat_str[1] = "Fire demon looks angrily at you.\n";
    chat_str[2] = "Fire demon twiddles its thumbs.\n";
  }
  load_chat(3, chat_str);  
}
