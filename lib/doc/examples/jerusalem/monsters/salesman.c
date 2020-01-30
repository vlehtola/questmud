inherit "obj/monster";
int sattuma;

reset(arg) {
    object ehka;
    ::reset(arg);
    if(arg) { return; }
    set_race("human");
    call_other(this_object(), "set_level", 23);
    call_other(this_object(), "set_name", "Salesman");
    call_other(this_object(), "set_alias", "salesman");
    call_other(this_object(), "set_short", "A salesman looking for a good spot to place his stand");
    call_other(this_object(), "set_long", "A salesman walking around the streets hurriedly.\n");
    call_other(this_object(), "set_al", 0);
    call_other(this_object(), "set_aggressive", 0);
    set_gender(1);

    sattuma = random(100) + 1;
    if(sattuma > 80) {
    ehka = clone_object("wizards/nalle/potion");
    move_object(ehka, this_object());
    }

}

