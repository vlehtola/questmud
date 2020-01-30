inherit "obj/monster";

reset(arg) {

    int i;
    string str;
    ::reset(arg);
    if(arg) { return; }
    i = random(3);
    if(i==0) str = "citizen exploring the streets of the city";
    if(i==1) str = "poor citizen seeking for doss house";
    if(i==2) str = "deportee Duranghom citizen";

    set_level(random(5)+10);
    set_name("citizen");
    set_short("A "+str);
    set_long("A child, who is born inside the gates of Duranghom, is a native of\n"+
             "Duranghom. A real citizen, who defends the city with his own blood\n"+
             "and sweat, to his very end. They don't need to pay taxes, but they\n"+
             "must be loyal to the major of Duranghom. All criminals and dissidents\n"+
             "will be expelled from the city, some may even be executed.\n");

    set_move_at_random(3);
    set_gender(1);
 }

