inherit "obj/monster";

reset(arg) {

    int i;
    string str;
    ::reset(arg);
    if(arg) { return; }
    i = random(4);
    if(i==0) str = "citizen wandering around the streets of the city";
    if(i==1) str = "small citizen is wondering around";
    if(i==2) str = "lazy citizen looking for job";
    if(i==3) str = "bored citizen is here digging his nose";

    set_level(20+random(5));
    set_name("citizen");
    set_alias("human");
    set_race("human");
    set_short("A "+str+" ");
    set_long("Citizen greets you quickly and continues wandering.\n"+
             "You can see that its quite affaird, maybe it's\n"+
             "because of your presence. It looks quite boring,\n"+
             "and it would be great fun to let it out of it's misery.\n");

    set_move_at_random(8);
    set_gender(1+random(2));
 }
