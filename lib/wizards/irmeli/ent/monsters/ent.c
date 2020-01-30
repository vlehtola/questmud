inherit "obj/monster";

reset(arg) {

    ::reset(arg);
    if (arg) { return; }

    set_level(random(5)*5+12);
    set_name("ent");
    set_alias("ent");
    set_short("A moss covered ent");
    set_long("It's hard to say, what this thing is, because it's covered with moss. Undoubtedly it's some sort of a tree, but it's not a regular tree. You can perceive its strange face, its soft hands and its big brown feets.\n");
    set_al(40);
    set_gender(0);
    set_race("ent");
    set_aggressive(0);
}









