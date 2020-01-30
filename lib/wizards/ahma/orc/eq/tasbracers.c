inherit "obj/armour";
start() {
  set_class(6);
  set_sub_type("leather bracers");
  set_name("bracers");
  set_short("Black cloth bracers with small sparkling jewels");
  set_long("Bracers made of two long stripes of black cloth. The bracers are used by\n" + 
           "wrapping the stripes around wearer's arms and attaching both ends through\n" +
           "the skin with appropriate mechanism. The black cloth is covered with tiny\n" +
           "multi-coloured jewels. Despite the minor protection which the bracers give\n" +
           "to their wearer, the cloth itself looks very durable and sturdy");

  set_weight(100);
  set_stats("dex", 2);
  set_stats("con", -7);
  set_stats("int", 2);
  set_stats("wis", 9);
  set_stats("spr", 5);
}

init() {
  ::init();
  add_action("wear", "wear");
}

wear(str) {
  if(str == "bracers" && !query_worn()) {
    write("You start wrapping the black stripes around your arms.\n");
    call_out("step2", 3);
    return 1;
  }
  else {
    return;
  }
}

step2() {
  write("Piercing your skin with the attachment-mechanism hurts a bit.\n");
  environment(this_object())->hit_with_spell(20 + random(21));
  do_wear();
  return 1;
}