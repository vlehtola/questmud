inherit "obj/monster";

reset(arg) {

    int i;
    string str;
    ::reset(arg);
    if(arg) { return; }
    i = random(3);
    if(i==0) str = "drunken sailor";
    if(i==1) str = "drunk pirate";
    if(i==2) str = "drunk moaning here";

    set_level(random(10)+10);
    set_name("drunk");
    set_short("A "+str+" ");
    set_long("He looks quite old man. He is wearing dirty clothes.\n"+
             "He is drinking bear and moaning in these streets.\n");
    set_move_at_random(3);
    set_gender(1);
 }
