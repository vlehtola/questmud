inherit "obj/monster";

reset(arg) {

    int i;
    string str;
    ::reset(arg);
    if(arg) { return; }
    i = random(3);
    if(i==0) str = "small";
    if(i==1) str = "medium sized";
    if(i==2) str = "large";

    set_level(random(5)+20+(2+i*5));
    set_name("spider");
    set_short("A "+str+" black spider");
    set_long("The realm is full of different dangerous animals, but the spiders are the danger number one, for the adventurers.  Their poison is exceedingly deadly, if infected. There are different sizes of spiders, some are deadly others not.\n");
    set_animal(1);
    set_mage(50, 100);
 }

