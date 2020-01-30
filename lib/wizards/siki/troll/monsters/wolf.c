inherit "obj/monster";

reset(arg) {

int i;
string str;

    ::reset(arg);
    if(arg) { return; }
    i = random(3);
    set_level(18+random(2+i));
    set_name("wolf");
    set_animal(1);
    if(i==0) str = "furious";
    if(i==1) str = "vicious";
    if(i==2) str = "large";
    set_short("A "+str+" wolf");
    set_long("A "+str+" and hungry wolf looking for something to eat. It has pointy\n"+
             "teeth and a thick black fur. Its eyes are full of rage and it is extremely\n"+
             "aggressive.\n");

    set_al(-10);
    set_aggressive(1);
 
}
