inherit "obj/monster"; 
 
reset(arg) {
    object money;
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 69);
        call_other(this_object(), "set_name", "leb");
        call_other(this_object(), "set_alias", "priest");
        call_other(this_object(), "set_short", "Leb-Kamar, the ruler of Jericho");
        call_other(this_object(), "set_long", "Before you is a silhouette of a great man. He is not too big in size\n" +
       "but his ego is bigger than the whole city of Jericho. He has won so many battles that they are uncountable.\n" +
       "As you have interfered with his privacy here, deep under the city of Jericho, you understand that here, no\n" +
        "rules of fair fight apply, but ruthless killing.\n");
        call_other(this_object(), "set_al", 10);
        call_other(this_object()," set_aggressive", 0);       
        set_block_dir("out");
        set_log();

        money = clone_object("/obj/money");
        call_other(money, "set_money", random(1000)+10);
        move_object(money, this_object());
 
        armour = clone_object("/wizards/walla/leb/armour/plate");
        move_object(armour, this_object());
        init_command("wear plate");
 
        armour = clone_object("/wizards/walla/leb/armour/leggings");
        move_object(armour, this_object());
        init_command("wear leggings");

        armour = clone_object("/wizards/walla/leb/armour/ring");       
        move_object(armour, this_object());
        init_command("wear ring");
 
        weapon = clone_object("/wizards/walla/leb/weapons/sword");
        move_object(weapon, this_object());
        init_command("wield sword");
 
}
