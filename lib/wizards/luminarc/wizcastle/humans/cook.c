inherit "obj/monster";
reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_level(15);
    set_name("cook");
    set_alias("cook");
    set_short("Busy cook, swinging knifes");
    set_long("This small man is a cook of this castle. He seems to be cooking\n"+ 
             "many diffrent foods at the same time, which makes him to look\n"+ 
             "very busy. Cook is wearing a long white hat and white shirt. He\n"+
             "is swinging some sharp knifes in his hand\n");
    set_race("human");
    set_al(10);
    set_gender(1);    
    set_aggressive(0);
}

