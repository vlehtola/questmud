inherit "obj/monster";

reset(arg) {
    object boots;
    ::reset(arg);
    if(arg) { return; }
set_level(42);
    set_alias("troll");
    set_short("A troll planning for revenge");
    set_long("A rough looking troll planning for revenge.\n");
    set_al(0);
    set_skill("kick", 80);
    set_aggressive(0);
set_whimpy(10);
    set_move_at_random(0);
    boots = clone_object("/wizards/bulut/boots.c");
    move_object(boots, this_object());
    init_command("wear boots");



}
