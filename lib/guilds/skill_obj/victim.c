inherit "obj/food";

reset(arg) {
int num;
num = random(100);
::reset(arg);
if (arg) { return; }
if (num < 30) {
set_name("mouse");
set_short("A dead mouse");
set_long("A little grey mouse killed for food.\n");
set_weight(2);
set_value(0);
set_strength(50000);
}
if (num > 29) {
set_name("squirrel");
set_short("A dead squirrel");
set_long("A corpse of brown squirrel, suitable for eating.\n");
set_weight(3);
set_value(0);
set_strength(80000);
}
if (num > 60) {
set_name("snake");
set_short("A dead slimy snake");
set_long("Slime drips all around of this snake's corpse...bon appetit.\n");
set_weight(4);
set_value(0);
set_strength(120000);
}
if (num > 80) {
set_name("beetle");
set_short("A big dead beetle");
set_long("It isn't any nicer to look at, even after it is dead.\n");
set_weight(1);
set_value(0);
set_strength(25000);
}
}

set_id(arg) {
    return name == arg;
}
