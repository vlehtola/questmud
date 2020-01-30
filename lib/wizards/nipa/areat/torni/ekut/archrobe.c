inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_name("robe");
    set_alias("robe");
    set_short("Red star decorated satin robes.");
    set_long("These robes are achieved with a promotion to Archmage title.\n"+
             "Robes glow with red colour and look good as new. They look\n"+
             "very similiar to the apprentices robes with a big moon icon\n"+
             "on them exept the star decoration."); 
    set_ac(5);
    set_value(100);
    set_weight(200);
    set_stats("int", 5);
    set_slot("torso");
}
