inherit "obj/monster";

reset(arg) {
    string a_chat_str;
    ::reset(arg);
    if (arg) { return; }
    set_level(29);
    set_name("gelugon");
    set_alias("fiend");
    set_short("A gelugon");
    set_long("The gelugon is a truly horrible creature. They are created"+
             "from the souls of people who died from exposure. On the demons' home plane"+
	     "they are then cast to the Frozen Pit for 500 days.\n");
    set_al(-95);
    set_gender(1);
    set_race("demon");
    set_mage(1);
    set_spell_chance(75, "exs brr blt");
    set_skill("cast essence", 85);
    set_skill("cast ice", 85);
    set_skill("cast bolt", 85);
    set_skill("mana control", 70);
    set_skill("chanting", 70);
    
    if (!a_chat_str) {
     a_chat_str = allocate(1);
     a_chat_str[0] = "The gelugon's eyes glow with a blue flame.\n"; 
    }
   load_a_chat(10, a_chat_str);  
}
