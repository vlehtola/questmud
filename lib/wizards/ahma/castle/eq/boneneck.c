inherit "obj/armour";

start() {
  set_class(5);
  set_name("necklace");
  set_short("Bone necklace");
  set_long("In a metallic string has been attached many pieces of various coloured bones\n" + 
           "and some bigger animal fangs. The necklace seems to have much more emotional\n" + 
           "than practical value, because it seems to have no magical enchantments in it\n" +
           "The bones hit against each other when the necklace is moved, making out some\n" + 
           "seriously annoying noise");
  set_slot("neck");
}

init() {
  ::init();
  add_action("rattle", "rattle");
}

rattle() {
  say(environment(this_object())->query_name() + " rattles the bone-made necklace.\n" +
      "GOD - that sound makes you mad!!\n");
  write("You try to anger others in the room by rattling the bone necklace.\n");
  return 1;
}