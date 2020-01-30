inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_level(90);
    set_name("wolf");
    set_short("Silent werewolf");
    set_long("A tall wolfman look-a-like creture stands silently here.\n");
    set_al(0);
    set_race("werewolf");
}
