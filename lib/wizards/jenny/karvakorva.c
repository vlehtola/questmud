inherit "obj/monster";

reset(arg) {
    object armour;
    ::reset(arg);
    if(arg) { return; }
    set_level(5);
        set_experience(90000000);
    set_name("Siki, the little karvakorva");
    set_alias("karvakorva");
    set_short("Siki, the little karvakorva");
    set_long("The is huge compared to its smaller relatives. It is atleast\n" +
             "one and a half meters long and one meter high.It is digging the\n" +
             "wall and your presence doesn't seem to distracting it in its work.\n");
    set_al(50);
    set_aggressive(0);
    set_animal(1);

}
