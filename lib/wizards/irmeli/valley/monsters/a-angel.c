inherit "obj/monster";

reset(arg) {
::reset(arg);
if (arg) { return; }
    set_level(32);
    set_name("angel");
    set_alias("angel");
    set_short("An avenging angel summoned by Scarecrow");
    set_long("An hostile looking angel has two, tremendous wings, which are tied together,\n"+
             "purpose to prevent him to fly. The regular celestial angel-look is far away\n"+
             "from him. First of all, his eyes are full of rage, secondly his body is full\n"+
             "of scalds and wounds from whiplashes and finally he is bold. He has broked up\n"+
             "from chains, chains which are in his legs and hands.\n");

    set_al(-10);
    set_gender(1);
    set_race("human");
    set_aggressive(1);
    set_mage(1);
}









