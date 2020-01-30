inherit "obj/monster";

reset(arg) {
    object armour;
    object weapon;
        ::reset(arg);
    if(arg) { return; }
    set_undead(1);
    call_other(this_object(), "set_level", 60);
    call_other(this_object(), "set_name", "skeleton");
set_log();
    call_other(this_object(), "set_alias", "skeleton");
    call_other(this_object(), "set_short", "A demonic skeleton holding a dusty axe");
    call_other(this_object(), "set_long", "You see a human sized skeleton. It is wearing a dark\n"
                                          "cloak covered with dust. You can see that this skeleton\n"
                                          "has been sleeping for a quite while now. The skeleton seems\n"
                                          "to be aggressive\n");
    set_spell_chance(90, "exs brr blt");
    set_skill("cast ice", 90);
    set_skill("cast bolt", 90);
    set_skill("attack", 100);
    set_skill("critical", 100);
    set_skill("cut", 100);
    set_skill("round blow", 100);
    set_skill_chance("round blow", 50);
    set_skill("cast essence", 90);
    set_skill("mana control", 80);
    call_other(this_object(), "set_aggressive", 1);
set_follow(50, 10);

    armour = clone_object("/wizards/aarrgh/nyxi/obj/belt.c");
    move_object(armour, this_object());
    init_command("wear belt");
    weapon = clone_object("/wizards/aarrgh/nyxi/obj/gaxe.c");
    move_object(weapon, this_object());
    init_command("wield axe");
}
