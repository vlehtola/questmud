inherit "obj/monster";

reset(arg) {
 
    ::reset(arg);
    if(arg) { return; }
    set_level(13);
    set_name("troll");
    set_alias("troll");
    set_race("troll");
    set_short("A forest troll");
    set_long("A very ugly troll is doing his business here.\n");
    set_al(-10);
    set_aggressive(0);
    set_move_at_random(0);
    set_skill_chance("kick",60);
}
