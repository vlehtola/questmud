inherit "obj/armour";

start() {
        set_class(6);
        set_slot("finger");
        set_name("ring");
        set_short("The ring of Ul'grath");
        set_long("Beatiful golden ring, there seems to be a text inside it. it says:\n"+
                   "'When forests were still green and waters were blue, there was\n"+
                   "an ancient god who used this ring to fight the evil forces.'\n"+
                   "The ring glows with unheartly force...");
         
          set_stats("str", 15);
          set_stats("con", 10);
          set_stats("dex", 5);
          set_stats("int", -4); 
          set_stats("wis", -4);
          set_stats("spr", -20);
         
        
}
