inherit "obj/monster";

reset(arg) {
  object cape, staff;
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(4)+21);
  set_name("apprentice mage");
  set_alt_name("demon");
  set_alias("mage");
  set_short("Apprentice demon mage");
  set_long("It can be easily seen that this mage is an apprentice one. Its arms are constantly\n" + 
           "shaking a bit when it tries to complete some simple spells to train its skills.\n" + 
           "Demon looks physically very weak: It seems to have been kept in the hunger and its\n" + 
           "arms look very thin, they are almost bare skin and bone. The demon mage is holding\n" + 
           "a wooden staff in its hands, a small orange aura can be seen around the staff.\n");
  set_al(-40);
  set_aggressive(0);
  set_resists("fire",70);

  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Apprentice mage tries desperately find correct magic words for its spell.\n";
    chat_str[1] = "Apprentice mage bows at you almost scaredly.\n";
    chat_str[2] = "Apprentice mage seems to collect confidence for something.\n";
  }
  load_chat(3, chat_str);

  cape = clone_object("/wizards/ahma/castle/eq/cape");
  move_object(cape, this_object());
  init_command("wear cape");

  move_object(staff = clone_object("/wizards/ahma/castle/eq/magistaff"), this_object());
  init_command("wield staff");
}

