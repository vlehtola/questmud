inherit "obj/armour";
  start() {

   set_class(5);
   set_slot("belt");
   set_name("belt");
   set_alias("sash");
   set_short("Mithril sash of Freedom");
   set_long("When you glance the sash, you notice it's eerie glow as\n"+
            "the sash radiates with peaceful aura, making you feel safe.\n"+
            "The sash is partially covered with blood of Durand, the\n"+
            "pacifist and a messenger of peace. This type of belts\n"+
            "are normally used by clerics and travelling healers,\n"+             
            "whose noble actions are rumoured all around the lands.\n"+
            "This belt is made of mithril and it is very exquisite\n"+
            "looking.");
   set_stats("str", -8);
   set_stats("dex", -20);
   set_stats("int", 10);
   set_stats("wis", 15);
   set_stats("spr", 25);
 }
