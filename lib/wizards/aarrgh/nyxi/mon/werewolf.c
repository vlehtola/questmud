/*taa mikaan werewolffi oo, taa o kaarme*/
inherit "obj/monster";

reset(arg) {
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 45);
call_other(this_object(), "set_name", "ekhidna");
call_other(this_object(), "set_alias", "viper");
call_other(this_object(), "set_short", "Ekhidna the Viper (hissing menacily)");
call_other(this_object(), "set_long", "You see a tall half snake half human entity standing bravely\n"
                                      "in front of you, she is about 10 feet tall and has 4 arms. In each\n"
			  	      "arms she has long nails which she uses as a piercing weapons.\n";
    call_other(this_object(), "set_al", -10);
    set_ac("10");
set_block_message("Ekhidna hisses: You are not going anywhere\n");
    call_other(this_object(), "set_aggressive", 0);
   set_block_dir("northeast");
}
