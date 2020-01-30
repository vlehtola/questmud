inherit "obj/monster";
object robes, wand;

reset(arg) {
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(2)+28);
  set_name("adept mage");
  set_alt_name("demon");
  set_alias("mage");
  set_short("Adept demon mage");
  set_long("The demon mage is drawing strange red runes in the air with its magic wand.\n" + 
           "As the creature notices you, it stops the drawing and starts to glower at\n" + 
           "you like it would be some higher power, which should be respected and bowed to.\n" + 
           "The demon is wearing a blue coat, which are more commonly used by human wizards\n" + 
           "and other spellcasters. It has probably stolen the coat from a killed wizard of\n" + 
           "the castle. The wand sizzles a bit in mage's hand when it waits patiently for\n" + 
           "the next event to take place.\n");
  set_al(-50);
  set_aggressive(0);
  set_resists("fire",80);
  
  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Adept mage glares scornfully at your direction.\n";
    chat_str[1] = "Adept mage draws a hand with a middle finger up in the air with its wand.\n";
    chat_str[2] = "Adept mage turns its back to you.\n";
  }
  load_chat(3, chat_str);
  
  set_mage();

  robes = clone_object("/wizards/ahma/castle/eq/robes");
  move_object(robes, this_object());
  init_command("wear robes");
  
  wand = clone_object("/wizards/ahma/castle/eq/wand");
  move_object(wand, this_object());
  init_command("wield wand");
}
