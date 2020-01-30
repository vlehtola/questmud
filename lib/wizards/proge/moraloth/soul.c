inherit "obj/monster";
int sattuma;

reset(arg) {
    object ehka;
    object necklace;
    object necklace2;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 24);
    call_other(this_object(), "set_name", "soul");
    call_other(this_object(), "set_short", "Cursed soul wandering about");
    call_other(this_object(), "set_long", 
"This is one of the souls of the people who once dwelled within\n"+
"these woods. It has been damned to haunt the forest for the\n"+
"eternity. It's glowing dark as it floats upon the ground.\n");
    call_other(this_object(), "set_al", -10);
    call_other(this_object(), "set_aggressive", 0);
    call_other(this_object(), "set_undead", 1);
    sattuma = random(100) + 1;
    if(sattuma >= 50) {
     necklace = clone_object("/wizards/proge/moraloth/necklace");
     move_object(necklace, this_object());
     init_command("wear necklace");
    }
    if(sattuma < 50) {
     necklace2 = clone_object("/wizards/proge/moraloth/necklace2");
     move_object(necklace2, this_object());
     init_command("wear necklace");
    }
    if(sattuma > 95 || sattuma < 5) {
     ehka = clone_object("/wizards/proge/moraloth/poison");
     move_object(ehka, this_object());
    }
}

