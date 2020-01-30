inherit "obj/armour";
start() {
  set_slot("cloak");
  set_name("cloak");
  set_short("A smooth crystal cloak named 'Blue Fusion'");
  set_long("A cloak made of extremely thin layer of some unknown glowing material.\n" +
           "The material must be some kind of crystal because of its smooth and\n" +
           "chilly surface. Bluish aura is surrounding the cloak, making it look\n" +
           "somewhat bigger than it really is. The cloak emits a weak, pulsating\n" +
           "light around it while waving softly");
  
  set_value(7000);
  set_weight(300);
  set_stats("str", 8);
  set_stats("dex", 8);
  set_stats("con", 8);
}
