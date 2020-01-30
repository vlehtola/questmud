inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_name("robe");
    set_alias("robe");
    set_short("A dark silk robe of Nyx");
    set_long("This robe is made of dark silk. When you examine it closer, you notice it glowing\n"
             "magically. The robe is designed as a shirt so you can wear it in your torso.\n"
             "There is ancient runes written in randomly all over the cloak. The runes are \n"
             "impossible to understand");
    set_ac(5);
    set_value(5000);
    set_stats("int", 17);
    set_stats("wis", 14);
    set_stats("con", -10); 
    set_stats("str", -10);
    set_stats("spr", 22);
    set_slot("torso");

}
