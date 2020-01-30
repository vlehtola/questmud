inherit "obj/monster";
 
reset(arg) {
 
    int i,g;
    string str;
    string gdr;
    ::reset(arg);
    if(arg) { return; }
    i = random(3);
    
    if(i==0) str = "poor citizen of Jericho";
    if(i==1) str = "citizen of Jericho";
    if(i==2) str = "young citizen, playing in the street";
    
    g = random(2);
    
    if(g==0) gdr = "1";
    if(g==0) gdr = "2";

    set_level(random(11)+10);
    set_name("citizen");
    set_short("A "+str+" ");
    set_long("A child, who is born inside the gates of Duranghom, is a native of\n"+
             "Duranghom. A real citizen, who defends the city with his own blood\n"+
             "and sweat, to his very end. They don't need to pay taxes, but they\n"+
             "must be loyal to the major of Duranghom. All criminals and dissidents\n"+
             "will be expeled from the city, some may be executed.\n");
 
    set_move_at_random(3);
    set_gender("+gdr+");
 }
