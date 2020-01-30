inherit "obj/monster";

reset(arg) {
 ::reset(arg);
 if(arg) { return; }
 set_level(32);
 set_name("kituras");
 set_alias("shopkeeper");
 set_short("Kituras Forgamer, the dwarven shopkeeper");
 set_long("Kituras is a small person, even for a dwarf. He has settled in here to\n"+
          "look after this shop, which he owns. Oddly enough, he doesn't have\n"+
          "anything to sale. His shop must be fake, maybe he has something for\n"+
          "sale in his backroom or under the counter.\n");
 set_al(0);
 set_aggressive(0);
 set_race("dwarf");
 set_gender(1);
 set_mage(1);
}
                                                                                                                       
