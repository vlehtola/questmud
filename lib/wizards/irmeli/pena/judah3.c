inherit "obj/monster";

reset(arg) {
    object money;
    object armour;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 75);
    call_other(this_object(), "set_name", "judah");
    call_other(this_object(), "set_alias", "judah");
    call_other(this_object(), "set_short", "Judah, emperor of the angels");
    call_other(this_object(), "set_long", "Judah is member of royal family. His eyes is flaming from anger. His feet\n" +
                                          "is as big as you are. He is all over covered with blood of humans.\n" +
                                          "Your blood might end to his shirt.\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);
    set_block_dir();
    
    money = clone_object("obj/money");
    call_other(money, "set_money", random(1000)+500);
    move_object(money, this_object());

    armour = clone_object("/wizards/irmeli/pena/equ/ringi.c");
    move_object(armour, this_object());
    init_command("wear ring");

    armour = clone_object("/wizards/irmeli/pena/equ/plate.c");
    move_object(armour, this_object());
    init_command("wear plate");
}


 
