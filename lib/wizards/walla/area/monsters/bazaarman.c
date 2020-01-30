inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_level(12);
    set_name("man");
    set_short("A man hustling around in the bazaar");
    set_long("The man is hustling around, he doesn't even have time to talk with anyone.\n" +
             "He is neither tall nor short, but on the contrary he is quite fat. He\n" +
             "has strong legs and hands, standing up for his fat body.\n");
    set_al(10);
    set_aggressive(0);
    set_race("human");
    set_gender(1);

}
