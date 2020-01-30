inherit "obj/monster";

reset(arg) {
  object staff, torso;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(2)+45);
  set_name("kern'h");
  set_alt_name("demon");
  set_alias("mage");
  set_short("Kern'h the stumble, an apprentice demon black mage");
  set_long("Hunchbacked elderly-looking demon is standing in the middle of the room. Its\n" + 
           "outlook tells you that it belongs to a feared demon group which is practicing\n" + 
           "black magicks. It has extremely long and crude nails in its hand, the staff it\n" + 
           "is holding sizzled wildly and some energy particles float all around demon. You\n" + 
           "see small flames blazing in mage's eyes as it scans you with its sight. It is\n" + 
           "whispering some demonic magic words in the air, but you do not have even a\n" + 
           "slightest idea what they might be for. The demon mage seems to be surrounded by\n" + 
           "an elemental shield.\n");
  set_max_hp(query_hp() + 15000);
  set_hp(query_max_hp());
  set_str(query_str() + 80);
  set_int(900);
  set_al(-70);
  set_aggressive(0);
  set_resists("fire",50+random(50));
  set_resists("cold", 20+random(45));
  set_resists("electric", 20+random(45));
  set_mage(10);
  set_log();
  
  staff = clone_object("/wizards/ahma/castle/eq/magistaff");
  move_object(staff, this_object());
  init_command("wield staff");
  
  torso = clone_object("/wizards/ahma/castle/eq/torso");
  move_object(torso, this_object());
  init_command("wear protector");
}
