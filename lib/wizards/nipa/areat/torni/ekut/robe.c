inherit "obj/armour";

reset(arg) {
    ::reset(arg);
      set_sub_type("leather armour");
    set_name("robe");
    set_alias("Robe");
    set_short("A Crimson red robe of the archmage");
    set_long("These robes are vowen from satin and has weird runes in it which\n"
     "seems to be imprinted just recently. These crimson red robes was\n"+
             "know all around Deleria for being used only by most powerful\n"+
             "spellcasters and archmages but is now forgotten by most.\n"+
             "Only a handful of these powerfully enchanted garments are know to\n"+
             "exist in mageguild alone and only the most competent mages are\n"+
             "allowed to have them. These robes contain many powerful enchantments\n"+
             "and are radiating an aura of raw magical energy, however, this robe\n"+
             "seems to have somehow corrupted and its aura seems to be twisted\n"+
             "and sinister. As you examine the runes you notice that they seem to\n"+
             "bleed when you touch them. You got the feeling that very dark and\n"+
             "twisted magics were used when these runes were made. Although that\n"+
             "robes are made of very thick satin it still feels chilly when you\n"+ 
               "wear them");
    set_ac(5);
    set_value(5000);
    set_stats("int", 30);
    set_stats("wis", 20);
    set_stats("con", -8);
    set_stats("dex", -16); 
    set_stats("str", -8);
    set_stats("spr", 25);
    set_slot("torso");
}
