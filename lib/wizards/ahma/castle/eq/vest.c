inherit "obj/armour";
start() {
  set_class(4);
  set_sub_type("chain mail");
  set_name("vest");
  set_short("A vest made of animal fur");
  set_long("An ordinary-looking brown vest, probably made from bear fur. The vest is not\n" + 
           "a practical armour, but it feels very comfortable and soft when weared. On\n" + 
           "front seems to be sewed some buttons for attaching the right and left sides\n" + 
           "of the vest to each other. There seems to be a small pocket on the right side\n" + 
           "of the vest, but it is too small for any of the things you are carrying with\n" + 
           "you. The hair on the fur seems to generate small field of static electricity,\n" + 
           "making some resistance against possible electric attacks against you");
  set_slot("torso");
  set_resists("electric", 30);
}
