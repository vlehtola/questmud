inherit "obj/armour";
start() {
  set_class(10);
  set_value(5000);
  set_sub_type("leather boots");
  set_name("sandals");
  set_short("Glowing sandals of Kralmakh");
  set_long("The crude-looking brownish sandals are surrounded by a weak orange aura. No\n" + 
           "one knows where or when these sandals are made, but the legend tells that\n" + 
           "the aura was before much stronger. Kralmakh, the feared legendary demon mage,\n" + 
           "gained his superior magical powers from these very sandals. The story also\n" + 
           "tells that Kralmakh was able to shake and make enormous wound-like gaps on the\n" + 
           "ground by just standing still and chanting quietly to the sandals. But nowadays\n" + 
           "the aura seems to be so weak that it just provides some more protection to feet\n" + 
           "of sandals' wearer");
  set_stats("dex", 3);
  set_stats("con", -4);
  set_stats("int", 10);
  set_stats("wis", 6);
  set_stats("spr", 18);
  set_resists("electric", 15);
}
