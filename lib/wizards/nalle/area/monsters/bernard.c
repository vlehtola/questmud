inherit "obj/monster";

reset(arg) {
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    set_race("human");
    set_gender(1);
    call_other(this_object(), "set_level", 41);
    call_other(this_object(), "set_name", "Bernard");
    call_other(this_object(), "set_alias", "bernard");
    call_other(this_object(), "set_short", "Bernard, the leader of the thieves of Chamron");
    call_other(this_object(), "set_long", "Bernard is a tall and thin man. He is wearing a dark cloak\n" +
                                          "and every now and then you can see something shining in his\n" +
                                          "sleeve. Bernard is clearly the leader of these people.\n");
    call_other(this_object(), "set_al", -15);
    call_other(this_object(), "set_aggressive", 1);
    set_log();

    armour = clone_object("/wizards/nalle/area/eq/bcloak");
    move_object(armour, this_object());
    init_command("wear cloak");

    weapon = clone_object("/wizards/nalle/area/eq/bdagger");
    move_object(weapon, this_object());
    init_command("wield dagger");
}

init() {
    add_action("east","east");
}

east() {
    if (this_object()->query_attack() == this_player()) {
        write("Bernard blocks your way.\n");
        return 1;
    }
}
