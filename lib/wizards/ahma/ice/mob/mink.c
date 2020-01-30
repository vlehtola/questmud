inherit "obj/monster";

reset(arg) {
  string chat_str, a_chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(10);
  set_name("mink");
  set_alias("animal");
  set_short("A small mink");
  set_long("An unusual sight in these caverns. A mink is about one and a third\n" +
           "foot long, brown-haired mammal. Mink has two deep-black eyes in its\n" +
           "small head. It is observing its surroundings for possible predators,\n" +
           "such as wolverines. Minks are known to be very agile, but weak\n" +
           "It is a mink.\n");
  
  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Mink observes its surroundings alertly.\n";
    chat_str[1] = "Mink makes some quick moves, but then stops.\n";
    chat_str[2] = "Mink sniffs the air.\n";
  }
  if(!a_chat_str) {
    a_chat_str = allocate(2);
    a_chat_str[0] = "Mink tries to hide among the snow, but you quickly track it down.\n";
    a_chat_str[1] = "Mink makes a ferocious jump-attack at you, but you dodge the attempt.\n";
  }
  
  load_chat(3, chat_str);
  load_a_chat(10, a_chat_str);
  set_animal();
  
  set_dex(query_dex() + 100);
  set_skill("dodge", 60);
  set_skill("alertness", 30);
  set_skill("foresee attack", 30);
  set_max_hp(query_hp() - 20);
  set_hp(query_max_hp());
  set_resists("cold", 30);
}

specname() {
  set_alt_name("cuong");
  set_short("Cuong, Serak's pet mink");
  set_long("An unusual sight in these caverns. A mink is about one and a third\n" +
           "foot long, brown-haired mammal. Mink has two deep-black eyes in its\n" +
           "small head. It is observing its surroundings for possible predators,\n" +
           "such as wolverines. Minks are known to be very agile, but weak\n" +
           "It is a mink.\n");
  
}

baby() {
  set_level(6);
  set_short("A tiny baby mink");
  set_alt_name("baby");
  set_long("An unusual sight in these caverns. A baby mink is about one foot long,\n" +
           "brown-haired mammal. Baby mink has two tiny, deep-black eyes in its\n" +
           "small head. It is observing its surroundings scaredly for possible\n" +
           "predators, such as wolverines. Minks are known to be very agile, but\n" +
           "weak.\n" +
           "It is a mink.\n");
  set_alt_name("offspring");
}
