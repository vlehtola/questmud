inherit "obj/armour";
start() {
  set_class(5);
  set_sub_type("chain mail");
  set_name("protector");
  set_short("Apprentice's torso protector");
  set_long("An iron chain mail which has been modified to fit mage's demands. Its weight\n" + 
           "has been somewhat decreased, and some magical enchantments have been laid in\n" + 
           "its chains. The chains in the mail are glowing a soft orange glow and quiet\n" + 
           "humming can be heard inside the armour when concentrating hard. Two red stones\n" + 
           "connected with a silvery chain have been attached in mail's left shoulder and\n" + 
           "two longer chains are hanging loose from the lower part of the mail. Chains\n" + 
           "keep making a tinkling voice when moving the mail around");
  set_slot("torso");
  set_stats("dex", -3);
  set_stats("int", 2);
  set_stats("wis", 3);
  set_stats("spr", 5);
}
