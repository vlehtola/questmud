a
10 a
10 c

q
x
x
**
l
s
x
p
mas
quit
**
exit
ed
**
 
reset(arg) {
    ::reset(arg);
    if (arg) { return; }
    set_name("adept");
    set_alias("mage");
    set_race("human");
    set_gender(1);
    set_mage(1); 
    set_al(-10);  
    set_aggressive(0);    
    set_level(42);
    set_short("Skilled human adept discussing on some matter.");
    set_long("This adept mage is discussing with another adept.\n"+
      "Both of them seem very worried and scared.\n");

set_skill("cast essence", 100);
set_skill("cast bolt", 100);
set_skill("cast ice", 100);
set_skill("cast fire", 100);
set_skill("cast electric", 100);
set_skill("mana control", 100);
}
