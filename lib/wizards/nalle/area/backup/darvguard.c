inherit "obj/monster";

reset(arg) {
    object money;
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 21);
    call_other(this_object(), "set_name", "darvox");
    call_other(this_object(), "set_alias", "darvox");
    call_other(this_object(), "set_short", " ");
    call_other(this_object(), "set_long", "Darvox, the master of the elements.\n");
    call_other(this_object(), "set_al", -21);
    call_other(this_object(), "set_aggressive", 1);
    call_other(this_object(), "set_exp", 60000);
    call_other(this_object(), "set_hp", 10000);
    set_block_dir("down");
    set_skill("dodge", 90);
    set_skill("bludgeons", 50);
    set_skill("attack", 50);
    set_skill("parry", 50);
    set_skill("stun", 50);
    set_skill("critical", 50); 
    
    money = clone_object("obj/money");
    call_other(money, "set_money", random(10)+10);
    move_object(money, this_object());

    armour = clone_object("/wizards/nalle/area/rags");
    move_object(armour, this_object());
    init_command("wear armour");

    weapon = clone_object("/wizards/nalle/area/club");
    move_object(weapon, this_object());
    init_command("wield club");
}
